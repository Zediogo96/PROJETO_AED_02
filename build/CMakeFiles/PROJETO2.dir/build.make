# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\build"

# Include any dependencies generated for this target.
include CMakeFiles/PROJETO2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PROJETO2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PROJETO2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PROJETO2.dir/flags.make

CMakeFiles/PROJETO2.dir/main.cpp.obj: CMakeFiles/PROJETO2.dir/flags.make
CMakeFiles/PROJETO2.dir/main.cpp.obj: ../main.cpp
CMakeFiles/PROJETO2.dir/main.cpp.obj: CMakeFiles/PROJETO2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PROJETO2.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PROJETO2.dir/main.cpp.obj -MF CMakeFiles\PROJETO2.dir\main.cpp.obj.d -o CMakeFiles\PROJETO2.dir\main.cpp.obj -c "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\main.cpp"

CMakeFiles/PROJETO2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PROJETO2.dir/main.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\main.cpp" > CMakeFiles\PROJETO2.dir\main.cpp.i

CMakeFiles/PROJETO2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PROJETO2.dir/main.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\main.cpp" -o CMakeFiles\PROJETO2.dir\main.cpp.s

CMakeFiles/PROJETO2.dir/Graph.cpp.obj: CMakeFiles/PROJETO2.dir/flags.make
CMakeFiles/PROJETO2.dir/Graph.cpp.obj: ../Graph.cpp
CMakeFiles/PROJETO2.dir/Graph.cpp.obj: CMakeFiles/PROJETO2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PROJETO2.dir/Graph.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PROJETO2.dir/Graph.cpp.obj -MF CMakeFiles\PROJETO2.dir\Graph.cpp.obj.d -o CMakeFiles\PROJETO2.dir\Graph.cpp.obj -c "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\Graph.cpp"

CMakeFiles/PROJETO2.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PROJETO2.dir/Graph.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\Graph.cpp" > CMakeFiles\PROJETO2.dir\Graph.cpp.i

CMakeFiles/PROJETO2.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PROJETO2.dir/Graph.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\Graph.cpp" -o CMakeFiles\PROJETO2.dir\Graph.cpp.s

# Object files for target PROJETO2
PROJETO2_OBJECTS = \
"CMakeFiles/PROJETO2.dir/main.cpp.obj" \
"CMakeFiles/PROJETO2.dir/Graph.cpp.obj"

# External object files for target PROJETO2
PROJETO2_EXTERNAL_OBJECTS =

PROJETO2.exe: CMakeFiles/PROJETO2.dir/main.cpp.obj
PROJETO2.exe: CMakeFiles/PROJETO2.dir/Graph.cpp.obj
PROJETO2.exe: CMakeFiles/PROJETO2.dir/build.make
PROJETO2.exe: CMakeFiles/PROJETO2.dir/linklibs.rsp
PROJETO2.exe: CMakeFiles/PROJETO2.dir/objects1.rsp
PROJETO2.exe: CMakeFiles/PROJETO2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PROJETO2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PROJETO2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PROJETO2.dir/build: PROJETO2.exe
.PHONY : CMakeFiles/PROJETO2.dir/build

CMakeFiles/PROJETO2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PROJETO2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PROJETO2.dir/clean

CMakeFiles/PROJETO2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02" "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02" "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\build" "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\build" "C:\Users\User\Desktop\Nova pasta\PROJETO_AED_02\build\CMakeFiles\PROJETO2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PROJETO2.dir/depend

