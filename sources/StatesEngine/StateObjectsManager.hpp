#pragma once
#include <Urho3D/Urho3D.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/Container/Vector.h>
#include <Urho3D/Container/Ptr.h>
#include <Urho3D/Engine/Application.h>
#include "StateObject.hpp"
#include "StateObjectsHub.hpp"
#include "BuildConfig.hpp"

#ifdef STATES_ENGINE_LUA
#include <StatesEngine/Lua/LuaStateObject.hpp>
#endif

/// \brief Namespace for all States Engine classes.
namespace StatesEngine
{

/// State object that can contain and manage other state objects.
class StateObjectsManager : public StateObject, public StateObjectsHub
{
URHO3D_OBJECT (StateObjectsManager, StateObject)
protected:
    virtual StateObject *HubAsStateObject ();
    virtual Urho3D::Context *GetContext ();
    virtual void SendUrho3DEvent (Urho3D::StringHash eventType, Urho3D::VariantMap &eventData);

#ifdef STATES_ENGINE_LUA
    Urho3D::PODVector <StateObject *> temporaryPodVector_;
#endif
public:
    StateObjectsManager (Urho3D::Context *context);
    /// Calls Init () of all containing state objects.
    virtual bool Init ();
    /// Calls Update (timeStep) of all containing state objects with *IsReady () && IsWillBeUpdated ()*.
    virtual bool Update (float timeStep);
    /// Calls Dispose () of all containing state objects.
    virtual bool Dispose ();
    virtual ~StateObjectsManager ();

#ifdef STATES_ENGINE_LUA
    /// \brief version of StateObjectsHub::Get for Lua, because Lua don't support Urho3D::SharedPtr's.
    StateObject *Lua_Get (Urho3D::String typeName);
    /// \brief version of StateObjectsHub::Add for Lua, because Lua don't support Urho3D::SharedPtr's.
    void Lua_Add (StateObject *object);
    /// \brief version of StateObjectsHub::Remove for Lua, because Lua don't support Urho3D::SharedPtr's.
    bool Lua_Remove (StateObject *object, bool dontDelete = false);
    /// \brief version of StateObjectsHub::Create for Lua, because Lua don't support Urho3D::SharedPtr's.
    StateObject *Lua_Create (Urho3D::String typeName);
    /// \brief version of StateObjectsHub::GetAll for Lua, because Lua don't support Urho3D::SharedPtr's.
    Urho3D::PODVector <StateObject *> &Lua_GetAll (Urho3D::String typeName);
    /// \brief version of StateObjectsHub::RemoveAll for Lua, because Lua don't support Urho3D::SharedPtr's.
    void Lua_RemoveAll (Urho3D::String typeName, bool dontDelete = false);
    /// \brief function for easier creating of lua objects. Creates LuaStateObject and runs CreateObject with given arguments.
    LuaStateObject *Lua_CreateLuaStateObject (Urho3D::String luaTypeName, Urho3D::String arguments = "");
    /// \brief function for getting LuaStateObjects by luaObjectTypeName.
    LuaStateObject *Lua_GetByLuaTypeName (Urho3D::String typeName);
    /// \brief function for getting LuaStateObjects by luaObjectTypeName.
    Urho3D::PODVector <StateObject *> &Lua_GetAllByLuaTypeName (Urho3D::String typeName);
    /// \brief function for removing LuaStateObjects by luaObjectTypeName.
    void Lua_RemoveAllByLuaTypeName (Urho3D::String typeName, bool dontDelete = false);
#endif
};
}
