
// Generated from ST.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "STListener.h"


/**
 * This class provides an empty implementation of STListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  STBaseListener : public STListener {
public:

  virtual void enterStartpoint(STParser::StartpointContext * /*ctx*/) override { }
  virtual void exitStartpoint(STParser::StartpointContext * /*ctx*/) override { }

  virtual void enterProgram_list(STParser::Program_listContext * /*ctx*/) override { }
  virtual void exitProgram_list(STParser::Program_listContext * /*ctx*/) override { }

  virtual void enterProgramDecl(STParser::ProgramDeclContext * /*ctx*/) override { }
  virtual void exitProgramDecl(STParser::ProgramDeclContext * /*ctx*/) override { }

  virtual void enterStatement_list(STParser::Statement_listContext * /*ctx*/) override { }
  virtual void exitStatement_list(STParser::Statement_listContext * /*ctx*/) override { }

  virtual void enterSelectStmt(STParser::SelectStmtContext * /*ctx*/) override { }
  virtual void exitSelectStmt(STParser::SelectStmtContext * /*ctx*/) override { }

  virtual void enterIterationStmt(STParser::IterationStmtContext * /*ctx*/) override { }
  virtual void exitIterationStmt(STParser::IterationStmtContext * /*ctx*/) override { }

  virtual void enterCallFuncStmt(STParser::CallFuncStmtContext * /*ctx*/) override { }
  virtual void exitCallFuncStmt(STParser::CallFuncStmtContext * /*ctx*/) override { }

  virtual void enterJumpStmt(STParser::JumpStmtContext * /*ctx*/) override { }
  virtual void exitJumpStmt(STParser::JumpStmtContext * /*ctx*/) override { }

  virtual void enterAssignStmt(STParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(STParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterPrefixExpr(STParser::PrefixExprContext * /*ctx*/) override { }
  virtual void exitPrefixExpr(STParser::PrefixExprContext * /*ctx*/) override { }

  virtual void enterExpr(STParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(STParser::ExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(STParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(STParser::OrExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(STParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(STParser::AndExprContext * /*ctx*/) override { }

  virtual void enterEqualExpr(STParser::EqualExprContext * /*ctx*/) override { }
  virtual void exitEqualExpr(STParser::EqualExprContext * /*ctx*/) override { }

  virtual void enterRelationExpr(STParser::RelationExprContext * /*ctx*/) override { }
  virtual void exitRelationExpr(STParser::RelationExprContext * /*ctx*/) override { }

  virtual void enterAddExpr(STParser::AddExprContext * /*ctx*/) override { }
  virtual void exitAddExpr(STParser::AddExprContext * /*ctx*/) override { }

  virtual void enterMultipliExpr(STParser::MultipliExprContext * /*ctx*/) override { }
  virtual void exitMultipliExpr(STParser::MultipliExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(STParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(STParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterPrimary(STParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(STParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterIfStmt(STParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(STParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterCaseStmt(STParser::CaseStmtContext * /*ctx*/) override { }
  virtual void exitCaseStmt(STParser::CaseStmtContext * /*ctx*/) override { }

  virtual void enterCaseList(STParser::CaseListContext * /*ctx*/) override { }
  virtual void exitCaseList(STParser::CaseListContext * /*ctx*/) override { }

  virtual void enterCaseValues(STParser::CaseValuesContext * /*ctx*/) override { }
  virtual void exitCaseValues(STParser::CaseValuesContext * /*ctx*/) override { }

  virtual void enterForStmt(STParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(STParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(STParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(STParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterRepeatStmt(STParser::RepeatStmtContext * /*ctx*/) override { }
  virtual void exitRepeatStmt(STParser::RepeatStmtContext * /*ctx*/) override { }

  virtual void enterType(STParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(STParser::TypeContext * /*ctx*/) override { }

  virtual void enterFuncParams(STParser::FuncParamsContext * /*ctx*/) override { }
  virtual void exitFuncParams(STParser::FuncParamsContext * /*ctx*/) override { }

  virtual void enterArray(STParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(STParser::ArrayContext * /*ctx*/) override { }

  virtual void enterIdenti(STParser::IdentiContext * /*ctx*/) override { }
  virtual void exitIdenti(STParser::IdentiContext * /*ctx*/) override { }

  virtual void enterStruct(STParser::StructContext * /*ctx*/) override { }
  virtual void exitStruct(STParser::StructContext * /*ctx*/) override { }

  virtual void enterDeclarationStmt(STParser::DeclarationStmtContext * /*ctx*/) override { }
  virtual void exitDeclarationStmt(STParser::DeclarationStmtContext * /*ctx*/) override { }

  virtual void enterVarDeclarationBlock(STParser::VarDeclarationBlockContext * /*ctx*/) override { }
  virtual void exitVarDeclarationBlock(STParser::VarDeclarationBlockContext * /*ctx*/) override { }

  virtual void enterVarDeclaration(STParser::VarDeclarationContext * /*ctx*/) override { }
  virtual void exitVarDeclaration(STParser::VarDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(STParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(STParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFunctionBlockDecl(STParser::FunctionBlockDeclContext * /*ctx*/) override { }
  virtual void exitFunctionBlockDecl(STParser::FunctionBlockDeclContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

