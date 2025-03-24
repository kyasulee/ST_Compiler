
// Generated from ST.g4 by ANTLR 4.9.2


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


//----------------- StartpointContext ------------------------------------------------------------------

STParser::StartpointContext::StartpointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::StartpointContext::EOF() {
  return getToken(STParser::EOF, 0);
}

std::vector<STParser::Program_listContext *> STParser::StartpointContext::program_list() {
  return getRuleContexts<STParser::Program_listContext>();
}

STParser::Program_listContext* STParser::StartpointContext::program_list(size_t i) {
  return getRuleContext<STParser::Program_listContext>(i);
}


size_t STParser::StartpointContext::getRuleIndex() const {
  return STParser::RuleStartpoint;
}

void STParser::StartpointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartpoint(this);
}

void STParser::StartpointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartpoint(this);
}


antlrcpp::Any STParser::StartpointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitStartpoint(this);
  else
    return visitor->visitChildren(this);
}

STParser::StartpointContext* STParser::startpoint() {
  StartpointContext *_localctx = _tracker.createInstance<StartpointContext>(_ctx, getState());
  enterRule(_localctx, 0, STParser::RuleStartpoint);
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
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::T__0 || _la == STParser::T__76

    || _la == STParser::T__78) {
      setState(68);
      program_list();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(74);
    match(STParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Program_listContext ------------------------------------------------------------------

STParser::Program_listContext::Program_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::ProgramDeclContext* STParser::Program_listContext::programDecl() {
  return getRuleContext<STParser::ProgramDeclContext>(0);
}

STParser::FunctionDeclContext* STParser::Program_listContext::functionDecl() {
  return getRuleContext<STParser::FunctionDeclContext>(0);
}

STParser::FunctionBlockDeclContext* STParser::Program_listContext::functionBlockDecl() {
  return getRuleContext<STParser::FunctionBlockDeclContext>(0);
}


size_t STParser::Program_listContext::getRuleIndex() const {
  return STParser::RuleProgram_list;
}

void STParser::Program_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_list(this);
}

void STParser::Program_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_list(this);
}


antlrcpp::Any STParser::Program_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitProgram_list(this);
  else
    return visitor->visitChildren(this);
}

STParser::Program_listContext* STParser::program_list() {
  Program_listContext *_localctx = _tracker.createInstance<Program_listContext>(_ctx, getState());
  enterRule(_localctx, 2, STParser::RuleProgram_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(76);
        programDecl();
        break;
      }

      case STParser::T__76: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        functionDecl();
        break;
      }

      case STParser::T__78: {
        enterOuterAlt(_localctx, 3);
        setState(78);
        functionBlockDecl();
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

//----------------- ProgramDeclContext ------------------------------------------------------------------

STParser::ProgramDeclContext::ProgramDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::ProgramDeclContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::DeclarationStmtContext* STParser::ProgramDeclContext::declarationStmt() {
  return getRuleContext<STParser::DeclarationStmtContext>(0);
}

std::vector<STParser::Statement_listContext *> STParser::ProgramDeclContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::ProgramDeclContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::ProgramDeclContext::getRuleIndex() const {
  return STParser::RuleProgramDecl;
}

void STParser::ProgramDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgramDecl(this);
}

void STParser::ProgramDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgramDecl(this);
}


antlrcpp::Any STParser::ProgramDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitProgramDecl(this);
  else
    return visitor->visitChildren(this);
}

STParser::ProgramDeclContext* STParser::programDecl() {
  ProgramDeclContext *_localctx = _tracker.createInstance<ProgramDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, STParser::RuleProgramDecl);
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
    setState(81);
    match(STParser::T__0);
    setState(82);
    match(STParser::IDENT);
    setState(84);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(83);
      declarationStmt();
      break;
    }

    default:
      break;
    }
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7)
      | (1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13)
      | (1ULL << STParser::T__32)
      | (1ULL << STParser::T__36)
      | (1ULL << STParser::T__41)
      | (1ULL << STParser::T__46)
      | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
      setState(86);
      statement_list();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(STParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_listContext ------------------------------------------------------------------

STParser::Statement_listContext::Statement_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::AssignStmtContext* STParser::Statement_listContext::assignStmt() {
  return getRuleContext<STParser::AssignStmtContext>(0);
}

STParser::SelectStmtContext* STParser::Statement_listContext::selectStmt() {
  return getRuleContext<STParser::SelectStmtContext>(0);
}

STParser::IterationStmtContext* STParser::Statement_listContext::iterationStmt() {
  return getRuleContext<STParser::IterationStmtContext>(0);
}

STParser::CallFuncStmtContext* STParser::Statement_listContext::callFuncStmt() {
  return getRuleContext<STParser::CallFuncStmtContext>(0);
}

STParser::JumpStmtContext* STParser::Statement_listContext::jumpStmt() {
  return getRuleContext<STParser::JumpStmtContext>(0);
}


size_t STParser::Statement_listContext::getRuleIndex() const {
  return STParser::RuleStatement_list;
}

void STParser::Statement_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_list(this);
}

void STParser::Statement_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_list(this);
}


antlrcpp::Any STParser::Statement_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitStatement_list(this);
  else
    return visitor->visitChildren(this);
}

STParser::Statement_listContext* STParser::statement_list() {
  Statement_listContext *_localctx = _tracker.createInstance<Statement_listContext>(_ctx, getState());
  enterRule(_localctx, 6, STParser::RuleStatement_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == STParser::IDENT) {
        setState(94);
        assignStmt();
      }
      setState(97);
      match(STParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(99);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == STParser::T__32

      || _la == STParser::T__36) {
        setState(98);
        selectStmt();
      }
      setState(101);
      match(STParser::T__2);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(103);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::T__41)
        | (1ULL << STParser::T__46)
        | (1ULL << STParser::T__48))) != 0)) {
        setState(102);
        iterationStmt();
      }
      setState(105);
      match(STParser::T__2);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(107);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::T__3)
        | (1ULL << STParser::T__4)
        | (1ULL << STParser::T__5)
        | (1ULL << STParser::T__6)
        | (1ULL << STParser::T__7))) != 0) || _la == STParser::IDENT) {
        setState(106);
        callFuncStmt();
      }
      setState(109);
      match(STParser::T__2);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(111);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::T__10)
        | (1ULL << STParser::T__11)
        | (1ULL << STParser::T__12)
        | (1ULL << STParser::T__13))) != 0)) {
        setState(110);
        jumpStmt();
      }
      setState(113);
      match(STParser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectStmtContext ------------------------------------------------------------------

STParser::SelectStmtContext::SelectStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::IfStmtContext* STParser::SelectStmtContext::ifStmt() {
  return getRuleContext<STParser::IfStmtContext>(0);
}

STParser::CaseStmtContext* STParser::SelectStmtContext::caseStmt() {
  return getRuleContext<STParser::CaseStmtContext>(0);
}


size_t STParser::SelectStmtContext::getRuleIndex() const {
  return STParser::RuleSelectStmt;
}

void STParser::SelectStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectStmt(this);
}

void STParser::SelectStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectStmt(this);
}


antlrcpp::Any STParser::SelectStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitSelectStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::SelectStmtContext* STParser::selectStmt() {
  SelectStmtContext *_localctx = _tracker.createInstance<SelectStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, STParser::RuleSelectStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::T__32: {
        enterOuterAlt(_localctx, 1);
        setState(116);
        ifStmt();
        break;
      }

      case STParser::T__36: {
        enterOuterAlt(_localctx, 2);
        setState(117);
        caseStmt();
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

//----------------- IterationStmtContext ------------------------------------------------------------------

STParser::IterationStmtContext::IterationStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::WhileStmtContext* STParser::IterationStmtContext::whileStmt() {
  return getRuleContext<STParser::WhileStmtContext>(0);
}

STParser::ForStmtContext* STParser::IterationStmtContext::forStmt() {
  return getRuleContext<STParser::ForStmtContext>(0);
}

STParser::RepeatStmtContext* STParser::IterationStmtContext::repeatStmt() {
  return getRuleContext<STParser::RepeatStmtContext>(0);
}


size_t STParser::IterationStmtContext::getRuleIndex() const {
  return STParser::RuleIterationStmt;
}

void STParser::IterationStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStmt(this);
}

void STParser::IterationStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStmt(this);
}


antlrcpp::Any STParser::IterationStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitIterationStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::IterationStmtContext* STParser::iterationStmt() {
  IterationStmtContext *_localctx = _tracker.createInstance<IterationStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, STParser::RuleIterationStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::T__46: {
        enterOuterAlt(_localctx, 1);
        setState(120);
        whileStmt();
        break;
      }

      case STParser::T__41: {
        enterOuterAlt(_localctx, 2);
        setState(121);
        forStmt();
        break;
      }

      case STParser::T__48: {
        enterOuterAlt(_localctx, 3);
        setState(122);
        repeatStmt();
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

//----------------- CallFuncStmtContext ------------------------------------------------------------------

STParser::CallFuncStmtContext::CallFuncStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::CallFuncStmtContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::FuncParamsContext* STParser::CallFuncStmtContext::funcParams() {
  return getRuleContext<STParser::FuncParamsContext>(0);
}


size_t STParser::CallFuncStmtContext::getRuleIndex() const {
  return STParser::RuleCallFuncStmt;
}

void STParser::CallFuncStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallFuncStmt(this);
}

void STParser::CallFuncStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallFuncStmt(this);
}


antlrcpp::Any STParser::CallFuncStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitCallFuncStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::CallFuncStmtContext* STParser::callFuncStmt() {
  CallFuncStmtContext *_localctx = _tracker.createInstance<CallFuncStmtContext>(_ctx, getState());
  enterRule(_localctx, 12, STParser::RuleCallFuncStmt);
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
    setState(125);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7))) != 0) || _la == STParser::IDENT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(126);
    match(STParser::T__8);
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__7)
      | (1ULL << STParser::T__8)
      | (1ULL << STParser::T__26)
      | (1ULL << STParser::T__31))) != 0) || _la == STParser::NUMBER

    || _la == STParser::IDENT) {
      setState(127);
      funcParams();
    }
    setState(130);
    match(STParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpStmtContext ------------------------------------------------------------------

STParser::JumpStmtContext::JumpStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t STParser::JumpStmtContext::getRuleIndex() const {
  return STParser::RuleJumpStmt;
}

void STParser::JumpStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStmt(this);
}

void STParser::JumpStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStmt(this);
}


antlrcpp::Any STParser::JumpStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitJumpStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::JumpStmtContext* STParser::jumpStmt() {
  JumpStmtContext *_localctx = _tracker.createInstance<JumpStmtContext>(_ctx, getState());
  enterRule(_localctx, 14, STParser::RuleJumpStmt);
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
    setState(132);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13))) != 0))) {
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

//----------------- AssignStmtContext ------------------------------------------------------------------

STParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::PrefixExprContext* STParser::AssignStmtContext::prefixExpr() {
  return getRuleContext<STParser::PrefixExprContext>(0);
}

STParser::ExprContext* STParser::AssignStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

STParser::CallFuncStmtContext* STParser::AssignStmtContext::callFuncStmt() {
  return getRuleContext<STParser::CallFuncStmtContext>(0);
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
  enterRule(_localctx, 16, STParser::RuleAssignStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    prefixExpr();
    setState(135);
    match(STParser::T__14);
    setState(138);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(136);
      expr();
      break;
    }

    case 2: {
      setState(137);
      callFuncStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrefixExprContext ------------------------------------------------------------------

STParser::PrefixExprContext::PrefixExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::IdentContext* STParser::PrefixExprContext::ident() {
  return getRuleContext<STParser::IdentContext>(0);
}


size_t STParser::PrefixExprContext::getRuleIndex() const {
  return STParser::RulePrefixExpr;
}

void STParser::PrefixExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrefixExpr(this);
}

void STParser::PrefixExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrefixExpr(this);
}


antlrcpp::Any STParser::PrefixExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitPrefixExpr(this);
  else
    return visitor->visitChildren(this);
}

STParser::PrefixExprContext* STParser::prefixExpr() {
  PrefixExprContext *_localctx = _tracker.createInstance<PrefixExprContext>(_ctx, getState());
  enterRule(_localctx, 18, STParser::RulePrefixExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    ident(0);
   
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

STParser::OrExprContext* STParser::ExprContext::orExpr() {
  return getRuleContext<STParser::OrExprContext>(0);
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
  enterRule(_localctx, 20, STParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    orExpr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrExprContext ------------------------------------------------------------------

STParser::OrExprContext::OrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::AndExprContext* STParser::OrExprContext::andExpr() {
  return getRuleContext<STParser::AndExprContext>(0);
}

STParser::OrExprContext* STParser::OrExprContext::orExpr() {
  return getRuleContext<STParser::OrExprContext>(0);
}


size_t STParser::OrExprContext::getRuleIndex() const {
  return STParser::RuleOrExpr;
}

void STParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}

void STParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}


antlrcpp::Any STParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}


STParser::OrExprContext* STParser::orExpr() {
   return orExpr(0);
}

STParser::OrExprContext* STParser::orExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  STParser::OrExprContext *_localctx = _tracker.createInstance<OrExprContext>(_ctx, parentState);
  STParser::OrExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, STParser::RuleOrExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(145);
    andExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(152);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<OrExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleOrExpr);
        setState(147);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(148);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << STParser::T__4)
          | (1ULL << STParser::T__5)
          | (1ULL << STParser::T__15)
          | (1ULL << STParser::T__16))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(149);
        andExpr(0); 
      }
      setState(154);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AndExprContext ------------------------------------------------------------------

STParser::AndExprContext::AndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::EqualExprContext* STParser::AndExprContext::equalExpr() {
  return getRuleContext<STParser::EqualExprContext>(0);
}

STParser::AndExprContext* STParser::AndExprContext::andExpr() {
  return getRuleContext<STParser::AndExprContext>(0);
}


size_t STParser::AndExprContext::getRuleIndex() const {
  return STParser::RuleAndExpr;
}

void STParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}

void STParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}


antlrcpp::Any STParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}


STParser::AndExprContext* STParser::andExpr() {
   return andExpr(0);
}

STParser::AndExprContext* STParser::andExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  STParser::AndExprContext *_localctx = _tracker.createInstance<AndExprContext>(_ctx, parentState);
  STParser::AndExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, STParser::RuleAndExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(156);
    equalExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(163);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpr);
        setState(158);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(159);
        _la = _input->LA(1);
        if (!(_la == STParser::T__3

        || _la == STParser::T__17)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(160);
        equalExpr(0); 
      }
      setState(165);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualExprContext ------------------------------------------------------------------

STParser::EqualExprContext::EqualExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::RelationExprContext* STParser::EqualExprContext::relationExpr() {
  return getRuleContext<STParser::RelationExprContext>(0);
}

STParser::EqualExprContext* STParser::EqualExprContext::equalExpr() {
  return getRuleContext<STParser::EqualExprContext>(0);
}


size_t STParser::EqualExprContext::getRuleIndex() const {
  return STParser::RuleEqualExpr;
}

void STParser::EqualExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualExpr(this);
}

void STParser::EqualExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualExpr(this);
}


antlrcpp::Any STParser::EqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitEqualExpr(this);
  else
    return visitor->visitChildren(this);
}


STParser::EqualExprContext* STParser::equalExpr() {
   return equalExpr(0);
}

STParser::EqualExprContext* STParser::equalExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  STParser::EqualExprContext *_localctx = _tracker.createInstance<EqualExprContext>(_ctx, parentState);
  STParser::EqualExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, STParser::RuleEqualExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(167);
    relationExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(177);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(175);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualExpr);
          setState(169);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(170);
          match(STParser::T__18);
          setState(171);
          relationExpr(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualExpr);
          setState(172);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(173);
          _la = _input->LA(1);
          if (!(_la == STParser::T__19

          || _la == STParser::T__20)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(174);
          relationExpr(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(179);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationExprContext ------------------------------------------------------------------

STParser::RelationExprContext::RelationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::AddExprContext* STParser::RelationExprContext::addExpr() {
  return getRuleContext<STParser::AddExprContext>(0);
}

STParser::RelationExprContext* STParser::RelationExprContext::relationExpr() {
  return getRuleContext<STParser::RelationExprContext>(0);
}


size_t STParser::RelationExprContext::getRuleIndex() const {
  return STParser::RuleRelationExpr;
}

void STParser::RelationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationExpr(this);
}

void STParser::RelationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationExpr(this);
}


antlrcpp::Any STParser::RelationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitRelationExpr(this);
  else
    return visitor->visitChildren(this);
}


STParser::RelationExprContext* STParser::relationExpr() {
   return relationExpr(0);
}

STParser::RelationExprContext* STParser::relationExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  STParser::RelationExprContext *_localctx = _tracker.createInstance<RelationExprContext>(_ctx, parentState);
  STParser::RelationExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, STParser::RuleRelationExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(181);
    addExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(188);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelationExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelationExpr);
        setState(183);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(184);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << STParser::T__21)
          | (1ULL << STParser::T__22)
          | (1ULL << STParser::T__23)
          | (1ULL << STParser::T__24))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(185);
        addExpr(0); 
      }
      setState(190);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
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

STParser::MultipliExprContext* STParser::AddExprContext::multipliExpr() {
  return getRuleContext<STParser::MultipliExprContext>(0);
}

STParser::AddExprContext* STParser::AddExprContext::addExpr() {
  return getRuleContext<STParser::AddExprContext>(0);
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
   return addExpr(0);
}

STParser::AddExprContext* STParser::addExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  STParser::AddExprContext *_localctx = _tracker.createInstance<AddExprContext>(_ctx, parentState);
  STParser::AddExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, STParser::RuleAddExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(192);
    multipliExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(199);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExpr);
        setState(194);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(195);
        _la = _input->LA(1);
        if (!(_la == STParser::T__25

        || _la == STParser::T__26)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(196);
        multipliExpr(0); 
      }
      setState(201);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MultipliExprContext ------------------------------------------------------------------

STParser::MultipliExprContext::MultipliExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::UnaryExprContext* STParser::MultipliExprContext::unaryExpr() {
  return getRuleContext<STParser::UnaryExprContext>(0);
}

STParser::MultipliExprContext* STParser::MultipliExprContext::multipliExpr() {
  return getRuleContext<STParser::MultipliExprContext>(0);
}


size_t STParser::MultipliExprContext::getRuleIndex() const {
  return STParser::RuleMultipliExpr;
}

void STParser::MultipliExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultipliExpr(this);
}

void STParser::MultipliExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultipliExpr(this);
}


antlrcpp::Any STParser::MultipliExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitMultipliExpr(this);
  else
    return visitor->visitChildren(this);
}


STParser::MultipliExprContext* STParser::multipliExpr() {
   return multipliExpr(0);
}

STParser::MultipliExprContext* STParser::multipliExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  STParser::MultipliExprContext *_localctx = _tracker.createInstance<MultipliExprContext>(_ctx, parentState);
  STParser::MultipliExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, STParser::RuleMultipliExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(203);
    unaryExpr();
    _ctx->stop = _input->LT(-1);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MultipliExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultipliExpr);
        setState(205);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(206);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << STParser::T__27)
          | (1ULL << STParser::T__28)
          | (1ULL << STParser::T__29)
          | (1ULL << STParser::T__30))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(207);
        unaryExpr(); 
      }
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

STParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::PrimaryContext* STParser::UnaryExprContext::primary() {
  return getRuleContext<STParser::PrimaryContext>(0);
}


size_t STParser::UnaryExprContext::getRuleIndex() const {
  return STParser::RuleUnaryExpr;
}

void STParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}

void STParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}


antlrcpp::Any STParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

STParser::UnaryExprContext* STParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 34, STParser::RuleUnaryExpr);
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
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::T__26: {
        setState(214); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(213);
          match(STParser::T__26);
          setState(216); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == STParser::T__26);
        break;
      }

      case STParser::T__31: {
        setState(218);
        match(STParser::T__31);
        break;
      }

      case STParser::T__7: {
        setState(219);
        match(STParser::T__7);
        break;
      }

      case STParser::T__8:
      case STParser::NUMBER:
      case STParser::IDENT: {
        break;
      }

    default:
      break;
    }
    setState(222);
    primary();
   
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

STParser::ExprContext* STParser::PrimaryContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::PrimaryContext::IDENT() {
  return getToken(STParser::IDENT, 0);
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
  enterRule(_localctx, 36, STParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        match(STParser::T__8);
        setState(225);
        expr();
        setState(226);
        match(STParser::T__9);
        break;
      }

      case STParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(228);
        match(STParser::IDENT);
        break;
      }

      case STParser::NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(229);
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

STParser::ExprContext* STParser::IfStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

std::vector<STParser::Statement_listContext *> STParser::IfStmtContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::IfStmtContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
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
  enterRule(_localctx, 38, STParser::RuleIfStmt);
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
    setState(232);
    match(STParser::T__32);
    setState(233);
    expr();
    setState(234);
    match(STParser::T__33);
    setState(238);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7)
      | (1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13)
      | (1ULL << STParser::T__32)
      | (1ULL << STParser::T__36)
      | (1ULL << STParser::T__41)
      | (1ULL << STParser::T__46)
      | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
      setState(235);
      statement_list();
      setState(240);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::T__34) {
      setState(241);
      match(STParser::T__34);
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::T__2)
        | (1ULL << STParser::T__3)
        | (1ULL << STParser::T__4)
        | (1ULL << STParser::T__5)
        | (1ULL << STParser::T__6)
        | (1ULL << STParser::T__7)
        | (1ULL << STParser::T__10)
        | (1ULL << STParser::T__11)
        | (1ULL << STParser::T__12)
        | (1ULL << STParser::T__13)
        | (1ULL << STParser::T__32)
        | (1ULL << STParser::T__36)
        | (1ULL << STParser::T__41)
        | (1ULL << STParser::T__46)
        | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
        setState(242);
        statement_list();
        setState(247);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(250);
    match(STParser::T__35);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStmtContext ------------------------------------------------------------------

STParser::CaseStmtContext::CaseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::ExprContext* STParser::CaseStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

STParser::CaseListContext* STParser::CaseStmtContext::caseList() {
  return getRuleContext<STParser::CaseListContext>(0);
}

std::vector<STParser::Statement_listContext *> STParser::CaseStmtContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::CaseStmtContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::CaseStmtContext::getRuleIndex() const {
  return STParser::RuleCaseStmt;
}

void STParser::CaseStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStmt(this);
}

void STParser::CaseStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStmt(this);
}


antlrcpp::Any STParser::CaseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitCaseStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::CaseStmtContext* STParser::caseStmt() {
  CaseStmtContext *_localctx = _tracker.createInstance<CaseStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, STParser::RuleCaseStmt);
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
    setState(252);
    match(STParser::T__36);
    setState(253);
    expr();
    setState(254);
    match(STParser::T__37);
    setState(255);
    caseList();
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::T__34) {
      setState(256);
      match(STParser::T__34);
      setState(260);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::T__2)
        | (1ULL << STParser::T__3)
        | (1ULL << STParser::T__4)
        | (1ULL << STParser::T__5)
        | (1ULL << STParser::T__6)
        | (1ULL << STParser::T__7)
        | (1ULL << STParser::T__10)
        | (1ULL << STParser::T__11)
        | (1ULL << STParser::T__12)
        | (1ULL << STParser::T__13)
        | (1ULL << STParser::T__32)
        | (1ULL << STParser::T__36)
        | (1ULL << STParser::T__41)
        | (1ULL << STParser::T__46)
        | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
        setState(257);
        statement_list();
        setState(262);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(265);
    match(STParser::T__38);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseListContext ------------------------------------------------------------------

STParser::CaseListContext::CaseListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::CaseValuesContext *> STParser::CaseListContext::caseValues() {
  return getRuleContexts<STParser::CaseValuesContext>();
}

STParser::CaseValuesContext* STParser::CaseListContext::caseValues(size_t i) {
  return getRuleContext<STParser::CaseValuesContext>(i);
}

std::vector<STParser::Statement_listContext *> STParser::CaseListContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::CaseListContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::CaseListContext::getRuleIndex() const {
  return STParser::RuleCaseList;
}

void STParser::CaseListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseList(this);
}

void STParser::CaseListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseList(this);
}


antlrcpp::Any STParser::CaseListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitCaseList(this);
  else
    return visitor->visitChildren(this);
}

STParser::CaseListContext* STParser::caseList() {
  CaseListContext *_localctx = _tracker.createInstance<CaseListContext>(_ctx, getState());
  enterRule(_localctx, 42, STParser::RuleCaseList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(275); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(267);
      caseValues();
      setState(268);
      match(STParser::T__39);
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(269);
          statement_list(); 
        }
        setState(274);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      }
      setState(277); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__7)
      | (1ULL << STParser::T__8)
      | (1ULL << STParser::T__26)
      | (1ULL << STParser::T__31))) != 0) || _la == STParser::NUMBER

    || _la == STParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseValuesContext ------------------------------------------------------------------

STParser::CaseValuesContext::CaseValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::ExprContext *> STParser::CaseValuesContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::CaseValuesContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}


size_t STParser::CaseValuesContext::getRuleIndex() const {
  return STParser::RuleCaseValues;
}

void STParser::CaseValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseValues(this);
}

void STParser::CaseValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseValues(this);
}


antlrcpp::Any STParser::CaseValuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitCaseValues(this);
  else
    return visitor->visitChildren(this);
}

STParser::CaseValuesContext* STParser::caseValues() {
  CaseValuesContext *_localctx = _tracker.createInstance<CaseValuesContext>(_ctx, getState());
  enterRule(_localctx, 44, STParser::RuleCaseValues);
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
    setState(279);
    expr();
    setState(284);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::T__40) {
      setState(280);
      match(STParser::T__40);
      setState(281);
      expr();
      setState(286);
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

//----------------- ForStmtContext ------------------------------------------------------------------

STParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::AssignStmtContext* STParser::ForStmtContext::assignStmt() {
  return getRuleContext<STParser::AssignStmtContext>(0);
}

std::vector<STParser::ExprContext *> STParser::ForStmtContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}

std::vector<STParser::Statement_listContext *> STParser::ForStmtContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::ForStmtContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
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
  enterRule(_localctx, 46, STParser::RuleForStmt);
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
    setState(287);
    match(STParser::T__41);
    setState(288);
    assignStmt();
    setState(289);
    match(STParser::T__42);
    setState(290);
    expr();
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::T__43) {
      setState(291);
      match(STParser::T__43);
      setState(292);
      expr();
    }
    setState(295);
    match(STParser::T__44);
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7)
      | (1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13)
      | (1ULL << STParser::T__32)
      | (1ULL << STParser::T__36)
      | (1ULL << STParser::T__41)
      | (1ULL << STParser::T__46)
      | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
      setState(296);
      statement_list();
      setState(301);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(302);
    match(STParser::T__45);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

STParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::ExprContext* STParser::WhileStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

std::vector<STParser::Statement_listContext *> STParser::WhileStmtContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::WhileStmtContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::WhileStmtContext::getRuleIndex() const {
  return STParser::RuleWhileStmt;
}

void STParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}

void STParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}


antlrcpp::Any STParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::WhileStmtContext* STParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 48, STParser::RuleWhileStmt);
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
    setState(304);
    match(STParser::T__46);
    setState(305);
    expr();
    setState(306);
    match(STParser::T__44);
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7)
      | (1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13)
      | (1ULL << STParser::T__32)
      | (1ULL << STParser::T__36)
      | (1ULL << STParser::T__41)
      | (1ULL << STParser::T__46)
      | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
      setState(307);
      statement_list();
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(313);
    match(STParser::T__47);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RepeatStmtContext ------------------------------------------------------------------

STParser::RepeatStmtContext::RepeatStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::ExprContext* STParser::RepeatStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

std::vector<STParser::Statement_listContext *> STParser::RepeatStmtContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::RepeatStmtContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::RepeatStmtContext::getRuleIndex() const {
  return STParser::RuleRepeatStmt;
}

void STParser::RepeatStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRepeatStmt(this);
}

void STParser::RepeatStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRepeatStmt(this);
}


antlrcpp::Any STParser::RepeatStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitRepeatStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::RepeatStmtContext* STParser::repeatStmt() {
  RepeatStmtContext *_localctx = _tracker.createInstance<RepeatStmtContext>(_ctx, getState());
  enterRule(_localctx, 50, STParser::RuleRepeatStmt);
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
    setState(315);
    match(STParser::T__48);
    setState(319);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7)
      | (1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13)
      | (1ULL << STParser::T__32)
      | (1ULL << STParser::T__36)
      | (1ULL << STParser::T__41)
      | (1ULL << STParser::T__46)
      | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
      setState(316);
      statement_list();
      setState(321);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(322);
    match(STParser::T__49);
    setState(323);
    expr();
    setState(324);
    match(STParser::T__50);
   
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
  enterRule(_localctx, 52, STParser::RuleType);
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
    setState(326);
    _la = _input->LA(1);
    if (!(((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (STParser::T__51 - 52))
      | (1ULL << (STParser::T__52 - 52))
      | (1ULL << (STParser::T__53 - 52))
      | (1ULL << (STParser::T__54 - 52))
      | (1ULL << (STParser::T__55 - 52))
      | (1ULL << (STParser::T__56 - 52))
      | (1ULL << (STParser::T__57 - 52))
      | (1ULL << (STParser::T__58 - 52))
      | (1ULL << (STParser::T__59 - 52))
      | (1ULL << (STParser::T__60 - 52))
      | (1ULL << (STParser::T__61 - 52))
      | (1ULL << (STParser::T__62 - 52))
      | (1ULL << (STParser::T__63 - 52))
      | (1ULL << (STParser::T__64 - 52))
      | (1ULL << (STParser::T__65 - 52)))) != 0))) {
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

//----------------- FuncParamsContext ------------------------------------------------------------------

STParser::FuncParamsContext::FuncParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::FuncParamsContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

std::vector<STParser::ExprContext *> STParser::FuncParamsContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::FuncParamsContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}

std::vector<STParser::FuncParamsContext *> STParser::FuncParamsContext::funcParams() {
  return getRuleContexts<STParser::FuncParamsContext>();
}

STParser::FuncParamsContext* STParser::FuncParamsContext::funcParams(size_t i) {
  return getRuleContext<STParser::FuncParamsContext>(i);
}

STParser::IdentContext* STParser::FuncParamsContext::ident() {
  return getRuleContext<STParser::IdentContext>(0);
}


size_t STParser::FuncParamsContext::getRuleIndex() const {
  return STParser::RuleFuncParams;
}

void STParser::FuncParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncParams(this);
}

void STParser::FuncParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncParams(this);
}


antlrcpp::Any STParser::FuncParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitFuncParams(this);
  else
    return visitor->visitChildren(this);
}

STParser::FuncParamsContext* STParser::funcParams() {
  FuncParamsContext *_localctx = _tracker.createInstance<FuncParamsContext>(_ctx, getState());
  enterRule(_localctx, 54, STParser::RuleFuncParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(355);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(328);
      match(STParser::IDENT);
      setState(338);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case STParser::T__14: {
          setState(329);
          match(STParser::T__14);
          setState(331);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << STParser::T__7)
            | (1ULL << STParser::T__8)
            | (1ULL << STParser::T__26)
            | (1ULL << STParser::T__31))) != 0) || _la == STParser::NUMBER

          || _la == STParser::IDENT) {
            setState(330);
            expr();
          }
          break;
        }

        case STParser::T__66: {
          setState(333);
          match(STParser::T__66);
          setState(335);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == STParser::IDENT) {
            setState(334);
            ident(0);
          }
          break;
        }

        case STParser::T__7:
        case STParser::T__8:
        case STParser::T__26:
        case STParser::T__31:
        case STParser::NUMBER:
        case STParser::IDENT: {
          setState(337);
          expr();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(344);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(340);
          match(STParser::T__40);
          setState(341);
          funcParams(); 
        }
        setState(346);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(347);
      expr();
      setState(352);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(348);
          match(STParser::T__40);
          setState(349);
          expr(); 
        }
        setState(354);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

STParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t STParser::IdentContext::getRuleIndex() const {
  return STParser::RuleIdent;
}

void STParser::IdentContext::copyFrom(IdentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayContext ------------------------------------------------------------------

tree::TerminalNode* STParser::ArrayContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

std::vector<STParser::ExprContext *> STParser::ArrayContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::ArrayContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}

STParser::ArrayContext::ArrayContext(IdentContext *ctx) { copyFrom(ctx); }

void STParser::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}
void STParser::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

antlrcpp::Any STParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentiContext ------------------------------------------------------------------

tree::TerminalNode* STParser::IdentiContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::IdentiContext::IdentiContext(IdentContext *ctx) { copyFrom(ctx); }

void STParser::IdentiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdenti(this);
}
void STParser::IdentiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdenti(this);
}

antlrcpp::Any STParser::IdentiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitIdenti(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructContext ------------------------------------------------------------------

std::vector<STParser::IdentContext *> STParser::StructContext::ident() {
  return getRuleContexts<STParser::IdentContext>();
}

STParser::IdentContext* STParser::StructContext::ident(size_t i) {
  return getRuleContext<STParser::IdentContext>(i);
}

STParser::StructContext::StructContext(IdentContext *ctx) { copyFrom(ctx); }

void STParser::StructContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct(this);
}
void STParser::StructContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct(this);
}

antlrcpp::Any STParser::StructContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitStruct(this);
  else
    return visitor->visitChildren(this);
}

STParser::IdentContext* STParser::ident() {
   return ident(0);
}

STParser::IdentContext* STParser::ident(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  STParser::IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, parentState);
  STParser::IdentContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, STParser::RuleIdent, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(375);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<IdentiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(358);
      match(STParser::IDENT);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(359);
      match(STParser::IDENT);
      setState(371); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(360);
                match(STParser::T__68);
                setState(361);
                expr();
                setState(366);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == STParser::T__40) {
                  setState(362);
                  match(STParser::T__40);
                  setState(363);
                  expr();
                  setState(368);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(369);
                match(STParser::T__69);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(373); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(382);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<StructContext>(_tracker.createInstance<IdentContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleIdent);
        setState(377);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(378);
        match(STParser::T__67);
        setState(379);
        ident(3); 
      }
      setState(384);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DeclarationStmtContext ------------------------------------------------------------------

STParser::DeclarationStmtContext::DeclarationStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::VarDeclarationBlockContext* STParser::DeclarationStmtContext::varDeclarationBlock() {
  return getRuleContext<STParser::VarDeclarationBlockContext>(0);
}

STParser::VarDeclarationContext* STParser::DeclarationStmtContext::varDeclaration() {
  return getRuleContext<STParser::VarDeclarationContext>(0);
}


size_t STParser::DeclarationStmtContext::getRuleIndex() const {
  return STParser::RuleDeclarationStmt;
}

void STParser::DeclarationStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationStmt(this);
}

void STParser::DeclarationStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationStmt(this);
}


antlrcpp::Any STParser::DeclarationStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitDeclarationStmt(this);
  else
    return visitor->visitChildren(this);
}

STParser::DeclarationStmtContext* STParser::declarationStmt() {
  DeclarationStmtContext *_localctx = _tracker.createInstance<DeclarationStmtContext>(_ctx, getState());
  enterRule(_localctx, 58, STParser::RuleDeclarationStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(387);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::T__70:
      case STParser::T__71:
      case STParser::T__72:
      case STParser::T__73:
      case STParser::T__74: {
        enterOuterAlt(_localctx, 1);
        setState(385);
        varDeclarationBlock();
        break;
      }

      case STParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(386);
        varDeclaration();
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

//----------------- VarDeclarationBlockContext ------------------------------------------------------------------

STParser::VarDeclarationBlockContext::VarDeclarationBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::VarDeclarationContext *> STParser::VarDeclarationBlockContext::varDeclaration() {
  return getRuleContexts<STParser::VarDeclarationContext>();
}

STParser::VarDeclarationContext* STParser::VarDeclarationBlockContext::varDeclaration(size_t i) {
  return getRuleContext<STParser::VarDeclarationContext>(i);
}


size_t STParser::VarDeclarationBlockContext::getRuleIndex() const {
  return STParser::RuleVarDeclarationBlock;
}

void STParser::VarDeclarationBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclarationBlock(this);
}

void STParser::VarDeclarationBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclarationBlock(this);
}


antlrcpp::Any STParser::VarDeclarationBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitVarDeclarationBlock(this);
  else
    return visitor->visitChildren(this);
}

STParser::VarDeclarationBlockContext* STParser::varDeclarationBlock() {
  VarDeclarationBlockContext *_localctx = _tracker.createInstance<VarDeclarationBlockContext>(_ctx, getState());
  enterRule(_localctx, 60, STParser::RuleVarDeclarationBlock);
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
    setState(389);
    _la = _input->LA(1);
    if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (STParser::T__70 - 71))
      | (1ULL << (STParser::T__71 - 71))
      | (1ULL << (STParser::T__72 - 71))
      | (1ULL << (STParser::T__73 - 71))
      | (1ULL << (STParser::T__74 - 71)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(393);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::IDENT) {
      setState(390);
      varDeclaration();
      setState(395);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(396);
    match(STParser::T__75);
   
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

tree::TerminalNode* STParser::VarDeclarationContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::TypeContext* STParser::VarDeclarationContext::type() {
  return getRuleContext<STParser::TypeContext>(0);
}

tree::TerminalNode* STParser::VarDeclarationContext::NUMBER() {
  return getToken(STParser::NUMBER, 0);
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
  enterRule(_localctx, 62, STParser::RuleVarDeclaration);
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
    setState(398);
    match(STParser::IDENT);
    setState(399);
    match(STParser::T__39);
    setState(400);
    type();
    setState(403);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::T__14) {
      setState(401);
      match(STParser::T__14);
      setState(402);
      match(STParser::NUMBER);
    }
    setState(405);
    match(STParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

STParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::FunctionDeclContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::TypeContext* STParser::FunctionDeclContext::type() {
  return getRuleContext<STParser::TypeContext>(0);
}

std::vector<STParser::VarDeclarationBlockContext *> STParser::FunctionDeclContext::varDeclarationBlock() {
  return getRuleContexts<STParser::VarDeclarationBlockContext>();
}

STParser::VarDeclarationBlockContext* STParser::FunctionDeclContext::varDeclarationBlock(size_t i) {
  return getRuleContext<STParser::VarDeclarationBlockContext>(i);
}

std::vector<STParser::Statement_listContext *> STParser::FunctionDeclContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::FunctionDeclContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::FunctionDeclContext::getRuleIndex() const {
  return STParser::RuleFunctionDecl;
}

void STParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void STParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}


antlrcpp::Any STParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

STParser::FunctionDeclContext* STParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 64, STParser::RuleFunctionDecl);
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
    setState(407);
    match(STParser::T__76);
    setState(408);
    match(STParser::IDENT);
    setState(409);
    match(STParser::T__39);
    setState(410);
    type();
    setState(414);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (STParser::T__70 - 71))
      | (1ULL << (STParser::T__71 - 71))
      | (1ULL << (STParser::T__72 - 71))
      | (1ULL << (STParser::T__73 - 71))
      | (1ULL << (STParser::T__74 - 71)))) != 0)) {
      setState(411);
      varDeclarationBlock();
      setState(416);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(420);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7)
      | (1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13)
      | (1ULL << STParser::T__32)
      | (1ULL << STParser::T__36)
      | (1ULL << STParser::T__41)
      | (1ULL << STParser::T__46)
      | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
      setState(417);
      statement_list();
      setState(422);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(423);
    match(STParser::T__77);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBlockDeclContext ------------------------------------------------------------------

STParser::FunctionBlockDeclContext::FunctionBlockDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::FunctionBlockDeclContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

std::vector<STParser::VarDeclarationBlockContext *> STParser::FunctionBlockDeclContext::varDeclarationBlock() {
  return getRuleContexts<STParser::VarDeclarationBlockContext>();
}

STParser::VarDeclarationBlockContext* STParser::FunctionBlockDeclContext::varDeclarationBlock(size_t i) {
  return getRuleContext<STParser::VarDeclarationBlockContext>(i);
}

std::vector<STParser::Statement_listContext *> STParser::FunctionBlockDeclContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::FunctionBlockDeclContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::FunctionBlockDeclContext::getRuleIndex() const {
  return STParser::RuleFunctionBlockDecl;
}

void STParser::FunctionBlockDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionBlockDecl(this);
}

void STParser::FunctionBlockDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionBlockDecl(this);
}


antlrcpp::Any STParser::FunctionBlockDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitFunctionBlockDecl(this);
  else
    return visitor->visitChildren(this);
}

STParser::FunctionBlockDeclContext* STParser::functionBlockDecl() {
  FunctionBlockDeclContext *_localctx = _tracker.createInstance<FunctionBlockDeclContext>(_ctx, getState());
  enterRule(_localctx, 66, STParser::RuleFunctionBlockDecl);
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
    setState(425);
    match(STParser::T__78);
    setState(426);
    match(STParser::IDENT);
    setState(430);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (STParser::T__70 - 71))
      | (1ULL << (STParser::T__71 - 71))
      | (1ULL << (STParser::T__72 - 71))
      | (1ULL << (STParser::T__73 - 71))
      | (1ULL << (STParser::T__74 - 71)))) != 0)) {
      setState(427);
      varDeclarationBlock();
      setState(432);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(436);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__2)
      | (1ULL << STParser::T__3)
      | (1ULL << STParser::T__4)
      | (1ULL << STParser::T__5)
      | (1ULL << STParser::T__6)
      | (1ULL << STParser::T__7)
      | (1ULL << STParser::T__10)
      | (1ULL << STParser::T__11)
      | (1ULL << STParser::T__12)
      | (1ULL << STParser::T__13)
      | (1ULL << STParser::T__32)
      | (1ULL << STParser::T__36)
      | (1ULL << STParser::T__41)
      | (1ULL << STParser::T__46)
      | (1ULL << STParser::T__48))) != 0) || _la == STParser::IDENT) {
      setState(433);
      statement_list();
      setState(438);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(439);
    match(STParser::T__79);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool STParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return orExprSempred(dynamic_cast<OrExprContext *>(context), predicateIndex);
    case 12: return andExprSempred(dynamic_cast<AndExprContext *>(context), predicateIndex);
    case 13: return equalExprSempred(dynamic_cast<EqualExprContext *>(context), predicateIndex);
    case 14: return relationExprSempred(dynamic_cast<RelationExprContext *>(context), predicateIndex);
    case 15: return addExprSempred(dynamic_cast<AddExprContext *>(context), predicateIndex);
    case 16: return multipliExprSempred(dynamic_cast<MultipliExprContext *>(context), predicateIndex);
    case 28: return identSempred(dynamic_cast<IdentContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool STParser::orExprSempred(OrExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool STParser::andExprSempred(AndExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool STParser::equalExprSempred(EqualExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool STParser::relationExprSempred(RelationExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool STParser::addExprSempred(AddExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool STParser::multipliExprSempred(MultipliExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool STParser::identSempred(IdentContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> STParser::_decisionToDFA;
atn::PredictionContextCache STParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN STParser::_atn;
std::vector<uint16_t> STParser::_serializedATN;

std::vector<std::string> STParser::_ruleNames = {
  "startpoint", "program_list", "programDecl", "statement_list", "selectStmt", 
  "iterationStmt", "callFuncStmt", "jumpStmt", "assignStmt", "prefixExpr", 
  "expr", "orExpr", "andExpr", "equalExpr", "relationExpr", "addExpr", "multipliExpr", 
  "unaryExpr", "primary", "ifStmt", "caseStmt", "caseList", "caseValues", 
  "forStmt", "whileStmt", "repeatStmt", "type", "funcParams", "ident", "declarationStmt", 
  "varDeclarationBlock", "varDeclaration", "functionDecl", "functionBlockDecl"
};

std::vector<std::string> STParser::_literalNames = {
  "", "'PROGRAM'", "'END_PROGRAM'", "';'", "'AND'", "'OR'", "'XOR'", "'MOD'", 
  "'NOT'", "'('", "')'", "'BREAK'", "'RETURN'", "'CONTINUE'", "'EXIT'", 
  "':='", "'|'", "'^'", "'&'", "'='", "'!='", "'<>'", "'>'", "'>='", "'<'", 
  "'<='", "'+'", "'-'", "'*'", "'/'", "'**'", "'%'", "'!'", "'IF'", "'THEN'", 
  "'ELSE'", "'END_IF'", "'CASE'", "'OF'", "'END_CASE'", "':'", "','", "'FOR'", 
  "'TO'", "'BY'", "'DO'", "'END_FOR'", "'WHILE'", "'END_WHILE'", "'REPEAT'", 
  "'UNTIL'", "'END_REPEAT'", "'INT'", "'SINT'", "'DINT'", "'LINT'", "'USINT'", 
  "'UINT'", "'UDINT'", "'ULINT'", "'REAL'", "'LREAL'", "'BOOL'", "'BYTE'", 
  "'WORD'", "'DWORD'", "'LWORD'", "'=>'", "'.'", "'['", "']'", "'VAR'", 
  "'VAR_INPUT'", "'VAR_OUTPUT'", "'VAR_IN_OUT'", "'VAR_TEMP'", "'END_VAR'", 
  "'FUNCTION'", "'END_FUNCTION'", "'FUNCTION_BLOCK'", "'END_FUNCTION_BLOCK'"
};

std::vector<std::string> STParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "NUMBER", "IDENT", "WS"
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
       0x3, 0x55, 0x1bc, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x3, 0x2, 0x7, 0x2, 0x48, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
       0x4b, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x5, 0x3, 0x52, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0x57, 0xa, 0x4, 0x3, 0x4, 0x7, 0x4, 0x5a, 0xa, 0x4, 0xc, 0x4, 0xe, 
       0x4, 0x5d, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x5, 0x5, 0x62, 
       0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x66, 0xa, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x5, 0x5, 0x6a, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
       0x6e, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x72, 0xa, 0x5, 0x3, 
       0x5, 0x5, 0x5, 0x75, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x79, 
       0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7e, 0xa, 0x7, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x83, 0xa, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x5, 0xa, 0x8d, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x7, 0xd, 0x99, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x9c, 0xb, 0xd, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 
       0xa4, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xa7, 0xb, 0xe, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x7, 0xf, 0xb2, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xb5, 0xb, 
       0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x7, 0x10, 0xbd, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xc0, 0xb, 
       0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x7, 0x11, 0xc8, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xcb, 0xb, 
       0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x7, 0x12, 0xd3, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xd6, 0xb, 
       0x12, 0x3, 0x13, 0x6, 0x13, 0xd9, 0xa, 0x13, 0xd, 0x13, 0xe, 0x13, 
       0xda, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xdf, 0xa, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
       0x3, 0x14, 0x5, 0x14, 0xe9, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x7, 0x15, 0xef, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
       0xf2, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xf6, 0xa, 0x15, 
       0xc, 0x15, 0xe, 0x15, 0xf9, 0xb, 0x15, 0x5, 0x15, 0xfb, 0xa, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x105, 0xa, 0x16, 0xc, 0x16, 0xe, 
       0x16, 0x108, 0xb, 0x16, 0x5, 0x16, 0x10a, 0xa, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x111, 0xa, 0x17, 
       0xc, 0x17, 0xe, 0x17, 0x114, 0xb, 0x17, 0x6, 0x17, 0x116, 0xa, 0x17, 
       0xd, 0x17, 0xe, 0x17, 0x117, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 
       0x18, 0x11d, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x120, 0xb, 0x18, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 
       0x19, 0x128, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x12c, 0xa, 
       0x19, 0xc, 0x19, 0xe, 0x19, 0x12f, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x137, 0xa, 
       0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x13a, 0xb, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x140, 0xa, 0x1b, 0xc, 0x1b, 0xe, 
       0x1b, 0x143, 0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
       0x14e, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x152, 0xa, 0x1d, 
       0x3, 0x1d, 0x5, 0x1d, 0x155, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 
       0x1d, 0x159, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x15c, 0xb, 0x1d, 0x3, 
       0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x161, 0xa, 0x1d, 0xc, 0x1d, 
       0xe, 0x1d, 0x164, 0xb, 0x1d, 0x5, 0x1d, 0x166, 0xa, 0x1d, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x7, 0x1e, 0x16f, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x172, 0xb, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x6, 0x1e, 0x176, 0xa, 0x1e, 0xd, 0x1e, 0xe, 
       0x1e, 0x177, 0x5, 0x1e, 0x17a, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
       0x1e, 0x7, 0x1e, 0x17f, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x182, 0xb, 
       0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x186, 0xa, 0x1f, 0x3, 0x20, 
       0x3, 0x20, 0x7, 0x20, 0x18a, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x18d, 
       0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x196, 0xa, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 
       0x22, 0x19f, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x1a2, 0xb, 0x22, 0x3, 
       0x22, 0x7, 0x22, 0x1a5, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x1a8, 0xb, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 
       0x23, 0x1af, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x1b2, 0xb, 0x23, 0x3, 
       0x23, 0x7, 0x23, 0x1b5, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x1b8, 0xb, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x2, 0x9, 0x18, 0x1a, 0x1c, 
       0x1e, 0x20, 0x22, 0x3a, 0x24, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
       0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
       0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
       0x3c, 0x3e, 0x40, 0x42, 0x44, 0x2, 0xc, 0x4, 0x2, 0x6, 0xa, 0x54, 
       0x54, 0x3, 0x2, 0xd, 0x10, 0x4, 0x2, 0x7, 0x8, 0x12, 0x13, 0x4, 0x2, 
       0x6, 0x6, 0x14, 0x14, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x18, 0x1b, 
       0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x36, 0x44, 
       0x3, 0x2, 0x49, 0x4d, 0x2, 0x1d7, 0x2, 0x49, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0x51, 0x3, 0x2, 0x2, 0x2, 0x6, 0x53, 0x3, 0x2, 0x2, 0x2, 0x8, 
       0x74, 0x3, 0x2, 0x2, 0x2, 0xa, 0x78, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7d, 
       0x3, 0x2, 0x2, 0x2, 0xe, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x86, 0x3, 
       0x2, 0x2, 0x2, 0x12, 0x88, 0x3, 0x2, 0x2, 0x2, 0x14, 0x8e, 0x3, 0x2, 
       0x2, 0x2, 0x16, 0x90, 0x3, 0x2, 0x2, 0x2, 0x18, 0x92, 0x3, 0x2, 0x2, 
       0x2, 0x1a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa8, 0x3, 0x2, 0x2, 0x2, 
       0x1e, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x22, 
       0xcc, 0x3, 0x2, 0x2, 0x2, 0x24, 0xde, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe8, 
       0x3, 0x2, 0x2, 0x2, 0x28, 0xea, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xfe, 0x3, 
       0x2, 0x2, 0x2, 0x2c, 0x115, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x119, 0x3, 
       0x2, 0x2, 0x2, 0x30, 0x121, 0x3, 0x2, 0x2, 0x2, 0x32, 0x132, 0x3, 
       0x2, 0x2, 0x2, 0x34, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x36, 0x148, 0x3, 
       0x2, 0x2, 0x2, 0x38, 0x165, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x179, 0x3, 
       0x2, 0x2, 0x2, 0x3c, 0x185, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x187, 0x3, 
       0x2, 0x2, 0x2, 0x40, 0x190, 0x3, 0x2, 0x2, 0x2, 0x42, 0x199, 0x3, 
       0x2, 0x2, 0x2, 0x44, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x5, 
       0x4, 0x3, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 
       0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 
       0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 
       0x4c, 0x4d, 0x7, 0x2, 0x2, 0x3, 0x4d, 0x3, 0x3, 0x2, 0x2, 0x2, 0x4e, 
       0x52, 0x5, 0x6, 0x4, 0x2, 0x4f, 0x52, 0x5, 0x42, 0x22, 0x2, 0x50, 
       0x52, 0x5, 0x44, 0x23, 0x2, 0x51, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x5, 
       0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x3, 0x2, 0x2, 0x54, 0x56, 0x7, 
       0x54, 0x2, 0x2, 0x55, 0x57, 0x5, 0x3c, 0x1f, 0x2, 0x56, 0x55, 0x3, 
       0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5b, 0x3, 0x2, 
       0x2, 0x2, 0x58, 0x5a, 0x5, 0x8, 0x5, 0x2, 0x59, 0x58, 0x3, 0x2, 0x2, 
       0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 
       0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x4, 0x2, 0x2, 0x5f, 0x7, 
       0x3, 0x2, 0x2, 0x2, 0x60, 0x62, 0x5, 0x12, 0xa, 0x2, 0x61, 0x60, 
       0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 
       0x2, 0x2, 0x2, 0x63, 0x75, 0x7, 0x5, 0x2, 0x2, 0x64, 0x66, 0x5, 0xa, 
       0x6, 0x2, 0x65, 0x64, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 
       0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x75, 0x7, 0x5, 0x2, 0x2, 
       0x68, 0x6a, 0x5, 0xc, 0x7, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x69, 
       0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x75, 
       0x7, 0x5, 0x2, 0x2, 0x6c, 0x6e, 0x5, 0xe, 0x8, 0x2, 0x6d, 0x6c, 0x3, 
       0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 
       0x2, 0x2, 0x6f, 0x75, 0x7, 0x5, 0x2, 0x2, 0x70, 0x72, 0x5, 0x10, 
       0x9, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 
       0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x7, 0x5, 0x2, 0x2, 
       0x74, 0x61, 0x3, 0x2, 0x2, 0x2, 0x74, 0x65, 0x3, 0x2, 0x2, 0x2, 0x74, 
       0x69, 0x3, 0x2, 0x2, 0x2, 0x74, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x74, 0x71, 
       0x3, 0x2, 0x2, 0x2, 0x75, 0x9, 0x3, 0x2, 0x2, 0x2, 0x76, 0x79, 0x5, 
       0x28, 0x15, 0x2, 0x77, 0x79, 0x5, 0x2a, 0x16, 0x2, 0x78, 0x76, 0x3, 
       0x2, 0x2, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0x7a, 0x7e, 0x5, 0x32, 0x1a, 0x2, 0x7b, 0x7e, 0x5, 0x30, 
       0x19, 0x2, 0x7c, 0x7e, 0x5, 0x34, 0x1b, 0x2, 0x7d, 0x7a, 0x3, 0x2, 
       0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 
       0x2, 0x7e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x9, 0x2, 0x2, 0x2, 
       0x80, 0x82, 0x7, 0xb, 0x2, 0x2, 0x81, 0x83, 0x5, 0x38, 0x1d, 0x2, 
       0x82, 0x81, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 
       0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0xc, 0x2, 0x2, 0x85, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x9, 0x3, 0x2, 0x2, 0x87, 0x11, 0x3, 
       0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x14, 0xb, 0x2, 0x89, 0x8c, 0x7, 
       0x11, 0x2, 0x2, 0x8a, 0x8d, 0x5, 0x16, 0xc, 0x2, 0x8b, 0x8d, 0x5, 
       0xe, 0x8, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8b, 0x3, 0x2, 
       0x2, 0x2, 0x8d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x3a, 
       0x1e, 0x2, 0x8f, 0x15, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x5, 0x18, 
       0xd, 0x2, 0x91, 0x17, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x8, 0xd, 0x1, 
       0x2, 0x93, 0x94, 0x5, 0x1a, 0xe, 0x2, 0x94, 0x9a, 0x3, 0x2, 0x2, 
       0x2, 0x95, 0x96, 0xc, 0x3, 0x2, 0x2, 0x96, 0x97, 0x9, 0x4, 0x2, 0x2, 
       0x97, 0x99, 0x5, 0x1a, 0xe, 0x2, 0x98, 0x95, 0x3, 0x2, 0x2, 0x2, 
       0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 
       0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x8, 0xe, 0x1, 0x2, 0x9e, 0x9f, 0x5, 
       0x1c, 0xf, 0x2, 0x9f, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0xc, 
       0x3, 0x2, 0x2, 0xa1, 0xa2, 0x9, 0x5, 0x2, 0x2, 0xa2, 0xa4, 0x5, 0x1c, 
       0xf, 0x2, 0xa3, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 
       0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 
       0xa6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa8, 
       0xa9, 0x8, 0xf, 0x1, 0x2, 0xa9, 0xaa, 0x5, 0x1e, 0x10, 0x2, 0xaa, 
       0xb3, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0xc, 0x4, 0x2, 0x2, 0xac, 0xad, 
       0x7, 0x15, 0x2, 0x2, 0xad, 0xb2, 0x5, 0x1e, 0x10, 0x2, 0xae, 0xaf, 
       0xc, 0x3, 0x2, 0x2, 0xaf, 0xb0, 0x9, 0x6, 0x2, 0x2, 0xb0, 0xb2, 0x5, 
       0x1e, 0x10, 0x2, 0xb1, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xae, 0x3, 
       0x2, 0x2, 0x2, 0xb2, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 
       0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x1d, 0x3, 0x2, 0x2, 
       0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x8, 0x10, 0x1, 
       0x2, 0xb7, 0xb8, 0x5, 0x20, 0x11, 0x2, 0xb8, 0xbe, 0x3, 0x2, 0x2, 
       0x2, 0xb9, 0xba, 0xc, 0x3, 0x2, 0x2, 0xba, 0xbb, 0x9, 0x7, 0x2, 0x2, 
       0xbb, 0xbd, 0x5, 0x20, 0x11, 0x2, 0xbc, 0xb9, 0x3, 0x2, 0x2, 0x2, 
       0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 
       0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 
       0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x8, 0x11, 0x1, 0x2, 0xc2, 0xc3, 
       0x5, 0x22, 0x12, 0x2, 0xc3, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 
       0xc, 0x3, 0x2, 0x2, 0xc5, 0xc6, 0x9, 0x8, 0x2, 0x2, 0xc6, 0xc8, 0x5, 
       0x22, 0x12, 0x2, 0xc7, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcb, 0x3, 
       0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 
       0x2, 0x2, 0xca, 0x21, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 
       0x2, 0xcc, 0xcd, 0x8, 0x12, 0x1, 0x2, 0xcd, 0xce, 0x5, 0x24, 0x13, 
       0x2, 0xce, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0xc, 0x3, 0x2, 0x2, 
       0xd0, 0xd1, 0x9, 0x9, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x24, 0x13, 0x2, 
       0xd2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 
       0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 0x7, 
       0x1d, 0x2, 0x2, 0xd8, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 
       0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 
       0x2, 0x2, 0xdb, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdf, 0x7, 0x22, 
       0x2, 0x2, 0xdd, 0xdf, 0x7, 0xa, 0x2, 0x2, 0xde, 0xd8, 0x3, 0x2, 0x2, 
       0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 
       0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 
       0xe1, 0x5, 0x26, 0x14, 0x2, 0xe1, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe2, 
       0xe3, 0x7, 0xb, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x16, 0xc, 0x2, 0xe4, 
       0xe5, 0x7, 0xc, 0x2, 0x2, 0xe5, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 
       0x7, 0x54, 0x2, 0x2, 0xe7, 0xe9, 0x7, 0x53, 0x2, 0x2, 0xe8, 0xe2, 
       0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe7, 0x3, 
       0x2, 0x2, 0x2, 0xe9, 0x27, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x23, 
       0x2, 0x2, 0xeb, 0xec, 0x5, 0x16, 0xc, 0x2, 0xec, 0xf0, 0x7, 0x24, 
       0x2, 0x2, 0xed, 0xef, 0x5, 0x8, 0x5, 0x2, 0xee, 0xed, 0x3, 0x2, 0x2, 
       0x2, 0xef, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 
       0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf2, 
       0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf7, 0x7, 0x25, 0x2, 0x2, 0xf4, 
       0xf6, 0x5, 0x8, 0x5, 0x2, 0xf5, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf9, 
       0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 
       0x2, 0x2, 0x2, 0xf8, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 
       0x2, 0x2, 0xfa, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 
       0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x26, 0x2, 
       0x2, 0xfd, 0x29, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x27, 0x2, 
       0x2, 0xff, 0x100, 0x5, 0x16, 0xc, 0x2, 0x100, 0x101, 0x7, 0x28, 0x2, 
       0x2, 0x101, 0x109, 0x5, 0x2c, 0x17, 0x2, 0x102, 0x106, 0x7, 0x25, 
       0x2, 0x2, 0x103, 0x105, 0x5, 0x8, 0x5, 0x2, 0x104, 0x103, 0x3, 0x2, 
       0x2, 0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10a, 0x3, 0x2, 
       0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x109, 0x102, 0x3, 0x2, 
       0x2, 0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 
       0x2, 0x2, 0x10b, 0x10c, 0x7, 0x29, 0x2, 0x2, 0x10c, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0x10d, 0x10e, 0x5, 0x2e, 0x18, 0x2, 0x10e, 0x112, 0x7, 
       0x2a, 0x2, 0x2, 0x10f, 0x111, 0x5, 0x8, 0x5, 0x2, 0x110, 0x10f, 0x3, 
       0x2, 0x2, 0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 
       0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x116, 0x3, 
       0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10d, 0x3, 
       0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 0x3, 
       0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x2d, 0x3, 
       0x2, 0x2, 0x2, 0x119, 0x11e, 0x5, 0x16, 0xc, 0x2, 0x11a, 0x11b, 0x7, 
       0x2b, 0x2, 0x2, 0x11b, 0x11d, 0x5, 0x16, 0xc, 0x2, 0x11c, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11c, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 
       0x7, 0x2c, 0x2, 0x2, 0x122, 0x123, 0x5, 0x12, 0xa, 0x2, 0x123, 0x124, 
       0x7, 0x2d, 0x2, 0x2, 0x124, 0x127, 0x5, 0x16, 0xc, 0x2, 0x125, 0x126, 
       0x7, 0x2e, 0x2, 0x2, 0x126, 0x128, 0x5, 0x16, 0xc, 0x2, 0x127, 0x125, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 
       0x3, 0x2, 0x2, 0x2, 0x129, 0x12d, 0x7, 0x2f, 0x2, 0x2, 0x12a, 0x12c, 
       0x5, 0x8, 0x5, 0x2, 0x12b, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x30, 0x2, 0x2, 0x131, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0x31, 0x2, 0x2, 0x133, 0x134, 
       0x5, 0x16, 0xc, 0x2, 0x134, 0x138, 0x7, 0x2f, 0x2, 0x2, 0x135, 0x137, 
       0x5, 0x8, 0x5, 0x2, 0x136, 0x135, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x32, 0x2, 0x2, 0x13c, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x141, 0x7, 0x33, 0x2, 0x2, 0x13e, 0x140, 
       0x5, 0x8, 0x5, 0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 
       0x3, 0x2, 0x2, 0x2, 0x142, 0x144, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 
       0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x34, 0x2, 0x2, 0x145, 0x146, 
       0x5, 0x16, 0xc, 0x2, 0x146, 0x147, 0x7, 0x35, 0x2, 0x2, 0x147, 0x35, 
       0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x9, 0xa, 0x2, 0x2, 0x149, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x154, 0x7, 0x54, 0x2, 0x2, 0x14b, 0x14d, 
       0x7, 0x11, 0x2, 0x2, 0x14c, 0x14e, 0x5, 0x16, 0xc, 0x2, 0x14d, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x155, 
       0x3, 0x2, 0x2, 0x2, 0x14f, 0x151, 0x7, 0x45, 0x2, 0x2, 0x150, 0x152, 
       0x5, 0x3a, 0x1e, 0x2, 0x151, 0x150, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 
       0x3, 0x2, 0x2, 0x2, 0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 
       0x5, 0x16, 0xc, 0x2, 0x154, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x154, 0x14f, 
       0x3, 0x2, 0x2, 0x2, 0x154, 0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x15a, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x2b, 0x2, 0x2, 0x157, 0x159, 
       0x5, 0x38, 0x1d, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15c, 
       0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 
       0x3, 0x2, 0x2, 0x2, 0x15b, 0x166, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 
       0x3, 0x2, 0x2, 0x2, 0x15d, 0x162, 0x5, 0x16, 0xc, 0x2, 0x15e, 0x15f, 
       0x7, 0x2b, 0x2, 0x2, 0x15f, 0x161, 0x5, 0x16, 0xc, 0x2, 0x160, 0x15e, 
       0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 
       0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 0x163, 0x166, 
       0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 0x165, 0x14a, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x166, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x8, 0x1e, 0x1, 0x2, 0x168, 0x17a, 
       0x7, 0x54, 0x2, 0x2, 0x169, 0x175, 0x7, 0x54, 0x2, 0x2, 0x16a, 0x16b, 
       0x7, 0x47, 0x2, 0x2, 0x16b, 0x170, 0x5, 0x16, 0xc, 0x2, 0x16c, 0x16d, 
       0x7, 0x2b, 0x2, 0x2, 0x16d, 0x16f, 0x5, 0x16, 0xc, 0x2, 0x16e, 0x16c, 
       0x3, 0x2, 0x2, 0x2, 0x16f, 0x172, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 
       0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x173, 
       0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 
       0x7, 0x48, 0x2, 0x2, 0x174, 0x176, 0x3, 0x2, 0x2, 0x2, 0x175, 0x16a, 
       0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17a, 
       0x3, 0x2, 0x2, 0x2, 0x179, 0x167, 0x3, 0x2, 0x2, 0x2, 0x179, 0x169, 
       0x3, 0x2, 0x2, 0x2, 0x17a, 0x180, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 
       0xc, 0x4, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x46, 0x2, 0x2, 0x17d, 0x17f, 
       0x5, 0x3a, 0x1e, 0x5, 0x17e, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x182, 
       0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 
       0x3, 0x2, 0x2, 0x2, 0x181, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 
       0x3, 0x2, 0x2, 0x2, 0x183, 0x186, 0x5, 0x3e, 0x20, 0x2, 0x184, 0x186, 
       0x5, 0x40, 0x21, 0x2, 0x185, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 0x184, 
       0x3, 0x2, 0x2, 0x2, 0x186, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x187, 0x18b, 
       0x9, 0xb, 0x2, 0x2, 0x188, 0x18a, 0x5, 0x40, 0x21, 0x2, 0x189, 0x188, 
       0x3, 0x2, 0x2, 0x2, 0x18a, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 
       0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 
       0x3, 0x2, 0x2, 0x2, 0x18d, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 
       0x7, 0x4e, 0x2, 0x2, 0x18f, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 
       0x7, 0x54, 0x2, 0x2, 0x191, 0x192, 0x7, 0x2a, 0x2, 0x2, 0x192, 0x195, 
       0x5, 0x36, 0x1c, 0x2, 0x193, 0x194, 0x7, 0x11, 0x2, 0x2, 0x194, 0x196, 
       0x7, 0x53, 0x2, 0x2, 0x195, 0x193, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 
       0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 
       0x7, 0x5, 0x2, 0x2, 0x198, 0x41, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 
       0x7, 0x4f, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x54, 0x2, 0x2, 0x19b, 0x19c, 
       0x7, 0x2a, 0x2, 0x2, 0x19c, 0x1a0, 0x5, 0x36, 0x1c, 0x2, 0x19d, 0x19f, 
       0x5, 0x3e, 0x20, 0x2, 0x19e, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a2, 
       0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 
       0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a0, 
       0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a5, 0x5, 0x8, 0x5, 0x2, 0x1a4, 0x1a3, 
       0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a9, 
       0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 
       0x7, 0x50, 0x2, 0x2, 0x1aa, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 
       0x7, 0x51, 0x2, 0x2, 0x1ac, 0x1b0, 0x7, 0x54, 0x2, 0x2, 0x1ad, 0x1af, 
       0x5, 0x3e, 0x20, 0x2, 0x1ae, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b2, 
       0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 
       0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b0, 
       0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b5, 0x5, 0x8, 0x5, 0x2, 0x1b4, 0x1b3, 
       0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b4, 
       0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 
       0x7, 0x52, 0x2, 0x2, 0x1ba, 0x45, 0x3, 0x2, 0x2, 0x2, 0x37, 0x49, 
       0x51, 0x56, 0x5b, 0x61, 0x65, 0x69, 0x6d, 0x71, 0x74, 0x78, 0x7d, 
       0x82, 0x8c, 0x9a, 0xa5, 0xb1, 0xb3, 0xbe, 0xc9, 0xd4, 0xda, 0xde, 
       0xe8, 0xf0, 0xf7, 0xfa, 0x106, 0x109, 0x112, 0x117, 0x11e, 0x127, 
       0x12d, 0x138, 0x141, 0x14d, 0x151, 0x154, 0x15a, 0x162, 0x165, 0x170, 
       0x177, 0x179, 0x180, 0x185, 0x18b, 0x195, 0x1a0, 0x1a6, 0x1b0, 0x1b6, 
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
