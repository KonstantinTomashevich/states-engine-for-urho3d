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
}
