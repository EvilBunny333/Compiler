%{
	#include<stdio.h>
%}

%token STRING INT IF ELSE FOR WHILE FLOAT BOOL INTNUMBER FLOATNUMBER ARRAY 
%left '+' '-'
%left '*' '/'

%nonassoc IFX 
%nonassoc ELSE

%% 
input : input line
| line
;

line : M {printf("result %d\n",$$);}
| V 
{
if($$ == 1){
printf("statement returns true\n");
}
else{
printf("statement returns false\n");
}
}
| Stmt {printf("statement returns %d\n",$$);}
| Var {printf("var is %d\n",$$);}
| line '\n'
;
Stmt: IF '(' V ')' '{' M '}' %prec IFX {printf("IF");return 0;}
| IF '(' V ')' '{' M '}' ELSE '{' M '}' {printf("IF ELSE");}
| WHILE '(' V ')' '{' M '}' {printf("WHILE");}
| FOR '(' INTNUMBER ',' V ',' M ')' '{' M '}' {printf("FOR");}
;
V: '(' V ')' {$$ = $2;}
| M '=' '=' M {$$ = ($1 == $4);}
| M '>' M {$$ = ($1 > $3);}
| M '<' M {$$ = ($1 < $3);}
| M '>' '=' M {$$ = ($1 >= $4);}
| M '<' '=' M {$$ = ($1 <= $4);}
;
M: '(' M ')'
| M '+' M {$$ = $1 + $3;}
| M '-' M {$$ = $1 - $3;}
| M '*' M {$$ = $1 * $3;}
| M '/' M {$$ = $1 / $3;}
| INTNUMBER {$$ = $1;}
| FLOATNUMBER {$$ = $1;}
;

Var: INT STRING '=' M
| FLOAT STRING '=' M
;

%%

extern FILE *yyin;

main(){
printf("Type in a calculation\n");
yyparse();
}

yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}