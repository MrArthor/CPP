%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "prac2.tab.h"
%}

%%

","														{return COMMA;}
"\n"													{return NLINE;}
[a-zA-Z0-9](\.[a-zA-Z0-9])?(\-[a-zA-Z0-9]*)?			{yylval.strval=yytext; printf("var token: %s ", yytext); return VAR;}
.                       								{printf("Invalid token......\n"); exit(0);}

%%

int yywrap(){
	return 1;
}
