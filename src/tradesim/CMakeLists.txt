cmake_minimum_required(VERSION 3.25)

project(tradesim)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED lib.cc)
else()
    add_library(${PROJECT_NAME} lib.cc)
endif()
