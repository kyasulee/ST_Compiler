
// Generated from ST.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "STParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by STParser.
 */
class  STVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by STParser.
   */
    virtual antlrcpp::Any visitStartpoint(STParser::StartpointContext *context) = 0;

    virtual antlrcpp::Any visitProgram_list(STParser::Program_listContext *context) = 0;

    virtual antlrcpp::Any visitProgramDecl(STParser::ProgramDeclContext *context) = 0;

    virtual antlrcpp::Any visitStatement_list(STParser::Statement_listContext *context) = 0;

    virtual antlrcpp::Any visitSelectStmt(STParser::SelectStmtContext *context) = 0;

    virtual antlrcpp::Any visitIterationStmt(STParser::IterationStmtContext *context) = 0;

    virtual antlrcpp::Any visitCallFuncStmt(STParser::CallFuncStmtContext *context) = 0;

    virtual antlrcpp::Any visitJumpStmt(STParser::JumpStmtContext *context) = 0;

    virtual antlrcpp::Any visitAssignStmt(STParser::AssignStmtContext *context) = 0;

    virtual antlrcpp::Any visitPrefixExpr(STParser::PrefixExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr(STParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitOrExpr(STParser::OrExprContext *context) = 0;

    virtual antlrcpp::Any visitAndExpr(STParser::AndExprContext *context) = 0;

    virtual antlrcpp::Any visitEqualExpr(STParser::EqualExprContext *context) = 0;

    virtual antlrcpp::Any visitRelationExpr(STParser::RelationExprContext *context) = 0;

    virtual antlrcpp::Any visitAddExpr(STParser::AddExprContext *context) = 0;

    virtual antlrcpp::Any visitMultipliExpr(STParser::MultipliExprContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpr(STParser::UnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(STParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(STParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitCaseStmt(STParser::CaseStmtContext *context) = 0;

    virtual antlrcpp::Any visitCaseList(STParser::CaseListContext *context) = 0;

    virtual antlrcpp::Any visitCaseValues(STParser::CaseValuesContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(STParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(STParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitRepeatStmt(STParser::RepeatStmtContext *context) = 0;

    virtual antlrcpp::Any visitType(STParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitFuncParams(STParser::FuncParamsContext *context) = 0;

    virtual antlrcpp::Any visitArray(STParser::ArrayContext *context) = 0;

    virtual antlrcpp::Any visitIdenti(STParser::IdentiContext *context) = 0;

    virtual antlrcpp::Any visitStruct(STParser::StructContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationStmt(STParser::DeclarationStmtContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclarationBlock(STParser::VarDeclarationBlockContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclaration(STParser::VarDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDecl(STParser::FunctionDeclContext *context) = 0;

    virtual antlrcpp::Any visitFunctionBlockDecl(STParser::FunctionBlockDeclContext *context) = 0;


};

