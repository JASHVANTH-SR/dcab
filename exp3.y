%{
#include <stdio.h>
#include <stdlib.h>
%}

%union {
    double num;
}

%token <num> NUMBER
%token LPAREN RPAREN PLUS MINUS TIMES DIVIDE

%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc UMINUS

%%

input: /* empty */ 
     | input line
     ;

line: expr '\n' { printf("= %f\n", $1); }
    ;

expr: NUMBER
    | LPAREN expr RPAREN
    | expr PLUS expr
    | expr MINUS expr
    | expr TIMES expr
    | expr DIVIDE expr
    | MINUS expr %prec UMINUS
    ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(char* s) {
    printf("%s\n", s);
}

int yylex() {
    return yylex();
}
