//
// Created by 84648 on 2025/3/26.
//
// 符号表头文件
#ifndef ST_BUILDER_SYMBOLTABLE_H
#define ST_BUILDER_SYMBOLTABLE_H

#include <unordered_map>
#include <stack>
#include <string>
#include "llvm-17/llvm/IR/Value.h"

enum class SymbolType {
    Variable,
    Program,
    FunctionBlock,
    Function,
    Input,
    Output,
    InOut
};

struct SymbolEntry {
    std::string name;
    SymbolType type;
    std::string dataType;
    bool isGlobal;
    llvm::Value* llvmValue; // LLVM值
};

#endif //ST_BUILDER_SYMBOLTABLE_H
