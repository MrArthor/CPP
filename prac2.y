%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	int yylex();
	void yyerror(char*);
	
%}

%union{
	int intval;
	char charval;
	char* strval;
}

%token <intval> COMMA NLINE
%token <strval> VAR
 
%start startnode

%%

startnode:  line		{printf("\n\nEXPRESSION MATCHED-------------\n\n\n");};
line: VAR COMMA VAR COMMA VAR COMMA VAR COMMA VAR	{printf("\n%s\n%s\n%s\n%s\n%s", $1,$3,$5,$7,$9);}; 


	
%%

void main(){
	extern FILE *yyin, *yyout;
	yyin = fopen("1.csv", "r");
	
	do{
		yyparse();
	}while(yyin);
}

void yyerror(char* s){
	fprintf(stderr, "%s\n", s);
	exit(0);
}
