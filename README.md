# Antlr4 and LLVM based IEC61131-3 ST compiler

Slowly implementing...

## How to？
1. Use ANTLR4 for lexical and syntactic analysis and generate an Abstract Syntax Tree (AST).
2. Traverse the AST and perform semantic analysis.
3. Accessing the AST using the LLVM API to generate LLVM IR.
4. Optimization LLVM IR.
5. Target code generation.
