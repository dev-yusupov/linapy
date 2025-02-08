cmake_minimum_required(VERSION 3.31)
project(LinaPyTests LANGUAGES CXX)

# Get the parent directory of the CMakeLists.txt
get_filename_component(BASE_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "Base directory: ${BASE_DIR}")

# Specify the path to the pybind11 package
set(CMAKE_PREFIX_PATH "${BASE_DIR}/.venv/Lib/site-packages/pybind11/share/cmake/pybind11")

# Add the pybind11_DIR variable
set(pybind11_DIR "${BASE_DIR}/.venv/Lib/site-packages/pybind11/share/cmake/pybind11")

# Include vcpkg toolchain file (only if needed for other dependencies)
set(CMAKE_TOOLCHAIN_FILE "C:/msys64/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Find pybind11
find_package(pybind11 REQUIRED)
message(STATUS "Found pybind11: ${pybind11_FOUND}")

# Use FetchContent to download and build GoogleTest
include(FetchContent)
FetchContent_Declare(
  gtest
  QUIET
  URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)
message(STATUS "GoogleTest downloaded and built")

# Define linapy library
add_library(linapy STATIC ${BASE_DIR}/linapy/determinant.cpp)
target_link_libraries(linapy PRIVATE pybind11::module)
message(STATUS "Linapy library defined")

# Find all test source files
file(GLOB_RECURSE ALL_CPP_SOURCES ${BASE_DIR}/tests/test_linapy_types/*.cpp)
message(STATUS "All source files: ${ALL_CPP_SOURCES}")  # Debugging output

# Define test executable
add_executable(unit_tests ${ALL_CPP_SOURCES})
target_link_libraries(unit_tests PRIVATE linapy gtest_main)
message(STATUS "Test executable defined")

# Enable testing
enable_testing()
add_test(NAME unit_tests COMMAND unit_tests)

# Use GoogleTest to automatically discover tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT 60  # Increased timeout for discovery
)
message(STATUS "Test discovery enabled")
