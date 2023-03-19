%{
	/* Define header file, macros*/
    #include <stdio.h>
    #include <stdlib.h>
									
	extern FILE *yyin;					/* Loading external file as input */
	extern int yyparse();
	extern int yylex();
	extern void yyerror(char *);
	extern int yylineno;
	extern int yywrap();
	int errors = 0;
%}


/*DEFINITION SECTION*/

/*========== TOKENS ==========*/
%token LOGOP 
%token RELOP 
%token ARITHOP 
%token LITERAL 
%token TYPE 
%token ID 
%token LABEL 

/*Keywords*/
%token FN 
%token MAIN 
%token LET 
%token PRINT 
%token INPUT 
%token RETURN 
%token JUMP 

/*Symbols*/
%token COLON 
%token SEMICOLON 
%token SECTION_OPEN 
%token SECTION_CLOSE
%token LEFTPAREN
%token RIGHTPAREN
%token ASSIGN 


/*========== START SYMBOL ==========*/
%start program								/* Specify Starting grammar symbol*/
%type stmt


/*RULE SECTION*/
/*========== GRAMMAR RULES ==========*/
%%
program:	stmt	{ printf("Sequence Accepted\n"); }
;

stmt:		ID ASSIGN LITERAL RELOP LITERAL SEMICOLON
;  

%%


/*AUXILLARY FUNCTIONS SECTION*/
#include "lex.yy.c"						/*Get tokens from output of FLEX*/

void yyerror(char *error) {				/*Define function body in case of error*/
	yylineno++;
	printf("yyerror[%d]: %s @ Line No - %d\n", ++errors, error, yylineno);
}

int main() {
	yyin = fopen("input.txt", "r");		/*Specify input file*/
	yyparse();
	return 0;
}
