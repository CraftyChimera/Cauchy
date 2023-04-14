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
%debug
%token RELOP 
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

/*Arithmetic Operations*/
%token MINUS
%token ADD
%token MULTIPLY
%token DIVIDE
%token MOD

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


arithexp:		arithexp MINUS arithexp { $$ = $1 - $3; }
				|
				arithexp ADD arithexp { $$ = $1 + $3;}
				|
				arithexp MULTIPLY arithexp { $$ = $1 * $3; }
				|
				arithexp DIVIDE arithexp { $$ = $1 / $3;}
				|
				LEFTPAREN arithexp RIGHTPAREN {$$ = $2;}
				|
				LITERAL { $$ = $1;}
				|
				ID { $$ = $1; }

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
				FN MAIN LEFTPAREN params RIGHTPAREN TYPE
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

emptyarg:		/* NOTHING */
;  

args:			LITERAL args_
				|
				ID args_
;

args_:			COMMA args
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
				assignstmt
				/* NOTHING */
;

printstmt:		PRINT LEFTPAREN 
					LITERAL
				RIGHTPAREN	{ printf("%d\n",$3); }
				|
				PRINT LEFTPAREN 
					ID { printf("%d\n",$3); }
				RIGHTPAREN	
				|
				PRINT LEFTPAREN 
					arithexp 
				RIGHTPAREN { printf("%d\n",$3); }
;

jumpstmt:		JUMP LEFTPAREN
					LABEL COMMA relexp
				RIGHTPAREN
;

labelstmt:		LABEL COLON	
					SECTION_OPEN
						body
					SECTION_CLOSE
				
;

assignstmt:		ID ASSIGN arithexp
				|
				ID ASSIGN relexp
;

callstmt:		ID LEFTPAREN
					args 
				RIGHTPAREN
				|
				ID LEFTPAREN
					emptyarg 
				RIGHTPAREN
;

declarStmt:		LET ID COLON TYPE ASSIGN INPUT LEFTPAREN RIGHTPAREN
				|
				LET ID COLON TYPE ASSIGN arithexp
				|
				LET ID COLON TYPE ASSIGN relexp
				|
				LET ID COLON TYPE ASSIGN callstmt
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
