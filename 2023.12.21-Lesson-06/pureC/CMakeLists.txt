cmake_minimum_required(VERSION 3.5)

project(pureC LANGUAGES C)

add_executable(pureC main.c
    my_string.h
    my_string.c
    writer.h
    writer.c
    helper.h
    helper.c
)

include(GNUInstallDirs)
install(TARGETS pureC
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
