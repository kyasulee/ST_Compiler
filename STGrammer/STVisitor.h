
// Generated from ST.g4 by ANTLR 4.9.3

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
    virtual antlrcpp::Any visitProgram(STParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStatement(STParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclaration(STParser::VarDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitAssignStmt(STParser::AssignStmtContext *context) = 0;

    virtual antlrcpp::Any visitExpr(STParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitAddExpr(STParser::AddExprContext *context) = 0;

    virtual antlrcpp::Any visitMulExpr(STParser::MulExprContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(STParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(STParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(STParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitType(STParser::TypeContext *context) = 0;


};

