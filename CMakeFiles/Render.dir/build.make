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
CMAKE_SOURCE_DIR = /home/moyuxishaojiu/opengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moyuxishaojiu/opengl

# Include any dependencies generated for this target.
include CMakeFiles/Render.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Render.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Render.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Render.dir/flags.make

CMakeFiles/Render.dir/test.cpp.o: CMakeFiles/Render.dir/flags.make
CMakeFiles/Render.dir/test.cpp.o: test.cpp
CMakeFiles/Render.dir/test.cpp.o: CMakeFiles/Render.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moyuxishaojiu/opengl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Render.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Render.dir/test.cpp.o -MF CMakeFiles/Render.dir/test.cpp.o.d -o CMakeFiles/Render.dir/test.cpp.o -c /home/moyuxishaojiu/opengl/test.cpp

CMakeFiles/Render.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Render.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moyuxishaojiu/opengl/test.cpp > CMakeFiles/Render.dir/test.cpp.i

CMakeFiles/Render.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Render.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moyuxishaojiu/opengl/test.cpp -o CMakeFiles/Render.dir/test.cpp.s

# Object files for target Render
Render_OBJECTS = \
"CMakeFiles/Render.dir/test.cpp.o"

# External object files for target Render
Render_EXTERNAL_OBJECTS =

Render: CMakeFiles/Render.dir/test.cpp.o
Render: CMakeFiles/Render.dir/build.make
Render: CMakeFiles/Render.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moyuxishaojiu/opengl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Render"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Render.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Render.dir/build: Render
.PHONY : CMakeFiles/Render.dir/build

CMakeFiles/Render.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Render.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Render.dir/clean

CMakeFiles/Render.dir/depend:
	cd /home/moyuxishaojiu/opengl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moyuxishaojiu/opengl /home/moyuxishaojiu/opengl /home/moyuxishaojiu/opengl /home/moyuxishaojiu/opengl /home/moyuxishaojiu/opengl/CMakeFiles/Render.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Render.dir/depend

