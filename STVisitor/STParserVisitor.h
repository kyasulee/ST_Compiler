// STParserVisitor.h
#ifndef ST_PARSER_VISITOR_H
#define ST_PARSER_VISITOR_H

#include "STBaseVisitor.h"
#include "STParser.h"

#include <string>
#include <unordered_map>

// 符号表类：保存变量声明和类型
class SymbolTable {
public:
    void declareVariable(const std::string& name, const std::string& type); // 声明一个变量并记录其类型
    bool isDeclared(const std::string&name) const; // 检查变量是否已被声明过
    std::string getType(const std::string& name) const; // 获取变量类型

private:
    std::unordered_map<std::string, std::string> symbolTables; // 变量名-类型的map
};

class newSTVisitor : public STBaseVisitor {
public:
    explicit newSTVisitor(); // 构造函数

    antlrcpp::Any visitStartpoint(STParser::StartpointContext *ctx) override;

    antlrcpp::Any visitProgram_list(STParser::Program_listContext *ctx) override;

    antlrcpp::Any visitProgramDecl(STParser::ProgramDeclContext *ctx) override;

    antlrcpp::Any visitStatement_list(STParser::Statement_listContext *ctx) override;

    antlrcpp::Any visitSelectStmt(STParser::SelectStmtContext *ctx) override;

    antlrcpp::Any visitIterationStmt(STParser::IterationStmtContext *ctx) override;

    antlrcpp::Any visitCallFuncStmt(STParser::CallFuncStmtContext *ctx) override;

    antlrcpp::Any visitJumpStmt(STParser::JumpStmtContext *ctx) override;

    antlrcpp::Any visitAssignStmt(STParser::AssignStmtContext *ctx) override;

    antlrcpp::Any visitPrefixExpr(STParser::PrefixExprContext *ctx) override;

    antlrcpp::Any visitExpr(STParser::ExprContext *ctx) override;

    antlrcpp::Any visitOrExpr(STParser::OrExprContext *ctx) override;

    antlrcpp::Any visitAndExpr(STParser::AndExprContext *ctx) override;

    antlrcpp::Any visitEqualExpr(STParser::EqualExprContext *ctx) override;

    antlrcpp::Any visitRelationExpr(STParser::RelationExprContext *ctx) override;

    antlrcpp::Any visitAddExpr(STParser::AddExprContext *ctx) override;

    antlrcpp::Any visitMultipliExpr(STParser::MultipliExprContext *ctx) override;

    antlrcpp::Any visitUnaryExpr(STParser::UnaryExprContext *ctx) override;

    antlrcpp::Any visitPrimary(STParser::PrimaryContext *ctx) override;

    antlrcpp::Any visitIfStmt(STParser::IfStmtContext *ctx) override;

    antlrcpp::Any visitCaseStmt(STParser::CaseStmtContext *ctx) override;

    antlrcpp::Any visitCaseList(STParser::CaseListContext *ctx) override;

    antlrcpp::Any visitCaseValues(STParser::CaseValuesContext *ctx) override;

    antlrcpp::Any visitForStmt(STParser::ForStmtContext *ctx) override;

    antlrcpp::Any visitWhileStmt(STParser::WhileStmtContext *ctx) override;

    antlrcpp::Any visitRepeatStmt(STParser::RepeatStmtContext *ctx) override;

    antlrcpp::Any visitType(STParser::TypeContext *ctx) override;

    antlrcpp::Any visitFuncParams(STParser::FuncParamsContext *ctx) override;

    antlrcpp::Any visitArray(STParser::ArrayContext *ctx) override;

    antlrcpp::Any visitIdenti(STParser::IdentiContext *ctx) override;

    antlrcpp::Any visitStruct(STParser::StructContext *ctx) override;

    antlrcpp::Any visitDeclarationStmt(STParser::DeclarationStmtContext *ctx) override;

    antlrcpp::Any visitVarDeclarationBlock(STParser::VarDeclarationBlockContext *ctx) override;

    antlrcpp::Any visitVarDeclaration(STParser::VarDeclarationContext *ctx) override;

    antlrcpp::Any visitFunctionDecl(STParser::FunctionDeclContext *ctx) override;

    antlrcpp::Any visitFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) override;

private:
    SymbolTable symbolTable; // 符号表
};

#endif // ST_PARSER_VISITOR_H