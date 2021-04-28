%{
#include "Parser.tab.h"
#include <stdio.h>
#include <string.h>
#undef yywrap
#define yywrap() 1	
;
 
%}
 
 
%%
[ \t]+; 

else|if|while|for {
return KEYWORD;
} 

[a-zA-Z]+ {
 return STRING;
}
 
[0-9]+ {
return NUMBER;
}

[+*/\-] {
return MATH;
}

. {
 ECHO;
}

\n {
return 0;
}
 
%%