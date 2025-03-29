//
// Created by 84648 on 2025/3/26.
//
// 符号表实现文件

#include "SymbolTable.h"
#include <iostream>
#include "json.hpp" // 引入 nlohmann/json 库
#include <fstream>
#include "SymbolTable.h"


const std::string SystemFuncLibPath = "Standard_fbfu.json";

void SymbolTable::initSystemFuncLib(const std::string &jsonPath) {
    try {
        std::ifstream file(jsonPath);
        if (!file.is_open()) {
            std::cerr << "Error: Failed to open JSON file: " << jsonPath << std::endl;
            return;
        }

        // 解析json
        nlohmann::json data;
        file >> data;

        for (const auto& func : data["Function"]) {
            std::string fuName = func["name"];
            systemFuncLib[fuName] = SymbolType::Function;
        }

        for (const auto & funcblock : data["FunctionBlock"]) {
            std::string fbName = funcblock["name"];
            systemFuncLib[fbName] = SymbolType::FunctionBlock;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception caught while initializing system function library: " << e.what() << std::endl;
    }
}

SymbolTable::SymbolTable(std::shared_ptr<SymbolTable> parent)
        : parentScope(parent) {
    enterScope();  // 初始化时自动进入第一个作用域

    initSystemFuncLib(SystemFuncLibPath); // 初始化系统fbfu库
}


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

bool SymbolTable::addSymbol(const std::string &name, SymbolType type, const std::string &dataType, bool isGlobal) {
    if (scopes.empty()) {
        std::cerr << "Error: No active scope!" << std::endl;
        return false;
    }

    auto& currentScope = scopes.back();
    if (currentScope.find(name) != currentScope.end()) {
        std::cerr << "Error: Symbol '" << name << "' already defined in this scope!" << std::endl;
        return false;
    }
    currentScope[name] = SymbolEntry(name, type, dataType, isGlobal);  // 调用构造函数
    return true;
}

SymbolEntry* SymbolTable::lookupSymbol(const std::string& name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto& scope = *it;
        // 在当前作用域查找
        if (scope.find(name) != scope.end()) {
            return &scope[name];
        }
        // 递归向上查找
        if (parentScope) {
            return parentScope->lookupSymbol(name);
        }
    }
    std::cerr << "Error: Symbol '" << name << "' not found!" << std::endl;
    return nullptr;
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