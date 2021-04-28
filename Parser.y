%{
	#include<stdio.h>
%}

%token MATH NUMBER KEYWORD STRING

%% 
calc: NUMBER MATH NUMBER {printf("This is a Calculation");};
%%

extern FILE *yyin;

main(){
yylex();
 while(!feof(yyin)){
  yyparse();
 }
}

yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}