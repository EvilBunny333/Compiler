%{
	#include<stdio.h>
%}

%token STRING INT IF ELSE FOR WHILE FLOAT BOOL INTNUMBER FLOATNUMBER ARRAY 
%left '+' '-'
%left '*' '/'
%left '(' ')'
%% 
S : M 
| V
| Stmt
| Var
;
Stmt: IF V M {printf("IF");return 0;}
| IF V M ELSE M {printf("IF ELSE");}
| WHILE V M {printf("WHILE");}
| FOR '(' INTNUMBER ',' V ',' M ')' M {printf("FOR");}
;
V: '(' V ')' {}
| M '=' '=' M {$$ = ($1 == $4);printf("V");}
| M '>' M {printf("V");}
| M '<' M {printf("V");}
| M '>' '=' M {printf("V");}
| M '<' '=' M {printf("V");}
;
M: '{' M '}' {}
| M '+' M {$$ = $1 + $3;printf("M");}
| M '-' M {$$ = $1 - $3;printf("M");}
| M '*' M {$$ = $1 * $3;printf("M");}
| M '/' M {$$ = $1 / $3;printf("M");}
| INTNUMBER {printf("number");}
;

Var: INT STRING '=' INTNUMBER
| FLOAT STRING '=' FLOATNUMBER
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