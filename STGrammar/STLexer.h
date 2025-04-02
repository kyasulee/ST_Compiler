
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
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, VAR = 38, 
    VAR_INPUT = 39, VAR_OUTPUT = 40, VAR_IN_OUT = 41, VAR_TEMP = 42, END_VAR = 43, 
    FUNCTION = 44, END_FUNCTION = 45, FUNCTION_BLOCK = 46, END_FUNCTION_BLOCK = 47, 
    INT = 48, SINT = 49, DINT = 50, LINT = 51, USINT = 52, UINT = 53, UDINT = 54, 
    ULINT = 55, REAL = 56, LREAL = 57, BOOL = 58, BYTE = 59, WORD = 60, 
    DWORD = 61, LWORD = 62, FOR = 63, TO = 64, BY = 65, END_FOR = 66, WHILE = 67, 
    DO = 68, END_WHILE = 69, REPEAT = 70, UNTIL = 71, END_REPEAT = 72, PROGRAM = 73, 
    END_PROGRAM = 74, IF = 75, ELSEIF = 76, THEN = 77, ELSE = 78, END_IF = 79, 
    CASE = 80, OF = 81, END_CASE = 82, METHOD = 83, END_METHOD = 84, ASSIGN = 85, 
    ARROW = 86, NUMBER = 87, IDENT = 88, WS = 89, COMMENT_LINE = 90, COMMENT_PARA = 91, 
    STRING_LITERAL = 92, PREFIX_OP = 93
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

