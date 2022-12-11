cmake_minimum_required(VERSION 3.15)
project(polygon_api_add LANGUAGES CXX)

include("../../cmake/utils.cmake")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if(is_top_level)
    find_package(polygon_api REQUIRED)
endif()

find_package(cpr REQUIRED)

set(sources main.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

add_executable(polygon_api_auth)
target_sources(polygon_api_auth PRIVATE ${sources})
target_link_libraries(polygon_api_auth PRIVATE polygon_api::polygon_api cpr::cpr)

if(NOT is_top_level)
    win_copy_deps_to_target_dir(polygon_api_auth polygon_api::polygon_api)
endif()