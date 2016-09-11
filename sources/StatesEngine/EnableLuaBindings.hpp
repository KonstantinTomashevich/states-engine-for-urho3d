#pragma once
#include "BuildConfig.hpp"
#ifdef STATES_ENGINE_LUA
#include <Urho3D/LuaScript/LuaScript.h>
namespace StatesEngine
{
void EnableLuaBindings (Urho3D::LuaScript *luaScript, bool runLuaInitializer = true);
}
#endif
