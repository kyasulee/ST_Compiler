
// Generated from ST.g4 by ANTLR 4.9.3

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

  virtual void enterProgram(STParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(STParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(STParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(STParser::StatementContext * /*ctx*/) override { }

  virtual void enterVarDeclaration(STParser::VarDeclarationContext * /*ctx*/) override { }
  virtual void exitVarDeclaration(STParser::VarDeclarationContext * /*ctx*/) override { }

  virtual void enterAssignStmt(STParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(STParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterExpr(STParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(STParser::ExprContext * /*ctx*/) override { }

  virtual void enterAddExpr(STParser::AddExprContext * /*ctx*/) override { }
  virtual void exitAddExpr(STParser::AddExprContext * /*ctx*/) override { }

  virtual void enterMulExpr(STParser::MulExprContext * /*ctx*/) override { }
  virtual void exitMulExpr(STParser::MulExprContext * /*ctx*/) override { }

  virtual void enterPrimary(STParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(STParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterIfStmt(STParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(STParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterForStmt(STParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(STParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterType(STParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(STParser::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

