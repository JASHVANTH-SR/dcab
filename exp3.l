%{
#include "y.tab.h"
%}

DIGIT [0-9]
NUMBER {DIGIT}+(\.{DIGIT}+)?
WS [ \t\n]+

%%

{WS}              /* ignore whitespace */
{NUMBER}          { yylval.num = atof(yytext); return NUMBER; }
"("               { return LPAREN; }
")"               { return RPAREN; }
"+"               { return PLUS; }
"-"               { return MINUS; }
"*"               { return TIMES; }
"/"               { return DIVIDE; }

%%

int yywrap() {
    return 1;
}
