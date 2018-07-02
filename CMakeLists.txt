cmake_minimum_required(VERSION 3.10)
project(alena)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")

add_executable(alena main.cpp
        dealer.cpp
        dealer.h
        player.h
        player0036.h)