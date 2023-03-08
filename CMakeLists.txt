cmake_minimum_required(VERSION 3.24)
project(ChickenSandBox C)

set(CMAKE_C_STANDARD 11)

add_executable(ChickenSandBox main.c testes/ola.c)
add_executable(ChickenSandBox_Fork_teste Fork_teste.c)
add_executable(ChickenSandBox_main ola.c)