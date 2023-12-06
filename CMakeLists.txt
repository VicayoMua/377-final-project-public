cmake_minimum_required(VERSION 3.20)
project(DiskVirtualMemoryManager)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

include_directories(googletest/googletest/include)
link_directories(googletest/build/lib)

add_executable(
        DiskVirtualMemoryManager
#        src/main.cpp
        include/simplestack
        include/diskmno
        include/diskmallo
        include/PageManager_ExtendedProj5
        test/test.cpp

)

find_package(Threads REQUIRED)
target_link_libraries(DiskVirtualMemoryManager Threads::Threads)

target_link_libraries(DiskVirtualMemoryManager gtest)