
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
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::FUNCTION)
      | (1ULL << STParser::FUNCTION_BLOCK)
      | (1ULL << STParser::PROGRAM))) != 0)) {
      setState(90);
      program_list();
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(96);
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
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::PROGRAM: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        programDecl();
        break;
      }

      case STParser::FUNCTION: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        functionDecl();
        break;
      }

      case STParser::FUNCTION_BLOCK: {
        enterOuterAlt(_localctx, 3);
        setState(100);
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

tree::TerminalNode* STParser::ProgramDeclContext::PROGRAM() {
  return getToken(STParser::PROGRAM, 0);
}

tree::TerminalNode* STParser::ProgramDeclContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::BodySectionContext* STParser::ProgramDeclContext::bodySection() {
  return getRuleContext<STParser::BodySectionContext>(0);
}

tree::TerminalNode* STParser::ProgramDeclContext::END_PROGRAM() {
  return getToken(STParser::END_PROGRAM, 0);
}

STParser::InterfaceSectionContext* STParser::ProgramDeclContext::interfaceSection() {
  return getRuleContext<STParser::InterfaceSectionContext>(0);
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
    setState(103);
    match(STParser::PROGRAM);
    setState(104);
    match(STParser::IDENT);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::VAR_INPUT)
      | (1ULL << STParser::VAR_OUTPUT)
      | (1ULL << STParser::VAR_IN_OUT)
      | (1ULL << STParser::VAR_TEMP))) != 0)) {
      setState(105);
      interfaceSection();
    }
    setState(108);
    bodySection();
    setState(109);
    match(STParser::END_PROGRAM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceSectionContext ------------------------------------------------------------------

STParser::InterfaceSectionContext::InterfaceSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::VarDeclarationBlockContext *> STParser::InterfaceSectionContext::varDeclarationBlock() {
  return getRuleContexts<STParser::VarDeclarationBlockContext>();
}

STParser::VarDeclarationBlockContext* STParser::InterfaceSectionContext::varDeclarationBlock(size_t i) {
  return getRuleContext<STParser::VarDeclarationBlockContext>(i);
}


size_t STParser::InterfaceSectionContext::getRuleIndex() const {
  return STParser::RuleInterfaceSection;
}

void STParser::InterfaceSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceSection(this);
}

void STParser::InterfaceSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceSection(this);
}


antlrcpp::Any STParser::InterfaceSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitInterfaceSection(this);
  else
    return visitor->visitChildren(this);
}

STParser::InterfaceSectionContext* STParser::interfaceSection() {
  InterfaceSectionContext *_localctx = _tracker.createInstance<InterfaceSectionContext>(_ctx, getState());
  enterRule(_localctx, 6, STParser::RuleInterfaceSection);
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
    setState(112); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(111);
      varDeclarationBlock();
      setState(114); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::VAR_INPUT)
      | (1ULL << STParser::VAR_OUTPUT)
      | (1ULL << STParser::VAR_IN_OUT)
      | (1ULL << STParser::VAR_TEMP))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodySectionContext ------------------------------------------------------------------

STParser::BodySectionContext::BodySectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::Statement_listContext *> STParser::BodySectionContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::BodySectionContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}


size_t STParser::BodySectionContext::getRuleIndex() const {
  return STParser::RuleBodySection;
}

void STParser::BodySectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBodySection(this);
}

void STParser::BodySectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBodySection(this);
}


antlrcpp::Any STParser::BodySectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitBodySection(this);
  else
    return visitor->visitChildren(this);
}

STParser::BodySectionContext* STParser::bodySection() {
  BodySectionContext *_localctx = _tracker.createInstance<BodySectionContext>(_ctx, getState());
  enterRule(_localctx, 8, STParser::RuleBodySection);
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
    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__0)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::WHILE)
      | (1ULL << STParser::REPEAT)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::CASE))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
      | (1ULL << (STParser::CONTINUE - 82))
      | (1ULL << (STParser::EXIT - 82))
      | (1ULL << (STParser::RETURN - 82))
      | (1ULL << (STParser::IDENT - 82)))) != 0)) {
      setState(116);
      statement_list();
      setState(121);
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
  enterRule(_localctx, 10, STParser::RuleStatement_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(123);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == STParser::IDENT) {
        setState(122);
        assignStmt();
      }
      setState(125);
      match(STParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(127);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == STParser::IF

      || _la == STParser::CASE) {
        setState(126);
        selectStmt();
      }
      setState(129);
      match(STParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(131);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::FOR)
        | (1ULL << STParser::WHILE)
        | (1ULL << STParser::REPEAT))) != 0)) {
        setState(130);
        iterationStmt();
      }
      setState(133);
      match(STParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(135);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == STParser::IDENT) {
        setState(134);
        callFuncStmt();
      }
      setState(137);
      match(STParser::T__0);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(139);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 82) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
        | (1ULL << (STParser::CONTINUE - 82))
        | (1ULL << (STParser::EXIT - 82))
        | (1ULL << (STParser::RETURN - 82)))) != 0)) {
        setState(138);
        jumpStmt();
      }
      setState(141);
      match(STParser::T__0);
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
  enterRule(_localctx, 12, STParser::RuleSelectStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(144);
        ifStmt();
        break;
      }

      case STParser::CASE: {
        enterOuterAlt(_localctx, 2);
        setState(145);
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
  enterRule(_localctx, 14, STParser::RuleIterationStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(148);
        whileStmt();
        break;
      }

      case STParser::FOR: {
        enterOuterAlt(_localctx, 2);
        setState(149);
        forStmt();
        break;
      }

      case STParser::REPEAT: {
        enterOuterAlt(_localctx, 3);
        setState(150);
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
  enterRule(_localctx, 16, STParser::RuleCallFuncStmt);
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
    setState(153);
    match(STParser::IDENT);
    setState(154);
    match(STParser::T__1);
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::T__1 || ((((_la - 86) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 86)) & ((1ULL << (STParser::NUMBER - 86))
      | (1ULL << (STParser::IDENT - 86))
      | (1ULL << (STParser::STRING_LITERAL - 86))
      | (1ULL << (STParser::PREFIX_OP - 86)))) != 0)) {
      setState(155);
      funcParams();
    }
    setState(158);
    match(STParser::T__2);
   
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

tree::TerminalNode* STParser::JumpStmtContext::BREAK() {
  return getToken(STParser::BREAK, 0);
}

tree::TerminalNode* STParser::JumpStmtContext::CONTINUE() {
  return getToken(STParser::CONTINUE, 0);
}

tree::TerminalNode* STParser::JumpStmtContext::RETURN() {
  return getToken(STParser::RETURN, 0);
}

STParser::ExprContext* STParser::JumpStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::JumpStmtContext::EXIT() {
  return getToken(STParser::EXIT, 0);
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
  enterRule(_localctx, 18, STParser::RuleJumpStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(167);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::BREAK: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        match(STParser::BREAK);
        break;
      }

      case STParser::CONTINUE: {
        enterOuterAlt(_localctx, 2);
        setState(161);
        match(STParser::CONTINUE);
        break;
      }

      case STParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(162);
        match(STParser::RETURN);
        setState(164);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == STParser::T__1 || ((((_la - 86) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 86)) & ((1ULL << (STParser::NUMBER - 86))
          | (1ULL << (STParser::IDENT - 86))
          | (1ULL << (STParser::STRING_LITERAL - 86))
          | (1ULL << (STParser::PREFIX_OP - 86)))) != 0)) {
          setState(163);
          expr();
        }
        break;
      }

      case STParser::EXIT: {
        enterOuterAlt(_localctx, 4);
        setState(166);
        match(STParser::EXIT);
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

//----------------- AssignStmtContext ------------------------------------------------------------------

STParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::PrefixExprContext* STParser::AssignStmtContext::prefixExpr() {
  return getRuleContext<STParser::PrefixExprContext>(0);
}

tree::TerminalNode* STParser::AssignStmtContext::ASSIGN() {
  return getToken(STParser::ASSIGN, 0);
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
  enterRule(_localctx, 20, STParser::RuleAssignStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    prefixExpr();
    setState(170);
    match(STParser::ASSIGN);
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(171);
      expr();
      break;
    }

    case 2: {
      setState(172);
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
  enterRule(_localctx, 22, STParser::RulePrefixExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
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
  enterRule(_localctx, 24, STParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
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
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, STParser::RuleOrExpr, precedence);

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
    setState(180);
    andExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(187);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<OrExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleOrExpr);
        setState(182);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(183);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << STParser::T__3)
          | (1ULL << STParser::T__4)
          | (1ULL << STParser::T__5)
          | (1ULL << STParser::T__6))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(184);
        andExpr(0); 
      }
      setState(189);
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
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, STParser::RuleAndExpr, precedence);

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
    setState(191);
    equalExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(198);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpr);
        setState(193);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(194);
        _la = _input->LA(1);
        if (!(_la == STParser::T__7

        || _la == STParser::T__8)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(195);
        equalExpr(0); 
      }
      setState(200);
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

tree::TerminalNode* STParser::EqualExprContext::EQ() {
  return getToken(STParser::EQ, 0);
}

tree::TerminalNode* STParser::EqualExprContext::NEQ() {
  return getToken(STParser::NEQ, 0);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, STParser::RuleEqualExpr, precedence);

    

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
    setState(202);
    relationExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(210);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualExpr);
          setState(204);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(205);
          match(STParser::EQ);
          setState(206);
          relationExpr(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualExpr);
          setState(207);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(208);
          match(STParser::NEQ);
          setState(209);
          relationExpr(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(214);
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

tree::TerminalNode* STParser::RelationExprContext::LT() {
  return getToken(STParser::LT, 0);
}

tree::TerminalNode* STParser::RelationExprContext::LTE() {
  return getToken(STParser::LTE, 0);
}

tree::TerminalNode* STParser::RelationExprContext::GT() {
  return getToken(STParser::GT, 0);
}

tree::TerminalNode* STParser::RelationExprContext::GTE() {
  return getToken(STParser::GTE, 0);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, STParser::RuleRelationExpr, precedence);

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
    setState(216);
    addExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(223);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelationExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelationExpr);
        setState(218);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(219);
        _la = _input->LA(1);
        if (!(((((_la - 78) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 78)) & ((1ULL << (STParser::LT - 78))
          | (1ULL << (STParser::LTE - 78))
          | (1ULL << (STParser::GT - 78))
          | (1ULL << (STParser::GTE - 78)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(220);
        addExpr(0); 
      }
      setState(225);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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

tree::TerminalNode* STParser::AddExprContext::ADD() {
  return getToken(STParser::ADD, 0);
}

tree::TerminalNode* STParser::AddExprContext::SUB() {
  return getToken(STParser::SUB, 0);
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
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, STParser::RuleAddExpr, precedence);

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
    setState(227);
    multipliExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExpr);
        setState(229);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(230);
        _la = _input->LA(1);
        if (!(_la == STParser::ADD

        || _la == STParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(231);
        multipliExpr(0); 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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

tree::TerminalNode* STParser::MultipliExprContext::MUL() {
  return getToken(STParser::MUL, 0);
}

tree::TerminalNode* STParser::MultipliExprContext::DIV() {
  return getToken(STParser::DIV, 0);
}

tree::TerminalNode* STParser::MultipliExprContext::EXP() {
  return getToken(STParser::EXP, 0);
}

tree::TerminalNode* STParser::MultipliExprContext::MOD() {
  return getToken(STParser::MOD, 0);
}

tree::TerminalNode* STParser::MultipliExprContext::SHL() {
  return getToken(STParser::SHL, 0);
}

tree::TerminalNode* STParser::MultipliExprContext::SHR() {
  return getToken(STParser::SHR, 0);
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
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, STParser::RuleMultipliExpr, precedence);

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
    setState(238);
    unaryExpr();
    _ctx->stop = _input->LT(-1);
    setState(245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MultipliExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultipliExpr);
        setState(240);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(241);
        _la = _input->LA(1);
        if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (STParser::MUL - 72))
          | (1ULL << (STParser::DIV - 72))
          | (1ULL << (STParser::EXP - 72))
          | (1ULL << (STParser::MOD - 72))
          | (1ULL << (STParser::SHL - 72))
          | (1ULL << (STParser::SHR - 72)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(242);
        unaryExpr(); 
      }
      setState(247);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
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

tree::TerminalNode* STParser::UnaryExprContext::PREFIX_OP() {
  return getToken(STParser::PREFIX_OP, 0);
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
  enterRule(_localctx, 38, STParser::RuleUnaryExpr);
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
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::PREFIX_OP) {
      setState(248);
      match(STParser::PREFIX_OP);
    }
    setState(251);
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

tree::TerminalNode* STParser::PrimaryContext::STRING_LITERAL() {
  return getToken(STParser::STRING_LITERAL, 0);
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
  enterRule(_localctx, 40, STParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(253);
        match(STParser::T__1);
        setState(254);
        expr();
        setState(255);
        match(STParser::T__2);
        break;
      }

      case STParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(257);
        match(STParser::IDENT);
        break;
      }

      case STParser::NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(258);
        match(STParser::NUMBER);
        break;
      }

      case STParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(259);
        match(STParser::STRING_LITERAL);
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

std::vector<STParser::ExprContext *> STParser::IfStmtContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::IfStmtContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> STParser::IfStmtContext::THEN() {
  return getTokens(STParser::THEN);
}

tree::TerminalNode* STParser::IfStmtContext::THEN(size_t i) {
  return getToken(STParser::THEN, i);
}

tree::TerminalNode* STParser::IfStmtContext::END_IF() {
  return getToken(STParser::END_IF, 0);
}

std::vector<STParser::Statement_listContext *> STParser::IfStmtContext::statement_list() {
  return getRuleContexts<STParser::Statement_listContext>();
}

STParser::Statement_listContext* STParser::IfStmtContext::statement_list(size_t i) {
  return getRuleContext<STParser::Statement_listContext>(i);
}

std::vector<tree::TerminalNode *> STParser::IfStmtContext::ELSEIF() {
  return getTokens(STParser::ELSEIF);
}

tree::TerminalNode* STParser::IfStmtContext::ELSEIF(size_t i) {
  return getToken(STParser::ELSEIF, i);
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
  enterRule(_localctx, 42, STParser::RuleIfStmt);
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
    setState(262);
    match(STParser::IF);
    setState(263);
    expr();
    setState(264);
    match(STParser::THEN);
    setState(268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__0)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::WHILE)
      | (1ULL << STParser::REPEAT)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::CASE))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
      | (1ULL << (STParser::CONTINUE - 82))
      | (1ULL << (STParser::EXIT - 82))
      | (1ULL << (STParser::RETURN - 82))
      | (1ULL << (STParser::IDENT - 82)))) != 0)) {
      setState(265);
      statement_list();
      setState(270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(278);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::ELSEIF) {
      setState(271);
      match(STParser::ELSEIF);
      setState(272);
      expr();
      setState(273);
      match(STParser::THEN);
      setState(274);
      statement_list();
      setState(280);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(288);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::ELSE) {
      setState(281);
      match(STParser::ELSE);
      setState(285);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::T__0)
        | (1ULL << STParser::FOR)
        | (1ULL << STParser::WHILE)
        | (1ULL << STParser::REPEAT)
        | (1ULL << STParser::IF)
        | (1ULL << STParser::CASE))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
        | (1ULL << (STParser::CONTINUE - 82))
        | (1ULL << (STParser::EXIT - 82))
        | (1ULL << (STParser::RETURN - 82))
        | (1ULL << (STParser::IDENT - 82)))) != 0)) {
        setState(282);
        statement_list();
        setState(287);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(290);
    match(STParser::END_IF);
   
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

tree::TerminalNode* STParser::CaseStmtContext::CASE() {
  return getToken(STParser::CASE, 0);
}

STParser::ExprContext* STParser::CaseStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::CaseStmtContext::OF() {
  return getToken(STParser::OF, 0);
}

STParser::CaseListContext* STParser::CaseStmtContext::caseList() {
  return getRuleContext<STParser::CaseListContext>(0);
}

tree::TerminalNode* STParser::CaseStmtContext::END_CASE() {
  return getToken(STParser::END_CASE, 0);
}

tree::TerminalNode* STParser::CaseStmtContext::ELSE() {
  return getToken(STParser::ELSE, 0);
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
  enterRule(_localctx, 44, STParser::RuleCaseStmt);
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
    setState(292);
    match(STParser::CASE);
    setState(293);
    expr();
    setState(294);
    match(STParser::OF);
    setState(295);
    caseList();
    setState(303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::ELSE) {
      setState(296);
      match(STParser::ELSE);
      setState(300);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << STParser::T__0)
        | (1ULL << STParser::FOR)
        | (1ULL << STParser::WHILE)
        | (1ULL << STParser::REPEAT)
        | (1ULL << STParser::IF)
        | (1ULL << STParser::CASE))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
        | (1ULL << (STParser::CONTINUE - 82))
        | (1ULL << (STParser::EXIT - 82))
        | (1ULL << (STParser::RETURN - 82))
        | (1ULL << (STParser::IDENT - 82)))) != 0)) {
        setState(297);
        statement_list();
        setState(302);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(305);
    match(STParser::END_CASE);
   
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
  enterRule(_localctx, 46, STParser::RuleCaseList);
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
    setState(315); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(307);
      caseValues();
      setState(308);
      match(STParser::T__9);
      setState(312);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(309);
          statement_list(); 
        }
        setState(314);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
      }
      setState(317); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == STParser::T__1 || ((((_la - 86) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 86)) & ((1ULL << (STParser::NUMBER - 86))
      | (1ULL << (STParser::IDENT - 86))
      | (1ULL << (STParser::STRING_LITERAL - 86))
      | (1ULL << (STParser::PREFIX_OP - 86)))) != 0));
   
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
  enterRule(_localctx, 48, STParser::RuleCaseValues);
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
    setState(319);
    expr();
    setState(324);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::T__10) {
      setState(320);
      match(STParser::T__10);
      setState(321);
      expr();
      setState(326);
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

tree::TerminalNode* STParser::ForStmtContext::FOR() {
  return getToken(STParser::FOR, 0);
}

STParser::AssignStmtContext* STParser::ForStmtContext::assignStmt() {
  return getRuleContext<STParser::AssignStmtContext>(0);
}

tree::TerminalNode* STParser::ForStmtContext::TO() {
  return getToken(STParser::TO, 0);
}

std::vector<STParser::ExprContext *> STParser::ForStmtContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}

tree::TerminalNode* STParser::ForStmtContext::DO() {
  return getToken(STParser::DO, 0);
}

tree::TerminalNode* STParser::ForStmtContext::END_FOR() {
  return getToken(STParser::END_FOR, 0);
}

tree::TerminalNode* STParser::ForStmtContext::BY() {
  return getToken(STParser::BY, 0);
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
  enterRule(_localctx, 50, STParser::RuleForStmt);
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
    setState(327);
    match(STParser::FOR);
    setState(328);
    assignStmt();
    setState(329);
    match(STParser::TO);
    setState(330);
    expr();
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::BY) {
      setState(331);
      match(STParser::BY);
      setState(332);
      expr();
    }
    setState(335);
    match(STParser::DO);
    setState(339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__0)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::WHILE)
      | (1ULL << STParser::REPEAT)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::CASE))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
      | (1ULL << (STParser::CONTINUE - 82))
      | (1ULL << (STParser::EXIT - 82))
      | (1ULL << (STParser::RETURN - 82))
      | (1ULL << (STParser::IDENT - 82)))) != 0)) {
      setState(336);
      statement_list();
      setState(341);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(342);
    match(STParser::END_FOR);
   
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

tree::TerminalNode* STParser::WhileStmtContext::WHILE() {
  return getToken(STParser::WHILE, 0);
}

STParser::ExprContext* STParser::WhileStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::WhileStmtContext::DO() {
  return getToken(STParser::DO, 0);
}

tree::TerminalNode* STParser::WhileStmtContext::END_WHILE() {
  return getToken(STParser::END_WHILE, 0);
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
  enterRule(_localctx, 52, STParser::RuleWhileStmt);
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
    setState(344);
    match(STParser::WHILE);
    setState(345);
    expr();
    setState(346);
    match(STParser::DO);
    setState(350);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__0)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::WHILE)
      | (1ULL << STParser::REPEAT)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::CASE))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
      | (1ULL << (STParser::CONTINUE - 82))
      | (1ULL << (STParser::EXIT - 82))
      | (1ULL << (STParser::RETURN - 82))
      | (1ULL << (STParser::IDENT - 82)))) != 0)) {
      setState(347);
      statement_list();
      setState(352);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(353);
    match(STParser::END_WHILE);
   
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

tree::TerminalNode* STParser::RepeatStmtContext::REPEAT() {
  return getToken(STParser::REPEAT, 0);
}

tree::TerminalNode* STParser::RepeatStmtContext::UNTIL() {
  return getToken(STParser::UNTIL, 0);
}

STParser::ExprContext* STParser::RepeatStmtContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::RepeatStmtContext::END_REPEAT() {
  return getToken(STParser::END_REPEAT, 0);
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
  enterRule(_localctx, 54, STParser::RuleRepeatStmt);
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
    setState(355);
    match(STParser::REPEAT);
    setState(359);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::T__0)
      | (1ULL << STParser::FOR)
      | (1ULL << STParser::WHILE)
      | (1ULL << STParser::REPEAT)
      | (1ULL << STParser::IF)
      | (1ULL << STParser::CASE))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (STParser::BREAK - 82))
      | (1ULL << (STParser::CONTINUE - 82))
      | (1ULL << (STParser::EXIT - 82))
      | (1ULL << (STParser::RETURN - 82))
      | (1ULL << (STParser::IDENT - 82)))) != 0)) {
      setState(356);
      statement_list();
      setState(361);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(362);
    match(STParser::UNTIL);
    setState(363);
    expr();
    setState(364);
    match(STParser::END_REPEAT);
   
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

STParser::BasicTypeContext* STParser::TypeContext::basicType() {
  return getRuleContext<STParser::BasicTypeContext>(0);
}

STParser::ArrayTypeContext* STParser::TypeContext::arrayType() {
  return getRuleContext<STParser::ArrayTypeContext>(0);
}

STParser::StructTypeContext* STParser::TypeContext::structType() {
  return getRuleContext<STParser::StructTypeContext>(0);
}

STParser::EnumeratedTypeContext* STParser::TypeContext::enumeratedType() {
  return getRuleContext<STParser::EnumeratedTypeContext>(0);
}

STParser::SubrangeTypeContext* STParser::TypeContext::subrangeType() {
  return getRuleContext<STParser::SubrangeTypeContext>(0);
}

tree::TerminalNode* STParser::TypeContext::IDENT() {
  return getToken(STParser::IDENT, 0);
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
  enterRule(_localctx, 56, STParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(372);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(366);
      basicType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(367);
      arrayType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(368);
      structType();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(369);
      enumeratedType();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(370);
      subrangeType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(371);
      match(STParser::IDENT);
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

//----------------- BasicTypeContext ------------------------------------------------------------------

STParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::BasicTypeContext::INT() {
  return getToken(STParser::INT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::SINT() {
  return getToken(STParser::SINT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::DINT() {
  return getToken(STParser::DINT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::LINT() {
  return getToken(STParser::LINT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::USINT() {
  return getToken(STParser::USINT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::UINT() {
  return getToken(STParser::UINT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::UDINT() {
  return getToken(STParser::UDINT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::ULINT() {
  return getToken(STParser::ULINT, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::REAL() {
  return getToken(STParser::REAL, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::LREAL() {
  return getToken(STParser::LREAL, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::BOOL() {
  return getToken(STParser::BOOL, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::BYTE() {
  return getToken(STParser::BYTE, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::WORD() {
  return getToken(STParser::WORD, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::DWORD() {
  return getToken(STParser::DWORD, 0);
}

tree::TerminalNode* STParser::BasicTypeContext::LWORD() {
  return getToken(STParser::LWORD, 0);
}


size_t STParser::BasicTypeContext::getRuleIndex() const {
  return STParser::RuleBasicType;
}

void STParser::BasicTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicType(this);
}

void STParser::BasicTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicType(this);
}


antlrcpp::Any STParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

STParser::BasicTypeContext* STParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 58, STParser::RuleBasicType);
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
    setState(374);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::INT)
      | (1ULL << STParser::SINT)
      | (1ULL << STParser::DINT)
      | (1ULL << STParser::LINT)
      | (1ULL << STParser::USINT)
      | (1ULL << STParser::UINT)
      | (1ULL << STParser::UDINT)
      | (1ULL << STParser::ULINT)
      | (1ULL << STParser::REAL)
      | (1ULL << STParser::LREAL)
      | (1ULL << STParser::BOOL)
      | (1ULL << STParser::BYTE)
      | (1ULL << STParser::WORD)
      | (1ULL << STParser::DWORD)
      | (1ULL << STParser::LWORD))) != 0))) {
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

//----------------- EnumeratedTypeContext ------------------------------------------------------------------

STParser::EnumeratedTypeContext::EnumeratedTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> STParser::EnumeratedTypeContext::IDENT() {
  return getTokens(STParser::IDENT);
}

tree::TerminalNode* STParser::EnumeratedTypeContext::IDENT(size_t i) {
  return getToken(STParser::IDENT, i);
}


size_t STParser::EnumeratedTypeContext::getRuleIndex() const {
  return STParser::RuleEnumeratedType;
}

void STParser::EnumeratedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeratedType(this);
}

void STParser::EnumeratedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeratedType(this);
}


antlrcpp::Any STParser::EnumeratedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitEnumeratedType(this);
  else
    return visitor->visitChildren(this);
}

STParser::EnumeratedTypeContext* STParser::enumeratedType() {
  EnumeratedTypeContext *_localctx = _tracker.createInstance<EnumeratedTypeContext>(_ctx, getState());
  enterRule(_localctx, 60, STParser::RuleEnumeratedType);
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
    setState(376);
    match(STParser::T__1);
    setState(377);
    match(STParser::IDENT);
    setState(382);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::T__10) {
      setState(378);
      match(STParser::T__10);
      setState(379);
      match(STParser::IDENT);
      setState(384);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(385);
    match(STParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubrangeTypeContext ------------------------------------------------------------------

STParser::SubrangeTypeContext::SubrangeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

STParser::BasicTypeContext* STParser::SubrangeTypeContext::basicType() {
  return getRuleContext<STParser::BasicTypeContext>(0);
}

std::vector<STParser::ExprContext *> STParser::SubrangeTypeContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::SubrangeTypeContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}


size_t STParser::SubrangeTypeContext::getRuleIndex() const {
  return STParser::RuleSubrangeType;
}

void STParser::SubrangeTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubrangeType(this);
}

void STParser::SubrangeTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubrangeType(this);
}


antlrcpp::Any STParser::SubrangeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitSubrangeType(this);
  else
    return visitor->visitChildren(this);
}

STParser::SubrangeTypeContext* STParser::subrangeType() {
  SubrangeTypeContext *_localctx = _tracker.createInstance<SubrangeTypeContext>(_ctx, getState());
  enterRule(_localctx, 62, STParser::RuleSubrangeType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    basicType();
    setState(388);
    match(STParser::T__1);
    setState(389);
    expr();
    setState(390);
    match(STParser::T__11);
    setState(391);
    expr();
    setState(392);
    match(STParser::T__2);
   
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

std::vector<STParser::FuncParamContext *> STParser::FuncParamsContext::funcParam() {
  return getRuleContexts<STParser::FuncParamContext>();
}

STParser::FuncParamContext* STParser::FuncParamsContext::funcParam(size_t i) {
  return getRuleContext<STParser::FuncParamContext>(i);
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
  enterRule(_localctx, 64, STParser::RuleFuncParams);
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
    setState(394);
    funcParam();
    setState(399);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::T__10) {
      setState(395);
      match(STParser::T__10);
      setState(396);
      funcParam();
      setState(401);
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

//----------------- FuncParamContext ------------------------------------------------------------------

STParser::FuncParamContext::FuncParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::FuncParamContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

tree::TerminalNode* STParser::FuncParamContext::ASSIGN() {
  return getToken(STParser::ASSIGN, 0);
}

STParser::ExprContext* STParser::FuncParamContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
}

tree::TerminalNode* STParser::FuncParamContext::ARROW() {
  return getToken(STParser::ARROW, 0);
}

STParser::IdentContext* STParser::FuncParamContext::ident() {
  return getRuleContext<STParser::IdentContext>(0);
}


size_t STParser::FuncParamContext::getRuleIndex() const {
  return STParser::RuleFuncParam;
}

void STParser::FuncParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncParam(this);
}

void STParser::FuncParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncParam(this);
}


antlrcpp::Any STParser::FuncParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitFuncParam(this);
  else
    return visitor->visitChildren(this);
}

STParser::FuncParamContext* STParser::funcParam() {
  FuncParamContext *_localctx = _tracker.createInstance<FuncParamContext>(_ctx, getState());
  enterRule(_localctx, 66, STParser::RuleFuncParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(402);
      match(STParser::IDENT);
      setState(403);
      match(STParser::ASSIGN);
      setState(404);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(405);
      match(STParser::IDENT);
      setState(406);
      match(STParser::ARROW);
      setState(407);
      ident(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(408);
      expr();
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
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, STParser::RuleIdent, precedence);

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
    setState(429);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<IdentiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(412);
      match(STParser::IDENT);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(413);
      match(STParser::IDENT);
      setState(425); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(414);
                match(STParser::T__13);
                setState(415);
                expr();
                setState(420);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == STParser::T__10) {
                  setState(416);
                  match(STParser::T__10);
                  setState(417);
                  expr();
                  setState(422);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(423);
                match(STParser::T__14);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(427); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(436);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<StructContext>(_tracker.createInstance<IdentContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleIdent);
        setState(431);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(432);
        match(STParser::T__12);
        setState(433);
        ident(3); 
      }
      setState(438);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
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
  enterRule(_localctx, 70, STParser::RuleDeclarationStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(441);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case STParser::VAR:
      case STParser::VAR_INPUT:
      case STParser::VAR_OUTPUT:
      case STParser::VAR_IN_OUT:
      case STParser::VAR_TEMP: {
        enterOuterAlt(_localctx, 1);
        setState(439);
        varDeclarationBlock();
        break;
      }

      case STParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(440);
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

tree::TerminalNode* STParser::VarDeclarationBlockContext::END_VAR() {
  return getToken(STParser::END_VAR, 0);
}

tree::TerminalNode* STParser::VarDeclarationBlockContext::VAR() {
  return getToken(STParser::VAR, 0);
}

tree::TerminalNode* STParser::VarDeclarationBlockContext::VAR_INPUT() {
  return getToken(STParser::VAR_INPUT, 0);
}

tree::TerminalNode* STParser::VarDeclarationBlockContext::VAR_OUTPUT() {
  return getToken(STParser::VAR_OUTPUT, 0);
}

tree::TerminalNode* STParser::VarDeclarationBlockContext::VAR_IN_OUT() {
  return getToken(STParser::VAR_IN_OUT, 0);
}

tree::TerminalNode* STParser::VarDeclarationBlockContext::VAR_TEMP() {
  return getToken(STParser::VAR_TEMP, 0);
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
  enterRule(_localctx, 72, STParser::RuleVarDeclarationBlock);
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
    setState(443);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::VAR_INPUT)
      | (1ULL << STParser::VAR_OUTPUT)
      | (1ULL << STParser::VAR_IN_OUT)
      | (1ULL << STParser::VAR_TEMP))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(447);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::IDENT) {
      setState(444);
      varDeclaration();
      setState(449);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(450);
    match(STParser::END_VAR);
   
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

STParser::ArrayTypeContext* STParser::VarDeclarationContext::arrayType() {
  return getRuleContext<STParser::ArrayTypeContext>(0);
}

STParser::StructTypeContext* STParser::VarDeclarationContext::structType() {
  return getRuleContext<STParser::StructTypeContext>(0);
}

tree::TerminalNode* STParser::VarDeclarationContext::ASSIGN() {
  return getToken(STParser::ASSIGN, 0);
}

STParser::ExprContext* STParser::VarDeclarationContext::expr() {
  return getRuleContext<STParser::ExprContext>(0);
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
  enterRule(_localctx, 74, STParser::RuleVarDeclaration);
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
    setState(452);
    match(STParser::IDENT);
    setState(453);
    match(STParser::T__9);
    setState(457);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(454);
      type();
      break;
    }

    case 2: {
      setState(455);
      arrayType();
      break;
    }

    case 3: {
      setState(456);
      structType();
      break;
    }

    default:
      break;
    }
    setState(461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == STParser::ASSIGN) {
      setState(459);
      match(STParser::ASSIGN);
      setState(460);
      expr();
    }
    setState(463);
    match(STParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

STParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::RangeContext *> STParser::ArrayTypeContext::range() {
  return getRuleContexts<STParser::RangeContext>();
}

STParser::RangeContext* STParser::ArrayTypeContext::range(size_t i) {
  return getRuleContext<STParser::RangeContext>(i);
}

tree::TerminalNode* STParser::ArrayTypeContext::OF() {
  return getToken(STParser::OF, 0);
}

STParser::TypeContext* STParser::ArrayTypeContext::type() {
  return getRuleContext<STParser::TypeContext>(0);
}


size_t STParser::ArrayTypeContext::getRuleIndex() const {
  return STParser::RuleArrayType;
}

void STParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void STParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}


antlrcpp::Any STParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

STParser::ArrayTypeContext* STParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 76, STParser::RuleArrayType);
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
    setState(465);
    match(STParser::T__15);
    setState(466);
    match(STParser::T__13);
    setState(467);
    range();
    setState(472);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::T__10) {
      setState(468);
      match(STParser::T__10);
      setState(469);
      range();
      setState(474);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(475);
    match(STParser::T__14);
    setState(476);
    match(STParser::OF);
    setState(477);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

STParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::ExprContext *> STParser::RangeContext::expr() {
  return getRuleContexts<STParser::ExprContext>();
}

STParser::ExprContext* STParser::RangeContext::expr(size_t i) {
  return getRuleContext<STParser::ExprContext>(i);
}


size_t STParser::RangeContext::getRuleIndex() const {
  return STParser::RuleRange;
}

void STParser::RangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange(this);
}

void STParser::RangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange(this);
}


antlrcpp::Any STParser::RangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitRange(this);
  else
    return visitor->visitChildren(this);
}

STParser::RangeContext* STParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 78, STParser::RuleRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    expr();
    setState(480);
    match(STParser::T__11);
    setState(481);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructTypeContext ------------------------------------------------------------------

STParser::StructTypeContext::StructTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<STParser::StructMemberContext *> STParser::StructTypeContext::structMember() {
  return getRuleContexts<STParser::StructMemberContext>();
}

STParser::StructMemberContext* STParser::StructTypeContext::structMember(size_t i) {
  return getRuleContext<STParser::StructMemberContext>(i);
}


size_t STParser::StructTypeContext::getRuleIndex() const {
  return STParser::RuleStructType;
}

void STParser::StructTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructType(this);
}

void STParser::StructTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructType(this);
}


antlrcpp::Any STParser::StructTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitStructType(this);
  else
    return visitor->visitChildren(this);
}

STParser::StructTypeContext* STParser::structType() {
  StructTypeContext *_localctx = _tracker.createInstance<StructTypeContext>(_ctx, getState());
  enterRule(_localctx, 80, STParser::RuleStructType);
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
    setState(483);
    match(STParser::T__16);
    setState(485); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(484);
      structMember();
      setState(487); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == STParser::IDENT);
    setState(489);
    match(STParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructMemberContext ------------------------------------------------------------------

STParser::StructMemberContext::StructMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::StructMemberContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::TypeContext* STParser::StructMemberContext::type() {
  return getRuleContext<STParser::TypeContext>(0);
}


size_t STParser::StructMemberContext::getRuleIndex() const {
  return STParser::RuleStructMember;
}

void STParser::StructMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructMember(this);
}

void STParser::StructMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructMember(this);
}


antlrcpp::Any STParser::StructMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitStructMember(this);
  else
    return visitor->visitChildren(this);
}

STParser::StructMemberContext* STParser::structMember() {
  StructMemberContext *_localctx = _tracker.createInstance<StructMemberContext>(_ctx, getState());
  enterRule(_localctx, 82, STParser::RuleStructMember);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    match(STParser::IDENT);
    setState(492);
    match(STParser::T__9);
    setState(493);
    type();
    setState(494);
    match(STParser::T__0);
   
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

tree::TerminalNode* STParser::FunctionDeclContext::FUNCTION() {
  return getToken(STParser::FUNCTION, 0);
}

tree::TerminalNode* STParser::FunctionDeclContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::TypeContext* STParser::FunctionDeclContext::type() {
  return getRuleContext<STParser::TypeContext>(0);
}

STParser::BodySectionContext* STParser::FunctionDeclContext::bodySection() {
  return getRuleContext<STParser::BodySectionContext>(0);
}

tree::TerminalNode* STParser::FunctionDeclContext::END_FUNCTION() {
  return getToken(STParser::END_FUNCTION, 0);
}

STParser::InterfaceSectionContext* STParser::FunctionDeclContext::interfaceSection() {
  return getRuleContext<STParser::InterfaceSectionContext>(0);
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
  enterRule(_localctx, 84, STParser::RuleFunctionDecl);
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
    setState(496);
    match(STParser::FUNCTION);
    setState(497);
    match(STParser::IDENT);
    setState(498);
    match(STParser::T__9);
    setState(499);
    type();
    setState(501);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::VAR_INPUT)
      | (1ULL << STParser::VAR_OUTPUT)
      | (1ULL << STParser::VAR_IN_OUT)
      | (1ULL << STParser::VAR_TEMP))) != 0)) {
      setState(500);
      interfaceSection();
    }
    setState(503);
    bodySection();
    setState(504);
    match(STParser::END_FUNCTION);
   
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

tree::TerminalNode* STParser::FunctionBlockDeclContext::FUNCTION_BLOCK() {
  return getToken(STParser::FUNCTION_BLOCK, 0);
}

tree::TerminalNode* STParser::FunctionBlockDeclContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::BodySectionContext* STParser::FunctionBlockDeclContext::bodySection() {
  return getRuleContext<STParser::BodySectionContext>(0);
}

tree::TerminalNode* STParser::FunctionBlockDeclContext::END_FUNCTION_BLOCK() {
  return getToken(STParser::END_FUNCTION_BLOCK, 0);
}

STParser::InterfaceSectionContext* STParser::FunctionBlockDeclContext::interfaceSection() {
  return getRuleContext<STParser::InterfaceSectionContext>(0);
}

std::vector<STParser::MethodDeclContext *> STParser::FunctionBlockDeclContext::methodDecl() {
  return getRuleContexts<STParser::MethodDeclContext>();
}

STParser::MethodDeclContext* STParser::FunctionBlockDeclContext::methodDecl(size_t i) {
  return getRuleContext<STParser::MethodDeclContext>(i);
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
  enterRule(_localctx, 86, STParser::RuleFunctionBlockDecl);
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
    setState(506);
    match(STParser::FUNCTION_BLOCK);
    setState(507);
    match(STParser::IDENT);
    setState(509);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::VAR_INPUT)
      | (1ULL << STParser::VAR_OUTPUT)
      | (1ULL << STParser::VAR_IN_OUT)
      | (1ULL << STParser::VAR_TEMP))) != 0)) {
      setState(508);
      interfaceSection();
    }
    setState(511);
    bodySection();
    setState(515);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == STParser::METHOD) {
      setState(512);
      methodDecl();
      setState(517);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(518);
    match(STParser::END_FUNCTION_BLOCK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclContext ------------------------------------------------------------------

STParser::MethodDeclContext::MethodDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* STParser::MethodDeclContext::METHOD() {
  return getToken(STParser::METHOD, 0);
}

tree::TerminalNode* STParser::MethodDeclContext::IDENT() {
  return getToken(STParser::IDENT, 0);
}

STParser::TypeContext* STParser::MethodDeclContext::type() {
  return getRuleContext<STParser::TypeContext>(0);
}

STParser::BodySectionContext* STParser::MethodDeclContext::bodySection() {
  return getRuleContext<STParser::BodySectionContext>(0);
}

tree::TerminalNode* STParser::MethodDeclContext::END_METHOD() {
  return getToken(STParser::END_METHOD, 0);
}

STParser::InterfaceSectionContext* STParser::MethodDeclContext::interfaceSection() {
  return getRuleContext<STParser::InterfaceSectionContext>(0);
}


size_t STParser::MethodDeclContext::getRuleIndex() const {
  return STParser::RuleMethodDecl;
}

void STParser::MethodDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDecl(this);
}

void STParser::MethodDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<STListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDecl(this);
}


antlrcpp::Any STParser::MethodDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<STVisitor*>(visitor))
    return parserVisitor->visitMethodDecl(this);
  else
    return visitor->visitChildren(this);
}

STParser::MethodDeclContext* STParser::methodDecl() {
  MethodDeclContext *_localctx = _tracker.createInstance<MethodDeclContext>(_ctx, getState());
  enterRule(_localctx, 88, STParser::RuleMethodDecl);
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
    setState(520);
    match(STParser::METHOD);
    setState(521);
    match(STParser::IDENT);
    setState(522);
    match(STParser::T__9);
    setState(523);
    type();
    setState(525);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << STParser::VAR)
      | (1ULL << STParser::VAR_INPUT)
      | (1ULL << STParser::VAR_OUTPUT)
      | (1ULL << STParser::VAR_IN_OUT)
      | (1ULL << STParser::VAR_TEMP))) != 0)) {
      setState(524);
      interfaceSection();
    }
    setState(527);
    bodySection();
    setState(528);
    match(STParser::END_METHOD);
   
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
    case 13: return orExprSempred(dynamic_cast<OrExprContext *>(context), predicateIndex);
    case 14: return andExprSempred(dynamic_cast<AndExprContext *>(context), predicateIndex);
    case 15: return equalExprSempred(dynamic_cast<EqualExprContext *>(context), predicateIndex);
    case 16: return relationExprSempred(dynamic_cast<RelationExprContext *>(context), predicateIndex);
    case 17: return addExprSempred(dynamic_cast<AddExprContext *>(context), predicateIndex);
    case 18: return multipliExprSempred(dynamic_cast<MultipliExprContext *>(context), predicateIndex);
    case 34: return identSempred(dynamic_cast<IdentContext *>(context), predicateIndex);

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
  "startpoint", "program_list", "programDecl", "interfaceSection", "bodySection", 
  "statement_list", "selectStmt", "iterationStmt", "callFuncStmt", "jumpStmt", 
  "assignStmt", "prefixExpr", "expr", "orExpr", "andExpr", "equalExpr", 
  "relationExpr", "addExpr", "multipliExpr", "unaryExpr", "primary", "ifStmt", 
  "caseStmt", "caseList", "caseValues", "forStmt", "whileStmt", "repeatStmt", 
  "type", "basicType", "enumeratedType", "subrangeType", "funcParams", "funcParam", 
  "ident", "declarationStmt", "varDeclarationBlock", "varDeclaration", "arrayType", 
  "range", "structType", "structMember", "functionDecl", "functionBlockDecl", 
  "methodDecl"
};

std::vector<std::string> STParser::_literalNames = {
  "", "';'", "'('", "')'", "'OR'", "'XOR'", "'|'", "'^'", "'AND'", "'&'", 
  "':'", "','", "'..'", "'.'", "'['", "']'", "'ARRAY'", "'STRUCT'", "'END_STRUCT'", 
  "'VAR'", "'VAR_INPUT'", "'VAR_OUTPUT'", "'VAR_IN_OUT'", "'VAR_TEMP'", 
  "'END_VAR'", "'FUNCTION'", "'END_FUNCTION'", "'FUNCTION_BLOCK'", "'END_FUNCTION_BLOCK'", 
  "'INT'", "'SINT'", "'DINT'", "'LINT'", "'USINT'", "'UINT'", "'UDINT'", 
  "'ULINT'", "'REAL'", "'LREAL'", "'BOOL'", "'BYTE'", "'WORD'", "'DWORD'", 
  "'LWORD'", "'FOR'", "'TO'", "'BY'", "'END_FOR'", "'WHILE'", "'DO'", "'END_WHILE'", 
  "'REPEAT'", "'UNTIL'", "'END_REPEAT'", "'PROGRAM'", "'END_PROGRAM'", "'IF'", 
  "'ELSEIF'", "'THEN'", "'ELSE'", "'END_IF'", "'CASE'", "'OF'", "'END_CASE'", 
  "'METHOD'", "'END_METHOD'", "':='", "'=>'", "'='", "", "'+'", "'-'", "'*'", 
  "'/'", "'**'", "'%'", "'SHL'", "'SHR'", "'<'", "'<='", "'>'", "'>='", 
  "'BREAK'", "'CONTINUE'", "'EXIT'", "'RETURN'"
};

std::vector<std::string> STParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "VAR", "VAR_INPUT", "VAR_OUTPUT", "VAR_IN_OUT", "VAR_TEMP", "END_VAR", 
  "FUNCTION", "END_FUNCTION", "FUNCTION_BLOCK", "END_FUNCTION_BLOCK", "INT", 
  "SINT", "DINT", "LINT", "USINT", "UINT", "UDINT", "ULINT", "REAL", "LREAL", 
  "BOOL", "BYTE", "WORD", "DWORD", "LWORD", "FOR", "TO", "BY", "END_FOR", 
  "WHILE", "DO", "END_WHILE", "REPEAT", "UNTIL", "END_REPEAT", "PROGRAM", 
  "END_PROGRAM", "IF", "ELSEIF", "THEN", "ELSE", "END_IF", "CASE", "OF", 
  "END_CASE", "METHOD", "END_METHOD", "ASSIGN", "ARROW", "EQ", "NEQ", "ADD", 
  "SUB", "MUL", "DIV", "EXP", "MOD", "SHL", "SHR", "LT", "LTE", "GT", "GTE", 
  "BREAK", "CONTINUE", "EXIT", "RETURN", "NUMBER", "IDENT", "WS", "COMMENT_LINE", 
  "COMMENT_PARA", "STRING_LITERAL", "PREFIX_OP"
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
       0x3, 0x5e, 0x215, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x3, 0x2, 
       0x7, 0x2, 0x5e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x61, 0xb, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x68, 0xa, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x6d, 0xa, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x6, 0x5, 0x73, 0xa, 0x5, 0xd, 
       0x5, 0xe, 0x5, 0x74, 0x3, 0x6, 0x7, 0x6, 0x78, 0xa, 0x6, 0xc, 0x6, 
       0xe, 0x6, 0x7b, 0xb, 0x6, 0x3, 0x7, 0x5, 0x7, 0x7e, 0xa, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x5, 0x7, 0x82, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
       0x7, 0x86, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x8a, 0xa, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x8e, 0xa, 0x7, 0x3, 0x7, 0x5, 0x7, 
       0x91, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x95, 0xa, 0x8, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x9a, 0xa, 0x9, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x5, 0xa, 0x9f, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xa7, 0xa, 0xb, 0x3, 
       0xb, 0x5, 0xb, 0xaa, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x5, 0xc, 0xb0, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x7, 0xf, 0xbc, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xbf, 0xb, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 
       0x10, 0xc7, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xca, 0xb, 0x10, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xd5, 0xa, 0x11, 0xc, 0x11, 
       0xe, 0x11, 0xd8, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xe0, 0xa, 0x12, 0xc, 0x12, 
       0xe, 0x12, 0xe3, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xeb, 0xa, 0x13, 0xc, 0x13, 
       0xe, 0x13, 0xee, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xf6, 0xa, 0x14, 0xc, 0x14, 
       0xe, 0x14, 0xf9, 0xb, 0x14, 0x3, 0x15, 0x5, 0x15, 0xfc, 0xa, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x107, 0xa, 0x16, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x10d, 0xa, 0x17, 
       0xc, 0x17, 0xe, 0x17, 0x110, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x117, 0xa, 0x17, 0xc, 0x17, 
       0xe, 0x17, 0x11a, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x11e, 
       0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x121, 0xb, 0x17, 0x5, 0x17, 0x123, 
       0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x12d, 0xa, 0x18, 0xc, 
       0x18, 0xe, 0x18, 0x130, 0xb, 0x18, 0x5, 0x18, 0x132, 0xa, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x139, 
       0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x13c, 0xb, 0x19, 0x6, 0x19, 0x13e, 
       0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x13f, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x7, 0x1a, 0x145, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x148, 0xb, 
       0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x150, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 
       0x154, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x157, 0xb, 0x1b, 0x3, 0x1b, 
       0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 
       0x15f, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x162, 0xb, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x168, 0xa, 0x1d, 0xc, 
       0x1d, 0xe, 0x1d, 0x16b, 0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x5, 0x1e, 0x177, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x17f, 0xa, 0x20, 
       0xc, 0x20, 0xe, 0x20, 0x182, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x190, 0xa, 0x22, 
       0xc, 0x22, 0xe, 0x22, 0x193, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x19c, 
       0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x1a5, 0xa, 0x24, 0xc, 0x24, 0xe, 
       0x24, 0x1a8, 0xb, 0x24, 0x3, 0x24, 0x3, 0x24, 0x6, 0x24, 0x1ac, 0xa, 
       0x24, 0xd, 0x24, 0xe, 0x24, 0x1ad, 0x5, 0x24, 0x1b0, 0xa, 0x24, 0x3, 
       0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x1b5, 0xa, 0x24, 0xc, 0x24, 
       0xe, 0x24, 0x1b8, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1bc, 
       0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x1c0, 0xa, 0x26, 0xc, 
       0x26, 0xe, 0x26, 0x1c3, 0xb, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1cc, 0xa, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1d0, 0xa, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
       0x7, 0x28, 0x1d9, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x1dc, 0xb, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x6, 0x2a, 0x1e8, 0xa, 
       0x2a, 0xd, 0x2a, 0xe, 0x2a, 0x1e9, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
       0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1f8, 0xa, 0x2c, 0x3, 
       0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
       0x2d, 0x200, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x204, 0xa, 
       0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x207, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
       0x210, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x2, 
       0x9, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x46, 0x2f, 0x2, 0x4, 0x6, 
       0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
       0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
       0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
       0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x2, 0x9, 0x3, 0x2, 
       0x6, 0x9, 0x3, 0x2, 0xa, 0xb, 0x3, 0x2, 0x50, 0x53, 0x3, 0x2, 0x48, 
       0x49, 0x3, 0x2, 0x4a, 0x4f, 0x3, 0x2, 0x1f, 0x2d, 0x3, 0x2, 0x15, 
       0x19, 0x2, 0x22f, 0x2, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x67, 0x3, 
       0x2, 0x2, 0x2, 0x6, 0x69, 0x3, 0x2, 0x2, 0x2, 0x8, 0x72, 0x3, 0x2, 
       0x2, 0x2, 0xa, 0x79, 0x3, 0x2, 0x2, 0x2, 0xc, 0x90, 0x3, 0x2, 0x2, 
       0x2, 0xe, 0x94, 0x3, 0x2, 0x2, 0x2, 0x10, 0x99, 0x3, 0x2, 0x2, 0x2, 
       0x12, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x16, 
       0xab, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xb3, 
       0x3, 0x2, 0x2, 0x2, 0x1c, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc0, 0x3, 
       0x2, 0x2, 0x2, 0x20, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x22, 0xd9, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x26, 0xef, 0x3, 0x2, 0x2, 
       0x2, 0x28, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x106, 0x3, 0x2, 0x2, 
       0x2, 0x2c, 0x108, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x126, 0x3, 0x2, 0x2, 
       0x2, 0x30, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x32, 0x141, 0x3, 0x2, 0x2, 
       0x2, 0x34, 0x149, 0x3, 0x2, 0x2, 0x2, 0x36, 0x15a, 0x3, 0x2, 0x2, 
       0x2, 0x38, 0x165, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x176, 0x3, 0x2, 0x2, 
       0x2, 0x3c, 0x178, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x17a, 0x3, 0x2, 0x2, 
       0x2, 0x40, 0x185, 0x3, 0x2, 0x2, 0x2, 0x42, 0x18c, 0x3, 0x2, 0x2, 
       0x2, 0x44, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1af, 0x3, 0x2, 0x2, 
       0x2, 0x48, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1bd, 0x3, 0x2, 0x2, 
       0x2, 0x4c, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1d3, 0x3, 0x2, 0x2, 
       0x2, 0x50, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1e5, 0x3, 0x2, 0x2, 
       0x2, 0x54, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1f2, 0x3, 0x2, 0x2, 
       0x2, 0x58, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x20a, 0x3, 0x2, 0x2, 
       0x2, 0x5c, 0x5e, 0x5, 0x4, 0x3, 0x2, 0x5d, 0x5c, 0x3, 0x2, 0x2, 0x2, 
       0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 
       0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x2, 0x2, 0x3, 0x63, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x64, 0x68, 0x5, 0x6, 0x4, 0x2, 0x65, 0x68, 0x5, 0x56, 
       0x2c, 0x2, 0x66, 0x68, 0x5, 0x58, 0x2d, 0x2, 0x67, 0x64, 0x3, 0x2, 
       0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 
       0x2, 0x68, 0x5, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x38, 0x2, 0x2, 
       0x6a, 0x6c, 0x7, 0x59, 0x2, 0x2, 0x6b, 0x6d, 0x5, 0x8, 0x5, 0x2, 
       0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 
       0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0xa, 0x6, 0x2, 0x6f, 0x70, 
       0x7, 0x39, 0x2, 0x2, 0x70, 0x7, 0x3, 0x2, 0x2, 0x2, 0x71, 0x73, 0x5, 
       0x4a, 0x26, 0x2, 0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 
       0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 
       0x2, 0x2, 0x75, 0x9, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 0x5, 0xc, 0x7, 
       0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 
       0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 
       0xb, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 
       0x5, 0x16, 0xc, 0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 
       0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x91, 0x7, 
       0x3, 0x2, 0x2, 0x80, 0x82, 0x5, 0xe, 0x8, 0x2, 0x81, 0x80, 0x3, 0x2, 
       0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 
       0x2, 0x83, 0x91, 0x7, 0x3, 0x2, 0x2, 0x84, 0x86, 0x5, 0x10, 0x9, 
       0x2, 0x85, 0x84, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 
       0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x91, 0x7, 0x3, 0x2, 0x2, 0x88, 
       0x8a, 0x5, 0x12, 0xa, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x89, 
       0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x91, 
       0x7, 0x3, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0x14, 0xb, 0x2, 0x8d, 0x8c, 
       0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 
       0x2, 0x2, 0x2, 0x8f, 0x91, 0x7, 0x3, 0x2, 0x2, 0x90, 0x7d, 0x3, 0x2, 
       0x2, 0x2, 0x90, 0x81, 0x3, 0x2, 0x2, 0x2, 0x90, 0x85, 0x3, 0x2, 0x2, 
       0x2, 0x90, 0x89, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8d, 0x3, 0x2, 0x2, 0x2, 
       0x91, 0xd, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x5, 0x2c, 0x17, 0x2, 
       0x93, 0x95, 0x5, 0x2e, 0x18, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 
       0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0xf, 0x3, 0x2, 0x2, 0x2, 0x96, 
       0x9a, 0x5, 0x36, 0x1c, 0x2, 0x97, 0x9a, 0x5, 0x34, 0x1b, 0x2, 0x98, 
       0x9a, 0x5, 0x38, 0x1d, 0x2, 0x99, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 
       0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x59, 0x2, 0x2, 0x9c, 0x9e, 
       0x7, 0x4, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0x42, 0x22, 0x2, 0x9e, 0x9d, 
       0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 
       0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x5, 0x2, 0x2, 0xa1, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0xa2, 0xaa, 0x7, 0x54, 0x2, 0x2, 0xa3, 0xaa, 0x7, 0x55, 
       0x2, 0x2, 0xa4, 0xa6, 0x7, 0x57, 0x2, 0x2, 0xa5, 0xa7, 0x5, 0x1a, 
       0xe, 0x2, 0xa6, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 
       0x2, 0xa7, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xaa, 0x7, 0x56, 0x2, 
       0x2, 0xa9, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa3, 0x3, 0x2, 0x2, 0x2, 
       0xa9, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 0x18, 0xd, 0x2, 0xac, 
       0xaf, 0x7, 0x44, 0x2, 0x2, 0xad, 0xb0, 0x5, 0x1a, 0xe, 0x2, 0xae, 
       0xb0, 0x5, 0x12, 0xa, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 
       0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 
       0x5, 0x46, 0x24, 0x2, 0xb2, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 
       0x5, 0x1c, 0xf, 0x2, 0xb4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 
       0x8, 0xf, 0x1, 0x2, 0xb6, 0xb7, 0x5, 0x1e, 0x10, 0x2, 0xb7, 0xbd, 
       0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0xc, 0x3, 0x2, 0x2, 0xb9, 0xba, 0x9, 
       0x2, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x1e, 0x10, 0x2, 0xbb, 0xb8, 0x3, 
       0x2, 0x2, 0x2, 0xbc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 
       0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x1d, 0x3, 0x2, 0x2, 
       0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x8, 0x10, 0x1, 
       0x2, 0xc1, 0xc2, 0x5, 0x20, 0x11, 0x2, 0xc2, 0xc8, 0x3, 0x2, 0x2, 
       0x2, 0xc3, 0xc4, 0xc, 0x3, 0x2, 0x2, 0xc4, 0xc5, 0x9, 0x3, 0x2, 0x2, 
       0xc5, 0xc7, 0x5, 0x20, 0x11, 0x2, 0xc6, 0xc3, 0x3, 0x2, 0x2, 0x2, 
       0xc7, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 
       0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 
       0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x8, 0x11, 0x1, 0x2, 0xcc, 0xcd, 
       0x5, 0x22, 0x12, 0x2, 0xcd, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 
       0xc, 0x4, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x46, 0x2, 0x2, 0xd0, 0xd5, 
       0x5, 0x22, 0x12, 0x2, 0xd1, 0xd2, 0xc, 0x3, 0x2, 0x2, 0xd2, 0xd3, 
       0x7, 0x47, 0x2, 0x2, 0xd3, 0xd5, 0x5, 0x22, 0x12, 0x2, 0xd4, 0xce, 
       0x3, 0x2, 0x2, 0x2, 0xd4, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 
       0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 
       0x2, 0x2, 0xd7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 
       0x2, 0xd9, 0xda, 0x8, 0x12, 0x1, 0x2, 0xda, 0xdb, 0x5, 0x24, 0x13, 
       0x2, 0xdb, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0xc, 0x3, 0x2, 0x2, 
       0xdd, 0xde, 0x9, 0x4, 0x2, 0x2, 0xde, 0xe0, 0x5, 0x24, 0x13, 0x2, 
       0xdf, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe1, 
       0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x8, 
       0x13, 0x1, 0x2, 0xe5, 0xe6, 0x5, 0x26, 0x14, 0x2, 0xe6, 0xec, 0x3, 
       0x2, 0x2, 0x2, 0xe7, 0xe8, 0xc, 0x3, 0x2, 0x2, 0xe8, 0xe9, 0x9, 0x5, 
       0x2, 0x2, 0xe9, 0xeb, 0x5, 0x26, 0x14, 0x2, 0xea, 0xe7, 0x3, 0x2, 
       0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 
       0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0x25, 0x3, 0x2, 0x2, 0x2, 
       0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x8, 0x14, 0x1, 0x2, 
       0xf0, 0xf1, 0x5, 0x28, 0x15, 0x2, 0xf1, 0xf7, 0x3, 0x2, 0x2, 0x2, 
       0xf2, 0xf3, 0xc, 0x3, 0x2, 0x2, 0xf3, 0xf4, 0x9, 0x6, 0x2, 0x2, 0xf4, 
       0xf6, 0x5, 0x28, 0x15, 0x2, 0xf5, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf6, 
       0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 
       0x3, 0x2, 0x2, 0x2, 0xf8, 0x27, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xf7, 0x3, 
       0x2, 0x2, 0x2, 0xfa, 0xfc, 0x7, 0x5e, 0x2, 0x2, 0xfb, 0xfa, 0x3, 
       0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 
       0x2, 0x2, 0xfd, 0xfe, 0x5, 0x2a, 0x16, 0x2, 0xfe, 0x29, 0x3, 0x2, 
       0x2, 0x2, 0xff, 0x100, 0x7, 0x4, 0x2, 0x2, 0x100, 0x101, 0x5, 0x1a, 
       0xe, 0x2, 0x101, 0x102, 0x7, 0x5, 0x2, 0x2, 0x102, 0x107, 0x3, 0x2, 
       0x2, 0x2, 0x103, 0x107, 0x7, 0x59, 0x2, 0x2, 0x104, 0x107, 0x7, 0x58, 
       0x2, 0x2, 0x105, 0x107, 0x7, 0x5d, 0x2, 0x2, 0x106, 0xff, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x103, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0x108, 0x109, 0x7, 0x3a, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x1a, 
       0xe, 0x2, 0x10a, 0x10e, 0x7, 0x3c, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0xc, 
       0x7, 0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x3, 0x2, 
       0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 
       0x2, 0x2, 0x10f, 0x118, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 
       0x2, 0x2, 0x111, 0x112, 0x7, 0x3b, 0x2, 0x2, 0x112, 0x113, 0x5, 0x1a, 
       0xe, 0x2, 0x113, 0x114, 0x7, 0x3c, 0x2, 0x2, 0x114, 0x115, 0x5, 0xc, 
       0x7, 0x2, 0x115, 0x117, 0x3, 0x2, 0x2, 0x2, 0x116, 0x111, 0x3, 0x2, 
       0x2, 0x2, 0x117, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 0x2, 
       0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x122, 0x3, 0x2, 
       0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11f, 0x7, 0x3d, 
       0x2, 0x2, 0x11c, 0x11e, 0x5, 0xc, 0x7, 0x2, 0x11d, 0x11c, 0x3, 0x2, 
       0x2, 0x2, 0x11e, 0x121, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11d, 0x3, 0x2, 
       0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 0x3, 0x2, 
       0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11b, 0x3, 0x2, 
       0x2, 0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 
       0x2, 0x2, 0x124, 0x125, 0x7, 0x3e, 0x2, 0x2, 0x125, 0x2d, 0x3, 0x2, 
       0x2, 0x2, 0x126, 0x127, 0x7, 0x3f, 0x2, 0x2, 0x127, 0x128, 0x5, 0x1a, 
       0xe, 0x2, 0x128, 0x129, 0x7, 0x40, 0x2, 0x2, 0x129, 0x131, 0x5, 0x30, 
       0x19, 0x2, 0x12a, 0x12e, 0x7, 0x3d, 0x2, 0x2, 0x12b, 0x12d, 0x5, 
       0xc, 0x7, 0x2, 0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x130, 0x3, 
       0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 
       0x2, 0x2, 0x2, 0x12f, 0x132, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12e, 0x3, 
       0x2, 0x2, 0x2, 0x131, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 
       0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x7, 
       0x41, 0x2, 0x2, 0x134, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x5, 
       0x32, 0x1a, 0x2, 0x136, 0x13a, 0x7, 0xc, 0x2, 0x2, 0x137, 0x139, 
       0x5, 0xc, 0x7, 0x2, 0x138, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 
       0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x13b, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x135, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 
       0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x31, 0x3, 0x2, 0x2, 0x2, 0x141, 0x146, 
       0x5, 0x1a, 0xe, 0x2, 0x142, 0x143, 0x7, 0xd, 0x2, 0x2, 0x143, 0x145, 
       0x5, 0x1a, 0xe, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x148, 
       0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 
       0x3, 0x2, 0x2, 0x2, 0x147, 0x33, 0x3, 0x2, 0x2, 0x2, 0x148, 0x146, 
       0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x2e, 0x2, 0x2, 0x14a, 0x14b, 
       0x5, 0x16, 0xc, 0x2, 0x14b, 0x14c, 0x7, 0x2f, 0x2, 0x2, 0x14c, 0x14f, 
       0x5, 0x1a, 0xe, 0x2, 0x14d, 0x14e, 0x7, 0x30, 0x2, 0x2, 0x14e, 0x150, 
       0x5, 0x1a, 0xe, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 
       0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x155, 
       0x7, 0x33, 0x2, 0x2, 0x152, 0x154, 0x5, 0xc, 0x7, 0x2, 0x153, 0x152, 
       0x3, 0x2, 0x2, 0x2, 0x154, 0x157, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 
       0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x158, 
       0x3, 0x2, 0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 
       0x7, 0x31, 0x2, 0x2, 0x159, 0x35, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 
       0x7, 0x32, 0x2, 0x2, 0x15b, 0x15c, 0x5, 0x1a, 0xe, 0x2, 0x15c, 0x160, 
       0x7, 0x33, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0xc, 0x7, 0x2, 0x15e, 0x15d, 
       0x3, 0x2, 0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 
       0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x163, 
       0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 
       0x7, 0x34, 0x2, 0x2, 0x164, 0x37, 0x3, 0x2, 0x2, 0x2, 0x165, 0x169, 
       0x7, 0x35, 0x2, 0x2, 0x166, 0x168, 0x5, 0xc, 0x7, 0x2, 0x167, 0x166, 
       0x3, 0x2, 0x2, 0x2, 0x168, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 
       0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16c, 
       0x3, 0x2, 0x2, 0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 
       0x7, 0x36, 0x2, 0x2, 0x16d, 0x16e, 0x5, 0x1a, 0xe, 0x2, 0x16e, 0x16f, 
       0x7, 0x37, 0x2, 0x2, 0x16f, 0x39, 0x3, 0x2, 0x2, 0x2, 0x170, 0x177, 
       0x5, 0x3c, 0x1f, 0x2, 0x171, 0x177, 0x5, 0x4e, 0x28, 0x2, 0x172, 
       0x177, 0x5, 0x52, 0x2a, 0x2, 0x173, 0x177, 0x5, 0x3e, 0x20, 0x2, 
       0x174, 0x177, 0x5, 0x40, 0x21, 0x2, 0x175, 0x177, 0x7, 0x59, 0x2, 
       0x2, 0x176, 0x170, 0x3, 0x2, 0x2, 0x2, 0x176, 0x171, 0x3, 0x2, 0x2, 
       0x2, 0x176, 0x172, 0x3, 0x2, 0x2, 0x2, 0x176, 0x173, 0x3, 0x2, 0x2, 
       0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 
       0x2, 0x177, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x9, 0x7, 0x2, 
       0x2, 0x179, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0x4, 0x2, 
       0x2, 0x17b, 0x180, 0x7, 0x59, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0xd, 0x2, 
       0x2, 0x17d, 0x17f, 0x7, 0x59, 0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 
       0x2, 0x17f, 0x182, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 
       0x2, 0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 0x3, 0x2, 0x2, 
       0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x7, 0x5, 0x2, 
       0x2, 0x184, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x5, 0x3c, 0x1f, 
       0x2, 0x186, 0x187, 0x7, 0x4, 0x2, 0x2, 0x187, 0x188, 0x5, 0x1a, 0xe, 
       0x2, 0x188, 0x189, 0x7, 0xe, 0x2, 0x2, 0x189, 0x18a, 0x5, 0x1a, 0xe, 
       0x2, 0x18a, 0x18b, 0x7, 0x5, 0x2, 0x2, 0x18b, 0x41, 0x3, 0x2, 0x2, 
       0x2, 0x18c, 0x191, 0x5, 0x44, 0x23, 0x2, 0x18d, 0x18e, 0x7, 0xd, 
       0x2, 0x2, 0x18e, 0x190, 0x5, 0x44, 0x23, 0x2, 0x18f, 0x18d, 0x3, 
       0x2, 0x2, 0x2, 0x190, 0x193, 0x3, 0x2, 0x2, 0x2, 0x191, 0x18f, 0x3, 
       0x2, 0x2, 0x2, 0x191, 0x192, 0x3, 0x2, 0x2, 0x2, 0x192, 0x43, 0x3, 
       0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x7, 
       0x59, 0x2, 0x2, 0x195, 0x196, 0x7, 0x44, 0x2, 0x2, 0x196, 0x19c, 
       0x5, 0x1a, 0xe, 0x2, 0x197, 0x198, 0x7, 0x59, 0x2, 0x2, 0x198, 0x199, 
       0x7, 0x45, 0x2, 0x2, 0x199, 0x19c, 0x5, 0x46, 0x24, 0x2, 0x19a, 0x19c, 
       0x5, 0x1a, 0xe, 0x2, 0x19b, 0x194, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x19b, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x8, 0x24, 0x1, 0x2, 0x19e, 0x1b0, 
       0x7, 0x59, 0x2, 0x2, 0x19f, 0x1ab, 0x7, 0x59, 0x2, 0x2, 0x1a0, 0x1a1, 
       0x7, 0x10, 0x2, 0x2, 0x1a1, 0x1a6, 0x5, 0x1a, 0xe, 0x2, 0x1a2, 0x1a3, 
       0x7, 0xd, 0x2, 0x2, 0x1a3, 0x1a5, 0x5, 0x1a, 0xe, 0x2, 0x1a4, 0x1a2, 
       0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a9, 
       0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 
       0x7, 0x11, 0x2, 0x2, 0x1aa, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a0, 
       0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ab, 
       0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 
       0x3, 0x2, 0x2, 0x2, 0x1af, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x19f, 
       0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 
       0xc, 0x4, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0xf, 0x2, 0x2, 0x1b3, 0x1b5, 
       0x5, 0x46, 0x24, 0x5, 0x1b4, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b8, 
       0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 
       0x3, 0x2, 0x2, 0x2, 0x1b7, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b6, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1bc, 0x5, 0x4a, 0x26, 0x2, 0x1ba, 0x1bc, 
       0x5, 0x4c, 0x27, 0x2, 0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1ba, 
       0x3, 0x2, 0x2, 0x2, 0x1bc, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1c1, 
       0x9, 0x8, 0x2, 0x2, 0x1be, 0x1c0, 0x5, 0x4c, 0x27, 0x2, 0x1bf, 0x1be, 
       0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bf, 
       0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c4, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 
       0x7, 0x1a, 0x2, 0x2, 0x1c5, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 
       0x7, 0x59, 0x2, 0x2, 0x1c7, 0x1cb, 0x7, 0xc, 0x2, 0x2, 0x1c8, 0x1cc, 
       0x5, 0x3a, 0x1e, 0x2, 0x1c9, 0x1cc, 0x5, 0x4e, 0x28, 0x2, 0x1ca, 
       0x1cc, 0x5, 0x52, 0x2a, 0x2, 0x1cb, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
       0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cc, 
       0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x7, 0x44, 0x2, 0x2, 0x1ce, 
       0x1d0, 0x5, 0x1a, 0xe, 0x2, 0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
       0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
       0x1d2, 0x7, 0x3, 0x2, 0x2, 0x1d2, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
       0x1d4, 0x7, 0x12, 0x2, 0x2, 0x1d4, 0x1d5, 0x7, 0x10, 0x2, 0x2, 0x1d5, 
       0x1da, 0x5, 0x50, 0x29, 0x2, 0x1d6, 0x1d7, 0x7, 0xd, 0x2, 0x2, 0x1d7, 
       0x1d9, 0x5, 0x50, 0x29, 0x2, 0x1d8, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
       0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 
       0x1db, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
       0x1da, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x7, 0x11, 0x2, 0x2, 0x1de, 
       0x1df, 0x7, 0x40, 0x2, 0x2, 0x1df, 0x1e0, 0x5, 0x3a, 0x1e, 0x2, 0x1e0, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x5, 0x1a, 0xe, 0x2, 0x1e2, 
       0x1e3, 0x7, 0xe, 0x2, 0x2, 0x1e3, 0x1e4, 0x5, 0x1a, 0xe, 0x2, 0x1e4, 
       0x51, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e7, 0x7, 0x13, 0x2, 0x2, 0x1e6, 
       0x1e8, 0x5, 0x54, 0x2b, 0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 
       0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
       0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 
       0x1ec, 0x7, 0x14, 0x2, 0x2, 0x1ec, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1ed, 
       0x1ee, 0x7, 0x59, 0x2, 0x2, 0x1ee, 0x1ef, 0x7, 0xc, 0x2, 0x2, 0x1ef, 
       0x1f0, 0x5, 0x3a, 0x1e, 0x2, 0x1f0, 0x1f1, 0x7, 0x3, 0x2, 0x2, 0x1f1, 
       0x55, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x7, 0x1b, 0x2, 0x2, 0x1f3, 
       0x1f4, 0x7, 0x59, 0x2, 0x2, 0x1f4, 0x1f5, 0x7, 0xc, 0x2, 0x2, 0x1f5, 
       0x1f7, 0x5, 0x3a, 0x1e, 0x2, 0x1f6, 0x1f8, 0x5, 0x8, 0x5, 0x2, 0x1f7, 
       0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f8, 
       0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x5, 0xa, 0x6, 0x2, 0x1fa, 
       0x1fb, 0x7, 0x1c, 0x2, 0x2, 0x1fb, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1fc, 
       0x1fd, 0x7, 0x1d, 0x2, 0x2, 0x1fd, 0x1ff, 0x7, 0x59, 0x2, 0x2, 0x1fe, 
       0x200, 0x5, 0x8, 0x5, 0x2, 0x1ff, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
       0x200, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x205, 0x5, 0xa, 0x6, 0x2, 0x202, 0x204, 0x5, 0x5a, 0x2e, 0x2, 0x203, 
       0x202, 0x3, 0x2, 0x2, 0x2, 0x204, 0x207, 0x3, 0x2, 0x2, 0x2, 0x205, 
       0x203, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x208, 0x3, 0x2, 0x2, 0x2, 0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x208, 
       0x209, 0x7, 0x1e, 0x2, 0x2, 0x209, 0x59, 0x3, 0x2, 0x2, 0x2, 0x20a, 
       0x20b, 0x7, 0x42, 0x2, 0x2, 0x20b, 0x20c, 0x7, 0x59, 0x2, 0x2, 0x20c, 
       0x20d, 0x7, 0xc, 0x2, 0x2, 0x20d, 0x20f, 0x5, 0x3a, 0x1e, 0x2, 0x20e, 
       0x210, 0x5, 0x8, 0x5, 0x2, 0x20f, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20f, 
       0x210, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 
       0x212, 0x5, 0xa, 0x6, 0x2, 0x212, 0x213, 0x7, 0x43, 0x2, 0x2, 0x213, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x5f, 0x67, 0x6c, 0x74, 0x79, 0x7d, 
       0x81, 0x85, 0x89, 0x8d, 0x90, 0x94, 0x99, 0x9e, 0xa6, 0xa9, 0xaf, 
       0xbd, 0xc8, 0xd4, 0xd6, 0xe1, 0xec, 0xf7, 0xfb, 0x106, 0x10e, 0x118, 
       0x11f, 0x122, 0x12e, 0x131, 0x13a, 0x13f, 0x146, 0x14f, 0x155, 0x160, 
       0x169, 0x176, 0x180, 0x191, 0x19b, 0x1a6, 0x1ad, 0x1af, 0x1b6, 0x1bb, 
       0x1c1, 0x1cb, 0x1cf, 0x1da, 0x1e9, 0x1f7, 0x1ff, 0x205, 0x20f, 
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
