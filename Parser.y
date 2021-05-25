%{
	#include<stdio.h>
	#include<string.h>

	union Value {
	int intval;
	float floatval;
	};

	typedef struct Variable{
	char *name;
	int type; //0 = int, 1 = float;
	union Value value;
	} Variable;

	Variable symbols[50];
	int attr = -1;
%}

%union {int i;char *str;};

%token<int> INTNUMBER FLOATNUMBER 
%token<str> STRING 
%token IF ELSE FOR WHILE PRINT ARRAY INT  FLOAT BOOL

%left '+' '-'
%left '*' '/'

%nonassoc IFX 
%nonassoc ELSE

%start input
%type<int> V M Var Stmt line print

%% 

input : input line
| line
;

line : M {printf("result %d\n",$<i>$);}
| V 
{
if($<i>1 == 1){printf("statement returns true\n");}
else{printf("statement returns false\n");}
}
| Stmt {printf("statement returns %d\n",$<i>$);}
| Var {printf("var is %d\n",$<i>$);}
| print
| line '\n'
;

Stmt: IF '(' V ')' '{' line '}' %prec IFX {printf("IF");return 0;}
| IF '(' V ')' '{' line '}' ELSE '{' line '}' {printf("IF ELSE");}
| WHILE '(' V ')' '{' line '}' {printf("WHILE");}
| FOR '(' INTNUMBER ',' V ',' M ')' '{' line '}' {printf("FOR");}
;

V: '(' V ')' {$<i>$ = $<i>2;}
| M '=' '=' M {$<i>$ = ($<i>1 == $<i>4);}
| M '>' M {$<i>$ = ($<i>1 > $<i>3);}
| M '<' M {$<i>$ = ($<i>1 < $<i>3);}
| M '>' '=' M {$<i>$ = ($<i>1 >= $<i>4);}
| M '<' '=' M {$<i>$ = ($<i>1 <= $<i>4);}
;

M: '(' M ')' {$<i>$ = $<i>2;}
| M '+' M {$<i>$ = $<i>1 + $<i>3;}
| M '-' M {$<i>$ = $<i>1 - $<i>3;}
| M '*' M {$<i>$ = $<i>1 * $<i>3;}
| M '/' M {$<i>$ = $<i>1 / $<i>3;}
| INTNUMBER {$<i>$ = $<i>1;}
| FLOATNUMBER {$<i>$ = $<i>1;}
| STRING { 
int var = -1;
int i=0;
for(i = 0; i<=attr;i++){
if(strcmp(symbols[i].name, yylval.str) == 0){
var = i;
break;
}
}
if(var >= 0 ){$<i>$ = symbols[var].value.intval;} else {printf("not a variable name");}}
;

Var: INT STRING '=' M {
$<i>$ = $<i>4;
attr++;
Variable var = { .name = $<str>2, .type = 0, .value.intval = $<i>4};
symbols[attr] = var;
}
| FLOAT STRING '=' M {
$<i>$ = $<i>4;
attr++;
struct Variable var = { .name = $<str>2, .type = 1, .value.floatval = $<i>4};
symbols[attr] = var;
}
;

print : PRINT {printlist();}
;

%%

extern FILE *yyin;
extern int yylex();
extern int yyparse();

main(){
printf("Type in a calculation\n");
yyparse();
}

yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}

printlist(){
int i=0;
for(i = 0; i<=attr;i++){
printf("%d name is %s\n", i,symbols[i].name);
printf("%d value is %d\n", i,symbols[i].value.intval);
}
}



