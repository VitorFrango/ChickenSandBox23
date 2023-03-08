cmake_minimum_required(VERSION 3.24)
project(ChickenSandBox C)

set(CMAKE_C_STANDARD 11)

add_executable(ChickenSandBox main.c ola.c hello.c SistemasOp/ola.c)
add_executable(ChickenSandBox_Fork_teste Fork_teste.c)
add_executable(ChickenSandBox_ola ola.c)
add_executable(ChickenSandBox_hello hello.c)


add_executable(ChickenSandBox_testesBatalahNaval testes/BatalahNaval.c)
add_executable(ChickenSandBox_testesalgo testes/algo.c)

add_executable(ChickenSandBox_SistemasOpola SistemasOp/ola.c)

