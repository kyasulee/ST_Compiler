cmake_minimum_required(VERSION 3.28)
project(STVisitor)

set(CMAKE_CXX_STANDARD 17)

# 设置源文件
set(SRC_FILES
        STParserVisitor.cpp
        STParserVisitor.h
)

# 添加可执行文件或静态库
add_library(STVisitorLib STATIC ${SRC_FILES})

# 指定头文件路径（让 STVisitor 能找到 STGrammar 的 .h 文件）
target_include_directories(STVisitorLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ../STGrammar
)

# 链接 STGrammarLib（在 STGrammar 目录的 CMakeLists.txt 里定义的库）
target_link_libraries(STVisitorLib PUBLIC STGrammarLib)
