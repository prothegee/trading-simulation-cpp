cmake_minimum_required(VERSION 3.25)

project(trading-simluation-cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_PDB_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

option(BUILD_TESTS "build the project tests; default: true" true)
option(BUILD_SHARED_LIBS "build shared libs; default: false" false)

include(scripts/cmake/init.cmake)

link_directories(BEFORE     ${CMAKE_SOURCE_DIR}/inc)
include_directories(BEFORE  ${CMAKE_SOURCE_DIR}/inc)

add_subdirectory(src/tradesim)
add_subdirectory(src/tradesim-engine)
add_subdirectory(src/tradesim-consumer)
add_subdirectory(src/tradesim-producer)
add_subdirectory(src/tradesim-simulate)

if (BUILD_TESTS)
    add_subdirectory(tests/unit_test) 
endif()
