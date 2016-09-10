/*
** Lua binding: LuaStateObject
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
TOLUA_API int tolua_LuaStateObject_open (lua_State* tolua_S);

using namespace StatesEngine;
using namespace Urho3D;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LuaStateObject (lua_State* tolua_S)
{
 LuaStateObject* self = (LuaStateObject*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"StateObject");
 tolua_usertype(tolua_S,"LuaStateObject");
 tolua_usertype(tolua_S,"Context");
}

/* method: new of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_new00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_new00_local
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_new00_local(lua_State* tolua_S)
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

/* method: Init of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_Init00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_Init00(lua_State* tolua_S)
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

/* method: Update of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_Update00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Dispose of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_Dispose00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_Dispose00(lua_State* tolua_S)
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

/* method: IsReady of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_IsReady00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_IsReady00(lua_State* tolua_S)
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

/* method: IsWillBeDeleted of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_IsWillBeDeleted00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_IsWillBeDeleted00(lua_State* tolua_S)
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

/* method: IsWillBeUpdated of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_IsWillBeUpdated00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_IsWillBeUpdated00(lua_State* tolua_S)
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

/* method: SetIsWillBeUpdated of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_SetIsWillBeUpdated00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_SetIsWillBeUpdated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetParent of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_GetParent00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_GetParent00(lua_State* tolua_S)
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

/* method: SetParent of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_SetParent00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_SetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStateObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"StateObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStateObject* self = (LuaStateObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: CreateObject of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_CreateObject00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_CreateObject00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_GetObjectName00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_GetObjectName00(lua_State* tolua_S)
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

/* method: IsObjectNotNull of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_IsObjectNotNull00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_IsObjectNotNull00(lua_State* tolua_S)
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

/* method: ReleaseLuaObject of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_ReleaseLuaObject00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_ReleaseLuaObject00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReleaseLuaObject'", NULL);
#endif
 {
  self->ReleaseLuaObject();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseLuaObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  LuaStateObject */
#ifndef TOLUA_DISABLE_tolua_LuaStateObject_StatesEngine_LuaStateObject_delete00
static int tolua_LuaStateObject_StatesEngine_LuaStateObject_delete00(lua_State* tolua_S)
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

/* Open function */
TOLUA_API int tolua_LuaStateObject_open (lua_State* tolua_S)
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
   tolua_function(tolua_S,"new",tolua_LuaStateObject_StatesEngine_LuaStateObject_new00);
   tolua_function(tolua_S,"new_local",tolua_LuaStateObject_StatesEngine_LuaStateObject_new00_local);
   tolua_function(tolua_S,".call",tolua_LuaStateObject_StatesEngine_LuaStateObject_new00_local);
   tolua_function(tolua_S,"Init",tolua_LuaStateObject_StatesEngine_LuaStateObject_Init00);
   tolua_function(tolua_S,"Update",tolua_LuaStateObject_StatesEngine_LuaStateObject_Update00);
   tolua_function(tolua_S,"Dispose",tolua_LuaStateObject_StatesEngine_LuaStateObject_Dispose00);
   tolua_function(tolua_S,"IsReady",tolua_LuaStateObject_StatesEngine_LuaStateObject_IsReady00);
   tolua_function(tolua_S,"IsWillBeDeleted",tolua_LuaStateObject_StatesEngine_LuaStateObject_IsWillBeDeleted00);
   tolua_function(tolua_S,"IsWillBeUpdated",tolua_LuaStateObject_StatesEngine_LuaStateObject_IsWillBeUpdated00);
   tolua_function(tolua_S,"SetIsWillBeUpdated",tolua_LuaStateObject_StatesEngine_LuaStateObject_SetIsWillBeUpdated00);
   tolua_function(tolua_S,"GetParent",tolua_LuaStateObject_StatesEngine_LuaStateObject_GetParent00);
   tolua_function(tolua_S,"SetParent",tolua_LuaStateObject_StatesEngine_LuaStateObject_SetParent00);
   tolua_function(tolua_S,"CreateObject",tolua_LuaStateObject_StatesEngine_LuaStateObject_CreateObject00);
   tolua_function(tolua_S,"GetObjectName",tolua_LuaStateObject_StatesEngine_LuaStateObject_GetObjectName00);
   tolua_function(tolua_S,"IsObjectNotNull",tolua_LuaStateObject_StatesEngine_LuaStateObject_IsObjectNotNull00);
   tolua_function(tolua_S,"ReleaseLuaObject",tolua_LuaStateObject_StatesEngine_LuaStateObject_ReleaseLuaObject00);
   tolua_function(tolua_S,"delete",tolua_LuaStateObject_StatesEngine_LuaStateObject_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaStateObject (lua_State* tolua_S) {
 return tolua_LuaStateObject_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif