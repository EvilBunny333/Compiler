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

/* Auflistung Tokens */
%token<int> INTNUMBER FLOATNUMBER 
%token<str> STRING 
%token IF ELSE FOR WHILE PRINT ARRAY INT  FLOAT BOOL

/* Priorisierung der Rechenarten */
%left '+' '-'
%left '*' '/'
%right '=' '<' '>'

/*  */
%nonassoc IFX 
%nonassoc ELSE

%start input
%type<int> V M Var Stmt line print

%% 
/* Deklarationen */
input : input line
| line
;

line : M {printf("result %d\n",$<i>$);}
| V 
{
if($<i>1 == 1){printf("statement returns true\n");}
else{printf("statement returns false\n");}
}
| Stmt {}
| Var {printf("var is %d\n",$<i>$);}
| print
| line '\n'
;

/* Statemens */
Stmt: IF '(' V ')' '{' line '}' { 
/* IF */
if($<i>3 == 1){$<i>$ = $<i>6; printf("statement returns %d\n",$<i>$);}else{printf("statement is false"); } ;}

/*  Errorhandling IF */
|IF error V ')' '{' line '}' {yyerror (" '(' in expression expected\n");}
|IF '(' error ')' '{' line '}' {yyerror (" no comparison\n");}
|IF '(' V error '{' line '}' {yyerror (" ')' in expression expected\n");}
|IF '(' V ')' error line '}' {yyerror (" '{' in expression expected\n");}
|IF '(' V ')' '{' error '}' {yyerror ("there is nothing to be excecuted\n");}
|IF '(' V ')' '{' line error {yyerror (" '}' in expression expected\n");}

/* IF ELSE */
| IF '(' V ')' '{' line '}' ELSE '{' line '}' { 
if($<i>3 == 1){$<i>$ = $<i>6; printf("statement returns %d\n",$<i>$);}
else{ printf("statement returns %d\n",$<i>10);} }

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
while($<i>3 == 1){$<i>$ = $<i>6; printf("statement returns %d\n",$<i>$);};}

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
for( a = 0; a < $<i>3; a = a + 1 ){
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
V: '(' V ')' {$<i>$ = $<i>2;}
| M '=' '=' M {$<i>$ = ($<i>1 == $<i>4);}
| M '>' M {$<i>$ = ($<i>1 > $<i>3);}
| M '<' M {$<i>$ = ($<i>1 < $<i>3);}
| M '>' '=' M {$<i>$ = ($<i>1 >= $<i>4);}
| M '<' '=' M {$<i>$ = ($<i>1 <= $<i>4);}
;

/* Rechenarten */
M: '(' M ')' {$<i>$ = $<i>2; }
| M '+' M {$<i>$ = $<i>1 + $<i>3; }
| M '-' M {$<i>$ = $<i>1 - $<i>3; }
| M '*' M {$<i>$ = $<i>1 * $<i>3; }
| M '/' M {$<i>$ = $<i>1 / $<i>3; }

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

/* Variablenzuweisung */
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
printf("%d name is %s\n", i,symbols[i].name);
printf("%d value is %d\n", i,symbols[i].value.intval);
}
}