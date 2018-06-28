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
#line 2 "traductor.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include "symtable.h"

// defino las funciones EXTERN, ya que usamos Bison, esto deveria de hacerse
// de forma automatica, pero param evitar problema al traducir, declaro

extern int yylex(void);													    // devuelve un valor entero que representa un tipo de token
extern FILE *yyin;														    // lugar de donde flex/lexx lee los caracteres
extern char *yytext; 														//reconoce tokens del input y es retornado al parser
extern int yylineno; 														//numero de linea del codigo fuente

FILE *yyoutput; 															//archivo que sera traducido
symrec *sym_table = (symrec * )0;
symrec *s;
symrec *symtable_set_type;

int tam_vector = 0;          												 // ignorar tamano del vector
int cant_corchetes = 0;       												 // cuando el vector es multidimensional imprimir una sola vez '=array()'
int imprimir_corchete = 0;   												 // cuando se reconoce ']' imprimir el ')' despues de cargar los valores al vector
int comprueba_funcion = 0;    												 // 1 cuando se define una funcion e imprimir 'function'
int sin_error = 1;               												 // si existe un error, se convierte en 0
int variable_global = 0;     												 // define si una variable es global


#line 93 "traductor.tab.c" /* yacc.c:339  */

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
   by #include "traductor.tab.h".  */
#ifndef YY_YY_TRADUCTOR_TAB_H_INCLUDED
# define YY_YY_TRADUCTOR_TAB_H_INCLUDED
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
    PTR_OP = 258,
    INC_OP = 259,
    DEC_OP = 260,
    LEFT_OP = 261,
    RIGHT_OP = 262,
    LE_OP = 263,
    GE_OP = 264,
    EQ_OP = 265,
    NE_OP = 266,
    AND_OP = 267,
    OR_OP = 268,
    MUL_ASSIGN = 269,
    DIV_ASSIGN = 270,
    MOD_ASSIGN = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    LEFT_ASSIGN = 274,
    RIGHT_ASSIGN = 275,
    AND_ASSIGN = 276,
    XOR_ASSIGN = 277,
    OR_ASSIGN = 278,
    TYPE_NAME = 279,
    CASE = 280,
    DEFAULT = 281,
    IF = 282,
    ELSE = 283,
    SWITCH = 284,
    WHILE = 285,
    DO = 286,
    FOR = 287,
    CONTINUE = 288,
    BREAK = 289,
    RETURN = 290,
    IDENTIFIER = 291,
    CONSTANT = 292,
    CHAR = 293,
    INT = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOID = 298,
    IFX = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "traductor.y" /* yacc.c:355  */

int tipo;
double val;
char *nombre;
struct symrec *tptr;


#line 186 "traductor.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRADUCTOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "traductor.tab.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    57,    50,     2,
      45,    46,    51,    52,    49,    53,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    65,
      58,    64,    59,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    61,    67,    54,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    72,    74,    74,    78,    79,    79,    80,
      80,    81,    81,    82,    83,    87,    88,    88,    92,    94,
      94,    95,    95,    96,   100,   101,   102,   103,   104,   105,
     108,   113,   114,   114,   115,   115,   116,   116,   120,   121,
     121,   122,   122,   127,   128,   128,   129,   129,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   143,   144,   144,
     145,   145,   150,   151,   151,   156,   157,   157,   162,   163,
     163,   168,   169,   169,   174,   175,   175,   180,   181,   181,
     181,   185,   186,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   202,   203,   203,   207,   211,   231,
     236,   237,   238,   242,   243,   243,   246,   260,   272,   259,
     275,   276,   277,   278,   279,   283,   287,   288,   288,   290,
     290,   292,   292,   293,   293,   297,   301,   302,   302,   306,
     319,   323,   324,   324,   328,   329,   329,   333,   337,   338,
     339,   340,   341,   342,   346,   346,   346,   347,   347,   347,
     351,   351,   352,   352,   354,   354,   359,   360,   364,   365,
     366,   370,   371,   375,   375,   376,   380,   380,   380,   380,
     381,   381,   381,   381,   385,   385,   385,   385,   386,   386,
     386,   386,   386,   387,   387,   387,   387,   391,   391,   392,
     392,   393,   393,   394,   394,   401,   402,   406,   419,   420,
     424,   425
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "CONTINUE", "BREAK", "RETURN", "IDENTIFIER", "CONSTANT", "CHAR",
  "INT", "FLOAT", "DOUBLE", "CONST", "VOID", "IFX", "'('", "')'", "'['",
  "']'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "$@1", "postfix_expression", "$@2",
  "$@3", "$@4", "argument_expression_list", "$@5", "unary_expression",
  "$@6", "$@7", "unary_operator", "cast_expression",
  "multiplicative_expression", "$@8", "$@9", "$@10", "additive_expression",
  "$@11", "$@12", "shift_expression", "$@13", "$@14",
  "relational_expression", "$@15", "$@16", "$@17", "$@18",
  "equality_expression", "$@19", "$@20", "and_expression", "$@21",
  "exclusive_or_expression", "$@22", "inclusive_or_expression", "$@23",
  "logical_and_expression", "$@24", "logical_or_expression", "$@25",
  "conditional_expression", "$@26", "$@27", "assignment_expression",
  "assignment_operator", "expression", "$@28", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list", "$@29",
  "init_declarator", "$@30", "$@31", "type_specifier", "declarator",
  "direct_declarator", "$@32", "$@33", "$@34", "$@35",
  "parameter_type_list", "parameter_list", "$@36", "parameter_declaration",
  "initializer_list", "$@37", "initializer", "$@38", "type_qualifier",
  "statement", "labeled_statement", "$@39", "$@40", "$@41", "$@42",
  "compound_statement", "$@43", "$@44", "$@45", "declaration_list",
  "statement_list", "expression_statement", "else_statement", "$@46",
  "selection_statement", "$@47", "$@48", "$@49", "$@50", "$@51", "$@52",
  "iteration_statement", "$@53", "$@54", "$@55", "$@56", "$@57", "$@58",
  "$@59", "$@60", "$@61", "$@62", "jump_statement", "$@63", "$@64", "$@65",
  "$@66", "external_declaration", "function_definition",
  "translation_unit", YY_NULLPTR
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
     295,   296,   297,   298,   299,    40,    41,    91,    93,    44,
      38,    42,    43,    45,   126,    33,    47,    37,    60,    62,
      94,   124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -206

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-206)))

#define YYTABLE_NINF -192

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     279,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,     0,
     217,   237,    10,   217,  -206,  -206,    35,   -22,  -206,    -3,
    -206,   195,  -206,     0,  -206,   237,   -30,    22,  -206,   217,
    -206,  -206,  -206,  -206,     8,  -206,    13,   301,   217,    30,
    -206,  -206,    67,   217,    85,   118,     0,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
     106,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,    36,   162,    85,  -206,    40,    34,    18,     1,
      37,   122,   115,   131,   192,    -6,  -206,  -206,   -21,  -206,
    -206,  -206,   164,  -206,  -206,  -206,  -206,   259,  -206,     0,
     159,   157,  -206,  -206,  -206,   160,  -206,  -206,    48,    85,
      85,    85,   144,   165,   166,   168,   301,   177,   158,   163,
     167,    85,    85,  -206,  -206,   181,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,    85,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,   216,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,   176,  -206,  -206,  -206,  -206,   210,  -206,
    -206,  -206,  -206,   -11,   -32,   198,    85,    85,  -206,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,  -206,
     217,    48,  -206,   301,    85,    85,    85,  -206,   335,  -206,
    -206,  -206,   -20,  -206,    57,  -206,  -206,  -206,    40,    40,
      34,    34,    18,    18,    18,    18,     1,     1,    37,   122,
     115,   131,   192,   -12,  -206,  -206,   -28,  -206,   301,  -206,
      77,    78,    79,   209,   335,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,    85,    85,    85,    48,
     301,   301,   301,    85,    95,  -206,  -206,  -206,   244,  -206,
    -206,   124,  -206,  -206,  -206,  -206,   301,   301,   200,  -206,
    -206,  -206
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   116,   110,   111,   112,   113,   137,   114,   196,     0,
      99,     0,   115,     0,   200,   195,     0,     0,   103,   106,
     100,   152,   156,     0,   199,     0,   123,   117,   102,   101,
       1,   201,   104,    98,     0,   197,     0,   160,     0,   106,
     157,   198,     0,     0,     0,     0,     0,   108,   151,    19,
      21,   144,   147,   166,   170,   174,   178,   183,   187,   189,
     193,     2,     3,     4,    24,    25,    26,    27,    28,    29,
     161,     6,    18,    30,     0,    31,    38,    43,    48,    57,
      62,    65,    68,    71,    74,    77,    81,    94,     0,   158,
     138,   139,     0,   140,   141,   142,   143,   160,   122,   130,
       0,   125,   126,    30,    97,     0,   120,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    11,     7,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    83,     0,    23,
      32,    34,    36,    39,    41,    44,    46,    53,    55,    49,
      51,    58,    60,    63,    66,    69,    72,    75,    78,    95,
     162,   153,   159,     0,   129,   124,   127,   118,   135,   134,
     109,    20,    22,     0,   148,   167,   171,   175,     0,   184,
     188,   190,   192,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,   145,     0,     0,     0,     0,   179,     0,   194,
       5,    10,     0,    15,     0,    33,    35,    37,    40,    42,
      45,    47,    54,    56,    50,    52,    59,    61,    64,    67,
      70,    73,    76,     0,    96,   128,     0,   131,     0,   149,
       0,     0,     0,     0,     0,    12,    16,     8,    79,   132,
     136,   146,   168,   172,   176,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    80,   133,   165,   173,
     177,     0,   185,   163,   169,   181,     0,     0,     0,   186,
     164,   182
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,   -44,
    -206,  -206,  -206,   -71,   -61,  -206,  -206,  -206,   -52,  -206,
    -206,   -87,  -206,  -206,   -67,  -206,  -206,  -206,  -206,    71,
    -206,  -206,    84,  -206,    70,  -206,   102,  -206,   110,  -206,
    -206,  -206,   -43,  -206,  -206,  -104,  -206,   -99,  -206,   197,
      -5,     2,  -206,  -206,   277,  -206,  -206,  -206,    -4,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,   119,  -206,  -206,
    -200,  -206,    33,   -84,  -206,  -206,  -206,  -206,  -206,    39,
    -206,  -206,  -206,   303,   245,  -205,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,   327,  -206,  -206
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    71,   122,    72,   187,   185,   186,   222,   267,    73,
     109,   110,    74,    75,    76,   189,   190,   191,    77,   192,
     193,    78,   194,   195,    79,   198,   199,   196,   197,    80,
     200,   201,    81,   202,    82,   203,    83,   204,    84,   205,
      85,   206,    86,   207,   268,    87,   138,    88,   208,   105,
       8,    23,    17,    46,    18,    34,   108,    10,    11,    12,
      44,    45,    42,    43,   100,   101,   210,   102,   246,   269,
     170,   211,    13,    89,    90,   111,   248,   112,   213,    91,
      36,    37,    38,    25,    92,    93,   284,   287,    94,   113,
     214,   270,   114,   215,   271,    95,   115,   216,   272,   116,
     253,   273,   288,   117,   218,   286,    96,   118,   119,   120,
     121,    14,    15,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,   104,     9,   139,   169,    19,    22,   157,   162,   147,
     148,   247,    20,   254,   220,    28,  -121,   159,     9,    39,
      40,   259,   183,   184,   145,   146,   255,    32,   159,   256,
     103,    28,   178,    22,   188,    30,     1,   159,   159,   260,
     123,   124,    39,    33,   160,    99,    29,   151,   152,   266,
      24,   258,    49,    50,   219,    26,   158,    27,    35,   149,
     150,  -107,    29,    21,    41,   171,   172,   103,   104,   277,
    -119,     1,    47,     2,     3,     4,     5,     6,     7,   162,
      48,   125,   223,   126,    61,    62,   143,   144,   224,    49,
      50,   140,    40,    63,  -107,   164,   141,   142,    64,    65,
      66,    67,    68,    69,   244,   257,   159,   169,   243,   232,
     233,   234,   235,    98,   168,   250,   251,   252,   225,   226,
     227,    61,    62,   262,   263,   264,   159,   159,   159,   249,
      63,   228,   229,   236,   237,    64,    65,    66,    67,    68,
      69,   282,   230,   231,   159,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   275,   261,   169,   106,   274,    49,    50,
     285,  -191,   153,   159,   281,   154,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   278,   279,   280,    51,
      52,    53,   155,    54,    55,    56,    57,    58,    59,    60,
      61,    62,   289,   290,   156,   165,   166,   174,   167,    63,
     175,   176,    99,   177,    64,    65,    66,    67,    68,    69,
      49,    50,   179,   180,   103,   276,   137,    -9,   181,    70,
      21,   161,   182,  -154,  -154,  -154,  -154,  -154,  -154,   212,
     217,    51,    52,    53,   221,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   265,     2,     3,     4,     5,     6,
       7,    63,  -150,    49,    50,   291,    64,    65,    66,    67,
      68,    69,   283,   238,   240,     2,     3,     4,     5,     6,
       7,    70,    21,   209,    51,    52,    53,   239,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     2,     3,     4,
       5,     6,     7,    21,    63,    49,    50,   241,   173,    64,
      65,    66,    67,    68,    69,     1,   242,     2,     3,     4,
       5,     6,     7,   107,    70,    21,    51,    52,    53,   245,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    49,
      50,    97,   163,    31,     0,     0,    63,     0,     0,     0,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    21,     0,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70
};

static const yytype_int16 yycheck[] =
{
      44,    44,     0,    74,   108,     9,    11,    13,    92,     8,
       9,   211,    10,   218,    46,    13,    46,    49,    16,    23,
      25,    49,   121,   122,     6,     7,    46,    49,    49,    49,
      74,    29,   116,    38,   138,     0,    36,    49,    49,    67,
       4,     5,    46,    65,    65,    43,    13,    10,    11,   254,
      11,    63,     4,     5,    65,    45,    62,    47,    19,    58,
      59,    64,    29,    66,    25,   109,   110,   111,   111,   269,
      48,    36,    64,    38,    39,    40,    41,    42,    43,   163,
      67,    45,   186,    47,    36,    37,    52,    53,   187,     4,
       5,    51,    97,    45,    64,    99,    56,    57,    50,    51,
      52,    53,    54,    55,   208,    48,    49,   211,   207,   196,
     197,   198,   199,    46,    66,   214,   215,   216,   189,   190,
     191,    36,    37,    46,    46,    46,    49,    49,    49,   213,
      45,   192,   193,   200,   201,    50,    51,    52,    53,    54,
      55,    46,   194,   195,    49,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   267,   248,   269,    48,   266,     4,     5,
      46,    65,    50,    49,   273,    60,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   270,   271,   272,    25,
      26,    27,    61,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   286,   287,    12,    46,    49,    63,    48,    45,
      45,    45,   210,    45,    50,    51,    52,    53,    54,    55,
       4,     5,    45,    65,   268,   268,    64,    46,    65,    65,
      66,    67,    65,    38,    39,    40,    41,    42,    43,    63,
      30,    25,    26,    27,    46,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    45,    38,    39,    40,    41,    42,
      43,    45,    67,     4,     5,    65,    50,    51,    52,    53,
      54,    55,    28,   202,   204,    38,    39,    40,    41,    42,
      43,    65,    66,    67,    25,    26,    27,   203,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    66,    45,     4,     5,   205,   111,    50,
      51,    52,    53,    54,    55,    36,   206,    38,    39,    40,
      41,    42,    43,    46,    65,    66,    25,    26,    27,   210,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     4,
       5,    38,    97,    16,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    38,    39,    40,    41,    42,    43,   118,   119,
     125,   126,   127,   140,   179,   180,   181,   120,   122,   126,
     119,    66,   118,   119,   147,   151,    45,    47,   119,   140,
       0,   179,    49,    65,   123,   147,   148,   149,   150,   126,
     118,   147,   130,   131,   128,   129,   121,    64,    67,     4,
       5,    25,    26,    27,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    45,    50,    51,    52,    53,    54,    55,
      65,    69,    71,    77,    80,    81,    82,    86,    89,    92,
      97,   100,   102,   104,   106,   108,   110,   113,   115,   141,
     142,   147,   152,   153,   156,   163,   174,   151,    46,   119,
     132,   133,   135,    77,   110,   117,    48,   122,   124,    78,
      79,   143,   145,   157,   160,   164,   167,   171,   175,   176,
     177,   178,    70,     4,     5,    45,    47,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    64,   114,    81,
      51,    56,    57,    52,    53,     6,     7,     8,     9,    58,
      59,    10,    11,    50,    60,    61,    12,    13,    62,    49,
      65,    67,   141,   152,   126,    46,    49,    48,    66,   113,
     138,    77,    77,   117,    63,    45,    45,    45,   141,    45,
      65,    65,    65,   115,   115,    73,    74,    72,   113,    83,
      84,    85,    87,    88,    90,    91,    95,    96,    93,    94,
      98,    99,   101,   103,   105,   107,   109,   111,   116,    67,
     134,   139,    63,   146,   158,   161,   165,    30,   172,    65,
      46,    46,    75,   113,   115,    81,    81,    81,    82,    82,
      86,    86,    89,    89,    89,    89,    92,    92,    97,   100,
     102,   104,   106,   115,   113,   135,   136,   138,   144,   141,
     115,   115,   115,   168,   153,    46,    49,    48,    63,    49,
      67,   141,    46,    46,    46,    45,   153,    76,   112,   137,
     159,   162,   166,   169,   115,   113,   110,   138,   141,   141,
     141,   115,    46,    28,   154,    46,   173,   155,   170,   141,
     141,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    70,    69,    71,    72,    71,    73,
      71,    74,    71,    71,    71,    75,    76,    75,    77,    78,
      77,    79,    77,    77,    80,    80,    80,    80,    80,    80,
      81,    82,    83,    82,    84,    82,    85,    82,    86,    87,
      86,    88,    86,    89,    90,    89,    91,    89,    92,    93,
      92,    94,    92,    95,    92,    96,    92,    97,    98,    97,
      99,    97,   100,   101,   100,   102,   103,   102,   104,   105,
     104,   106,   107,   106,   108,   109,   108,   110,   111,   112,
     110,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   115,   116,   115,   117,   118,   119,
     119,   119,   119,   120,   121,   120,   122,   123,   124,   122,
     125,   125,   125,   125,   125,   126,   127,   128,   127,   129,
     127,   130,   127,   131,   127,   132,   133,   134,   133,   135,
     135,   136,   137,   136,   138,   139,   138,   140,   141,   141,
     141,   141,   141,   141,   143,   144,   142,   145,   146,   142,
     148,   147,   149,   147,   150,   147,   151,   151,   152,   152,
     152,   153,   153,   155,   154,   154,   157,   158,   159,   156,
     160,   161,   162,   156,   164,   165,   166,   163,   167,   168,
     169,   170,   163,   171,   172,   173,   163,   175,   174,   176,
     174,   177,   174,   178,   174,   179,   179,   180,   180,   180,
     181,   181
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     4,     1,     0,     5,     0,
       4,     0,     5,     2,     2,     1,     0,     4,     1,     0,
       3,     0,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     0,     4,
       0,     4,     1,     0,     4,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     1,     0,     4,     1,     0,     0,
       7,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     3,     1,
       2,     2,     2,     1,     0,     4,     1,     0,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     0,
       4,     0,     4,     0,     5,     1,     1,     0,     4,     2,
       1,     1,     0,     4,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     6,     0,     0,     5,
       0,     3,     0,     4,     0,     5,     1,     2,     1,     2,
       0,     1,     2,     0,     3,     0,     0,     0,     0,     9,
       0,     0,     0,     8,     0,     0,     0,     8,     0,     0,
       0,     0,    11,     0,     0,     0,    10,     0,     3,     0,
       3,     0,     3,     0,     4,     1,     1,     3,     3,     2,
       1,     2
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
#line 70 "traductor.y" /* yacc.c:1646  */
    { if (comprueba_funcion){ fprintf(yyoutput, "%s", yytext); comprueba_funcion=0; } else if(variable_global){ fprintf(yyoutput, "%s", yytext); }else{ fprintf(yyoutput, "%s", yytext);} }
#line 1556 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "traductor.y" /* yacc.c:1646  */
    { if (!tam_vector) {fprintf(yyoutput, "%s", yytext); } else {fprintf(yyoutput, "%s", yytext); tam_vector=0;} }
#line 1562 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 1568 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 1574 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "[ "); }
#line 1580 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " ]"); }
#line 1586 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 80 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 1592 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 80 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 1598 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 81 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 1604 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 1610 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 82 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "++"); }
#line 1616 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 83 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "--"); }
#line 1622 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 88 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ", "); }
#line 1628 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "++"); }
#line 1634 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 95 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "--"); }
#line 1640 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 100 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " & "); }
#line 1646 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 101 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " * "); }
#line 1652 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 102 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " + "); }
#line 1658 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 103 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " - "); }
#line 1664 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 104 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " ~ "); }
#line 1670 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 105 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " ! "); }
#line 1676 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 114 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " * "); }
#line 1682 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 115 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " / "); }
#line 1688 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 116 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " %% "); }
#line 1694 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 121 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " + "); }
#line 1700 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 122 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " - "); }
#line 1706 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 128 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " << "); }
#line 1712 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 129 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " >> "); }
#line 1718 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " < "); }
#line 1724 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 136 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " > "); }
#line 1730 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 137 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " <= "); }
#line 1736 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 138 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " >= "); }
#line 1742 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 144 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " == "); }
#line 1748 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 145 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " != "); }
#line 1754 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 151 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " & "); }
#line 1760 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 157 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " ^ "); }
#line 1766 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 163 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " | "); }
#line 1772 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 169 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " && "); }
#line 1778 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 175 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " || "); }
#line 1784 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 181 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " ? "); }
#line 1790 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 181 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " : "); }
#line 1796 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 189 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " = "); }
#line 1802 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 190 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " *= "); }
#line 1808 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 191 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " /= "); }
#line 1814 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 192 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " %%= "); }
#line 1820 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 193 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " += "); }
#line 1826 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 194 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " -= "); }
#line 1832 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 195 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " <<= "); }
#line 1838 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 196 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " >>= "); }
#line 1844 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 197 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " &= "); }
#line 1850 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 198 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " ^= "); }
#line 1856 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 199 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " |= "); }
#line 1862 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 203 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ", "); }
#line 1868 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 212 "traductor.y" /* yacc.c:1646  */
    {
							for(symtable_set_type=sym_table; symtable_set_type!=(symrec *)0; symtable_set_type=(symrec *)symtable_set_type->next){
								if(symtable_set_type->type==-1){
									symtable_set_type->type=(yyvsp[-2].tipo);
								}
							}
							if (cant_corchetes==1 && imprimir_corchete==1)
							{
								fprintf(yyoutput, "];\n");
								cant_corchetes=0;
								imprimir_corchete=0;
							}else
								fprintf(yyoutput, ";\n");
											
						}
#line 1888 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 231 "traductor.y" /* yacc.c:1646  */
    {if((yyvsp[0].tipo) == INT) fprintf(yyoutput, "int ");
										if((yyvsp[0].tipo) == CHAR) fprintf(yyoutput, "char ");
										if((yyvsp[0].tipo) == VOID) fprintf(yyoutput, "void ");
										if((yyvsp[0].tipo) == FLOAT) fprintf(yyoutput, "float ");
										if((yyvsp[0].tipo) == DOUBLE) fprintf(yyoutput, "double ");}
#line 1898 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 243 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 1904 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 247 "traductor.y" /* yacc.c:1646  */
    {
							s = getsym((yyvsp[0].nombre));
							if (s==(symrec *)0)
							{
								s = putsym((yyvsp[0].nombre), -1, 0);
							}
							else
							{
								printf("Variable ya declarada!\n");
								yyerrok;	
							}
						}
#line 1921 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 260 "traductor.y" /* yacc.c:1646  */
    {
							s=getsym((yyvsp[0].nombre));
							if(s==(symrec *)0)
							{
								s=putsym((yyvsp[0].nombre), -1, 0);
							}
							else
							{
								printf("Variable ya declarada!\n");
								yyerrok;
							}
						}
#line 1938 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 272 "traductor.y" /* yacc.c:1646  */
    { if (imprimir_corchete==0) fprintf(yyoutput, "="); }
#line 1944 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 283 "traductor.y" /* yacc.c:1646  */
    {(yyval.nombre)=(yyvsp[0].nombre);}
#line 1950 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 287 "traductor.y" /* yacc.c:1646  */
    { if (comprueba_funcion){ fprintf(yyoutput, "%s", yytext); comprueba_funcion=0; } else fprintf(yyoutput, "%s", yytext); (yyval.nombre)=(yyvsp[0].nombre); }
#line 1956 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 288 "traductor.y" /* yacc.c:1646  */
    { tam_vector=1; if (!cant_corchetes) fprintf(yyoutput, "[ "); cant_corchetes=1; }
#line 1962 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 289 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "] ");}
#line 1968 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 290 "traductor.y" /* yacc.c:1646  */
    { if (!cant_corchetes) fprintf(yyoutput, "[ "); cant_corchetes=1; }
#line 1974 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 291 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "] "); }
#line 1980 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 292 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 1986 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 292 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 1992 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 293 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 1998 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 293 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 2004 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 302 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ", "); }
#line 2010 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 307 "traductor.y" /* yacc.c:1646  */
    {
							s=getsym((yyvsp[0].nombre));
						    if(s==(symrec *) 0)
						    {
						        s=putsym((yyvsp[0].nombre), (yyvsp[-1].tipo), 0);
						    }
						    else
						    {
						        printf("Variable ya declarada!\n");
						        yyerrok;
						    }
						}
#line 2027 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 324 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " ,"); }
#line 2033 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 329 "traductor.y" /* yacc.c:1646  */
    {fprintf(yyoutput, "{ ");}
#line 2039 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 329 "traductor.y" /* yacc.c:1646  */
    {fprintf(yyoutput, "} ");}
#line 2045 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 333 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "const "); }
#line 2051 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 346 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "case "); }
#line 2057 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 346 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ": "); }
#line 2063 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 347 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "default "); }
#line 2069 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 347 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ": "); }
#line 2075 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 351 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "{ "); }
#line 2081 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 351 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " }\n"); }
#line 2087 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 352 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "{\n"); }
#line 2093 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 352 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "}\n"); }
#line 2099 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 354 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "{\n"); }
#line 2105 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 354 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "}\n"); }
#line 2111 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 370 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 2117 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 371 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 2123 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 375 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "else"); }
#line 2129 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 380 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "if"); }
#line 2135 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 380 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 2141 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 380 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 2147 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 381 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "switch"); }
#line 2153 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 381 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 2159 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 381 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 2165 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 385 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "while"); }
#line 2171 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 385 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 2177 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 385 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 2183 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 386 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "do"); }
#line 2189 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 386 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "while"); }
#line 2195 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 386 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 2201 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 386 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 2207 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 386 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 2213 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 387 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "for"); }
#line 2219 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 387 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "( "); }
#line 2225 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 387 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, " )"); }
#line 2231 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 391 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "continue"); }
#line 2237 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 391 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 2243 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 392 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "break"); }
#line 2249 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 392 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 2255 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 393 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "return"); }
#line 2261 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 393 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 2267 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 394 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, "return "); }
#line 2273 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 394 "traductor.y" /* yacc.c:1646  */
    { fprintf(yyoutput, ";\n"); }
#line 2279 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 401 "traductor.y" /* yacc.c:1646  */
    { comprueba_funcion=1; }
#line 2285 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 407 "traductor.y" /* yacc.c:1646  */
    {
							s=getsym((yyvsp[-1].nombre));
							if(s==(symrec *)0)
							{
								s=putsym((yyvsp[-1].nombre),(yyvsp[-2].tipo),1);
							}
							else
							{
								printf("Funcion ya declarada!");
								yyerrok;
							}
						}
#line 2302 "traductor.tab.c" /* yacc.c:1646  */
    break;


#line 2306 "traductor.tab.c" /* yacc.c:1646  */
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
#line 427 "traductor.y" /* yacc.c:1906  */

//						FUNCIONES


#include <stdio.h>
#include <string.h>
#define X 300
#define Y 300
int indice =0;
char matriz[300][300],matriz_aux[300][300];
char funcion_name[20],funcion_name_aux[20];
char matriz_aux1[300][300];
int encontro_funcion=0,fil=0,col=0,columna=0;
void leer_archivo();
void clonacion();
char entrada[20];

yyerror(s)
char *s;
{
	sin_error=0;
	printf("%s: ERROR en la Linea %d cerca de:  %s\n", s, yylineno, yylval.nombre);
}

symrec * putsym(sym_name,sym_type, b_function)
	char *sym_name;
	int sym_type;
	int b_function;
{
	symrec *ptr;
	ptr = (symrec *) malloc(sizeof(symrec));
	ptr->name = (char *) malloc(strlen(sym_name) + 1);
	strcpy(ptr->name, sym_name);
	ptr->type = sym_type;
	ptr->value = 0; //set value to 0
	ptr->function = b_function;
	ptr->next =(struct symrec *) sym_table;
	sym_table = ptr;
	return ptr;
}
symrec * getsym(sym_name)
	char *sym_name;
{
	symrec *ptr;
	for(ptr = sym_table; ptr != (symrec*)0; ptr = (symrec *)ptr->next)
		if(strcmp(ptr->name, sym_name) == 0)
		{
			printf("simbolo: %s\n", ptr->name);
			return ptr;
		}
	return 0;
}

const char *tipo_id(int tipo){
	switch(tipo){
		case(282):
			return "CHAR";
		case(284):
			return "INT";
		case(288):
			return "FLOAT";
		case(289):
			return "DOUBLE";
		case(290):
			return "CONST";
		case(291):
			return "VOID";
		default:
			return "NO";
	}
}

const char *tipo_var(int tipo){
	switch(tipo){
		case(1):
			return "Funcion";
		case(0):
			return "Variable";
		default:
			return "NO";
	}
}

void leer_archivo()
{
    
    int i=0,j=0;
    char c;
	if ((yyoutput=fopen(entrada, "r")) == NULL)
	{
		printf("No se pudo abrir el archivo para escritura\n");
            return;
	}
    while(1)
    {
        c = fgetc(yyoutput);
        if(c=='\n')
        {
            i++;
            j=0;
        }else{

            j++;
        }
        matriz[i][j]=c;
        if( feof(yyoutput) )
        {
            break ;
        }
    }
    fclose(yyoutput);
    indice = i;
}

void clonacion(){

	int q,w,z;
	z=0;
	for(q=0;q<X;q++)
	{

			if(q == (indice-2))
				{
					strcat(matriz_aux1[z], "\n}");

				}
			else{
				strcat(matriz_aux1[z], matriz_aux[q]);
			}
		z++;

	}
}

//									MAIN - DEF
int main(int argc,char **argv)
{
	strcpy(entrada,argv[2]);
	/* Debe tener 3 parametros, ejecutable.exe /path/to/fuente.c /path/to/objeto.php */
	if (argc<3)
	{
		printf("Modo incorrecto de uso\n Forma correcta %s archivo.c archivo.php\n", argv[0]);
		return 0;
	}
	if ((yyin = fopen(argv[1],"rt")) == NULL) /*  */
	{
		printf("No se pudo abrir el archivo de lectura\n");
                return 0;
	}
	if ((yyoutput=fopen(argv[2], "w")) == NULL)
	{
		printf("No se pudo abrir el archivo para escritura\n");
                return 0;
	}

	fprintf(yyoutput, "\n");
	yyparse();
	fprintf(yyoutput, "\n");
	fclose(yyin);
	fclose(yyoutput);
	leer_archivo();
	clonacion();
	remove(entrada);
    yyoutput = fopen(entrada,"w+");
    fprintf(yyoutput, "#include <iostream>\nusing namespace std;\n");
    for(fil=0;fil<indice;fil++)
     {
        fprintf(yyoutput, "%s", matriz[fil]);
    }
    fclose(yyoutput);

	if(sin_error)
		printf("***********_ Traducción COMPLETA _***********\n");
	else
		printf("\nNo se pudo finalizar la traducción.\n");

	FILE *simbolos;
	strcat(argv[1], ".txt");
	simbolos=fopen(argv[1], "w+");
	symrec * ptr_table;
	fprintf(simbolos, "NOMBRE, TIPO, VARIABLE O FUNCION.\n");
	for(ptr_table = sym_table; ptr_table!=(symrec *)0; ptr_table=(symrec *)ptr_table->next)
	{
		fprintf(simbolos, "\t%s, %s, %s\n", ptr_table->name,
			tipo_id(ptr_table->type), 
			tipo_var(ptr_table->function));
	}

	fclose(simbolos);
	return 0;
}
