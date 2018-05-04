cmake_minimum_required(VERSION 3.2.2) 
project(gentle-intro-to-ranges C CXX)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)

################################################################################
# C++ standard settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

################################################################################
# Diverse variables

# ...

################################################################################
# Add library from subfolder
# add_subdirectory(libs/arithmetics)

################################################################################
# Add Executable
# add_subdirectory(src)

################################################################################
enable_testing()

################################################################################
# Build test dependencies for Catch and Gtest.
add_subdirectory(test-catch)

