#include "EnableLuaBindings.hpp"
#include <Urho3D/ThirdParty/toluapp/tolua++.h>
#include <Urho3D/LuaScript/ToluaUtils.h>
#include "BuildConfig.hpp"

#include "LuaStateObject.hpp"
#include "SceneContainer.hpp"
#include "StateObject.hpp"
#include "StateObjectsManager.hpp"
#include "StatesEngine.hpp"
#include "StatesEngineEvents.hpp"

namespace ToLuaXX_LuaStateObject
{
#include "generated/tolua_LuaStateObject.cpp"
}

namespace ToLuaXX_SceneContainer
{
#include "generated/tolua_SceneContainer.cpp"
}

namespace ToLuaXX_StateObject
{
#include "generated/tolua_StateObject.cpp"
}

namespace ToLuaXX_StateObjectsManager
{
#include "generated/tolua_StateObjectsManager.cpp"
}

namespace ToLuaXX_StatesEngine
{
#include "generated/tolua_StatesEngine.cpp"
}

namespace ToLuaXX_StatesEngineEvents
{
#include "generated/tolua_StatesEngineEvents.cpp"
}


namespace StatesEngine
{
namespace ToLua
{
void EnableAll (Urho3D::LuaScript *luaScript)
{
    EnableLuaStateObject (luaScript);
    EnableSceneContainer (luaScript);
    EnableStateObject (luaScript);
    EnableStateObjectsManager (luaScript);
    EnableStatesEngine (luaScript);
    EnableStatesEngineEvents (luaScript);

    LuaInitLuaStateObject (luaScript);
    LuaInitStatesEngine (luaScript);
    LuaInitStatesEngineEvents (luaScript);

}

void EnableLuaStateObject (Urho3D::LuaScript *luaScript)
{
    ToLuaXX_LuaStateObject::tolua_LuaStateObject_open (luaScript->GetState ());
}

void LuaInitLuaStateObject (Urho3D::LuaScript *luaScript)
{
    luaScript->ExecuteFile ("ToLuaPackagesInitializers/__init.LuaStateObject.lua");
}

void EnableSceneContainer (Urho3D::LuaScript *luaScript)
{
    ToLuaXX_SceneContainer::tolua_SceneContainer_open (luaScript->GetState ());
}

void EnableStateObject (Urho3D::LuaScript *luaScript)
{
    ToLuaXX_StateObject::tolua_StateObject_open (luaScript->GetState ());
}

void EnableStateObjectsManager (Urho3D::LuaScript *luaScript)
{
    ToLuaXX_StateObjectsManager::tolua_StateObjectsManager_open (luaScript->GetState ());
}

void EnableStatesEngine (Urho3D::LuaScript *luaScript)
{
    ToLuaXX_StatesEngine::tolua_StatesEngine_open (luaScript->GetState ());
}

void LuaInitStatesEngine (Urho3D::LuaScript *luaScript)
{
    luaScript->ExecuteFile ("ToLuaPackagesInitializers/__init.StatesEngine.lua");
}

void EnableStatesEngineEvents (Urho3D::LuaScript *luaScript)
{
    ToLuaXX_StatesEngineEvents::tolua_StatesEngineEvents_open (luaScript->GetState ());
}

void LuaInitStatesEngineEvents (Urho3D::LuaScript *luaScript)
{
    luaScript->ExecuteFile ("ToLuaPackagesInitializers/__init.StatesEngineEvents.lua");
}


}
}
