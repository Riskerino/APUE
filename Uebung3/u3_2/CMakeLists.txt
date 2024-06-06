cmake_minimum_required(VERSION 3.10)

# Set the project name
project(translate_dna)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Add the executable
add_executable(translate_dna translate_dna.cpp)
