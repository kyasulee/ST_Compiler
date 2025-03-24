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