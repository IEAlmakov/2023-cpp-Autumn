cmake_minimum_required(VERSION 3.5)

project(2024_04_01-Lesson-04 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task1 task1.cpp graph.h graph.cpp)

add_executable(task2 task2.cpp graph.h graph.cpp)

add_executable(task3 task3.cpp graph.h graph.cpp)

add_executable(task4 task4.cpp graph.h graph.cpp)

add_executable(task5 task5.cpp graph.h graph.cpp)

add_executable(task6 task6.cpp graph.h graph.cpp)

add_executable(task7 task7.cpp graph.h graph.cpp)

add_executable(task8 task8.cpp graph.h graph.cpp)

add_executable(task9 task9.cpp graph.h graph.cpp)

add_executable(task10 task10.cpp graph.h graph.cpp)

add_executable(task11 task11.cpp graph.h graph.cpp)

add_executable(task12 task12.cpp graph.h graph.cpp)

add_executable(task13 task13.cpp graph.h graph.cpp)

add_executable(task14 task14.cpp graph.h graph.cpp)

add_executable(task15 task15.cpp graph.h graph.cpp)

add_executable(task16 task16.cpp graph.h graph.cpp)


include(GNUInstallDirs)


install(TARGETS task1 task2 task3 task4 task6 task7 task8 task9 task10 task11 task12 task13 task14 task15 task16
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
