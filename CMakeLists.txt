cmake_minimum_required(VERSION 3.20)
project(DiskVirtualMemoryManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(
        DiskVirtualMemoryManager
        src/main.cpp
        include/simplestack
        include/diskmno
        include/diskmallo
        include/PageManager_ExtendedProj5

)

find_package(Threads REQUIRED)
target_link_libraries(DiskVirtualMemoryManager Threads::Threads)