# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build

# Include any dependencies generated for this target.
include CMakeFiles/regalloc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/regalloc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/regalloc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/regalloc.dir/flags.make

CMakeFiles/regalloc.dir/src/main.c.o: CMakeFiles/regalloc.dir/flags.make
CMakeFiles/regalloc.dir/src/main.c.o: /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/main.c
CMakeFiles/regalloc.dir/src/main.c.o: CMakeFiles/regalloc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/regalloc.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/regalloc.dir/src/main.c.o -MF CMakeFiles/regalloc.dir/src/main.c.o.d -o CMakeFiles/regalloc.dir/src/main.c.o -c /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/main.c

CMakeFiles/regalloc.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/regalloc.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/main.c > CMakeFiles/regalloc.dir/src/main.c.i

CMakeFiles/regalloc.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/regalloc.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/main.c -o CMakeFiles/regalloc.dir/src/main.c.s

CMakeFiles/regalloc.dir/src/utils.c.o: CMakeFiles/regalloc.dir/flags.make
CMakeFiles/regalloc.dir/src/utils.c.o: /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/utils.c
CMakeFiles/regalloc.dir/src/utils.c.o: CMakeFiles/regalloc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/regalloc.dir/src/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/regalloc.dir/src/utils.c.o -MF CMakeFiles/regalloc.dir/src/utils.c.o.d -o CMakeFiles/regalloc.dir/src/utils.c.o -c /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/utils.c

CMakeFiles/regalloc.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/regalloc.dir/src/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/utils.c > CMakeFiles/regalloc.dir/src/utils.c.i

CMakeFiles/regalloc.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/regalloc.dir/src/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/utils.c -o CMakeFiles/regalloc.dir/src/utils.c.s

CMakeFiles/regalloc.dir/src/regalloc.c.o: CMakeFiles/regalloc.dir/flags.make
CMakeFiles/regalloc.dir/src/regalloc.c.o: /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/regalloc.c
CMakeFiles/regalloc.dir/src/regalloc.c.o: CMakeFiles/regalloc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/regalloc.dir/src/regalloc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/regalloc.dir/src/regalloc.c.o -MF CMakeFiles/regalloc.dir/src/regalloc.c.o.d -o CMakeFiles/regalloc.dir/src/regalloc.c.o -c /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/regalloc.c

CMakeFiles/regalloc.dir/src/regalloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/regalloc.dir/src/regalloc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/regalloc.c > CMakeFiles/regalloc.dir/src/regalloc.c.i

CMakeFiles/regalloc.dir/src/regalloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/regalloc.dir/src/regalloc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/regalloc.c -o CMakeFiles/regalloc.dir/src/regalloc.c.s

CMakeFiles/regalloc.dir/src/container.c.o: CMakeFiles/regalloc.dir/flags.make
CMakeFiles/regalloc.dir/src/container.c.o: /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/container.c
CMakeFiles/regalloc.dir/src/container.c.o: CMakeFiles/regalloc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/regalloc.dir/src/container.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/regalloc.dir/src/container.c.o -MF CMakeFiles/regalloc.dir/src/container.c.o.d -o CMakeFiles/regalloc.dir/src/container.c.o -c /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/container.c

CMakeFiles/regalloc.dir/src/container.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/regalloc.dir/src/container.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/container.c > CMakeFiles/regalloc.dir/src/container.c.i

CMakeFiles/regalloc.dir/src/container.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/regalloc.dir/src/container.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/src/container.c -o CMakeFiles/regalloc.dir/src/container.c.s

# Object files for target regalloc
regalloc_OBJECTS = \
"CMakeFiles/regalloc.dir/src/main.c.o" \
"CMakeFiles/regalloc.dir/src/utils.c.o" \
"CMakeFiles/regalloc.dir/src/regalloc.c.o" \
"CMakeFiles/regalloc.dir/src/container.c.o"

# External object files for target regalloc
regalloc_EXTERNAL_OBJECTS =

regalloc: CMakeFiles/regalloc.dir/src/main.c.o
regalloc: CMakeFiles/regalloc.dir/src/utils.c.o
regalloc: CMakeFiles/regalloc.dir/src/regalloc.c.o
regalloc: CMakeFiles/regalloc.dir/src/container.c.o
regalloc: CMakeFiles/regalloc.dir/build.make
regalloc: CMakeFiles/regalloc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable regalloc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/regalloc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/regalloc.dir/build: regalloc
.PHONY : CMakeFiles/regalloc.dir/build

CMakeFiles/regalloc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/regalloc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/regalloc.dir/clean

CMakeFiles/regalloc.dir/depend:
	cd /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1 /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1 /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build /home/shawn-andrew/Documents/programming/projects/mymalloc/regalloc/ver0.1/build/CMakeFiles/regalloc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/regalloc.dir/depend

