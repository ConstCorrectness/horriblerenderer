cmake_minimum_required(VERSION 3.20)
project(horrible-glad LANGUAGES C)


file(GLOB GLAD_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(glad STATIC ${GLAD_SOURCES})

target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(glad::glad ALIAS glad)

