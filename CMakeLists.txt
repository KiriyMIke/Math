cmake_minimum_required(VERSION 3.0)

project(translator)

set(SOURCE_LIB translator.cpp)
add_library(LIB STATIC ${SOURCE_LIB})

add_executable(telega main.cpp)

target_link_libraries(telega LIB)