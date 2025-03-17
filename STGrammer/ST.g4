grammar ST;

program: statement* EOF;

NUMBER
    : [0-9]+
    ;

IDENT
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

// 关键字
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

// 运算符
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

// 分隔符
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

// 注释
WS
    : [ \t\r\n]+ -> skip
    ;


statement
    : varDeclaration
    | assignStmt
    | ifStmt
    | forStmt
    ;

// 变量声明
varDeclaration
    : 'VAR' ID ':' type ';' 'END_VAR'
    ;

// 赋值语句
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
