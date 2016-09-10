#include "StateObject.hpp"
#include "Urho3D/IO/Log.h"
#include "BuildConfig.hpp"
namespace StatesEngine
{

StateObject::StateObject (Urho3D::Context *context) : Urho3D::Object (context)
{
    ready_ = false;
    isWillBeDeleted_ = false;
    isWillBeUpdated_ = true;
    parent_ = 0;
}

bool StateObject::Init ()
{
    assert (false);
}

bool StateObject::Update (float timeStep)
{
    assert (false);
}

bool StateObject::Dispose ()
{
    assert (false);
}

bool StateObject::IsReady ()
{
    return ready_;
}

bool StateObject::IsWillBeDeleted ()
{
    return isWillBeDeleted_;
}

bool StateObject::IsWillBeUpdated ()
{
    return isWillBeUpdated_;
}

void StateObject::SetIsWillBeUpdated (bool isWillBeUpdated)
{
    isWillBeUpdated_ = isWillBeUpdated;
}

StateObject *StateObject::GetParent ()
{
    return parent_;
}

void StateObject::SetParent (StateObject *parent)
{
    parent_ = parent;
}

StateObject::~StateObject ()
{

}
}
