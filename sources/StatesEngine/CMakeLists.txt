if (NOT STATES_ENGINE_LIB_TYPE)
set (STATES_ENGINE_LIB_TYPE STATIC)
endif ()

set (TARGET_NAME StatesEngine)
define_source_files (RECURSE GLOB_H_PATTERNS "*.hpp")
define_dependency_libs (Urho3D)
setup_library (${STATES_ENGINE_LIB_TYPE})

if (STATES_ENGINE_INSTALL)
    install (TARGETS StatesEngine EXPORT StatesEngineConfig ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/libs LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/libs)
    install (EXPORT StatesEngineConfig DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake)

    set (DEST_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/StatesEngine)
    install_header_files (FILES ${H_FILES} DESTINATION ${DEST_INCLUDE_DIR} FILES_MATCHING PATTERN *.hpp)
endif ()
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/BuildConfig.hpp.cmake ${CMAKE_CURRENT_SOURCE_DIR}/BuildConfig.hpp)
