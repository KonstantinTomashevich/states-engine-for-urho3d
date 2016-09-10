#pragma once
#cmakedefine STATES_ENGINE_ENABLE_ASSERTION
#cmakedefine TOLUA_DEBUG
#cmakedefine STATES_ENGINE_LUA

#ifdef STATES_ENGINE_ENABLE_ASSERTION
#undef NDEBUG
#endif

#ifdef TOLUA_DEBUG
#undef TOLUA_RELEASE
#endif

