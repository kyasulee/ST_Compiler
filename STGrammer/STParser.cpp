
// Generated from ST.g4 by ANTLR 4.9.3


#include "STListener.h"
#include "STVisitor.h"

#include "STParser.h"


using namespace antlrcpp;
using namespace antlr4;

STParser::STParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

STParser::~STParser() {
  delete _interpreter;
}

std::string STParser::getGrammarFileName() const {
  return "ST.g4";
}

const std::vector<std::string>& STParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& STParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

STParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::ProgramContext::EOF() {
  return getToken(STParser::EOF, 0);
}

std::vector<STParser::StatementContext *> STParser::ProgramContext::statement() {
  return getRuleContexts<STParser::StatementContext>();
}

STParser::StatementContext* STParser::ProgramContext::statement(size_t i) {
  return getRuleContext<STParser::StatementContext>(i);
}


size_t STParser::ProgramContext::getRuleIndex() const {
  return STParser::RuleProgram;
}

void STParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void STParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any STParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

STParser::ProgramContext* STParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, STParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::ID))) != 0)) {
      setState(22);
      statement();
      setState(27);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(28);
    match(STParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

STParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::VarDeclarationContext* STParser::StatementContext::varDeclaration() {
  return getRuleContext<STParser::VarDeclarationContext>(0);
}

STParser::AssignStmtContext* STParser::StatementContext::assignStmt() {
  return getRuleContext<STParser::AssignStmtContext>(0);
}

STParser::IfStmtContext* STParser::StatementContext::ifStmt() {
  return getRuleContext<STParser::IfStmtContext>(0);
}

STParser::ForStmtContext* STParser::StatementContext::forStmt() {
  return getRuleContext<STParser::ForStmtContext>(0);
}


size_t STParser::StatementContext::getRuleIndex() const {
  return STParser::RuleStatement;
}

void STParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void STParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any STParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

STParser::StatementContext* STParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, STParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(30);
        varDeclaration();
        break;
      }

      case STParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        assignStmt();
        break;
      }

      case STParser::IF: {
        enterOuterAlt(_localctx, 3);
        setState(32);
        ifStmt();
        break;
      }

      case STParser::FOR: {
        enterOuterAlt(_localctx, 4);
        setState(33);
        forStmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

STParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::VarDeclarationContext::VAR() {
  return getToken(STParser::VAR, 0);
}

tree::TerminalNode* STParser::VarDeclarationContext::ID() {
  return getToken(STParser::ID, 0);
}

tree::TerminalNode* STParser::VarDeclarationContext::COLON() {
  return getToken(STParser::COLON, 0);
}

STParser::TypeContext* STParser::VarDeclarationContext::type() {
  return getRuleContext<STParser::TypeContext>(0);
}

tree::TerminalNode* STParser::VarDeclarationContext::SEMI() {
  return getToken(STParser::SEMI, 0);
}


size_t STParser::VarDeclarationContext::getRuleIndex() const {
  return STParser::RuleVarDeclaration;
}

void STParser::VarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclaration(this);
}

void STParser::VarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclaration(this);
}


antlrcpp::Any STParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

STParser::VarDeclarationContext* STParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, STParser::RuleVarDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(STParser::VAR);
    setState(37);
    match(STParser::ID);
    setState(38);
    match(STParser::COLON);
    setState(39);
    type();
    setState(40);
    match(STParser::SEMI);
    setState(41);
    match(STParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStmtContext ------------------------------------------------------------------

STParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::AssignStmtContext::ID() {
  return getToken(STParser::ID, 0);
}

tree::TerminalNode* STParser::AssignStmtContext::ASSIGN() {
  return getToken(STParser::ASSIGN, 0);
}

STParser::ExprContext* STParser::AssignStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::AssignStmtContext::SEMI() {
  return getToken(STParser::SEMI, 0);
}


size_t STParser::AssignStmtContext::getRuleIndex() const {
  return STParser::RuleAssignStmt;
}

void STParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}

void STParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}


antlrcpp::Any STParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::AssignStmtContext* STParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, STParser::RuleAssignStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(STParser::ID);
    setState(44);
    match(STParser::ASSIGN);
    setState(45);
    expr();
    setState(46);
    match(STParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

STParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::AddExprContext* STParser::ExprContext::addExpr() {
  return getRuleContext<STParser::AddExprContext>(0);
}


size_t STParser::ExprContext::getRuleIndex() const {
  return STParser::RuleExpr;
}

void STParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void STParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any STParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

STParser::ExprContext* STParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 8, STParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    addExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExprContext ------------------------------------------------------------------

STParser::AddExprContext::AddExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::MulExprContext *> STParser::AddExprContext::mulExpr() {
  return getRuleContexts<STParser::MulExprContext>();
}

STParser::MulExprContext* STParser::AddExprContext::mulExpr(size_t i) {
  return getRuleContext<STParser::MulExprContext>(i);
}

std::vector<tree::TerminalNode *> STParser::AddExprContext::ADD() {
  return getTokens(STParser::ADD);
}

tree::TerminalNode* STParser::AddExprContext::ADD(size_t i) {
  return getToken(STParser::ADD, i);
}

std::vector<tree::TerminalNode *> STParser::AddExprContext::MINUS() {
  return getTokens(STParser::MINUS);
}

tree::TerminalNode* STParser::AddExprContext::MINUS(size_t i) {
  return getToken(STParser::MINUS, i);
}


size_t STParser::AddExprContext::getRuleIndex() const {
  return STParser::RuleAddExpr;
}

void STParser::AddExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpr(this);
}

void STParser::AddExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpr(this);
}


antlrcpp::Any STParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}

STParser::AddExprContext* STParser::addExpr() {
  AddExprContext *_localctx = _tracker.createInstance<AddExprContext>(_ctx, getState());
  enterRule(_localctx, 10, STParser::RuleAddExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    mulExpr();
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::ADD

    || _la == STParser::MINUS) {
      setState(51);
      _la = _input->LA(1);
      if (!(_la == STParser::ADD

      || _la == STParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(52);
      mulExpr();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExprContext ------------------------------------------------------------------

STParser::MulExprContext::MulExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::PrimaryContext *> STParser::MulExprContext::primary() {
  return getRuleContexts<STParser::PrimaryContext>();
}

STParser::PrimaryContext* STParser::MulExprContext::primary(size_t i) {
  return getRuleContext<STParser::PrimaryContext>(i);
}

std::vector<tree::TerminalNode *> STParser::MulExprContext::MUL() {
  return getTokens(STParser::MUL);
}

tree::TerminalNode* STParser::MulExprContext::MUL(size_t i) {
  return getToken(STParser::MUL, i);
}

std::vector<tree::TerminalNode *> STParser::MulExprContext::DIV() {
  return getTokens(STParser::DIV);
}

tree::TerminalNode* STParser::MulExprContext::DIV(size_t i) {
  return getToken(STParser::DIV, i);
}


size_t STParser::MulExprContext::getRuleIndex() const {
  return STParser::RuleMulExpr;
}

void STParser::MulExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpr(this);
}

void STParser::MulExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpr(this);
}


antlrcpp::Any STParser::MulExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitMulExpr(this);
  else
    return visitor->visitChildren(this);
}

STParser::MulExprContext* STParser::mulExpr() {
  MulExprContext *_localctx = _tracker.createInstance<MulExprContext>(_ctx, getState());
  enterRule(_localctx, 12, STParser::RuleMulExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    primary();
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::MUL

    || _la == STParser::DIV) {
      setState(59);
      _la = _input->LA(1);
      if (!(_la == STParser::MUL

      || _la == STParser::DIV)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(60);
      primary();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

STParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::PrimaryContext::LPAREN() {
  return getToken(STParser::LPAREN, 0);
}

STParser::ExprContext* STParser::PrimaryContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::PrimaryContext::RPAREN() {
  return getToken(STParser::RPAREN, 0);
}

tree::TerminalNode* STParser::PrimaryContext::ID() {
  return getToken(STParser::ID, 0);
}

tree::TerminalNode* STParser::PrimaryContext::NUMBER() {
  return getToken(STParser::NUMBER, 0);
}


size_t STParser::PrimaryContext::getRuleIndex() const {
  return STParser::RulePrimary;
}

void STParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void STParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


antlrcpp::Any STParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

STParser::PrimaryContext* STParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 14, STParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(66);
        match(STParser::LPAREN);
        setState(67);
        expr();
        setState(68);
        match(STParser::RPAREN);
        break;
      }

      case STParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(70);
        match(STParser::ID);
        break;
      }

      case STParser::NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(71);
        match(STParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

STParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::IfStmtContext::IF() {
  return getToken(STParser::IF, 0);
}

STParser::ExprContext* STParser::IfStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::IfStmtContext::THEN() {
  return getToken(STParser::THEN, 0);
}

tree::TerminalNode* STParser::IfStmtContext::END_IF() {
  return getToken(STParser::END_IF, 0);
}

std::vector<STParser::StatementContext *> STParser::IfStmtContext::statement() {
  return getRuleContexts<STParser::StatementContext>();
}

STParser::StatementContext* STParser::IfStmtContext::statement(size_t i) {
  return getRuleContext<STParser::StatementContext>(i);
}

tree::TerminalNode* STParser::IfStmtContext::ELSE() {
  return getToken(STParser::ELSE, 0);
}


size_t STParser::IfStmtContext::getRuleIndex() const {
  return STParser::RuleIfStmt;
}

void STParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void STParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


antlrcpp::Any STParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::IfStmtContext* STParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 16, STParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(STParser::IF);
    setState(75);
    expr();
    setState(76);
    match(STParser::THEN);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::ID))) != 0)) {
      setState(77);
      statement();
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::ELSE) {
      setState(83);
      match(STParser::ELSE);
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::VAR)
        | (1ULL << STParser::IF)
        | (1ULL << STParser::FOR)
        | (1ULL << STParser::ID))) != 0)) {
        setState(84);
        statement();
        setState(89);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(92);
    match(STParser::END_IF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

STParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::ForStmtContext::FOR() {
  return getToken(STParser::FOR, 0);
}

tree::TerminalNode* STParser::ForStmtContext::ID() {
  return getToken(STParser::ID, 0);
}

tree::TerminalNode* STParser::ForStmtContext::ASSIGN() {
  return getToken(STParser::ASSIGN, 0);
}

std::vector<STParser::ExprContext *> STParser::ForStmtContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}

tree::TerminalNode* STParser::ForStmtContext::TO() {
  return getToken(STParser::TO, 0);
}

tree::TerminalNode* STParser::ForStmtContext::DO() {
  return getToken(STParser::DO, 0);
}

tree::TerminalNode* STParser::ForStmtContext::END_FOR() {
  return getToken(STParser::END_FOR, 0);
}

std::vector<STParser::StatementContext *> STParser::ForStmtContext::statement() {
  return getRuleContexts<STParser::StatementContext>();
}

STParser::StatementContext* STParser::ForStmtContext::statement(size_t i) {
  return getRuleContext<STParser::StatementContext>(i);
}


size_t STParser::ForStmtContext::getRuleIndex() const {
  return STParser::RuleForStmt;
}

void STParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void STParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}


antlrcpp::Any STParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::ForStmtContext* STParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 18, STParser::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(STParser::FOR);
    setState(95);
    match(STParser::ID);
    setState(96);
    match(STParser::ASSIGN);
    setState(97);
    expr();
    setState(98);
    match(STParser::TO);
    setState(99);
    expr();
    setState(100);
    match(STParser::DO);
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::ID))) != 0)) {
      setState(101);
      statement();
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(107);
    match(STParser::END_FOR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

STParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t STParser::TypeContext::getRuleIndex() const {
  return STParser::RuleType;
}

void STParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void STParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any STParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

STParser::TypeContext* STParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 20, STParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__1)
      | (1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> STParser::_decisionToDFA;
atn::PredictionContextCache STParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN STParser::_atn;
std::vector<uint16_t> STParser::_serializedATN;

std::vector<std::string> STParser::_ruleNames = {
  "program", "statement", "varDeclaration", "assignStmt", "expr", "addExpr", 
  "mulExpr", "primary", "ifStmt", "forStmt", "type"
};

std::vector<std::string> STParser::_literalNames = {
  "", "'END_VAR'", "'INT'", "'REAL'", "'BOOL'", "'WORD'", "", "", "'VAR'", 
  "'IF'", "'THEN'", "'ELSE'", "'END_IF'", "'FOR'", "'TO'", "'DO'", "'END_FOR'", 
  "':='", "'+'", "'-'", "'*'", "'/'", "';'", "':'", "'('", "')'"
};

std::vector<std::string> STParser::_symbolicNames = {
  "", "", "", "", "", "", "NUMBER", "IDENT", "VAR", "IF", "THEN", "ELSE", 
  "END_IF", "FOR", "TO", "DO", "END_FOR", "ASSIGN", "ADD", "MINUS", "MUL", 
  "DIV", "SEMI", "COLON", "LPAREN", "RPAREN", "WS", "ID"
};

dfa::Vocabulary STParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> STParser::_tokenNames;

STParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x1d, 0x72, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x7, 0x2, 0x1a, 
       0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x25, 0xa, 0x3, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x38, 0xa, 0x7, 
       0xc, 0x7, 0xe, 0x7, 0x3b, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x7, 0x8, 0x40, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x43, 0xb, 0x8, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
       0x4b, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
       0x51, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x54, 0xb, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x7, 0xa, 0x58, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x5b, 0xb, 0xa, 
       0x5, 0xa, 0x5d, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 
       0xb, 0x69, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x6c, 0xb, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x2, 0x2, 0xd, 0x2, 0x4, 
       0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x5, 0x3, 0x2, 
       0x14, 0x15, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x4, 0x7, 0x2, 0x72, 
       0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x24, 0x3, 0x2, 0x2, 0x2, 0x6, 
       0x26, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x32, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0x34, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3c, 0x3, 
       0x2, 0x2, 0x2, 0x10, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x12, 0x4c, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x60, 0x3, 0x2, 0x2, 0x2, 0x16, 0x6f, 0x3, 0x2, 0x2, 
       0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 0x18, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 
       0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x2, 0x2, 0x3, 0x1f, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x20, 0x25, 0x5, 0x6, 0x4, 0x2, 0x21, 0x25, 0x5, 0x8, 
       0x5, 0x2, 0x22, 0x25, 0x5, 0x12, 0xa, 0x2, 0x23, 0x25, 0x5, 0x14, 
       0xb, 0x2, 0x24, 0x20, 0x3, 0x2, 0x2, 0x2, 0x24, 0x21, 0x3, 0x2, 0x2, 
       0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x23, 0x3, 0x2, 0x2, 0x2, 
       0x25, 0x5, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0xa, 0x2, 0x2, 0x27, 
       0x28, 0x7, 0x1d, 0x2, 0x2, 0x28, 0x29, 0x7, 0x19, 0x2, 0x2, 0x29, 
       0x2a, 0x5, 0x16, 0xc, 0x2, 0x2a, 0x2b, 0x7, 0x18, 0x2, 0x2, 0x2b, 
       0x2c, 0x7, 0x3, 0x2, 0x2, 0x2c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 
       0x7, 0x1d, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x13, 0x2, 0x2, 0x2f, 0x30, 
       0x5, 0xa, 0x6, 0x2, 0x30, 0x31, 0x7, 0x18, 0x2, 0x2, 0x31, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x33, 0x5, 0xc, 0x7, 0x2, 0x33, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0x39, 0x5, 0xe, 0x8, 0x2, 0x35, 0x36, 0x9, 0x2, 0x2, 
       0x2, 0x36, 0x38, 0x5, 0xe, 0x8, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 
       0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 
       0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x3c, 0x41, 0x5, 0x10, 0x9, 0x2, 0x3d, 0x3e, 
       0x9, 0x3, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x10, 0x9, 0x2, 0x3f, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 
       0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0xf, 0x3, 0x2, 
       0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x1a, 
       0x2, 0x2, 0x45, 0x46, 0x5, 0xa, 0x6, 0x2, 0x46, 0x47, 0x7, 0x1b, 
       0x2, 0x2, 0x47, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x7, 0x1d, 
       0x2, 0x2, 0x49, 0x4b, 0x7, 0x8, 0x2, 0x2, 0x4a, 0x44, 0x3, 0x2, 0x2, 
       0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 
       0x4b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0xb, 0x2, 0x2, 0x4d, 
       0x4e, 0x5, 0xa, 0x6, 0x2, 0x4e, 0x52, 0x7, 0xc, 0x2, 0x2, 0x4f, 0x51, 
       0x5, 0x4, 0x3, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 
       0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 
       0x2, 0x2, 0x53, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 
       0x2, 0x55, 0x59, 0x7, 0xd, 0x2, 0x2, 0x56, 0x58, 0x5, 0x4, 0x3, 0x2, 
       0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x55, 0x3, 
       0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 
       0x2, 0x2, 0x5e, 0x5f, 0x7, 0xe, 0x2, 0x2, 0x5f, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x60, 0x61, 0x7, 0xf, 0x2, 0x2, 0x61, 0x62, 0x7, 0x1d, 0x2, 
       0x2, 0x62, 0x63, 0x7, 0x13, 0x2, 0x2, 0x63, 0x64, 0x5, 0xa, 0x6, 
       0x2, 0x64, 0x65, 0x7, 0x10, 0x2, 0x2, 0x65, 0x66, 0x5, 0xa, 0x6, 
       0x2, 0x66, 0x6a, 0x7, 0x11, 0x2, 0x2, 0x67, 0x69, 0x5, 0x4, 0x3, 
       0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x3, 0x2, 0x2, 0x2, 
       0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 
       0x7, 0x12, 0x2, 0x2, 0x6e, 0x15, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 
       0x9, 0x4, 0x2, 0x2, 0x70, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb, 0x1b, 0x24, 
       0x39, 0x41, 0x4a, 0x52, 0x59, 0x5c, 0x6a, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

STParser::Initializer STParser::_init;
