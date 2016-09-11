#include "StatesEngine.hpp"
#include "BuildConfig.hpp"
namespace StatesEngine
{
StatesEngineSubsystem *StatesEngineSubsystem::instance_ = 0;
StatesEngineSubsystem::StatesEngineSubsystem (Urho3D::Context *context) : Urho3D::Object (context), currentState_ ()
{
    assert (!instance_);
    instance_ = this;
}

bool StatesEngineSubsystem::Init ()
{
    SubscribeToEvent (Urho3D::E_UPDATE, URHO3D_HANDLER (StatesEngineSubsystem, Update));
    return true;
}

void StatesEngineSubsystem::Update (Urho3D::StringHash eventType, Urho3D::VariantMap &info)
{
    float timeStep = info [Urho3D::Update::P_TIMESTEP].GetFloat ();
    if (HasState ())
        currentState_->Update (timeStep);
}

bool StatesEngineSubsystem::Dispose ()
{
    DisposeState ();
    return true;
}

Urho3D::SharedPtr<StateObject> StatesEngineSubsystem::GetState()
{
    return currentState_;
}

bool StatesEngineSubsystem::HasState ()
{
    return currentState_.NotNull ();
}

void StatesEngineSubsystem::DisposeState ()
{
    currentState_.Reset ();
}

bool StatesEngineSubsystem::IsState (Urho3D::String typeName)
{
    if (HasState ())
        return (currentState_->GetTypeInfo ()->IsTypeOf (typeName));
    else
        return false;
}

void StatesEngineSubsystem::SetupState (Urho3D::SharedPtr <StateObject> state)
{
    currentState_ = state;
    if (HasState ())
    {
        currentState_->SetParent (0);
        currentState_->Init ();
    }
}

StatesEngineSubsystem *StatesEngineSubsystem::GetInstance ()
{
    return instance_;
}

StatesEngineSubsystem::~StatesEngineSubsystem ()
{
    Dispose ();
}

StateObject *StatesEngineSubsystem::Lua_GetState ()
{
    return currentState_.Get ();
}

void StatesEngineSubsystem::Lua_SetupState (StateObject *state)
{
    if (currentState_.Get () != state)
    {
        Urho3D::SharedPtr <StateObject> newState (state);
        SetupState (newState);
    }
}
}
