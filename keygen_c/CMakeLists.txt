cmake_minimum_required(VERSION 3.9)
project(keygen_c C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


add_executable(keygen_c main.c)
target_link_libraries(keygen_c m)
