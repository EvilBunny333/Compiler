/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Parser.y"

	#include<stdio.h>
	#include<string.h>

	union Value {
	int intval;
	float floatval;
	};

	typedef struct Variable{
	char *name;
	int type; //0 = int, 1 = float;
	union Value value;
	} Variable;

	Variable symbols[50];
	int attr = -1;

/* Line 371 of yacc.c  */
#line 87 "Parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTNUMBER = 258,
     FLOATNUMBER = 259,
     STRING = 260,
     IF = 261,
     ELSE = 262,
     FOR = 263,
     WHILE = 264,
     PRINT = 265,
     ARRAY = 266,
     INT = 267,
     FLOAT = 268,
     BOOL = 269,
     IFX = 270
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 20 "Parser.y"
int i;char *str;

/* Line 387 of yacc.c  */
#line 148 "Parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 176 "Parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    17,    15,     2,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,    19,    21,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      21,    29,    37,    45,    53,    61,    69,    77,    89,   101,
     113,   125,   137,   149,   161,   173,   185,   197,   205,   213,
     221,   229,   237,   245,   253,   261,   269,   277,   285,   293,
     301,   309,   313,   318,   322,   326,   331,   336,   340,   344,
     348,   352,   356,   362,   368,   374,   380,   386,   392,   398,
     404,   410,   416,   422,   428,   434,   440,   446,   452,   454,
     456,   458,   463,   468
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    29,    30,    -1,    30,    -1,    33,    -1,
      32,    -1,    31,    -1,    34,    -1,    35,    -1,    30,    23,
      -1,     6,    24,    32,    25,    26,    30,    27,    -1,     6,
       1,    32,    25,    26,    30,    27,    -1,     6,    24,     1,
      25,    26,    30,    27,    -1,     6,    24,    32,     1,    26,
      30,    27,    -1,     6,    24,    32,    25,     1,    30,    27,
      -1,     6,    24,    32,    25,    26,     1,    27,    -1,     6,
      24,    32,    25,    26,    30,     1,    -1,     6,    24,    32,
      25,    26,    30,    27,     7,    26,    30,    27,    -1,     6,
       1,    32,    25,    26,    30,    27,     7,    26,    30,    27,
      -1,     6,    24,     1,    25,    26,    30,    27,     7,    26,
      30,    27,    -1,     6,    24,    32,     1,    26,    30,    27,
       7,    26,    30,    27,    -1,     6,    24,    32,    25,     1,
      30,    27,     7,    26,    30,    27,    -1,     6,    24,    32,
      25,    26,     1,    27,     7,    26,    30,    27,    -1,     6,
      24,    32,    25,    26,    30,     1,     7,    26,    30,    27,
      -1,     6,    24,    32,    25,    26,    30,    27,     7,     1,
      30,    27,    -1,     6,    24,    32,    25,    26,    30,    27,
       7,    26,     1,    27,    -1,     6,    24,    32,    25,    26,
      30,    27,     7,    26,    30,     1,    -1,     9,    24,    32,
      25,    26,    30,    27,    -1,     9,     1,    32,    25,    26,
      30,    27,    -1,     9,    24,     1,    25,    26,    30,    27,
      -1,     9,    24,    32,     1,    26,    30,    27,    -1,     9,
      24,    32,    25,     1,    30,    27,    -1,     9,    24,    32,
      25,    26,     1,    27,    -1,     9,    24,    32,    25,    26,
      30,     1,    -1,     8,    24,     3,    25,    26,    30,    27,
      -1,     8,     1,     3,    25,    26,    30,    27,    -1,     8,
      24,     1,    25,    26,    30,    27,    -1,     8,    24,     3,
       1,    26,    30,    27,    -1,     8,    24,     3,    25,     1,
      30,    27,    -1,     8,    24,     3,    25,    26,     1,    27,
      -1,     8,    24,     3,    25,    26,    30,     1,    -1,    24,
      32,    25,    -1,    33,    19,    19,    33,    -1,    33,    21,
      33,    -1,    33,    20,    33,    -1,    33,    21,    19,    33,
      -1,    33,    20,    19,    33,    -1,    24,    33,    25,    -1,
      33,    15,    33,    -1,    33,    16,    33,    -1,    33,    17,
      33,    -1,    33,    18,    33,    -1,     1,    33,    15,    33,
      25,    -1,    24,     1,    15,    33,    25,    -1,    24,    33,
      15,     1,    25,    -1,    24,    33,    15,    33,     1,    -1,
       1,    33,    16,    33,    25,    -1,    24,     1,    16,    33,
      25,    -1,    24,    33,    16,     1,    25,    -1,    24,    33,
      16,    33,     1,    -1,     1,    33,    17,    33,    25,    -1,
      24,     1,    17,    33,    25,    -1,    24,    33,    17,     1,
      25,    -1,    24,    33,    17,    33,     1,    -1,     1,    33,
      18,    33,    25,    -1,    24,     1,    18,    33,    25,    -1,
      24,    33,    18,     1,    25,    -1,    24,    33,    18,    33,
       1,    -1,     3,    -1,     4,    -1,     5,    -1,    12,     5,
      19,    33,    -1,    13,     5,    19,    33,    -1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    42,    45,    46,    51,    52,    53,    54,
      58,    62,    63,    64,    65,    66,    67,    69,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    83,    86,    87,
      88,    89,    90,    91,    93,    99,   100,   101,   102,   103,
     104,   108,   109,   110,   111,   112,   113,   117,   118,   119,
     120,   121,   124,   125,   126,   127,   130,   131,   132,   133,
     136,   137,   138,   139,   142,   143,   144,   145,   147,   148,
     149,   162,   168,   176
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTNUMBER", "FLOATNUMBER", "STRING",
  "IF", "ELSE", "FOR", "WHILE", "PRINT", "ARRAY", "INT", "FLOAT", "BOOL",
  "'+'", "'-'", "'*'", "'/'", "'='", "'<'", "'>'", "IFX", "'\\n'", "'('",
  "')'", "'{'", "'}'", "$accept", "input", "line", "Stmt", "V", "M", "Var",
  "print", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    43,    45,    42,    47,    61,
      60,    62,   270,    10,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    29,    30,    30,    30,    30,    30,    30,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    32,    32,    32,    32,    32,    32,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    34,    34,    35
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       7,     7,     7,     7,     7,     7,     7,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     3,     4,     3,     3,     4,     4,     3,     3,     3,
       3,     3,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     1,     1,
       1,     4,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    68,    69,    70,     0,     0,     0,    73,     0,
       0,     0,     0,     3,     6,     5,     4,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,    47,    48,
      49,    50,    51,     0,     0,    44,     0,    43,    48,    49,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    46,
      45,    52,    56,    60,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    57,    61,    65,    54,    55,    58,    59,    62,    63,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    10,    35,    36,    37,
      38,    39,    40,    34,    28,    29,    30,    31,    32,    33,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -19
static const yytype_int16 yypact[] =
{
     273,   286,   -19,   -19,   -19,    22,   126,   153,   -19,    -3,
       9,   373,   163,    60,   -19,   -19,   469,   -19,   -19,   378,
     481,   387,   395,    82,    14,   387,   400,    77,    79,   347,
      98,   432,   -19,    60,   -19,   286,   286,   286,   286,   116,
     356,   365,    64,   286,   286,   286,   286,   119,   469,   128,
      67,   123,   131,   124,   135,   228,   133,   286,   286,   286,
     286,   286,   286,   -19,   405,   411,   417,   422,   -19,    33,
      33,   -19,   -19,   286,   286,   485,   286,   485,    -6,    69,
     137,   145,   152,   170,   179,     0,   181,   182,   190,    12,
     191,   192,   201,    15,   485,   485,   415,   443,   447,   458,
     233,   121,   238,   173,   243,   194,   268,   205,   485,   485,
     485,   -19,   -19,   -19,   -19,   273,   273,   273,   273,   295,
     273,   273,   273,   273,   308,   273,   273,   273,   273,   321,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -18,    26,    68,   132,     3,    61,   138,   174,
     176,   177,    28,   101,   222,   237,   257,   279,    66,   103,
     221,   249,   252,   254,   258,   259,   263,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   209,   262,   269,   289,   297,   302,    21,   273,   273,
     273,   273,   273,   273,   273,   334,   326,   390,   416,   444,
     454,   455,   468,    73,   120,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -19,   -19,    -9,   -19,   229,    -1,   -19,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      20,   118,    27,    33,     1,    34,     2,     3,     4,   160,
      31,    37,    38,   123,    28,    52,   128,    53,    42,   111,
      48,    48,   194,    21,    48,    48,   119,    19,    20,     1,
     164,     2,     3,     4,    69,    70,    71,    72,   124,    75,
      77,   129,    78,    79,    80,    81,    22,   195,    20,    34,
      37,    38,    19,   161,    20,   171,    94,    95,    96,    97,
      98,    99,   165,   101,   103,   105,   107,     1,    84,     2,
       3,     4,   108,   109,     1,   110,     2,     3,     4,    64,
      65,    66,    67,    34,    34,    51,    37,    38,   166,    68,
      19,    34,    85,   178,   112,   162,    57,    19,    58,    20,
     212,    20,   172,    20,   179,    20,   142,   143,   144,   145,
     147,   148,   149,   150,   151,   153,   154,   155,   156,   157,
     159,   213,   135,    63,    34,    88,    34,    23,   173,     1,
     180,     2,     3,     4,    92,    73,   -48,   -48,    37,    38,
     -48,   -48,   -48,    34,    82,    20,   -48,   214,    86,    89,
      24,    20,    19,    83,    25,    34,    87,    20,    93,   163,
      90,    34,   113,    32,     1,   167,     2,     3,     4,     5,
     114,     6,     7,     8,   137,     9,    10,    26,   115,   196,
     197,   198,   199,   200,   201,   202,   204,    11,   -49,   -49,
      37,    38,   -49,   -49,   -49,   139,   116,    34,   -49,    34,
      34,   168,    20,   169,   170,   117,   141,   120,   121,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   122,   125,   126,   -50,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   127,   181,     1,
     -51,     2,     3,     4,     1,   188,     2,     3,     4,     1,
      30,     2,     3,     4,     1,    34,     2,     3,     4,   174,
      47,    50,    19,    91,    54,    56,   182,    19,   134,   183,
      34,   184,    19,   136,   175,   185,   186,    19,   138,     1,
     187,     2,     3,     4,     1,     0,     2,     3,     4,     5,
      34,     6,     7,     8,   176,     9,    10,     1,   189,     2,
       3,     4,    19,   140,     0,   190,   146,    11,     2,     3,
       4,     5,    34,     6,     7,     8,   177,     9,    10,   152,
      19,     2,     3,     4,     5,   191,     6,     7,     8,    11,
       9,    10,   158,   192,     2,     3,     4,     5,   193,     6,
       7,     8,    11,     9,    10,   203,     0,     2,     3,     4,
       5,     0,     6,     7,     8,    11,     9,    10,     1,    34,
       2,     3,     4,   205,     0,     0,     0,     1,    11,     2,
       3,     4,    59,    60,    61,    62,     1,     0,     2,     3,
       4,    19,     0,     0,    29,    74,     2,     3,     4,    29,
      19,     2,     3,     4,    76,     0,     0,     0,     1,    19,
       2,     3,     4,     0,     0,     0,    49,    11,     2,     3,
       4,    55,    19,     2,     3,     4,   100,     0,     2,     3,
       4,    11,   102,    34,     2,     3,     4,   206,   104,    11,
       2,     3,     4,   106,    11,     2,     3,     4,     0,    19,
      35,    36,    37,    38,     0,    19,     0,     0,     0,    34,
     130,    19,     0,   207,     0,     0,    19,    64,    65,    66,
      67,    39,    40,    41,     0,     0,     0,    68,    35,    36,
      37,    38,    35,    36,    37,    38,     0,    34,   131,     0,
       0,   208,   132,    35,    36,    37,    38,    34,    34,     0,
       0,   209,   210,   133,    35,    36,    37,    38,    39,    40,
      41,    34,     0,     0,     0,   211,    43,    44,    45,    46,
      35,    36,    37,    38
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-19)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     1,     5,    12,     1,    23,     3,     4,     5,    27,
      11,    17,    18,     1,     5,     1,     1,     3,    19,    25,
      21,    22,     1,     1,    25,    26,    26,    24,    29,     1,
      27,     3,     4,     5,    35,    36,    37,    38,    26,    40,
      41,    26,    43,    44,    45,    46,    24,    26,    49,    23,
      17,    18,    24,    27,    55,    27,    57,    58,    59,    60,
      61,    62,     1,    64,    65,    66,    67,     1,     1,     3,
       4,     5,    73,    74,     1,    76,     3,     4,     5,    15,
      16,    17,    18,    23,    23,     3,    17,    18,    27,    25,
      24,    23,    25,    27,    25,    27,    19,    24,    19,   100,
      27,   102,     1,   104,     1,   106,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     1,     1,    25,    23,     1,    23,     1,    27,     1,
      27,     3,     4,     5,     1,    19,    15,    16,    17,    18,
      19,    20,    21,    23,    25,   146,    25,    27,    25,    25,
      24,   152,    24,    25,     1,    23,    25,   158,    25,    27,
      25,    23,    25,     0,     1,    27,     3,     4,     5,     6,
      25,     8,     9,    10,     1,    12,    13,    24,    26,   188,
     189,   190,   191,   192,   193,   194,   195,    24,    15,    16,
      17,    18,    19,    20,    21,     1,    26,    23,    25,    23,
      23,    27,   203,    27,    27,    26,     1,    26,    26,    15,
      16,    17,    18,    19,    20,    21,    26,    26,    26,    25,
      15,    16,    17,    18,    19,    20,    21,    26,     7,     1,
      25,     3,     4,     5,     1,    26,     3,     4,     5,     1,
      11,     3,     4,     5,     1,    23,     3,     4,     5,    27,
      21,    22,    24,    25,    25,    26,     7,    24,    25,     7,
      23,     7,    24,    25,    27,     7,     7,    24,    25,     1,
       7,     3,     4,     5,     1,    -1,     3,     4,     5,     6,
      23,     8,     9,    10,    27,    12,    13,     1,    26,     3,
       4,     5,    24,    25,    -1,    26,     1,    24,     3,     4,
       5,     6,    23,     8,     9,    10,    27,    12,    13,     1,
      24,     3,     4,     5,     6,    26,     8,     9,    10,    24,
      12,    13,     1,    26,     3,     4,     5,     6,    26,     8,
       9,    10,    24,    12,    13,     1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    10,    24,    12,    13,     1,    23,
       3,     4,     5,    27,    -1,    -1,    -1,     1,    24,     3,
       4,     5,    15,    16,    17,    18,     1,    -1,     3,     4,
       5,    24,    -1,    -1,     1,    19,     3,     4,     5,     1,
      24,     3,     4,     5,    19,    -1,    -1,    -1,     1,    24,
       3,     4,     5,    -1,    -1,    -1,     1,    24,     3,     4,
       5,     1,    24,     3,     4,     5,     1,    -1,     3,     4,
       5,    24,     1,    23,     3,     4,     5,    27,     1,    24,
       3,     4,     5,     1,    24,     3,     4,     5,    -1,    24,
      15,    16,    17,    18,    -1,    24,    -1,    -1,    -1,    23,
      25,    24,    -1,    27,    -1,    -1,    24,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    15,    16,
      17,    18,    15,    16,    17,    18,    -1,    23,    25,    -1,
      -1,    27,    25,    15,    16,    17,    18,    23,    23,    -1,
      -1,    27,    27,    25,    15,    16,    17,    18,    19,    20,
      21,    23,    -1,    -1,    -1,    27,    15,    16,    17,    18,
      15,    16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    10,    12,
      13,    24,    29,    30,    31,    32,    33,    34,    35,    24,
      33,     1,    24,     1,    24,     1,    24,     5,     5,     1,
      32,    33,     0,    30,    23,    15,    16,    17,    18,    19,
      20,    21,    33,    15,    16,    17,    18,    32,    33,     1,
      32,     3,     1,     3,    32,     1,    32,    19,    19,    15,
      16,    17,    18,    25,    15,    16,    17,    18,    25,    33,
      33,    33,    33,    19,    19,    33,    19,    33,    33,    33,
      33,    33,    25,    25,     1,    25,    25,    25,     1,    25,
      25,    25,     1,    25,    33,    33,    33,    33,    33,    33,
       1,    33,     1,    33,     1,    33,     1,    33,    33,    33,
      33,    25,    25,    25,    25,    26,    26,    26,     1,    26,
      26,    26,    26,     1,    26,    26,    26,    26,     1,    26,
      25,    25,    25,    25,    25,     1,    25,     1,    25,     1,
      25,     1,    30,    30,    30,    30,     1,    30,    30,    30,
      30,    30,     1,    30,    30,    30,    30,    30,     1,    30,
      27,    27,    27,    27,    27,     1,    27,    27,    27,    27,
      27,    27,     1,    27,    27,    27,    27,    27,    27,     1,
      27,     7,     7,     7,     7,     7,     7,     7,    26,    26,
      26,    26,    26,    26,     1,    26,    30,    30,    30,    30,
      30,    30,    30,     1,    30,    27,    27,    27,    27,    27,
      27,    27,    27,     1,    27
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
/* Line 1792 of yacc.c  */
#line 45 "Parser.y"
    {printf("result %d\n",(yyval.i));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 47 "Parser.y"
    {
if((yyvsp[(1) - (1)].i) == 1){printf("statement returns true\n");}
else{printf("statement returns false\n");}
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 51 "Parser.y"
    {}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 52 "Parser.y"
    {printf("var is %d\n",(yyval.i));}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 58 "Parser.y"
    { 
/* IF */
if((yyvsp[(3) - (7)].i) == 1){(yyval.i) = (yyvsp[(6) - (7)].i); printf("statement returns %d\n",(yyval.i));}else{printf("statement is false"); } ;}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 62 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 63 "Parser.y"
    {yyerror (" no comparison\n");}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 64 "Parser.y"
    {yyerror (" ')' in expression expected\n");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 65 "Parser.y"
    {yyerror (" '{' in expression expected\n");}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 66 "Parser.y"
    {yyerror ("there is nothing to be excecuted\n");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 67 "Parser.y"
    {yyerror (" '}' in expression expected\n");}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 69 "Parser.y"
    { 
if((yyvsp[(3) - (11)].i) == 1){(yyval.i) = (yyvsp[(6) - (11)].i); printf("statement returns %d\n",(yyval.i));}
else{ printf("statement returns %d\n",(yyvsp[(10) - (11)].i));} }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 73 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 74 "Parser.y"
    {yyerror (" no comparison\n");}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 75 "Parser.y"
    {yyerror (" ')' in expression expected\n");}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 76 "Parser.y"
    {yyerror (" '{' in IF expression expected\n");}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 77 "Parser.y"
    {yyerror ("there is nothing to be excecuted in your IF\n");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 78 "Parser.y"
    {yyerror (" '}' in IF expression expected\n");}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 79 "Parser.y"
    {yyerror (" '{' in ELSE expression expected\n");}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 80 "Parser.y"
    {yyerror ("there is nothing to be excecuted in your ELSE\n");}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 81 "Parser.y"
    {yyerror (" '}' in ELSE expression expected\n");}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 83 "Parser.y"
    {
while((yyvsp[(3) - (7)].i) == 1){(yyval.i) = (yyvsp[(6) - (7)].i); printf("statement returns %d\n",(yyval.i));};}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 86 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 87 "Parser.y"
    {yyerror (" no comparison\n");}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 88 "Parser.y"
    {yyerror (" ')' in expression expected\n");}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 89 "Parser.y"
    {yyerror (" '{' in expression expected\n");}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 90 "Parser.y"
    {yyerror ("there is nothing to be excecuted\n");}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 91 "Parser.y"
    {yyerror (" '}' in expression expected\n");}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 93 "Parser.y"
    {
int a = 0;
for( a = 0; a < (yyvsp[(3) - (7)].i); a = a + 1 ){
      printf("statement returns %d\n",(yyvsp[(6) - (7)].i));
   };}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 99 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 100 "Parser.y"
    {yyerror (" no counter\n");}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 101 "Parser.y"
    {yyerror (" ')' in expression expected\n");}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 102 "Parser.y"
    {yyerror (" '{' in expression expected\n");}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 103 "Parser.y"
    {yyerror ("there is nothing to be excecuted\n");}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 104 "Parser.y"
    {yyerror (" '}' in expression expected\n");}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 108 "Parser.y"
    {(yyval.i) = (yyvsp[(2) - (3)].i);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 109 "Parser.y"
    {(yyval.i) = ((yyvsp[(1) - (4)].i) == (yyvsp[(4) - (4)].i));}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 110 "Parser.y"
    {(yyval.i) = ((yyvsp[(1) - (3)].i) > (yyvsp[(3) - (3)].i));}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 111 "Parser.y"
    {(yyval.i) = ((yyvsp[(1) - (3)].i) < (yyvsp[(3) - (3)].i));}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 112 "Parser.y"
    {(yyval.i) = ((yyvsp[(1) - (4)].i) >= (yyvsp[(4) - (4)].i));}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 113 "Parser.y"
    {(yyval.i) = ((yyvsp[(1) - (4)].i) <= (yyvsp[(4) - (4)].i));}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 117 "Parser.y"
    {(yyval.i) = (yyvsp[(2) - (3)].i); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 118 "Parser.y"
    {(yyval.i) = (yyvsp[(1) - (3)].i) + (yyvsp[(3) - (3)].i); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 119 "Parser.y"
    {(yyval.i) = (yyvsp[(1) - (3)].i) - (yyvsp[(3) - (3)].i); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 120 "Parser.y"
    {(yyval.i) = (yyvsp[(1) - (3)].i) * (yyvsp[(3) - (3)].i); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 121 "Parser.y"
    {(yyval.i) = (yyvsp[(1) - (3)].i) / (yyvsp[(3) - (3)].i); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 124 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 125 "Parser.y"
    {yyerror (" first argument in expression missing\n");}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 126 "Parser.y"
    {yyerror (" second argument in expression missing\n");}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 127 "Parser.y"
    {yyerror (" ')' in expression expected\n"); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 130 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 131 "Parser.y"
    {yyerror (" first argument in expression missing\n");}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 132 "Parser.y"
    {yyerror (" second argument in expression missing\n");}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 133 "Parser.y"
    {yyerror (" ')' in expression expected\n"); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 136 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 137 "Parser.y"
    {yyerror (" first argument in expression missing\n");}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 138 "Parser.y"
    {yyerror (" second argument in expression missing\n");}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 139 "Parser.y"
    {yyerror (" ')' in expression expected\n"); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 142 "Parser.y"
    {yyerror (" '(' in expression expected\n");}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 143 "Parser.y"
    {yyerror (" first argument in expression missing\n");}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 144 "Parser.y"
    {yyerror (" second argument in expression missing\n");}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 145 "Parser.y"
    {yyerror (" ')' in expression expected\n"); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 147 "Parser.y"
    {(yyval.i) = (yyvsp[(1) - (1)].i);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 148 "Parser.y"
    {(yyval.i) = (yyvsp[(1) - (1)].i);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 149 "Parser.y"
    { 
int var = -1;
int i=0;
for(i = 0; i<=attr;i++){
if(strcmp(symbols[i].name, yylval.str) == 0){
var = i;
break;
}
}
if(var >= 0 ){(yyval.i) = symbols[var].value.intval;} else {printf("not a variable name");}}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 162 "Parser.y"
    {
(yyval.i) = (yyvsp[(4) - (4)].i);
attr++;
Variable var = { .name = (yyvsp[(2) - (4)].str), .type = 0, .value.intval = (yyvsp[(4) - (4)].i)};
symbols[attr] = var;
}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 168 "Parser.y"
    {
(yyval.i) = (yyvsp[(4) - (4)].i);
attr++;
struct Variable var = { .name = (yyvsp[(2) - (4)].str), .type = 1, .value.floatval = (yyvsp[(4) - (4)].i)};
symbols[attr] = var;
}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 176 "Parser.y"
    {printlist();}
    break;


/* Line 1792 of yacc.c  */
#line 2034 "Parser.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 179 "Parser.y"


extern FILE *yyin;
extern int yylex();
extern int yyparse();

main(){
printf("Type in a calculation\n");
yyparse();
}

/* Allgemeines Errorhandling */
yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}

/* Ausgabe aller Variablen mit Value  */
printlist(){
int i=0;
for(i = 0; i<=attr;i++){
printf("%d name is %s\n", i,symbols[i].name);
printf("%d value is %d\n", i,symbols[i].value.intval);
}
}



