set (TARGET_NAME TestStatesEngineCXX)
set (H_FILES TestStatesEngineCXX.hpp)
set (CPP_FILES TestStatesEngineCXX.cpp)
set (SOURCE_FILES ${H_FILES} ${CPP_FILES})
setup_main_executable ()
target_link_libraries (TestStatesEngineCXX StatesEngine)
add_test (NAME test_states_engine_cxx COMMAND TestStatesEngineCXX)

if (STATES_ENGINE_LUA)
    set (TARGET_NAME TestStatesEngineLua)
    set (H_FILES TestStatesEngineLua.hpp)
    set (CPP_FILES TestStatesEngineLua.cpp)
    set (SOURCE_FILES ${H_FILES} ${CPP_FILES})
    setup_main_executable ()
    target_link_libraries (TestStatesEngineLua StatesEngine)
    add_test (NAME test_states_engine_lua COMMAND TestStatesEngineLua)
endif ()
