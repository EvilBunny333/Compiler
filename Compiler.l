%{
#include "Parser.tab.h"
#include <stdio.h>
#include <string.h>
#undef yywrap
#define yywrap() 1	
;
 
%}
 
 
%%
#ignore
[ \t]+; 

#dataTypes

int {
return INT;
}

#data
[a-zA-Z]+ {
 return STRING;
}
 
[0-9]+ {
yylval = atoi(yytext);
return NUMBER;
}

#math
\+ {
return '+';
}

\- {
return '-';
}

\* {
return '*';
}

\/ {
return '/';
}

. {
 ECHO;
}

\n {
return 0;
}
 
%%