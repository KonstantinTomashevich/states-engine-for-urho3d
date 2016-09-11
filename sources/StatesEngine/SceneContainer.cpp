#include "SceneContainer.hpp"
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Camera.h>
namespace StatesEngine
{

SceneContainer::SceneContainer (Urho3D::Context *context) : StateObject (context)
{
    scene_ = 0;
}

void SceneContainer::Set (Urho3D::SharedPtr <Urho3D::Scene> scene)
{
    scene_ = scene;
}

void SceneContainer::Lua_Set (Urho3D::Scene *scene, bool isKeepPrevious)
{
    Urho3D::SharedPtr <Urho3D::Scene> sceneToSet (scene);
    Urho3D::SharedPtr <Urho3D::Scene> previousScene = Get ();
    Set (sceneToSet);
    if (isKeepPrevious)
        previousScene.Detach ();
}

Urho3D::Scene *SceneContainer::Lua_Get ()
{
    return scene_.Get ();
}

void SceneContainer::Set (Urho3D::XMLElement source)
{
    scene_ = new Urho3D::Scene (context_);
    scene_->LoadXML (source);
}

void SceneContainer::Set (Urho3D::String pathToXML)
{
    Urho3D::ResourceCache *cache = context_->GetSubsystem <Urho3D::ResourceCache> ();
    Urho3D::XMLFile *file = cache->GetResource <Urho3D::XMLFile> (pathToXML);
    if (file)
        Set (file->GetRoot ());
}

Urho3D::SharedPtr <Urho3D::Scene> SceneContainer::Get ()
{
    return scene_;
}

Urho3D::Node *SceneContainer::GetNode (Urho3D::String wayToNode)
{
    Urho3D::Vector <Urho3D::String> names = wayToNode.Split ('/');
    Urho3D::Node *node = 0;
    node = scene_->GetChild (names.At (0));
    for (int index = 1; index < names.Size (); index++)
    {
        if (node)
            node = node->GetChild (names.At (index));
        else
            return 0;
    }
    return node;
}

void SceneContainer::SetupSceneViewport(int index, Urho3D::Node *cameraNode, Urho3D::IntRect rectangle,
                                        int shadowMapSize)
{
    Urho3D::Renderer* renderer = context_->GetSubsystem <Urho3D::Renderer>();
    Urho3D::SharedPtr <Urho3D::Viewport> viewport (
                                    new Urho3D::Viewport(context_, scene_,
                                    cameraNode->GetComponent <Urho3D::Camera>(), rectangle));
    renderer->SetViewport (index, viewport);
    renderer->SetShadowMapSize (shadowMapSize);
}

void SceneContainer::SetupSceneViewport (int index, Urho3D::String wayToCameraNode, Urho3D::IntRect rectangle,
                                         int shadowMapSize)
{
    Urho3D::Node *cameraNode = GetNode (wayToCameraNode);
    SetupSceneViewport (index, cameraNode, rectangle, shadowMapSize);
}

void SceneContainer::Release ()
{
    scene_.Reset ();
}

bool SceneContainer::Init ()
{
    if (scene_.NotNull ())
    {
        ready_ = true;
        return true;
    }
    else
    {
        ready_ = false;
        return false;
    }
}

bool SceneContainer::Update (float timeStep)
{
    return true;
}

bool SceneContainer::Dispose ()
{
    Release ();
    ready_ = false;
    return true;
}

SceneContainer::~SceneContainer ()
{
    Dispose ();
}
}
