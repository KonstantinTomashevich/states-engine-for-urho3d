#pragma once
#include <Urho3D/Urho3D.h>
#include <Urho3D/Container/Vector.h>
#include <Urho3D/Container/Ptr.h>
#include <Urho3D/IO/Log.h>
#include "StateObject.hpp"
#include "BuildConfig.hpp"

/// \brief Namespace for all States Engine classes.
namespace StatesEngine
{

/// \brief Basic class for managing state objects.
class StateObjectsHub
{
protected:
    Urho3D::Vector <Urho3D::SharedPtr <StateObject> > objects_;
    bool isUseLog_;

    virtual StateObject *HubAsStateObject () = 0;
    virtual Urho3D::Context *GetContext () = 0;
    virtual void SendUrho3DEvent (Urho3D::StringHash eventType, Urho3D::VariantMap &eventData) = 0;
public:
    StateObjectsHub ();
    /// \brief Calls Init () of all objects with given type.
    bool ReInitAll (Urho3D::String typeName);
    /// \brief Calls Update (timeStep) of all objects with given type and *IsReady () && IsWillBeUpdated ()*.
    bool UpdateAll (Urho3D::String typeName, float timeStep);
    /// \brief Calls Dispose () of all objects with given type.
    bool DisposeAll (Urho3D::String typeName);
    bool IsUseLog ();
    void SetIsUseLog (bool isUseLog);
    virtual ~StateObjectsHub ();

    /// \brief Returns first state object with given type.
    Urho3D::SharedPtr <StateObject> Get (Urho3D::String typeName);
    /// \brief Adds given state object and calls Init () of it if it's *IsReady () == false*.
    void Add (Urho3D::SharedPtr <StateObject> object);
    ///  \brief Removes given object from state.
    ///  \param [in] object object to remove.
    ///  \param [in] isDelete call *delete object;* after removing?
    bool Remove (Urho3D::SharedPtr <StateObject> object);

    /// Returns new vector with all state objects with given type.
    Urho3D::Vector <Urho3D::SharedPtr <StateObject> > GetAll (Urho3D::String typeName);

    ///  \brief Removes all objects with given type.
    ///  \param [in] typeName objects type name, see Urho3D::Object::GetTypeName ().
    ///  \param [in] isDelete call *delete object;* after removing?
    void RemoveAll (Urho3D::String typeName);

    /// \brief Is contain at least one state object with given type?
    bool IsContain (Urho3D::String typeName);
    /// \brief Returns count of state objects with given type.
    int CountOf (Urho3D::String typeName);

    ///  \brief Create object of given type and add it to hub.
    ///  \param typeName typeName of given object. Objects factory will be registered in context.
    ///  \return Urho3D::SharedPtr to created object.
    Urho3D::SharedPtr <StateObject> Create (Urho3D::String typeName);

    /// \brief Template version of StateObjectsHub::Get (Urho3D::String).
    template <class T> inline Urho3D::SharedPtr <T> Get ()
    {
        Urho3D::SharedPtr <T> object;
        object.DynamicCast (Get (T::GetTypeNameStatic ()));
        return object;
    }

    /// \brief Template version of StateObjectsHub::GetAll (Urho3D::String).
    template <class T> inline Urho3D::Vector <Urho3D::SharedPtr <T> > *GetAll ()
    {
        return (Urho3D::Vector <Urho3D::SharedPtr <T> > *) GetAll (T::GetTypeNameStatic ());
    }

    /// \brief Template version of StateObjectsHub::RemoveAll (Urho3D::String, bool).
    template <class T> inline void RemoveAll ()
    {
        RemoveAll (T::GetTypeNameStatic ());
    }

    /// \brief Template version of StateObjectsHub::IsContain (Urho3D::String).
    template <class T> inline bool IsContain ()
    {
        return IsContain (T::GetTypeNameStatic ());
    }

    /// \brief Template version of StateObjectsHub::CountOf (Urho3D::String).
    template <class T> inline int CountOf ()
    {
        return CountOf (T::GetTypeNameStatic ());
    }

    /// \brief Template version of StateObjectsHub::Create (Urho3D::String).
    template <class T> inline Urho3D::SharedPtr <T> Create ()
    {
        Urho3D::SharedPtr <T> object;
        object.StaticCast (Create (T::GetTypeNameStatic ()));
        return object;
    }
};
}
