cmake_minimum_required(VERSION 3.20)
project(DiskVirtualMemoryManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(
        DiskVirtualMemoryManager
        src/main.cpp
        src/diskmno.cpp
        src/diskmallo.cpp
        src/my_malloc.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(DiskVirtualMemoryManager Threads::Threads)

add_executable(
        MallocTest
        src/my_malloc.cpp
        tests/test.cpp
)
target_link_libraries(MallocTest gtest gtest_main pthread)