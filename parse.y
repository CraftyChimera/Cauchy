%{
	/* Define header file, macros*/
    #include <stdio.h>
    #include <stdlib.h>
	#include "intmdt_code.h"
									
	extern FILE *yyin;					/* Loading external file as input */
	extern int yyparse();
	extern int yylex();
	extern void yyerror(char *);
	extern int yylineno;
	extern int yywrap();
	int errors = 0;
    int sym[26];
	intmdt_code_t* intermediate_code;
	intmdt_new_code_t* new_intermediate_code;
	int temp_idx = 0;

void Gen3AddrCode(int op1, int op2, int res, char opcode[]) { /* Wrapper to generate 3 address code */
	intmdt_addr_t* arg1 = malloc(sizeof(intmdt_addr_t));
	intmdt_addr_t* arg2 = malloc(sizeof(intmdt_addr_t));
	intmdt_addr_t* result = malloc(sizeof(intmdt_addr_t));
	arg1->addr.int_const_ptr = op1;
	arg1->type = int_const;
	arg2->addr.int_const_ptr = op2;
	arg2->type = int_const;
	result->addr.int_const_ptr = res;
	result->type = int_const;
	gen(intermediate_code,opcode,arg1,arg2,result);
	}

void new_gen_3addr_code(char *op) {
							intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
							arg1->is_temp = 1;
							arg1->idx = temp_idx-2;
							
							arg2->is_temp = 1;
							arg2->idx = temp_idx-1;

							result->is_temp = 1;
							result->idx = temp_idx++;
			
					new_gen(new_intermediate_code,op,arg1,arg2,result); 
}
%}


/*DEFINITION SECTION*/

/*========== TOKENS ==========*/
%debug
%token LITERAL id
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

/*Relational Operations*/
%token EQ
%token NE
%token GT
%token GTE
%token LT
%token LTE

/*========== START SYMBOL ==========*/
%start program								/* Specify Starting grammar symbol*/


/*RULE SECTION*/
/*========== GRAMMAR RULES ==========*/
%%
program:		fn program 
				|
				/* NOTHING */
;

arithexp:		arithexp MINUS term { 
										$$=$1-$3; 
							intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));

							arg1->is_temp = 1;
							arg1->idx = temp_idx-2;
							
							arg2->is_temp = 1;
							arg2->idx = temp_idx-1;

							result->is_temp = 1;
							result->idx = temp_idx++;
			
					new_gen(new_intermediate_code,"SUB",arg1,arg2,result); 
									}
				|
				arithexp ADD term	{ 
										$$=$1+$3; 
										new_gen_3addr_code("ADD");
									}
				|
				term { $$=$1; }
;

term:			term MULTIPLY factor	{ 
							$$=$1*$3; 
							new_gen_3addr_code("MUL");
										}
				|
				term DIVIDE factor	{ 
							$$=$1/$3; 
							new_gen_3addr_code("DIV");
									}
				|
				factor { $$=$1; }
;

factor:			LEFTPAREN relexp RIGHTPAREN { $$=$2; }
				|
				LITERAL { $$=$1;
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
						arg1->is_temp = 0;
						arg1->idx = -1;
						arg1->literal = $1;

						arg2->is_temp = 1;
						arg2->idx = -1;

						result->is_temp = 1;
						result->idx = temp_idx++;
						new_gen(new_intermediate_code,"LOAD_L",arg1,arg2,result);
				 }
				|
				ID		{ $$=sym[$1]; 
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
						arg1->is_temp = 0;
						arg1->idx = $1;

						arg2->is_temp = 1;
						arg2->idx = -1;

						result->is_temp = 1;
						result->idx = temp_idx++;
			
					new_gen(new_intermediate_code,"LOAD",arg1,arg2,result); }
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

C:				C GT D { $$=$1>$3; 
					new_gen_3addr_code("GT");
					}
				|
				C GTE D { 
					$$=$1>=$3; 
					new_gen_3addr_code("GTE");
				}
				|
				C LT D { 
					$$=$1<$3; 
					new_gen_3addr_code("LT");
				}
				|
				C LTE D { 
					$$=$1<=$3; 
					new_gen_3addr_code("LTE");
				}
				|
				C EQ D { 
					$$=$1==$3; 
					new_gen_3addr_code("EQ");
				}
				|
				C NE D { 
					$$=$1!=$3; 
					new_gen_3addr_code("NE");
				}
				|
				D
;

D:				arithexp
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
				|
				/* NOTHING */
;

printstmt:		PRINT LEFTPAREN 
					LITERAL
				RIGHTPAREN	{ printf("%d\n",$3); }
				|
				PRINT LEFTPAREN 
					ID 
				RIGHTPAREN	{ 
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						arg1->is_temp = 0;
						arg1->idx = $3;
						arg1->is_label = false;

						arg2->is_temp = 1;
						arg2->idx = -1;
						arg2->is_label = false;

						result->is_temp = 1;
						result->idx = -1;
						result->is_label = false;
						
						new_gen(new_intermediate_code,"PRINT",arg1,arg2,result);
						temp_idx = 0; 
					printf("%d\n",sym[$3]); 
					
					}
				|
				PRINT LEFTPAREN 
					relexp 
				RIGHTPAREN	{ printf("%d\n",$3); }
;

jumpstmt:		JUMP LEFTPAREN
					LABEL COMMA relexp
				RIGHTPAREN { 
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						arg1->is_temp = 1;
						arg1->idx = temp_idx-1;
						arg1->is_label = false;

						arg2->is_temp = 1;
						arg2->idx = -1;
						arg2->is_label = false;

						result->is_temp = 0;
						result->literal = $3;
						result->is_label = true;
						
						new_gen(new_intermediate_code,"JUMP_IF",arg1,arg2,result);
						temp_idx = 0; 
						}
;

labelstmt:		LABEL COLON	
					SECTION_OPEN
						body
					SECTION_CLOSE
				
;

assignstmt:		ID ASSIGN relexp { sym[$1]=$3;
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
						arg1->is_temp = 1;
						arg1->idx = temp_idx-1;

						arg2->is_temp = 1;
						arg2->idx = -1;

						result->is_temp = 0;
						result->idx = $1;
						new_gen(new_intermediate_code,"ASSIGN",arg1,arg2,result);
						temp_idx = 0;
				 } 
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
				| 
				/* NOTHING */
;

returnstmt:		RETURN arithexp SEMICOLON	
					{
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						arg1->is_temp = 1;
						arg1->idx = -1;
						arg1->is_label = false;

						arg2->is_temp = 1;
						arg2->idx = -1;
						arg2->is_label = false;

						result->is_temp = 0;
						result->idx = -1;
						result->literal = $2;
						result->is_label = false;
						
						new_gen(new_intermediate_code,"RET",arg1,arg2,result);
						temp_idx = 0; 
					}	
				|
				RETURN relexp SEMICOLON		
				|
				RETURN ID SEMICOLON	{
				 }	
;

%%


/*AUXILLARY FUNCTIONS SECTION*/
#include "lex.yy.c"						/*Get tokens from output of FLEX*/

void yyerror(char *error) {				/*Define function body in case of error*/
	printf("yyerror[%d]: %s @ Line No - %d\n", ++errors, error, yylineno);
}

int main() {
	yyin = fopen("input.txt", "r");		/*Specify input file*/
	intermediate_code = malloc(sizeof(intmdt_code_t));
	new_intermediate_code = malloc(sizeof(intmdt_new_code_t));
	intermediate_code->n = 0;
	new_intermediate_code->n = 0;

	yyparse();
	printf("\n");
	int* leader_indices = new_print(new_intermediate_code);
	int i=0;
	printf("\n\n");
	printf("Block Leaders:\n");

	while(leader_indices[i] != -1)
	{
		int index = leader_indices[i];
		printf("%d\t",index);
	  printf(new_intermediate_code->code[index]->op);
	  intmdt_new_addr_print(new_intermediate_code->code[index]->arg1);
      intmdt_new_addr_print(new_intermediate_code->code[index]->arg2);
      intmdt_new_addr_print(new_intermediate_code->code[index]->result);
    printf("\n");
		i++;
	}
	return 0;
}
