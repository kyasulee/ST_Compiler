# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /root/codes/llvm/st_builder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/codes/llvm/st_builder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/st_builder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/st_builder.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/st_builder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/st_builder.dir/flags.make

CMakeFiles/st_builder.dir/main.cpp.o: CMakeFiles/st_builder.dir/flags.make
CMakeFiles/st_builder.dir/main.cpp.o: /root/codes/llvm/st_builder/main.cpp
CMakeFiles/st_builder.dir/main.cpp.o: CMakeFiles/st_builder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/codes/llvm/st_builder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/st_builder.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/st_builder.dir/main.cpp.o -MF CMakeFiles/st_builder.dir/main.cpp.o.d -o CMakeFiles/st_builder.dir/main.cpp.o -c /root/codes/llvm/st_builder/main.cpp

CMakeFiles/st_builder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/st_builder.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/codes/llvm/st_builder/main.cpp > CMakeFiles/st_builder.dir/main.cpp.i

CMakeFiles/st_builder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/st_builder.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/codes/llvm/st_builder/main.cpp -o CMakeFiles/st_builder.dir/main.cpp.s

# Object files for target st_builder
st_builder_OBJECTS = \
"CMakeFiles/st_builder.dir/main.cpp.o"

# External object files for target st_builder
st_builder_EXTERNAL_OBJECTS =

st_builder: CMakeFiles/st_builder.dir/main.cpp.o
st_builder: CMakeFiles/st_builder.dir/build.make
st_builder: STVisitor/libSTVisitorLib.a
st_builder: STGrammar/libSTGrammarLib.a
st_builder: /home/wjq/workspace/llvm/lib/libLLVMCore.a
st_builder: /home/wjq/workspace/llvm/lib/libLLVMBinaryFormat.a
st_builder: /home/wjq/workspace/llvm/lib/libLLVMRemarks.a
st_builder: /home/wjq/workspace/llvm/lib/libLLVMBitstreamReader.a
st_builder: /home/wjq/workspace/llvm/lib/libLLVMTargetParser.a
st_builder: /home/wjq/workspace/llvm/lib/libLLVMSupport.a
st_builder: /home/wjq/workspace/llvm/lib/libLLVMDemangle.a
st_builder: /usr/lib/x86_64-linux-gnu/libz.so
st_builder: /usr/lib/x86_64-linux-gnu/libzstd.so
st_builder: CMakeFiles/st_builder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/codes/llvm/st_builder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable st_builder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/st_builder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/st_builder.dir/build: st_builder
.PHONY : CMakeFiles/st_builder.dir/build

CMakeFiles/st_builder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/st_builder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/st_builder.dir/clean

CMakeFiles/st_builder.dir/depend:
	cd /root/codes/llvm/st_builder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/codes/llvm/st_builder /root/codes/llvm/st_builder /root/codes/llvm/st_builder/cmake-build-debug /root/codes/llvm/st_builder/cmake-build-debug /root/codes/llvm/st_builder/cmake-build-debug/CMakeFiles/st_builder.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/st_builder.dir/depend

