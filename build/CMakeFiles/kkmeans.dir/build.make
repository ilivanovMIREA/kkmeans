# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ilivanov/kkmeans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilivanov/kkmeans/build

# Include any dependencies generated for this target.
include CMakeFiles/kkmeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kkmeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kkmeans.dir/flags.make

CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o: CMakeFiles/kkmeans.dir/flags.make
CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o: ../kkmeans/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilivanov/kkmeans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o -c /home/ilivanov/kkmeans/kkmeans/main.cpp

CMakeFiles/kkmeans.dir/kkmeans/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kkmeans.dir/kkmeans/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilivanov/kkmeans/kkmeans/main.cpp > CMakeFiles/kkmeans.dir/kkmeans/main.cpp.i

CMakeFiles/kkmeans.dir/kkmeans/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kkmeans.dir/kkmeans/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilivanov/kkmeans/kkmeans/main.cpp -o CMakeFiles/kkmeans.dir/kkmeans/main.cpp.s

CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.requires:

.PHONY : CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.requires

CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.provides: CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/kkmeans.dir/build.make CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.provides.build
.PHONY : CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.provides

CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.provides.build: CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o


# Object files for target kkmeans
kkmeans_OBJECTS = \
"CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o"

# External object files for target kkmeans
kkmeans_EXTERNAL_OBJECTS =

kkmeans: CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o
kkmeans: CMakeFiles/kkmeans.dir/build.make
kkmeans: /usr/local/lib/libdlib.a
kkmeans: /usr/lib/x86_64-linux-gnu/libnsl.so
kkmeans: /usr/lib/x86_64-linux-gnu/libX11.so
kkmeans: CMakeFiles/kkmeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilivanov/kkmeans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kkmeans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kkmeans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kkmeans.dir/build: kkmeans

.PHONY : CMakeFiles/kkmeans.dir/build

CMakeFiles/kkmeans.dir/requires: CMakeFiles/kkmeans.dir/kkmeans/main.cpp.o.requires

.PHONY : CMakeFiles/kkmeans.dir/requires

CMakeFiles/kkmeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kkmeans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kkmeans.dir/clean

CMakeFiles/kkmeans.dir/depend:
	cd /home/ilivanov/kkmeans/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilivanov/kkmeans /home/ilivanov/kkmeans /home/ilivanov/kkmeans/build /home/ilivanov/kkmeans/build /home/ilivanov/kkmeans/build/CMakeFiles/kkmeans.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kkmeans.dir/depend

