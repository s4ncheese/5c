# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\EDU Programs\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\EDU Programs\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug

# Include any dependencies generated for this target.
include al/algorithms/CMakeFiles/algorithms.dir/depend.make
# Include the progress variables for this target.
include al/algorithms/CMakeFiles/algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include al/algorithms/CMakeFiles/algorithms.dir/flags.make

al/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj: al/algorithms/CMakeFiles/algorithms.dir/flags.make
al/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj: ../libs/algorithms/algorithm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object al/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj"
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\algorithms.dir\algorithm.c.obj -c C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\libs\algorithms\algorithm.c

al/algorithms/CMakeFiles/algorithms.dir/algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/algorithms.dir/algorithm.c.i"
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\libs\algorithms\algorithm.c > CMakeFiles\algorithms.dir\algorithm.c.i

al/algorithms/CMakeFiles/algorithms.dir/algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/algorithms.dir/algorithm.c.s"
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\libs\algorithms\algorithm.c -o CMakeFiles\algorithms.dir\algorithm.c.s

al/algorithms/CMakeFiles/algorithms.dir/array/array.c.obj: al/algorithms/CMakeFiles/algorithms.dir/flags.make
al/algorithms/CMakeFiles/algorithms.dir/array/array.c.obj: ../libs/algorithms/array/array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object al/algorithms/CMakeFiles/algorithms.dir/array/array.c.obj"
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\algorithms.dir\array\array.c.obj -c C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\libs\algorithms\array\array.c

al/algorithms/CMakeFiles/algorithms.dir/array/array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/algorithms.dir/array/array.c.i"
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\libs\algorithms\array\array.c > CMakeFiles\algorithms.dir\array\array.c.i

al/algorithms/CMakeFiles/algorithms.dir/array/array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/algorithms.dir/array/array.c.s"
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\libs\algorithms\array\array.c -o CMakeFiles\algorithms.dir\array\array.c.s

# Object files for target algorithms
algorithms_OBJECTS = \
"CMakeFiles/algorithms.dir/algorithm.c.obj" \
"CMakeFiles/algorithms.dir/array/array.c.obj"

# External object files for target algorithms
algorithms_EXTERNAL_OBJECTS =

al/algorithms/libalgorithms.a: al/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj
al/algorithms/libalgorithms.a: al/algorithms/CMakeFiles/algorithms.dir/array/array.c.obj
al/algorithms/libalgorithms.a: al/algorithms/CMakeFiles/algorithms.dir/build.make
al/algorithms/libalgorithms.a: al/algorithms/CMakeFiles/algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libalgorithms.a"
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && $(CMAKE_COMMAND) -P CMakeFiles\algorithms.dir\cmake_clean_target.cmake
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
al/algorithms/CMakeFiles/algorithms.dir/build: al/algorithms/libalgorithms.a
.PHONY : al/algorithms/CMakeFiles/algorithms.dir/build

al/algorithms/CMakeFiles/algorithms.dir/clean:
	cd /d C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms && $(CMAKE_COMMAND) -P CMakeFiles\algorithms.dir\cmake_clean.cmake
.PHONY : al/algorithms/CMakeFiles/algorithms.dir/clean

al/algorithms/CMakeFiles/algorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\libs\algorithms C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms C:\Projects\CLionProjects\5aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\cmake-build-debug\al\algorithms\CMakeFiles\algorithms.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : al/algorithms/CMakeFiles/algorithms.dir/depend

