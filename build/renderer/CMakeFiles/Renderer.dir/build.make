# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abduraghmaan/Desktop/Nibbler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abduraghmaan/Desktop/Nibbler/build

# Include any dependencies generated for this target.
include renderer/CMakeFiles/Renderer.dir/depend.make

# Include the progress variables for this target.
include renderer/CMakeFiles/Renderer.dir/progress.make

# Include the compile flags for this target's objects.
include renderer/CMakeFiles/Renderer.dir/flags.make

renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o: renderer/CMakeFiles/Renderer.dir/flags.make
renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o: ../renderer/src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abduraghmaan/Desktop/Nibbler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o"
	cd /home/abduraghmaan/Desktop/Nibbler/build/renderer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Renderer.cpp.o -c /home/abduraghmaan/Desktop/Nibbler/renderer/src/Renderer.cpp

renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Renderer.cpp.i"
	cd /home/abduraghmaan/Desktop/Nibbler/build/renderer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abduraghmaan/Desktop/Nibbler/renderer/src/Renderer.cpp > CMakeFiles/Renderer.dir/src/Renderer.cpp.i

renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Renderer.cpp.s"
	cd /home/abduraghmaan/Desktop/Nibbler/build/renderer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abduraghmaan/Desktop/Nibbler/renderer/src/Renderer.cpp -o CMakeFiles/Renderer.dir/src/Renderer.cpp.s

renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.requires:

.PHONY : renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.requires

renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.provides: renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.requires
	$(MAKE) -f renderer/CMakeFiles/Renderer.dir/build.make renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.provides.build
.PHONY : renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.provides

renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.provides.build: renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o


# Object files for target Renderer
Renderer_OBJECTS = \
"CMakeFiles/Renderer.dir/src/Renderer.cpp.o"

# External object files for target Renderer
Renderer_EXTERNAL_OBJECTS =

renderer/libRenderer.a: renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o
renderer/libRenderer.a: renderer/CMakeFiles/Renderer.dir/build.make
renderer/libRenderer.a: renderer/CMakeFiles/Renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abduraghmaan/Desktop/Nibbler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRenderer.a"
	cd /home/abduraghmaan/Desktop/Nibbler/build/renderer && $(CMAKE_COMMAND) -P CMakeFiles/Renderer.dir/cmake_clean_target.cmake
	cd /home/abduraghmaan/Desktop/Nibbler/build/renderer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
renderer/CMakeFiles/Renderer.dir/build: renderer/libRenderer.a

.PHONY : renderer/CMakeFiles/Renderer.dir/build

renderer/CMakeFiles/Renderer.dir/requires: renderer/CMakeFiles/Renderer.dir/src/Renderer.cpp.o.requires

.PHONY : renderer/CMakeFiles/Renderer.dir/requires

renderer/CMakeFiles/Renderer.dir/clean:
	cd /home/abduraghmaan/Desktop/Nibbler/build/renderer && $(CMAKE_COMMAND) -P CMakeFiles/Renderer.dir/cmake_clean.cmake
.PHONY : renderer/CMakeFiles/Renderer.dir/clean

renderer/CMakeFiles/Renderer.dir/depend:
	cd /home/abduraghmaan/Desktop/Nibbler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abduraghmaan/Desktop/Nibbler /home/abduraghmaan/Desktop/Nibbler/renderer /home/abduraghmaan/Desktop/Nibbler/build /home/abduraghmaan/Desktop/Nibbler/build/renderer /home/abduraghmaan/Desktop/Nibbler/build/renderer/CMakeFiles/Renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : renderer/CMakeFiles/Renderer.dir/depend

