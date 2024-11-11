cmake_minimum_required(VERSION 3.10)

project(RoomFetch)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(roomfetch src/main.cpp src/modules.cpp)