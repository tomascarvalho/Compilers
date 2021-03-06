/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mccompiler.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

void yyerror(char *s);
int yylex();

extern char *yytext;
extern int linha, coluna, flag_l, lex;

int aux_ref = 0;
int flag_error = 0;
int print_t = 0;


node* root;
node* aux;


#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMP = 258,
    AND = 259,
    ASSIGN = 260,
    AST = 261,
    CHAR = 262,
    COMMMA = 263,
    DIV = 264,
    ELSE = 265,
    EQ = 266,
    FOR = 267,
    GE = 268,
    GT = 269,
    IF = 270,
    INT = 271,
    LBRACE = 272,
    LE = 273,
    LPAR = 274,
    LSQ = 275,
    LT = 276,
    MINUS = 277,
    MOD = 278,
    NE = 279,
    NOT = 280,
    OR = 281,
    PLUS = 282,
    RBRACE = 283,
    RETURN = 284,
    RPAR = 285,
    RSQ = 286,
    SEMI = 287,
    VOID = 288,
    RESERVED = 289,
    ID = 290,
    INTLIT = 291,
    CHRLIT = 292,
    STRLIT = 293,
    COMMA = 294,
    PRECEDENCE = 295
  };
#endif
/* Tokens.  */
#define AMP 258
#define AND 259
#define ASSIGN 260
#define AST 261
#define CHAR 262
#define COMMMA 263
#define DIV 264
#define ELSE 265
#define EQ 266
#define FOR 267
#define GE 268
#define GT 269
#define IF 270
#define INT 271
#define LBRACE 272
#define LE 273
#define LPAR 274
#define LSQ 275
#define LT 276
#define MINUS 277
#define MOD 278
#define NE 279
#define NOT 280
#define OR 281
#define PLUS 282
#define RBRACE 283
#define RETURN 284
#define RPAR 285
#define RSQ 286
#define SEMI 287
#define VOID 288
#define RESERVED 289
#define ID 290
#define INTLIT 291
#define CHRLIT 292
#define STRLIT 293
#define COMMA 294
#define PRECEDENCE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 23 "mccompiler.y" /* yacc.c:355  */

    char* var;
    struct node* no;

#line 213 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    51,    52,    55,    56,    57,    58,    61,
      64,    75,    78,    79,    82,    83,    86,    87,    91,    94,
     106,   107,   110,   113,   114,   117,   118,   121,   127,   130,
     131,   138,   139,   140,   143,   157,   171,   181,   193,   230,
     277,   318,   322,   332,   343,   375,   421,   462,   472,   473,
     478,   479,   482,   483,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   516,   517,   518,   519,   520,
     521,   522,   523
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMP", "AND", "ASSIGN", "AST", "CHAR",
  "COMMMA", "DIV", "ELSE", "EQ", "FOR", "GE", "GT", "IF", "INT", "LBRACE",
  "LE", "LPAR", "LSQ", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RETURN", "RPAR", "RSQ", "SEMI", "VOID", "RESERVED", "ID",
  "INTLIT", "CHRLIT", "STRLIT", "COMMA", "PRECEDENCE", "$accept", "Start",
  "Repetition", "FunctionDefinition", "FunctionBody", "DeclarationAux",
  "StatementAux", "StatementAux1", "FunctionDeclaration",
  "FunctionDeclarator", "AstAux", "ParameterList", "ParameterAux",
  "ParameterDeclaration", "Declaration", "DeclaratorAux", "TypeSpec",
  "Declarator", "Statement", "StatementE", "ExprStat", "ExpressionAux",
  "Expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,    -7,   -46,   -46,   -46,    10,    20,    20,    20,    26,
     -46,   -46,   -46,    20,    20,    20,   -46,   -46,    26,   -13,
      30,     6,   -46,   -46,   -46,   -46,   108,   -46,   -46,    31,
      26,    36,    -4,   307,   146,    26,     0,    27,    35,     6,
     -46,   -46,   327,   327,    52,    57,   307,   280,   327,   327,
     327,   327,    62,   -46,   -46,   -46,    59,   184,    66,    68,
     362,   -46,    75,    69,    26,    81,    96,   -46,    97,    97,
     327,   327,    90,    89,   -24,    97,    97,    97,    99,    37,
     -46,   100,   102,   103,   222,   327,   -46,   184,   106,   -46,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   -46,     0,   -46,    94,
     -46,   107,   -22,   -46,   -46,   -46,   -46,   112,   -46,   -16,
     -46,   327,   327,    78,   120,   118,   -46,   -46,   362,   405,
     362,    97,    97,   424,   209,   209,   209,    -9,   209,    60,
      97,   424,   386,    60,    69,   -46,   327,   260,   -46,   -46,
     119,    16,   -46,   -46,   -46,   -46,   -46,   122,   145,   327,
     260,   327,   260,   124,   147,   129,   -46,   327,   260,   260,
     130,   -46,   -46,   260,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    31,    32,    33,     0,     0,     0,     0,    21,
      28,     1,     2,     0,     0,     0,     3,     4,    21,     0,
       0,    29,     6,     7,     8,    20,     0,    18,     9,    35,
      21,     0,     0,    15,     0,    21,     0,     0,     0,    29,
      27,    11,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    50,    76,    77,    78,    79,     0,     0,     0,    51,
      53,    13,     0,    23,    21,     0,    35,    30,    68,    69,
      50,     0,     0,     0,     0,    71,    72,    70,     0,     0,
      10,     0,     0,     0,     0,    50,    14,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,    22,    26,
      34,     0,     0,    37,    81,    80,    41,     0,    75,     0,
      48,    50,     0,     0,     0,     0,    16,    42,    52,    55,
      54,    65,    66,    57,    62,    60,    61,     0,    59,    64,
      67,    58,    56,    63,    23,    25,    50,     0,    82,    74,
       0,     0,    49,    43,    47,    73,    24,     0,    38,    50,
       0,    50,     0,     0,    44,     0,    39,    50,     0,     0,
       0,    45,    40,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,    71,   164,   -46,   132,   121,   -27,   169,   -46,
      -6,   -46,    33,    63,     5,   133,   -25,   150,   -46,    29,
     -33,   -45,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,    12,    13,    28,    33,    56,    86,    14,    19,
      38,    62,   108,    63,    15,    31,     9,    21,    57,    87,
      88,    59,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    35,    74,    20,    26,     8,   115,     2,   147,    35,
      11,    64,    25,    58,   149,    90,     3,    90,    78,    27,
      -5,     1,   155,    90,    41,    10,   112,     2,    10,     1,
      90,    34,    18,     4,   119,     2,     3,   111,   117,    34,
      42,    68,    69,    43,     3,    30,   160,    75,    76,    77,
      36,    37,   125,     4,   137,    90,    47,   124,   109,    48,
     126,     4,    49,    65,    50,    29,    93,   118,    40,    94,
      66,    70,    52,    53,    54,    55,    71,   151,    16,    17,
      99,    79,    64,   102,    22,    23,    24,    80,   150,   128,
     129,   130,   131,   132,   133,   134,   135,   136,    89,   138,
     139,   140,   141,   142,   143,   106,   152,    90,   107,    32,
     120,   -12,   110,   157,   -12,     2,    37,    99,   113,   114,
     -12,   121,   122,   -12,     3,   -12,   163,   -12,   165,   145,
     -12,   116,   120,   -12,   170,   -12,   -12,   -12,   127,   146,
     -12,     4,   148,   -12,   -12,   -12,   -12,     1,   153,   -12,
     154,   159,   -12,     2,   161,   162,   167,   168,   -12,   169,
     173,   -12,     3,   -12,     6,   -12,    61,    72,   -12,     7,
     144,   -12,    67,   -12,   -12,   -12,   158,   156,   -12,     4,
      39,   -12,   -12,   -12,   -12,    81,     0,    42,     0,   164,
      43,   166,     0,     0,     0,     0,    82,   171,   172,    83,
       0,    84,   174,    47,     0,     0,    48,     0,     0,    49,
       0,    50,   -17,    85,     0,    93,   -50,     0,    94,    52,
      53,    54,    55,   123,     0,    42,     0,     0,    43,    99,
       0,   101,   102,     0,    82,     0,   105,    83,     0,    84,
       0,    47,     0,     0,    48,     0,     0,    49,     0,    50,
     -17,    85,     0,     0,   -50,     0,     0,    52,    53,    54,
      55,    81,     0,    42,     0,     0,    43,     0,     0,     0,
       0,     0,    82,     0,     0,    83,     0,    84,     0,    47,
       0,    73,    48,    42,     0,    49,    43,    50,     0,    85,
       0,     0,   -50,     0,     0,    52,    53,    54,    55,    47,
       0,     0,    48,     0,     0,    49,     0,    50,     0,     0,
      42,     0,     0,    43,     0,    52,    53,    54,    55,    44,
       0,     0,    45,     0,    46,     0,    47,     0,     0,    48,
      42,     0,    49,    43,    50,     0,    51,     0,     0,   -50,
       0,     0,    52,    53,    54,    55,    47,     0,     0,    48,
       0,     0,    49,     0,    50,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,    55,    91,    92,    93,     0,
       0,    94,     0,    95,     0,    96,    97,     0,     0,     0,
      98,     0,    99,   100,   101,   102,   103,     0,   104,   105,
      91,     0,    93,     0,     0,    94,     0,    95,     0,    96,
      97,     0,     0,     0,    98,     0,    99,   100,   101,   102,
     103,    93,     0,   105,    94,     0,    95,     0,    96,    97,
       0,     0,     0,    98,     0,    99,   100,   101,   102,   103,
      93,     0,   105,    94,     0,     0,     0,    96,    97,     0,
       0,     0,    98,     0,    99,   100,   101,   102,     0,     0,
       0,   105
};

static const yytype_int16 yycheck[] =
{
      33,    26,    47,     9,    17,     0,    30,     7,    30,    34,
       0,    36,    18,    46,    30,    39,    16,    39,    51,    32,
       0,     1,    31,    39,    28,    32,    71,     7,    32,     1,
      39,    26,     6,    33,    79,     7,    16,    70,     1,    34,
       3,    42,    43,     6,    16,    39,    30,    48,    49,    50,
      19,    20,    85,    33,    99,    39,    19,    84,    64,    22,
      87,    33,    25,    36,    27,    35,     6,    30,    32,     9,
      35,    19,    35,    36,    37,    38,    19,   122,     7,     8,
      20,    19,   107,    23,    13,    14,    15,    28,   121,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    32,   100,
     101,   102,   103,   104,   105,    30,    28,    39,    39,     1,
      32,     3,    31,   146,     6,     7,    20,    20,    28,    30,
      12,    19,    19,    15,    16,    17,   159,    19,   161,    35,
      22,    32,    32,    25,   167,    27,    28,    29,    32,    32,
      32,    33,    30,    35,    36,    37,    38,     1,    28,     3,
      32,    32,     6,     7,    32,    10,    32,    10,    12,    30,
      30,    15,    16,    17,     0,    19,    34,    46,    22,     0,
     107,    25,    39,    27,    28,    29,   147,   144,    32,    33,
      30,    35,    36,    37,    38,     1,    -1,     3,    -1,   160,
       6,   162,    -1,    -1,    -1,    -1,    12,   168,   169,    15,
      -1,    17,   173,    19,    -1,    -1,    22,    -1,    -1,    25,
      -1,    27,    28,    29,    -1,     6,    32,    -1,     9,    35,
      36,    37,    38,     1,    -1,     3,    -1,    -1,     6,    20,
      -1,    22,    23,    -1,    12,    -1,    27,    15,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,     1,    -1,     3,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    15,    -1,    17,    -1,    19,
      -1,     1,    22,     3,    -1,    25,     6,    27,    -1,    29,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,    19,
      -1,    -1,    22,    -1,    -1,    25,    -1,    27,    -1,    -1,
       3,    -1,    -1,     6,    -1,    35,    36,    37,    38,    12,
      -1,    -1,    15,    -1,    17,    -1,    19,    -1,    -1,    22,
       3,    -1,    25,     6,    27,    -1,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    19,    -1,    -1,    22,
      -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    13,    14,    -1,    -1,    -1,
      18,    -1,    20,    21,    22,    23,    24,    -1,    26,    27,
       4,    -1,     6,    -1,    -1,     9,    -1,    11,    -1,    13,
      14,    -1,    -1,    -1,    18,    -1,    20,    21,    22,    23,
      24,     6,    -1,    27,     9,    -1,    11,    -1,    13,    14,
      -1,    -1,    -1,    18,    -1,    20,    21,    22,    23,    24,
       6,    -1,    27,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    16,    33,    42,    44,    49,    55,    57,
      32,     0,    43,    44,    49,    55,    43,    43,     6,    50,
      51,    58,    43,    43,    43,    51,    17,    32,    45,    35,
      39,    56,     1,    46,    55,    57,    19,    20,    51,    58,
      32,    28,     3,     6,    12,    15,    17,    19,    22,    25,
      27,    29,    35,    36,    37,    38,    47,    59,    61,    62,
      63,    46,    52,    54,    57,    36,    35,    56,    63,    63,
      19,    19,    47,     1,    62,    63,    63,    63,    61,    19,
      28,     1,    12,    15,    17,    29,    48,    60,    61,    32,
      39,     4,     5,     6,     9,    11,    13,    14,    18,    20,
      21,    22,    23,    24,    26,    27,    30,    39,    53,    51,
      31,    61,    62,    28,    30,    30,    32,     1,    30,    62,
      32,    19,    19,     1,    48,    61,    48,    32,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    62,    63,    63,
      63,    63,    63,    63,    54,    35,    32,    30,    30,    30,
      61,    62,    28,    28,    32,    31,    53,    61,    60,    32,
      30,    32,    10,    61,    60,    61,    60,    32,    10,    30,
      61,    60,    60,    30,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    43,    43,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    50,
      51,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     2,     2,     3,
       4,     3,     0,     2,     2,     0,     2,     0,     3,     5,
       2,     0,     2,     0,     3,     3,     2,     4,     2,     0,
       3,     1,     1,     1,     5,     2,     2,     3,     5,     7,
       9,     3,     2,     3,     5,     7,     9,     3,     2,     3,
       0,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     4,     4,     3,     1,     1,     1,     1,
       3,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
        case 2:
#line 50 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(rt_node,"Program",""); root = (yyval.no); addChild((yyval.no),(yyvsp[-1].no)); addBrother((yyvsp[-1].no),(yyvsp[0].no));}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(rt_node,"Program",""); root = (yyval.no); addChild((yyval.no),(yyvsp[-1].no)); addBrother((yyvsp[-1].no),(yyvsp[0].no));}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 52 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(rt_node,"Program",""); root = (yyval.no); addChild((yyval.no),(yyvsp[-1].no)); addBrother((yyvsp[-1].no),(yyvsp[0].no));}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 55 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 56 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no),(yyvsp[0].no));}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 57 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no),(yyvsp[0].no));}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 58 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no),(yyvsp[0].no));}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(funcdec_node,"FuncDefinition",""); addChild((yyval.no), (yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[-1].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 64 "mccompiler.y" /* yacc.c:1646  */
    {	(yyval.no) = createNode(funcdec_node,"FuncBody",""); 
																	if ((yyvsp[-2].no) != NULL)
																	{
																		addChild((yyval.no),(yyvsp[-2].no));
																		addBrother((yyvsp[-2].no),(yyvsp[-1].no));
																	}
																	else
																	{
																		addChild((yyval.no), (yyvsp[-1].no));
																	}
																 }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 75 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL; flag_error = 1;}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 78 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 79 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); addBrother((yyvsp[-1].no),(yyvsp[0].no));}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 82 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); addBrother((yyvsp[-1].no),(yyvsp[0].no));}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 83 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 86 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); addBrother((yyvsp[-1].no), (yyvsp[0].no));}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 87 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(funcdec_node,"FuncDeclaration",""); addChild((yyval.no), (yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[-1].no));}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "mccompiler.y" /* yacc.c:1646  */
    { 	aux = createNode(id_node,"Id",(yyvsp[-3].var));
                                                                	if((yyvsp[-4].no) != NULL ){
                                                                  		(yyval.no) = (yyvsp[-4].no);
                                                                  		addBrother((yyvsp[-4].no), aux);
                                                                	}
                                                                	else{
                                                             	 		(yyval.no) = aux;
                                                            		}
                                                                	addBrother((yyval.no),(yyvsp[-1].no));
                                                              	}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 106 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(term_node,"Pointer",""); addBrother((yyval.no),(yyvsp[0].no));}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 107 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(funcdec_node,"ParamList",""); addChild((yyval.no),(yyvsp[-1].no)); addBrother((yyvsp[-1].no),(yyvsp[0].no));}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 113 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 114 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); addBrother((yyvsp[-1].no), (yyvsp[0].no));}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 117 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(funcdec_node,"ParamDeclaration",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[-1].no)); addBrother((yyvsp[-2].no),createNode(id_node,"Id",(yyvsp[0].var))); }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 118 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(funcdec_node,"ParamDeclaration",""); addChild((yyval.no),(yyvsp[-1].no)); addBrother((yyvsp[-1].no),(yyvsp[0].no)); }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 121 "mccompiler.y" /* yacc.c:1646  */
    {
                                                                    if((yyvsp[-2].no)->aux_ref == 2) (yyval.no) = createNode(vardec_node,"ArrayDeclaration","");
                                                                    else if((yyvsp[-2].no)->aux_ref == 1) (yyval.no) = createNode(vardec_node,"Declaration","");
                                                                    addChild((yyval.no),(yyvsp[-3].no)); addBrother((yyvsp[-3].no),(yyvsp[-2].no)); addBrother((yyval.no),(yyvsp[-1].no));
                                                                    assign_value((yyval.no),(yyvsp[-3].no)->str_type);
                                                              	}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL; flag_error = 1; }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 131 "mccompiler.y" /* yacc.c:1646  */
    { 	if((yyvsp[-1].no)->aux_ref == 2) (yyval.no) = createNode(vardec_node,"ArrayDeclaration","");
                                                                	else if((yyvsp[-1].no)->aux_ref == 1) (yyval.no) = createNode(vardec_node,"Declaration","");
                                                                	addChild((yyval.no),createNode(term_node,"",""));
                                                                	addBrother((yyval.no)->son,(yyvsp[-1].no)); addBrother((yyval.no),(yyvsp[0].no));
                                                              	}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 138 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(term_node,"Char","");}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 139 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(term_node,"Int","");}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 140 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(term_node,"Void","");}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 143 "mccompiler.y" /* yacc.c:1646  */
    { 
																	aux = createNode(id_node,"Id",(yyvsp[-3].var));
                                                                    if((yyvsp[-4].no) != NULL)
                                                                    {
            	                                                		(yyval.no) = (yyvsp[-4].no);
                                            		                    addBrother((yyvsp[-4].no),aux);
                                                        			}
                                                                    else
                                                                    {
                                                                    	(yyval.no) = aux;
                                                                    }
                                                                    (yyval.no)->aux_ref = 2;
                                                                    addBrother((yyval.no), createNode(id_node,"IntLit",(yyvsp[-1].var)));
                                                              	}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 157 "mccompiler.y" /* yacc.c:1646  */
    { 	aux = createNode(id_node,"Id",(yyvsp[0].var));
                                                                	if((yyvsp[-1].no) != NULL)
                                                                	{
                                                                        (yyval.no) = (yyvsp[-1].no);
                                                                    	addBrother((yyvsp[-1].no),aux);
                                            	                    }
                                                                    else{
                                                                    	(yyval.no) = aux;

                                                                    }
                                                                    (yyval.no)->aux_ref = 1;
	                                                            }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 171 "mccompiler.y" /* yacc.c:1646  */
    {	
																	if ((yyvsp[-1].no) == NULL)
																	{
																		(yyval.no) = createNode(unknown_node, "Null",""); 
																	}
																	else
																	{
																		(yyval.no) = (yyvsp[-1].no);
																	}
																}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 181 "mccompiler.y" /* yacc.c:1646  */
    { 	
																	if (nBrothers((yyvsp[-1].no),0) >= 2)
																	{
																		(yyval.no) = createNode(stat_node, "StatList", "");
																		addChild((yyval.no), (yyvsp[-1].no));
																	}
																	else
																	{
																		(yyval.no) = (yyvsp[-1].no);
																	}
																	
																}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "mccompiler.y" /* yacc.c:1646  */
    {	
																	(yyval.no) = createNode(stat_node,"If",""); addChild((yyval.no),(yyvsp[-2].no)); 
																	
																	
																	if (nBrothers((yyvsp[0].no),0) >= 2)
																	{
																		aux = createNode(stat_node, "StatList", "");
																		addChild(aux, (yyvsp[0].no));
																		assign_node((yyvsp[0].no));
																		addBrother((yyvsp[-2].no), aux);
																		
																	}
																	else
																	{
                                                                      	if((yyvsp[0].no) == NULL)
                                                                      	{

                                                                            addBrother((yyvsp[-2].no),createNode(unknown_node,"Null",""));
                                                                            addBrother((yyvsp[-2].no),createNode(unknown_node,"Null",""));
                                                                            
                                                                      	}
                                                                      	else if(nBrothers((yyvsp[0].no),1) == 1)
                                                                      	{
                                                                            addBrother((yyvsp[-2].no),(yyvsp[0].no));
                                                                            addBrother((yyvsp[-2].no),createNode(unknown_node,"Null",""));

                                                                   
                                                                      	}
                                                                      	else if(nBrothers((yyvsp[0].no),1) == 2)
                                                                      	{
                                                                            addBrother((yyvsp[-2].no),(yyvsp[0].no));
                                                                    		assign_node((yyvsp[0].no));
                                                                    		
                                                                      	}
                                                                	}
                                                              	}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 230 "mccompiler.y" /* yacc.c:1646  */
    { 	(yyval.no) = createNode(stat_node,"If",""); addChild((yyval.no),(yyvsp[-4].no));
                                                                	if(nBrothers((yyvsp[-2].no),0)>=2)
                                                                	{
                                                                      	aux= createNode(stat_node,"StatList","");
                                                                      	addChild(aux,(yyvsp[-2].no));
                                                                      	assign_node((yyvsp[-2].no));
                                                                      	addBrother((yyvsp[-4].no),aux);
                                                                    }
                                                                    else
                                                                    {
                                                                      	if((yyvsp[-2].no) == NULL)
                                                                      	{

                                                                            addBrother((yyvsp[-4].no),createNode(unknown_node,"Null",""));
                                                                      	}
                                                              			else if(nBrothers((yyvsp[-2].no),1) == 1)
                                                              			{
                                                                            addBrother((yyvsp[-4].no),(yyvsp[-2].no));
                                                                      	}
                                                                      	else if(nBrothers((yyvsp[-2].no),1) == 2)
                                                                      	{
                                                    						addBrother((yyvsp[-4].no),(yyvsp[-2].no));
                                                                      	}
                                                                    }
                                                                    if(nBrothers((yyvsp[0].no),0)>=2)
                                                                    {
                                                                      	aux = createNode(stat_node,"StatList","");
                                                                      	addChild(aux,(yyvsp[0].no));
                                                                      	assign_node((yyvsp[0].no));
                                                                        addBrother((yyvsp[-4].no),aux);
                                                                    }
                                                                	else
                                                                	{
                                                                      	if((yyvsp[0].no) == NULL)
                                                                      	{
                                                                            addBrother((yyvsp[-4].no),createNode(unknown_node,"Null",""));
                                                                      	}
                                                                      	if(nBrothers((yyvsp[0].no),0) == 1)
                                                                      	{
                                                                            addBrother((yyvsp[-4].no),(yyvsp[0].no));
                                                                      	}
                                                                      	else if(nBrothers((yyvsp[-4].no),1) == 2)
                                                                      	{
                                                                        	addBrother((yyvsp[-4].no),createNode(unknown_node,"Null",""));
                                                                      	}
                                                                    }
                                                              	}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 277 "mccompiler.y" /* yacc.c:1646  */
    { 	(yyval.no) = createNode(stat_node,"For","");
                                                                            	if((yyvsp[-6].no) == NULL)
                                                                            	{
                                                                                    addChild((yyval.no),createNode(unknown_node,"Null",""));
                                                                                }
                                                                            	else
                                                                            	{
                                                                                    addChild((yyval.no),(yyvsp[-6].no));
                                                                                }
                                                                            	if((yyvsp[-4].no) == NULL)
                                                                            	{
																					addBrother((yyval.no)->son,createNode(unknown_node,"Null",""));
																				}
                                                                                else
                                                                                {
                                                                                	addBrother((yyval.no)->son,(yyvsp[-4].no));
                                                                                } 
                                                                                if((yyvsp[-2].no) == NULL)
                                                                                {
                                                                                	addBrother((yyval.no)->son,createNode(unknown_node,"Null",""));
                                                                                } 
                                                                                else 
                                                                                {
                                                                                	addBrother((yyval.no)->son,(yyvsp[-2].no));
                                                                            	}
                                                                                if(nBrothers((yyvsp[0].no),0)>=2)
                                                                                {
                                                                                  	aux = createNode(stat_node,"StatList","");
                                                                                   	addChild(aux,(yyvsp[0].no));
                                                                                   	assign_node((yyvsp[0].no));
                                                                                    addBrother((yyval.no)->son,aux);
                                                                                }
                                                                                else if ((yyvsp[0].no) == NULL)
                                                                                {
                                                                                	addBrother((yyval.no)->son, createNode(unknown_node, "Null",""));
                                                                                }
                                                                                else
                                                                                {
                                                                                  	addBrother((yyval.no)->son,(yyvsp[0].no));
                                                                                } 
                                                                            }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 318 "mccompiler.y" /* yacc.c:1646  */
    { (yyval.no) = createNode(stat_node,"Return",""); if((yyvsp[-1].no) == NULL) addChild((yyval.no),createNode(unknown_node,"Null","")); else addChild((yyval.no),(yyvsp[-1].no)); }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 322 "mccompiler.y" /* yacc.c:1646  */
    {	
																	if ((yyvsp[-1].no) == NULL)
																	{
																		(yyval.no) = createNode(unknown_node, "Null",""); 
																	}
																	else
																	{
																		(yyval.no) = (yyvsp[-1].no);
																	}
																}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 332 "mccompiler.y" /* yacc.c:1646  */
    { 	if (nBrothers((yyvsp[-1].no),0) >= 2)
																	{
																		(yyval.no) = createNode(stat_node, "StatList", "");
																		addChild((yyval.no), (yyvsp[-1].no));
																	}
																	else
																	{
																		(yyval.no) = (yyvsp[-1].no);
																	}
																	
																}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 343 "mccompiler.y" /* yacc.c:1646  */
    { 	(yyval.no) = createNode(stat_node,"If",""); addChild((yyval.no),(yyvsp[-2].no));
                                                                    if(nBrothers((yyvsp[0].no),0)>=2)
                                                                    {
                                                                      	aux = createNode(stat_node,"StatList","");
                                                                      	addChild(aux,(yyvsp[0].no));
                                                                      	assign_node((yyvsp[0].no));
                                                                      	addBrother((yyvsp[-2].no),aux);
                                                                      	

                                                                    }
                                                                    else
                                                                    {
                                                                      	if((yyvsp[0].no) == NULL)
                                                                      	{
                                                                    		addBrother((yyvsp[-2].no),createNode(unknown_node,"Null",""));
                                                                    		addBrother((yyvsp[-2].no),createNode(unknown_node,"Null",""));
                                                                    		
                                                                  		}
                                                                      	else if(nBrothers((yyvsp[0].no),1) == 1)
                                                                      	{
                                                                            addBrother((yyvsp[-2].no),(yyvsp[0].no));
                                                                            addBrother((yyvsp[-2].no),createNode(unknown_node,"Null",""));
                                                                            
                                                                      	}
                                                                      	else if(nBrothers((yyvsp[0].no),1) == 2)
                                                                      	{
                                                                            addChild((yyvsp[-2].no),(yyvsp[0].no));
                                                                            assign_node((yyvsp[0].no));
                                                                            
                                                                      	}
                                                                    }
                                                          		}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 375 "mccompiler.y" /* yacc.c:1646  */
    {	(yyval.no) = createNode(stat_node,"If",""); addChild((yyval.no),(yyvsp[-4].no));
                                                                	if(nBrothers((yyvsp[-2].no),0)>=2)
                                                                	{
                                                                      	aux = createNode(stat_node,"StatList","");
                                                                      	addChild(aux,(yyvsp[-2].no));
                                                                     	assign_node((yyvsp[-2].no));
                                                                      	addBrother((yyvsp[-4].no),aux);
                                                                    }
                                                                	else
                                                                	{
                                                                      	if((yyvsp[-2].no) == NULL)
                                                                      	{
                                                                            addBrother((yyvsp[-4].no),createNode(unknown_node,"Null",""));
                                                                        }
                                                                     	else if(nBrothers((yyvsp[-2].no),1) == 1)
                                                                     	{
                                                                            addBrother((yyvsp[-4].no),(yyvsp[-2].no));
                                                                      	}
                                                                      	else if(nBrothers((yyvsp[-2].no),1) == 2)
                                                                      	{
                                                                            addBrother((yyvsp[-4].no),(yyvsp[-2].no));
                                                                      	}
                                                                    }
                                                                    if(nBrothers((yyvsp[0].no),0)>=2)
                                                                    {
                                                                 	 	aux = createNode(stat_node,"StatList","");
                                                                  		addChild(aux,(yyvsp[0].no));
                                                                  		assign_node((yyvsp[0].no));
                                                                      	addBrother((yyvsp[-4].no),aux);
                                                                	}
                                                                    else
                                                                    {
                                                                      	if((yyvsp[0].no) == NULL)
                                                                      	{
                                                                        	addBrother((yyvsp[-4].no),createNode(unknown_node,"Null",""));
                                                                      	}
                                                              			if(nBrothers((yyvsp[0].no),0) == 1)
                                                              			{
                                                                            addBrother((yyvsp[-4].no),(yyvsp[0].no));
                                                                      	}
                                                                      	else if(nBrothers((yyvsp[-4].no),1) == 2)
                                                                      	{
                                                                        	addBrother((yyvsp[-4].no),createNode(unknown_node,"Null",""));
                                                                      	}
                                                                    }
                                                              	}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 421 "mccompiler.y" /* yacc.c:1646  */
    { 	(yyval.no) = createNode(stat_node,"For","");
                                                                            	if((yyvsp[-6].no) == NULL)
                                                                            	{
                                                                                  	addChild((yyval.no),createNode(unknown_node,"Null",""));
                                                                                }
                                                                                else
                                                                                {
                                                                                  	addChild((yyval.no),(yyvsp[-6].no));
                                                                                }
                                                                                if((yyvsp[-4].no) == NULL)
                                                                            	{
                                                                            		addBrother((yyval.no)->son,createNode(unknown_node,"Null",""));
                                                                             	}
                                                                                else
                                                                                {
                                                                                	addBrother((yyval.no)->son,(yyvsp[-4].no));	
                                                                                } 
                                                                            	if((yyvsp[-2].no) == NULL)
                                                                        		{
                                                                        			addBrother((yyval.no)->son,createNode(unknown_node,"Null",""));
                                                                        		}
                                                                                else 
                                                                            	{
                                                                            		addBrother((yyval.no)->son,(yyvsp[-2].no));
                                                                            	}
                                                                                if(nBrothers((yyvsp[0].no),0)>=2)
                                                                                {
                                                                                  	aux = createNode(stat_node,"StatList","");
                                                                                  	addChild(aux,(yyvsp[0].no));
                                                                                  	assign_node((yyvsp[0].no));
                                                                                  	addBrother((yyval.no)->son,aux);
                                                                            	}
                                                                                else if((yyvsp[0].no) == NULL)
                                                                                {
                                                                                  	addBrother((yyval.no)->son,createNode(unknown_node,"Null",""));
                                                                                }
                                                                                else
                                                                                {
                                                                                	addBrother((yyval.no)->son,(yyvsp[0].no));
                                                                        		}
                                                                          	}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 462 "mccompiler.y" /* yacc.c:1646  */
    { 	(yyval.no) = createNode(stat_node,"Return",""); 
																	if((yyvsp[-1].no) == NULL)
																	{
																		addChild((yyval.no),createNode(unknown_node,"Null",""));
																	}
																	else
																	{
																		addChild((yyval.no),(yyvsp[-1].no)); 
																	} 
																}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 472 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL; flag_error = 1;}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 473 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL; flag_error = 1;}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 478 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 479 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 482 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Comma",""); (yyval.no)->aux_ref = 3; addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 483 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) =(yyvsp[0].no);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 486 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Store",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 487 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"And",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no)); }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 488 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Or",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 489 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Eq",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 490 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Ne",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 491 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Lt",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 492 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Gt",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 493 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Le",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 494 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Ge",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 495 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Add",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 496 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Sub",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 497 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Mul",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 498 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Div",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 499 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Mod",""); addChild((yyval.no),(yyvsp[-2].no)); addBrother((yyvsp[-2].no),(yyvsp[0].no));}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 500 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Addr", ""); addChild((yyval.no),(yyvsp[0].no));}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 501 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node, "Deref", ""); addChild((yyval.no), (yyvsp[0].no));}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 502 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node, "Plus", ""); addChild((yyval.no), (yyvsp[0].no));}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 503 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node, "Minus", ""); addChild((yyval.no), (yyvsp[0].no));}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 504 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node, "Not", ""); addChild((yyval.no), (yyvsp[0].no));}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 505 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Deref",""); addChild((yyval.no),createNode(op_node,"Add","")); addChild((yyval.no)->son,(yyvsp[-3].no)); addBrother((yyvsp[-3].no),(yyvsp[-1].no));}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 506 "mccompiler.y" /* yacc.c:1646  */
    { 	(yyval.no) = createNode(op_node,"Call",""); addChild((yyval.no),createNode(id_node,"Id",(yyvsp[-3].var)));
                                                                    if((yyvsp[-1].no)->aux_ref == 3)
                                                                    {
                                                                  		addBrother((yyval.no)->son,deleteComma((yyvsp[-1].no)));
                                                                    }
                                                                    else
                                                                    {
                                                                      	addBrother((yyval.no)->son,(yyvsp[-1].no));
                                                                    }
                                                              	}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 516 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(op_node,"Call",""); (yyval.no)->aux_ref=3; addChild((yyval.no),createNode(id_node,"Id",(yyvsp[-2].var)));}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 517 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(id_node,"Id",(yyvsp[0].var));}
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 518 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(id_node,"IntLit",(yyvsp[0].var));}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 519 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(id_node,"ChrLit",(yyvsp[0].var));}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 520 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(id_node,"StrLit",(yyvsp[0].var));}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 521 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no); (yyval.no)->aux_ref = 0;}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 522 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(unknown_node,"Null",""); flag_error = 1;}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 523 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.no) = createNode(unknown_node,"Null",""); flag_error = 1;}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2309 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 527 "mccompiler.y" /* yacc.c:1906  */

void yyerror(char *s){
  printf("Line %d, col %lu: %s: %s\n", linha, (unsigned long)(coluna-strlen(yytext)), s, yytext);
}

int main(int argc, char *argv[]){
	 if(argv[1]!=NULL){
        if(strcmp(argv[1],"-t")==0){
        	lex=0;
        	flag_l=0;
            print_t = 1;
        }
        else if(strcmp(argv[1],"-1")==0){

        	lex=1;
        	flag_l=0;
        	yylex();
        }
        else if(strcmp(argv[1],"-l")==0){

        	lex=1;
        	flag_l=1;
        	yylex();
        }
    }
  	if(!lex){
    	yyparse();
    	if(print_t && !flag_error)
      		print_tree(root,0);
  	}

    return 0;
}
 					
