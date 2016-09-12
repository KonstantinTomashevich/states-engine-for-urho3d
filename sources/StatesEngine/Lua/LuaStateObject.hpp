#include <StatesEngine/BuildConfig.hpp>
#ifdef STATES_ENGINE_LUA
#pragma once
#include <Urho3D/Urho3D.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/LuaScript/LuaScript.h>
#include <StatesEngine/StateObject.hpp>

namespace StatesEngine
{
class LuaStateObject : public StateObject
{
URHO3D_OBJECT (LuaStateObject, StateObject)
protected:
    Urho3D::String luaObjectName_;
    Urho3D::LuaScript *luaScript_;

    Urho3D::String CreateLuaPreferedName (Urho3D::String luaTypeName);
    void lua_GetReady ();
    void lua_SetReady ();
    void lua_GetIsWillBeDeleted ();
    void lua_SetIsWillBeUpdated ();
    void lua_GetIsWillBeUpdated();
    void lua_SetParent ();
public:
    LuaStateObject (Urho3D::Context *context);
    /// \brief Initialize your object here. Set *ready_ = true* in successfull end of initialize.
    virtual bool Init ();
    /// \brief Update. Will be runned every frame if *ready_ == true* and *isWillBeUpdated_ == true*.
    virtual bool Update (float timeStep);
    /// \brief Dispose of your object. Remember to set *ready_ = false* if you want to reuse objects!
    virtual bool Dispose ();

    virtual void SetIsWillBeUpdated (bool isWillBeUpdated);
    virtual void SetParent (StateObject *parent);

    /// \brief Creates lua instance object with given type and stores it.
    /// \param luaTypeName way to lua class-table, see Lua OOP.
    /// \param arguments [optional] arguments for object constructor.
    void CreateObject (Urho3D::String luaTypeName, Urho3D::String arguments = "");
    Urho3D::String GetObjectName ();
    bool IsObjectNotNull ();
    void ReleaseObject ();
    virtual ~LuaStateObject ();
};
}
#endif
