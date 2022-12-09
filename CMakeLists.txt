cmake_minimum_required(VERSION 3.15)
project(polygon_api
        VERSION 1.0.0
        DESCRIPTION "C++ library maintaining codeforces polygon user-api interaction"
        LANGUAGES CXX)

#----------------------------------------------------------------------------------------------------------------------
# general settings and options
#----------------------------------------------------------------------------------------------------------------------

if (PARENT_CXX_STANDARD)
    if (PARENT_CXX_STANDARD LESS 17)
        message(FATAL_ERROR "cpr ${cpr_VERSION} does not support ${PARENT_CXX_STANDARD}")
    endif()
else()
    # Set standard version if not already set by potential parent project
    set(CMAKE_CXX_STANDARD 17)
endif()

message(STATUS "CXX standard: ${CMAKE_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/utils.cmake)
include(GNUInstallDirs)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

# POLYGON_API_SHARED_LIBS option (undefined by default) can be used to force shared/static build
option(POLYGON_API_BUILD_TESTS "Build polygon_api tests" ON)
option(POLYGON_API_BUILD_EXAMPLES "Build polygon_api examples" ON)
option(POLYGON_API_BUILD_DOCS "Build polygon_api documentation" OFF)
option(POLYGON_API_INSTALL "Generate target for installing polygon_api" ${is_top_level})
set_if_undefined(POLYGON_API_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/polygon_api" CACHE STRING
        "Install path for polygon_api package-related CMake files")

if(DEFINED POLYGON_API_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ${POLYGON_API_SHARED_LIBS})
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set_if_undefined(CMAKE_CXX_VISIBILITY_PRESET hidden)
set_if_undefined(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

add_library(polygon_api) # initialized below
add_library(polygon_api::polygon_api ALIAS polygon_api)

#----------------------------------------------------------------------------------------------------------------------
# polygon_api dependencies
#----------------------------------------------------------------------------------------------------------------------

# Search for your dependencies here

#----------------------------------------------------------------------------------------------------------------------
# polygon_api sources
#----------------------------------------------------------------------------------------------------------------------

include(GenerateExportHeader)
set(export_file_name "export_shared.h")

if(NOT BUILD_SHARED_LIBS)
    set(export_file_name "export_static.h")
endif()

generate_export_header(polygon_api EXPORT_FILE_NAME include/polygon_api/${export_file_name})

set(sources
        include/polygon_api/export.h
        include/polygon_api/polygon_api.h
        src/polygon_api.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

#----------------------------------------------------------------------------------------------------------------------
# polygon_api target
#----------------------------------------------------------------------------------------------------------------------

include(CMakePackageConfigHelpers)

target_sources(polygon_api PRIVATE ${sources})
target_compile_definitions(polygon_api PUBLIC "$<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:POLYGON_API_STATIC_DEFINE>")

target_include_directories(polygon_api
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>")

set_target_properties(polygon_api PROPERTIES
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION})

if(POLYGON_API_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
    configure_package_config_file(cmake/polygon_api-config.cmake.in polygon_api-config.cmake
            INSTALL_DESTINATION "${POLYGON_API_INSTALL_CMAKEDIR}")

    write_basic_package_version_file(polygon_api-config-version.cmake
            COMPATIBILITY SameMajorVersion)

    install(TARGETS polygon_api EXPORT polygon_api_export
            RUNTIME COMPONENT polygon_api
            LIBRARY COMPONENT polygon_api NAMELINK_COMPONENT polygon_api-dev
            ARCHIVE COMPONENT polygon_api-dev
            INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
    install(DIRECTORY include/
            TYPE INCLUDE
            COMPONENT polygon_api-dev)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/polygon_api/${export_file_name}"
            COMPONENT polygon_api-dev
            DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/polygon_api")

    set(targets_file "polygon_api-shared-targets.cmake")

    if(NOT BUILD_SHARED_LIBS)
        set(targets_file "polygon_api-static-targets.cmake")
    endif()

    install(EXPORT polygon_api_export
            COMPONENT polygon_api-dev
            FILE "${targets_file}"
            DESTINATION "${POLYGON_API_INSTALL_CMAKEDIR}"
            NAMESPACE polygon_api::)

    install(FILES
            "${CMAKE_CURRENT_BINARY_DIR}/polygon_api-config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/polygon_api-config-version.cmake"
            COMPONENT polygon_api-dev
            DESTINATION "${POLYGON_API_INSTALL_CMAKEDIR}")

    if(MSVC)
        set(pdb_file "")
        set(pdb_file_destination "")

        if(BUILD_SHARED_LIBS)
            set(pdb_file "$<TARGET_PDB_FILE:polygon_api>")
            set(pdb_file_destination "${CMAKE_INSTALL_BINDIR}")
        else()
            # TARGET_PDB_FILE does not work for pdb file generated for static library build, determining it manually
            set(pdb_file "$<TARGET_FILE_DIR:polygon_api>/$<TARGET_FILE_PREFIX:polygon_api>$<TARGET_FILE_BASE_NAME:polygon_api>.pdb")
            set(pdb_file_destination "${CMAKE_INSTALL_LIBDIR}")
        endif()

        install(FILES "${pdb_file}"
                COMPONENT polygon_api-dev
                CONFIGURATIONS Debug RelWithDebInfo
                DESTINATION "${pdb_file_destination}"
                OPTIONAL)
    endif()
endif()

#----------------------------------------------------------------------------------------------------------------------
# other targets
#----------------------------------------------------------------------------------------------------------------------

if(POLYGON_API_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(POLYGON_API_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(POLYGON_API_BUILD_DOCS)
    find_package(Doxygen REQUIRED)
    doxygen_add_docs(docs include)
endif()

find_package(cpr REQUIRED)

target_link_libraries(polygon_api
        PRIVATE
            polygon_api::polygon_api
            cpr::cpr)