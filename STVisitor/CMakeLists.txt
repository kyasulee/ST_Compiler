cmake_minimum_required(VERSION 3.28)
project(STVisitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

# 添加头文件目录
include_directories(${LLVM_INCLUDE_DIRS})

# 添加库目录
link_directories(${LLVM_LIBRARY_DIRS})

# 设置源文件
set(SRC_FILES
        STParserVisitor.h
        STParserVisitor.cpp
        SymbolTable.h
        SymbolTable.cpp
        SemanticAnalyzer.h
        SemanticAnalyzer.cpp
        AnyTypeCheck.h
        AnyTypeCheck.cpp
        IRNode.h
        IRNode.cpp
)

# 添加可执行文件或静态库
add_library(STVisitorLib STATIC ${SRC_FILES})

# 指定头文件路径（让 STVisitor 能找到 STGrammar 的 .h 文件）
target_include_directories(STVisitorLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ../STGrammar
        ../include
        /usr/include/llvm-c-17
        /usr/include/llvm-17
)

# 链接 LLVM 库
target_link_libraries(STVisitorLib PUBLIC ${LLVM_LIBRARIES} LLVMCore LLVMSupport)
# 链接 STGrammarLib（在 STGrammar 目录的 CMakeLists.txt 里定义的库）
target_link_libraries(STVisitorLib PUBLIC STGrammarLib)