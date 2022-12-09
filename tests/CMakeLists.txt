cmake_minimum_required(VERSION 3.14)
project(polygon_api_tests)

#----------------------------------------------------------------------------------------------------------------------
# general settings and options
#----------------------------------------------------------------------------------------------------------------------

include("../cmake/utils.cmake")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}"
        is_top_level)

if(is_top_level)
    enable_testing()
    find_package(polygon_api REQUIRED)
endif()

#----------------------------------------------------------------------------------------------------------------------
# testing framework
#----------------------------------------------------------------------------------------------------------------------

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # do not override parent project's runtime settings on Windows
set(INSTALL_GTEST OFF)

# For simplicity, always build googletest as static library. This prevents mylib-tests executable from
# complaining about missing googletest DLLs on Windows.
set(BUILD_SHARED_LIBS OFF)

FetchContent_MakeAvailable(googletest)

#----------------------------------------------------------------------------------------------------------------------
# tests dependencies
#----------------------------------------------------------------------------------------------------------------------

if(is_top_level)
    find_package(polygon_api REQUIRED)
endif()

#----------------------------------------------------------------------------------------------------------------------
# tests source
#----------------------------------------------------------------------------------------------------------------------

set(sources
        add_test.cpp
        sub_test.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

#----------------------------------------------------------------------------------------------------------------------
# tests target
#----------------------------------------------------------------------------------------------------------------------

add_executable(polygon_api_tests)
target_sources(polygon_api_tests PRIVATE ${sources})

add_executable(polygon_api_test_add)
target_sources(polygon_api_test_add PRIVATE add_test.cpp)

target_link_libraries(polygon_api_tests
        PRIVATE
            polygon_api::polygon_api
            gtest_main)

target_link_libraries(polygon_api_test_add
        PRIVATE
        polygon_api::polygon_api
        gtest_main)

if(NOT is_top_level)
    win_copy_deps_to_target_dir(polygon_api_tests polygon_api::polygon_api)
endif()

include(GoogleTest)
gtest_discover_tests(polygon_api_tests)