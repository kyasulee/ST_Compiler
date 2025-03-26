
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
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, VAR = 37, VAR_INPUT = 38, 
    VAR_OUTPUT = 39, VAR_IN_OUT = 40, VAR_TEMP = 41, END_VAR = 42, FUNCTION = 43, 
    END_FUNCTION = 44, FUNCTION_BLOCK = 45, END_FUNCTION_BLOCK = 46, INT = 47, 
    SINT = 48, DINT = 49, LINT = 50, USINT = 51, UINT = 52, UDINT = 53, 
    ULINT = 54, REAL = 55, LREAL = 56, BOOL = 57, BYTE = 58, WORD = 59, 
    DWORD = 60, LWORD = 61, FOR = 62, TO = 63, BY = 64, END_FOR = 65, WHILE = 66, 
    DO = 67, END_WHILE = 68, REPEAT = 69, UNTIL = 70, END_REPEAT = 71, PROGRAM = 72, 
    END_PROGRAM = 73, IF = 74, THEN = 75, ELSE = 76, END_IF = 77, CASE = 78, 
    OF = 79, END_CASE = 80, NUMBER = 81, IDENT = 82, WS = 83, COMMENT_LINE = 84, 
    COMMENT_PARA = 85
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

