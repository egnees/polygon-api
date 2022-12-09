cmake_minimum_required(VERSION 3.14)
project(polygon_api_add LANGUAGES CXX)

include("../../cmake/utils.cmake")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if(is_top_level)
    find_package(polygon_api REQUIRED)
endif()

set(sources main.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

add_executable(polygon_api_add)
target_sources(polygon_api_add PRIVATE ${sources})
target_link_libraries(polygon_api_add PRIVATE polygon_api::polygon_api)

if(NOT is_top_level)
    win_copy_deps_to_target_dir(polygon_api_add polygon_api::polygon_api)
endif()