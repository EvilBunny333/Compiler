%{
#include "Parser.tab.h"
#include <stdio.h>
#include <string.h>	
;
 
%}
 
 
%%
#ignore
[ \t]+; 

#Keywords

if {
return IF;
}

else {
return ELSE;
}

for {
return FOR;
}

while {
return WHILE;
}



#dataTypes
int {
return INT;
}

float {
return FLOAT;
}

bool {
return BOOL;
}

#operation
print {
return PRINT;
}

#data
[a-zA-Z]+ {
 yylval.str = strdup(yytext);
 return STRING;
}
 
[0-9]+ {
yylval.i = atoi(yytext);
return INTNUMBER;
}

[0-9]*\.[0-9]+ {
yylval.fl = atof(yytext);
return FLOATNUMBER;
}

[a-zA-Z]+\[[0-9]+\] {
 return ARRAY;
}



#math

[-+()=/*><{},] {
return *yytext;
}

\n {
return '\n';
}

. {
 ECHO;
}
 
%%

int yywrap(void) {     return 1; } 