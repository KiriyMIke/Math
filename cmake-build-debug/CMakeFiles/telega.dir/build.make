# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oleg/CLionProjects/Math

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oleg/CLionProjects/Math/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/telega.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/telega.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/telega.dir/flags.make

CMakeFiles/telega.dir/main.cpp.o: CMakeFiles/telega.dir/flags.make
CMakeFiles/telega.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/CLionProjects/Math/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/telega.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/telega.dir/main.cpp.o -c /home/oleg/CLionProjects/Math/main.cpp

CMakeFiles/telega.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/telega.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/CLionProjects/Math/main.cpp > CMakeFiles/telega.dir/main.cpp.i

CMakeFiles/telega.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/telega.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/CLionProjects/Math/main.cpp -o CMakeFiles/telega.dir/main.cpp.s

# Object files for target telega
telega_OBJECTS = \
"CMakeFiles/telega.dir/main.cpp.o"

# External object files for target telega
telega_EXTERNAL_OBJECTS =

telega: CMakeFiles/telega.dir/main.cpp.o
telega: CMakeFiles/telega.dir/build.make
telega: libLIB.a
telega: CMakeFiles/telega.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oleg/CLionProjects/Math/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable telega"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/telega.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/telega.dir/build: telega

.PHONY : CMakeFiles/telega.dir/build

CMakeFiles/telega.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/telega.dir/cmake_clean.cmake
.PHONY : CMakeFiles/telega.dir/clean

CMakeFiles/telega.dir/depend:
	cd /home/oleg/CLionProjects/Math/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oleg/CLionProjects/Math /home/oleg/CLionProjects/Math /home/oleg/CLionProjects/Math/cmake-build-debug /home/oleg/CLionProjects/Math/cmake-build-debug /home/oleg/CLionProjects/Math/cmake-build-debug/CMakeFiles/telega.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/telega.dir/depend

