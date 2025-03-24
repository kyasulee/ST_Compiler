grammar ST;

startpoint: program_list* EOF;

program_list
    : programDecl
    | functionDecl
    | functionBlockDecl
    ;

programDecl
    : 'PROGRAM' IDENT  declarationStmt?  statement_list*  'END_PROGRAM'
    ;

statement_list
    : assignStmt? ';'
    | selectStmt? ';'
    | iterationStmt? ';'
    | callFuncStmt? ';'
    | jumpStmt? ';'
    ;

selectStmt
    : ifStmt
    | caseStmt
    ;

iterationStmt
    : whileStmt
    | forStmt
    | repeatStmt
    ;

callFuncStmt
    : (IDENT | 'AND' | 'OR' | 'XOR' | 'MOD' | 'NOT') '(' (funcParams)? ')'
    ;

jumpStmt
    : 'BREAK'
    | 'RETURN'
    | 'CONTINUE'
    | 'EXIT'
    ;

NUMBER
    : [0-9]+
    ;

IDENT
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

WS
    : [ \t\r\n]+ -> skip
    ;


assignStmt
    : prefixExpr ':=' (expr | callFuncStmt)
    ;

prefixExpr
    : ident
    ;

expr
    : orExpr
    ;

orExpr
    : andExpr
    | orExpr ('OR' | 'XOR' | '|' | '^') andExpr
    ;

andExpr
    : equalExpr
    | andExpr ('AND' | '&') equalExpr
    ;

equalExpr
    : relationExpr
    | equalExpr '=' relationExpr
    | equalExpr ('!=' | '<>') relationExpr
    ;

relationExpr
    : addExpr
    | relationExpr ('>' | '>=' | '<' | '<=') addExpr
    ;

addExpr
    : multipliExpr
    | addExpr ( '+' | '-') multipliExpr
    ;

multipliExpr
    : unaryExpr
    | multipliExpr ('*' | '/' | '**' | '%') unaryExpr
    ;

unaryExpr
    : ('-'+ | '!' | 'NOT')? primary
    ;

primary
    : '(' expr ')'
    | IDENT
    | NUMBER
    ;

ifStmt
    : 'IF' expr 'THEN' statement_list* ('ELSE' statement_list*)?  'END_IF'
    ;

caseStmt
    : 'CASE' expr 'OF' caseList ('ELSE' statement_list*)? 'END_CASE'
    ;

caseList
    : (caseValues ':' statement_list*)+
    ;

caseValues
    : expr (',' expr)*
    ;

forStmt
    :  'FOR' assignStmt 'TO' expr ('BY' expr)? 'DO' statement_list* 'END_FOR'
    ;

whileStmt
    : 'WHILE' expr 'DO' statement_list* 'END_WHILE'
    ;

repeatStmt
    : 'REPEAT' statement_list* 'UNTIL' expr 'END_REPEAT'
    ;

type
    : 'INT' | 'SINT' | 'DINT' | 'LINT' | 'USINT' | 'UINT' | 'UDINT' | 'ULINT'
    | 'REAL' | 'LREAL'
    | 'BOOL' | 'BYTE' | 'WORD' | 'DWORD' | 'LWORD'
    ;

funcParams
    : IDENT (':=' expr? | '=>' (ident)? | expr) (',' funcParams)*
    | expr (',' expr)*
    ;

ident
    : IDENT                             # Identi
    | ident '.' ident                   # Struct
    | IDENT ('[' expr (',' expr)* ']')+ # Array
    ;


declarationStmt
    : varDeclarationBlock
    | varDeclaration
    ;

varDeclarationBlock
    : ('VAR' | 'VAR_INPUT' | 'VAR_OUTPUT' | 'VAR_IN_OUT' | 'VAR_TEMP')
      varDeclaration*
      'END_VAR'
    ;

varDeclaration
    :  IDENT ':' type (':=' NUMBER)? ';'
    ;

functionDecl
    : 'FUNCTION' IDENT ':' type varDeclarationBlock*  statement_list* 'END_FUNCTION'
    ;

functionBlockDecl
    : 'FUNCTION_BLOCK' IDENT  varDeclarationBlock*  statement_list* 'END_FUNCTION_BLOCK'
    ;