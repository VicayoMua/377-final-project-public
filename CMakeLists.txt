cmake_minimum_required(VERSION 3.20)
project(DiskVirtualMemoryManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(
        DiskVirtualMemoryManager
        src/diskmno.cpp
        src/diskmallo.cpp
        src/main.cpp
        include/simplestack
        include/diskmno.h
        include/diskmallo.h

)

find_package(Threads REQUIRED)
target_link_libraries(DiskVirtualMemoryManager Threads::Threads)