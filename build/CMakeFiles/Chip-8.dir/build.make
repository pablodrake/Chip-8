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
CMAKE_SOURCE_DIR = /home/xd/Desktop/repos/Chip-8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xd/Desktop/repos/Chip-8/build

# Include any dependencies generated for this target.
include CMakeFiles/Chip-8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Chip-8.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Chip-8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chip-8.dir/flags.make

CMakeFiles/Chip-8.dir/src/main.cpp.o: CMakeFiles/Chip-8.dir/flags.make
CMakeFiles/Chip-8.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Chip-8.dir/src/main.cpp.o: CMakeFiles/Chip-8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xd/Desktop/repos/Chip-8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chip-8.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chip-8.dir/src/main.cpp.o -MF CMakeFiles/Chip-8.dir/src/main.cpp.o.d -o CMakeFiles/Chip-8.dir/src/main.cpp.o -c /home/xd/Desktop/repos/Chip-8/src/main.cpp

CMakeFiles/Chip-8.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chip-8.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xd/Desktop/repos/Chip-8/src/main.cpp > CMakeFiles/Chip-8.dir/src/main.cpp.i

CMakeFiles/Chip-8.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chip-8.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xd/Desktop/repos/Chip-8/src/main.cpp -o CMakeFiles/Chip-8.dir/src/main.cpp.s

CMakeFiles/Chip-8.dir/src/Chip8.cpp.o: CMakeFiles/Chip-8.dir/flags.make
CMakeFiles/Chip-8.dir/src/Chip8.cpp.o: ../src/Chip8.cpp
CMakeFiles/Chip-8.dir/src/Chip8.cpp.o: CMakeFiles/Chip-8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xd/Desktop/repos/Chip-8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Chip-8.dir/src/Chip8.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chip-8.dir/src/Chip8.cpp.o -MF CMakeFiles/Chip-8.dir/src/Chip8.cpp.o.d -o CMakeFiles/Chip-8.dir/src/Chip8.cpp.o -c /home/xd/Desktop/repos/Chip-8/src/Chip8.cpp

CMakeFiles/Chip-8.dir/src/Chip8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chip-8.dir/src/Chip8.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xd/Desktop/repos/Chip-8/src/Chip8.cpp > CMakeFiles/Chip-8.dir/src/Chip8.cpp.i

CMakeFiles/Chip-8.dir/src/Chip8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chip-8.dir/src/Chip8.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xd/Desktop/repos/Chip-8/src/Chip8.cpp -o CMakeFiles/Chip-8.dir/src/Chip8.cpp.s

# Object files for target Chip-8
Chip__8_OBJECTS = \
"CMakeFiles/Chip-8.dir/src/main.cpp.o" \
"CMakeFiles/Chip-8.dir/src/Chip8.cpp.o"

# External object files for target Chip-8
Chip__8_EXTERNAL_OBJECTS =

Chip-8: CMakeFiles/Chip-8.dir/src/main.cpp.o
Chip-8: CMakeFiles/Chip-8.dir/src/Chip8.cpp.o
Chip-8: CMakeFiles/Chip-8.dir/build.make
Chip-8: CMakeFiles/Chip-8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xd/Desktop/repos/Chip-8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Chip-8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chip-8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chip-8.dir/build: Chip-8
.PHONY : CMakeFiles/Chip-8.dir/build

CMakeFiles/Chip-8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chip-8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chip-8.dir/clean

CMakeFiles/Chip-8.dir/depend:
	cd /home/xd/Desktop/repos/Chip-8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xd/Desktop/repos/Chip-8 /home/xd/Desktop/repos/Chip-8 /home/xd/Desktop/repos/Chip-8/build /home/xd/Desktop/repos/Chip-8/build /home/xd/Desktop/repos/Chip-8/build/CMakeFiles/Chip-8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chip-8.dir/depend

