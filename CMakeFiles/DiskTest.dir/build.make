# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public

# Include any dependencies generated for this target.
include CMakeFiles/DiskTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DiskTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DiskTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DiskTest.dir/flags.make

CMakeFiles/DiskTest.dir/src/diskmno.cpp.o: CMakeFiles/DiskTest.dir/flags.make
CMakeFiles/DiskTest.dir/src/diskmno.cpp.o: src/diskmno.cpp
CMakeFiles/DiskTest.dir/src/diskmno.cpp.o: CMakeFiles/DiskTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DiskTest.dir/src/diskmno.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DiskTest.dir/src/diskmno.cpp.o -MF CMakeFiles/DiskTest.dir/src/diskmno.cpp.o.d -o CMakeFiles/DiskTest.dir/src/diskmno.cpp.o -c /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmno.cpp

CMakeFiles/DiskTest.dir/src/diskmno.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiskTest.dir/src/diskmno.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmno.cpp > CMakeFiles/DiskTest.dir/src/diskmno.cpp.i

CMakeFiles/DiskTest.dir/src/diskmno.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiskTest.dir/src/diskmno.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmno.cpp -o CMakeFiles/DiskTest.dir/src/diskmno.cpp.s

CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o: CMakeFiles/DiskTest.dir/flags.make
CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o: src/diskmallo.cpp
CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o: CMakeFiles/DiskTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o -MF CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o.d -o CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o -c /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmallo.cpp

CMakeFiles/DiskTest.dir/src/diskmallo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiskTest.dir/src/diskmallo.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmallo.cpp > CMakeFiles/DiskTest.dir/src/diskmallo.cpp.i

CMakeFiles/DiskTest.dir/src/diskmallo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiskTest.dir/src/diskmallo.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmallo.cpp -o CMakeFiles/DiskTest.dir/src/diskmallo.cpp.s

CMakeFiles/DiskTest.dir/tests/main.cpp.o: CMakeFiles/DiskTest.dir/flags.make
CMakeFiles/DiskTest.dir/tests/main.cpp.o: tests/main.cpp
CMakeFiles/DiskTest.dir/tests/main.cpp.o: CMakeFiles/DiskTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DiskTest.dir/tests/main.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DiskTest.dir/tests/main.cpp.o -MF CMakeFiles/DiskTest.dir/tests/main.cpp.o.d -o CMakeFiles/DiskTest.dir/tests/main.cpp.o -c /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/tests/main.cpp

CMakeFiles/DiskTest.dir/tests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiskTest.dir/tests/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/tests/main.cpp > CMakeFiles/DiskTest.dir/tests/main.cpp.i

CMakeFiles/DiskTest.dir/tests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiskTest.dir/tests/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/tests/main.cpp -o CMakeFiles/DiskTest.dir/tests/main.cpp.s

# Object files for target DiskTest
DiskTest_OBJECTS = \
"CMakeFiles/DiskTest.dir/src/diskmno.cpp.o" \
"CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o" \
"CMakeFiles/DiskTest.dir/tests/main.cpp.o"

# External object files for target DiskTest
DiskTest_EXTERNAL_OBJECTS =

DiskTest: CMakeFiles/DiskTest.dir/src/diskmno.cpp.o
DiskTest: CMakeFiles/DiskTest.dir/src/diskmallo.cpp.o
DiskTest: CMakeFiles/DiskTest.dir/tests/main.cpp.o
DiskTest: CMakeFiles/DiskTest.dir/build.make
DiskTest: CMakeFiles/DiskTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DiskTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DiskTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DiskTest.dir/build: DiskTest
.PHONY : CMakeFiles/DiskTest.dir/build

CMakeFiles/DiskTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DiskTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DiskTest.dir/clean

CMakeFiles/DiskTest.dir/depend:
	cd /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles/DiskTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DiskTest.dir/depend
