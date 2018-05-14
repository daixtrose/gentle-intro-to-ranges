cmake_minimum_required(VERSION 3.2.2) 

include(CTest)


################################################################################
# Import Catch Test Framework 
################################################################################

# See http://dbgit.prakinf.tu-ilmenau.de/code/pfabric/blob/dbe8dbfe21a79c00738cf7762368181edf249767/cmake/Download3rdParty.cmake

include(../cmake-helper/DownloadProject/DownloadProject.cmake)
download_project(PROJ               catch
                 GIT_REPOSITORY      https://github.com/catchorg/Catch2
                 GIT_TAG             master
                 UPDATE_DISCONNECTED 1
)

set(CATCH_INCLUDE_DIR ${catch_SOURCE_DIR}/single_include CACHE INTERNAL "Path to include folder for Catch")
include_directories(${CATCH_INCLUDE_DIR})


################################################################################
# Define Unit Tests  
################################################################################

include_directories(../libs/range-v3/include)

add_executable(some_unit_test_using_catch 
    test_main.cpp
    transform.cpp
    composition.cpp
    conversion_to_stl.cpp
    dual_interface.cpp
    group_by.cpp
    yield_if.cpp
    remove_if.cpp
    set_operations.cpp
    dangling_references.cpp
    partitioning.cpp
    generating_sequences.cpp
    accessing_elements.cpp)

#target_link_libraries(some_unit_test_using_catch
#    arithmetics)


add_test(NAME some_unit_test_using_catch COMMAND some_unit_test_using_catch)
