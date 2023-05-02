## Semantic Analysis

**Aim**: To add the semantic actions for the existing syntax analyzer, symbol table for variable assignment and generate intermediate code

**Explanation**: 
We modify our existing parser that we made previously, by adding semantic actions for the  grammar rules handling arithmetic and relational expressions.

Programming logic for the generation of intermediate three address code is also added into our program.

**Source code**: `parse.y`
```c
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
										//Gen3AddrCode($1,$3,$$,"-");
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
										//Gen3AddrCode($1,$3,$$,"+");
							intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
							arg1->is_temp = 1;
							arg1->idx = temp_idx-2;
							
							arg2->is_temp = 1;
							arg2->idx = temp_idx-1;

							result->is_temp = 1;
							result->idx = temp_idx++;
			
					new_gen(new_intermediate_code,"ADD",arg1,arg2,result); 
									}
				|
				term { $$=$1; }
;

term:			term MULTIPLY factor	{ 
											$$=$1*$3; 
											Gen3AddrCode($1,$3,$$,"*");
																		intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));

							arg1->is_temp = 1;
							arg1->idx = temp_idx-2;
							
							arg2->is_temp = 1;
							arg2->idx = temp_idx-1;

							result->is_temp = 1;
							result->idx = temp_idx++;
			
					new_gen(new_intermediate_code,"MUL",arg1,arg2,result); 
										}
				|
				term DIVIDE factor	{ 
										$$=$1*$3; 
										Gen3AddrCode($1,$3,$$,"/");
																	intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
							intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));

							arg1->is_temp = 1;
							arg1->idx = temp_idx-2;
							
							arg2->is_temp = 1;
							arg2->idx = temp_idx-1;

							result->is_temp = 1;
							result->idx = temp_idx++;
			
					new_gen(new_intermediate_code,"DIV",arg1,arg2,result); 
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
					Gen3AddrCode($1,$3,$$,">");

					}
				|
				C GTE D { 
					$$=$1>=$3; 
					Gen3AddrCode($1,$3,$$,">=");
				}
				|
				C LT D { 
					$$=$1<$3; 
					Gen3AddrCode($1,$3,$$,"<");
				}
				|
				C LTE D { 
					$$=$1<=$3; 
					Gen3AddrCode($1,$3,$$,"<=");
				}
				|
				C EQ D { 
					$$=$1==$3; 
					Gen3AddrCode($1,$3,$$,"==");
				}
				|
				C NE D { 
					$$=$1!=$3; 
					Gen3AddrCode($1,$3,$$,"!=");
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
				RIGHTPAREN	{ printf("%d\n",sym[$3]); }
				|
				PRINT LEFTPAREN 
					relexp 
				RIGHTPAREN	{ printf("%d\n",$3); }
;

jumpstmt:		JUMP LEFTPAREN
					LABEL COMMA relexp
				RIGHTPAREN { Gen3AddrCode($3,0,(int)$5,"JUMP"); }
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
	intermediate_code = malloc(sizeof(intmdt_code_t));
	new_intermediate_code = malloc(sizeof(intmdt_new_code_t));
	intermediate_code->n = 0;
	new_intermediate_code->n = 0;

	yyparse();
	
	printf("SYMBOL TABLE\n");
	for (int i = 0; i < 26; i++) {
		printf("%c: %d\t",i+97,sym[i]);
	 }
	printf("\n");
	new_print(new_intermediate_code);
	return 0;
}

```

**Input**:
```go
fn main() int { 	
	a = 4;
	b = 25+a;
	c = 7-8;
	d = (7 * 8) && (a > c || b < c);
	print(d);
	return 0;
} 
```

**Output**:
```json
1
```

**Symbol Table**:
```json
a: 4    b: 29   c: -1   d: 1    e: 1    f: 0    g: 0    h: 0    i: 0    j: 0    k: 0    l: 0    m: 0    n: 0    o: 0    p: 0    q: 0    r: 0
s: 0    t: 0    u: 0    v: 0    w: 0    x: 0    y: 0    z: 0
```

**Three Address Code**:
```json
LOAD_L	4	--	$0
ASSIGN	$0	--	a
LOAD_L	25	--	$0
LOAD	a	--	$1
ADD		$0	$1	$2
ASSIGN	$2	--	b
LOAD_L	7	--	$0
LOAD_L	8	--	$1
SUB		$0	$1	$2
ASSIGN	$2	--	c
LOAD_L	7	--	$0
LOAD_L	8	--	$1
MUL		$0	$1	$2
LOAD	a	--	$3
LOAD	c	--	$4
LOAD	b	--	$5
LOAD	c	--	$6
ASSIGN	$6	--	d
LOAD_L	0	--	$0
```


**Conclusion**: We were able to successfully add the semantic actions, symbol table as well as generate intermediate code for our language.