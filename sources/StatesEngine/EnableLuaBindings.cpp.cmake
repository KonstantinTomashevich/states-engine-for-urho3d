#include "EnableLuaBindings.hpp"
#include <Urho3D/ThirdParty/toluapp/tolua++.h>
#include <Urho3D/LuaScript/ToluaUtils.h>
#include "BuildConfig.hpp"

${PackagesCXXHeadersInclude}
${IncludesList}
namespace StatesEngine
{
namespace ToLua
{
void EnableAll (Urho3D::LuaScript *luaScript)
{
${EnableAllCode}
${LuaInitAllCode}
}

${EnablersAndInitializerCode}
}
}
