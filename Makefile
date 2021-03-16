# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/csuser/Desktop/cpsc223/hw8-rdurnil

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csuser/Desktop/cpsc223/hw8-rdurnil

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csuser/Desktop/cpsc223/hw8-rdurnil/CMakeFiles /home/csuser/Desktop/cpsc223/hw8-rdurnil/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csuser/Desktop/cpsc223/hw8-rdurnil/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named hw8test

# Build rule for target.
hw8test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 hw8test
.PHONY : hw8test

# fast build rule for target.
hw8test/fast:
	$(MAKE) -f CMakeFiles/hw8test.dir/build.make CMakeFiles/hw8test.dir/build
.PHONY : hw8test/fast

#=============================================================================
# Target rules for targets named hw8perf

# Build rule for target.
hw8perf: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 hw8perf
.PHONY : hw8perf

# fast build rule for target.
hw8perf/fast:
	$(MAKE) -f CMakeFiles/hw8perf.dir/build.make CMakeFiles/hw8perf.dir/build
.PHONY : hw8perf/fast

hw8_perf.o: hw8_perf.cpp.o

.PHONY : hw8_perf.o

# target to build an object file
hw8_perf.cpp.o:
	$(MAKE) -f CMakeFiles/hw8perf.dir/build.make CMakeFiles/hw8perf.dir/hw8_perf.cpp.o
.PHONY : hw8_perf.cpp.o

hw8_perf.i: hw8_perf.cpp.i

.PHONY : hw8_perf.i

# target to preprocess a source file
hw8_perf.cpp.i:
	$(MAKE) -f CMakeFiles/hw8perf.dir/build.make CMakeFiles/hw8perf.dir/hw8_perf.cpp.i
.PHONY : hw8_perf.cpp.i

hw8_perf.s: hw8_perf.cpp.s

.PHONY : hw8_perf.s

# target to generate assembly for a file
hw8_perf.cpp.s:
	$(MAKE) -f CMakeFiles/hw8perf.dir/build.make CMakeFiles/hw8perf.dir/hw8_perf.cpp.s
.PHONY : hw8_perf.cpp.s

hw8_test.o: hw8_test.cpp.o

.PHONY : hw8_test.o

# target to build an object file
hw8_test.cpp.o:
	$(MAKE) -f CMakeFiles/hw8test.dir/build.make CMakeFiles/hw8test.dir/hw8_test.cpp.o
.PHONY : hw8_test.cpp.o

hw8_test.i: hw8_test.cpp.i

.PHONY : hw8_test.i

# target to preprocess a source file
hw8_test.cpp.i:
	$(MAKE) -f CMakeFiles/hw8test.dir/build.make CMakeFiles/hw8test.dir/hw8_test.cpp.i
.PHONY : hw8_test.cpp.i

hw8_test.s: hw8_test.cpp.s

.PHONY : hw8_test.s

# target to generate assembly for a file
hw8_test.cpp.s:
	$(MAKE) -f CMakeFiles/hw8test.dir/build.make CMakeFiles/hw8test.dir/hw8_test.cpp.s
.PHONY : hw8_test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... hw8test"
	@echo "... edit_cache"
	@echo "... hw8perf"
	@echo "... hw8_perf.o"
	@echo "... hw8_perf.i"
	@echo "... hw8_perf.s"
	@echo "... hw8_test.o"
	@echo "... hw8_test.i"
	@echo "... hw8_test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

