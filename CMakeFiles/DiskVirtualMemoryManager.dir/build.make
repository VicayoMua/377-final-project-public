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
include CMakeFiles/DiskVirtualMemoryManager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DiskVirtualMemoryManager.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DiskVirtualMemoryManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DiskVirtualMemoryManager.dir/flags.make

CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/flags.make
CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o -MF CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o.d -o CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o -c /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/main.cpp

CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/main.cpp > CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.i

CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/main.cpp -o CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.s

CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/flags.make
CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o: src/diskmno.cpp
CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o -MF CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o.d -o CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o -c /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmno.cpp

CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmno.cpp > CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.i

CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmno.cpp -o CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.s

CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/flags.make
CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o: src/diskmallo.cpp
CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o -MF CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o.d -o CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o -c /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmallo.cpp

CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmallo.cpp > CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.i

CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/diskmallo.cpp -o CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.s

CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/flags.make
CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o: src/my_malloc.cpp
CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o: CMakeFiles/DiskVirtualMemoryManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o -MF CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o.d -o CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o -c /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/my_malloc.cpp

CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/my_malloc.cpp > CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.i

CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/src/my_malloc.cpp -o CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.s

# Object files for target DiskVirtualMemoryManager
DiskVirtualMemoryManager_OBJECTS = \
"CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o" \
"CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o" \
"CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o" \
"CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o"

# External object files for target DiskVirtualMemoryManager
DiskVirtualMemoryManager_EXTERNAL_OBJECTS =

DiskVirtualMemoryManager: CMakeFiles/DiskVirtualMemoryManager.dir/src/main.cpp.o
DiskVirtualMemoryManager: CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmno.cpp.o
DiskVirtualMemoryManager: CMakeFiles/DiskVirtualMemoryManager.dir/src/diskmallo.cpp.o
DiskVirtualMemoryManager: CMakeFiles/DiskVirtualMemoryManager.dir/src/my_malloc.cpp.o
DiskVirtualMemoryManager: CMakeFiles/DiskVirtualMemoryManager.dir/build.make
DiskVirtualMemoryManager: CMakeFiles/DiskVirtualMemoryManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DiskVirtualMemoryManager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DiskVirtualMemoryManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DiskVirtualMemoryManager.dir/build: DiskVirtualMemoryManager
.PHONY : CMakeFiles/DiskVirtualMemoryManager.dir/build

CMakeFiles/DiskVirtualMemoryManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DiskVirtualMemoryManager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DiskVirtualMemoryManager.dir/clean

CMakeFiles/DiskVirtualMemoryManager.dir/depend:
	cd /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public /nfs/elsrv4/users1/grad/bltran/cs377/377-final-project-public/CMakeFiles/DiskVirtualMemoryManager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DiskVirtualMemoryManager.dir/depend
