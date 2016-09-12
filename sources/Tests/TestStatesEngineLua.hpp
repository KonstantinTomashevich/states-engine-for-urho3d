#pragma once
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>

class TestStatesEngineLua : public Urho3D::Application
{
URHO3D_OBJECT (TestStatesEngineLua, Urho3D::Application)
public:
    TestStatesEngineLua (Urho3D::Context *context);
    virtual void Setup ();
    virtual void Start ();
    virtual void Stop ();
    virtual ~TestStatesEngineLua();
};
