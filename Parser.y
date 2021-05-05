%{
	#include<stdio.h>
%}

%token NUMBER STRING INT
%left '+' '-'
%left '*' '/'

%% 
S : M {
printf("Result = %d\n", $$);
return 0;
}

M: M '+' M {$$ = $1 + $3;}
| M '-' M {$$ = $1 - $3;}
| M '*' M {$$ = $1 * $3;}
| M '/' M {$$ = $1 / $3;}
| NUMBER {$$ = $1;}
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