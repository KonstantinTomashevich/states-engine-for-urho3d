#include "StateObjectsHub.hpp"
#include "StatesEngineEvents.hpp"
#include "BuildConfig.hpp"

namespace StatesEngine
{
StateObjectsHub::StateObjectsHub() : objects_ ()
{
    isUseLog_ = false;
}

StateObjectsHub::~StateObjectsHub ()
{

}

bool StateObjectsHub::ReInitAll (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    Urho3D::Vector <Urho3D::SharedPtr<StateObject> > *objects = GetAll (typeName);
    if (!objects->Empty ())
        for (int index = 0; index < objects_.Size (); index++)
        {
            Urho3D::SharedPtr <StateObject> object = objects_.At (index);
            if (object.NotNull ())
            {
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Initializing ") + object->GetTypeName ());
                bool result = object->Init ();
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Result: ") + Urho3D::String (result) + Urho3D::String ("."));
            }
        }
    delete objects;
    return true;
}

bool StateObjectsHub::UpdateAll (Urho3D::String typeName, float timeStep)
{
    assert (typeName != Urho3D::String::EMPTY);
    assert (timeStep > 0.0f);
    Urho3D::Vector <Urho3D::SharedPtr<StateObject> > *objects = GetAll (typeName);
    if (!objects->Empty ())
        for (int index = 0; index < objects->Size (); index++)
        {
            Urho3D::SharedPtr <StateObject> object = objects->At (index);
            if (object.NotNull () && object->IsReady () && object->IsWillBeUpdated ())
            {
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Updating ") + object->GetTypeName ());
                bool result = object->Update (timeStep);
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Result: ") + Urho3D::String (result) + Urho3D::String ("."));
            }
        }

    if (!objects->Empty ())
    {
        int index = 0;
        while (index < objects->Size ())
        {
            Urho3D::SharedPtr<StateObject> object = objects->At (index);
            if (object.NotNull () && object->IsWillBeDeleted ())
            {
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Disposing ") + object->GetTypeName () +
                                 Urho3D::String (" because it's isWillBeDeleted = true"));
                bool result = object->Dispose ();
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Result: ") + Urho3D::String (result) + Urho3D::String ("."));

                objects_.Remove (object);
                objects->Remove (object);
            }
            else
                index++;
        }
        objects_.Compact ();
    }
    delete objects;
    return true;
}

bool StateObjectsHub::DisposeAll (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    Urho3D::Vector <Urho3D::SharedPtr<StateObject> > *objects = GetAll (typeName);
    if (!objects->Empty ())
        for (int index = 0; index < objects->Size (); index++)
        {
            Urho3D::SharedPtr <StateObject> object = objects->At (index);
            if (object.NotNull ())
            {
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Disposing ") + object->GetTypeName ());
                bool result = object->Dispose ();
                if (isUseLog_)
                    GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Result: ") + Urho3D::String (result) + Urho3D::String ("."));
            }
        }
    delete objects;
    return true;
}

Urho3D::SharedPtr <StateObject> StateObjectsHub::Get (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    for (int index = 0; index < objects_.Size (); index++)
        if (objects_.At (index)->GetTypeInfo ()->IsTypeOf (typeName) || typeName == "any")
            return objects_.At (index);
    return Urho3D::SharedPtr <StateObject> ();
}

Urho3D::Vector <Urho3D::SharedPtr <StateObject> > *StateObjectsHub::GetAll (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    Urho3D::Vector <Urho3D::SharedPtr <StateObject> > *array =
            new Urho3D::Vector <Urho3D::SharedPtr <StateObject> > ();
    for (int index = 0; index < objects_.Size (); index++)
        if (objects_.At (index)->GetTypeInfo ()->IsTypeOf (typeName) || typeName == "any")
            array->Push (objects_.At (index));
    return array;
}

void StateObjectsHub::Add (Urho3D::SharedPtr <StateObject> object)
{
    assert (object.NotNull ());
    if (!object->IsReady ())
    {
        object->SetParent (HubAsStateObject ());
        bool result = object->Init ();
        if (isUseLog_)
            GetContext ()->GetSubsystem <Urho3D::Log> ()->Write (Urho3D::LOG_DEBUG, Urho3D::String ("Initializing ") + object->GetTypeName () +
                      Urho3D::String (", result: ") + Urho3D::String (result) + Urho3D::String ("."));
    }
    objects_.Push (object);

    Urho3D::VariantMap eventData;
    eventData [Events::StateObjectAddedToHub::P_STATE_OBJECT] = object.Get ();
    eventData [Events::StateObjectAddedToHub::P_HUB] = this;
    SendUrho3DEvent (Events::E_STATE_OBJECT_ADDED_TO_HUB, eventData);
}

bool StateObjectsHub::Remove (Urho3D::SharedPtr<StateObject> object)
{
    assert (object.NotNull ());
    if (objects_.Contains (object))
    {
        Urho3D::VariantMap eventData;
        eventData [Events::StateObjectRemovedFromHub::P_STATE_OBJECT] = object.Get ();
        eventData [Events::StateObjectRemovedFromHub::P_HUB] = this;
        SendUrho3DEvent (Events::E_STATE_OBJECT_REMOVED_FROM_HUB, eventData);
    }
    return objects_.Remove (object);
}

void StateObjectsHub::RemoveAll (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    Urho3D::Vector <Urho3D::SharedPtr <StateObject> > *array = GetAll (typeName);
    for (int index = 0; index < array->Size (); index++)
        Remove (array->At (index));
    array->Clear ();
    delete array;
}

bool StateObjectsHub::IsContain (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    return Get (typeName);
}

int StateObjectsHub::CountOf (Urho3D::String typeName)
{
    assert (typeName != Urho3D::String::EMPTY);
    Urho3D::Vector <Urho3D::SharedPtr <StateObject> > *result = GetAll (typeName);
    int count = result->Size ();
    delete result;
    return count;
}

Urho3D::SharedPtr <StateObject> StateObjectsHub::Create (Urho3D::String typeName)
{
    Urho3D::SharedPtr <StateObject> object;
    object.StaticCast (GetContext ()->CreateObject (typeName));
    if (object.NotNull ())
        Add (object);
    return object;
}

bool StateObjectsHub::IsUseLog ()
{
    return isUseLog_;
}

void StateObjectsHub::SetIsUseLog (bool isUseLog)
{
    isUseLog_ = isUseLog;
}
}
