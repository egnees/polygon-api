cmake_minimum_required(VERSION 3.15)
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
        cpr_test.cpp
        auth_test.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

#----------------------------------------------------------------------------------------------------------------------
# tests target
#----------------------------------------------------------------------------------------------------------------------

find_package(cpr REQUIRED)

add_executable(polygon_api_tests)
target_sources(polygon_api_tests PRIVATE ${sources})

target_link_libraries(polygon_api_tests PRIVATE
        polygon_api::polygon_api
        gtest_main
        cpr::cpr)

# cpr test
add_executable(cpr_test)
target_sources(cpr_test PRIVATE cpr_test.cpp)

target_link_libraries(cpr_test PRIVATE
        polygon_api::polygon_api
        gtest_main
        cpr::cpr)

#auth test
add_executable(auth_test)
target_sources(auth_test PRIVATE auth_test.cpp)

target_link_libraries(auth_test PRIVATE
        polygon_api::polygon_api
        gtest_main
        cpr::cpr)

#create problem test
add_executable(create_problem_test)
target_sources(create_problem_test PRIVATE create_problem_test.cpp)

target_link_libraries(create_problem_test PRIVATE
        polygon_api::polygon_api
        gtest_main
        cpr::cpr)

#----------------------------------------------------------------------------------------------------------------------
# includes
#----------------------------------------------------------------------------------------------------------------------

if(NOT is_top_level)
    win_copy_deps_to_target_dir(polygon_api_tests polygon_api::polygon_api)
endif()

include(GoogleTest)
gtest_discover_tests(polygon_api_tests)