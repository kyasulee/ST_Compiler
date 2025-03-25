cmake_minimum_required(VERSION 3.28)
project(st_builder)

set(CMAKE_CXX_STANDARD 17)

# 指定 ANTLR 头文件和库路径
set(ANTLR_INCLUDE_DIR /usr/local/include/antlr4-runtime)
set(ANTLR_LIB_DIR /usr/local/lib)

# 子目录
add_subdirectory(STGrammar)
add_subdirectory(STVisitor)

# 生成可执行文件
add_executable(st_builder main.cpp)

# 包含头文件
target_include_directories(st_builder PRIVATE ${ANTLR_INCLUDE_DIR})

# 链接库文件
target_link_directories(st_builder PRIVATE ${ANTLR_LIB_DIR})
target_link_libraries(st_builder PRIVATE antlr4-runtime)
target_link_libraries(st_builder PRIVATE STVisitorLib)
target_link_libraries(st_builder PRIVATE STGrammarLib)