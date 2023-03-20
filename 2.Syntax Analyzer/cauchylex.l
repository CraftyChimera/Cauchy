/*DEFINITION SECTION*/
%{
	extern int yylval;
%}


digit		[[:digit:]]
letter		[[:lower:]]
label		[[:upper:]]
id			{letter}({letter}|{digit})*
literal		true|false|{digit}+|\"({letter}|\w)+\"
type		int|bool|string
relop		">"|">="|"<"|"<="|"!="|"==" 
arithop 	"*"|"+"|"/"|"-"|"%"

not			"!"
and			"&&"
or			"||"

fn			"fn"
main		"main"
let			"let"
jump		"jump"
print		"print"
input		"input"
return		"return" 

%%

{fn}		{ return FN; }
{main}		{ return MAIN; }
{let}		{ return LET; }
{jump}		{ return JUMP; }
{print}		{ return PRINT; }
{input}		{ return INPUT; }
{return}	{ return RETURN; }

{label}		{ return LABEL; }
{type}		{ return TYPE; }
{literal}	{ return LITERAL; }
{id}		{ return ID; }
{relop}		{ return RELOP; }
{arithop}	{ return ARITHOP; }

{not}		{ return NOT; }
{and}		{ return AND; }
{or}		{ return OR; }

[\n]		{ yylineno++; }
":"			{ return COLON; }
";"			{ return SEMICOLON; }
"{"			{ return SECTION_OPEN; }
"}"			{ return SECTION_CLOSE; }
"("			{ return LEFTPAREN; }
")"			{ return RIGHTPAREN; }
","			{ return COMMA; }
"="			{ return ASSIGN; }

%%

int yywrap() {				/*Called when scanner reaches EOF*/
	return 1;
}