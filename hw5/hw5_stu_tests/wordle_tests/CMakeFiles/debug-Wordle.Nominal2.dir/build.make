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

# Utility rule file for debug-Wordle.Nominal2.

# Include the progress variables for this target.
include wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/progress.make

wordle_tests/CMakeFiles/debug-Wordle.Nominal2:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/work/hw-alamgir/hw5/hw5_stu_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging Wordle.Nominal2 with GDB..."
	cd /work/hw-alamgir/hw5 && gdb --args /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests/wordle_tests --gtest_filter=Wordle.Nominal2

debug-Wordle.Nominal2: wordle_tests/CMakeFiles/debug-Wordle.Nominal2
debug-Wordle.Nominal2: wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/build.make

.PHONY : debug-Wordle.Nominal2

# Rule to build all files generated by this target.
wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/build: debug-Wordle.Nominal2

.PHONY : wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/build

wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/clean:
	cd /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-Wordle.Nominal2.dir/cmake_clean.cmake
.PHONY : wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/clean

wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/depend:
	cd /work/hw-alamgir/hw5/hw5_stu_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/hw-alamgir/hw5/hw5_stu_tests /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests /work/hw-alamgir/hw5/hw5_stu_tests /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests /work/hw-alamgir/hw5/hw5_stu_tests/wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wordle_tests/CMakeFiles/debug-Wordle.Nominal2.dir/depend

