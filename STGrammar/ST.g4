grammar ST;

// lexer
VAR: 'VAR';
VAR_INPUT : 'VAR_INPUT';
VAR_OUTPUT: 'VAR_OUTPUT';
VAR_IN_OUT: 'VAR_IN_OUT';
VAR_TEMP: 'VAR_TEMP';
END_VAR: 'END_VAR';
FUNCTION: 'FUNCTION';
END_FUNCTION: 'END_FUNCTION';
FUNCTION_BLOCK: 'FUNCTION_BLOCK';
END_FUNCTION_BLOCK: 'END_FUNCTION_BLOCK';
INT: 'INT';
SINT: 'SINT';
DINT: 'DINT';
LINT: 'LINT';
USINT: 'USINT';
UINT: 'UINT';
UDINT: 'UDINT';
ULINT: 'ULINT';
REAL: 'REAL';
LREAL: 'LREAL';
BOOL : 'BOOL';
BYTE: 'BYTE';
WORD: 'WORD';
DWORD: 'DWORD';
LWORD: 'LWORD';
FOR: 'FOR';
TO: 'TO';
BY: 'BY';
END_FOR: 'END_FOR';
WHILE: 'WHILE';
DO: 'DO';
END_WHILE: 'END_WHILE';
REPEAT: 'REPEAT';
UNTIL: 'UNTIL';
END_REPEAT: 'END_REPEAT';
PROGRAM : 'PROGRAM';
END_PROGRAM: 'END_PROGRAM';
IF : 'IF';
ELSEIF: 'ELSEIF';
THEN: 'THEN';
ELSE: 'ELSE';
END_IF: 'END_IF';
CASE: 'CASE';
OF: 'OF';
END_CASE: 'END_CASE';
METHOD: 'METHOD';
END_METHOD: 'END_METHOD';

ASSIGN: ':=';
ARROW: '=>';

startpoint: program_list* EOF;

program_list
    : programDecl
    | functionDecl
    | functionBlockDecl
    ;

programDecl
    : PROGRAM IDENT  interfaceSection? bodySection  END_PROGRAM
    ;

interfaceSection
    : varDeclarationBlock+
    ;

bodySection
    : statement_list*
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
    : IDENT '(' funcParams? ')'
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

COMMENT_LINE
    :  '//' ~[\r\n]* -> skip
    ;

COMMENT_PARA
    :  '/*' .*? '*/' -> skip
    ;

STRING_LITERAL
    :  '"' (~["\\] | '\\' .)* '"'
    ;

PREFIX_OP
    :  ('-'+ | '!' | 'NOT')
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
    | multipliExpr ('*' | '/' | '**' | '%' | 'SHL' | 'SHR') unaryExpr
    ;

unaryExpr
    : PREFIX_OP? primary
    ;

primary
    : '(' expr ')'
    | IDENT
    | NUMBER
    | STRING_LITERAL
    ;

ifStmt
    : IF expr THEN statement_list* (ELSEIF expr THEN statement_list)* (ELSE statement_list*)?  END_IF
    ;

caseStmt
    : CASE expr OF caseList (ELSE statement_list*)? END_CASE
    ;

caseList
    : (caseValues ':' statement_list*)+
    ;

caseValues
    : expr (',' expr)*
    ;

forStmt
    :  FOR assignStmt TO expr (BY expr)? DO statement_list* END_FOR
    ;

whileStmt
    : WHILE expr DO statement_list* END_WHILE
    ;


repeatStmt
    : REPEAT statement_list* UNTIL expr END_REPEAT
    ;

type
    : basicType
    | arrayType
    | structType
    | enumeratedType
    | subrangeType
    | IDENT  // 用户定义类型
    ;

basicType
    : INT | SINT | DINT | LINT | USINT | UINT | UDINT | ULINT
    | REAL | LREAL
    | BOOL | BYTE | WORD | DWORD | LWORD
    ;

enumeratedType
    : '(' IDENT (',' IDENT)* ')'
    ;

subrangeType
    : basicType '(' expr '..' expr ')'
    ;

funcParams
    : funcParam (',' funcParam)*
    ;

funcParam
    : IDENT ASSIGN expr
    | IDENT ARROW ident
    | expr
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
    : (VAR | VAR_INPUT | VAR_OUTPUT | VAR_IN_OUT | VAR_TEMP)
      varDeclaration*
      END_VAR
    ;

varDeclaration
    :  IDENT ':' (type | arrayType | structType) (':=' expr)? ';'
    ;


arrayType
    : 'ARRAY' '[' range (',' range)* ']' 'OF' type
    ;

range
    : expr '..' expr
    ;

structType
    : 'STRUCT' structMember+ 'END_STRUCT'
    ;

structMember
    : IDENT ':' type ';'
    ;


functionDecl
    : FUNCTION IDENT ':' type interfaceSection?  bodySection END_FUNCTION
    ;

functionBlockDecl
    : FUNCTION_BLOCK IDENT  interfaceSection?  bodySection methodDecl* END_FUNCTION_BLOCK
    ;

methodDecl
    : METHOD IDENT ':' type interfaceSection? bodySection END_METHOD
    ;