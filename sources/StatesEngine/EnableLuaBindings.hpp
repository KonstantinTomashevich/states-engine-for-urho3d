#pragma once
#include <Urho3D/LuaScript/LuaScript.h>
namespace StatesEngine
{
namespace ToLua
{
void EnableAll (Urho3D::LuaScript *luaScript);
void EnableLuaStateObject (Urho3D::LuaScript *luaScript);
void LuaInitLuaStateObject (Urho3D::LuaScript *luaScript);
void EnableSceneContainer (Urho3D::LuaScript *luaScript);
void EnableStateObject (Urho3D::LuaScript *luaScript);
void EnableStateObjectsManager (Urho3D::LuaScript *luaScript);
void EnableStatesEngine (Urho3D::LuaScript *luaScript);
void LuaInitStatesEngine (Urho3D::LuaScript *luaScript);
void EnableStatesEngineEvents (Urho3D::LuaScript *luaScript);
void LuaInitStatesEngineEvents (Urho3D::LuaScript *luaScript);

}
}
