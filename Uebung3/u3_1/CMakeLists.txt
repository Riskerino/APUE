cmake_minimum_required(VERSION 3.10)

# Set the project name
project(gc_content)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Add the executable
add_executable(gc_content gc_content.cpp)
