#pragma once
#cmakedefine STATES_ENGINE_ENABLE_ASSERTION
#ifdef STATES_ENGINE_ENABLE_ASSERTION
#undef NDEBUG
#endif

