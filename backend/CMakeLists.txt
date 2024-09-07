cmake_minimum_required(VERSION 3.13)  # CMake version check
project(Solver)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add all files
file(GLOB SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Set the executable location to the backend folder
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(solve.exe ${SOURCE_FILES})