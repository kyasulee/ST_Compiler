
// Generated from ST.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "STParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by STParser.
 */
class  STListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStartpoint(STParser::StartpointContext *ctx) = 0;
  virtual void exitStartpoint(STParser::StartpointContext *ctx) = 0;

  virtual void enterProgram_list(STParser::Program_listContext *ctx) = 0;
  virtual void exitProgram_list(STParser::Program_listContext *ctx) = 0;

  virtual void enterProgramDecl(STParser::ProgramDeclContext *ctx) = 0;
  virtual void exitProgramDecl(STParser::ProgramDeclContext *ctx) = 0;

  virtual void enterStatement_list(STParser::Statement_listContext *ctx) = 0;
  virtual void exitStatement_list(STParser::Statement_listContext *ctx) = 0;

  virtual void enterSelectStmt(STParser::SelectStmtContext *ctx) = 0;
  virtual void exitSelectStmt(STParser::SelectStmtContext *ctx) = 0;

  virtual void enterIterationStmt(STParser::IterationStmtContext *ctx) = 0;
  virtual void exitIterationStmt(STParser::IterationStmtContext *ctx) = 0;

  virtual void enterCallFuncStmt(STParser::CallFuncStmtContext *ctx) = 0;
  virtual void exitCallFuncStmt(STParser::CallFuncStmtContext *ctx) = 0;

  virtual void enterJumpStmt(STParser::JumpStmtContext *ctx) = 0;
  virtual void exitJumpStmt(STParser::JumpStmtContext *ctx) = 0;

  virtual void enterAssignStmt(STParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(STParser::AssignStmtContext *ctx) = 0;

  virtual void enterPrefixExpr(STParser::PrefixExprContext *ctx) = 0;
  virtual void exitPrefixExpr(STParser::PrefixExprContext *ctx) = 0;

  virtual void enterExpr(STParser::ExprContext *ctx) = 0;
  virtual void exitExpr(STParser::ExprContext *ctx) = 0;

  virtual void enterOrExpr(STParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(STParser::OrExprContext *ctx) = 0;

  virtual void enterAndExpr(STParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(STParser::AndExprContext *ctx) = 0;

  virtual void enterEqualExpr(STParser::EqualExprContext *ctx) = 0;
  virtual void exitEqualExpr(STParser::EqualExprContext *ctx) = 0;

  virtual void enterRelationExpr(STParser::RelationExprContext *ctx) = 0;
  virtual void exitRelationExpr(STParser::RelationExprContext *ctx) = 0;

  virtual void enterAddExpr(STParser::AddExprContext *ctx) = 0;
  virtual void exitAddExpr(STParser::AddExprContext *ctx) = 0;

  virtual void enterMultipliExpr(STParser::MultipliExprContext *ctx) = 0;
  virtual void exitMultipliExpr(STParser::MultipliExprContext *ctx) = 0;

  virtual void enterUnaryExpr(STParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(STParser::UnaryExprContext *ctx) = 0;

  virtual void enterPrimary(STParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(STParser::PrimaryContext *ctx) = 0;

  virtual void enterIfStmt(STParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(STParser::IfStmtContext *ctx) = 0;

  virtual void enterCaseStmt(STParser::CaseStmtContext *ctx) = 0;
  virtual void exitCaseStmt(STParser::CaseStmtContext *ctx) = 0;

  virtual void enterCaseList(STParser::CaseListContext *ctx) = 0;
  virtual void exitCaseList(STParser::CaseListContext *ctx) = 0;

  virtual void enterCaseValues(STParser::CaseValuesContext *ctx) = 0;
  virtual void exitCaseValues(STParser::CaseValuesContext *ctx) = 0;

  virtual void enterForStmt(STParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(STParser::ForStmtContext *ctx) = 0;

  virtual void enterWhileStmt(STParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(STParser::WhileStmtContext *ctx) = 0;

  virtual void enterRepeatStmt(STParser::RepeatStmtContext *ctx) = 0;
  virtual void exitRepeatStmt(STParser::RepeatStmtContext *ctx) = 0;

  virtual void enterType(STParser::TypeContext *ctx) = 0;
  virtual void exitType(STParser::TypeContext *ctx) = 0;

  virtual void enterFuncParams(STParser::FuncParamsContext *ctx) = 0;
  virtual void exitFuncParams(STParser::FuncParamsContext *ctx) = 0;

  virtual void enterArray(STParser::ArrayContext *ctx) = 0;
  virtual void exitArray(STParser::ArrayContext *ctx) = 0;

  virtual void enterIdenti(STParser::IdentiContext *ctx) = 0;
  virtual void exitIdenti(STParser::IdentiContext *ctx) = 0;

  virtual void enterStruct(STParser::StructContext *ctx) = 0;
  virtual void exitStruct(STParser::StructContext *ctx) = 0;

  virtual void enterDeclarationStmt(STParser::DeclarationStmtContext *ctx) = 0;
  virtual void exitDeclarationStmt(STParser::DeclarationStmtContext *ctx) = 0;

  virtual void enterVarDeclarationBlock(STParser::VarDeclarationBlockContext *ctx) = 0;
  virtual void exitVarDeclarationBlock(STParser::VarDeclarationBlockContext *ctx) = 0;

  virtual void enterVarDeclaration(STParser::VarDeclarationContext *ctx) = 0;
  virtual void exitVarDeclaration(STParser::VarDeclarationContext *ctx) = 0;

  virtual void enterFunctionDecl(STParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(STParser::FunctionDeclContext *ctx) = 0;

  virtual void enterFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) = 0;
  virtual void exitFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) = 0;


};

