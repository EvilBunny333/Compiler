%{
	#include<stdio.h>
%}

%token STRING INT IF ELSE FOR WHILE FLOAT BOOL INTNUMBER FLOATNUMBER ARRAY 
%left '+' '-'
%left '*' '/'
%left '(' ')'
%% 
S : Stmt {printf("STMT");}
;
Stmt: IF V '{' M '}' {printf("IF");}
| IF V '{' M '}' ELSE '{' M '}' {printf("IF ELSE");}
| WHILE V '{' M '}' {}
| FOR '(' INTNUMBER ',' V ',' M ')' '{' M '}' {}
| M {printf("Result = %d\n", $$);return 0;}
;
M: M '+' M {$$ = $1 + $3;}
| M '-' M {$$ = $1 - $3;}
| M '*' M {$$ = $1 * $3;}
| M '/' M {$$ = $1 / $3;}
| INTNUMBER {$$ = $1;}
;
V:'(' M '=' '=' M ')' {}
| '(' M '>' M ')' {}
| '(' M '<' M ')' {}
| '(' M '>' '=' M ')' {}
| '(' M '<' '=' M ')' {}
;
%%

extern FILE *yyin;

main(){
printf("Type in a calculation\n");
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