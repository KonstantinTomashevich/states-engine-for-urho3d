/*
** Lua binding: SceneContainer
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_SceneContainer_open (lua_State* tolua_S);

using namespace StatesEngine;
using namespace Urho3D;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_SceneContainer (lua_State* tolua_S)
{
 SceneContainer* self = (SceneContainer*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Urho3D__SharedPtr_Urho3D__Scene_ (lua_State* tolua_S)
{
 Urho3D::SharedPtr<Urho3D::Scene>* self = (Urho3D::SharedPtr<Urho3D::Scene>*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"StateObject");
 tolua_usertype(tolua_S,"Urho3D::Node");
 tolua_usertype(tolua_S,"Urho3D::Context");
 tolua_usertype(tolua_S,"SceneContainer");
 tolua_usertype(tolua_S,"Urho3D::IntRect");
 tolua_usertype(tolua_S,"Urho3D::XMLElement");
 tolua_usertype(tolua_S,"Urho3D::SharedPtr<Urho3D::Scene>");
}

/* method: new of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_new00
static int tolua_SceneContainer_StatesEngine_SceneContainer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_new00_local
static int tolua_SceneContainer_StatesEngine_SceneContainer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Set00
static int tolua_SceneContainer_StatesEngine_SceneContainer_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Urho3D::SharedPtr<Urho3D::Scene>",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::SharedPtr<Urho3D::Scene> scene = *((Urho3D::SharedPtr<Urho3D::Scene>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(scene);
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

/* method: Set of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Set01
static int tolua_SceneContainer_StatesEngine_SceneContainer_Set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Urho3D::XMLElement",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::XMLElement source = *((Urho3D::XMLElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(source);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneContainer_StatesEngine_SceneContainer_Set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Set02
static int tolua_SceneContainer_StatesEngine_SceneContainer_Set02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::String pathToXML = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(pathToXML);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneContainer_StatesEngine_SceneContainer_Set01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Get00
static int tolua_SceneContainer_StatesEngine_SceneContainer_Get00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get'", NULL);
#endif
 {
  Urho3D::SharedPtr<Urho3D::Scene> tolua_ret = (Urho3D::SharedPtr<Urho3D::Scene>)  self->Get();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Urho3D::SharedPtr<Urho3D::Scene>)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Urho3D::SharedPtr<Urho3D::Scene>");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Urho3D::SharedPtr<Urho3D::Scene>));
  tolua_pushusertype(tolua_S,tolua_obj,"Urho3D::SharedPtr<Urho3D::Scene>");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
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

/* method: GetNode of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_GetNode00
static int tolua_SceneContainer_StatesEngine_SceneContainer_GetNode00(lua_State* tolua_S)
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
  Urho3D::String wayToNode = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNode'", NULL);
#endif
 {
  Urho3D::Node* tolua_ret = (Urho3D::Node*)  self->GetNode(wayToNode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Urho3D::Node");
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_SetupSceneViewport00
static int tolua_SceneContainer_StatesEngine_SceneContainer_SetupSceneViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Urho3D::Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Urho3D::IntRect",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  Urho3D::Node* cameraNode = ((Urho3D::Node*)  tolua_tousertype(tolua_S,3,0));
  Urho3D::IntRect rectangle = *((Urho3D::IntRect*)  tolua_tousertype(tolua_S,4,0));
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_SetupSceneViewport01
static int tolua_SceneContainer_StatesEngine_SceneContainer_SetupSceneViewport01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SceneContainer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Urho3D::IntRect",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SceneContainer* self = (SceneContainer*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  Urho3D::String wayToCameraNode = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,3,0));
  Urho3D::IntRect rectangle = *((Urho3D::IntRect*)  tolua_tousertype(tolua_S,4,0));
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
 return tolua_SceneContainer_StatesEngine_SceneContainer_SetupSceneViewport00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Release of class  SceneContainer */
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Release00
static int tolua_SceneContainer_StatesEngine_SceneContainer_Release00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Init00
static int tolua_SceneContainer_StatesEngine_SceneContainer_Init00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Update00
static int tolua_SceneContainer_StatesEngine_SceneContainer_Update00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_Dispose00
static int tolua_SceneContainer_StatesEngine_SceneContainer_Dispose00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_SceneContainer_StatesEngine_SceneContainer_delete00
static int tolua_SceneContainer_StatesEngine_SceneContainer_delete00(lua_State* tolua_S)
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

/* Open function */
TOLUA_API int tolua_SceneContainer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SceneContainer","SceneContainer","StateObject",tolua_collect_SceneContainer);
  #else
  tolua_cclass(tolua_S,"SceneContainer","SceneContainer","StateObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SceneContainer");
   tolua_function(tolua_S,"new",tolua_SceneContainer_StatesEngine_SceneContainer_new00);
   tolua_function(tolua_S,"new_local",tolua_SceneContainer_StatesEngine_SceneContainer_new00_local);
   tolua_function(tolua_S,".call",tolua_SceneContainer_StatesEngine_SceneContainer_new00_local);
   tolua_function(tolua_S,"Set",tolua_SceneContainer_StatesEngine_SceneContainer_Set00);
   tolua_function(tolua_S,"Set",tolua_SceneContainer_StatesEngine_SceneContainer_Set01);
   tolua_function(tolua_S,"Set",tolua_SceneContainer_StatesEngine_SceneContainer_Set02);
   tolua_function(tolua_S,"Get",tolua_SceneContainer_StatesEngine_SceneContainer_Get00);
   tolua_function(tolua_S,"GetNode",tolua_SceneContainer_StatesEngine_SceneContainer_GetNode00);
   tolua_function(tolua_S,"SetupSceneViewport",tolua_SceneContainer_StatesEngine_SceneContainer_SetupSceneViewport00);
   tolua_function(tolua_S,"SetupSceneViewport",tolua_SceneContainer_StatesEngine_SceneContainer_SetupSceneViewport01);
   tolua_function(tolua_S,"Release",tolua_SceneContainer_StatesEngine_SceneContainer_Release00);
   tolua_function(tolua_S,"Init",tolua_SceneContainer_StatesEngine_SceneContainer_Init00);
   tolua_function(tolua_S,"Update",tolua_SceneContainer_StatesEngine_SceneContainer_Update00);
   tolua_function(tolua_S,"Dispose",tolua_SceneContainer_StatesEngine_SceneContainer_Dispose00);
   tolua_function(tolua_S,"delete",tolua_SceneContainer_StatesEngine_SceneContainer_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_SceneContainer (lua_State* tolua_S) {
 return tolua_SceneContainer_open(tolua_S);
};
#endif

