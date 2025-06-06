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
CMAKE_BINARY_DIR = /root/codes/llvm/st_builder/build

# Include any dependencies generated for this target.
include STVisitor/CMakeFiles/STVisitorLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include STVisitor/CMakeFiles/STVisitorLib.dir/compiler_depend.make

# Include the progress variables for this target.
include STVisitor/CMakeFiles/STVisitorLib.dir/progress.make

# Include the compile flags for this target's objects.
include STVisitor/CMakeFiles/STVisitorLib.dir/flags.make

STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/flags.make
STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o: /root/codes/llvm/st_builder/STVisitor/STParserVisitor.cpp
STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/codes/llvm/st_builder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o -MF CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o.d -o CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o -c /root/codes/llvm/st_builder/STVisitor/STParserVisitor.cpp

STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.i"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/codes/llvm/st_builder/STVisitor/STParserVisitor.cpp > CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.i

STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.s"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/codes/llvm/st_builder/STVisitor/STParserVisitor.cpp -o CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.s

STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/flags.make
STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o: /root/codes/llvm/st_builder/STVisitor/SymbolTable.cpp
STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/codes/llvm/st_builder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o -MF CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o.d -o CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o -c /root/codes/llvm/st_builder/STVisitor/SymbolTable.cpp

STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.i"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/codes/llvm/st_builder/STVisitor/SymbolTable.cpp > CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.i

STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.s"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/codes/llvm/st_builder/STVisitor/SymbolTable.cpp -o CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.s

STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/flags.make
STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o: /root/codes/llvm/st_builder/STVisitor/SemanticAnalyzer.cpp
STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/codes/llvm/st_builder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o -MF CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o.d -o CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o -c /root/codes/llvm/st_builder/STVisitor/SemanticAnalyzer.cpp

STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.i"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/codes/llvm/st_builder/STVisitor/SemanticAnalyzer.cpp > CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.i

STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.s"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/codes/llvm/st_builder/STVisitor/SemanticAnalyzer.cpp -o CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.s

STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/flags.make
STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o: /root/codes/llvm/st_builder/STVisitor/AnyTypeCheck.cpp
STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/codes/llvm/st_builder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o -MF CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o.d -o CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o -c /root/codes/llvm/st_builder/STVisitor/AnyTypeCheck.cpp

STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.i"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/codes/llvm/st_builder/STVisitor/AnyTypeCheck.cpp > CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.i

STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.s"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/codes/llvm/st_builder/STVisitor/AnyTypeCheck.cpp -o CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.s

STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/flags.make
STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.o: /root/codes/llvm/st_builder/STVisitor/IRNode.cpp
STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.o: STVisitor/CMakeFiles/STVisitorLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/codes/llvm/st_builder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.o"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.o -MF CMakeFiles/STVisitorLib.dir/IRNode.cpp.o.d -o CMakeFiles/STVisitorLib.dir/IRNode.cpp.o -c /root/codes/llvm/st_builder/STVisitor/IRNode.cpp

STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/STVisitorLib.dir/IRNode.cpp.i"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/codes/llvm/st_builder/STVisitor/IRNode.cpp > CMakeFiles/STVisitorLib.dir/IRNode.cpp.i

STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/STVisitorLib.dir/IRNode.cpp.s"
	cd /root/codes/llvm/st_builder/build/STVisitor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/codes/llvm/st_builder/STVisitor/IRNode.cpp -o CMakeFiles/STVisitorLib.dir/IRNode.cpp.s

# Object files for target STVisitorLib
STVisitorLib_OBJECTS = \
"CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o" \
"CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o" \
"CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o" \
"CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o" \
"CMakeFiles/STVisitorLib.dir/IRNode.cpp.o"

# External object files for target STVisitorLib
STVisitorLib_EXTERNAL_OBJECTS =

STVisitor/libSTVisitorLib.a: STVisitor/CMakeFiles/STVisitorLib.dir/STParserVisitor.cpp.o
STVisitor/libSTVisitorLib.a: STVisitor/CMakeFiles/STVisitorLib.dir/SymbolTable.cpp.o
STVisitor/libSTVisitorLib.a: STVisitor/CMakeFiles/STVisitorLib.dir/SemanticAnalyzer.cpp.o
STVisitor/libSTVisitorLib.a: STVisitor/CMakeFiles/STVisitorLib.dir/AnyTypeCheck.cpp.o
STVisitor/libSTVisitorLib.a: STVisitor/CMakeFiles/STVisitorLib.dir/IRNode.cpp.o
STVisitor/libSTVisitorLib.a: STVisitor/CMakeFiles/STVisitorLib.dir/build.make
STVisitor/libSTVisitorLib.a: STVisitor/CMakeFiles/STVisitorLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/codes/llvm/st_builder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libSTVisitorLib.a"
	cd /root/codes/llvm/st_builder/build/STVisitor && $(CMAKE_COMMAND) -P CMakeFiles/STVisitorLib.dir/cmake_clean_target.cmake
	cd /root/codes/llvm/st_builder/build/STVisitor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/STVisitorLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
STVisitor/CMakeFiles/STVisitorLib.dir/build: STVisitor/libSTVisitorLib.a
.PHONY : STVisitor/CMakeFiles/STVisitorLib.dir/build

STVisitor/CMakeFiles/STVisitorLib.dir/clean:
	cd /root/codes/llvm/st_builder/build/STVisitor && $(CMAKE_COMMAND) -P CMakeFiles/STVisitorLib.dir/cmake_clean.cmake
.PHONY : STVisitor/CMakeFiles/STVisitorLib.dir/clean

STVisitor/CMakeFiles/STVisitorLib.dir/depend:
	cd /root/codes/llvm/st_builder/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/codes/llvm/st_builder /root/codes/llvm/st_builder/STVisitor /root/codes/llvm/st_builder/build /root/codes/llvm/st_builder/build/STVisitor /root/codes/llvm/st_builder/build/STVisitor/CMakeFiles/STVisitorLib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : STVisitor/CMakeFiles/STVisitorLib.dir/depend

