cmake_minimum_required(VERSION 3.0)

project(translator)

set(SOURCE_LIB translator.cpp)
add_library(LIB STATIC ${SOURCE_LIB})

<<<<<<< HEAD
add_executable(telega main.cpp)

target_link_libraries(telega LIB)
=======
add_executable(1 main.cpp)

target_link_libraries(1 LIB)
>>>>>>> 4fce83c831d1eb0573b680233fcef57d404e9908
