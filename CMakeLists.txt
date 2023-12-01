cmake_minimum_required(VERSION 3.25)
project(DiskVirtualMemoryManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(
        DiskVirtualMemoryManager
        src/main.cpp
        include/simplestack
        include/diskmno
        include/diskmallo

)

find_package(Threads REQUIRED)
target_link_libraries(DiskVirtualMemoryManager Threads::Threads)