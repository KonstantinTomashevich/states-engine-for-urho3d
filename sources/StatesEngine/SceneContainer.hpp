#pragma once
#include "StateObject.hpp"
#include <Urho3D/Core/Object.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Container/Ptr.h>
#include <Urho3D/Container/Str.h>

/// \brief Namespace for all States Engine classes.
namespace StatesEngine
{

/// \brief Container object for Urho3D::Scene.
class SceneContainer : public StateObject
{
URHO3D_OBJECT (SceneContainer, StateObject)
protected:
    /// \brief Pointer to scene.
    Urho3D::SharedPtr <Urho3D::Scene> scene_;
public:
    SceneContainer (Urho3D::Context *context);
    /// \brief Set scene.
    void Set (Urho3D::SharedPtr <Urho3D::Scene> scene);
    /// \brief Loads scene from specified xml file.
    void Set (Urho3D::XMLElement source);
    /// \brief Loads scene from xml file from specified path.
    void Set (Urho3D::String pathToXML);
    /// \brief Returns *scene_*.
    Urho3D::SharedPtr <Urho3D::Scene> Get ();
    /// \brief Returns scene node by literal way. Way will be look like "/nameOfParent2Node/nameOfParent1Node/nameOfNode/".
    Urho3D::Node *GetNode (Urho3D::String wayToNode);

    ///  \brief Setups scene viewport.
    ///  \param [in] index index of viewport. See **Urho3D::Renderer::SetViewport ()**.
    ///  \param [in] cameraNode node with **Urho3D::Camera** component.
    ///  \param [in] rectangle viewport's screen rectangle.
    ///  \param [in] shadowMapSize size of shadow map for light rendering.
    void SetupSceneViewport (int index, Urho3D::Node *cameraNode, Urho3D::IntRect rectangle, int shadowMapSize = 1024);

    ///  \brief Setups scene viewport.
    ///  \param [in] index index of viewport. See **Urho3D::Renderer::SetViewport ()**.
    ///  \param [in] wayToCameraNode way to node with **Urho3D::Camera** component. See **GetNode (Urho3D::String wayToNode)**.
    ///  \param [in] rectangle viewport's screen rectangle.
    ///  \param [in] shadowMapSize size of shadow map for light rendering.
    void SetupSceneViewport (int index, Urho3D::String wayToCameraNode, Urho3D::IntRect rectangle, int shadowMapSize = 1024);

    /// \brief Releases shared pointer.
    void Release ();
    virtual bool Init ();
    virtual bool Update (float timeStep);
    virtual bool Dispose ();
    virtual ~SceneContainer ();

    /// \brief version of SceneContainer::Set for Lua, because Lua don't support Urho3D::SharedPtr's.
    void Lua_Set (Urho3D::Scene *scene);
    /// \brief version of SceneContainer::Get for Lua, because Lua don't support Urho3D::SharedPtr's.
    Urho3D::Scene *Lua_Get ();
};
}
