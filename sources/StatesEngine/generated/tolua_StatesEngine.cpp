/*
** Lua binding: StatesEngine
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_StatesEngine_open (lua_State* tolua_S);

using namespace StatesEngine;
using namespace Urho3D;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_StatesEngineSubsystem (lua_State* tolua_S)
{
 StatesEngineSubsystem* self = (StatesEngineSubsystem*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Urho3D__SharedPtr_StateObject_ (lua_State* tolua_S)
{
 Urho3D::SharedPtr<StateObject>* self = (Urho3D::SharedPtr<StateObject>*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Urho3D::VariantMap");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Urho3D::Context");
 tolua_usertype(tolua_S,"Urho3D::StringHash");
 tolua_usertype(tolua_S,"StatesEngineSubsystem");
 tolua_usertype(tolua_S,"Urho3D::SharedPtr<StateObject>");
}

/* method: new of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_new00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_new00_local
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Init00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Init00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Update00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Urho3D::StringHash",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Urho3D::VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::StringHash eventType = *((Urho3D::StringHash*)  tolua_tousertype(tolua_S,2,0));
  Urho3D::VariantMap* info = ((Urho3D::VariantMap*)  tolua_tousertype(tolua_S,3,0));
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
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Dispose00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Dispose00(lua_State* tolua_S)
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

/* method: GetState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_GetState00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_GetState00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetState'", NULL);
#endif
 {
  Urho3D::SharedPtr<StateObject> tolua_ret = (Urho3D::SharedPtr<StateObject>)  self->GetState();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Urho3D::SharedPtr<StateObject>)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Urho3D::SharedPtr<StateObject>");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Urho3D::SharedPtr<StateObject>));
  tolua_pushusertype(tolua_S,tolua_obj,"Urho3D::SharedPtr<StateObject>");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
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

/* method: HasState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_HasState00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_HasState00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_DisposeState00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_DisposeState00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_IsState00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_IsState00(lua_State* tolua_S)
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
  Urho3D::String typeName = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,2,0));
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

/* method: SetupState of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_SetupState00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_SetupState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StatesEngineSubsystem",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Urho3D::SharedPtr<StateObject>",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StatesEngineSubsystem* self = (StatesEngineSubsystem*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::SharedPtr<StateObject> state = *((Urho3D::SharedPtr<StateObject>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetupState'", NULL);
#endif
 {
  self->SetupState(state);
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

/* method: GetInstance of class  StatesEngineSubsystem */
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_GetInstance00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_GetInstance00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_delete00
static int tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_delete00(lua_State* tolua_S)
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

/* Open function */
TOLUA_API int tolua_StatesEngine_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StatesEngineSubsystem","StatesEngineSubsystem","Object",tolua_collect_StatesEngineSubsystem);
  #else
  tolua_cclass(tolua_S,"StatesEngineSubsystem","StatesEngineSubsystem","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StatesEngineSubsystem");
   tolua_function(tolua_S,"new",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_new00);
   tolua_function(tolua_S,"new_local",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_new00_local);
   tolua_function(tolua_S,".call",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_new00_local);
   tolua_function(tolua_S,"Init",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Init00);
   tolua_function(tolua_S,"Update",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Update00);
   tolua_function(tolua_S,"Dispose",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_Dispose00);
   tolua_function(tolua_S,"GetState",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_GetState00);
   tolua_function(tolua_S,"HasState",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_HasState00);
   tolua_function(tolua_S,"DisposeState",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_DisposeState00);
   tolua_function(tolua_S,"IsState",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_IsState00);
   tolua_function(tolua_S,"SetupState",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_SetupState00);
   tolua_function(tolua_S,"GetInstance",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_GetInstance00);
   tolua_function(tolua_S,"delete",tolua_StatesEngine_StatesEngine_StatesEngineSubsystem_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_StatesEngine (lua_State* tolua_S) {
 return tolua_StatesEngine_open(tolua_S);
};
#endif

