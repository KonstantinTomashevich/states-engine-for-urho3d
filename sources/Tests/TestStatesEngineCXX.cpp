#include "TestStatesEngineCXX.hpp"
#include <Urho3D/Container/Ptr.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/IO/Log.h>

#include <StatesEngine/StatesEngine.hpp>
#include <StatesEngine/StateObjectsManager.hpp>

TestStatesEngineCXX::TestStatesEngineCXX (Urho3D::Context *context) : Urho3D::Application(context)
{

}

void TestStatesEngineCXX::Setup ()
{
    engineParameters_ ["FullScreen"] = false;
    engineParameters_ ["WindowResizable"] = true;
}

void TestStatesEngineCXX::Start ()
{
    context_->RegisterSubsystem (this);
    Urho3D::Log *log = context_->GetSubsystem <Urho3D::Log> ();
    log->Write (Urho3D::LOG_INFO, "Application started!");

    StatesEngine::StatesEngineSubsystem *statesEngine = new StatesEngine::StatesEngineSubsystem (context_);
    statesEngine->Init ();
    context_->RegisterSubsystem (statesEngine);
    statesEngine->SetupState (Urho3D::SharedPtr <StatesEngine::StateObjectsManager> (new StatesEngine::StateObjectsManager (context_)));
    log->Write (Urho3D::LOG_INFO, "StatesEngine initialized!");

    Urho3D::VariantMap updateData;
    updateData [Urho3D::Update::P_TIMESTEP] = 1 / 60.0f;
    statesEngine->Update (Urho3D::E_UPDATE, updateData);
    log->Write (Urho3D::LOG_INFO, "Empty update passed!");

    context_->RegisterFactory <TestObject> ();
    Urho3D::SharedPtr <TestObject> testObject = statesEngine->GetState <StatesEngine::StateObjectsManager> ()->Create <TestObject> ();
    if (testObject.Null ())
        ErrorExit ("Test object isn't created!");
    if (!testObject->IsInitialized ())
        ErrorExit ("Test object initialization don't called after create!");

    statesEngine->Update (Urho3D::E_UPDATE, updateData);
    if (!testObject->IsUpdatePassed ())
        ErrorExit ("Test object update don't called!");
    if (testObject->GetLastUpdateTimeStep () != 1 / 60.0f)
        ErrorExit ("Test object recieves incorrect time step!");

    statesEngine->GetState <StatesEngine::StateObjectsManager> ()->DisposeAll ("TestObject");
    if (!testObject->IsDisposed ())
        ErrorExit ("Test object dispose don't called!");
    log->Write (Urho3D::LOG_INFO, "All tests passed!");
    engine_->Exit ();
}

void TestStatesEngineCXX::Stop ()
{
    StatesEngine::StatesEngineSubsystem *statesEngine = context_->GetSubsystem <StatesEngine::StatesEngineSubsystem> ();
    statesEngine->DisposeState ();
    context_->RemoveSubsystem ("StatesEngine");
}

TestStatesEngineCXX::~TestStatesEngineCXX ()
{

}


TestObject::TestObject (Urho3D::Context *context) : StatesEngine::StateObject (context),
    isInitialized_ (false), isUpdatePassed_ (false), isDisposed_ (false), lastUpdateTimeStep_ (0.0f)
{

}

bool TestObject::Init ()
{
    ready_ = true;
    isInitialized_ = true;
    return true;
}

bool TestObject::Update (float timeStep)
{
    isUpdatePassed_ = true;
    lastUpdateTimeStep_ = timeStep;
    return true;
}

bool TestObject::Dispose ()
{
    isDisposed_ = true;
    return true;
}

bool TestObject::IsInitialized ()
{
    return isInitialized_;
}

bool TestObject::IsUpdatePassed ()
{
    return isUpdatePassed_;
}

bool TestObject::IsDisposed ()
{
    return isDisposed_;
}

float TestObject::GetLastUpdateTimeStep ()
{
    return lastUpdateTimeStep_;
}

TestObject::~TestObject ()
{

}
URHO3D_DEFINE_APPLICATION_MAIN (TestStatesEngineCXX)
