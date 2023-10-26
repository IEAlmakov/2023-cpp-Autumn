cmake_minimum_required(VERSION 3.5)

project(Array_program LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Array_program main.cpp
    correct.h correct.cpp
    array.h array.cpp)

include(GNUInstallDirs)
install(TARGETS Array_program
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
