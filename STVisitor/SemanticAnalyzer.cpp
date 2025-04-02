//
// Created by 84648 on 2025/3/29.
//
#include "SemanticAnalyzer.h"
#include "AnyTypeCheck.h"

// 进入新作用域
void SemanticAnalyzer::enterScope() {
    currentScope = std::make_shared<SymbolTable>(currentScope);
}

// 退出作用域
void SemanticAnalyzer::exitScope() {
    if (currentScope) {
        currentScope = currentScope->getParentScope();
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

// program声明检查
bool SemanticAnalyzer::declareProgram(const std::string& name) {
    if (!currentScope->addSymbol(name, SymbolType::Program, "")) {
        std::cerr << "Error: Program '" << name << "' is already declared in this scope." << std::endl;
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

bool SemanticAnalyzer::checkFunctionReturnType(const std::string &name, const std::string dataType) {
    SymbolEntry* fuSymbol = currentScope->lookupSymbol(name);
    if (fuSymbol) {
        std::string returnType = fuSymbol->dataType;
        DataType actualType = StringToDataType(dataType);
        if (returnType == "ANY_INT") {
            if (!ANY_INT::isPartOf(actualType)) {
                return false;
            }
        } else if (returnType == "ANY_NUM") {
            if (!ANY_NUM::isPartOf(actualType)) {
                return false;
            }
        } else if (returnType == "ANY_REAL") {
            if (!ANY_REAL::isPartOf(actualType)) {
                return false;
            }
        } else {
            if (returnType != dataType) {
                return false;
            }
        }
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

SymbolEntry* SemanticAnalyzer::getsymbolEntryInScope(const std::string &name) const {
    SymbolEntry* entry = currentScope->lookupSymbol(name);
    if (entry != nullptr) {
        return entry;
    }
    return nullptr;
}


bool SemanticAnalyzer::print() const {
    std::cout << "Symbol Table:" << std::endl;
    currentScope->print();
}

// 辅助函数1：将DataType枚举类型变成std::string
std::string DataTypeToString(DataType type) {
    switch (type) {
        case DataType::SINT: return "SINT";
        case DataType::INT: return "INT";
        case DataType::DINT: return "DINT";
        case DataType::LINT: return "LINT";
        case DataType::USINT: return "USINT";
        case DataType::UINT: return "UINT";
        case DataType::UDINT: return "UDINT";
        case DataType::ULINT: return "ULINT";
        case DataType::REAL: return "REAL";
        case DataType::LREAL: return "LREAL";
        case DataType::BOOL: return "BOOL";
        case DataType::STRING: return "STRING";
        case DataType::WSTRING: return "WSTRING";
        case DataType::TIME: return "TIME";
        case DataType::DATE: return "DATE";
        default: throw std::runtime_error("Error: Unknown DataType.");
    }
}

// 辅助函数2：将std::string变成DataType枚举类型
DataType StringToDataType(const std::string& typeStr) {
    if (typeStr == "SINT") return DataType::SINT;
    if (typeStr == "INT") return DataType::INT;
    if (typeStr == "DINT") return DataType::DINT;
    if (typeStr == "LINT") return DataType::LINT;
    if (typeStr == "USINT") return DataType::USINT;
    if (typeStr == "UINT") return DataType::UINT;
    if (typeStr == "UDINT") return DataType::UDINT;
    if (typeStr == "ULINT") return DataType::ULINT;
    if (typeStr == "REAL") return DataType::REAL;
    if (typeStr == "LREAL") return DataType::LREAL;
    if (typeStr == "BOOL") return DataType::BOOL;
    if (typeStr == "STRING") return DataType::STRING;
    if (typeStr == "WSTRING") return DataType::WSTRING;
    if (typeStr == "TIME") return DataType::TIME;
    if (typeStr == "DATE") return DataType::DATE;

    throw std::runtime_error("Error: Unknown type: " + typeStr);
}