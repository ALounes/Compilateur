/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IFX = 258,
     T_ELSE = 259,
     T_NE = 260,
     T_EQ = 261,
     T_LE = 262,
     T_GE = 263,
     T_OR = 264,
     T_AND = 265,
     T_UMINUS = 266,
     T_NNOT = 267,
     T_BEGIN = 268,
     T_DO = 269,
     T_END = 270,
     T_FUNCTION = 271,
     T_IF = 272,
     T_NOT = 273,
     T_NUMERIC = 274,
     T_PROGRAM = 275,
     T_RETURN = 276,
     T_SKIP = 277,
     T_THEN = 278,
     T_VAR = 279,
     T_VARIABLE = 280,
     T_WHILE = 281,
     T_WRITE = 282
   };
#endif
/* Tokens.  */
#define IFX 258
#define T_ELSE 259
#define T_NE 260
#define T_EQ 261
#define T_LE 262
#define T_GE 263
#define T_OR 264
#define T_AND 265
#define T_UMINUS 266
#define T_NNOT 267
#define T_BEGIN 268
#define T_DO 269
#define T_END 270
#define T_FUNCTION 271
#define T_IF 272
#define T_NOT 273
#define T_NUMERIC 274
#define T_PROGRAM 275
#define T_RETURN 276
#define T_SKIP 277
#define T_THEN 278
#define T_VAR 279
#define T_VARIABLE 280
#define T_WHILE 281
#define T_WRITE 282




/* Copy the first part of user declarations.  */
#line 1 "eise.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "symboles.h"
#include "ast.h"

int yylex(void);
void yyerror(char *s);

nodeType *programRoot;

int typeDeclaration;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "eise.y"
{
	float f;
	char *s;
	nodeType *np;
}
/* Line 193 of yacc.c.  */
#line 174 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 187 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    14,    11,    36,    12,    35,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       6,    39,     5,     2,     2,     2,     2,     2,     2,     2,
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
       7,     8,     9,    10,    13,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    14,    15,    18,    19,    20,    21,
      22,    25,    27,    31,    35,    37,    39,    40,    43,    45,
      53,    56,    59,    60,    63,    66,    67,    69,    73,    77,
      80,    82,    84,    86,    88,    90,    92,    94,    96,   101,
     108,   113,   115,   118,   121,   125,   130,   134,   136,   138,
     142,   146,   150,   154,   158,   162,   166,   170,   174,   178,
     182,   185,   189,   193,   196,   198
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    26,    31,    34,    42,    35,    -1,    43,
      44,    51,    59,    -1,    -1,    45,    48,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    49,    -1,    30,    50,    34,
      -1,    50,    36,    31,    -1,    31,    -1,    52,    -1,    -1,
      52,    53,    -1,    53,    -1,    54,    37,    55,    38,    34,
      56,    34,    -1,    22,    31,    -1,    46,    50,    -1,    -1,
      57,    59,    -1,    47,    48,    -1,    -1,    31,    -1,    19,
      60,    21,    -1,    60,    61,    34,    -1,    61,    34,    -1,
      59,    -1,    64,    -1,    65,    -1,    66,    -1,    68,    -1,
      67,    -1,    62,    -1,    63,    -1,    23,    70,    29,    61,
      -1,    23,    70,    29,    61,     4,    61,    -1,    32,    70,
      20,    61,    -1,    28,    -1,    33,    70,    -1,    27,    70,
      -1,    58,    39,    70,    -1,    31,    37,    69,    38,    -1,
      69,    36,    70,    -1,    70,    -1,    25,    -1,    70,    11,
      70,    -1,    70,    12,    70,    -1,    70,    14,    70,    -1,
      70,    15,    70,    -1,    37,    70,    38,    -1,    70,     6,
      70,    -1,    70,     5,    70,    -1,    70,    10,    70,    -1,
      70,     9,    70,    -1,    70,     7,    70,    -1,    70,     8,
      70,    -1,    24,    70,    -1,    70,    16,    70,    -1,    70,
      13,    70,    -1,    12,    70,    -1,    58,    -1,    68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    69,    89,    95,    96,   100,   107,   114,
     120,   121,   124,   127,   128,   131,   132,   135,   136,   139,
     146,   162,   163,   166,   169,   170,   173,   189,   192,   193,
     196,   197,   198,   199,   200,   201,   202,   203,   206,   207,
     210,   213,   216,   219,   226,   229,   243,   245,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IFX", "T_ELSE", "'>'", "'<'", "T_NE",
  "T_EQ", "T_LE", "T_GE", "'+'", "'-'", "T_OR", "'*'", "'/'", "T_AND",
  "T_UMINUS", "T_NNOT", "T_BEGIN", "T_DO", "T_END", "T_FUNCTION", "T_IF",
  "T_NOT", "T_NUMERIC", "T_PROGRAM", "T_RETURN", "T_SKIP", "T_THEN",
  "T_VAR", "T_VARIABLE", "T_WHILE", "T_WRITE", "';'", "'.'", "','", "'('",
  "')'", "'='", "$accept", "program_eise", "bloc_principal",
  "set_nbvariables_globales_to_0", "partie_declaration_variables_globales",
  "set_type_declaration_globales", "set_type_declaration_formels",
  "set_type_declaration_locales", "liste_declaration_variables",
  "declaration_variable", "liste_variables", "partie_definition_fonctions",
  "liste_definition_fonctions", "definition_fonction",
  "prototype_fonction", "liste_parametres_formels", "bloc_fonction",
  "partie_declaration_variables_locales", "acces_variable",
  "instruction_composee", "liste_instructions", "instruction",
  "if_instruction", "while_instruction", "skip_instruction",
  "write_instruction", "return_instruction", "affectation",
  "appel_fonction", "liste_parametres_effectifs", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,    62,    60,   260,   261,   262,
     263,    43,    45,   264,    42,    47,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,    59,    46,    44,    40,    41,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    44,    44,    45,    46,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    52,    53,
      54,    55,    55,    56,    57,    57,    58,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      63,    64,    65,    66,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     0,     2,     0,     0,     0,     0,
       2,     1,     3,     3,     1,     1,     0,     2,     1,     7,
       2,     2,     0,     2,     2,     0,     1,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     6,
       4,     1,     2,     2,     3,     4,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     6,     2,    16,
       0,     0,     0,    15,    18,     0,     0,     5,    11,    20,
       0,     3,    17,     8,    14,     0,    10,     0,     0,    41,
      26,     0,     0,     0,    30,     0,     0,    36,    37,    31,
      32,    33,    35,    34,     0,     0,    12,     0,     0,     0,
      48,     0,    64,    65,     0,    43,     0,     0,    42,     0,
      27,     0,    29,    21,     0,    13,    63,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,    44,    28,     9,    53,    55,
      54,    58,    59,    57,    56,    49,    50,    62,    51,    52,
      61,    38,     0,    45,    40,     0,     0,     0,     0,    46,
      24,    19,    23,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     7,     9,    10,    44,   105,    17,    18,
      25,    12,    13,    14,    15,    45,   106,   107,    52,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    53,    82,
      54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -26
static const yytype_int16 yypact[] =
{
     -21,   -25,    11,   -15,   -26,   -26,   -19,   -20,   -26,    -2,
      -7,    -5,    17,    -2,   -26,     2,     9,    -7,   -26,   -26,
      49,   -26,   -26,    -8,   -26,    23,   -26,    -3,    -3,   -26,
       7,    -3,    -3,    26,   -26,    10,    35,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,     9,    32,   -26,    40,    -3,    -3,
     -26,    -3,   -26,   -26,   103,   144,    -3,   128,   144,    -3,
     -26,    39,   -26,    38,    41,   -26,   -26,   -26,    91,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    49,    24,   144,    49,   144,   -26,    60,   -26,   109,
     109,   109,   109,   109,   109,    -1,    -1,    -1,   -26,   -26,
     -26,    79,    -3,   -26,   -26,    -7,    50,    17,    49,   144,
      -7,   -26,   -26,   -26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -13,   -16,
      42,   -26,   -26,    74,   -26,   -26,   -26,   -26,   -18,   -12,
     -26,   -23,   -26,   -26,   -26,   -26,   -26,   -26,   -17,   -26,
     -24
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int8 yytable[] =
{
      21,    26,    33,    43,    55,     1,     3,    57,    58,    48,
      -7,     4,    61,    78,    79,    80,     8,    33,    43,     5,
      11,    49,    50,    16,    66,    67,    19,    68,    30,    20,
     -22,    60,    83,    27,    51,    85,    20,    28,    29,    23,
      24,    30,    31,    32,    56,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    46,   101,    47,
     102,   104,   103,    33,    43,    59,    33,    43,    20,    62,
      64,    65,    27,    86,    47,    87,    28,    29,   109,   -25,
      30,    31,    32,   108,   111,   113,    63,    22,     0,     0,
      33,    43,   110,     0,    26,   112,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    88,
       0,     0,    81,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80
};

static const yytype_int8 yycheck[] =
{
      12,    17,    20,    20,    28,    26,    31,    31,    32,    12,
      30,     0,    35,    14,    15,    16,    35,    35,    35,    34,
      22,    24,    25,    30,    48,    49,    31,    51,    31,    19,
      38,    21,    56,    23,    37,    59,    19,    27,    28,    37,
      31,    31,    32,    33,    37,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    34,    81,    36,
      36,    84,    38,    81,    81,    39,    84,    84,    19,    34,
      38,    31,    23,    34,    36,    34,    27,    28,   102,    19,
      31,    32,    33,     4,    34,   108,    44,    13,    -1,    -1,
     108,   108,   105,    -1,   110,   107,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    38,
      -1,    -1,    29,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    20,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    41,    31,     0,    34,    42,    43,    35,    44,
      45,    22,    51,    52,    53,    54,    30,    48,    49,    31,
      19,    59,    53,    37,    31,    50,    49,    23,    27,    28,
      31,    32,    33,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    46,    55,    34,    36,    12,    24,
      25,    37,    58,    68,    70,    70,    37,    70,    70,    39,
      21,    61,    34,    50,    38,    31,    70,    70,    70,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    29,    69,    70,    20,    70,    34,    34,    38,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    61,    36,    38,    61,    47,    56,    57,     4,    70,
      48,    34,    59,    61
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 2:
#line 65 "eise.y"
    { programRoot = (yyvsp[(4) - (5)].np); }
    break;

  case 3:
#line 72 "eise.y"
    { nodeType *n0, *n1, *n2;
				  n0 = createOperatorNode(OPER_RESERVE_SPACE,0); 
				  if ((yyvsp[(3) - (4)].np)!=NULL)
				  {
				  	n2 = createOperatorNode(OPER_MAIN,1,(yyvsp[(4) - (4)].np));
				  	n1 = createOperatorNode(OPER_SEQUENCE,2,(yyvsp[(3) - (4)].np),n2);
				  	(yyval.np) = createOperatorNode(OPER_SEQUENCE,2,n0,n1); 
				  }
				  else
				  {
				  	n2 = createOperatorNode(OPER_MAIN,1,(yyvsp[(4) - (4)].np));
				  	(yyval.np) = createOperatorNode(OPER_SEQUENCE,2,n0,n2); 
				  }
				}
    break;

  case 4:
#line 89 "eise.y"
    { 
			reset_index_table_nbre_variables(0); 
			printf("nbVariablesGlobales=0\n");
		}
    break;

  case 7:
#line 100 "eise.y"
    { 
			typeDeclaration=TYPE_VARIABLE_GLOBALE; 
			printf("typeDeclaration=TYPE_VARIABLE_GLOBALE\n");
		}
    break;

  case 8:
#line 107 "eise.y"
    { 
			typeDeclaration=TYPE_PARAMETRE; 
			printf("typeDeclaration=TYPE_PARAMETRE\n");
		}
    break;

  case 9:
#line 114 "eise.y"
    { 
			typeDeclaration=TYPE_VARIABLE_LOCALE; 
			printf("typeDeclaration=TYPE_VARIABLE_LOCALE\n");
		}
    break;

  case 13:
#line 127 "eise.y"
    { declarer_variable(getFunctionNum(),(yyvsp[(3) - (3)].s),typeDeclaration); }
    break;

  case 14:
#line 128 "eise.y"
    { declarer_variable(getFunctionNum(),(yyvsp[(1) - (1)].s),typeDeclaration); }
    break;

  case 16:
#line 132 "eise.y"
    { (yyval.np) = NULL ; }
    break;

  case 17:
#line 135 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_SEQUENCE,2,(yyvsp[(1) - (2)].np),(yyvsp[(2) - (2)].np)); }
    break;

  case 19:
#line 140 "eise.y"
    { 
			(yyval.np) = createOperatorNode(OPER_DEF_FONCTION,2,(yyvsp[(1) - (7)].np),(yyvsp[(6) - (7)].np)) ;
			print_current_table_symb();
		}
    break;

  case 20:
#line 147 "eise.y"
    { 
			declarer_variable(0,(yyvsp[(2) - (2)].s),TYPE_FONCTION);
			int index=est_deja_declare(0,(yyvsp[(2) - (2)].s));
			printf("index=%d\n",index);

			increment_current_function();
			printf("getFunctionNum()=%d\n",getFunctionNum());
			ajouter_table_fonctions(index,getFunctionNum());
			
		  	nodeType *nodeIndex=createNumericNode((float)index);
		  	nodeType *nodeFunctionNum=createNumericNode((float)getFunctionNum());
		  	(yyval.np) = createOperatorNode(OPER_SEQUENCE,2,nodeIndex,nodeFunctionNum); 
	        }
    break;

  case 23:
#line 166 "eise.y"
    { (yyval.np) = (yyvsp[(2) - (2)].np) ; }
    break;

  case 26:
#line 174 "eise.y"
    { 
			int varloc=est_deja_declare(getFunctionNum(),(yyvsp[(1) - (1)].s));
			int varglob=est_deja_declare(0,(yyvsp[(1) - (1)].s));
			if (varloc!=-1)
				(yyval.np)=createIdentifierNode((yyvsp[(1) - (1)].s),getFunctionNum(),varloc) ; 
			else if (varglob!=-1)
				(yyval.np)=createIdentifierNode((yyvsp[(1) - (1)].s),0,varglob) ; 
			else
			{
				printf("variable %s non declaree\n",(yyvsp[(1) - (1)].s));
				exit(1);
			}
		}
    break;

  case 27:
#line 189 "eise.y"
    { (yyval.np) = (yyvsp[(2) - (3)].np) ; }
    break;

  case 28:
#line 192 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_SEQUENCE,2,(yyvsp[(1) - (3)].np),(yyvsp[(2) - (3)].np)); }
    break;

  case 38:
#line 206 "eise.y"
    { (yyval.np)=createOperatorNode(OPER_IF,2,(yyvsp[(2) - (4)].np),(yyvsp[(4) - (4)].np)); }
    break;

  case 39:
#line 207 "eise.y"
    { (yyval.np)=createOperatorNode(OPER_IF,3,(yyvsp[(2) - (6)].np),(yyvsp[(4) - (6)].np),(yyvsp[(6) - (6)].np)) ; }
    break;

  case 40:
#line 210 "eise.y"
    { (yyval.np)=createOperatorNode(OPER_WHILE,2,(yyvsp[(2) - (4)].np),(yyvsp[(4) - (4)].np)); }
    break;

  case 41:
#line 213 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_SKIP,0); }
    break;

  case 42:
#line 216 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_WRITE,1,(yyvsp[(2) - (2)].np)); }
    break;

  case 43:
#line 220 "eise.y"
    { 
			nodeType *n0=createIdentifierNode("RET",getFunctionNum(),0) ; 
			(yyval.np) = createOperatorNode(OPER_RETURN,2,n0,(yyvsp[(2) - (2)].np)); 
		}
    break;

  case 44:
#line 226 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_ASSIGN,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)) ; printf("OPER_ASSIGN=%p\n",(yyval.np)) ; }
    break;

  case 45:
#line 230 "eise.y"
    { 
			int varglob=est_deja_declare(0,(yyvsp[(1) - (4)].s));
			printf("appel_fonction varglob=%d\n",varglob);
			if (varglob!=-1)
				(yyval.np) = createOperatorNode(OPER_APPEL_FONCTION,2,createIdentifierNode((yyvsp[(1) - (4)].s),0,varglob),(yyvsp[(3) - (4)].np)) ; 
			else
			{
				printf("fonction %s inconnue\n",(yyvsp[(1) - (4)].s));
				exit(1);
			}
		}
    break;

  case 46:
#line 244 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_SEQUENCE,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)) ; }
    break;

  case 48:
#line 248 "eise.y"
    { (yyval.np) = createNumericNode((yyvsp[(1) - (1)].f)); }
    break;

  case 49:
#line 249 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_ADD,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 50:
#line 250 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_SUB,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 51:
#line 251 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_MULT,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 52:
#line 252 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_DIV,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 53:
#line 253 "eise.y"
    { (yyval.np) = (yyvsp[(2) - (3)].np) ; }
    break;

  case 54:
#line 254 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_INF,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 55:
#line 255 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_SUP,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 56:
#line 256 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_GE,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 57:
#line 257 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_LE,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 58:
#line 258 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_NE,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 59:
#line 259 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_EQ,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 60:
#line 260 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_NOT,1,(yyvsp[(2) - (2)].np)); }
    break;

  case 61:
#line 261 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_AND,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 62:
#line 262 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_OR,2,(yyvsp[(1) - (3)].np),(yyvsp[(3) - (3)].np)); }
    break;

  case 63:
#line 263 "eise.y"
    { (yyval.np) = createOperatorNode(OPER_NEG,1,(yyvsp[(2) - (2)].np)); }
    break;


/* Line 1267 of yacc.c.  */
#line 1771 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 267 "eise.y"


void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
	init_table_symboles();
    	yyparse();
	print_table_symb(0);
	print_table_fonctions();
	//printf("generateDigraph\n");
	//generateDigraph(programRoot);
	//printf("generateAsm\n");
	generateAsm(programRoot,"res.asm");
    	return 0;
}

