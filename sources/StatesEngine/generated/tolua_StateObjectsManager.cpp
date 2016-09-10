/*
** Lua binding: StateObjectsManager
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
TOLUA_API int tolua_StateObjectsManager_open (lua_State* tolua_S);

using namespace StatesEngine;
using namespace Urho3D;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_StateObjectsManager (lua_State* tolua_S)
{
 StateObjectsManager* self = (StateObjectsManager*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"StateObject");
 tolua_usertype(tolua_S,"Urho3D::Context");
 tolua_usertype(tolua_S,"StateObjectsManager");
 tolua_usertype(tolua_S,"Urho3D::SharedPtr<StateObject>");
 tolua_usertype(tolua_S,"Urho3D::Vector<Urho3D::SharedPtr<StateObject> >");
}

/* method: new of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_new00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_new00_local
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_ReInitAll00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_ReInitAll00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_UpdateAll00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_UpdateAll00(lua_State* tolua_S)
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
  Urho3D::String typeName = ((Urho3D::String)  tolua_tourho3dstring(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_DisposeAll00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_DisposeAll00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_IsUseLog00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_IsUseLog00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_SetIsUseLog00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_SetIsUseLog00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_delete00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_delete00(lua_State* tolua_S)
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

/* method: Get of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Get00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Get00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get'", NULL);
#endif
 {
  Urho3D::SharedPtr<StateObject> tolua_ret = (Urho3D::SharedPtr<StateObject>)  self->Get(typeName);
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
 tolua_error(tolua_S,"#ferror in function 'Get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Add of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Add00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Urho3D::SharedPtr<StateObject>",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::SharedPtr<StateObject> object = *((Urho3D::SharedPtr<StateObject>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'", NULL);
#endif
 {
  self->Add(object);
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

/* method: Remove of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Remove00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StateObjectsManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Urho3D::SharedPtr<StateObject>",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StateObjectsManager* self = (StateObjectsManager*)  tolua_tousertype(tolua_S,1,0);
  Urho3D::SharedPtr<StateObject> object = *((Urho3D::SharedPtr<StateObject>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Remove'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Remove(object);
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

/* method: GetAll of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_GetAll00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_GetAll00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAll'", NULL);
#endif
 {
  Urho3D::Vector<Urho3D::SharedPtr<StateObject> >* tolua_ret = (Urho3D::Vector<Urho3D::SharedPtr<StateObject> >*)  self->GetAll(typeName);
  ToluaPushVector<Urho3D::SharedPtr<StateObject> >(tolua_S,(void*)tolua_ret,"Urho3D::Vector<Urho3D::SharedPtr<StateObject> >");
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

/* method: RemoveAll of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_RemoveAll00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_RemoveAll00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAll'", NULL);
#endif
 {
  self->RemoveAll(typeName);
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_IsContain00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_IsContain00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_CountOf00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_CountOf00(lua_State* tolua_S)
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

/* method: Create of class  StateObjectsManager */
#ifndef TOLUA_DISABLE_tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Create00
static int tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Create00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Create'", NULL);
#endif
 {
  Urho3D::SharedPtr<StateObject> tolua_ret = (Urho3D::SharedPtr<StateObject>)  self->Create(typeName);
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
 tolua_error(tolua_S,"#ferror in function 'Create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_StateObjectsManager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"StatesEngine",0);
 tolua_beginmodule(tolua_S,"StatesEngine");
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StateObjectsManager","StateObjectsManager","StateObject",tolua_collect_StateObjectsManager);
  #else
  tolua_cclass(tolua_S,"StateObjectsManager","StateObjectsManager","StateObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StateObjectsManager");
   tolua_function(tolua_S,"new",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_new00);
   tolua_function(tolua_S,"new_local",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_new00_local);
   tolua_function(tolua_S,".call",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_new00_local);
   tolua_function(tolua_S,"ReInitAll",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_ReInitAll00);
   tolua_function(tolua_S,"UpdateAll",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_UpdateAll00);
   tolua_function(tolua_S,"DisposeAll",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_DisposeAll00);
   tolua_function(tolua_S,"IsUseLog",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_IsUseLog00);
   tolua_function(tolua_S,"SetIsUseLog",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_SetIsUseLog00);
   tolua_function(tolua_S,"delete",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_delete00);
   tolua_function(tolua_S,"Get",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Get00);
   tolua_function(tolua_S,"Add",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Add00);
   tolua_function(tolua_S,"Remove",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Remove00);
   tolua_function(tolua_S,"GetAll",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_GetAll00);
   tolua_function(tolua_S,"RemoveAll",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_RemoveAll00);
   tolua_function(tolua_S,"IsContain",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_IsContain00);
   tolua_function(tolua_S,"CountOf",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_CountOf00);
   tolua_function(tolua_S,"Create",tolua_StateObjectsManager_StatesEngine_StateObjectsManager_Create00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_StateObjectsManager (lua_State* tolua_S) {
 return tolua_StateObjectsManager_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif