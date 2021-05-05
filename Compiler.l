%{
#include "Parser.tab.h"
#include <stdio.h>
#include <string.h>
#undef yywrap
#define yywrap() 1	
;
 
%} 

%%
[0-9]+   {yylval = (int)yytext; return NUMBER;} 
[\t\n]   ; 
"+"      {return PLUS;} 
"-"      {return MINUS;}
"*"      {return TIMES;} 
"/"      {return DIVIDE;} 
"^"      {return POWER;} 
"("      {return LEFT_PARENTHESIS;} 
")"      {return RIGHT_PARENTHESIS;} 
";"      {return END;} 
%% 