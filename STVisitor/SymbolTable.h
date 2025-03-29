//
// Created by 84648 on 2025/3/26.
//
// 符号表头文件
#ifndef ST_BUILDER_SYMBOLTABLE_H
#define ST_BUILDER_SYMBOLTABLE_H

#include <unordered_map>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include "llvm-17/llvm/IR/Value.h"

enum class SymbolType {
    Variable,
    Program,
    FunctionBlock,
    Function
};

struct SymbolEntry {
    std::string name;
    SymbolType type;
    std::string dataType;
    bool isGlobal;

    std::vector<std::string> members; // 成员变量或方法, 用于FB

    // 默认构造函数
    SymbolEntry() : name(""), type(SymbolType::Variable), dataType(""), isGlobal(false) {}
    // 构造函数
    SymbolEntry(const std::string& name, SymbolType type, const std::string& dataType, bool isGlobal = false)
            : name(name), type(type), dataType(dataType), isGlobal(isGlobal) {}

    // 添加成员变量或方法
    void addMember(const std::string& memberName) {
        if (type != SymbolType::FunctionBlock) {
            std::cerr << "Error: Only FunctionBlocks can have members!" << std::endl;
            return;
        }
        members.push_back(memberName);
    }

    void printMember() const {
        if (!members.empty()) {
            std::cout << "  Members: " ;
            for (const auto& member : members) {
                std::cout << member << " ";
            }
            std::cout << std::endl;
        }
    }
};

class SymbolTable {
private:
    std::vector<std::unordered_map<std::string, SymbolEntry>> scopes; // 当前作用域

public:
    std::shared_ptr<SymbolTable> parentScope; // 父作用域指针
    std::unordered_map<std::string, SymbolType> systemFuncLib;

    SymbolTable(std::shared_ptr<SymbolTable> parent = nullptr);

    void enterScope();  // 进入新作用域
    void exitScope();   // 退出当前作用域
    bool addSymbol(const std::string& name, SymbolType type, const std::string& dataType, bool isGlobal = false);
    SymbolEntry* lookupSymbol(const std::string& name);
    void print() const;

    void initSystemFuncLib(const std::string& jsonPath);
};

#endif //ST_BUILDER_SYMBOLTABLE_H
