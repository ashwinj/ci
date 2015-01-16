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
#line 1 "ci.y" /* yacc.c:339  */

#include <stdio.h>
#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "ast_builder.h"
#include "symbol_table.h"
#include "vm.h"

//#define YYDEBUG 1

#line 77 "y.tab.c" /* yacc.c:339  */

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
    MAIN_DEFINITION = 258,
    LIB_PRINTF = 259,
    LIB_SCANF = 260,
    CHAR_CONSTANT = 261,
    HEX_INT_CONSTANT = 262,
    OCT_INT_CONSTANT = 263,
    DEC_INT_CONSTANT = 264,
    HEX_LONG_CONSTANT = 265,
    OCT_LONG_CONSTANT = 266,
    DEC_LONG_CONSTANT = 267,
    FLOAT_CONSTANT = 268,
    DOUBLE_CONSTANT = 269,
    IDENTIFIER = 270,
    STRING_LITERAL = 271,
    INC_OP = 272,
    DEC_OP = 273,
    LEFT_SHIFT_OP = 274,
    RIGHT_SHIFT_OP = 275,
    LE_OP = 276,
    GE_OP = 277,
    EQ_OP = 278,
    NE_OP = 279,
    AND_OP = 280,
    OR_OP = 281,
    MUL_ASSIGN = 282,
    DIV_ASSIGN = 283,
    MOD_ASSIGN = 284,
    ADD_ASSIGN = 285,
    SUB_ASSIGN = 286,
    LEFT_ASSIGN = 287,
    RIGHT_ASSIGN = 288,
    AND_ASSIGN = 289,
    XOR_ASSIGN = 290,
    OR_ASSIGN = 291,
    CHAR_TYPE = 292,
    SHORT_TYPE = 293,
    INT_TYPE = 294,
    LONG_TYPE = 295,
    FLOAT_TYPE = 296,
    DOUBLE_TYPE = 297,
    VOID_TYPE = 298,
    IF = 299,
    ELSE = 300,
    WHILE = 301,
    FOR = 302,
    CONTINUE = 303,
    BREAK = 304,
    RETURN = 305,
    LOWER_THAN_ELSE = 306
  };
#endif
/* Tokens.  */
#define MAIN_DEFINITION 258
#define LIB_PRINTF 259
#define LIB_SCANF 260
#define CHAR_CONSTANT 261
#define HEX_INT_CONSTANT 262
#define OCT_INT_CONSTANT 263
#define DEC_INT_CONSTANT 264
#define HEX_LONG_CONSTANT 265
#define OCT_LONG_CONSTANT 266
#define DEC_LONG_CONSTANT 267
#define FLOAT_CONSTANT 268
#define DOUBLE_CONSTANT 269
#define IDENTIFIER 270
#define STRING_LITERAL 271
#define INC_OP 272
#define DEC_OP 273
#define LEFT_SHIFT_OP 274
#define RIGHT_SHIFT_OP 275
#define LE_OP 276
#define GE_OP 277
#define EQ_OP 278
#define NE_OP 279
#define AND_OP 280
#define OR_OP 281
#define MUL_ASSIGN 282
#define DIV_ASSIGN 283
#define MOD_ASSIGN 284
#define ADD_ASSIGN 285
#define SUB_ASSIGN 286
#define LEFT_ASSIGN 287
#define RIGHT_ASSIGN 288
#define AND_ASSIGN 289
#define XOR_ASSIGN 290
#define OR_ASSIGN 291
#define CHAR_TYPE 292
#define SHORT_TYPE 293
#define INT_TYPE 294
#define LONG_TYPE 295
#define FLOAT_TYPE 296
#define DOUBLE_TYPE 297
#define VOID_TYPE 298
#define IF 299
#define ELSE 300
#define WHILE 301
#define FOR 302
#define CONTINUE 303
#define BREAK 304
#define RETURN 305
#define LOWER_THAN_ELSE 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 12 "ci.y" /* yacc.c:355  */

	ast node;
	char unary_code;
	char* string;
	assignment_code assign_code;

#line 226 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 241 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   670

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    62,    57,     2,
      53,    54,    52,    63,    71,    58,     2,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    74,
      64,    70,    65,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    67,    73,    59,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    84,    85,    86,    87,    91,
      92,    93,    94,    95,    96,    97,   101,   102,   103,   104,
     108,   109,   110,   111,   112,   116,   117,   121,   122,   123,
     124,   128,   129,   130,   134,   135,   136,   140,   141,   142,
     143,   144,   148,   149,   150,   154,   155,   159,   160,   164,
     165,   169,   170,   174,   175,   179,   180,   184,   185,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     203,   204,   208,   212,   213,   217,   218,   222,   223,   227,
     228,   232,   233,   237,   241,   242,   246,   247,   248,   249,
     250,   254,   255,   259,   260,   264,   265,   269,   270,   271,
     275,   276,   277,   278,   282,   283,   284,   285,   289,   290,
     291,   295,   299,   303,   307,   311,   315,   316,   317,   321,
     322,   326,   330,   334,   335,   339,   340
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN_DEFINITION", "LIB_PRINTF",
  "LIB_SCANF", "CHAR_CONSTANT", "HEX_INT_CONSTANT", "OCT_INT_CONSTANT",
  "DEC_INT_CONSTANT", "HEX_LONG_CONSTANT", "OCT_LONG_CONSTANT",
  "DEC_LONG_CONSTANT", "FLOAT_CONSTANT", "DOUBLE_CONSTANT", "IDENTIFIER",
  "STRING_LITERAL", "INC_OP", "DEC_OP", "LEFT_SHIFT_OP", "RIGHT_SHIFT_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "CHAR_TYPE",
  "SHORT_TYPE", "INT_TYPE", "LONG_TYPE", "FLOAT_TYPE", "DOUBLE_TYPE",
  "VOID_TYPE", "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN",
  "LOWER_THAN_ELSE", "'*'", "'('", "')'", "'['", "']'", "'&'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'+'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "','", "'{'", "'}'", "';'", "$accept", "constant", "type",
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "initializer", "initializer_list", "declarator",
  "variable_declarator", "variable_declarator_list",
  "variable_declaration", "variable_declaration_list", "statement",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "compound_statement",
  "parameter_list", "parameter", "function_definition", "function_call",
  "printf_call", "scanf_call", "argument_expression_list",
  "global_declaration", "main_prototype", "main_definition",
  "translation_unit", "script", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    42,    40,    41,    91,    93,    38,    45,   126,
      33,    47,    37,    43,    60,    62,    94,   124,    63,    58,
      61,    44,   123,   125,    59
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  -114,   -40,   -36,   -26,   -15,    -1,    22,    53,   125,
    -114,  -114,  -114,   -52,  -114,     4,   145,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,    -3,    77,  -114,    11,   161,  -114,
    -114,  -114,  -114,    95,   595,   499,   139,  -114,   104,   111,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    51,
    -114,   610,   610,   128,   129,   130,   106,   110,   410,  -114,
     523,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   139,  -114,
      76,     0,   595,  -114,   -37,    20,   108,   -11,   127,   131,
     121,   122,   165,   -12,  -114,  -114,    13,  -114,   232,  -114,
     250,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   176,
     -32,  -114,  -114,  -114,   136,   499,  -114,  -114,   138,  -114,
     595,   595,   595,   595,   595,  -114,  -114,   595,   595,   428,
    -114,  -114,  -114,    21,   141,    -6,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   595,
    -114,   595,   595,   595,   595,   595,   595,   595,   595,   595,
     595,   595,   595,   595,   595,   595,   595,   595,   595,   595,
     595,  -114,  -114,  -114,   321,  -114,  -114,  -114,   -52,    95,
    -114,  -114,     2,  -114,    -5,     1,     5,    15,     6,     9,
     428,  -114,   595,  -114,  -114,  -114,  -114,  -114,   -37,   -37,
      20,    20,   108,   108,   108,   108,   -11,   -11,   127,   131,
     121,   122,   165,    72,  -114,  -114,  -114,  -114,   499,  -114,
    -114,   595,  -114,  -114,  -114,   339,   339,   580,  -114,   595,
    -114,  -114,   151,  -114,   339,    10,  -114,   339,  -114,   339,
    -114,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   141,    12,    13,    14,    17,    15,    16,    11,     0,
     140,   139,   143,     0,   145,     0,     0,    19,    20,    21,
      24,    22,    23,    18,    97,    99,   101,     0,     0,   142,
     144,   146,     1,   128,     0,     0,     0,   103,     0,     0,
       2,     3,     4,     5,     8,     9,    10,     6,     7,    25,
      27,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,    40,    42,    43,    44,   124,   113,    26,     0,    29,
      36,    45,     0,    47,    51,    54,    57,    62,    65,    67,
      69,    71,    73,    75,    77,    90,     0,   104,     0,   111,
       0,   107,   108,   109,   110,   106,    31,    32,    33,     0,
       0,   129,    45,    92,     0,     0,    93,   100,    97,   102,
     136,   136,   136,     0,     0,    37,    38,     0,     0,     0,
     123,   122,   120,     0,     0,     0,    34,    35,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    79,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   126,   105,     0,   125,   112,   131,     0,     0,
      98,    95,     0,   137,     0,     0,     0,     0,     0,     0,
       0,   121,     0,    28,    78,    48,    49,    50,    53,    52,
      55,    56,    60,    61,    58,    59,    63,    64,    66,    68,
      70,    72,    74,     0,    91,   127,   132,   130,     0,    94,
     134,     0,   135,   133,    30,     0,     0,     0,    46,     0,
      96,   138,   115,   117,     0,     0,    76,     0,   118,     0,
     116,   119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,   -20,  -114,  -114,   -34,  -114,   -53,     8,    16,
     -49,     3,    52,    57,    59,    60,    58,  -114,   -33,   -14,
    -114,   -56,  -114,   -82,  -114,  -114,   186,  -114,   -19,  -114,
     -85,   135,  -113,  -114,  -114,  -114,   -10,  -114,    55,  -114,
    -114,  -114,  -114,    48,   210,  -114,   211,  -114,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    67,     9,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     139,    86,   104,   107,   172,    25,    26,    27,    10,    88,
      89,    90,    91,    92,    93,    94,    95,   100,   101,    11,
      96,    97,    98,   174,    12,    13,    14,    15,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     102,   103,   123,    29,   125,   166,   180,     1,    68,    87,
     148,   149,    17,    99,   158,   141,    18,   115,   116,   140,
      28,   106,   168,   171,   142,   143,    19,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    20,   102,   169,
     124,     2,     3,     4,     5,     6,     7,     8,   183,   210,
      33,    21,    34,   150,   151,   212,   159,   177,   125,   213,
     215,   178,   179,   216,   229,   160,   211,   217,    68,   163,
     138,   214,   211,   208,    22,   209,   211,   160,   144,   166,
     160,   160,    36,   145,   160,    37,   160,   161,   185,   186,
     187,   106,   160,   126,   127,   181,   173,   173,   173,   192,
     193,   194,   195,   203,   112,    23,   113,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   184,   220,   146,   147,   218,
     222,   223,     2,     3,     4,     5,     6,     7,     8,   228,
      24,   219,   230,   160,   231,    32,   204,    35,   102,    99,
     152,   153,   188,   189,   108,   196,   197,   110,   206,   175,
     176,   225,   190,   191,   111,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     120,   117,   118,   119,   121,   102,   226,   155,   154,   156,
     157,   167,   170,    34,   106,   182,   227,   221,     2,     3,
       4,     5,     6,     7,     8,    53,   198,    54,    55,    56,
      57,    58,   199,    59,    60,   200,   202,   201,    61,    62,
      63,    64,   109,   164,   207,    30,    31,     0,     0,     0,
       0,     0,     0,    28,    65,    66,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     2,
       3,     4,     5,     6,     7,     8,    53,     0,    54,    55,
      56,    57,    58,     0,    59,    60,     0,     0,     0,    61,
      62,    63,    64,     0,    53,     0,    54,    55,    56,    57,
      58,     0,    59,    60,    28,   162,    66,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,   165,    66,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,    53,     0,    54,    55,    56,
      57,    58,     0,    59,    60,     0,     0,     0,    61,    62,
      63,    64,     0,    53,     0,    54,    55,    56,    57,    58,
       0,    59,    60,    28,   205,    66,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,    66,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,     0,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    59,    60,     0,     0,     0,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    60,     0,     0,   122,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,     0,    61,    62,    63,    64,
       2,     3,     4,     5,     6,     7,     8,     0,     0,     0,
       0,   105,     0,     0,     0,    59,    60,     0,     0,     0,
      61,    62,    63,    64,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,     0,    59,    60,   224,     0,     0,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    59,    60,     0,
       0,     0,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,    59,   114,     0,     0,     0,    61,    62,    63,
      64
};

static const yytype_int16 yycheck[] =
{
      34,    34,    58,    13,    60,    90,   119,     3,    28,    28,
      21,    22,    52,    33,    26,    52,    52,    51,    52,    72,
      72,    35,    54,   105,    61,    62,    52,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    52,    72,    71,
      60,    37,    38,    39,    40,    41,    42,    43,    54,    54,
      53,    52,    55,    64,    65,    54,    68,   113,   114,    54,
      54,   117,   118,    54,    54,    71,    71,   180,    88,    88,
      70,    56,    71,    71,    52,    73,    71,    71,    58,   164,
      71,    71,    71,    63,    71,    74,    71,    74,   141,   142,
     143,   105,    71,    17,    18,    74,   110,   111,   112,   148,
     149,   150,   151,   159,    53,    52,    55,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   139,   208,    19,    20,   182,
     215,   216,    37,    38,    39,    40,    41,    42,    43,   224,
      15,    69,   227,    71,   229,     0,   160,    70,   182,   169,
      23,    24,   144,   145,    15,   152,   153,    53,   168,   111,
     112,   217,   146,   147,    53,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      74,    53,    53,    53,    74,   219,   219,    66,    57,    67,
      25,    15,    56,    55,   208,    54,    45,   211,    37,    38,
      39,    40,    41,    42,    43,    44,   154,    46,    47,    48,
      49,    50,   155,    52,    53,   156,   158,   157,    57,    58,
      59,    60,    36,    88,   169,    15,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    49,    50,    -1,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    44,    -1,    46,    47,    48,    49,
      50,    -1,    52,    53,    72,    73,    74,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    -1,    44,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    72,    73,    74,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    74,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    74,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    57,    58,    59,    60,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    60,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    37,    38,    39,    40,    41,    42,    43,    77,
     103,   114,   119,   120,   121,   122,   123,    52,    52,    52,
      52,    52,    52,    52,    15,   100,   101,   102,    72,   111,
     119,   121,     0,    53,    55,    70,    71,    74,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    44,    46,    47,    48,    49,    50,    52,
      53,    57,    58,    59,    60,    73,    74,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    96,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   115,   116,   117,    77,
     112,   113,    80,    93,    97,    72,    94,    98,    15,   101,
      53,    53,    53,    55,    53,    80,    80,    53,    53,    53,
      74,    74,    74,    96,    77,    96,    17,    18,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    70,    95,
      82,    52,    61,    62,    58,    63,    19,    20,    21,    22,
      64,    65,    23,    24,    57,    66,    67,    25,    26,    68,
      71,    74,    73,   103,   106,    73,   105,    15,    54,    71,
      56,    98,    99,    94,   118,   118,   118,    96,    96,    96,
     107,    74,    54,    54,    94,    82,    82,    82,    83,    83,
      84,    84,    85,    85,    85,    85,    86,    86,    87,    88,
      89,    90,    91,    96,    94,    73,   111,   113,    71,    73,
      54,    71,    54,    54,    56,    54,    54,   107,    82,    69,
      98,    94,   105,   105,    54,    96,    93,    45,   105,    54,
     105,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    83,
      83,    84,    84,    84,    85,    85,    85,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   109,
     110,   110,   110,   110,   111,   111,   111,   111,   112,   112,
     112,   113,   114,   115,   116,   117,   118,   118,   118,   119,
     119,   120,   121,   122,   122,   123,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     3,     1,
       4,     1,     1,     1,     2,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     1,     3,     1,     4,     1,
       3,     1,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     5,     7,     5,     6,     7,
       2,     3,     2,     2,     2,     3,     3,     4,     0,     1,
       3,     2,     6,     4,     4,     4,     0,     1,     3,     1,
       1,     1,     2,     1,     2,     1,     2
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
#line 55 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), CHAR); }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), INT); }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), INT); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), INT); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), FLOAT); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), DOUBLE); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), LONG); }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), LONG); }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 63 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), LONG); }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("void", VOID); }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("char", CHAR); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 69 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("short", SHORT); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 70 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("int", INT); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 71 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("float", FLOAT); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 72 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("double", DOUBLE); }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 73 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("long", LONG); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 74 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("void pointer", VOID_PTR); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 75 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("char pointer", CHAR_PTR); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 76 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("short pointer", SHORT_PTR); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 77 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("int pointer", INT_PTR); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 78 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("float pointer", FLOAT_PTR); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 79 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("double pointer", DOUBLE_PTR); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 80 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_type_node("long pointer", LONG_PTR); }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 84 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_variable_node((yyvsp[0].string), UNDEFINED); }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 85 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 86 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_constant_node((yyvsp[0].string), CHAR_PTR); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 87 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 91 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 92 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_array_variable_node((yyvsp[-3].string), (yyvsp[-1].node), UNDEFINED); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 93 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 94 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 95 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 96 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_inc_exp_node(POST_INCREMENT, (yyvsp[-1].node)); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 97 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_dec_exp_node(POST_DECREMENT, (yyvsp[-1].node)); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 101 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 102 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_inc_exp_node(PRE_INCREMENT, (yyvsp[0].node)); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 103 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_dec_exp_node(PRE_DECREMENT, (yyvsp[0].node)); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 104 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_unary_exp_node((yyvsp[-1].unary_code), (yyvsp[0].node)); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 108 "ci.y" /* yacc.c:1646  */
    { (yyval.unary_code) = '&'; }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 109 "ci.y" /* yacc.c:1646  */
    { (yyval.unary_code) = '*'; }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 110 "ci.y" /* yacc.c:1646  */
    { (yyval.unary_code) = '-'; }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 111 "ci.y" /* yacc.c:1646  */
    { (yyval.unary_code) = '~'; }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 112 "ci.y" /* yacc.c:1646  */
    { (yyval.unary_code) = '!'; }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 116 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 117 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_cast_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 121 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 122 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_mul_exp_node((yyvsp[-2].node), MULTIPLICATION, (yyvsp[0].node)); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 123 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_mul_exp_node((yyvsp[-2].node), DIVISION, (yyvsp[0].node)); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 124 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_mul_exp_node((yyvsp[-2].node), MODULO, (yyvsp[0].node)); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 128 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 129 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_add_exp_node((yyvsp[-2].node), ADDITION, (yyvsp[0].node)); }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 130 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_add_exp_node((yyvsp[-2].node), SUBTRACTION, (yyvsp[0].node)); }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 134 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 135 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_shift_exp_node((yyvsp[-2].node), LEFT_SHIFT, (yyvsp[0].node)); }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 136 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_shift_exp_node((yyvsp[-2].node), RIGHT_SHIFT, (yyvsp[0].node)); }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 140 "ci.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 141 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_rel_exp_node((yyvsp[-2].node), REL_LESS, (yyvsp[0].node)); }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 142 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_rel_exp_node((yyvsp[-2].node), REL_GREATER, (yyvsp[0].node)); }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 143 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_rel_exp_node((yyvsp[-2].node), REL_LESS_EQUAL, (yyvsp[0].node)); }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 144 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_rel_exp_node((yyvsp[-2].node), REL_GREATER_EQUAL, (yyvsp[0].node)); }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 148 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 149 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_rel_exp_node((yyvsp[-2].node), REL_EQUAL, (yyvsp[0].node)); }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 150 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_rel_exp_node((yyvsp[-2].node), REL_NOT_EQUAL, (yyvsp[0].node)); }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 154 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 155 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_bit_exp_node((yyvsp[-2].node), BITWISE_AND, (yyvsp[0].node)); }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 159 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 160 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_bit_exp_node((yyvsp[-2].node), BITWISE_XOR, (yyvsp[0].node)); }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 164 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 165 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_bit_exp_node((yyvsp[-2].node), BITWISE_OR, (yyvsp[0].node)); }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 169 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 170 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_logic_exp_node((yyvsp[-2].node), LOGICAL_AND, (yyvsp[0].node)); }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 174 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 175 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_logic_exp_node((yyvsp[-2].node), LOGICAL_OR, (yyvsp[0].node)); }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 179 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 180 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_cond_exp_node((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 184 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 185 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_assign_exp_node((yyvsp[-2].node), (yyvsp[-1].assign_code), (yyvsp[0].node)); }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 189 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = EQ_ASSIGN_CODE; }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 190 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = MUL_ASSIGN_CODE; }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 191 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = DIV_ASSIGN_CODE; }
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 192 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = MOD_ASSIGN_CODE; }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 193 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = ADD_ASSIGN_CODE; }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 194 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = SUB_ASSIGN_CODE; }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 195 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = LEFT_ASSIGN_CODE; }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 196 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = RIGHT_ASSIGN_CODE; }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 197 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = AND_ASSIGN_CODE; }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 198 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = XOR_ASSIGN_CODE; }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 199 "ci.y" /* yacc.c:1646  */
    { (yyval.assign_code) = OR_ASSIGN_CODE; }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 203 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_exp_list_node((yyvsp[0].node)); }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 204 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = append_exp_list_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 208 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 212 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 213 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 217 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_init_list_node((yyvsp[0].node)); }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 218 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = append_init_list_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 222 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_variable_node((yyvsp[0].string), UNDEFINED); }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 223 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_array_variable_node((yyvsp[-3].string), (yyvsp[-1].node), UNDEFINED); }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 227 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 228 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_assign_exp_node((yyvsp[-2].node), EQ_ASSIGN_CODE, (yyvsp[0].node)); }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 232 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_var_decl_list_node((yyvsp[0].node)); }
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 233 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = append_var_decl_list_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 237 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_decl_node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 241 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_var_type_decl_list_node((yyvsp[0].node)); }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 242 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = append_var_type_decl_list_node((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 246 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 247 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 248 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 249 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 250 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 254 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_stmt_list_node((yyvsp[0].node)); }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 255 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = append_stmt_list_node((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 259 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_exp_stmt_node(NULL); }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 260 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_exp_stmt_node((yyvsp[-1].node)); }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 264 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_if_stmt_node((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 265 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_if_stmt_node((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 269 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_while_stmt_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 270 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_for_stmt_node((yyvsp[-3].node),(yyvsp[-2].node),NULL,(yyvsp[0].node)); }
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 271 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_for_stmt_node((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 275 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_return_stmt_node(NULL); }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 276 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_return_stmt_node((yyvsp[-1].node)); }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 277 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_break_stmt_node(); }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 278 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_continue_stmt_node(); }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 282 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_compound_stmt_node(NULL, NULL); }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 283 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 284 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 285 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_compound_stmt_node((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 289 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 290 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_param_list_node((yyvsp[0].node)); }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 291 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = append_param_list_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 295 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_param_node((yyvsp[-1].node), (yyvsp[0].string)); }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 299 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_func_def_node((yyvsp[-5].node),(yyvsp[-4].string),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 303 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_func_call_node((yyvsp[-3].string),(yyvsp[-1].node)); }
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 307 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_printf_call_node((yyvsp[-1].node)); }
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 311 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_scanf_call_node((yyvsp[-1].node)); }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 315 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 316 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_arg_exp_list_node((yyvsp[0].node)); }
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 317 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = append_arg_exp_list_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 321 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); eval_func_def((yyval.node)); if(_interact) print_prompt(); }
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 322 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); eval_global_var_decl((yyval.node)); if(_interact) print_prompt(); }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 326 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; /*set IN_MAIN flag here*/ }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 330 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_main_def_node((yyvsp[0].node)); eval_main_def((yyval.node)); }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 334 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; /* are these nodes required? */ }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 335 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; /* are these nodes required? */ }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 339 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_func_call_node(MAIN_FUNCTION_LABEL, NULL); set_main_ref((yyval.node)); /* are these nodes required? */ }
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 340 "ci.y" /* yacc.c:1646  */
    { (yyval.node) = new_func_call_node(MAIN_FUNCTION_LABEL, NULL); set_main_ref((yyval.node)); /* are these nodes required? */ }
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2466 "y.tab.c" /* yacc.c:1646  */
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
#line 343 "ci.y" /* yacc.c:1906  */


extern char yytext[];
extern int column;
//int yydebug=1;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
