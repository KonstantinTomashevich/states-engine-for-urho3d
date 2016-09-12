#include <StatesEngine/BuildConfig.hpp>
#ifdef STATES_ENGINE_LUA
#include <StatesEngine/StatesEngineAll.hpp>
#include "EnableLuaBindings.hpp"
#include <Urho3D/ThirdParty/toluapp/tolua++.h>
#include <Urho3D/LuaScript/ToluaUtils.h>
#include "tolua_AllStatesEngine.cpp"

namespace StatesEngine
{
void EnableLuaBindings (Urho3D::LuaScript *luaScript, bool runLuaInitializer)
{
    tolua_AllStatesEngine_open (luaScript->GetState ());
    if (runLuaInitializer)
        luaScript->ExecuteFile ("StatesEngineLua/InitStatesEngine.lua");
}
}
#endif
