
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
    T__38 = 39, VAR = 40, VAR_INPUT = 41, VAR_OUTPUT = 42, VAR_IN_OUT = 43, 
    VAR_TEMP = 44, END_VAR = 45, FUNCTION = 46, END_FUNCTION = 47, FUNCTION_BLOCK = 48, 
    END_FUNCTION_BLOCK = 49, INT = 50, SINT = 51, DINT = 52, LINT = 53, 
    USINT = 54, UINT = 55, UDINT = 56, ULINT = 57, REAL = 58, LREAL = 59, 
    BOOL = 60, BYTE = 61, WORD = 62, DWORD = 63, LWORD = 64, FOR = 65, TO = 66, 
    BY = 67, END_FOR = 68, WHILE = 69, DO = 70, END_WHILE = 71, REPEAT = 72, 
    UNTIL = 73, END_REPEAT = 74, PROGRAM = 75, END_PROGRAM = 76, IF = 77, 
    ELSEIF = 78, THEN = 79, ELSE = 80, END_IF = 81, CASE = 82, OF = 83, 
    END_CASE = 84, METHOD = 85, END_METHOD = 86, ASSIGN = 87, ARROW = 88, 
    NUMBER = 89, IDENT = 90, WS = 91, COMMENT_LINE = 92, COMMENT_PARA = 93, 
    STRING_LITERAL = 94
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

