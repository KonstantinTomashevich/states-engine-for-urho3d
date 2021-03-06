#include <StatesEngine/BuildConfig.hpp>
#ifdef STATES_ENGINE_LUA
#include "LuaStateObject.hpp"
#include <Urho3D/LuaScript/LuaFunction.h>
#include <Urho3D/ThirdParty/toluapp/tolua++.h>

namespace StatesEngine
{
Urho3D::String LuaStateObject::CreateLuaPreferedName (Urho3D::String luaTypeName)
{
    Urho3D::String preferedName = luaTypeName;
    StateObject *scanningParent = parent_;
    while (scanningParent)
    {
        preferedName = (scanningParent->GetTypeName () + "_" + preferedName);
        scanningParent = scanningParent->GetParent ();
    }
    preferedName.Replace ('.', '_');
    preferedName.Replace ("_G", "global");
    return preferedName;
}

void LuaStateObject::lua_GetReady ()
{
    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
    lua_getfield (luaScript_->GetState (), -1, "ready_");
    ready_ = lua_toboolean (luaScript_->GetState (), -1);
}

void LuaStateObject::lua_SetReady ()
{
    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
    lua_pushboolean (luaScript_->GetState (), ready_);
    lua_setfield (luaScript_->GetState (), -2, "ready_");
}

void LuaStateObject::lua_GetIsWillBeDeleted ()
{
    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
    lua_getfield (luaScript_->GetState (), -1, "isWillBeDeleted_");
    isWillBeDeleted_ = lua_toboolean (luaScript_->GetState (), -1);
}

void LuaStateObject::lua_SetIsWillBeUpdated ()
{
    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
    lua_pushboolean (luaScript_->GetState (), isWillBeUpdated_);
    lua_setfield (luaScript_->GetState (), -2, "isWillBeUpdated_");
}

void LuaStateObject::lua_GetIsWillBeUpdated ()
{
    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
    lua_getfield (luaScript_->GetState (), -1, "isWillBeUpdated_");
    isWillBeUpdated_ = lua_toboolean (luaScript_->GetState (), -1);
}

void LuaStateObject::lua_SetParent ()
{
    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());

    Urho3D::String parentTypeName;
    if (parent_)
        parentTypeName = parent_->GetTypeName ();
    else
        parentTypeName = "nil";

    tolua_pushusertype (luaScript_->GetState (), parent_, parentTypeName.CString ());
    lua_setfield (luaScript_->GetState (), -2, "parent_");
}

void LuaStateObject::lua_SetCXXObject ()
{
    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
    tolua_pushusertype (luaScript_->GetState (), this, GetTypeName ().CString ());
    lua_setfield (luaScript_->GetState (), -2, "cxxObject_");
}

LuaStateObject::LuaStateObject (Urho3D::Context *context) : StateObject (context)
{
    luaObjectName_ = "";
    luaObjectTypeName_ = "";
    luaScript_ = context_->GetSubsystem <Urho3D::LuaScript> ();
    assert (luaScript_);
}

bool LuaStateObject::Init ()
{
    if (luaObjectName_ != "")
    {
        lua_SetCXXObject ();
        Urho3D::String luaCommand = "_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ + ":Init ()";
        luaScript_->ExecuteString (luaCommand);
        lua_GetReady ();
        lua_GetIsWillBeUpdated ();
        lua_GetIsWillBeDeleted ();

        lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
        lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
        lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
        lua_getfield (luaScript_->GetState (), -1, "lastInitReturn_");

        if (lua_type (luaScript_->GetState (), -1) == LUA_TBOOLEAN)
        {
            bool result = lua_toboolean (luaScript_->GetState (), -1);
            luaScript_->ExecuteString ("_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ + ".lastInitReturn_ = nil");
            return result;
        }
        else
            return ready_;
    }
    else
        return false;
}

bool LuaStateObject::Update (float timeStep)
{
    if (luaObjectName_ != "")
    {
        lua_SetCXXObject ();
        Urho3D::String luaCommand = "_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ +
                ":Update (" + Urho3D::String (timeStep) + ")";
        luaScript_->ExecuteString (luaCommand);
        lua_GetReady ();
        lua_GetIsWillBeUpdated ();
        lua_GetIsWillBeDeleted ();

        lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
        lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
        lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
        lua_getfield (luaScript_->GetState (), -1, "lastUpdateReturn_");

        if (lua_type (luaScript_->GetState (), -1) == LUA_TBOOLEAN)
        {
            bool result = lua_toboolean (luaScript_->GetState (), -1);
            luaScript_->ExecuteString ("_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ + ".lastUpdateReturn_ = nil");
            return result;
        }
        else
            return ready_;
    }
    else
        return false;
}

bool LuaStateObject::Dispose ()
{
    if (luaObjectName_ != "")
    {
        lua_SetCXXObject ();
        Urho3D::String luaCommand = "_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ + ":Dispose ()";
        luaScript_->ExecuteString (luaCommand);
        lua_GetReady ();
        lua_GetIsWillBeUpdated ();
        lua_GetIsWillBeDeleted ();

        lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
        lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
        lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
        lua_getfield (luaScript_->GetState (), -1, "lastDisposeReturn_");

        if (lua_type (luaScript_->GetState (), -1) == LUA_TBOOLEAN)
        {
            bool result = lua_toboolean (luaScript_->GetState (), -1);
            luaScript_->ExecuteString ("_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ + ".lastDisposeReturn_ = nil");
            return result;
        }
        else
            return !ready_;
    }
    else
        return false;
}

void LuaStateObject::SetIsWillBeUpdated (bool isWillBeUpdated)
{
    StateObject::SetIsWillBeUpdated (isWillBeUpdated);
    lua_SetIsWillBeUpdated ();
}

void LuaStateObject::SetParent (StateObject *parent)
{
    StateObject::SetParent (parent);
    if (luaObjectName_ != "")
        lua_SetParent ();
}

void LuaStateObject::CreateObject (Urho3D::String luaTypeName, Urho3D::String arguments)
{
    luaObjectTypeName_ = luaTypeName;
    Urho3D::String preferedName = CreateLuaPreferedName (luaTypeName);
    Urho3D::String resultingName;
    int lastIndex = -1;

    do
    {
        lastIndex++;
        resultingName = preferedName + Urho3D::String (lastIndex);

        lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
        lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
        lua_getfield (luaScript_->GetState (), -1, resultingName.CString ());
    }
    while (lua_istable (luaScript_->GetState (), -1));

    luaObjectName_ = resultingName;
    Urho3D::String luaCommand = "_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ +
            " = " + luaTypeName + "(" + arguments + ")";
    luaScript_->ExecuteString (luaCommand);

    lua_SetParent ();
    lua_SetIsWillBeUpdated ();
    lua_SetReady ();
}

Urho3D::String LuaStateObject::GetObjectName ()
{
    return luaObjectName_;
}

Urho3D::String LuaStateObject::GetObjectTypeName ()
{
    return luaObjectTypeName_;
}

bool LuaStateObject::IsObjectNotNull ()
{
    if (luaObjectName_ == "")
        return false;

    lua_getglobal (luaScript_->GetState (), "StatesEngineUtils");
    lua_getfield (luaScript_->GetState (), -1, "LuaStateObjects");
    lua_getfield (luaScript_->GetState (), -1, luaObjectName_.CString ());
    return (lua_istable (luaScript_->GetState (), -1));
}

void LuaStateObject::ReleaseObject ()
{
    Urho3D::String luaCommand = "_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ + " = nil";
    luaScript_->ExecuteString (luaCommand);
    luaObjectName_ = "";
    luaObjectTypeName_ = "";
}

LuaStateObject::~LuaStateObject ()
{

}
}
#endif
