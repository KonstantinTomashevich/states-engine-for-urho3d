#pragma once
#include <Urho3D/Urho3D.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/Engine/Application.h>
#include "StateObjectsManager.hpp"
#include "BuildConfig.hpp"

/// \brief Namespace for all States Engine classes.
namespace StatesEngine
{

/// States Engine subsystem.
class StatesEngineSubsystem : public Urho3D::Object
{
URHO3D_OBJECT (StatesEngineSubsystem, Object)
protected:
    /// Current root state object, by default this is null.
    Urho3D::SharedPtr <StateObject> currentState_;
    static StatesEngineSubsystem *instance_;
public:
    StatesEngineSubsystem (Urho3D::Context *context);
    /// Subscribes to Urho3D::E_UPDATE event.
    bool Init ();
    /// Calls Update (timeStep) of root state object.
    void Update (Urho3D::StringHash eventType, Urho3D::VariantMap& info);
    /// Calls Dispose () of root state object.
    bool Dispose ();

    Urho3D::SharedPtr <StateObject> GetState ();
    bool HasState ();
    void DisposeState ();
    /// See Urho3D::TypeInfo ()::IsTypeOf ().
    bool IsState (Urho3D::String typeName);

    /// \brief Setups *state* as current root state.
    /// \param [in] state state that you want to set as root.
    void SetupState (Urho3D::SharedPtr <StateObject> state);
    static StatesEngineSubsystem *GetInstance ();
    ~StatesEngineSubsystem ();

    template <class T> Urho3D::SharedPtr <T> GetState ()
    {
        assert (IsState (T::GetTypeNameStatic ()));
        Urho3D::SharedPtr <T> ptr;
        ptr.StaticCast (GetState ());
        return ptr;
    }

    /// \brief version of StatesEngineSubsystem::GetState for Lua, because Lua don't support Urho3D::SharedPtr's.
    StateObject *Lua_GetState ();
    /// \brief version of StatesEngineSubsystem::SetupState for Lua, because Lua don't support Urho3D::SharedPtr's.
    void Lua_SetupState (StateObject *state, bool isKeepPrevious = false);
};
}
