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

StateObject *StateObjectsManager::Lua_Get (Urho3D::String typeName)
{
    return Get (typeName).Get ();
}

void StateObjectsManager::Lua_Add (StateObject *object)
{
    Urho3D::SharedPtr <StateObject> objectToAdd (object);
    Add (objectToAdd);
}

bool StateObjectsManager::Lua_Remove (StateObject *object)
{
    for (int index = 0; index < objects_.Size (); index++)
        if (objects_.At (index).Get () == object)
        {
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

Urho3D::Vector <StateObject *> StateObjectsManager::Lua_GetAll (Urho3D::String typeName)
{
    Urho3D::Vector <StateObject *> pointers;
    Urho3D::Vector <Urho3D::SharedPtr <StateObject> > sharedPointers = GetAll (typeName);

    if (sharedPointers.Empty ())
        return pointers;

    for (int index = 0; index < sharedPointers.Size (); index++)
        pointers.Push (sharedPointers.At (index).Get ());
    return pointers;
}
}
