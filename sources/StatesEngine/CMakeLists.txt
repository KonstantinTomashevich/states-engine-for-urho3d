# --- Create tolua++ StatesEngine bindings --- $
if (STATES_ENGINE_LUA)
    # --- Copy tolua++ header because tolua++ generates files with relative include ("#include "tolua++.h") --- #
    file (COPY ${URHO3D_HOME}/include/Urho3D/ThirdParty/toluapp/tolua++.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/generated)

    # --- Setup Urho3D's default tolua++ executable if it isn't specified --- #
    if (NOT TOLUAXX_EXECUTABLE)
        set (TOLUAXX_EXECUTABLE ${URHO3D_HOME}/bin/tool/tolua++${CMAKE_EXECUTABLE_SUFFIX})
        message (STATUS "TOLUAXX_EXECUTABLE setted automaticaly from Urho3D home.")
    endif ()
    message (STATUS "Current TOLUAXX_EXECUTABLE is: ${TOLUAXX_EXECUTABLE}")

    # --- Scan for top-level tolua++ packages --- #
    file (GLOB LuaPackages tolua_packages/*.pkg)

    set (ToLuaFiles "")
    set (PerPackageEnableHeader "")
    set (PackagesCXXHeadersInclude "")
    set (IncludesList "")
    set (EnableAllCode "")
    set (LuaInitAllCode "")
    set (EnablersAndInitializerCode "")

    # --- Run tolua++ on each top-level package and generate code for it's include --- #
    foreach (Package ${LuaPackages})
        get_filename_component (PackageName ${Package} NAME_WE)
        execute_process (COMMAND ${TOLUAXX_EXECUTABLE} -o ${CMAKE_CURRENT_SOURCE_DIR}/generated/tolua_${PackageName}.cpp ${Package})

        set (PerPackageEnableHeader "${PerPackageEnableHeader}void Enable${PackageName} (Urho3D::LuaScript *luaScript);\n")
        set (PackagesCXXHeadersInclude "${PackagesCXXHeadersInclude}#include \"${PackageName}.hpp\"\n")
        set (IncludesList "${IncludesList}namespace ToLuaXX_${PackageName}\n{\n#include \"generated/tolua_${PackageName}.cpp\"\n}\n\n")
        set (EnableAllCode "${EnableAllCode}    Enable${PackageName} (luaScript);\n")
        set (EnablersAndInitializerCode "${EnablersAndInitializerCode}void Enable${PackageName} (Urho3D::LuaScript *luaScript)\n{\n")
        set (EnablersAndInitializerCode "${EnablersAndInitializerCode}    ToLuaXX_${PackageName}::tolua_${PackageName}_open (luaScript->GetState ());\n}\n")

        # --- Execute special setup code for package if needed --- #
        if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tolua_packages/__init.${PackageName}.lua")
            file (COPY "${CMAKE_CURRENT_SOURCE_DIR}/tolua_packages/__init.${PackageName}.lua" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Data/ToLuaPackagesInitializers")
            #file (READ "${CMAKE_CURRENT_SOURCE_DIR}/tolua_packages/__init.${PackageName}.lua" luaEnablerCode)
            #string (REPLACE "\"" "\\\"" luaEnablerCode ${luaEnablerCode})
            #string (REPLACE "\n" "\\n\"\n                              \"" luaEnablerCode ${luaEnablerCode})

            set (EnablersAndInitializerCode "${EnablersAndInitializerCode}\nvoid LuaInit${PackageName} (Urho3D::LuaScript *luaScript)\n{\n")
            set (EnablersAndInitializerCode "${EnablersAndInitializerCode}    luaScript->ExecuteFile (\"ToLuaPackagesInitializers/__init.${PackageName}.lua\");\n}\n")

            set (PerPackageEnableHeader "${PerPackageEnableHeader}void LuaInit${PackageName} (Urho3D::LuaScript *luaScript);\n")
            set (LuaInitAllCode "${LuaInitAllCode}    LuaInit${PackageName} (luaScript);\n")
        endif ()
        set (EnablersAndInitializerCode "${EnablersAndInitializerCode}\n")
    endforeach ()

    # --- Write enablers code to special compile module for easier using in application --- #
    configure_file (${CMAKE_CURRENT_SOURCE_DIR}/EnableLuaBindings.hpp.cmake ${CMAKE_CURRENT_SOURCE_DIR}/EnableLuaBindings.hpp)
    configure_file (${CMAKE_CURRENT_SOURCE_DIR}/EnableLuaBindings.cpp.cmake ${CMAKE_CURRENT_SOURCE_DIR}/EnableLuaBindings.cpp)
endif ()

# --- Setup StatesEngine target --- #
if (NOT STATES_ENGINE_LIB_TYPE)
    set (STATES_ENGINE_LIB_TYPE STATIC)
endif ()

set (TARGET_NAME StatesEngine)
define_source_files (GLOB_H_PATTERNS "*.hpp")
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
