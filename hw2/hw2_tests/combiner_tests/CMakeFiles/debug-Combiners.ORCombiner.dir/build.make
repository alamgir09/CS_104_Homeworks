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
CMAKE_SOURCE_DIR = /work/hw-alamgir/hw2/hw2_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/hw-alamgir/hw2/hw2_tests

# Utility rule file for debug-Combiners.ORCombiner.

# Include the progress variables for this target.
include combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/progress.make

combiner_tests/CMakeFiles/debug-Combiners.ORCombiner:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/work/hw-alamgir/hw2/hw2_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging Combiners.ORCombiner with GDB..."
	cd /work/hw-alamgir/hw2 && gdb --args /work/hw-alamgir/hw2/hw2_tests/combiner_tests/combiner_tests --gtest_filter=Combiners.ORCombiner

debug-Combiners.ORCombiner: combiner_tests/CMakeFiles/debug-Combiners.ORCombiner
debug-Combiners.ORCombiner: combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/build.make

.PHONY : debug-Combiners.ORCombiner

# Rule to build all files generated by this target.
combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/build: debug-Combiners.ORCombiner

.PHONY : combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/build

combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/clean:
	cd /work/hw-alamgir/hw2/hw2_tests/combiner_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-Combiners.ORCombiner.dir/cmake_clean.cmake
.PHONY : combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/clean

combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/depend:
	cd /work/hw-alamgir/hw2/hw2_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/hw-alamgir/hw2/hw2_tests /work/hw-alamgir/hw2/hw2_tests/combiner_tests /work/hw-alamgir/hw2/hw2_tests /work/hw-alamgir/hw2/hw2_tests/combiner_tests /work/hw-alamgir/hw2/hw2_tests/combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : combiner_tests/CMakeFiles/debug-Combiners.ORCombiner.dir/depend

