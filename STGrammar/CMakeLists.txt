cmake_minimum_required(VERSION 3.28)
project(STGrammar)

set(CMAKE_CXX_STANDARD 17)

# 指定 ANTLR 生成的源文件
set(GENERATED_SRC
        STLexer.cpp
        STParser.cpp
        STBaseVisitor.cpp
        STVisitor.cpp
        STBaseListener.cpp
        STListener.cpp
)

set(GENERATED_HEADERS
        STLexer.h
        STParser.h
        STBaseVisitor.h
        STVisitor.h
        STBaseListener.h
        STListener.h
)

# 创建静态库 STGrammarLib
add_library(STGrammarLib STATIC ${GENERATED_SRC})

# 让外部模块能够找到 STGrammar 头文件
target_include_directories(STGrammarLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 链接 ANTLR4 运行时 (你需要手动安装 antlr4-runtime)
target_link_libraries(STGrammarLib PUBLIC antlr4-runtime)
