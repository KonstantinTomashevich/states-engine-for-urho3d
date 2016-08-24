#include "StatesEngine.hpp"
#include "BuildConfig.hpp"
namespace StatesEngine
{

StatesEngine::StatesEngine (Urho3D::Context *context) : Urho3D::Object (context), currentState_ ()
{

}

bool StatesEngine::Init ()
{
    SubscribeToEvent (Urho3D::E_UPDATE, URHO3D_HANDLER (StatesEngine, Update));
    return true;
}

void StatesEngine::Update (Urho3D::StringHash eventType, Urho3D::VariantMap &info)
{
    float timeStep = info [Urho3D::Update::P_TIMESTEP].GetFloat ();
    if (HasState ())
        currentState_->Update (timeStep);
}

bool StatesEngine::Dispose ()
{
    DisposeState ();
    return true;
}

Urho3D::SharedPtr<StateObject> StatesEngine::GetState()
{
    return currentState_;
}

bool StatesEngine::HasState ()
{
    return currentState_.NotNull ();
}

void StatesEngine::DisposeState ()
{
    currentState_.Reset ();
}

bool StatesEngine::IsState (Urho3D::String typeName)
{
    if (HasState ())
        return (currentState_->GetTypeInfo ()->IsTypeOf (typeName));
    else
        return false;
}

void StatesEngine::SetupState (Urho3D::SharedPtr <StateObject> state)
{
    currentState_ = state;
    if (HasState ())
    {
        currentState_->SetParent (0);
        currentState_->Init ();
    }
}

StatesEngine::~StatesEngine ()
{
    Dispose ();
}
}
