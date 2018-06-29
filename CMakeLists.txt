cmake_minimum_required(VERSION 3.10)
project(alena)

set(CMAKE_CXX_STANDARD 98)

add_executable(alena main.cpp
        dealer.cpp
        dealer.h
        player.h player0036.cpp player0036.h)