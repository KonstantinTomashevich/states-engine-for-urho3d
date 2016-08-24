#pragma once
#include <Urho3D/Urho3D.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/Container/Vector.h>
#include <Urho3D/Container/Ptr.h>
#include <Urho3D/Engine/Application.h>
#include "StateObject.hpp"
#include "StateObjectsHub.hpp"

/*!
 * Namespace for all States Engine classes.
 */
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
public:
    StateObjectsManager (Urho3D::Context *context);
    /// Calls Init () of all containing state objects.
    virtual bool Init ();
    /// Calls Update (timeStep) of all containing state objects with *IsReady () && IsWillBeUpdated ()*.
    virtual bool Update (float timeStep);
    /// Calls Dispose () of all containing state objects.
    virtual bool Dispose ();
    virtual ~StateObjectsManager ();
};
}
