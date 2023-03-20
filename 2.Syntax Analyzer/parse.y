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
%token COMMA

/*Logical Operations*/
%token NOT
%token AND
%token OR

/*========== START SYMBOL ==========*/
%start program								/* Specify Starting grammar symbol*/
%type stmt


/*RULE SECTION*/
/*========== GRAMMAR RULES ==========*/
%%
program:		fn program
				|
				/* NOTHING */
;


arithexp:		arithexp ARITHOP arithexp
				|
				LEFTPAREN arithexp RIGHTPAREN
				|
				LITERAL
				|
				ID
;

relexp:			relexp RELOP relexp
				|
				NOT relexp
				|
				relexp AND relexp
				|
				relexp OR relexp
				|
				LEFTPAREN relexp RIGHTPAREN
				| 
				arithexp
;

fn:				FN ID LEFTPAREN params RIGHTPAREN TYPE
					SECTION_OPEN 
						body
						returnstmt
					SECTION_CLOSE
				|
fn:				FN main LEFTPAREN params RIGHTPAREN TYPE
					SECTION_OPEN 
						body
						returnstmt
					SECTION_CLOSE
;

params:			ID COLON TYPE params_
				|
				/* NOTHING */
;

params_:		COMMA params 
				| 
				/* NOTHING */
;  

body:			body_ SEMICOLON body
				|
				/* NOTHING */
;  

body_:			declarStmt
				|
				jumpstmt
				|
				printstmt
				|
				labelstmt
				|
				callstmt
				|
				literalstmt
				|
				/* NOTHING */
;

printstmt:		PRINT LEFTPAREN 
					LITERAL
				RIGHTPAREN	
				|
				PRINT LEFTPAREN 
					ID 
				RIGHTPAREN	
;

jumpstmt:		JUMP LEFTPAREN
					ID COMMA relexp
				RIGHTPAREN
;

labelstmt:		LABEL COLON	LEFTPAREN
				RIGHTPAREN
;

assignstmt:		ID ASSIGN arithexp
				|
				ID ASSIGN relexp
;

callstmt:		ID LEFTPAREN
					params
				RIGHTPAREN
;

declarStmt:		LET ID COLON TYPE ASSIGN INPUT LEFTPAREN RIGHTPAREN
				|
				LET ID COLON TYPE ASSIGN arithexp
				|
				LET ID COLON TYPE ASSIGN relexp
;

literalstmt:	LITERAL literalstmt_	
;

literalstmt_:	COMMA literalstmt 
				| /* NOTHING */
;

returnstmt:		RETURN arithexp SEMICOLON		
				|
				RETURN relexp SEMICOLON		
				|
				RETURN ID SEMICOLON		
;

%%


/*AUXILLARY FUNCTIONS SECTION*/
#include "lex.yy.c"						/*Get tokens from output of FLEX*/

void yyerror(char *error) {				/*Define function body in case of error*/
	printf("yyerror[%d]: %s @ Line No - %d\n", ++errors, error, yylineno);
}

int main() {
	yyin = fopen("input.txt", "r");		/*Specify input file*/
	yyparse();
	return 0;
}
