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
CMAKE_COMMAND = /root/Desktop/clion-2018.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /root/Desktop/clion-2018.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Desktop/Project/SO/myshell2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Desktop/Project/SO/myshell2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/myshell2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myshell2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myshell2.dir/flags.make

CMakeFiles/myshell2.dir/main.c.o: CMakeFiles/myshell2.dir/flags.make
CMakeFiles/myshell2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Desktop/Project/SO/myshell2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myshell2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myshell2.dir/main.c.o   -c /root/Desktop/Project/SO/myshell2/main.c

CMakeFiles/myshell2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myshell2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Desktop/Project/SO/myshell2/main.c > CMakeFiles/myshell2.dir/main.c.i

CMakeFiles/myshell2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myshell2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Desktop/Project/SO/myshell2/main.c -o CMakeFiles/myshell2.dir/main.c.s

CMakeFiles/myshell2.dir/main.c.o.requires:

.PHONY : CMakeFiles/myshell2.dir/main.c.o.requires

CMakeFiles/myshell2.dir/main.c.o.provides: CMakeFiles/myshell2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/myshell2.dir/build.make CMakeFiles/myshell2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/myshell2.dir/main.c.o.provides

CMakeFiles/myshell2.dir/main.c.o.provides.build: CMakeFiles/myshell2.dir/main.c.o


CMakeFiles/myshell2.dir/execute.c.o: CMakeFiles/myshell2.dir/flags.make
CMakeFiles/myshell2.dir/execute.c.o: ../execute.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Desktop/Project/SO/myshell2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/myshell2.dir/execute.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myshell2.dir/execute.c.o   -c /root/Desktop/Project/SO/myshell2/execute.c

CMakeFiles/myshell2.dir/execute.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myshell2.dir/execute.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Desktop/Project/SO/myshell2/execute.c > CMakeFiles/myshell2.dir/execute.c.i

CMakeFiles/myshell2.dir/execute.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myshell2.dir/execute.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Desktop/Project/SO/myshell2/execute.c -o CMakeFiles/myshell2.dir/execute.c.s

CMakeFiles/myshell2.dir/execute.c.o.requires:

.PHONY : CMakeFiles/myshell2.dir/execute.c.o.requires

CMakeFiles/myshell2.dir/execute.c.o.provides: CMakeFiles/myshell2.dir/execute.c.o.requires
	$(MAKE) -f CMakeFiles/myshell2.dir/build.make CMakeFiles/myshell2.dir/execute.c.o.provides.build
.PHONY : CMakeFiles/myshell2.dir/execute.c.o.provides

CMakeFiles/myshell2.dir/execute.c.o.provides.build: CMakeFiles/myshell2.dir/execute.c.o


CMakeFiles/myshell2.dir/divide.c.o: CMakeFiles/myshell2.dir/flags.make
CMakeFiles/myshell2.dir/divide.c.o: ../divide.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Desktop/Project/SO/myshell2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/myshell2.dir/divide.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myshell2.dir/divide.c.o   -c /root/Desktop/Project/SO/myshell2/divide.c

CMakeFiles/myshell2.dir/divide.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myshell2.dir/divide.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/Desktop/Project/SO/myshell2/divide.c > CMakeFiles/myshell2.dir/divide.c.i

CMakeFiles/myshell2.dir/divide.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myshell2.dir/divide.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/Desktop/Project/SO/myshell2/divide.c -o CMakeFiles/myshell2.dir/divide.c.s

CMakeFiles/myshell2.dir/divide.c.o.requires:

.PHONY : CMakeFiles/myshell2.dir/divide.c.o.requires

CMakeFiles/myshell2.dir/divide.c.o.provides: CMakeFiles/myshell2.dir/divide.c.o.requires
	$(MAKE) -f CMakeFiles/myshell2.dir/build.make CMakeFiles/myshell2.dir/divide.c.o.provides.build
.PHONY : CMakeFiles/myshell2.dir/divide.c.o.provides

CMakeFiles/myshell2.dir/divide.c.o.provides.build: CMakeFiles/myshell2.dir/divide.c.o


# Object files for target myshell2
myshell2_OBJECTS = \
"CMakeFiles/myshell2.dir/main.c.o" \
"CMakeFiles/myshell2.dir/execute.c.o" \
"CMakeFiles/myshell2.dir/divide.c.o"

# External object files for target myshell2
myshell2_EXTERNAL_OBJECTS =

myshell2: CMakeFiles/myshell2.dir/main.c.o
myshell2: CMakeFiles/myshell2.dir/execute.c.o
myshell2: CMakeFiles/myshell2.dir/divide.c.o
myshell2: CMakeFiles/myshell2.dir/build.make
myshell2: CMakeFiles/myshell2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Desktop/Project/SO/myshell2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable myshell2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myshell2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myshell2.dir/build: myshell2

.PHONY : CMakeFiles/myshell2.dir/build

CMakeFiles/myshell2.dir/requires: CMakeFiles/myshell2.dir/main.c.o.requires
CMakeFiles/myshell2.dir/requires: CMakeFiles/myshell2.dir/execute.c.o.requires
CMakeFiles/myshell2.dir/requires: CMakeFiles/myshell2.dir/divide.c.o.requires

.PHONY : CMakeFiles/myshell2.dir/requires

CMakeFiles/myshell2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myshell2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myshell2.dir/clean

CMakeFiles/myshell2.dir/depend:
	cd /root/Desktop/Project/SO/myshell2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Desktop/Project/SO/myshell2 /root/Desktop/Project/SO/myshell2 /root/Desktop/Project/SO/myshell2/cmake-build-debug /root/Desktop/Project/SO/myshell2/cmake-build-debug /root/Desktop/Project/SO/myshell2/cmake-build-debug/CMakeFiles/myshell2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myshell2.dir/depend

