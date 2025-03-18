
// Generated from ST.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "STVisitor.h"


/**
 * This class provides an empty implementation of STVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  STBaseVisitor : public STVisitor {
public:

  virtual antlrcpp::Any visitStartpoint(STParser::StartpointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_list(STParser::Program_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramDecl(STParser::ProgramDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_list(STParser::Statement_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectStmt(STParser::SelectStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIterationStmt(STParser::IterationStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallFuncStmt(STParser::CallFuncStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJumpStmt(STParser::JumpStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignStmt(STParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrefixExpr(STParser::PrefixExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(STParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrExpr(STParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndExpr(STParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualExpr(STParser::EqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationExpr(STParser::RelationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddExpr(STParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultipliExpr(STParser::MultipliExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpr(STParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(STParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(STParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseStmt(STParser::CaseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseList(STParser::CaseListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseValues(STParser::CaseValuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt(STParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(STParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeatStmt(STParser::RepeatStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(STParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncParams(STParser::FuncParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray(STParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdenti(STParser::IdentiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct(STParser::StructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationStmt(STParser::DeclarationStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDeclarationBlock(STParser::VarDeclarationBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDeclaration(STParser::VarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDecl(STParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) override {
    return visitChildren(ctx);
  }


};

