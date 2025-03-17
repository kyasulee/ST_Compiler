
// Generated from ST.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "STParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by STParser.
 */
class  STListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(STParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(STParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(STParser::StatementContext *ctx) = 0;
  virtual void exitStatement(STParser::StatementContext *ctx) = 0;

  virtual void enterVarDeclaration(STParser::VarDeclarationContext *ctx) = 0;
  virtual void exitVarDeclaration(STParser::VarDeclarationContext *ctx) = 0;

  virtual void enterAssignStmt(STParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(STParser::AssignStmtContext *ctx) = 0;

  virtual void enterExpr(STParser::ExprContext *ctx) = 0;
  virtual void exitExpr(STParser::ExprContext *ctx) = 0;

  virtual void enterAddExpr(STParser::AddExprContext *ctx) = 0;
  virtual void exitAddExpr(STParser::AddExprContext *ctx) = 0;

  virtual void enterMulExpr(STParser::MulExprContext *ctx) = 0;
  virtual void exitMulExpr(STParser::MulExprContext *ctx) = 0;

  virtual void enterPrimary(STParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(STParser::PrimaryContext *ctx) = 0;

  virtual void enterIfStmt(STParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(STParser::IfStmtContext *ctx) = 0;

  virtual void enterForStmt(STParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(STParser::ForStmtContext *ctx) = 0;

  virtual void enterType(STParser::TypeContext *ctx) = 0;
  virtual void exitType(STParser::TypeContext *ctx) = 0;


};

