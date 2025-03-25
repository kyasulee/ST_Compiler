// STParserVisitor.cpp

#include "STParserVisitor.h"
#include "STParser.h"

#include <iostream>

// 声明一个变量并记录类型
void SymbolTable::declareVariable(const std::string &name, const std::string &type) {
    symbolTables[name] = type;
    std::cout << "Declared Variable: " << name << " (" << type << ")" << std::endl;
}

// 检查变量是否已经声明
bool SymbolTable::isDeclared(const std::string &name) const {
    return symbolTables.find(name) != symbolTables.end();
}

// 获取变量类型，未定义时返回“”
std::string SymbolTable::getType(const std::string &name) const {
    if(isDeclared(name)) {
        return symbolTables.at(name);
    }
    return "";
}

// 构造函数
newSTVisitor::newSTVisitor() : symbolTable() {}

antlrcpp::Any newSTVisitor::visitStartpoint(STParser::StartpointContext *ctx) {
    std::cout << "Visiting Startpoint:" <<  std::endl;

    // 递归访问program_list
    for (auto program: ctx->program_list()) {
        visit(program);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitProgram_list(STParser::Program_listContext *ctx) {
    std::cout << "Visiting Program_list:" << std::endl;

    if(ctx->programDecl()){
        std::cout << "Visiting programDecl:" << std::endl;
        visit(ctx->programDecl());
    } else if (ctx->functionDecl()) {
        std::cout << "Visiting functionDecl:" << std::endl;
        visit(ctx->functionDecl());
    } else if (ctx->functionBlockDecl()) {
        std::cout << "Visiting functionBlockDecl:" << std::endl;
        visit(ctx->functionBlockDecl());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitProgramDecl(STParser::ProgramDeclContext *ctx) {
    // 程序名
    std::string progName = ctx->IDENT()->getText();
    std::cout << "Visiting Program Decl:" << progName << std::endl;

    // 变量声明
    if(ctx->declarationStmt()) {
        visit(ctx->declarationStmt());
    }

    for(auto stmt: ctx->statement_list()) {
        visit(stmt);
    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitStatement_list(STParser::Statement_listContext *ctx) {
    std::cout << "Visiting Statement_list:" << std::endl;

    if (ctx->assignStmt()) {
        std::cout << "now is assignStmt" << std::endl;
        visit(ctx->assignStmt());
    } else if (ctx->selectStmt()) {
        std::cout << "now is selectStmt" << std::endl;
        visit(ctx->selectStmt());
    } else if (ctx->iterationStmt()) {
        std::cout << "now is iterationStmt" << std::endl;
        visit(ctx->iterationStmt());
    } else if (ctx->callFuncStmt()) {
        std::cout << "now is callFuncStmt" << std::endl;
        visit(ctx->callFuncStmt());
    } else if (ctx->jumpStmt()) {
        std::cout << "now is jumpStmt" << std::endl;
        visit(ctx->jumpStmt());
    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitSelectStmt(STParser::SelectStmtContext *ctx) {
    std::cout << "Visiting SelectStmt:" << std::endl;

    if(ctx->ifStmt()) {
        std::cout << "now found if statement" << std::endl;
        visit(ctx->ifStmt());
    } else if (ctx->caseStmt()) {
        std::cout << "now found case statement" << std::endl;
        visit(ctx->caseStmt());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitIterationStmt(STParser::IterationStmtContext *ctx) {
    std::cout << "Visiting IterationStmt:" << std::endl;

    if (ctx->whileStmt()) {
        std::cout << "now found while statement" << std::endl;
        visit(ctx->whileStmt());
    } else if (ctx->forStmt()) {
        std::cout << "now found for statement" << std::endl;
        visit(ctx->forStmt());
    } else if (ctx->repeatStmt()) {
        std::cout << "now found repeat statement" << std::endl;
        visit(ctx->repeatStmt());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitCallFuncStmt(STParser::CallFuncStmtContext *ctx) {
    std::cout << "Visiting CallFuncStmt:" << std::endl;

    std::string funcName;
    if (ctx->IDENT()) {
        funcName = ctx->IDENT()->getText();
    } else {
        funcName = ctx->getText(); // 'AND' | 'OR' | 'XOR' | 'MOD' | 'NOT'
    }
    std::cout << "function name is:" << funcName << std::endl;

    if (ctx->funcParams()) {
        std::cout << "now visiting funcParams" << std::endl;
        visit(ctx->funcParams());
    } else {
        std::cout << "there is no parameters provided" << std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitJumpStmt(STParser::JumpStmtContext *ctx) {
    std::cout << "Visiting JumpStmt:" << std::endl;

    if (ctx->getText() == "BREAK") {
        std::cout << "Found BREAK Statement" << std::endl;
    } else if (ctx->getText() == "RETURN") {
        std::cout << "Found RETURN Statement" << std::endl;
    } else if (ctx->getText() == "CONTINUE") {
        std::cout << "Found CONTINUE Statement" << std::endl;
    } else if (ctx->getText() == "EXIT") {
        std::cout << "Found EXIT Statement" << std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitAssignStmt(STParser::AssignStmtContext *ctx) {
    std::cout << "Visiting AssignStmt:" << std::endl;

    std::string leftValue;
    if (ctx->prefixExpr()) {
        leftValue = ctx->prefixExpr()->getText();
        std::cout << "Left Value of AssignStmt is:" << leftValue << std::endl;
    }

    if (ctx->expr()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->expr()->getText() << std::endl;
        visit(ctx->expr());
    } else if (ctx->callFuncStmt()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->callFuncStmt()->getText() << std::endl;
        visit(ctx->callFuncStmt());
    }

    return nullptr;
}