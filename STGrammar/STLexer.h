
// Generated from ST.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  STLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, VAR = 42, VAR_INPUT = 43, VAR_OUTPUT = 44, 
    VAR_IN_OUT = 45, VAR_TEMP = 46, END_VAR = 47, FUNCTION = 48, END_FUNCTION = 49, 
    FUNCTION_BLOCK = 50, END_FUNCTION_BLOCK = 51, INT = 52, SINT = 53, DINT = 54, 
    LINT = 55, USINT = 56, UINT = 57, UDINT = 58, ULINT = 59, REAL = 60, 
    LREAL = 61, BOOL = 62, BYTE = 63, WORD = 64, DWORD = 65, LWORD = 66, 
    FOR = 67, TO = 68, BY = 69, END_FOR = 70, WHILE = 71, DO = 72, END_WHILE = 73, 
    REPEAT = 74, UNTIL = 75, END_REPEAT = 76, PROGRAM = 77, END_PROGRAM = 78, 
    IF = 79, ELSEIF = 80, THEN = 81, ELSE = 82, END_IF = 83, CASE = 84, 
    OF = 85, END_CASE = 86, METHOD = 87, END_METHOD = 88, NUMBER = 89, IDENT = 90, 
    WS = 91, COMMENT_LINE = 92, COMMENT_PARA = 93, STRING_LITERAL = 94
  };

  explicit STLexer(antlr4::CharStream *input);
  ~STLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

