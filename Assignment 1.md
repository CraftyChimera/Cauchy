## Language specification
**Source code**:
```
fn main() int { 	
	a = 10;
	b = 25;
	c = 7;
	d = (a < -b) && (a > c || b < c);
	print(d);
	return 0;
} 
```

## Lexical Analysis<a name="Lexical-Analysis"></a>
**Aim**: To make a lexical analyzer using LEX tool to read source code programs and group them into corresponding tokens for our custom language cauchy. 

**Source Code**: 
```go
fn main() {
  let a:int = 12;
  let b:int = a + 4;
  let c:int = b * a;
  jump(L,(c != 12));
  print("Equal!");
  jump(M, true);
  L: {
    print("Not equal");
  }
  M: {}
  return 0; 
}
```


**Token Specification**:
| S.No | Token      | Lexemes                    |
| --| ---------- | -----------------          |
| 1. | Keyword    | fn, main, let, print, jump, return |
| 2. | Operators  | + - * / % != = == >= <= < > not and or|
| 3. | Data types | int, string, bool          |
| 4. | Symbols | { } ( ) : |
| 5. | Delimiters | whitespace, tabs, newline |
| 6. | Literals | true false 12  |

 
**Explanation:**
By using the LEX tool we were able to create a C program that groups and label each token accordingly. When we pass the input program as `input.txt` we will get all lexemes converted to tokens. 

We specify all the tokens beforehand in the `cauchylex.l` file and then make sure that they can be later fed into the YACC program for parsing. The pattern for all tokens will also be specified in this file.

We then add each lexeme and their corresponding token to a symbol table, we’ll use an int array to for storing and acting as symbol table.


**Program**: `cauchylex.l`

```cpp
/*DEFINITION SECTION*/

%{

extern int yylval;

%}

digit [[:digit:]]

letter [[:lower:]]

label [[:upper:]]

id {letter}

literal true|false|{digit}+|\"({letter}|\w)+\"

type int|bool|string

gt ">"

gte ">="

lt "<"

lte "<="

eq "=="

ne "!="

not "!"

and "&&"

or "||"

fn "fn"

main "main"

let "let"

jump "jump"

print "print"

input "input"

return "return"

%%

{fn} { return FN; }

{main} { return MAIN; }

{let} { return LET; }

{jump} { return JUMP; }

{print} { return PRINT; }

{input} { return INPUT; }

{return} { return RETURN; }

{label} { return LABEL; }

{type} { return TYPE; }

{literal} {

yylval = atoi(yytext);

return LITERAL;

}

{id} {

yylval = (int)(yytext[0]-'a');

return ID;

}

{gt} { return GT; }

{gte} { return GTE; }

{lt} { return LT; }

{lte} { return LTE; }

{eq} { return EQ; }

{ne} { return NE; }

"*" { return MULTIPLY; }

"+" { return ADD; }

"/" { return DIVIDE; }

"-" { return MINUS; }

{not} { return NOT; }

{and} { return AND; }

{or} { return OR; }

[\n] { yylineno++; }

":" { return COLON; }

";" { return SEMICOLON; }

"{" { return SECTION_OPEN; }

"}" { return SECTION_CLOSE; }

"(" { return LEFTPAREN; }

")" { return RIGHTPAREN; }

"," { return COMMA; }

"=" { return ASSIGN; }

%%

int yywrap() { /*Called when scanner reaches EOF*/
return 1;
}
```

**Conclusion** : We have succeeded in making a lexical Analyzer using LEX Tool for cauchy language.