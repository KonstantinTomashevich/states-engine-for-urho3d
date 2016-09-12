# --- Create tolua++ StatesEngine bindings --- $
if (STATES_ENGINE_LUA)
    # --- Copy tolua++ header because tolua++ generates files with relative include ("#include "tolua++.h") --- #
    file (COPY "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_packages/InitStatesEngine.lua" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Data/StatesEngineLua")

    # --- Setup Urho3D's default tolua++ executable if it isn't specified --- #
    if (NOT TOLUAXX_EXECUTABLE)
        set (TOLUAXX_EXECUTABLE ${URHO3D_HOME}/bin/tool/tolua++${CMAKE_EXECUTABLE_SUFFIX})
        message (STATUS "TOLUAXX_EXECUTABLE setted automaticaly from Urho3D home.")
    endif ()
    message (STATUS "Current TOLUAXX_EXECUTABLE is: ${TOLUAXX_EXECUTABLE}")

    set (UmbrellaPkgCode "")
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_packages/AllStatesEngine.pkg")
        file (REMOVE "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_packages/AllStatesEngine.pkg")
    endif ()

    file (GLOB TopLevelPackages "Lua/tolua_packages/*.pkg")
    foreach (TopLevelPackage ${TopLevelPackages})
        file (RELATIVE_PATH TopLevelPackageRelative "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_packages" ${TopLevelPackage})
        set (UmbrellaPkgCode "${UmbrellaPkgCode}$pfile \"${TopLevelPackageRelative}\"\n")
    endforeach ()
    file (WRITE "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_packages/AllStatesEngine.pkg" ${UmbrellaPkgCode})

    if (NOT DONT_REGENERATE_LUA_API)
        # --- Run tolua++ --- #
        execute_process (COMMAND ${TOLUAXX_EXECUTABLE} -L "ToCppHook.lua" "AllStatesEngine.pkg" WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_packages" OUTPUT_VARIABLE TOLUAXX_OUTPUT)

        # --- Write tolua++ output--- "
        if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_AllStatesEngine.cpp")
            file (REMOVE "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_AllStatesEngine.cpp")
        endif ()
        file (WRITE "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_AllStatesEngine.cpp" "${TOLUAXX_OUTPUT}")
        file (COPY "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_AllStatesEngine.cpp" DESTINATION "${CMAKE_SOURCE_DIR}/vendors")
    else ()
        file (COPY "${CMAKE_SOURCE_DIR}/vendors/tolua_AllStatesEngine.cpp" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/Lua")
    endif ()
endif ()

# --- Generate StatesEngineAll.hpp --- #
file (GLOB Headers "*.hpp")
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/StatesEngineAll.hpp")
    file (REMOVE "${CMAKE_CURRENT_SOURCE_DIR}/StatesEngineAll.hpp")
endif ()

set (HeadersCode "#pragma once\n")
foreach (Header ${Headers})
    file (RELATIVE_PATH HeaderRelative ${CMAKE_CURRENT_SOURCE_DIR} ${Header})
    set (HeadersCode "${HeadersCode}#include \"${HeaderRelative}\"\n")
endforeach ()

if (STATES_ENGINE_LUA)
    file (GLOB LuaHeaders "Lua/*.hpp")
    foreach (LuaHeader ${LuaHeaders})
        file (RELATIVE_PATH LuaHeaderRelative ${CMAKE_CURRENT_SOURCE_DIR} ${LuaHeader})
        set (HeadersCode "${HeadersCode}#include \"${LuaHeaderRelative}\"\n")
    endforeach ()
endif ()
file (WRITE "${CMAKE_CURRENT_SOURCE_DIR}/StatesEngineAll.hpp" ${HeadersCode})

# --- Setup StatesEngine target --- #
if (NOT STATES_ENGINE_LIB_TYPE)
    set (STATES_ENGINE_LIB_TYPE STATIC)
endif ()

set (TARGET_NAME StatesEngine)
file (GLOB BasicHeaders "*.hpp")
file (GLOB BasicImplementations "*.cpp")
set (SOURCE_FILES ${BasicHeaders} ${BasicImplementations})

if (STATES_ENGINE_LUA)
    file (GLOB LuaBindingHeaders "Lua/*.hpp")
    file (GLOB LuaBindingImplementations "Lua/*.cpp")
    list (REMOVE_ITEM LuaBindingImplementations "${CMAKE_CURRENT_SOURCE_DIR}/Lua/tolua_AllStatesEngine.cpp")
    set (SOURCE_FILES ${SOURCE_FILES} ${LuaBindingHeaders} ${LuaBindingImplementations})
endif ()

define_dependency_libs (Urho3D)
setup_library (${STATES_ENGINE_LIB_TYPE})

# --- Configure StatesEngine installation if needed --- #
if (STATES_ENGINE_INSTALL)
    install (TARGETS StatesEngine EXPORT StatesEngineConfig ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/libs LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/libs)
    install (EXPORT StatesEngineConfig DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake)

    set (DEST_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/StatesEngine)
    install_header_files (FILES ${H_FILES} DESTINATION ${DEST_INCLUDE_DIR} FILES_MATCHING PATTERN *.hpp)
endif ()
# --- Write configuration variables which used as defines in StatesEngine code --- #
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/BuildConfig.hpp.cmake ${CMAKE_CURRENT_SOURCE_DIR}/BuildConfig.hpp)
