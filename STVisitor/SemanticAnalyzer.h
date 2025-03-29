//
// Created by 84648 on 2025/3/29.
//

#ifndef ST_BUILDER_SEMANTICANALYZER_H
#define ST_BUILDER_SEMANTICANALYZER_H

#include "SymbolTable.h"
#include <iostream>
#include <memory>
#include <unordered_map>

class SemanticAnalyzer {
private:
    std::shared_ptr<SymbolTable> currentScope;  // 当前作用域
    std::unordered_map<std::string, std::string> implicitConversions; // 允许的隐式转换

public:
    SemanticAnalyzer();

    void enterScope();  // 进入新作用域
    void exitScope();   // 退出当前作用域

    bool declareVariable(const std::string& name, const std::string& datatype); // 变量声明
    bool checkVariableUsage(const std::string &name);       // 变量使用
    bool declareFunction(const std::string& name, const std::string &returnType); // fu声明检查
    bool checkFunctionCall(const std::string& name); // fu调用检查
    bool declareFunctionBlock(const std::string& name);  // fb声明
    bool checkFunctionBlockInstance(const std::string& instanceName, const std::string &fbType); // fb实例化检查
    bool checkFunctionBlockMethodCall(const std::string& instanceName /*const std::string &methodName*/ ); // fb调用检查

    bool checkAssignment(const std::string& lhs, const std::string &rhsType); // 赋值语句检查
};

#endif //ST_BUILDER_SEMANTICANALYZER_H
