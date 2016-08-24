#pragma once
#include <Urho3D/Urho3D.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/Engine/Application.h>

/*!
 * \brief Namespace for all States Engine classes.
 */
namespace StatesEngine
{

/*!
 * \brief Basic class for all objects in your game states.
 */
class StateObject : public Urho3D::Object
{
URHO3D_OBJECT (StateObject, Object)
protected:
    /// Is object ready to update?
    bool ready_;
    /// Will this object be removed and deleted after update?
    bool isWillBeDeleted_;
    /// Will this object be updated?
    bool isWillBeUpdated_;
    /// Parent of this object. Can be 0 in some cases.
    StateObject *parent_;
public:
    StateObject (Urho3D::Context *context);
    /// Initialize your object here. Set *ready_ = true* in successfull end of initialize.
    virtual bool Init () = 0;
    /// Update. Will be runned every frame if *ready_ == true* and *isWillBeUpdated_ == true*.
    virtual bool Update (float timeStep) = 0;
    /// Dispose of your object. Remember to set *ready_ = false* if you want to reuse objects!
    virtual bool Dispose () = 0;

    bool IsReady ();
    bool IsWillBeDeleted ();
    virtual bool IsWillBeUpdated ();
    /// You can reimplement this if you want to stop external control of object's update.
    virtual void SetIsWillBeUpdated (bool isWillBeUpdated);

    StateObject *GetParent ();
    void SetParent (StateObject *parent);
    virtual ~StateObject ();
};
}
