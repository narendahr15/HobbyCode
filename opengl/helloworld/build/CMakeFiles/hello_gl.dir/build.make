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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/manimoha/Documents/hobby/opengl/helloworld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manimoha/Documents/hobby/opengl/helloworld/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_gl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_gl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_gl.dir/flags.make

CMakeFiles/hello_gl.dir/main.cpp.o: CMakeFiles/hello_gl.dir/flags.make
CMakeFiles/hello_gl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manimoha/Documents/hobby/opengl/helloworld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_gl.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello_gl.dir/main.cpp.o -c /home/manimoha/Documents/hobby/opengl/helloworld/main.cpp

CMakeFiles/hello_gl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_gl.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manimoha/Documents/hobby/opengl/helloworld/main.cpp > CMakeFiles/hello_gl.dir/main.cpp.i

CMakeFiles/hello_gl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_gl.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manimoha/Documents/hobby/opengl/helloworld/main.cpp -o CMakeFiles/hello_gl.dir/main.cpp.s

CMakeFiles/hello_gl.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hello_gl.dir/main.cpp.o.requires

CMakeFiles/hello_gl.dir/main.cpp.o.provides: CMakeFiles/hello_gl.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hello_gl.dir/build.make CMakeFiles/hello_gl.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hello_gl.dir/main.cpp.o.provides

CMakeFiles/hello_gl.dir/main.cpp.o.provides.build: CMakeFiles/hello_gl.dir/main.cpp.o


# Object files for target hello_gl
hello_gl_OBJECTS = \
"CMakeFiles/hello_gl.dir/main.cpp.o"

# External object files for target hello_gl
hello_gl_EXTERNAL_OBJECTS =

hello_gl: CMakeFiles/hello_gl.dir/main.cpp.o
hello_gl: CMakeFiles/hello_gl.dir/build.make
hello_gl: /usr/lib/x86_64-linux-gnu/libGL.so
hello_gl: /usr/lib/x86_64-linux-gnu/libGLU.so
hello_gl: /usr/lib/x86_64-linux-gnu/libglut.so
hello_gl: /usr/lib/x86_64-linux-gnu/libXmu.so
hello_gl: /usr/lib/x86_64-linux-gnu/libXi.so
hello_gl: CMakeFiles/hello_gl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/manimoha/Documents/hobby/opengl/helloworld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_gl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_gl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_gl.dir/build: hello_gl

.PHONY : CMakeFiles/hello_gl.dir/build

CMakeFiles/hello_gl.dir/requires: CMakeFiles/hello_gl.dir/main.cpp.o.requires

.PHONY : CMakeFiles/hello_gl.dir/requires

CMakeFiles/hello_gl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_gl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_gl.dir/clean

CMakeFiles/hello_gl.dir/depend:
	cd /home/manimoha/Documents/hobby/opengl/helloworld/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manimoha/Documents/hobby/opengl/helloworld /home/manimoha/Documents/hobby/opengl/helloworld /home/manimoha/Documents/hobby/opengl/helloworld/build /home/manimoha/Documents/hobby/opengl/helloworld/build /home/manimoha/Documents/hobby/opengl/helloworld/build/CMakeFiles/hello_gl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_gl.dir/depend
