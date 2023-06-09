/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"

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

#line 120 "parse.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


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
    id = 259,                      /* id  */
    TYPE = 260,                    /* TYPE  */
    ID = 261,                      /* ID  */
    LABEL = 262,                   /* LABEL  */
    FN = 263,                      /* FN  */
    MAIN = 264,                    /* MAIN  */
    LET = 265,                     /* LET  */
    PRINT = 266,                   /* PRINT  */
    INPUT = 267,                   /* INPUT  */
    RETURN = 268,                  /* RETURN  */
    JUMP = 269,                    /* JUMP  */
    COLON = 270,                   /* COLON  */
    SEMICOLON = 271,               /* SEMICOLON  */
    SECTION_OPEN = 272,            /* SECTION_OPEN  */
    SECTION_CLOSE = 273,           /* SECTION_CLOSE  */
    LEFTPAREN = 274,               /* LEFTPAREN  */
    RIGHTPAREN = 275,              /* RIGHTPAREN  */
    ASSIGN = 276,                  /* ASSIGN  */
    COMMA = 277,                   /* COMMA  */
    MINUS = 278,                   /* MINUS  */
    ADD = 279,                     /* ADD  */
    MULTIPLY = 280,                /* MULTIPLY  */
    DIVIDE = 281,                  /* DIVIDE  */
    MOD = 282,                     /* MOD  */
    NOT = 283,                     /* NOT  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    EQ = 286,                      /* EQ  */
    NE = 287,                      /* NE  */
    GT = 288,                      /* GT  */
    GTE = 289,                     /* GTE  */
    LT = 290,                      /* LT  */
    LTE = 291                      /* LTE  */
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



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LITERAL = 3,                    /* LITERAL  */
  YYSYMBOL_id = 4,                         /* id  */
  YYSYMBOL_TYPE = 5,                       /* TYPE  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_LABEL = 7,                      /* LABEL  */
  YYSYMBOL_FN = 8,                         /* FN  */
  YYSYMBOL_MAIN = 9,                       /* MAIN  */
  YYSYMBOL_LET = 10,                       /* LET  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_INPUT = 12,                     /* INPUT  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_JUMP = 14,                      /* JUMP  */
  YYSYMBOL_COLON = 15,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_SECTION_OPEN = 17,              /* SECTION_OPEN  */
  YYSYMBOL_SECTION_CLOSE = 18,             /* SECTION_CLOSE  */
  YYSYMBOL_LEFTPAREN = 19,                 /* LEFTPAREN  */
  YYSYMBOL_RIGHTPAREN = 20,                /* RIGHTPAREN  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_ADD = 24,                       /* ADD  */
  YYSYMBOL_MULTIPLY = 25,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 26,                    /* DIVIDE  */
  YYSYMBOL_MOD = 27,                       /* MOD  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_GTE = 34,                       /* GTE  */
  YYSYMBOL_LT = 35,                        /* LT  */
  YYSYMBOL_LTE = 36,                       /* LTE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_arithexp = 39,                  /* arithexp  */
  YYSYMBOL_term = 40,                      /* term  */
  YYSYMBOL_factor = 41,                    /* factor  */
  YYSYMBOL_relexp = 42,                    /* relexp  */
  YYSYMBOL_A = 43,                         /* A  */
  YYSYMBOL_B = 44,                         /* B  */
  YYSYMBOL_C = 45,                         /* C  */
  YYSYMBOL_D = 46,                         /* D  */
  YYSYMBOL_fn = 47,                        /* fn  */
  YYSYMBOL_params = 48,                    /* params  */
  YYSYMBOL_params_ = 49,                   /* params_  */
  YYSYMBOL_emptyarg = 50,                  /* emptyarg  */
  YYSYMBOL_args = 51,                      /* args  */
  YYSYMBOL_args_ = 52,                     /* args_  */
  YYSYMBOL_body = 53,                      /* body  */
  YYSYMBOL_body_ = 54,                     /* body_  */
  YYSYMBOL_printstmt = 55,                 /* printstmt  */
  YYSYMBOL_jumpstmt = 56,                  /* jumpstmt  */
  YYSYMBOL_labelstmt = 57,                 /* labelstmt  */
  YYSYMBOL_assignstmt = 58,                /* assignstmt  */
  YYSYMBOL_callstmt = 59,                  /* callstmt  */
  YYSYMBOL_declarStmt = 60,                /* declarStmt  */
  YYSYMBOL_literalstmt = 61,               /* literalstmt  */
  YYSYMBOL_literalstmt_ = 62,              /* literalstmt_  */
  YYSYMBOL_returnstmt = 63                 /* returnstmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   107,   111,   129,   134,   137,   142,   147,
     150,   152,   169,   185,   188,   190,   193,   195,   198,   200,
     203,   207,   212,   217,   222,   227,   232,   235,   237,   241,
     247,   254,   255,   259,   260,   264,   267,   269,   272,   273,
     277,   278,   282,   284,   286,   288,   290,   292,   294,   295,
     299,   303,   327,   332,   355,   362,   380,   383,   388,   390,
     392,   395,   398,   399,   403,   425,   427
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LITERAL", "id",
  "TYPE", "ID", "LABEL", "FN", "MAIN", "LET", "PRINT", "INPUT", "RETURN",
  "JUMP", "COLON", "SEMICOLON", "SECTION_OPEN", "SECTION_CLOSE",
  "LEFTPAREN", "RIGHTPAREN", "ASSIGN", "COMMA", "MINUS", "ADD", "MULTIPLY",
  "DIVIDE", "MOD", "NOT", "AND", "OR", "EQ", "NE", "GT", "GTE", "LT",
  "LTE", "$accept", "program", "arithexp", "term", "factor", "relexp", "A",
  "B", "C", "D", "fn", "params", "params_", "emptyarg", "args", "args_",
  "body", "body_", "printstmt", "jumpstmt", "labelstmt", "assignstmt",
  "callstmt", "declarStmt", "literalstmt", "literalstmt_", "returnstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    10,    11,     7,     9,    21,   -59,   -59,    66,    66,
      51,    56,    75,    91,    92,    95,    79,    85,    86,    66,
     -59,    57,    57,   -59,    82,    32,    90,   100,    88,    89,
      96,    94,   -59,   -59,   -59,   -59,   -59,   -59,   -59,    96,
     108,   -59,    14,     3,    97,    98,     4,   105,    31,    99,
      57,   101,   -59,    93,    93,   102,   103,   -59,   -59,     3,
      33,     3,    23,    49,   -59,   104,    87,   -59,    52,   -59,
      57,   113,   106,   107,    13,   109,   112,    54,   -12,   -59,
     -59,   -59,    14,   -59,   -59,   -59,   -59,    15,     3,    23,
     -59,    33,    33,    33,    33,     3,     3,    38,    38,    38,
      38,    38,    38,   111,   114,   -59,   -59,   -59,     3,   -59,
     -59,   -59,   -59,   -59,    28,    49,    49,   -59,   -59,    87,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,     2,    35,
     -59,   117,   118,   104,   -59,   -59,   110,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     3,     0,     0,     1,     2,    32,    32,
       0,     0,     0,     0,     0,     0,    34,     0,     0,    32,
      31,    41,    41,    33,    63,     0,     0,     0,     0,     0,
       0,     0,    44,    43,    45,    48,    46,    42,    47,     0,
       0,    61,    35,     0,     0,     0,     0,     0,     0,     0,
      41,     0,    62,    39,    39,     0,     0,    11,    12,     0,
       0,     0,    27,     6,     9,    55,    15,    17,    19,    26,
      41,     0,    11,    12,     0,     0,    12,    27,     0,    29,
      40,    30,     0,    36,    37,    57,    56,     0,     0,    13,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,     0,    66,
      64,    65,    38,    10,     0,     4,     5,     7,     8,    14,
      16,    24,    25,    20,    21,    22,    23,    54,     0,     0,
      10,    12,     0,    59,    60,    53,     0,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   121,   -36,   -11,     5,   -46,    25,   -58,   -59,    -8,
     -59,    60,   -59,   -59,    39,    71,   -21,   -59,   -59,   -59,
     -59,   -59,    12,   -59,   115,   -59,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    62,    63,    64,    65,    66,    67,    68,    69,
       3,    11,    20,    55,    56,    83,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    41,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    39,    78,    90,   111,    57,    57,    72,   131,    58,
      73,     6,    77,    87,   132,     1,     4,    53,    95,     5,
      54,    59,    59,    59,    89,    60,    60,    60,     8,    80,
      61,    61,    61,   107,    57,   113,    57,    76,   120,    58,
       9,    57,   114,    95,    58,    95,    91,    92,   130,   103,
      59,    42,    88,    43,    60,   135,    60,    59,    95,    61,
      24,    60,   129,    25,    26,    95,    13,    27,    28,    12,
     110,    29,    10,   -49,    93,    94,    14,    91,    92,    23,
     115,   116,   133,    97,    98,    99,   100,   101,   102,   121,
     122,   123,   124,   125,   126,    15,    16,    17,   117,   118,
      18,    19,    21,    22,    40,    44,    45,    46,    47,    48,
      50,    24,    75,    71,    70,    82,    96,    79,   104,    81,
     119,   112,    85,    86,     7,    84,   105,   106,   109,   127,
     137,   108,     0,     0,    95,   128,    42,   136,     0,     0,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
      46,    22,    48,    61,    16,     3,     3,     3,     6,     6,
       6,     0,    48,    59,    12,     8,     6,     3,    30,     9,
       6,    19,    19,    19,    60,    23,    23,    23,    19,    50,
      28,    28,    28,    20,     3,    20,     3,     6,    96,     6,
      19,     3,    88,    30,     6,    30,    23,    24,    20,    70,
      19,    19,    19,    21,    23,    20,    23,    19,    30,    28,
       3,    23,   108,     6,     7,    30,    15,    10,    11,     9,
      16,    14,     6,    16,    25,    26,    20,    23,    24,    19,
      91,    92,   128,    31,    32,    33,    34,    35,    36,    97,
      98,    99,   100,   101,   102,    20,     5,     5,    93,    94,
       5,    22,    17,    17,    22,    15,     6,    19,    19,    13,
      16,     3,     7,    15,    17,    22,    29,    18,     5,    18,
      95,    82,    20,    20,     3,    54,    20,    20,    16,    18,
      20,    22,    -1,    -1,    30,    21,    19,    19,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    38,    47,     6,     9,     0,    38,    19,    19,
       6,    48,    48,    15,    20,    20,     5,     5,     5,    22,
      49,    17,    17,    48,     3,     6,     7,    10,    11,    14,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    53,
      22,    62,    19,    21,    15,     6,    19,    19,    13,    63,
      16,    63,    61,     3,     6,    50,    51,     3,     6,    19,
      23,    28,    39,    40,    41,    42,    43,    44,    45,    46,
      17,    15,     3,     6,    42,     7,     6,    39,    42,    18,
      53,    18,    22,    52,    52,    20,    20,    42,    19,    39,
      44,    23,    24,    25,    26,    30,    29,    31,    32,    33,
      34,    35,    36,    53,     5,    20,    20,    20,    22,    16,
      16,    16,    51,    20,    42,    40,    40,    41,    41,    43,
      44,    46,    46,    46,    46,    46,    46,    18,    21,    42,
      20,     6,    12,    42,    59,    20,    19,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    39,    40,    40,    40,
      41,    41,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    55,    56,    57,    58,    59,    59,    60,    60,
      60,    61,    62,    62,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     2,     3,     1,     3,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     3,    10,
      10,     4,     0,     2,     0,     0,     2,     2,     2,     0,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     4,     4,     6,     5,     3,     4,     4,     8,     6,
       6,     2,     2,     0,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* arithexp: arithexp MINUS term  */
#line 111 "parse.y"
                                            { 
										yyval=yyvsp[-2]-yyvsp[0]; 
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
#line 1344 "parse.tab.c"
    break;

  case 5: /* arithexp: arithexp ADD term  */
#line 129 "parse.y"
                                                        { 
										yyval=yyvsp[-2]+yyvsp[0]; 
										new_gen_3addr_code("ADD");
									}
#line 1353 "parse.tab.c"
    break;

  case 6: /* arithexp: term  */
#line 134 "parse.y"
                                     { yyval=yyvsp[0]; }
#line 1359 "parse.tab.c"
    break;

  case 7: /* term: term MULTIPLY factor  */
#line 137 "parse.y"
                                                { 
							yyval=yyvsp[-2]*yyvsp[0]; 
							new_gen_3addr_code("MUL");
										}
#line 1368 "parse.tab.c"
    break;

  case 8: /* term: term DIVIDE factor  */
#line 142 "parse.y"
                                                        { 
							yyval=yyvsp[-2]/yyvsp[0]; 
							new_gen_3addr_code("DIV");
									}
#line 1377 "parse.tab.c"
    break;

  case 9: /* term: factor  */
#line 147 "parse.y"
                                       { yyval=yyvsp[0]; }
#line 1383 "parse.tab.c"
    break;

  case 10: /* factor: LEFTPAREN relexp RIGHTPAREN  */
#line 150 "parse.y"
                                                    { yyval=yyvsp[-1]; }
#line 1389 "parse.tab.c"
    break;

  case 11: /* factor: LITERAL  */
#line 152 "parse.y"
                                        { yyval=yyvsp[0];
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
						arg1->is_temp = 0;
						arg1->idx = -1;
						arg1->literal = yyvsp[0];

						arg2->is_temp = 1;
						arg2->idx = -1;

						result->is_temp = 1;
						result->idx = temp_idx++;
						new_gen(new_intermediate_code,"LOAD_L",arg1,arg2,result);
				 }
#line 1410 "parse.tab.c"
    break;

  case 12: /* factor: ID  */
#line 169 "parse.y"
                                                { yyval=sym[yyvsp[0]]; 
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
						arg1->is_temp = 0;
						arg1->idx = yyvsp[0];

						arg2->is_temp = 1;
						arg2->idx = -1;

						result->is_temp = 1;
						result->idx = temp_idx++;
			
					new_gen(new_intermediate_code,"LOAD",arg1,arg2,result); }
#line 1430 "parse.tab.c"
    break;

  case 13: /* factor: MINUS arithexp  */
#line 185 "parse.y"
                                               { yyval=-yyvsp[0]; }
#line 1436 "parse.tab.c"
    break;

  case 14: /* relexp: relexp OR A  */
#line 188 "parse.y"
                                    {yyval = yyvsp[-2] || yyvsp[0];}
#line 1442 "parse.tab.c"
    break;

  case 15: /* relexp: A  */
#line 190 "parse.y"
                                  {yyval = yyvsp[0];}
#line 1448 "parse.tab.c"
    break;

  case 16: /* A: A AND B  */
#line 193 "parse.y"
                                        {yyval = yyvsp[-2] && yyvsp[0];}
#line 1454 "parse.tab.c"
    break;

  case 17: /* A: B  */
#line 195 "parse.y"
                                  {yyval = yyvsp[0];}
#line 1460 "parse.tab.c"
    break;

  case 18: /* B: NOT B  */
#line 198 "parse.y"
                                      {yyval = !yyvsp[0];}
#line 1466 "parse.tab.c"
    break;

  case 19: /* B: C  */
#line 200 "parse.y"
                                  {yyval = yyvsp[0];}
#line 1472 "parse.tab.c"
    break;

  case 20: /* C: C GT D  */
#line 203 "parse.y"
                                       { yyval=yyvsp[-2]>yyvsp[0]; 
					new_gen_3addr_code("GT");
					}
#line 1480 "parse.tab.c"
    break;

  case 21: /* C: C GTE D  */
#line 207 "parse.y"
                                        { 
					yyval=yyvsp[-2]>=yyvsp[0]; 
					new_gen_3addr_code("GTE");
				}
#line 1489 "parse.tab.c"
    break;

  case 22: /* C: C LT D  */
#line 212 "parse.y"
                                       { 
					yyval=yyvsp[-2]<yyvsp[0]; 
					new_gen_3addr_code("LT");
				}
#line 1498 "parse.tab.c"
    break;

  case 23: /* C: C LTE D  */
#line 217 "parse.y"
                                        { 
					yyval=yyvsp[-2]<=yyvsp[0]; 
					new_gen_3addr_code("LTE");
				}
#line 1507 "parse.tab.c"
    break;

  case 24: /* C: C EQ D  */
#line 222 "parse.y"
                                       { 
					yyval=yyvsp[-2]==yyvsp[0]; 
					new_gen_3addr_code("EQ");
				}
#line 1516 "parse.tab.c"
    break;

  case 25: /* C: C NE D  */
#line 227 "parse.y"
                                       { 
					yyval=yyvsp[-2]!=yyvsp[0]; 
					new_gen_3addr_code("NE");
				}
#line 1525 "parse.tab.c"
    break;

  case 50: /* printstmt: PRINT LEFTPAREN LITERAL RIGHTPAREN  */
#line 301 "parse.y"
                                                { printf("%d\n",yyvsp[-1]); }
#line 1531 "parse.tab.c"
    break;

  case 51: /* printstmt: PRINT LEFTPAREN ID RIGHTPAREN  */
#line 305 "parse.y"
                                                { 
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						arg1->is_temp = 0;
						arg1->idx = yyvsp[-1];
						arg1->is_label = false;

						arg2->is_temp = 1;
						arg2->idx = -1;
						arg2->is_label = false;

						result->is_temp = 1;
						result->idx = -1;
						result->is_label = false;
						
						new_gen(new_intermediate_code,"PRINT",arg1,arg2,result);
						temp_idx = 0; 
					printf("%d\n",sym[yyvsp[-1]]); 
					
					}
#line 1557 "parse.tab.c"
    break;

  case 52: /* printstmt: PRINT LEFTPAREN relexp RIGHTPAREN  */
#line 329 "parse.y"
                                                { printf("%d\n",yyvsp[-1]); }
#line 1563 "parse.tab.c"
    break;

  case 53: /* jumpstmt: JUMP LEFTPAREN LABEL COMMA relexp RIGHTPAREN  */
#line 334 "parse.y"
                                           { 
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
						result->literal = yyvsp[-3];
						result->is_label = true;
						
						new_gen(new_intermediate_code,"JUMP_IF",arg1,arg2,result);
						temp_idx = 0; 
						}
#line 1587 "parse.tab.c"
    break;

  case 55: /* assignstmt: ID ASSIGN relexp  */
#line 362 "parse.y"
                                         { sym[yyvsp[-2]]=yyvsp[0];
						intmdt_new_addr_t* arg1 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* arg2 = malloc(sizeof(intmdt_new_addr_t));
						intmdt_new_addr_t* result = malloc(sizeof(intmdt_new_addr_t));
						
						arg1->is_temp = 1;
						arg1->idx = temp_idx-1;

						arg2->is_temp = 1;
						arg2->idx = -1;

						result->is_temp = 0;
						result->idx = yyvsp[-2];
						new_gen(new_intermediate_code,"ASSIGN",arg1,arg2,result);
						temp_idx = 0;
				 }
#line 1608 "parse.tab.c"
    break;

  case 59: /* declarStmt: LET ID COLON TYPE ASSIGN relexp  */
#line 390 "parse.y"
                                                                { sym[yyvsp[-4]]=yyvsp[0]; }
#line 1614 "parse.tab.c"
    break;

  case 64: /* returnstmt: RETURN arithexp SEMICOLON  */
#line 404 "parse.y"
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
						result->literal = yyvsp[-1];
						result->is_label = false;
						
						new_gen(new_intermediate_code,"RET",arg1,arg2,result);
						temp_idx = 0; 
					}
#line 1639 "parse.tab.c"
    break;

  case 66: /* returnstmt: RETURN ID SEMICOLON  */
#line 427 "parse.y"
                                                        {
				 }
#line 1646 "parse.tab.c"
    break;


#line 1650 "parse.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 431 "parse.y"



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
