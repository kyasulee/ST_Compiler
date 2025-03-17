# 基于LLVM的IEC61131-3 ST语言编译器

缓慢实现中...

## How to？
1. 使用antlr4进行词法和语法分析并生成抽象语法树AST
2. 遍历AST，进行语义分析
3. 使用LLVM API访问AST，生成LLVM IR
4. 优化
5. 目标代码生成
