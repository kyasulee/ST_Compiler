//
// Created by 84648 on 2025/3/26.
//
// 符号表实现文件

#include "SymbolTable.h"
#include <iostream>
#include "json.hpp" // 引入 nlohmann/json 库
#include <fstream>
#include "SymbolTable.h"

void SymbolTable::initSystemFuncLib(const std::string &jsonPath) {
    if (!parentScope) {
        std::ifstream file(jsonPath);
        if (!file.is_open()) {
            std::cerr << "Error: Failed to open JSON file: " << jsonPath << std::endl;
            return;
        }

        // 解析json
        try {
            nlohmann::json data = nlohmann::json::parse(file);
            for (const auto& func : data["Function"]) {
                std::string fuName = func["name"].get<std::string>();
                std::string returnType = func["return_type"].get<std::string>();
                std::transform(fuName.begin(), fuName.end(), fuName.begin(), ::toupper);

                scopes[fuName] = SymbolEntry{fuName, SymbolType::Function, returnType, true};
            }

            for (const auto& func : data["FunctionBlock"]) {
                std::string fbName = func["name"].get<std::string>();
                std::transform(fbName.begin(), fbName.end(), fbName.begin(), ::toupper);

                scopes[fbName] = SymbolEntry{fbName, SymbolType::FunctionBlock, "", true};
            }
        } catch (const std::exception& e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }
    } else {
        auto globalScope = this;
        while (globalScope->parentScope) {
            globalScope = globalScope->parentScope.get();
        }
        globalScope->initSystemFuncLib(jsonPath);
    }
}


bool SymbolTable::addSymbol(const std::string &name, SymbolType type, const std::string &dataType, bool isGlobal) {
    if (scopes.find(name) != scopes.end()) {
        std::cerr << "Error: Symbol '" << name << "' already defined in this scope!" << std::endl;
        return false;
    }
    scopes[name] = SymbolEntry(name, type, dataType, isGlobal);  // 调用构造函数
    return true;
}

SymbolEntry* SymbolTable::lookupSymbol(const std::string& name) {
    // 遍历当前符号表的所有作用域（从最近的作用域开始）
    if (scopes.find(name) != scopes.end()) {
        std::cout << "Found symbol '" << name << "' in current scope." << std::endl;
        std::cout << scopes[name].name << "===" <<  scopes[name].dataType << std::endl;
        return &scopes[name]; // 找到符号，返回指针
    }

    // 如果当前符号表中找不到，尝试在父作用域中查找
    if (parentScope) {
        std::cout << "Recursing to parent scope..." << std::endl;
        return parentScope->lookupSymbol(name);
    }

//    std::cerr << "Error: Symbol '" << name << "' not found!" << std::endl;
    return nullptr;
}

void SymbolTable::print() const {
    std::cout << "Symbol Table:" << std::endl;
    std::cout << scopes.size() << std::endl;
    for (const auto& scope : scopes) {
        std::string name = scope.first;
        auto entry = scope.second;

        std::cout << "  " << name << " ("
                  << (entry.type == SymbolType::Variable ? "Variable" :
                      entry.type == SymbolType::Function ? "Function" :
                      entry.type == SymbolType::FunctionBlock ? "FunctionBlock" : "Program")
                  << ", " << entry.dataType << ", "
                  << (entry.isGlobal ? "Global" : "Local") << ")" << std::endl;
        entry.printMember();

    }
}