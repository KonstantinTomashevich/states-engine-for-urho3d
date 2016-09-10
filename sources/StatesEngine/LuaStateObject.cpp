#include "BuildConfig.hpp"
#ifdef STATES_ENGINE_LUA
#include "LuaStateObject.hpp"
#include <Urho3D/LuaScript/LuaFunction.h>
#include <Urho3D/ThirdParty/toluapp/tolua++.h>

#include <Urho3D/IO/Log.h>

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
    Urho3D::LuaFunction *setter = luaScript_->GetFunction (Urho3D::String ("_G.StatesEngineUtils.LuaStateObjects.") +
                                                           luaObjectName_ + Urho3D::String (":SetReady"));
    if (setter)
    {
        if (!setter->BeginCall ())
        {
            assert (false);
            return;
        }
        setter->PushBool (ready_);
        if (!setter->EndCall ())
        {
            assert (false);
            return;
        }
    }
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
    tolua_pushusertype (luaScript_->GetState (), parent_, GetTypeName ().CString ());
    lua_setfield (luaScript_->GetState (), -2, "parent_");
}

LuaStateObject::LuaStateObject (Urho3D::Context *context) : StateObject (context)
{
    luaObjectName_ = "";
    luaScript_ = context_->GetSubsystem <Urho3D::LuaScript> ();
    assert (luaScript_);
}

bool LuaStateObject::Init ()
{
    if (luaObjectName_ != "")
    {
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
    lua_SetParent ();
}

void LuaStateObject::CreateObject (Urho3D::String luaTypeName, Urho3D::String arguments)
{
    Urho3D::LuaFunction *checker = luaScript_->GetFunction ("_G.StatesEngineUtils.IsLuaStateObjectExists");
    assert (checker);
    Urho3D::String preferedName = CreateLuaPreferedName (luaTypeName);
    Urho3D::String resultingName;
    int lastIndex = -1;

    if (checker)
    {
        do
        {
            lastIndex++;
            resultingName = preferedName + Urho3D::String (lastIndex);

            if (!checker->BeginCall ())
            {
                assert (false);
                return;
            }
            checker->PushString ("nothing");
            checker->PushString (resultingName);
            if (!checker->EndCall (1))
            {
                assert (false);
                return;
            }
        }
        while (lua_tointeger (luaScript_->GetState (), -1) == 1);

        luaObjectName_ = resultingName;
        Urho3D::String luaCommand = "_G.StatesEngineUtils.LuaStateObjects." + luaObjectName_ +
                " = " + luaTypeName + "(" + arguments + ")";
        luaScript_->ExecuteString (luaCommand);
    }
}

Urho3D::String LuaStateObject::GetObjectName ()
{
    return luaObjectName_;
}

bool LuaStateObject::IsObjectNotNull ()
{
    if (luaObjectName_ == "")
        return false;

    Urho3D::LuaFunction *checker = luaScript_->GetFunction ("_G.StatesEngineUtils.IsLuaStateObjectExists");
    assert (checker);
    if (checker)
    {
        if (!checker->BeginCall ())
        {
            assert (false);
            return false;
        }
        checker->PushString ("nothing");
        checker->PushString (luaObjectName_);
        if (!checker->EndCall (1))
        {
            assert (false);
            return false;
        }
        return lua_toboolean (luaScript_->GetState (), 0);
    }
    else
        return false;
}

void LuaStateObject::ReleaseLuaObject ()
{
    if (luaObjectName_ != "")
    {
        Urho3D::LuaFunction *releaser = luaScript_->GetFunction ("_G.StatesEngineUtils.ReleaseLuaStateObject");
        assert (releaser);
        if (releaser)
        {
            if (!releaser->BeginCall ())
            {
                assert (false);
                return;
            }
            releaser->PushString ("nothing");
            releaser->PushString (luaObjectName_);
            if (!releaser->EndCall (1))
            {
                assert (false);
                return;
            }
            bool result = lua_toboolean (luaScript_->GetState (), 0);
            if (result)
                luaObjectName_ = "";
        }
    }
}

LuaStateObject::~LuaStateObject ()
{

}
}
#endif
