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

/* Auflistung Tokens */
%token<i> INTNUMBER
%token<fl> FLOATNUMBER
%token<str> STRING 
%token IF ELSE FOR WHILE PRINT INT  FLOAT BOOL

/* Priorisierung der Rechenarten */
%left '+' '-'
%left '*' '/'
%right '=' '<' '>'

/*  */

%start input
%type<i> V M Var Stmt line print

%% 
/* Deklarationen */
input : input line
| line
;

line : M {printf("result %d\n",$$);}
| V 
{
if($<i>1 == 1){printf("statement returns true\n");}
else{printf("statement returns false\n");}
}
| Stmt 
| Var 
| print
| line '\n'
;

/* Statemens */
Stmt: IF '(' V ')' '{' line '}' { 
/* IF */
if($3 == 1){$$ = $6; printf("statement returns %d\n",$<i>$);}else{printf("statement is false"); } ;}

/*  Errorhandling IF */
|IF error V ')' '{' line '}' {yyerror (" '(' in expression expected\n");}
|IF '(' error ')' '{' line '}' {yyerror (" no comparison\n");}
|IF '(' V error '{' line '}' {yyerror (" ')' in expression expected\n");}
|IF '(' V ')' error line '}' {yyerror (" '{' in expression expected\n");}
|IF '(' V ')' '{' error '}' {yyerror ("there is nothing to be excecuted\n");}
|IF '(' V ')' '{' line error {yyerror (" '}' in expression expected\n");}

/* IF ELSE */
| IF '(' V ')' '{' line '}' ELSE '{' line '}' { 
if($3 == 1){$$ = $6; printf("statement returns %d\n",$$);}
else{ printf("statement returns %d\n",$10);} }

/*  Errorhandling IF ELSE*/
|IF error V ')' '{' line '}'  ELSE '{' line '}' {yyerror (" '(' in expression expected\n");}
|IF '(' error ')' '{' line '}' ELSE '{' line '}'{yyerror (" no comparison\n");}
|IF '(' V error '{' line '}' ELSE '{' line '}' {yyerror (" ')' in expression expected\n");}
|IF '(' V ')' error line '}' ELSE '{' line '}' {yyerror (" '{' in IF expression expected\n");}
|IF '(' V ')' '{' error '}' ELSE '{' line '}' {yyerror ("there is nothing to be excecuted in your IF\n");}
|IF '(' V ')' '{' line error ELSE '{' line '}' {yyerror (" '}' in IF expression expected\n");}
|IF '(' V ')' '{' line '}' ELSE error line '}' {yyerror (" '{' in ELSE expression expected\n");}
|IF '(' V ')' '{' line '}' ELSE '{' error '}' {yyerror ("there is nothing to be excecuted in your ELSE\n");}
|IF '(' V ')' '{' line '}' ELSE '{' line error {yyerror (" '}' in ELSE expression expected\n");}

/* WHILE */
| WHILE '(' V ')' '{' line '}' {
while($3 == 1){$$ = $6; printf("statement returns %d\n",$$);};}

/*  Errorhandling WHILE */
| WHILE error V ')' '{' line '}' {yyerror (" '(' in expression expected\n");}
| WHILE '(' error ')' '{' line '}' {yyerror (" no comparison\n");}
| WHILE '(' V error '{' line '}' {yyerror (" ')' in expression expected\n");}
| WHILE '(' V ')' error line '}' {yyerror (" '{' in expression expected\n");}
| WHILE '(' V ')' '{' error '}' {yyerror ("there is nothing to be excecuted\n");}
| WHILE '(' V ')' '{' line error {yyerror (" '}' in expression expected\n");}

/* FOR */
| FOR '(' INTNUMBER ')' '{' line '}' {
int a = 0;
for( a = 0; a < $3; a = a + 1 ){
      printf("statement returns %d\n",$<i>6);
   };}

/*  Errorhandling FOR */
| FOR error INTNUMBER ')' '{' line '}' {yyerror (" '(' in expression expected\n");}
| FOR '(' error ')' '{' line '}' {yyerror (" no counter\n");}
| FOR '(' INTNUMBER error '{' line '}' {yyerror (" ')' in expression expected\n");}
| FOR '(' INTNUMBER ')' error line '}' {yyerror (" '{' in expression expected\n");}
| FOR '(' INTNUMBER ')' '{' error '}' {yyerror ("there is nothing to be excecuted\n");}
| FOR '(' INTNUMBER ')' '{' line error {yyerror (" '}' in expression expected\n");}
;

/* Vergleichsarten */
V: '(' V ')' {$$ = $2;}
| M '=' '=' M {$$ = ($1 == $4);}
| M '>' M {$$ = ($1 > $3);}
| M '<' M {$$ = ($1 < $3);}
| M '>' '=' M {$$ = ($1 >= $4);}
| M '<' '=' M {$$ = ($1 <= $4);}
;

/* Rechenarten */
M: '(' M ')' {$$ = $2; }
| M '+' M {$$ = $1 + $3; }
| M '-' M {$$ = $1 - $3; }
| M '*' M {$$ = $1 * $3; }
| M '/' M {$$ = $1 / $3; }

/* Errorhandling '+' */
| error M '+' M ')' {yyerror (" '(' in expression expected\n");}
| '(' error '+' M ')' {yyerror (" first argument in expression missing\n");}
| '(' M '+' error ')' {yyerror (" second argument in expression missing\n");}
| '(' M '+' M error {yyerror (" ')' in expression expected\n"); }

/* Errorhandling '-' */
| error M '-' M ')' {yyerror (" '(' in expression expected\n");}
| '(' error '-' M ')' {yyerror (" first argument in expression missing\n");}
| '(' M '-' error ')' {yyerror (" second argument in expression missing\n");}
| '(' M '-' M error {yyerror (" ')' in expression expected\n"); }

/* Errorhandling '*' */
| error M '*' M ')' {yyerror (" '(' in expression expected\n");}
| '(' error '*' M ')' {yyerror (" first argument in expression missing\n");}
| '(' M '*' error ')' {yyerror (" second argument in expression missing\n");}
| '(' M '*' M error {yyerror (" ')' in expression expected\n"); }

/* Errorhandling '/' */
| error M '/' M ')' {yyerror (" '(' in expression expected\n");}
| '(' error '/' M ')' {yyerror (" first argument in expression missing\n");}
| '(' M '/' error ')' {yyerror (" second argument in expression missing\n");}
| '(' M '/' M error {yyerror (" ')' in expression expected\n"); }

| '(' M error M ')' {yyerror (" '+,-,*,/' in expression expected\n"); }

| INTNUMBER {$<i>$ = $<i>1;}
| FLOATNUMBER {$<fl>$ = $<fl>1;}
| STRING '=' M 
	{$$ = $3;
	int var = findvar($<str>1);
	if(var >= 0 ){symbols[var].value.intval = $<i>3;} else {printf("unknown variable name");}
	}
| STRING { 
	int var = findvar(yylval.str);
	if(var >= 0 ){$<i>$ = symbols[var].value.intval;} else {printf("unknown variable name");}
}
;

/* Variablenzuweisung */
Var: INT STRING '=' INTNUMBER {
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

/* Allgemeines Errorhandling */
yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}

/* Ausgabe aller Variablen mit Value  */
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

