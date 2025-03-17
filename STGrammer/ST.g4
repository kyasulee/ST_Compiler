grammar ST;

program: statement* EOF;

NUMBER
    : [0-9]+
    ;

IDENT
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

// Keywords
VAR
    : 'VAR'
    ;

IF
    : 'IF'
    ;

THEN
    : 'THEN'
    ;

ELSE
    : 'ELSE'
    ;

END_IF
    : 'END_IF'
    ;

FOR
    : 'FOR'
    ;

TO
    : 'TO'
    ;

DO
    : 'DO'
    ;

END_FOR
    : 'END_FOR'
    ;

ASSIGN
    : ':='
    ;

// Operators
ADD
    : '+'
    ;

MINUS
    : '-'
    ;

MUL
    : '*'
    ;

DIV
    : '/'
    ;

// Delimiters
SEMI
    : ';'
    ;

COLON
    : ':'
    ;

LPAREN
    : '('
    ;

RPAREN
    : ')'
    ;

WS
    : [ \t\r\n]+ -> skip
    ;


statement
    : varDeclaration
    | assignStmt
    | ifStmt
    | forStmt
    ;

// Variable Declaration
varDeclaration
    : 'VAR' ID ':' type ';' 'END_VAR'
    ;

// Assignment Statement
assignStmt
    : ID ':=' expr ';'
    ;

expr
    : addExpr
    ;

addExpr
    : mulExpr (('+' | '-') mulExpr)*
    ;

mulExpr
    :  primary (('*' | '/') primary)*
    ;

primary
    : '(' expr ')'
    | ID
    | NUMBER
    ;

ifStmt
    : 'IF' expr 'THEN' statement* ('ELSE' statement*)?  'END_IF'
    ;

forStmt
    :  'FOR' ID ':=' expr 'TO' expr 'DO' statement* 'END_FOR'
    ;

type
    : 'INT'
    | 'REAL'
    | 'BOOL'
    | 'WORD'
    ;
