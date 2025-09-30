cmake_minimum_required(VERSION 3.16)
project(new_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(new_project ${SOURCES})

target_include_directories(new_project PRIVATE
    ${CMAKE_SOURCE_DIR}/include/
)

target_compile_options(new_project PRIVATE -Wall -Wextra -Wpedantic)

add_custom_target(run
    COMMAND $<TARGET_FILE:new_project>
    DEPENDS new_project
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
