//
// Created by 84648 on 2025/3/29.
//
#include "SemanticAnalyzer.h"

SemanticAnalyzer::SemanticAnalyzer() {
    currentScope = std::make_shared<SymbolTable>();
}

// 进入新作用域
void SemanticAnalyzer::enterScope() {
    currentScope = std::make_shared<SymbolTable>(currentScope);
}

// 退出作用域
void SemanticAnalyzer::exitScope() {
    if(currentScope->parentScope) {
        currentScope = currentScope->parentScope;
    } else {
        std::cerr << "Error: No scope to exit!" << std::endl;
    }
}

// 变量声明检查
bool SemanticAnalyzer::declareVariable(const std::string &name, const std::string &datatype) {
    if(!currentScope->addSymbol(name, SymbolType::Variable, datatype)) {
        std::cerr << "Error: Variable '" << name << "' is already declared in this scope." << std::endl;
        return false;
    }
    return true;
}

// 变量使用检查
bool SemanticAnalyzer::checkVariableUsage(const std::string &name) {
    if(!currentScope->lookupSymbol(name)) {
        std::cerr << "Error: Variable '" << name << "' is not declared." << std::endl;
        return false;
    }
    return true;
}

// fu声明检查
bool SemanticAnalyzer::declareFunction(const std::string &name, const std::string &returnType) {
    if (!currentScope->addSymbol(name, SymbolType::Function, returnType)) {
        std::cerr << "Error: Function '" << name << "' is already declared." << std::endl;
        return false;
    }
    return true;
}

// fu调用检查
bool SemanticAnalyzer::checkFunctionCall(const std::string &name) {
    auto fuSymbol = currentScope->lookupSymbol(name);
    if (!fuSymbol || fuSymbol->type != SymbolType::Function) {
        std::cerr << "Error: Function '" << name << "' is not declared." << std::endl;
        return false;
    }
    return true;
}

// fb声明检查
bool SemanticAnalyzer::declareFunctionBlock(const std::string &name) {
    if (!currentScope->addSymbol(name, SymbolType::FunctionBlock, name)) {
        std::cerr << "Error: Function Block '" << name << "' is already declared." << std::endl;
        return false;
    }
    return true;
}

// fb实例化检查
bool SemanticAnalyzer::checkFunctionBlockInstance(const std::string &instanceName, const std::string &fbType) {
    auto fbSymbol = currentScope->lookupSymbol(fbType);
    if (!fbSymbol || fbSymbol->type != SymbolType::FunctionBlock) {
        std::cerr << "Error: Function Block type '" << fbType << "' is not declared." << std::endl;
        return false;
    }

    if (!currentScope->addSymbol(instanceName, SymbolType::Variable, fbType)) {
        std::cerr << "Error: Instance '" << instanceName << "' is already declared." << std::endl;
        return false;
    }
    return true;
}

// fb调用检查
bool SemanticAnalyzer::checkFunctionBlockMethodCall(const std::string &instanceName /*const std::string &methodName*/) {
    auto instanceSymbol = currentScope->lookupSymbol(instanceName);
    if (!instanceSymbol || instanceSymbol->type != SymbolType::Variable) {
        std::cerr << "Error: Instance '" << instanceName << "' is not declared." << std::endl;
        return false;
    }

    std::string fbType = instanceSymbol->dataType;
    auto fbSymbol = currentScope->lookupSymbol(fbType);
    if (!fbSymbol || fbSymbol->type != SymbolType::FunctionBlock) {
        std::cerr << "Error: '" << instanceName << "' is not a Function Block instance." << std::endl;
        return false;
    }

//    std::string callFBMethod = fbType + "." + methodName;
//    if (!currentScope->lookupSymbol(callFBMethod)) {
//        std::cerr << "Error: Function Block " << fbType << " has no method named " << methodName << "." << std::endl;
//        return false;
//    }
    return true;
}

// 赋值语句检查
bool SemanticAnalyzer::checkAssignment(const std::string &lhs, const std::string &rhsType) {
    auto lhsSymbol = currentScope->lookupSymbol(lhs);
    if (!lhsSymbol) {
        std::cerr << "Error: Variable '" << lhs << "' is not declared." << std::endl;
        return false;
    }

    std::string lhsType = lhsSymbol->dataType;
    if (lhsType != rhsType) {
        std::cerr << "Error: Type mismatch in assignment: cannot assign "<< rhsType << " to " << lhsType << "." << std::endl;
        return false;
    }
    return true;
}