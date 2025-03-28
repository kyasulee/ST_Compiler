//
// Created by 84648 on 2025/3/26.
//
// 符号表实现文件

#include "SymbolTable.h"
#include <iostream>
#include "SymbolTable.h"

void SymbolTable::enterScope() {
    scopes.emplace_back(); // 在vector中添加一个新的作用域
}

void SymbolTable::exitScope() {
    if(scopes.empty()) {
        std::cerr << "Error: No scope to exit!" << std::endl;
        return;
    }
    scopes.pop_back(); // 删除最后一个作用域
}

void SymbolTable::addSymbol(const std::string& name, SymbolType type, const std::string& dataType, bool isGlobal) {
    if (scopes.empty()) {
        std::cerr << "Error: No active scope!" << std::endl;
        return;
    }

    auto& currentScope = scopes.back();
    if (currentScope.find(name) != currentScope.end()) {
        std::cerr << "Error: Symbol '" << name << "' already defined in this scope!" << std::endl;
        return;
    }
    currentScope[name] = SymbolEntry(name, type, dataType, isGlobal);  // 调用构造函数
}

SymbolEntry* SymbolTable::lookupSymbol(const std::string& name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto& scope = *it;
        if (scope.find(name) != scope.end()) {
            return &scope[name];
        }
    }
    std::cerr << "Error: Symbol '" << name << "' not found!" << std::endl;
    return nullptr;
}

void SymbolTable::addFunctionBlockMember(const std::string &fbName, const std::string &memberName) {
    SymbolEntry* fbEntry = lookupSymbol(fbName);
    if (!fbEntry || fbEntry->type != SymbolType::FunctionBlock) {
        std::cerr << "Error: '" << fbName << "' is not a valid FunctionBlock!" << std::endl;
        return;
    }
    fbEntry->addMember(memberName);
}

void SymbolTable::print() const {
    std::cout << "Symbol Table:" << std::endl;
    for (const auto& scope : scopes) {
        for (const auto& [name, entry] : scope) {
            std::cout << "  " << name << " ("
                      << (entry.type == SymbolType::Variable ? "Variable" :
                          entry.type == SymbolType::Function ? "Function" :
                          entry.type == SymbolType::FunctionBlock ? "FunctionBlock" : "Program")
                      << ", " << entry.dataType << ", "
                      << (entry.isGlobal ? "Global" : "Local") << ")" << std::endl;
            entry.printMember();
        }
    }
}