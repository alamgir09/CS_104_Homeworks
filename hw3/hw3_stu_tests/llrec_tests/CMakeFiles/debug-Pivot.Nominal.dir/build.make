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
CMAKE_SOURCE_DIR = /work/hw-alamgir/hw3/hw3_stu_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/hw-alamgir/hw3/hw3_stu_tests

# Utility rule file for debug-Pivot.Nominal.

# Include the progress variables for this target.
include llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/progress.make

llrec_tests/CMakeFiles/debug-Pivot.Nominal:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/work/hw-alamgir/hw3/hw3_stu_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging Pivot.Nominal with GDB..."
	cd /work/hw-alamgir/hw3 && gdb --args /work/hw-alamgir/hw3/hw3_stu_tests/llrec_tests/llrec_tests --gtest_filter=Pivot.Nominal

debug-Pivot.Nominal: llrec_tests/CMakeFiles/debug-Pivot.Nominal
debug-Pivot.Nominal: llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/build.make

.PHONY : debug-Pivot.Nominal

# Rule to build all files generated by this target.
llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/build: debug-Pivot.Nominal

.PHONY : llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/build

llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/clean:
	cd /work/hw-alamgir/hw3/hw3_stu_tests/llrec_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-Pivot.Nominal.dir/cmake_clean.cmake
.PHONY : llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/clean

llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/depend:
	cd /work/hw-alamgir/hw3/hw3_stu_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/hw-alamgir/hw3/hw3_stu_tests /work/hw-alamgir/hw3/hw3_stu_tests/llrec_tests /work/hw-alamgir/hw3/hw3_stu_tests /work/hw-alamgir/hw3/hw3_stu_tests/llrec_tests /work/hw-alamgir/hw3/hw3_stu_tests/llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : llrec_tests/CMakeFiles/debug-Pivot.Nominal.dir/depend

