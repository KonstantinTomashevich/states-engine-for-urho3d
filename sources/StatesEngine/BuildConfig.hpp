#pragma once
#define STATES_ENGINE_ENABLE_ASSERTION
#define TOLUA_DEBUG
#define STATES_ENGINE_LUA

#ifdef STATES_ENGINE_ENABLE_ASSERTION
#undef NDEBUG
#endif

#ifdef TOLUA_DEBUG
#undef TOLUA_RELEASE
#endif

