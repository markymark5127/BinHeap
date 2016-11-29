cmake_minimum_required(VERSION 3.6)
project(BinHeap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES
    Flags.h
    BinHeap.h
    BinHeap.cpp
    catch.hpp
    tests.cpp)

add_executable(BinHeap ${SOURCE_FILES})
target_link_libraries(BinHeap ${CMAKE_SOURCE_DIR}/libBinHeap.a)
set_target_properties(BinHeap PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )
