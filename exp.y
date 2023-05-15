%{
#include <stdio.h>
%}

%union {
    int num;
}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

program : expr '\n' { printf("%d\n", $1); }
        ;

expr : expr '+' expr { printf("t%d = t%d + t%d\n", ++$$,$1,$3); }
     | expr '-' expr { printf("t%d = t%d - t%d\n", ++$$,$1,$3); }
     | expr '*' expr { printf("t%d = t%d * t%d\n", ++$$,$1,$3); }
     | expr '/' expr { printf("t%d = t%d / t%d\n", ++$$,$1,$3); }
     | NUMBER { $$ = $1; printf("t%d = %d\n", $$, $1); }
     ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(char* msg) {
    printf("Error: %s\n", msg);
    return 0;
}
