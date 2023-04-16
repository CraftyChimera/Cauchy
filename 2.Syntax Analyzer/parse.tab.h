/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LITERAL = 258,                 /* LITERAL  */
    TYPE = 259,                    /* TYPE  */
    ID = 260,                      /* ID  */
    LABEL = 261,                   /* LABEL  */
    FN = 262,                      /* FN  */
    MAIN = 263,                    /* MAIN  */
    LET = 264,                     /* LET  */
    PRINT = 265,                   /* PRINT  */
    INPUT = 266,                   /* INPUT  */
    RETURN = 267,                  /* RETURN  */
    JUMP = 268,                    /* JUMP  */
    COLON = 269,                   /* COLON  */
    SEMICOLON = 270,               /* SEMICOLON  */
    SECTION_OPEN = 271,            /* SECTION_OPEN  */
    SECTION_CLOSE = 272,           /* SECTION_CLOSE  */
    LEFTPAREN = 273,               /* LEFTPAREN  */
    RIGHTPAREN = 274,              /* RIGHTPAREN  */
    ASSIGN = 275,                  /* ASSIGN  */
    COMMA = 276,                   /* COMMA  */
    MINUS = 277,                   /* MINUS  */
    ADD = 278,                     /* ADD  */
    MULTIPLY = 279,                /* MULTIPLY  */
    DIVIDE = 280,                  /* DIVIDE  */
    MOD = 281,                     /* MOD  */
    NOT = 282,                     /* NOT  */
    AND = 283,                     /* AND  */
    OR = 284,                      /* OR  */
    EQ = 285,                      /* EQ  */
    NE = 286,                      /* NE  */
    GT = 287,                      /* GT  */
    GTE = 288,                     /* GTE  */
    LT = 289,                      /* LT  */
    LTE = 290                      /* LTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
