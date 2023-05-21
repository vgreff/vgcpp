cmake_minimum_required (VERSION 3.8)

project(VgCpp CXX)
set(CMAKE_CXX_STANDARD 20)

set(thisproject_headerdir ${PROJECT_SOURCE_DIR} )
include_directories(${thisproject_headerdir})

add_subdirectory(apps)


enable_testing()
add_subdirectory(tests)
