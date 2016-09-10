#pragma once
#include <Urho3D/Math/StringHash.h>
#include <Urho3D/Core/Object.h>

/// \brief Namespace for all States Engine classes.
namespace StatesEngine
{
/// \brief Namespace for all States Engine events.
namespace Events
{
URHO3D_EVENT (E_STATE_OBJECT_ADDED_TO_HUB, StateObjectAddedToHub)
{
    /// StateObject *.
    URHO3D_PARAM (P_STATE_OBJECT, StateObject);
    /// StateObjectsHub *.
    URHO3D_PARAM (P_HUB, Hub);
}

URHO3D_EVENT (E_STATE_OBJECT_REMOVED_FROM_HUB, StateObjectRemovedFromHub)
{
    /// StateObject *.
    URHO3D_PARAM (P_STATE_OBJECT, StateObject);
    /// StateObjectsHub *.
    URHO3D_PARAM (P_HUB, Hub);
}
}
}
