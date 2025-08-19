cmake_minimum_required(VERSION 3.20)

project(HorribleRenderer
  VERSION 0.0.0.1
  DESCRIPTION "A Terrible Renderer"
  LANGUAGES CXX C ASM
)


# Options
option(BUILD_TESTING "Build tests" ON)
option(BUILD_BENCHMARKS "Build benchmarks" ON)
option(BUILD_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)


# Global C++ settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output dirs
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# External deps (submodules)
# --------------------------
# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
add_subdirectory(external/glfw)

include_directories(include)
include_directories(external/glad/include)

# GoogleTest
set(INSTALL_GTEST OFF CACHE BOOL "")
add_subdirectory(external/googletest)


# Google Benchmark
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "")
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "")
set(BENCHMARK_DOWNLOAD_DEPENDENCIES OFF CACHE BOOL "")
add_subdirectory(external/benchmark)


add_subdirectory(external/glad)


add_subdirectory(src)

# Tests
if(BUILD_TESTING)
enable_testing()
  add_subdirectory(tests)
endif()


# Benchmarks
if(BUILD_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()