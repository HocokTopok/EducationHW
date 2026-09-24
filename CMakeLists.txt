#################################################################

cmake_minimum_required(VERSION 3.28)

#################################################################

project(EducationHW LANGUAGES CXX)

#################################################################

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED True)

#################################################################

find_package(GTest CONFIG REQUIRED)

#################################################################

file(GLOB sources CONFIGURE_DEPENDS "Tasks/*.cpp")

foreach(source IN LISTS sources)
    get_filename_component(name "${source}" NAME_WLE)
    string(REPLACE "." "_" target_name "${name}")

    add_executable         (task_${target_name} "${source}")
    set_target_properties  (task_${target_name} PROPERTIES OUTPUT_NAME "${name}")
    target_compile_options (task_${target_name} PRIVATE -Wall -Wextra -Wpedantic)
    target_link_libraries  (task_${target_name} PRIVATE GTest::gtest)
endforeach()

#################################################################