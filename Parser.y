%{
	#include<stdio.h>
	#include<string.h>

	union Value {
	int intval;
	float floatval;
	char *strval;
	int boolval;
	};

	typedef struct Variable{
	char *name;
	int type; //0 = int, 1 = float;
	union Value value;
	} Variable;

	Variable symbols[50];
	int attr = -1;
%}

%union {int i;char *str; float fl;};

%token<int> INTNUMBER
%token<float> FLOATNUMBER
%token<str> STRING 
%token IF ELSE FOR WHILE PRINT INT  FLOAT BOOL

%left '+' '-'
%left '*' '/'

%nonassoc IFX 
%nonassoc ELSE

%start input
%type<int> V M Var Stmt line print

%% 

input: 
input line
| line
;

line: 
M 
| V 
	{
	if($<i>1 == 1){printf("statement returns true\n");}
	else{printf("statement returns false\n");}
	}
| Stmt {printf("statement returns %d\n",$<i>$);}
| Var 
| print
| line '\n'
;

Stmt: 
IF '(' V ')' '{' line '}' %prec IFX 
	{
	printf("IF");
	if($<i>3 ==1) {$<i>$ = $<i>6;}
	else{$<i>$ = 0;}
	}
| IF '(' V ')' '{' line '}' ELSE '{' line '}' 
	{
	printf("IF ELSE");
	if($<i>3 ==1) {$<i>$ = $<i>6;}
	else{$<i>$ = $<i>10;}
	}
| WHILE '(' V ')' '{' line '}' {printf("WHILE");}
;

V: 
'(' V ')' {$<i>$ = $<i>2;}
| M '=' '=' M {$<i>$ = ($<i>1 == $<i>4);}
| M '>' M {$<i>$ = ($<i>1 > $<i>3);}
| M '<' M {$<i>$ = ($<i>1 < $<i>3);}
| M '>' '=' M {$<i>$ = ($<i>1 >= $<i>4);}
| M '<' '=' M {$<i>$ = ($<i>1 <= $<i>4);}
;

M: 
'(' M ')' {$<fl>$ = $<fl>2;}
| M '+' M {$<fl>$ = $<fl>1 + $<fl>3;}
| M '-' M {$<fl>$ = $<fl>1 - $<fl>3;}
| M '*' M {$<fl>$ = $<fl>1 * $<fl>3;}
| M '/' M {$<fl>$ = $<fl>1 / $<fl>3;}
| INTNUMBER {$<i>$ = $<i>1;}
| FLOATNUMBER {$<fl>$ = $<fl>1;}
| STRING '=' M {
	$<i>$ = $<i>3;
	int var = findvar($<str>1);
	if(var >= 0 ){symbols[var].value.intval = $<i>3;} else {printf("unknown variable name");}
	}
| STRING { 
	int var = findvar(yylval.str);
	if(var >= 0 ){$<i>$ = symbols[var].value.intval;} else {printf("unknown variable name");}
	}
;

Var: 
INT STRING '=' INTNUMBER {
	int check = checkReDecl($<str>2);
	if(check ==1){
	$<i>$ = $<i>4;
	attr++;
	Variable var = { .name = $<str>2, .type = 0, .value.intval = $<i>4};
	symbols[attr] = var;
	}
	}
| FLOAT STRING '=' FLOATNUMBER {
	int check = checkReDecl($<str>2);
	if(check ==1){
	$<fl>$ = $<fl>4;
	attr++;
	struct Variable var = { .name = $<str>2, .type = 1, .value.floatval = $<fl>4};
	symbols[attr] = var;
	}
	}
| STRING STRING '=' STRING {
	int check = checkReDecl($<str>2);
	if(check ==1){
	$<i>$ = $<i>4;
	attr++;
	Variable var = { .name = $<str>2, .type = 2, .value.strval = $<str>4};
	symbols[attr] = var;
	}
	}
| BOOL STRING '=' INTNUMBER {
	if($<i>4 == 0 | $<i>4 == 1 ){
	int check = checkReDecl($<str>2);
	if(check ==1){
	$<i>$ = $<i>4;
	attr++;
	Variable var = { .name = $<str>2, .type = 3, .value.boolval = $<i>4};
	symbols[attr] = var;
	}
	}
	else{printf("Not a bool Value.\n");}
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

int findvar(char name[])
{
	int var = -1;
	int i=0;
	for(i = 0; i<=attr;i++){ 
	if(strcmp(symbols[i].name, name) == 0){
	var = i;
	return var;
	}
	}
	return var;
}

int checkReDecl(char name[]){
int var = findvar(name);
if(var >= 0){printf("The Variable is already declared.\n");return 0;}
else{return 1;}
}

yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
return 0;
}

printlist(){
int i=0;
for(i = 0; i<=attr;i++){
if(symbols[i].type == 0){
printf("%d name is %s, value is %d, type is int\n", i,symbols[i].name,symbols[i].value.intval);
}
else if(symbols[i].type == 1){
printf("%d name is %s, value is %f, type is float\n", i,symbols[i].name,symbols[i].value.floatval);
}
else if(symbols[i].type == 2){
printf("%d name is %s, value is %s, type is string\n", i,symbols[i].name,symbols[i].value.strval);
}
else if(symbols[i].type == 3){
printf("%d name is %s, value is %d, type is bool\n", i,symbols[i].name,symbols[i].value.boolval);
}
}
}





