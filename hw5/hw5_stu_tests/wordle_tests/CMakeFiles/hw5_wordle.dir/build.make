# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /work/hw-alamgir/hw5/hw5_stu_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/hw-alamgir/hw5/hw5_stu_tests

# Include any dependencies generated for this target.
include wordle_tests/CMakeFiles/hw5_wordle.dir/depend.make

# Include the progress variables for this target.
include wordle_tests/CMakeFiles/hw5_wordle.dir/progress.make

# Include the compile flags for this target's objects.
include wordle_tests/CMakeFiles/hw5_wordle.dir/flags.make

wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.o: wordle_tests/CMakeFiles/hw5_wordle.dir/flags.make
wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.o: /work/hw-alamgir/hw5/wordle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/hw-alamgir/hw5/hw5_stu_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.o"
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.o -c /work/hw-alamgir/hw5/wordle.cpp

wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.i"
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/hw-alamgir/hw5/wordle.cpp > CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.i

wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.s"
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/hw-alamgir/hw5/wordle.cpp -o CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.s

wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.o: wordle_tests/CMakeFiles/hw5_wordle.dir/flags.make
wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.o: /work/hw-alamgir/hw5/dict-eng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/hw-alamgir/hw5/hw5_stu_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.o"
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.o -c /work/hw-alamgir/hw5/dict-eng.cpp

wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.i"
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/hw-alamgir/hw5/dict-eng.cpp > CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.i

wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.s"
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/hw-alamgir/hw5/dict-eng.cpp -o CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.s

# Object files for target hw5_wordle
hw5_wordle_OBJECTS = \
"CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.o" \
"CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.o"

# External object files for target hw5_wordle
hw5_wordle_EXTERNAL_OBJECTS =

wordle_tests/libhw5_wordle.a: wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/wordle.cpp.o
wordle_tests/libhw5_wordle.a: wordle_tests/CMakeFiles/hw5_wordle.dir/work/hw-alamgir/hw5/dict-eng.cpp.o
wordle_tests/libhw5_wordle.a: wordle_tests/CMakeFiles/hw5_wordle.dir/build.make
wordle_tests/libhw5_wordle.a: wordle_tests/CMakeFiles/hw5_wordle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/hw-alamgir/hw5/hw5_stu_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libhw5_wordle.a"
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw5_wordle.dir/cmake_clean_target.cmake
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw5_wordle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wordle_tests/CMakeFiles/hw5_wordle.dir/build: wordle_tests/libhw5_wordle.a

.PHONY : wordle_tests/CMakeFiles/hw5_wordle.dir/build

wordle_tests/CMakeFiles/hw5_wordle.dir/clean:
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw5_wordle.dir/cmake_clean.cmake
.PHONY : wordle_tests/CMakeFiles/hw5_wordle.dir/clean

wordle_tests/CMakeFiles/hw5_wordle.dir/depend:
	cd /work/hw-alamgir/hw5/hw5_stu_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/hw-alamgir/hw5/hw5_stu_tests /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests /work/hw-alamgir/hw5/hw5_stu_tests /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests/CMakeFiles/hw5_wordle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wordle_tests/CMakeFiles/hw5_wordle.dir/depend

