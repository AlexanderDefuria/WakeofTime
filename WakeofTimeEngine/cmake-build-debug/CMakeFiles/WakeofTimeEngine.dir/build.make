# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/alexander/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alexander/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexander/Desktop/WakeofTime/WakeofTimeEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WakeofTimeEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WakeofTimeEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WakeofTimeEngine.dir/flags.make

CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.o: CMakeFiles/WakeofTimeEngine.dir/flags.make
CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.o: ../deps/glad/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.o   -c /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/deps/glad/glad.c

CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/deps/glad/glad.c > CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.i

CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/deps/glad/glad.c -o CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.s

CMakeFiles/WakeofTimeEngine.dir/main.cpp.o: CMakeFiles/WakeofTimeEngine.dir/flags.make
CMakeFiles/WakeofTimeEngine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WakeofTimeEngine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WakeofTimeEngine.dir/main.cpp.o -c /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/main.cpp

CMakeFiles/WakeofTimeEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WakeofTimeEngine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/main.cpp > CMakeFiles/WakeofTimeEngine.dir/main.cpp.i

CMakeFiles/WakeofTimeEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WakeofTimeEngine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/main.cpp -o CMakeFiles/WakeofTimeEngine.dir/main.cpp.s

CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.o: CMakeFiles/WakeofTimeEngine.dir/flags.make
CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.o: ../renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.o -c /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/renderer.cpp

CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/renderer.cpp > CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.i

CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/renderer.cpp -o CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.s

# Object files for target WakeofTimeEngine
WakeofTimeEngine_OBJECTS = \
"CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.o" \
"CMakeFiles/WakeofTimeEngine.dir/main.cpp.o" \
"CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.o"

# External object files for target WakeofTimeEngine
WakeofTimeEngine_EXTERNAL_OBJECTS =

WakeofTimeEngine: CMakeFiles/WakeofTimeEngine.dir/deps/glad/glad.c.o
WakeofTimeEngine: CMakeFiles/WakeofTimeEngine.dir/main.cpp.o
WakeofTimeEngine: CMakeFiles/WakeofTimeEngine.dir/renderer.cpp.o
WakeofTimeEngine: CMakeFiles/WakeofTimeEngine.dir/build.make
WakeofTimeEngine: CMakeFiles/WakeofTimeEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable WakeofTimeEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WakeofTimeEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WakeofTimeEngine.dir/build: WakeofTimeEngine

.PHONY : CMakeFiles/WakeofTimeEngine.dir/build

CMakeFiles/WakeofTimeEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WakeofTimeEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WakeofTimeEngine.dir/clean

CMakeFiles/WakeofTimeEngine.dir/depend:
	cd /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexander/Desktop/WakeofTime/WakeofTimeEngine /home/alexander/Desktop/WakeofTime/WakeofTimeEngine /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/CMakeFiles/WakeofTimeEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WakeofTimeEngine.dir/depend

