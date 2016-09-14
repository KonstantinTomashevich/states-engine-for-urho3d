/*
** Lua binding: AllStatesEngine
*/

//
// Copyright (c) 2008-2016 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <Urho3D/Precompiled.h>

#include <Urho3D/ThirdParty/toluapp/tolua++.h>
#include <Urho3D/LuaScript/ToluaUtils.h>

#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/* Exported function */
TOLUA_API int tolua_AllStatesEngine_open (lua_State* tolua_S);

using namespace StatesEngine;
using namespace Urho3D;
using namespace StatesEngine;
using namespace Urho3D;
using namespace StatesEngine;
using namespace Urho3D;
using namespace StatesEngine;
using namespace Urho3D;
using namespace StatesEngine;
using namespace Urho3D;
using namespace Urho3D;
using namespace StatesEngine::Events;
using namespace StatesEngine::Events::StateObjectAddedToHub;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_StateObject (lua_State* tolua_S)
{
 StateObject* self = (StateObject*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_LuaStateObject (lua_State* tolua_S)
{
 LuaStateObject* self = (LuaStateObject*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_SceneContainer (lua_State* tolua_S)
{
 SceneContainer* self = (SceneContainer*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_StatesEngineSubsystem (lua_State* tolua_S)
{
 StatesEngineSubsystem* self = (StatesEngineSubsystem*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_StateObjectsManager (lua_State* tolua_S)
{
 StateObjectsManager* self = (StateObjectsManager*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_SharedPtr_Scene_ (lua_State* tolua_S)
{
 SharedPtr<Scene>* self = (SharedPtr<Scene>*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"PODVector<StateObject*>");
 tolua_usertype(tolua_S,"VariantMap");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"StringHash");
 tolua_usertype(tolua_S,"SceneContainer");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"StateObjectsManager");
 tolua_usertype(tolua_S,"Urho3D::PODVector<StateObject*>");
 tolua_usertype(tolua_S,"SharedPtr<Scene>");
 tolua_usertype(tolua_S,"LuaStateObject");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"StateObject");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"StatesEngineSubsystem");
 tolua_usertype(tolua_S,"Context");
 tolua_usertype(tolua_S,"XMLElement");
}

/* method: new of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_new00
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  LuaStateObject* tolua_ret = (LuaStateObject*)  Mtolua_new((LuaStateObject)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaStateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_new00_local
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  LuaStateObject* tolua_ret = (LuaStateObject*)  Mtolua_new((LuaStateObject)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaStateObject");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateObject of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_CreateObject00
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_CreateObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
  String luaTypeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
  String arguments = ((String)  tolua_tourho3dstring(tolua_S,3,""));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateObject'", NULL);
#endif
 {
  self->CreateObject(luaTypeName,arguments);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectName of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_GetObjectName00
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_GetObjectName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetObjectName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectTypeName of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_GetObjectTypeName00
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_GetObjectTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectTypeName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetObjectTypeName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsObjectNotNull of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_IsObjectNotNull00
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_IsObjectNotNull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsObjectNotNull'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsObjectNotNull();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsObjectNotNull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReleaseObject of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_ReleaseObject00
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_ReleaseObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReleaseObject'", NULL);
#endif
 {
  self->ReleaseObject();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_LuaStateObject_delete00
static int tolua_AllStatesEngine_StatesEngine_LuaStateObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_new00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  SceneContainer* tolua_ret = (SceneContainer*)  Mtolua_new((SceneContainer)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneContainer");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_new00_local
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  SceneContainer* tolua_ret = (SceneContainer*)  Mtolua_new((SceneContainer)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneContainer");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_SetFromXMLElement00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_SetFromXMLElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"XMLElement",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  XMLElement source = *((XMLElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(source);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFromXMLElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_SetFromXMLFile00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_SetFromXMLFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  String pathToXML = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(pathToXML);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFromXMLFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_Set of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_Set00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  bool isKeepPrevious = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_Set'", NULL);
#endif
 {
  self->Lua_Set(scene,isKeepPrevious);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_Get of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_Get00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_Get'", NULL);
#endif
 {
  Scene* tolua_ret = (Scene*)  self->Lua_Get();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_Get01
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_Get01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get'", NULL);
#endif
 {
  SharedPtr<Scene> tolua_ret = (SharedPtr<Scene>)  self->Get();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SharedPtr<Scene>)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SharedPtr<Scene>");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SharedPtr<Scene>));
  tolua_pushusertype(tolua_S,tolua_obj,"SharedPtr<Scene>");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_AllStatesEngine_StatesEngine_SceneContainer_Get00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNode of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_GetNode00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_GetNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  String wayToNode = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetNode(wayToNode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetupSceneViewport of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_SetupSceneViewport00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_SetupSceneViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"IntRect",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  Node* cameraNode = ((Node*)  tolua_tousertype(tolua_S,3,0));
  IntRect rectangle = *((IntRect*)  tolua_tousertype(tolua_S,4,0));
  int shadowMapSize = ((int)  tolua_tonumber(tolua_S,5,1024));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetupSceneViewport'", NULL);
#endif
 {
  self->SetupSceneViewport(index,cameraNode,rectangle,shadowMapSize);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetupSceneViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetupSceneViewport of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_SetupSceneViewport01
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_SetupSceneViewport01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"IntRect",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  String wayToCameraNode = ((String)  tolua_tourho3dstring(tolua_S,3,0));
  IntRect rectangle = *((IntRect*)  tolua_tousertype(tolua_S,4,0));
  int shadowMapSize = ((int)  tolua_tonumber(tolua_S,5,1024));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetupSceneViewport'", NULL);
#endif
 {
  self->SetupSceneViewport(index,wayToCameraNode,rectangle,shadowMapSize);
 }
 }
 return 0;
tolua_lerror:
 return tolua_AllStatesEngine_StatesEngine_SceneContainer_SetupSceneViewport00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Release of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_Release00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_Release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Release'", NULL);
#endif
 {
  self->Release();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_Init00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Init();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_Update00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  float timeStep = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Update(timeStep);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Dispose of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_Dispose00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_Dispose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Dispose'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Dispose();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Dispose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_SceneContainer_delete00
static int tolua_AllStatesEngine_StatesEngine_SceneContainer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_new00
static int tolua_AllStatesEngine_StatesEngine_StateObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  StateObject* tolua_ret = (StateObject*)  Mtolua_new((StateObject)(context));
  ToluaPushObject(tolua_S,(void*)tolua_ret,"StateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_new00_local
static int tolua_AllStatesEngine_StatesEngine_StateObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  StateObject* tolua_ret = (StateObject*)  Mtolua_new((StateObject)(context));
  ToluaPushObject(tolua_S,(void*)tolua_ret,"StateObject");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_Init00
static int tolua_AllStatesEngine_StatesEngine_StateObject_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Init();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_Update00
static int tolua_AllStatesEngine_StatesEngine_StateObject_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
  float timeStep = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Update(timeStep);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Dispose of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_Dispose00
static int tolua_AllStatesEngine_StatesEngine_StateObject_Dispose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Dispose'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Dispose();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Dispose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsReady of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_IsReady00
static int tolua_AllStatesEngine_StatesEngine_StateObject_IsReady00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsReady'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsReady();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsReady'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsWillBeDeleted of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_IsWillBeDeleted00
static int tolua_AllStatesEngine_StatesEngine_StateObject_IsWillBeDeleted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsWillBeDeleted'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsWillBeDeleted();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsWillBeDeleted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsWillBeUpdated of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_IsWillBeUpdated00
static int tolua_AllStatesEngine_StatesEngine_StateObject_IsWillBeUpdated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsWillBeUpdated'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsWillBeUpdated();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsWillBeUpdated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsWillBeUpdated of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_SetIsWillBeUpdated00
static int tolua_AllStatesEngine_StatesEngine_StateObject_SetIsWillBeUpdated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
  bool isWillBeUpdated = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsWillBeUpdated'", NULL);
#endif
 {
  self->SetIsWillBeUpdated(isWillBeUpdated);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsWillBeUpdated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParent of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_GetParent00
static int tolua_AllStatesEngine_StatesEngine_StateObject_GetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParent'", NULL);
#endif
 {
  StateObject* tolua_ret = (StateObject*)  self->GetParent();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"StateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetParent of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_SetParent00
static int tolua_AllStatesEngine_StatesEngine_StateObject_SetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
  StateObject* parent = ((StateObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetParent'", NULL);
#endif
 {
  self->SetParent(parent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  StateObject */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObject_delete00
static int tolua_AllStatesEngine_StatesEngine_StateObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObject* self = (StateObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_new00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  StateObjectsManager* tolua_ret = (StateObjectsManager*)  Mtolua_new((StateObjectsManager)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StateObjectsManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_new00_local
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  StateObjectsManager* tolua_ret = (StateObjectsManager*)  Mtolua_new((StateObjectsManager)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StateObjectsManager");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReInitAll of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_ReInitAll00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_ReInitAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReInitAll'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->ReInitAll(typeName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReInitAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_UpdateAll00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_UpdateAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
  float timeStep = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateAll'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->UpdateAll(typeName,timeStep);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DisposeAll of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_DisposeAll00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_DisposeAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DisposeAll'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->DisposeAll(typeName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DisposeAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUseLog of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_IsUseLog00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_IsUseLog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUseLog'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsUseLog();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUseLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsUseLog of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_SetIsUseLog00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_SetIsUseLog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  bool isUseLog = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsUseLog'", NULL);
#endif
 {
  self->SetIsUseLog(isUseLog);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsUseLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_delete00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_Get of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Get00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_Get'", NULL);
#endif
 {
  StateObject* tolua_ret = (StateObject*)  self->Lua_Get(typeName);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"StateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_Add of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Add00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  StateObject* object = ((StateObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_Add'", NULL);
#endif
 {
  self->Lua_Add(object);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_Remove of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Remove00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"StateObject",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  StateObject* object = ((StateObject*)  tolua_tousertype(tolua_S,2,0));
  bool dontDelete = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_Remove'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Lua_Remove(object,dontDelete);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_Create of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Create00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_Create'", NULL);
#endif
 {
  StateObject* tolua_ret = (StateObject*)  self->Lua_Create(typeName);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"StateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_GetAll of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetAll00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_GetAll'", NULL);
#endif
 {
  PODVector<StateObject*>& tolua_ret = (PODVector<StateObject*>&)  self->Lua_GetAll(typeName);
  ToluaPushPODVector<StateObject*>("",tolua_S,(void*)&tolua_ret,"StateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_RemoveAll of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_RemoveAll00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_RemoveAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
  bool dontDelete = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_RemoveAll'", NULL);
#endif
 {
  self->Lua_RemoveAll(typeName,dontDelete);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsContain of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_IsContain00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_IsContain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsContain'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsContain(typeName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsContain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CountOf of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_CountOf00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_CountOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CountOf'", NULL);
#endif
 {
  int tolua_ret = (int)  self->CountOf(typeName);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CountOf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_CreateLuaStateObject of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_CreateLuaStateObject00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_CreateLuaStateObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  String luaTypeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
  String arguments = ((String)  tolua_tourho3dstring(tolua_S,3,""));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_CreateLuaStateObject'", NULL);
#endif
 {
  LuaStateObject* tolua_ret = (LuaStateObject*)  self->Lua_CreateLuaStateObject(luaTypeName,arguments);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaStateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateLuaStateObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_GetByLuaTypeName of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetByLuaTypeName00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetByLuaTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::String typeName = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_GetByLuaTypeName'", NULL);
#endif
 {
  LuaStateObject* tolua_ret = (LuaStateObject*)  self->Lua_GetByLuaTypeName(typeName);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaStateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetByLuaTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_GetAllByLuaTypeName of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetAllByLuaTypeName00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetAllByLuaTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::String typeName = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_GetAllByLuaTypeName'", NULL);
#endif
 {
  Urho3D::PODVector<StateObject*>& tolua_ret = (Urho3D::PODVector<StateObject*>&)  self->Lua_GetAllByLuaTypeName(typeName);
  ToluaPushPODVector<StateObject*>("",tolua_S,(void*)&tolua_ret,"Urho3D::PODVector<StateObject*>");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllByLuaTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_RemoveAllByLuaTypeName of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StateObjectsManager_RemoveAllByLuaTypeName00
static int tolua_AllStatesEngine_StatesEngine_StateObjectsManager_RemoveAllByLuaTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::String typeName = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,2,0));
  bool dontDelete = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_RemoveAllByLuaTypeName'", NULL);
#endif
 {
  self->Lua_RemoveAllByLuaTypeName(typeName,dontDelete);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllByLuaTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_new00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  StatesEngineSubsystem* tolua_ret = (StatesEngineSubsystem*)  Mtolua_new((StatesEngineSubsystem)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StatesEngineSubsystem");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_new00_local
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  StatesEngineSubsystem* tolua_ret = (StatesEngineSubsystem*)  Mtolua_new((StatesEngineSubsystem)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StatesEngineSubsystem");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Init00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Init();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Update00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  VariantMap* info = ((VariantMap*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
 {
  self->Update(eventType,*info);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Dispose of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Dispose00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Dispose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Dispose'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Dispose();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Dispose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_GetState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_GetState00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_GetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_GetState'", NULL);
#endif
 {
  StateObject* tolua_ret = (StateObject*)  self->Lua_GetState();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"StateObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lua_SetupState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_SetupState00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_SetupState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"StateObject",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
  StateObject* state = ((StateObject*)  tolua_tousertype(tolua_S,2,0));
  bool isKeepPrevious = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lua_SetupState'", NULL);
#endif
 {
  self->Lua_SetupState(state,isKeepPrevious);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetupState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_HasState00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_HasState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasState'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasState();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DisposeState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_DisposeState00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_DisposeState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DisposeState'", NULL);
#endif
 {
  self->DisposeState();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DisposeState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_IsState00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_IsState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
  String typeName = ((String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsState'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsState(typeName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInstance of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_GetInstance00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  StatesEngineSubsystem* tolua_ret = (StatesEngineSubsystem*)  StatesEngineSubsystem::GetInstance();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"StatesEngineSubsystem");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_delete00
static int tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: E_STATE_OBJECT_ADDED_TO_HUB */
#ifndef TOLUA_DISABLE_tolua_get_Events_E_STATE_OBJECT_ADDED_TO_HUB
static int tolua_get_Events_E_STATE_OBJECT_ADDED_TO_HUB(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&E_STATE_OBJECT_ADDED_TO_HUB,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: P_STATE_OBJECT */
#ifndef TOLUA_DISABLE_tolua_get_StateObjectAddedToHub_P_STATE_OBJECT
static int tolua_get_StateObjectAddedToHub_P_STATE_OBJECT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&P_STATE_OBJECT,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: P_HUB */
#ifndef TOLUA_DISABLE_tolua_get_StateObjectAddedToHub_P_HUB
static int tolua_get_StateObjectAddedToHub_P_HUB(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&P_HUB,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: E_STATE_OBJECT_REMOVED_FROM_HUB */
#ifndef TOLUA_DISABLE_tolua_get_Events_E_STATE_OBJECT_REMOVED_FROM_HUB
static int tolua_get_Events_E_STATE_OBJECT_REMOVED_FROM_HUB(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&E_STATE_OBJECT_REMOVED_FROM_HUB,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: P_STATE_OBJECT */
#ifndef TOLUA_DISABLE_tolua_get_StateObjectRemovedFromHub_P_STATE_OBJECT
static int tolua_get_StateObjectRemovedFromHub_P_STATE_OBJECT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&P_STATE_OBJECT,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: P_HUB */
#ifndef TOLUA_DISABLE_tolua_get_StateObjectRemovedFromHub_P_HUB
static int tolua_get_StateObjectRemovedFromHub_P_HUB(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&P_HUB,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_AllStatesEngine_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaStateObject","LuaStateObject","StateObject",tolua_collect_LuaStateObject);
  #else
  tolua_cclass(tolua_S,"LuaStateObject","LuaStateObject","StateObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaStateObject");
   tolua_function(tolua_S,"new",tolua_AllStatesEngine_StatesEngine_LuaStateObject_new00);
   tolua_function(tolua_S,"new_local",tolua_AllStatesEngine_StatesEngine_LuaStateObject_new00_local);
   tolua_function(tolua_S,".call",tolua_AllStatesEngine_StatesEngine_LuaStateObject_new00_local);
   tolua_function(tolua_S,"CreateObject",tolua_AllStatesEngine_StatesEngine_LuaStateObject_CreateObject00);
   tolua_function(tolua_S,"GetObjectName",tolua_AllStatesEngine_StatesEngine_LuaStateObject_GetObjectName00);
   tolua_function(tolua_S,"GetObjectTypeName",tolua_AllStatesEngine_StatesEngine_LuaStateObject_GetObjectTypeName00);
   tolua_function(tolua_S,"IsObjectNotNull",tolua_AllStatesEngine_StatesEngine_LuaStateObject_IsObjectNotNull00);
   tolua_function(tolua_S,"ReleaseObject",tolua_AllStatesEngine_StatesEngine_LuaStateObject_ReleaseObject00);
   tolua_function(tolua_S,"delete",tolua_AllStatesEngine_StatesEngine_LuaStateObject_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SceneContainer","SceneContainer","StateObject",tolua_collect_SceneContainer);
  #else
  tolua_cclass(tolua_S,"SceneContainer","SceneContainer","StateObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SceneContainer");
   tolua_function(tolua_S,"new",tolua_AllStatesEngine_StatesEngine_SceneContainer_new00);
   tolua_function(tolua_S,"new_local",tolua_AllStatesEngine_StatesEngine_SceneContainer_new00_local);
   tolua_function(tolua_S,".call",tolua_AllStatesEngine_StatesEngine_SceneContainer_new00_local);
   tolua_function(tolua_S,"SetFromXMLElement",tolua_AllStatesEngine_StatesEngine_SceneContainer_SetFromXMLElement00);
   tolua_function(tolua_S,"SetFromXMLFile",tolua_AllStatesEngine_StatesEngine_SceneContainer_SetFromXMLFile00);
   tolua_function(tolua_S,"Set",tolua_AllStatesEngine_StatesEngine_SceneContainer_Set00);
   tolua_function(tolua_S,"Get",tolua_AllStatesEngine_StatesEngine_SceneContainer_Get00);
   tolua_function(tolua_S,"Get",tolua_AllStatesEngine_StatesEngine_SceneContainer_Get01);
   tolua_function(tolua_S,"GetNode",tolua_AllStatesEngine_StatesEngine_SceneContainer_GetNode00);
   tolua_function(tolua_S,"SetupSceneViewport",tolua_AllStatesEngine_StatesEngine_SceneContainer_SetupSceneViewport00);
   tolua_function(tolua_S,"SetupSceneViewport",tolua_AllStatesEngine_StatesEngine_SceneContainer_SetupSceneViewport01);
   tolua_function(tolua_S,"Release",tolua_AllStatesEngine_StatesEngine_SceneContainer_Release00);
   tolua_function(tolua_S,"Init",tolua_AllStatesEngine_StatesEngine_SceneContainer_Init00);
   tolua_function(tolua_S,"Update",tolua_AllStatesEngine_StatesEngine_SceneContainer_Update00);
   tolua_function(tolua_S,"Dispose",tolua_AllStatesEngine_StatesEngine_SceneContainer_Dispose00);
   tolua_function(tolua_S,"delete",tolua_AllStatesEngine_StatesEngine_SceneContainer_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StateObject","StateObject","Object",tolua_collect_StateObject);
  #else
  tolua_cclass(tolua_S,"StateObject","StateObject","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StateObject");
   tolua_function(tolua_S,"new",tolua_AllStatesEngine_StatesEngine_StateObject_new00);
   tolua_function(tolua_S,"new_local",tolua_AllStatesEngine_StatesEngine_StateObject_new00_local);
   tolua_function(tolua_S,".call",tolua_AllStatesEngine_StatesEngine_StateObject_new00_local);
   tolua_function(tolua_S,"Init",tolua_AllStatesEngine_StatesEngine_StateObject_Init00);
   tolua_function(tolua_S,"Update",tolua_AllStatesEngine_StatesEngine_StateObject_Update00);
   tolua_function(tolua_S,"Dispose",tolua_AllStatesEngine_StatesEngine_StateObject_Dispose00);
   tolua_function(tolua_S,"IsReady",tolua_AllStatesEngine_StatesEngine_StateObject_IsReady00);
   tolua_function(tolua_S,"IsWillBeDeleted",tolua_AllStatesEngine_StatesEngine_StateObject_IsWillBeDeleted00);
   tolua_function(tolua_S,"IsWillBeUpdated",tolua_AllStatesEngine_StatesEngine_StateObject_IsWillBeUpdated00);
   tolua_function(tolua_S,"SetIsWillBeUpdated",tolua_AllStatesEngine_StatesEngine_StateObject_SetIsWillBeUpdated00);
   tolua_function(tolua_S,"GetParent",tolua_AllStatesEngine_StatesEngine_StateObject_GetParent00);
   tolua_function(tolua_S,"SetParent",tolua_AllStatesEngine_StatesEngine_StateObject_SetParent00);
   tolua_function(tolua_S,"delete",tolua_AllStatesEngine_StatesEngine_StateObject_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StateObjectsManager","StateObjectsManager","StateObject",tolua_collect_StateObjectsManager);
  #else
  tolua_cclass(tolua_S,"StateObjectsManager","StateObjectsManager","StateObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StateObjectsManager");
   tolua_function(tolua_S,"new",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_new00);
   tolua_function(tolua_S,"new_local",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_new00_local);
   tolua_function(tolua_S,".call",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_new00_local);
   tolua_function(tolua_S,"ReInitAll",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_ReInitAll00);
   tolua_function(tolua_S,"UpdateAll",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_UpdateAll00);
   tolua_function(tolua_S,"DisposeAll",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_DisposeAll00);
   tolua_function(tolua_S,"IsUseLog",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_IsUseLog00);
   tolua_function(tolua_S,"SetIsUseLog",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_SetIsUseLog00);
   tolua_function(tolua_S,"delete",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_delete00);
   tolua_function(tolua_S,"Get",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Get00);
   tolua_function(tolua_S,"Add",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Add00);
   tolua_function(tolua_S,"Remove",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Remove00);
   tolua_function(tolua_S,"Create",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_Create00);
   tolua_function(tolua_S,"GetAll",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetAll00);
   tolua_function(tolua_S,"RemoveAll",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_RemoveAll00);
   tolua_function(tolua_S,"IsContain",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_IsContain00);
   tolua_function(tolua_S,"CountOf",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_CountOf00);
   tolua_function(tolua_S,"CreateLuaStateObject",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_CreateLuaStateObject00);
   tolua_function(tolua_S,"GetByLuaTypeName",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetByLuaTypeName00);
   tolua_function(tolua_S,"GetAllByLuaTypeName",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_GetAllByLuaTypeName00);
   tolua_function(tolua_S,"RemoveAllByLuaTypeName",tolua_AllStatesEngine_StatesEngine_StateObjectsManager_RemoveAllByLuaTypeName00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StatesEngineSubsystem","StatesEngineSubsystem","Object",tolua_collect_StatesEngineSubsystem);
  #else
  tolua_cclass(tolua_S,"StatesEngineSubsystem","StatesEngineSubsystem","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StatesEngineSubsystem");
   tolua_function(tolua_S,"new",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_new00);
   tolua_function(tolua_S,"new_local",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_new00_local);
   tolua_function(tolua_S,".call",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_new00_local);
   tolua_function(tolua_S,"Init",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Init00);
   tolua_function(tolua_S,"Update",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Update00);
   tolua_function(tolua_S,"Dispose",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_Dispose00);
   tolua_function(tolua_S,"GetState",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_GetState00);
   tolua_function(tolua_S,"SetupState",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_SetupState00);
   tolua_function(tolua_S,"HasState",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_HasState00);
   tolua_function(tolua_S,"DisposeState",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_DisposeState00);
   tolua_function(tolua_S,"IsState",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_IsState00);
   tolua_function(tolua_S,"GetInstance",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_GetInstance00);
   tolua_function(tolua_S,"delete",tolua_AllStatesEngine_StatesEngine_StatesEngineSubsystem_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  tolua_module(tolua_S,"Events",1);
  tolua_beginmodule(tolua_S,"Events");
   tolua_variable(tolua_S,"E_STATE_OBJECT_ADDED_TO_HUB",tolua_get_Events_E_STATE_OBJECT_ADDED_TO_HUB,NULL);
   tolua_module(tolua_S,"StateObjectAddedToHub",1);
   tolua_beginmodule(tolua_S,"StateObjectAddedToHub");
    tolua_variable(tolua_S,"P_STATE_OBJECT",tolua_get_StateObjectAddedToHub_P_STATE_OBJECT,NULL);
    tolua_variable(tolua_S,"P_HUB",tolua_get_StateObjectAddedToHub_P_HUB,NULL);
   tolua_endmodule(tolua_S);
   tolua_variable(tolua_S,"E_STATE_OBJECT_REMOVED_FROM_HUB",tolua_get_Events_E_STATE_OBJECT_REMOVED_FROM_HUB,NULL);
   tolua_module(tolua_S,"StateObjectRemovedFromHub",1);
   tolua_beginmodule(tolua_S,"StateObjectRemovedFromHub");
    tolua_variable(tolua_S,"P_STATE_OBJECT",tolua_get_StateObjectRemovedFromHub_P_STATE_OBJECT,NULL);
    tolua_variable(tolua_S,"P_HUB",tolua_get_StateObjectRemovedFromHub_P_HUB,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AllStatesEngine (lua_State* tolua_S) {
 return tolua_AllStatesEngine_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif