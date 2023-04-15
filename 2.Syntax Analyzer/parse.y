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
    int sym[26];
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

arithexp:		arithexp MINUS term { $$=$1-$3; }
				|
				arithexp ADD term { $$=$1+$3; }
				|
				term { $$=$1; }
;

term:			term MULTIPLY factor { $$=$1*$3; }
				|
				term DIVIDE factor { $$=$1/$3; }
				|
				factor { $$=$1; }
;

factor:			LEFTPAREN arithexp RIGHTPAREN { $$=$2; }
				|
				LITERAL { $$=$1; }
				|
				ID		{ $$=sym[$1]; }
				|
				MINUS arithexp { $$=-$2; }
;

relexp:			relexp OR A {$$ = $1 || $3;}
				|
				A {$$ = $1;}
;

A:				A AND B {$$ = $1 && $3;}
				|
				B {$$ = $1;}
;

B:				NOT B {$$ = !$2;}
				|
				C {$$ = $1;}
;

C:				arithexp RELOP arithexp
				|
				arithexp
				|
				LEFTPAREN relexp RIGHTPAREN
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
					ID 
				RIGHTPAREN	{ printf("%d\n",sym[$3]); }
				|
				PRINT LEFTPAREN 
					relexp 
				RIGHTPAREN	{ printf("%d\n",$3); }
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

assignstmt:		ID ASSIGN relexp { sym[$1]=$3; } 
;

callstmt:		ID LEFTPAREN
					args RIGHTPAREN
				|
				ID LEFTPAREN
					emptyarg 
				RIGHTPAREN
;

declarStmt:		LET ID COLON TYPE ASSIGN INPUT LEFTPAREN RIGHTPAREN
				|
				LET ID COLON TYPE ASSIGN relexp { sym[$2]=$6; }
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
	printf("SYMBOL TABLE\n");
	for (int i = 0; i < 26; i++) {
		printf("%c: %d\n",i+97,sym[i]);
	}
	return 0;
}
