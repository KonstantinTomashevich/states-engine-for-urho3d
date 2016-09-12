#include "StateObjectsManager.hpp"
#include "BuildConfig.hpp"
namespace StatesEngine
{
StateObject *StateObjectsManager::HubAsStateObject()
{
    return this;
}

Urho3D::Context *StateObjectsManager::GetContext()
{
    return context_;
}

void StateObjectsManager::SendUrho3DEvent (Urho3D::StringHash eventType, Urho3D::VariantMap &eventData)
{
    SendEvent (eventType, eventData);
}

StateObjectsManager::StateObjectsManager (Urho3D::Context *context) : StateObject (context), StateObjectsHub ()
{

}

bool StateObjectsManager::Init ()
{
    return ReInitAll ("any");
}

bool StateObjectsManager::Update (float timeStep)
{
    assert (timeStep > 0.0f);
    return UpdateAll ("any", timeStep);
}

bool StateObjectsManager::Dispose ()
{
    return DisposeAll ("any");
}

StateObjectsManager::~StateObjectsManager ()
{
    Dispose ();
    RemoveAll ("any");
}

#ifdef STATES_ENGINE_LUA
StateObject *StateObjectsManager::Lua_Get (Urho3D::String typeName)
{
    return Get (typeName).Get ();
}

void StateObjectsManager::Lua_Add (StateObject *object)
{
    Urho3D::SharedPtr <StateObject> objectToAdd (object);
    Add (objectToAdd);
}

bool StateObjectsManager::Lua_Remove (StateObject *object, bool dontDelete)
{
    for (int index = 0; index < objects_.Size (); index++)
        if (objects_.At (index).Get () == object)
        {
            if (dontDelete)
            {
                Urho3D::SharedPtr <StateObject> temporaryPtr = objects_.At (index);
                objects_.Remove (objects_.At (index));
                temporaryPtr.Detach ();
            }
            else
                objects_.Remove (objects_.At (index));
            return true;
        }
    return false;
}

StateObject *StateObjectsManager::Lua_Create (Urho3D::String typeName)
{
    Urho3D::SharedPtr <StateObject> created = Create (typeName);
    return created.Get ();
}

Urho3D::PODVector <StateObject *> &StateObjectsManager::Lua_GetAll (Urho3D::String typeName)
{
    temporaryPodVector_.Clear ();
    Urho3D::Vector <Urho3D::SharedPtr <StateObject> > sharedPointers = GetAll (typeName);

    if (sharedPointers.Empty ())
        return temporaryPodVector_;

    for (int index = 0; index < sharedPointers.Size (); index++)
        temporaryPodVector_.Push (sharedPointers.At (index).Get ());
    return temporaryPodVector_;
}

void StateObjectsManager::Lua_RemoveAll(Urho3D::String typeName, bool dontDelete)
{
    assert (typeName != Urho3D::String::EMPTY);
    int index = 0;
    while (!objects_.Empty () && index < objects_.Size ())
    {
        if (objects_.At (index)->GetTypeInfo ()->IsTypeOf (typeName) || typeName == "any")
        {
            if (dontDelete)
            {
                Urho3D::SharedPtr <StateObject> temporaryPtr = objects_.At (index);
                objects_.Remove (objects_.At (index));
                temporaryPtr.Detach ();
            }
            else
                objects_.Remove (objects_.At (index));
        }
        else
            index++;
    }
}

LuaStateObject *StateObjectsManager::Lua_CreateLuaStateObject (Urho3D::String luaTypeName, Urho3D::String arguments)
{
    Urho3D::SharedPtr <LuaStateObject> luaStateObject;
    luaStateObject.StaticCast (Create ("LuaStateObject"));
    luaStateObject->CreateObject (luaTypeName, arguments);
    luaStateObject->Init ();
    return luaStateObject.Get ();
}

LuaStateObject *StateObjectsManager::Lua_GetByLuaTypeName(Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    Urho3D::Vector <Urho3D::SharedPtr <LuaStateObject> > luaStateObjects = GetAll <LuaStateObject> ();
    for (int index = 0; index < luaStateObjects.Size (); index++)
        if (luaStateObjects.At (index)->GetObjectTypeName () == typeName)
            return luaStateObjects.At (index).Get ();
    return 0;
}

Urho3D::PODVector <StateObject *> &StateObjectsManager::Lua_GetAllByLuaTypeName (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    temporaryPodVector_.Clear ();
    Urho3D::Vector <Urho3D::SharedPtr <LuaStateObject> > luaStateObjects = GetAll <LuaStateObject> ();
    for (int index = 0; index < luaStateObjects.Size (); index++)
        if (luaStateObjects.At (index)->GetObjectTypeName () == typeName)
            temporaryPodVector_.Push (luaStateObjects.At (index));
    return temporaryPodVector_;
}

void StateObjectsManager::Lua_RemoveAllByLuaTypeName (Urho3D::String typeName, bool dontDelete)
{
    assert (typeName != Urho3D::String::EMPTY);
    int index = 0;
    while (!objects_.Empty () && index < objects_.Size ())
    {
        if (objects_.At (index)->GetTypeInfo ()->IsTypeOf <LuaStateObject> () &&
                ( (LuaStateObject *) objects_.At (index).Get ())->GetObjectTypeName () == typeName)
        {
            if (dontDelete)
            {
                Urho3D::SharedPtr <StateObject> temporaryPtr = objects_.At (index);
                objects_.Remove (objects_.At (index));
                temporaryPtr.Detach ();
            }
            else
                objects_.Remove (objects_.At (index));
        }
        else
            index++;
    }
}
#endif
}
