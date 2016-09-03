#pragma once
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Container/Vector.h>
#include <StatesEngine/StateObject.hpp>

class TestObject : public StatesEngine::StateObject
{
URHO3D_OBJECT (TestObject, StatesEngine::StateObject)
protected:
    bool isInitialized_;
    bool isUpdatePassed_;
    bool isDisposed_;
    float lastUpdateTimeStep_;
public:
    TestObject (Urho3D::Context *context);
    bool Init();
    bool Update(float timeStep);
    bool Dispose();

    bool IsInitialized ();
    bool IsUpdatePassed ();
    bool IsDisposed ();
    float GetLastUpdateTimeStep ();
    virtual ~TestObject ();
};

class TestStatesEngineCXX : public Urho3D::Application
{
URHO3D_OBJECT (TestStatesEngineCXX, Urho3D::Application)
public:
    TestStatesEngineCXX (Urho3D::Context *context);
    virtual void Setup ();
    virtual void Start ();
    virtual void Stop ();
    virtual ~TestStatesEngineCXX();
};
