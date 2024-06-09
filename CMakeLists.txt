cmake_minimum_required(VERSION 3.28)
project(fila_banco C)

set(CMAKE_C_STANDARD 23)

add_executable(fila_banco main.c
        include/node.h
        src/node.c
        include/menu.h
        src/menu.c)

include_directories(include)
