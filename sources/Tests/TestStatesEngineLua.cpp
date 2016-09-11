#include "TestStatesEngineLua.hpp"
#include <Urho3D/LuaScript/LuaScript.h>
#include <Urho3D/LuaScript/LuaFunction.h>
#include <Urho3D/ThirdParty/toluapp/tolua++.h>
#include <Urho3D/IO/Log.h>

#include <StatesEngine/StatesEngine.hpp>
#include <StatesEngine/StateObjectsManager.hpp>
#include <StatesEngine/EnableLuaBindings.hpp>

TestStatesEngineLua::TestStatesEngineLua (Urho3D::Context *context) : Urho3D::Application(context)
{

}

void TestStatesEngineLua::Setup ()
{
    engineParameters_ ["FullScreen"] = false;
    engineParameters_ ["WindowResizable"] = true;
}

void TestStatesEngineLua::Start ()
{
    context_->RegisterSubsystem (this);
    Urho3D::Log *log = context_->GetSubsystem <Urho3D::Log> ();
    log->Write (Urho3D::LOG_INFO, "Application started!");

    StatesEngine::StatesEngineSubsystem *statesEngine = new StatesEngine::StatesEngineSubsystem (context_);
    statesEngine->Init ();
    context_->RegisterSubsystem (statesEngine);
    statesEngine->SetupState (Urho3D::SharedPtr <StatesEngine::StateObjectsManager> (new StatesEngine::StateObjectsManager (context_)));
    log->Write (Urho3D::LOG_INFO, "StatesEngine initialized!");

    Urho3D::LuaScript *luaScript = new Urho3D::LuaScript (context_);
    context_->RegisterSubsystem (luaScript);
    StatesEngine::EnableLuaBindings (luaScript);
    luaScript->ExecuteFile ("TestStatesEngine.lua");

    Urho3D::LuaFunction *testFunction = luaScript->GetFunction ("TestStatesEngine");
    if (!testFunction)
        ErrorExit ("Can't find test function!");
    testFunction->BeginCall ();
    testFunction->EndCall (1);

    int testReturn = lua_tointeger (luaScript->GetState (), 0);
    log->Write (Urho3D::LOG_INFO, Urho3D::String ("Script return: ") + Urho3D::String (testReturn));
    if (testReturn != 0)
        ErrorExit ("Script return != 0!");
    engine_->Exit ();
}

void TestStatesEngineLua::Stop ()
{
    StatesEngine::StatesEngineSubsystem *statesEngine = context_->GetSubsystem <StatesEngine::StatesEngineSubsystem> ();
    statesEngine->DisposeState ();
    context_->RemoveSubsystem ("StatesEngine");
}

TestStatesEngineLua::~TestStatesEngineLua ()
{

}
URHO3D_DEFINE_APPLICATION_MAIN (TestStatesEngineLua)
