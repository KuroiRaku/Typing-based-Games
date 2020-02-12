cmake_minimum_required(VERSION 3.15)
project(glad LANGUAGES C)

add_library(glad STATIC)

target_include_directories(glad PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(glad PRIVATE "src/glad.c")


