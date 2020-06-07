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
#line 1 "sintatica.y" /* yacc.c:339  */

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <boost/algorithm/string/replace.hpp>

#define YYSTYPE atributos

using namespace std;


int i = 0;
int lbl = 0;
string swVar = "";

struct atributos
{
	string label; //nome
	string traducao;
	string tipo;
	string valor;
	int booleano;
	string operacao;
	int tamanho;
};

struct contexto{
	map<string,atributos> varMap;
	string labelInicio, labelFim;
};

struct funcao{
	string conteudo;
	string label;
	vector<string>tipos; 
	vector<atributos>parametros; 
};

struct dim{
	map<string, vector<string> > dim;
};

map<string,atributos> varInfo;
vector<funcao> stackFunction;
vector<contexto> varContext;
map<string,atributos>::iterator varInfoIt;
vector<string> variaveis;
vector<string> variaveisGlobais;
vector<string> tempGlobal;
vector <string> mensagens;
map<string,int> strTemp;
vector<dim> matContext;
vector<string> matTemp;
vector<atributos> varStack;
map<string, vector<atributos> > funcParam;
vector<atributos> temparam;
vector<string> setMeFree;
string retorno = "";

void yyerror(string);
int yylex(void);
string itos(int);
string typeCompare(string,string);
void addVar(string,string, string);
atributos getVar(string);
int checkVar(string label);
atributos operacoes(struct atributos, struct atributos,string, struct atributos);
void checkRelacionalType(string t1, string t2);
void checkBooleanType(string t1, string t2);
void checkNegacaoBool(string t1);
void declaraVariaveis();
void declaraVariaveisGlobais();
void checkDeclar(string label);
void getErrors();
void pushContext();
void popContext();
int verificaVariavel(string label, string tipo);
int getTamanho(string tipo);
void addGlobalVar(string,string, string);
void atribuiTempsGlobais();
contexto returnContexto();
void defineLabel(string, string);
string getLabel();
string getContinue();
string getBreak();
void pushFunction(string, string); //empilhar as funções
void popFunction(); 
void declaraFunctions();
void pushParameters(string);
string popParameters();
int checkVariableValue(string label);
void freeAll();


#line 166 "y.tab.c" /* yacc.c:339  */

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
    TK_IF = 258,
    TK_ELSE = 259,
    TK_WHILE = 260,
    TK_LOOP = 261,
    TK_WRITE = 262,
    TK_READ = 263,
    TK_FOR = 264,
    TK_SWITCH = 265,
    TK_CASE = 266,
    TK_DEFAULT = 267,
    TK_CONTINUE = 268,
    TK_BREAK = 269,
    TK_LEN = 270,
    TK_COMENTARIO = 271,
    TK_COMENTARIOS = 272,
    TK_NUM = 273,
    TK_BOOLEANO = 274,
    TK_CHAR = 275,
    TK_REAL = 276,
    TK_RELACIONAL = 277,
    TK_IGUALDADE = 278,
    TK_LOGICO = 279,
    TK_NEGACAO = 280,
    TK_STRING = 281,
    TK_MAIN = 282,
    TK_ID = 283,
    TK_TIPO_INT = 284,
    TK_TIPO_FLOAT = 285,
    TK_TIPO_CHAR = 286,
    TK_TIPO_BOOL = 287,
    TK_TIPO_STRING = 288,
    TK_GLOBAL = 289,
    TK_RETURN = 290,
    TK_BOOL_TRUE = 291,
    TK_BOOL_FALSE = 292,
    TK_FIM = 293,
    TK_ERROR = 294
  };
#endif
/* Tokens.  */
#define TK_IF 258
#define TK_ELSE 259
#define TK_WHILE 260
#define TK_LOOP 261
#define TK_WRITE 262
#define TK_READ 263
#define TK_FOR 264
#define TK_SWITCH 265
#define TK_CASE 266
#define TK_DEFAULT 267
#define TK_CONTINUE 268
#define TK_BREAK 269
#define TK_LEN 270
#define TK_COMENTARIO 271
#define TK_COMENTARIOS 272
#define TK_NUM 273
#define TK_BOOLEANO 274
#define TK_CHAR 275
#define TK_REAL 276
#define TK_RELACIONAL 277
#define TK_IGUALDADE 278
#define TK_LOGICO 279
#define TK_NEGACAO 280
#define TK_STRING 281
#define TK_MAIN 282
#define TK_ID 283
#define TK_TIPO_INT 284
#define TK_TIPO_FLOAT 285
#define TK_TIPO_CHAR 286
#define TK_TIPO_BOOL 287
#define TK_TIPO_STRING 288
#define TK_GLOBAL 289
#define TK_RETURN 290
#define TK_BOOL_TRUE 291
#define TK_BOOL_FALSE 292
#define TK_FIM 293
#define TK_ERROR 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 295 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   551

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      56,    57,    54,    52,    59,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    58,
      47,    45,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,    42,     2,     2,     2,
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
      35,    36,    37,    38,    39,    43,    44,    48,    49,    50,
      51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   124,   144,   148,   155,   163,   170,   175,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   195,   203,   210,   217,   226,   234,   238,
     252,   265,   278,   291,   296,   305,   310,   311,   314,   320,
     325,   330,   337,   342,   347,   352,   355,   361,   368,   374,
     381,   386,   391,   396,   401,   410,   421,   431,   438,   444,
     451,   458,   467,   476,   481,   487,   492,   498,   505,   511,
     534,   538,   543,   548,   556,   564,   572,   582,   592,   609,
     617,   633,   650,   668,   695,   703,   709,   719,   729,   740,
     751,   801,   817,   823,   829,   838,   855,   863,   880,   887,
     904,   912,   920,   929,   955,   962,   981,   982,  1035,  1072,
    1109,  1146,  1149,  1177,  1205,  1233,  1261,  1289,  1328,  1338,
    1343,  1350,  1360,  1367,  1377,  1383,  1394,  1401,  1407,  1415,
    1422,  1438,  1446,  1456,  1463,  1471,  1479
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_IF", "TK_ELSE", "TK_WHILE",
  "TK_LOOP", "TK_WRITE", "TK_READ", "TK_FOR", "TK_SWITCH", "TK_CASE",
  "TK_DEFAULT", "TK_CONTINUE", "TK_BREAK", "TK_LEN", "TK_COMENTARIO",
  "TK_COMENTARIOS", "TK_NUM", "TK_BOOLEANO", "TK_CHAR", "TK_REAL",
  "TK_RELACIONAL", "TK_IGUALDADE", "TK_LOGICO", "TK_NEGACAO", "TK_STRING",
  "TK_MAIN", "TK_ID", "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR",
  "TK_TIPO_BOOL", "TK_TIPO_STRING", "TK_GLOBAL", "TK_RETURN",
  "TK_BOOL_TRUE", "TK_BOOL_FALSE", "TK_FIM", "TK_ERROR", "'{'", "'}'",
  "'~'", "\"&&\"", "\"||\"", "'='", "'>'", "'<'", "\"<=\"", "\">=\"",
  "\"==\"", "\"!=\"", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "';'",
  "','", "':'", "'['", "']'", "$accept", "T", "S", "BLOCO", "PUSH_CONTEXT",
  "POP_CONTEXT", "COMANDOS", "COMANDO", "FUNCTION", "RETURN", "PARAMETERS",
  "CHAMAPARAM", "JUMP", "WRITE", "W_OBJ", "W_LINE", "READ", "R_OBJ",
  "R_LINE", "LEN", "IF", "ELSE", "WHILE", "FOR", "SWITCH", "CASES",
  "DEFAULT", "BREAK", "CONTINUE", "E", "COMENTARIO", "COMENTARIOS",
  "DECLAR", "MATRIX", "DIM", "GLOBAL", "EXPRESSION", YY_NULLPTR
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
     123,   125,   126,   295,   296,    61,    62,    60,   297,   298,
     299,   300,    43,    45,    42,    47,    40,    41,    59,    44,
      58,    91,    93
};
# endif

#define YYPACT_NINF -125

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-125)))

#define YYTABLE_NINF -122

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -125,     3,   347,  -125,   -44,   -23,   347,   422,     4,   -20,
     -12,    24,    29,    -6,  -125,  -125,  -125,  -125,  -125,  -125,
      25,    90,   112,   123,   124,   138,   518,   143,  -125,  -125,
      16,    42,     9,  -125,  -125,   347,  -125,  -125,  -125,   127,
     131,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   480,  -125,
    -125,   133,  -125,  -125,   399,   399,   187,   154,  -125,   137,
      85,   376,  -125,   126,  -125,   171,  -125,   478,   179,  -125,
    -125,  -125,  -125,    91,   445,    11,   -32,   153,   165,   445,
     151,     8,    10,    40,    43,    46,  -125,   186,   198,   199,
     205,   206,   157,   211,   212,   184,   188,   190,   197,   265,
    -125,  -125,  -125,  -125,   445,   445,   445,   445,  -125,  -125,
     399,   126,   -14,    -8,   209,   347,   191,   202,   183,    67,
      71,   265,  -125,   117,    68,   234,   238,   239,   253,   224,
     231,   236,   249,   126,   445,  -125,   445,  -125,   445,   445,
     250,   487,   445,   399,   173,   272,   445,   173,   273,   445,
     173,   274,   399,   276,   445,   173,   277,   269,   298,   299,
     300,   301,  -125,  -125,  -125,   445,   445,   445,   445,  -125,
      79,    79,  -125,  -125,    35,   399,   399,   399,   243,   243,
     399,   317,   445,  -125,   468,  -125,   171,   314,   321,   308,
      44,    45,    47,    48,   399,   330,  -125,  -125,   126,   126,
     126,   126,  -125,   445,   110,   461,    35,   343,   344,   346,
     361,   335,   445,   126,   336,   445,   126,   341,   445,    35,
     445,   126,   351,   445,   399,   445,   445,   399,   445,  -125,
    -125,  -125,  -125,    35,    35,    35,   386,  -125,    -5,  -125,
     170,   342,   126,   352,   445,   -17,   404,  -125,    49,   358,
     360,   363,   364,   243,   176,   243,   232,   243,   287,   333,
     243,   392,   473,    35,   126,   126,    35,   126,   243,  -125,
     365,  -125,   349,   415,   478,   445,   385,   445,   173,   173,
     173,   173,  -125,   349,  -125,   349,  -125,   349,   349,  -125,
     349,  -125,  -125,   388,   373,   237,  -125,   126,  -125,  -125,
    -125,  -125,   243,   243,  -125,   132,   371,  -125,  -125,   295,
    -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     9,     1,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    73,    75,    74,    79,
      78,     0,     0,     0,     0,     0,     0,     0,    76,    77,
       0,     0,     0,     7,     3,     9,    19,    20,    18,     0,
       0,    85,    12,    15,    16,    17,    36,    37,     0,    21,
      22,     0,   111,   106,     0,     0,     0,     0,     5,    79,
      78,    45,    38,    41,    47,    51,    46,     0,     0,    68,
      67,    53,    55,     0,     0,     0,     0,     0,     0,    35,
       0,    94,    96,    98,   100,   104,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     8,    13,    14,     0,     0,     0,     0,    10,    11,
       0,   136,     0,     0,     0,     9,     0,     0,     0,    79,
       0,    44,    49,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,    88,     0,    89,     0,     0,
       0,     0,     0,     0,    33,     0,     0,    33,     0,     0,
      33,     0,     0,     0,     0,    33,     0,   120,   122,   124,
     126,   129,    27,    86,    87,     0,     0,     0,     0,    84,
      69,    70,    71,    72,   135,     0,     0,     0,    28,    28,
       0,     0,     0,    40,    45,    48,    51,     0,     0,     0,
      94,    96,    98,   104,     0,     0,    52,    54,   107,   108,
     109,   110,    91,    35,     0,   136,   102,     0,     0,     0,
       0,     0,     0,    97,     0,     0,    99,     0,     0,   101,
       0,   105,     0,     0,     0,     0,     0,     0,     0,    80,
      81,    82,    83,   132,   133,   134,    58,    59,     0,     7,
       0,    42,    44,    50,     0,     0,    65,    34,    90,     0,
       0,     0,     0,    28,     0,    28,     0,    28,     0,     0,
      28,     0,   136,   128,   123,   125,   127,   130,    28,    56,
       0,     4,    90,     0,     0,     0,     0,     0,    33,    33,
      33,    33,    23,   112,    26,   114,    24,   113,   115,    25,
     116,    57,    60,   118,     0,     0,    62,   117,    29,    30,
      31,    32,    28,    28,    61,    65,     0,    63,    64,     6,
      66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,   -67,   434,   200,   -31,    -1,  -125,  -125,
    -124,   235,  -125,  -125,  -125,   257,  -125,  -125,   263,  -125,
    -125,  -125,  -125,  -125,  -125,   148,  -125,  -125,  -125,    -7,
    -125,  -125,   -65,  -125,    -9,  -125,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    33,    56,    57,   100,    34,    58,    36,    37,
     211,   140,    38,    39,    62,   120,    40,    66,   123,    41,
      42,   269,    43,    44,    45,   276,   308,    46,    47,    48,
      49,    50,    51,    52,   145,    53,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    35,   129,     3,   101,   175,   176,   177,   175,   176,
     177,    80,    54,   136,   175,   176,   177,   175,   176,   177,
      71,   137,    72,   214,    13,    99,   217,    16,   113,    17,
      18,   222,    64,    55,    35,    19,    67,    60,    95,    96,
      97,   274,    98,   178,    68,    28,    29,   111,   111,   179,
      73,   118,   270,   143,   121,   146,   134,   175,   176,   177,
      65,    30,    31,   135,   144,    32,   147,   133,    93,  -119,
      74,  -119,   141,   148,   151,   153,   156,    75,    76,    77,
      78,    79,    69,   174,   181,   149,  -119,    70,   152,   143,
     146,   154,   149,   154,   277,    94,   150,   170,   171,   172,
     173,  -119,   155,   111,  -119,  -119,  -119,  -119,  -119,  -119,
    -118,   236,   237,    74,    35,   189,   206,   131,    81,   132,
     187,   188,    77,    78,   -43,   219,   -43,   198,   183,   199,
     184,   200,   201,   106,   107,   204,   205,   116,   117,   213,
      82,    79,   216,   275,   306,   111,  -119,   221,   233,   234,
     235,    83,    84,   238,   298,   299,   300,   301,   229,   230,
     231,   232,   104,   105,   106,   107,    85,   245,   111,   111,
     111,    92,   248,   111,   185,   240,   186,   242,   104,   105,
     106,   107,   148,   151,   156,   102,   282,   111,   284,   103,
     286,   109,   114,   289,   115,   -39,   141,   263,   138,   122,
     266,   291,   207,   208,   209,   254,   210,   130,   256,   294,
     139,   258,   142,   259,   157,   162,   261,   262,   264,   265,
     111,   267,   104,   105,   106,   107,   158,   159,   104,   105,
     106,   107,   272,   160,   161,   304,   305,   273,   283,   163,
     164,   165,   310,   135,   182,   166,     4,   167,     5,     6,
       7,     8,     9,    10,   168,   137,    11,    12,    13,    14,
      15,    16,   190,    17,    18,   180,   191,   192,   295,    19,
     297,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,   193,   194,    -6,   104,   105,   106,   107,   195,   104,
     105,   106,   107,   196,   285,    30,    31,   303,     4,    32,
       5,     6,     7,     8,     9,    10,   197,   202,    11,    12,
      13,    14,    15,    16,   224,    17,    18,   104,   105,   106,
     107,    19,   169,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,   212,   215,   218,   -28,   220,   223,   104,
     105,   106,   107,   225,   226,   227,   228,    30,    31,   287,
       4,    32,     5,     6,     7,     8,     9,    10,   239,   134,
      11,    12,    13,    14,    15,    16,   136,    17,    18,   244,
     246,   249,   250,    19,   251,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,   104,   105,   106,   107,   252,
     268,    13,   253,   255,    16,   288,    17,    18,   257,    30,
      31,   184,   119,    32,    60,    95,    96,    97,   260,    98,
    -118,   186,    28,    29,    13,   275,   278,    16,   279,    17,
      18,   280,   281,   292,   110,    19,   296,    60,    30,    31,
     302,   309,    32,   277,     2,    28,    29,    13,   247,   271,
      16,   241,    17,    18,   104,   105,   106,   107,    59,   243,
      60,    30,    31,   307,   290,    32,     0,     0,    28,    29,
      13,     0,     0,    16,     0,    17,    18,   104,   105,   106,
     107,    19,     0,    60,    30,    31,     0,   293,    61,     0,
       0,    28,    29,    13,     0,     0,    16,     0,    17,    18,
       0,     0,     0,     0,   119,     0,    60,    30,    31,     0,
       0,    32,     0,     0,    28,    29,   124,   125,   126,   127,
      24,   128,    26,   104,   105,   106,   107,     0,   -95,   -95,
      30,    31,     0,     0,    32,   104,   105,   106,   107,     0,
    -121,  -121,   104,   105,   106,   107,     0,     0,   108,   104,
     105,   106,   107,     0,     0,   203,    86,    87,    88,    89,
      90,    91
};

static const yytype_int16 yycheck[] =
{
       7,     2,    67,     0,    35,    22,    23,    24,    22,    23,
      24,    20,    56,    45,    22,    23,    24,    22,    23,    24,
      26,    53,    28,   147,    15,    32,   150,    18,    55,    20,
      21,   155,    28,    56,    35,    26,    56,    28,    29,    30,
      31,    58,    33,    57,    56,    36,    37,    54,    55,    57,
      56,    60,    57,    45,    61,    45,    45,    22,    23,    24,
      56,    52,    53,    52,    56,    56,    56,    74,    52,    61,
      45,    61,    79,    82,    83,    84,    85,    52,    53,    54,
      55,    56,    58,   110,   115,    45,    61,    58,    45,    45,
      45,    45,    45,    45,    45,    53,    56,   104,   105,   106,
     107,    61,    56,   110,    61,    61,    61,    61,    61,    61,
      61,   178,   179,    45,   115,   124,   143,    26,    28,    28,
      52,    53,    54,    55,    57,   152,    59,   134,    57,   136,
      59,   138,   139,    54,    55,   142,   143,    52,    53,   146,
      28,    56,   149,    11,    12,   152,    61,   154,   175,   176,
     177,    28,    28,   180,   278,   279,   280,   281,   165,   166,
     167,   168,    52,    53,    54,    55,    28,   194,   175,   176,
     177,    28,    62,   180,    57,   182,    59,   184,    52,    53,
      54,    55,   191,   192,   193,    58,   253,   194,   255,    58,
     257,    58,     5,   260,    40,    58,   203,   224,    45,    28,
     227,   268,    29,    30,    31,   212,    33,    28,   215,   274,
      45,   218,    61,   220,    28,    58,   223,   224,   225,   226,
     227,   228,    52,    53,    54,    55,    28,    28,    52,    53,
      54,    55,    62,    28,    28,   302,   303,   244,    62,    28,
      28,    57,   309,    52,    61,    57,     3,    57,     5,     6,
       7,     8,     9,    10,    57,    53,    13,    14,    15,    16,
      17,    18,    28,    20,    21,    56,    28,    28,   275,    26,
     277,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    28,    58,    40,    52,    53,    54,    55,    57,    52,
      53,    54,    55,    57,    62,    52,    53,    60,     3,    56,
       5,     6,     7,     8,     9,    10,    57,    57,    13,    14,
      15,    16,    17,    18,    45,    20,    21,    52,    53,    54,
      55,    26,    57,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    61,    61,    61,    41,    61,    61,    52,
      53,    54,    55,    45,    45,    45,    45,    52,    53,    62,
       3,    56,     5,     6,     7,     8,     9,    10,    41,    45,
      13,    14,    15,    16,    17,    18,    45,    20,    21,    61,
      40,    28,    28,    26,    28,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    52,    53,    54,    55,    28,
       4,    15,    57,    57,    18,    62,    20,    21,    57,    52,
      53,    59,    26,    56,    28,    29,    30,    31,    57,    33,
      61,    59,    36,    37,    15,    11,    58,    18,    58,    20,
      21,    58,    58,    58,    25,    26,    41,    28,    52,    53,
      57,    60,    56,    45,     0,    36,    37,    15,   203,   239,
      18,   184,    20,    21,    52,    53,    54,    55,    26,   186,
      28,    52,    53,   305,    62,    56,    -1,    -1,    36,    37,
      15,    -1,    -1,    18,    -1,    20,    21,    52,    53,    54,
      55,    26,    -1,    28,    52,    53,    -1,    62,    56,    -1,
      -1,    36,    37,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    26,    -1,    28,    52,    53,    -1,
      -1,    56,    -1,    -1,    36,    37,    28,    29,    30,    31,
      32,    33,    34,    52,    53,    54,    55,    -1,    57,    58,
      52,    53,    -1,    -1,    56,    52,    53,    54,    55,    -1,
      57,    58,    52,    53,    54,    55,    -1,    -1,    58,    52,
      53,    54,    55,    -1,    -1,    58,    28,    29,    30,    31,
      32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    67,     0,     3,     5,     6,     7,     8,     9,
      10,    13,    14,    15,    16,    17,    18,    20,    21,    26,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      52,    53,    56,    65,    69,    70,    71,    72,    75,    76,
      79,    82,    83,    85,    86,    87,    90,    91,    92,    93,
      94,    95,    96,    98,    56,    56,    66,    67,    70,    26,
      28,    56,    77,    92,    28,    56,    80,    56,    56,    58,
      58,    26,    28,    56,    45,    52,    53,    54,    55,    56,
      97,    28,    28,    28,    28,    28,    28,    29,    30,    31,
      32,    33,    28,    52,    53,    29,    30,    31,    33,    92,
      68,    69,    58,    58,    52,    53,    54,    55,    58,    58,
      25,    92,    99,    99,     5,    40,    52,    53,    97,    26,
      78,    92,    28,    81,    28,    29,    30,    31,    33,    95,
      28,    26,    28,    92,    45,    52,    45,    53,    45,    45,
      74,    92,    61,    45,    56,    97,    45,    56,    97,    45,
      56,    97,    45,    97,    45,    56,    97,    28,    28,    28,
      28,    28,    58,    28,    28,    57,    57,    57,    57,    57,
      92,    92,    92,    92,    99,    22,    23,    24,    57,    57,
      56,    69,    61,    57,    59,    57,    59,    52,    53,    97,
      28,    28,    28,    28,    58,    57,    57,    57,    92,    92,
      92,    92,    57,    58,    92,    92,    99,    29,    30,    31,
      33,    73,    61,    92,    73,    61,    92,    73,    61,    99,
      61,    92,    73,    61,    45,    45,    45,    45,    45,    92,
      92,    92,    92,    99,    99,    99,    66,    66,    99,    41,
      92,    78,    92,    81,    61,    99,    40,    74,    62,    28,
      28,    28,    28,    57,    92,    57,    92,    57,    92,    92,
      57,    92,    92,    99,    92,    92,    99,    92,     4,    84,
      57,    68,    62,    92,    58,    11,    88,    45,    58,    58,
      58,    58,    66,    62,    66,    62,    66,    62,    62,    66,
      62,    66,    58,    62,    95,    92,    41,    92,    73,    73,
      73,    73,    57,    60,    66,    66,    12,    88,    89,    60,
      66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    67,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    76,    77,
      77,    77,    78,    78,    78,    78,    79,    80,    80,    81,
      81,    81,    82,    82,    82,    82,    83,    84,    84,    85,
      85,    86,    87,    88,    88,    88,    89,    90,    91,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     5,     1,     0,     0,     2,     0,
       2,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     6,     6,     6,     3,     0,     4,
       4,     4,     4,     0,     3,     0,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     3,     1,
       3,     0,     4,     2,     4,     2,     6,     2,     0,     5,
       7,     9,     7,     5,     5,     0,     3,     2,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     3,     1,     3,     3,     3,     3,
       5,     4,     1,     1,     2,     4,     2,     4,     2,     4,
       2,     4,     4,     3,     2,     4,     1,     4,     4,     4,
       4,     1,     6,     6,     6,     6,     6,     7,     4,     0,
       3,     5,     3,     5,     3,     5,     3,     5,     5,     3,
       5,     2,     3,     3,     3,     2,     1
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
#line 119 "sintatica.y" /* yacc.c:1646  */
    {

				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 125 "sintatica.y" /* yacc.c:1646  */
    {
				//yyerror("");
				getErrors();
				cout << "/*Compilador PACMAN*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n"<<endl;
				//adicionando o contexto global 
				declaraVariaveisGlobais();
				declaraVariaveis();
				cout<<"int main(void)\n{\n"<<endl;
				cout <<"goto init;\n\n"<<endl;
				declaraFunctions();
				cout <<"init: \n "<<endl;
				atribuiTempsGlobais();
				cout << (yyvsp[0]).traducao<<endl;
				freeAll();
				cout<<"\treturn 0;\n}" << endl;

			}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 145 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao;
			}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 155 "sintatica.y" /* yacc.c:1646  */
    {
				pushContext();
				(yyval).traducao = "";
		  		(yyval).label = "";
			}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 163 "sintatica.y" /* yacc.c:1646  */
    {
				popContext();
				(yyval).traducao = "";
			  	(yyval).label = "";
			}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 171 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 175 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 196 "sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).traducao = "";
				string conteudo = "\t\n" + (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t goto " + (yyvsp[-4]).label+"Fim;\n "  ;
				pushFunction((yyvsp[-4]).label, conteudo);
				
			}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).traducao = "";
				string conteudo = "\t\n" +popParameters() + (yyvsp[0]).traducao + "\tgoto " + (yyvsp[-4]).label+"Fim;\n "  ;
				pushFunction((yyvsp[-4]).label, conteudo);
			}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 211 "sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).traducao = "";
				string conteudo = "\t\n" +popParameters() + (yyvsp[0]).traducao + "\tgoto " + (yyvsp[-4]).label+"Fim;\n "  ;
				pushFunction((yyvsp[-4]).label, conteudo);
			}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 218 "sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).traducao = "";
				string conteudo = "\t\n" +popParameters() + (yyvsp[0]).traducao + "\tgoto " + (yyvsp[-4]).label+"Fim;\n "  ;
				pushFunction((yyvsp[-4]).label, conteudo);
			}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 227 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP"+itos(i++);
				(yyval).traducao = "\n\t" +(yyval).label + " = " +getVar((yyvsp[-1]).label).valor + "\n";
				retorno = (yyval).label;

			}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 234 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 239 "sintatica.y" /* yacc.c:1646  */
    {
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				(yyval).label = "TMP"+itos(i++);
				(yyval).traducao = (yyvsp[0]).traducao + "\tint " +(yyvsp[-2]).label + " = " + (yyval).label + ";\n";
				atributos a;
				a.tipo = "int";
				a.label = (yyval).label;
				temparam.push_back(a);
				addVar((yyvsp[-2]).label, a.label, a.tipo);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);

			}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 253 "sintatica.y" /* yacc.c:1646  */
    {
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				(yyval).label = "TMP"+itos(i++);
				(yyval).traducao = (yyvsp[0]).traducao + "\tfloat " +(yyvsp[-2]).label + " = " + (yyval).label + ";\n";
				atributos a;
				a.tipo = "float";
				a.label = (yyval).label;
				temparam.push_back(a);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);

			}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 266 "sintatica.y" /* yacc.c:1646  */
    {
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				(yyval).label = "TMP"+itos(i++);
				(yyval).traducao = (yyvsp[0]).traducao + "\tchar " +(yyvsp[-2]).label + " = " + (yyval).label + ";\n";
				atributos a;
				a.tipo = "char";
				a.label = (yyval).label;
				temparam.push_back(a);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);

			}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 279 "sintatica.y" /* yacc.c:1646  */
    {
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				(yyval).label = "TMP"+itos(i++);
				(yyval).traducao = (yyvsp[0]).traducao + "\tchar* " +(yyvsp[-2]).label + " = " + (yyval).label + ";\n";
				atributos a;
				a.tipo = "char*";
				a.label = (yyval).label;
				temparam.push_back(a);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);
			}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 291 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 297 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
				atributos a;
				a.tipo = (yyvsp[-2]).tipo;
				a.label = (yyval).label;
				temparam.push_back(a);
			}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 305 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 315 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao + "\tcout << " + (yyvsp[0]).valor + " << endl;\n";
			}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 321 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).valor = (yyvsp[0]).valor;
				(yyval).traducao = "";
			}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 326 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
				(yyval).valor = (yyvsp[-1]).valor;
			}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 331 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).valor = (yyvsp[0]).label;
			}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 338 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).valor = (yyvsp[-2]).valor + " << " + (yyvsp[0]).valor;
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
			}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 343 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
				(yyval).valor = (yyvsp[0]).valor;
			}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 348 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).valor = (yyvsp[0]).label;
			}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 356 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "\tcin >> " + (yyvsp[0]).traducao + ";\n";
			}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 362 "sintatica.y" /* yacc.c:1646  */
    {
				if(getVar((yyvsp[0]).label).tipo == "bool"){
					mensagens.push_back("Ler Booleano? Ficou biruta?");
				}
				(yyval).traducao = (yyvsp[0]).label;
			}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 369 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 375 "sintatica.y" /* yacc.c:1646  */
    {
				if(getVar((yyvsp[0]).label).tipo == "bool"){
					mensagens.push_back("Ler Booleano? Ficou biruta?");
				}
				(yyval).traducao = (yyvsp[0]).label;
			}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 382 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao + " >> " + (yyvsp[0]).traducao;
			}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 386 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 392 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = "int";
				(yyval).traducao = "\tstrlen("+ (yyvsp[-1]).valor + ");\n";
			}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 397 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = "int";
				(yyval).traducao = "\tstrlen("+ (yyvsp[0]).valor + ");\n";
			}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 402 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = "int";
				if(getVar((yyvsp[-1]).label).tipo == "string"){
					(yyval).traducao = "\tstrlen("+ (yyvsp[-1]).label + ");\n";
				}else{
					mensagens.push_back("Sem paciência para iniciantes... Len é pra string... Apenas.");
				}
			}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 411 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = "int";
				if(getVar((yyvsp[0]).label).tipo == "string"){
					(yyval).traducao = "\tstrlen("+ (yyvsp[0]).label + ");\n";
				}else{
					mensagens.push_back("Sem paciência para iniciantes... Len é pra string... Apenas.");
				}
			}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 422 "sintatica.y" /* yacc.c:1646  */
    {
				string fim = getLabel();
				string aux = "TMP"+itos(i++);
				variaveis.push_back("\tint "+aux);
				(yyval).traducao = (yyvsp[-3]).traducao + "\t"+ aux + " = !" + (yyvsp[-3]).label + "\n\tif("+aux+">=1)\n\t\tgoto "+(yyvsp[0]).label+";\n" + (yyvsp[-1]).traducao + "\tgoto "+fim+";\n\t"+ (yyvsp[0]).label +":\n" + (yyvsp[0]).traducao + "\t" + fim +":\n";
			
			}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 432 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = getLabel();
				(yyval).traducao = (yyvsp[0]).traducao;

			}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 438 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = getLabel();
				(yyval).traducao = "";
			}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 445 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = getLabel();
				string fim = getLabel();
				string aux = "TMP"+itos(i++);
				(yyval).traducao = "\t" + (yyval).label + ":\n" + (yyvsp[-2]).traducao + "\t" + aux + " = !" + (yyvsp[-2]).label + "\n\tif(" + aux + ">=1)\n\t\t goto "+fim+";\n" + (yyvsp[0]).traducao + "\tgoto " + (yyval).label +";\n\t"+fim +":\n";
			}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 452 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = getLabel();
				(yyval).traducao = "\t" + (yyval).label + ": \n" + (yyvsp[-5]).traducao + (yyvsp[-2]).traducao + "\tif("+(yyvsp[-2]).label+">=1)\n\t\t goto " + (yyval).label + ";\n";
			}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 459 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = getLabel();
				string fim = getLabel();
				string aux = "TMP" + itos(i++);
				(yyval).traducao = (yyvsp[-6]).traducao + "\t" + (yyval).label + ":\n" + (yyvsp[-4]).traducao + "\t" + aux + " = !" + (yyvsp[-4]).label + "\n\tif("+aux+">=1)\n\t\t goto "+fim+";\n" + (yyvsp[0]).traducao + (yyvsp[-2]).traducao + "\tgoto " + (yyval).label + ";\n\t"+fim +":\n";
			}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 468 "sintatica.y" /* yacc.c:1646  */
    {
				string fim = getLabel();
				boost::replace_all((yyvsp[-1]).traducao, "??" , (yyvsp[-4]).label);
				boost::replace_all((yyvsp[-1]).traducao, "!!" , fim);
				(yyval).traducao = (yyvsp[-1]).traducao + "\t" + fim + ":\n";
			}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 477 "sintatica.y" /* yacc.c:1646  */
    {
				string fim = getLabel();
				(yyval).traducao = (yyvsp[-3]).traducao + "\tif(?? != " + (yyvsp[-3]).label + ")\n\t\tgoto " + fim + ";\n" + (yyvsp[-1]).traducao + "\tgoto !!;\n\t" + fim + ":\n" + (yyvsp[0]).traducao;
			}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 482 "sintatica.y" /* yacc.c:1646  */
    {
				string fim = getLabel();
				(yyval).traducao = (yyvsp[-3]).traducao + "\tif(?? != " + (yyvsp[-3]).label + ")\n\t\tgoto " + fim + ";\n" + (yyvsp[-1]).traducao + "\tgoto !!\n\t" + fim + ":\n" + (yyvsp[0]).traducao;
			}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 487 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 493 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 499 "sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).traducao = "\tgoto "+ getBreak() + ";\n";
			}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 506 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "\tgoto "+ getContinue() + ";\n";
			}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 512 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).tipo == "string" && (yyvsp[0]).tipo == "string"){
					(yyval).tipo = "string";
					(yyval).label = "TMP" + itos(i++);
					int tam1, tam2;
					if(strTemp.count((yyvsp[-2]).label)){
						tam1 = strTemp[(yyvsp[-2]).label];
					}else{
						tam1 = getVar((yyvsp[-2]).label).tamanho;
					}
					if(strTemp.count((yyvsp[0]).label)){
						tam2 = strTemp[(yyvsp[0]).label];
					}else{
						tam2 = getVar((yyvsp[0]).label).tamanho;
					}
					variaveis.push_back("\tchar "+(yyval).label+"["+itos(tam1+tam2+1)+"]");
					strTemp[(yyval).label] = tam1+tam2;
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\tstrcat("+(yyval).label+", "+(yyvsp[-2]).label+");\n\tstrcat("+(yyval).label+", "+(yyvsp[0]).label+");\n";
				}else{
					(yyval) = operacoes((yyval),(yyvsp[-2]),"+",(yyvsp[0]));
				}
			}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 535 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = operacoes((yyval),(yyvsp[-2]),"-",(yyvsp[0]));
			}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 539 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = operacoes((yyval),(yyvsp[-2]),"*",(yyvsp[0]));

			}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 544 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = operacoes((yyval),(yyvsp[-2]),"/",(yyvsp[0]));

			}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 549 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
				//$$.traducao = "\tint " + $$.label + " = " + $1.traducao + ";\n";
				(yyval).traducao = "\t"+(yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
				variaveis.push_back("\tint "+(yyval).label);
				(yyval).tipo = "int";
			}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 557 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
				//$$.traducao = "\tfloat " + $$.label + " = " + $1.traducao + ";\n";
				(yyval).traducao = "\t"+(yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
				variaveis.push_back("\tfloat "+(yyval).label);
				(yyval).tipo = "float";
			}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 565 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
			//	$$.traducao = "\tchar " + $$.label + " = " + $1.traducao + ";\n";
				(yyval).traducao = "\t"+(yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
				variaveis.push_back("\tchar "+(yyval).label);
				(yyval).tipo = "char";
			}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 573 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
				(yyvsp[0]).traducao = "true";
				//$$.traducao = "\tint " + $$.label + " = 1;\n";
				(yyval).traducao = "\t" + (yyval).label + " = 1;\n";
				(yyval).tipo = "bool";
				variaveis.push_back("\tint "+(yyval).label);
				(yyval).booleano = 1; // usa essa bagaça aqui p comparar
			}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 583 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
				(yyvsp[0]).traducao = "false";
				//$$.traducao = "\tint " + $$.label + " = 0;\n";
				(yyval).traducao = "\t" + (yyval).label + " = 0;\n";
				(yyval).tipo = "bool";
				variaveis.push_back("\tint "+(yyval).label);
				(yyval).booleano = 0; // usa essa bagaça aqui o comparar
			}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 593 "sintatica.y" /* yacc.c:1646  */
    {
					if(checkVar((yyvsp[0]).label)){
					  (yyval).valor = getVar((yyvsp[0]).label).valor;
					  (yyval).tipo = getVar((yyvsp[0]).label).tipo;
					  (yyval).label = "TMP" + itos(i++);
					//$$.traducao = "\t"+ $$.tipo + " " + $$.label + " = " + $1.label + ";\n";
					if((yyval).tipo == "string"){
						variaveis.push_back("\tchar "+(yyval).label + "[" + itos(varContext[varContext.size()-1].varMap[(yyvsp[0]).label].tamanho+1) + "]");
						strTemp[(yyval).label] = varContext[varContext.size()-1].varMap[(yyvsp[0]).label].tamanho;
						(yyval).traducao = "\tstrcpy(" + (yyval).label + ", " + (yyvsp[0]).label + ");\n"; 
					}else{
						variaveis.push_back("\t"+(yyval).tipo+ " " +(yyval).label);
						(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).label + ";\n";
					}
					}
			}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 610 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
				strTemp[(yyval).label] = (yyvsp[0]).valor.length()-2;
				variaveis.push_back("\tchar* "+(yyval).label);
				(yyval).traducao = "\t"+(yyval).label+" = "+(yyvsp[0]).valor+";\n";
				(yyval).tipo = "string";
			}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 618 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[0]).tipo == "bool"){
					//yyerror("Cast de BOOL pra INT aqui não!");
					mensagens.push_back("Cast de BOOL pra INT aqui não!");
				}
				if((yyvsp[0]).tipo == "string"){
					//yyerror("Cast de BOOL pra INT aqui não!");
					mensagens.push_back("Cast de STRING pra INT aqui não!");
				}
				(yyval).label = "TMP" + itos(i++);
				//$$.traducao = $4.traducao + "\tint " + $$.label + " = (int) " + $4.label + ";\n";
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = (int) " + (yyvsp[0]).label + ";\n";
				(yyval).tipo = "int";
				variaveis.push_back("\t"+(yyval).tipo+" "+(yyval).label);
			}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 634 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[0]).tipo == "bool"){
				//	yyerror("Cast de BOOL pra FLOAT aqui não!");
					mensagens.push_back("Cast de BOOL pra FLOAT aqui não!");
				}
				if((yyvsp[0]).tipo == "string"){
				//	yyerror("Cast de BOOL pra FLOAT aqui não!");
					mensagens.push_back("Cast de STRING pra FLOAT aqui não!");
				}
				(yyval).label = "TMP" + itos(i++);
				//$$.traducao = $4.traducao + "\tfloat " + $$.label + " = (float) " + $4.label + ";\n";
				(yyval).traducao = (yyvsp[0]).traducao + "\t " + (yyval).label + " = (float) " + (yyvsp[0]).label + ";\n";
				(yyval).tipo = "float";
				variaveis.push_back("\t"+(yyval).tipo+" "+(yyval).label);

			}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 651 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[0]).tipo == "bool"){
				//	yyerror("Cast de BOOL pra CHAR aqui não!");
					mensagens.push_back("Cast de BOOL pra CHAR aqui não!");

				}
				if((yyvsp[0]).tipo == "string"){
				//	yyerror("Cast de BOOL pra CHAR aqui não!");
					mensagens.push_back("Cast de STRING pra CHAR aqui não!");
				}
				(yyval).label = "TMP" + itos(i++);
				//$$.traducao = $4.traducao + "\tchar " + $$.label + " = (char) " + $4.label + ";\n";
				(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = (char) " + (yyvsp[0]).label + ";\n";
				(yyval).tipo = "char";
				variaveis.push_back("\t"+(yyval).tipo+" "+(yyval).label);

			}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 669 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = "string";
				(yyval).label = "TMP" + itos(i++);
				if((yyvsp[0]).tipo == "char"){
					variaveis.push_back("\tchar "+(yyval).label+"[2]");
					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + "[0] = " + (yyvsp[0]).label + ";\n";
					strTemp[(yyval).label] = 1;
				}else if((yyvsp[0]).tipo == "string"){
					(yyval).traducao = (yyvsp[0]).traducao;
					(yyval).label = (yyvsp[0]).label;
				}else if((yyvsp[0]).tipo == "int"){
					variaveis.push_back("\tchar "+(yyval).label+"[12]");
					(yyval).traducao = (yyvsp[0]).traducao + "\tsprintf(" + (yyval).label + ", \"%d\", " + (yyvsp[0]).label + ");\n";
					strTemp[(yyval).label] = 11;
				}else if((yyvsp[0]).tipo == "float"){
					variaveis.push_back("\tchar "+(yyval).label+"[16]");
					(yyval).traducao = (yyvsp[0]).traducao + "\tsprintf(" + (yyval).label + ", \"%f\", " + (yyvsp[0]).label + ");\n";
					strTemp[(yyval).label] = 15;
				}else{
					mensagens.push_back("OPA, conversão de boolean pra string é forçar a barra né!");
				}
				string temp = "TMP" + itos(i++);
				variaveis.push_back("\tchar* "+temp);
				(yyval).traducao = (yyval).traducao + "\t" + temp + " = " + (yyval).label;
				(yyval).label = temp;
			}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 696 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
				(yyval).label = (yyvsp[-1]).label;
				(yyval).tipo = (yyvsp[-1]).tipo;
				variaveis.push_back("\t"+(yyval).tipo+" "+(yyval).label);

			}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 704 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
				variaveis.push_back("\tint "+(yyval).label);
				(yyval).traducao = "\t"+ (yyval).label + " = " + (yyvsp[0]).traducao;
			}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 710 "sintatica.y" /* yacc.c:1646  */
    {
				if(getVar((yyvsp[0]).label).tipo == "int" || getVar((yyvsp[0]).label).tipo == "float"){
					(yyval).traducao = "\t" + (yyvsp[0]).label + " = " + (yyvsp[0]).label + " + " +  itos(1) + ";\n";
					(yyval).tipo = getVar((yyvsp[0]).label).tipo;
					(yyval).label = (yyvsp[0]).label;
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar ++ nisso aí que tu botou...");
				}
			}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 720 "sintatica.y" /* yacc.c:1646  */
    {
				if(getVar((yyvsp[0]).label).tipo == "int" || getVar((yyvsp[0]).label).tipo == "float"){
					(yyval).traducao = "\t" + (yyvsp[0]).label + " = " + (yyvsp[0]).label + " - " +  itos(1) + ";\n";
					(yyval).tipo = getVar((yyvsp[0]).label).tipo;
					(yyval).label = (yyvsp[0]).label;
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar -- nisso aí que tu botou...");
				}
			}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 730 "sintatica.y" /* yacc.c:1646  */
    {
				if(getVar((yyvsp[0]).label).tipo == "int" || getVar((yyvsp[0]).label).tipo == "float"){
					(yyval).label = "TMP"+itos(i++);
					(yyval).tipo = getVar((yyvsp[0]).label).tipo;
					variaveis.push_back("\t"+getVar((yyvsp[0]).label).tipo + " " + (yyval).label);
					(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).label + ";\n\t" + (yyvsp[0]).label + " = " + (yyvsp[0]).label + " + 1;\n";
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar ++ nisso aí que tu botou...");
				}
			}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 741 "sintatica.y" /* yacc.c:1646  */
    {
				if(getVar((yyvsp[0]).label).tipo == "int" || getVar((yyvsp[0]).label).tipo == "float"){
					(yyval).label = "TMP"+itos(i++);
					(yyval).tipo = getVar((yyvsp[0]).label).tipo;
					variaveis.push_back("\t"+getVar((yyvsp[0]).label).tipo + " " + (yyval).label);
					(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).label + ";\n\t" + (yyvsp[0]).label + " = " + (yyvsp[0]).label + " - 1;\n";
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar -- nisso aí que tu botou...");
				}
			}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 752 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = getVar((yyvsp[-4]).label).tipo;
				(yyval).label = "TMP"+itos(i++);
				string tipo;
				if((yyval).tipo == "int*" || (yyval).tipo == "bool*"){
					variaveis.push_back("\tint "+(yyval).label);
					tipo = "int";
				}
				else if((yyval).tipo == "float*"){
					variaveis.push_back("\tfloat "+(yyval).label);
					tipo = "int";
				}
				else if((yyval).tipo == "char*"){
					variaveis.push_back("\tchar "+(yyval).label);
					tipo = "int";
				}
				else{
					variaveis.push_back("\tchar* "+(yyval).label);
					tipo = "int";
				}
				matTemp.push_back((yyvsp[-1]).label);
				if(matTemp.size() == matContext[varContext.size()-1].dim[(yyvsp[-4]).label].size()){
					string multiplier = "1";
					string index = "0";
					int j;
					(yyval).traducao = "";
					string aux1, aux2, aux3, aux4;
					for(j=0; j<matContext[varContext.size()-1].dim[(yyvsp[-4]).label].size(); j++){
						aux1 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux1);
						(yyval).traducao += "\t" + aux1 + " = " + multiplier + ";\n";
						aux2 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux2);
						(yyval).traducao += "\t" + aux2 + " = " + aux1 + " * " + matTemp[j] + ";\n";
						aux3 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux3);
						(yyval).traducao += "\t" + aux3 + " = " + index + ";\n";
						aux4 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux4);
						(yyval).traducao += "\t" + aux4 + " = " + aux3 + " + " + aux2 + ";\n";
						index = aux4;
						multiplier = aux1 + " + " + matContext[varContext.size()-1].dim[(yyvsp[-4]).label][j];
					}
					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + (yyval).traducao + "\t" + (yyval).label + " = " + (yyvsp[-4]).label + "["+index+"];\n";
				}else{
					mensagens.push_back("Dimensão paralela da matriz: "+(yyvsp[-4]).label);
				}
				matTemp.clear();
			}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 802 "sintatica.y" /* yacc.c:1646  */
    {
				string declaratudo = "";
				int i;
				for(i = 0; i < funcParam[(yyvsp[-3]).label].size(); i++){
					if(temparam[i].tipo == funcParam[(yyvsp[-3]).label][i].tipo){
						declaratudo += "\t" + funcParam[(yyvsp[-3]).label][i].label + " = " + temparam[i].label + ";\n";
					}else{
						mensagens.push_back("Não deu match nos parâmetros");
					}
				}
				string retorno_funcao = "TMP" + itos(i++);
				(yyval).traducao = (yyvsp[-1]).traducao + declaratudo + "\tgoto " + (yyvsp[-3]).label + ";\n\t"+ (yyvsp[-3]).label+"Fim" +": \n\t"+ retorno_funcao +" = "+ retorno +"\n";
				retorno = "";
			}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 818 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 824 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 830 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
				(yyval).traducao = "\tint " + (yyvsp[0]).label + ";\n";
				(yyval).tipo = "int";
				addVar((yyvsp[0]).label, "", (yyval).tipo);


			}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 840 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "string*"){
					mensagens.push_back("STRING pra INT? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				(yyval).tipo = "int";
				if((yyvsp[0]).tipo != "int" && (yyvsp[0]).tipo != "int*"){
					(yyval).traducao = (yyvsp[0]).traducao;
					//$$.traducao = $4.traducao + "\tint "+ $2.label + " = (int) " + $4.label + ";\n";
				}else{
					(yyval).traducao = (yyvsp[0]).traducao;
					//$$.traducao = $4.traducao + "\tint "+ $2.label + " = " + $4.label + ";\n";
				}
				addVar((yyvsp[-2]).label,  (yyvsp[0]).label, (yyval).tipo);
			}
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 856 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
				(yyval).traducao = "\tfloat " + (yyvsp[0]).label + ";\n";
				(yyval).tipo = "float";
				addVar((yyvsp[0]).label, "", (yyval).tipo); //coloquei o valor como "" pq é só a declaração, mas depois tem que ver isso

			}
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 864 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "string*"){
					mensagens.push_back("STRING pra FLOAT? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				if((yyvsp[0]).tipo != "float" && (yyvsp[0]).tipo != "float*"){
					(yyval).traducao = (yyvsp[0]).traducao;
					//$$.traducao = $4.traducao + "\tfloat "+ $2.label + " = (float) " + $4.label + ";\n";
				}else{
					(yyval).traducao = (yyvsp[0]).traducao;
					//$$.traducao = $4.traducao + "\tfloat "+ $2.label + " = " + $4.label + ";\n";
				}
				(yyval).tipo = "float";
				addVar((yyvsp[-2]).label, (yyvsp[0]).label, (yyval).tipo);

			}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 881 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
				(yyval).traducao = "\tchar " + (yyvsp[0]).label + ";\n";
				(yyval).tipo = "char";
				addVar((yyvsp[0]).label, "", (yyval).tipo);
			}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 888 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "string*"){
					mensagens.push_back("STRING pra CHAR? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				if((yyvsp[0]).tipo != "char" && (yyvsp[0]).tipo != "char*"){
					(yyval).traducao = (yyvsp[0]).traducao;
					//$$.traducao = $4.traducao + "\tchar "+ $2.label + " = (char) " + $4.label + ";\n";
				}else{
					(yyval).traducao = (yyvsp[0]).traducao;
					//$$.traducao = $4.traducao + "\tchar "+ $2.label + " = " + $4.label + ";\n";
				}
				(yyval).tipo = "char";
				addVar((yyvsp[-2]).label, (yyvsp[0]).label, (yyval).tipo);

			}
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 905 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
			    (yyval).traducao = "\tint " + (yyvsp[0]).label + ";\n";
				(yyval).tipo = "bool";
				addVar((yyvsp[0]).label, "", (yyval).tipo);

			}
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 913 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
				(yyval).traducao = (yyvsp[0]).traducao;
			   // $$.traducao = $4.traducao + "\tint " + $2.label + " = " + $4.label + ";\n";
			    (yyval).tipo = "bool";
			    addVar((yyvsp[-2]).label, (yyvsp[0]).label, (yyval).tipo);
			}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 921 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
				(yyval).label = "TMP" + itos(i++);
				(yyval).traducao = (yyvsp[0]).traducao;
				//$$.traducao = $4.traducao + "\tint"+" " + $2.label + " = " + $4.label + ";\n";
				addVar((yyvsp[-2]).label, (yyvsp[0]).label, (yyval).tipo);

			}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 930 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).tipo = getVar((yyvsp[-2]).label).tipo;
				//cout << $$.tipo << endl;
				if(((yyval).tipo == "bool" || (yyval).tipo == "bool*") && ((yyvsp[0]).tipo != "bool" && (yyvsp[0]).tipo != "bool*")){
					//yyerror("Conversão inválida de "+$3.tipo+" para bool");
					mensagens.push_back("Conversão inválida de "+(yyvsp[0]).tipo+" para bool");
				}
				if((yyvsp[0]).tipo == "string"  || (yyvsp[0]).tipo == "string*"){
					if(getVar((yyvsp[-2]).label).tipo == "string"){
						if(strTemp.count((yyvsp[0]).label)>0){
							varContext[varContext.size()-1].varMap[(yyvsp[-2]).label].tamanho = strTemp[(yyvsp[0]).label];
							(yyval).traducao = (yyvsp[0]).traducao + "\t"+(yyvsp[-2]).label+" = "+(yyvsp[0]).label+";\n";
						}else{
							varContext[varContext.size()-1].varMap[(yyvsp[-2]).label].tamanho = varContext[varContext.size()-1].varMap[(yyvsp[0]).label].tamanho;
							(yyval).traducao = (yyvsp[0]).traducao + "\t"+(yyvsp[-2]).label+" = "+(yyvsp[0]).label+";\n";
						}
					}else{
						mensagens.push_back("Conversão inválida de string para "+getVar((yyvsp[0]).label).tipo);
					}
				}else if((getVar((yyvsp[-2]).label).tipo == "string" || getVar((yyvsp[-2]).label).tipo == "string*")){
					mensagens.push_back("Conversão inválida de "+getVar((yyvsp[0]).label).tipo+" para string");
				}else{
					(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + (yyvsp[0]).label + ";\n";
				}
			}
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 956 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = "\tchar* " + (yyval).label + " = (char*) malloc(200 * sizeof(char));\n";
				(yyval).tipo = "string";
				addVar((yyval).label, "", (yyval).tipo);
			}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 963 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[-2]).label;
				(yyval).tipo = "string";
				addVar((yyval).label, "", (yyval).tipo);
				if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "string*"){
					if(strTemp[(yyvsp[0]).label] > 0){ 
						(yyval).traducao = (yyvsp[0]).traducao;
						//$$.traducao = $4.traducao + "\tchar* " + $$.label + " = "+$4.label+";\n";
						varContext[varContext.size()-1].varMap[(yyval).label].tamanho = strTemp[(yyvsp[0]).label];
					}else{
						(yyval).traducao = (yyvsp[0]).traducao;
						//$$.traducao = $4.traducao + "\tchar* " + $$.label + " = "+$4.label+";\n";
						varContext[varContext.size()-1].varMap[(yyval).label].tamanho = varContext[varContext.size()-1].varMap[(yyvsp[0]).label].tamanho;
					}
				}else{
					mensagens.push_back("Não tem conversão implícita pra string não, querido, usa (string) aí.");
				}
			}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 983 "sintatica.y" /* yacc.c:1646  */
    {
				string tipo = varContext[varContext.size()-1].varMap [(yyvsp[-3]).label].tipo;
				string temp = "TMP"+itos(i++);
				if(tipo == "string"){
					if((yyvsp[0]).tipo == "string"){
						if(strTemp.count((yyvsp[0]).label)){
							variaveis.push_back("\tchar "+temp+"["+itos(getVar((yyvsp[-3]).label).tamanho+strTemp[(yyvsp[0]).label]+1)+"]");
							strTemp[temp] = getVar((yyvsp[-3]).label).tamanho+strTemp[(yyvsp[0]).label];
						}else{
							variaveis.push_back("\tchar "+temp+"["+itos(getVar((yyvsp[-3]).label).tamanho+getVar((yyvsp[0]).label).tamanho+1)+"]");
							strTemp[temp] = getVar((yyvsp[-3]).label).tamanho+getVar((yyvsp[0]).label).tamanho;
						}
						(yyval).traducao = (yyvsp[0]).traducao + "\t strcpy("+temp+", "+(yyvsp[-3]).label+");\n\tstrcat("+temp+", "+(yyvsp[0]).label+");\n";
						(yyval).label = temp;
					}else{
						mensagens.push_back("Operações de strings somente com strings!");
					}
				}else{
					if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "bool" || tipo == "bool"){
						mensagens.push_back("operação matemática com bool ou string aqui não!");
					}else{
						if(tipo == "int"){
							if((yyvsp[0]).tipo == "int"){
								(yyval).label = (yyvsp[-3]).label;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " + " + (yyvsp[0]).label + ";\n";
							}else{
								variaveis.push_back("\tint "+temp);
								(yyval).label = (yyvsp[-3]).label;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (int) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " + " + temp + ";\n";
							}
						}else if(tipo == "float"){
							if((yyvsp[0]).tipo == "float"){
								(yyval).label = (yyvsp[-3]).label;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " + " + (yyvsp[0]).label + ";\n";
							}else{
								variaveis.push_back("\tfloat "+temp);
								(yyval).label = (yyvsp[-3]).label;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (float) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " + " + temp + ";\n";
							}
						}else if(tipo == "char"){
							if((yyvsp[0]).tipo == "char"){
								(yyval).label = (yyvsp[-3]).label;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " + " + (yyvsp[0]).label + ";\n";
							}else{
								variaveis.push_back("\tchar "+temp);
								(yyval).label = (yyvsp[-3]).label;
								(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (char) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " + " + temp + ";\n";
							}
						}
					}
				}
			}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1036 "sintatica.y" /* yacc.c:1646  */
    {
				string tipo = varContext[varContext.size()-1].varMap [(yyvsp[-3]).label].tipo;
				string temp = "TMP"+itos(i++);
				if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "bool" || tipo == "bool" || tipo == "string"){
					mensagens.push_back("operação matemática com bool ou string aqui não!");
				}else{
					if(tipo == "int"){
						if((yyvsp[0]).tipo == "int"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " - " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tint "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (int) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " - " + temp + ";\n";
						}
					}else if(tipo == "float"){
						if((yyvsp[0]).tipo == "float"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " - " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tfloat "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (float) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " - " + temp + ";\n";
						}
					}else if(tipo == "char"){
						if((yyvsp[0]).tipo == "char"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " - " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tchar "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (char) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " - " + temp + ";\n";
						}
					}
				}
			}
#line 2864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1073 "sintatica.y" /* yacc.c:1646  */
    {
				string tipo = varContext[varContext.size()-1].varMap [(yyvsp[-3]).label].tipo;
				string temp = "TMP"+itos(i++);
				if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "bool" || tipo == "bool" || tipo == "string"){
					mensagens.push_back("operação matemática com bool ou string aqui não!");
				}else{
					if(tipo == "int"){
						if((yyvsp[0]).tipo == "int"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " * " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tint "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (int) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " * " + temp + ";\n";
						}
					}else if(tipo == "float"){
						if((yyvsp[0]).tipo == "float"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " * " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tfloat "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (float) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " * " + temp + ";\n";
						}
					}else if(tipo == "char"){
						if((yyvsp[0]).tipo == "char"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " * " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tchar "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (char) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " * " + temp + ";\n";
						}
					}
				}
			}
#line 2905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1110 "sintatica.y" /* yacc.c:1646  */
    {
				string tipo = varContext[varContext.size()-1].varMap [(yyvsp[-3]).label].tipo;
				string temp = "TMP"+itos(i++);
				if((yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "bool" || tipo == "bool" || tipo == "string"){
					mensagens.push_back("operação matemática com bool ou string aqui não!");
				}else{
					if(tipo == "int"){
						if((yyvsp[0]).tipo == "int"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " / " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tint "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (int) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " / " + temp + ";\n";
						}
					}else if(tipo == "float"){
						if((yyvsp[0]).tipo == "float"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " / " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tfloat "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (float) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " / " + temp + ";\n";
						}
					}else if(tipo == "char"){
						if((yyvsp[0]).tipo == "char"){
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyval).label + " = " + (yyvsp[-3]).label + " / " + (yyvsp[0]).label + ";\n";
						}else{
							variaveis.push_back("\tchar "+temp);
							(yyval).label = (yyvsp[-3]).label;
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + temp + " = (char) " + (yyvsp[0]).label + ";\n\t" + (yyval).label + " = " + (yyvsp[-3]).label + " / " + temp + ";\n";
						}
					}
				}
			}
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1150 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo == "int"){
					(yyval).label = (yyvsp[-4]).label;
					(yyval).tipo = "int*";
					addVar((yyval).label, "", (yyval).tipo);
					matContext[varContext.size()-1].dim[(yyval).label].insert(matContext[varContext.size()-1].dim[(yyval).label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[(yyval).label].push_back((yyvsp[-1]).label);
					int j = 0;
					string size = "1";
					(yyval).traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[(yyval).label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						(yyval).traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[(yyval).label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					(yyval).traducao += "\t" + aux2 + " = " + aux + " * sizeof(int);\n";
					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + (yyval).traducao + "\t" + "int* " + (yyval).label +" = (int*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back((yyvsp[-4]).label);
			}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1178 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo == "int"){
					(yyval).label = (yyvsp[-4]).label;
					(yyval).tipo = "char*";
					addVar((yyval).label, "", (yyval).tipo);
					matContext[varContext.size()-1].dim[(yyval).label].insert(matContext[varContext.size()-1].dim[(yyval).label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[(yyval).label].push_back((yyvsp[-1]).label);
					int j = 0;
					string size = "1";
					(yyval).traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[(yyval).label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						(yyval).traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[(yyval).label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					(yyval).traducao += "\t" + aux2 + " = " + aux + " * sizeof(char);\n";
					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + (yyval).traducao + "\t" + "char* " + (yyval).label +" = (char*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back((yyvsp[-4]).label);
			}
#line 3010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1206 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo == "int"){
					(yyval).label = (yyvsp[-4]).label;
					(yyval).tipo = "float*";
					addVar((yyval).label, "", (yyval).tipo);
					matContext[varContext.size()-1].dim[(yyval).label].insert(matContext[varContext.size()-1].dim[(yyval).label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[(yyval).label].push_back((yyvsp[-1]).label);
					int j = 0;
					string size = "1";
					(yyval).traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[(yyval).label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						(yyval).traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[(yyval).label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					(yyval).traducao += "\t" + aux2 + " = " + aux + " * sizeof(float);\n";
					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + (yyval).traducao + "\t" + "float* " + (yyval).label +" = (float*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back((yyvsp[-4]).label);
			}
#line 3042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1234 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo == "int"){
					(yyval).label = (yyvsp[-4]).label;
					(yyval).tipo = "bool*";
					addVar((yyval).label, "", (yyval).tipo);
					matContext[varContext.size()-1].dim[(yyval).label].insert(matContext[varContext.size()-1].dim[(yyval).label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[(yyval).label].push_back((yyvsp[-1]).label);
					int j = 0;
					string size = "1";
					(yyval).traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[(yyval).label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						(yyval).traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[(yyval).label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					(yyval).traducao += "\t" + aux2 + " = " + aux + " * sizeof(int);\n";
					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + (yyval).traducao + "\t" + "int* " + (yyval).label +" = (int*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back((yyvsp[-4]).label);
			}
#line 3074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1262 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo == "int"){
					(yyval).label = (yyvsp[-4]).label;
					(yyval).tipo = "string*";
					addVar((yyval).label, "", (yyval).tipo);
					matContext[varContext.size()-1].dim[(yyval).label].insert(matContext[varContext.size()-1].dim[(yyval).label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[(yyval).label].push_back((yyvsp[-1]).label);
					int j = 0;
					string size = "1";
					(yyval).traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[(yyval).label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						(yyval).traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[(yyval).label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					(yyval).traducao += "\t" + aux2 + " = " + aux + " * sizeof(char*);\n";
					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + (yyval).traducao + "\t" + "char** " + (yyval).label +" = (char**) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back((yyvsp[-4]).label);
			}
#line 3106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1290 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-3]).tipo == "int"){
					(yyval).label = (yyvsp[-6]).label;
					(yyval).tipo = (yyvsp[0]).tipo;
					string tipo = "int";
					matTemp.push_back((yyvsp[-3]).label);
					if(matTemp.size() == matContext[varContext.size()-1].dim[(yyvsp[-6]).label].size()){
						string multiplier = "1";
						string index = "0";
						int j;
						string aux1, aux2, aux3, aux4;
						for(j=0; j<matContext[varContext.size()-1].dim[(yyvsp[-6]).label].size(); j++){
							aux1 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux1);
							(yyval).traducao += "\t" + aux1 + " = " + multiplier + ";\n";
							aux2 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux2);
							(yyval).traducao += "\t" + aux2 + " = " + aux1 + " * " + matTemp[j] + ";\n";
							aux3 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux3);
							(yyval).traducao += "\t" + aux3 + " = " + index + ";\n";
							aux4 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux4);
							(yyval).traducao += "\t" + aux4 + " = " + aux3 + " + " + aux2 + ";\n";
							index = aux4;
							multiplier = aux1 + " + " + matContext[varContext.size()-1].dim[(yyvsp[-6]).label][j];
						}
						(yyval).traducao = (yyvsp[0]).traducao + (yyvsp[-5]).traducao + (yyvsp[-3]).traducao + (yyval).traducao + "\t" + (yyvsp[-6]).label + "["+index+"] = " + (yyvsp[0]).label + ";\n";
					}else{
						mensagens.push_back("Dimensão paralela da matriz: "+(yyvsp[-6]).label);
					}
					matTemp.clear();
				}else{
					mensagens.push_back("quase na hora de apresentar e não to mais com criatividade pra mensagem de erro");
				}
			}
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1329 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo == "int"){
					(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao;
					matTemp.push_back((yyvsp[-1]).label);
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
			}
#line 3160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1338 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1344 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
				(yyval).traducao = "";
				(yyval).tipo = "int";
				addGlobalVar((yyvsp[0]).label, "", (yyval).tipo);
			}
#line 3179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1352 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[0]).tipo == "string"){
					mensagens.push_back("STRING pra INT? Vou nem comentar...");
				}
				(yyval).tipo = "int";
				(yyval).traducao = "";
				addGlobalVar((yyvsp[-2]).label, (yyvsp[0]).traducao , (yyval).tipo);
			}
#line 3192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1361 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
				(yyval).tipo = "float";
				addGlobalVar((yyvsp[0]).label, "", (yyval).tipo); //coloquei o valor como "" pq é só a declaração, mas depois tem que ver isso

			}
#line 3203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1368 "sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo == "string"){
					mensagens.push_back("STRING pra FLOAT? Vou nem comentar...");
				}
				(yyval).traducao = "";
				(yyval).tipo = "float";
				addGlobalVar((yyvsp[-2]).label, (yyvsp[0]).traducao, (yyval).tipo);

			}
#line 3217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1378 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
				(yyval).tipo = "char";
				addGlobalVar((yyvsp[0]).label, "", (yyval).tipo);
			}
#line 3227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1384 "sintatica.y" /* yacc.c:1646  */
    {
			if((yyvsp[0]).tipo == "string"){
					mensagens.push_back("STRING pra CHAR? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				(yyval).traducao="";
				(yyval).tipo = "char";
				addGlobalVar((yyvsp[-2]).label, (yyvsp[0]).traducao, (yyval).tipo);

			}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1395 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
				(yyval).tipo = "bool";
				addGlobalVar((yyvsp[0]).label, "", (yyval).tipo);

			}
#line 3253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1402 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			    (yyval).tipo = "bool";
			    addGlobalVar((yyvsp[-2]).label, (yyvsp[0]).traducao, (yyval).tipo);
			}
#line 3263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1408 "sintatica.y" /* yacc.c:1646  */
    {
				//checkDeclar($2.label);
				(yyval).label = "TMP" + itos(i++);
				(yyval).traducao = "";
				addGlobalVar((yyvsp[-2]).label, (yyvsp[0]).traducao, (yyval).tipo);

			}
#line 3275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1416 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = "";
				(yyval).tipo = "string";
				addGlobalVar((yyval).label, "", (yyval).tipo);
			}
#line 3286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1423 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[-2]).label;
				(yyval).tipo = "string";
				(yyval).traducao = "";
				addGlobalVar((yyval).label, (yyvsp[0]).traducao, (yyval).tipo);
				if((yyvsp[0]).tipo == "string"){
					if(strTemp[(yyvsp[0]).label] > 0){ 
						varContext[varContext.size()-1].varMap[(yyval).label].tamanho = strTemp[(yyvsp[-1]).label];
					}else{
						varContext[varContext.size()-1].varMap[(yyval).label].tamanho = varContext[varContext.size()-1].varMap[(yyvsp[-1]).label].tamanho;
					}
				}else{
					mensagens.push_back("Não tem conversão implícita pra string não, querido, usa (string) aí.");
				}
			}
#line 3306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1439 "sintatica.y" /* yacc.c:1646  */
    {
				if(!checkVar((yyvsp[-1]).label)){
					mensagens.push_back("Então... a variável é global mas precisa de um tipo né?! Troca lá a '" + (yyvsp[0]).label +"' por favor. :) ");
				}
			}
#line 3316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1447 "sintatica.y" /* yacc.c:1646  */
    {
				checkRelacionalType((yyvsp[-2]).tipo, (yyvsp[0]).tipo); //se forem tipos diferentes, daqui ele n passa e estoura o erro
				(yyval).label = "TMP" + itos(i++);
				(yyval).traducao = (yyval).traducao + (yyvsp[0]).traducao + "\t"+ (yyval).label + " = " + (yyvsp[-2]).label + (yyvsp[-1]).operacao +(yyvsp[0]).label + ";\n";
				(yyval).tipo = "bool";
				variaveis.push_back("\tint " + (yyval).label);


			}
#line 3330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1457 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "TMP" + itos(i++);
				(yyval).tipo = "bool";
				(yyval).traducao = (yyval).traducao + (yyvsp[0]).traducao + "\t"+(yyval).label + " = " + (yyvsp[-2]).label + (yyvsp[-1]).operacao +(yyvsp[0]).label + ";\n";
				variaveis.push_back("\tint " + (yyval).label);
			}
#line 3341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1464 "sintatica.y" /* yacc.c:1646  */
    {
				checkBooleanType((yyvsp[-2]).tipo, (yyvsp[0]).tipo);
				(yyval).label = "TMP" + itos(i++);
				(yyval).tipo = "bool";
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t"+ (yyval).label + " = " + (yyvsp[-2]).label + (yyvsp[-1]).operacao +(yyvsp[0]).label + ";\n";
				variaveis.push_back("\tint " + (yyval).label);
			}
#line 3353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1472 "sintatica.y" /* yacc.c:1646  */
    {
				checkNegacaoBool((yyvsp[0]).tipo);
				(yyval).label = "TMP" + itos(i++);
				(yyval).tipo = "bool";
				(yyval).traducao = (yyvsp[0]).traducao + "\t"+ (yyval).label + " = " + (yyvsp[-1]).operacao + (yyvsp[0]).label + ";\n";
				variaveis.push_back("\tint " + (yyval).label);
			}
#line 3365 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3369 "y.tab.c" /* yacc.c:1646  */
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
#line 1483 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

string itos(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

void yyerror(string msg)
{
/*	if(mensagens.size() > 0){
		for(vector<string>::iterator it = mensagens.begin(); it != mensagens.end(); ++it){
			cout<<*it<<endl;
		}*/
		//cout << ""<<msg << endl;
		exit (0);
	//}
}

void getErrors()
{
	if(mensagens.size() > 0){
		for(vector<string>::iterator it = mensagens.begin(); it != mensagens.end(); ++it){
			cout<<*it<<endl;
		}
		//cout << ""<<msg << endl;
		exit (0);
	}
}


string typeCompare(string t1, string t2){
	if(t1 == "int" && t2 == "int"){
		return "int";
	}else if(t1 == "float" && t2 == "float"){
		return "float";
	}else if(t1 == "float" && t2 == "int" || t1 == "int" && t2 == "float"){
		return "float";
	}else if((t1 == "char" && t2 == "int") || (t1 == "int" && t2 == "char")){
		return "int";
	}else if((t1 == "char" && t2 == "float") || (t1 == "float" && t2 == "char")){
		return "float";
	}else if(t1 == "char" && t2 == "char"){
		return "int";
	}
}

void addGlobalVar(string label, string valor, string tipo){
  varInfoIt = varInfo.find(label);
  //cout << label << " "<< valor <<" "<< tipo <<endl;

  //if(varInfoIt != varInfo.end()){ // Var||Const was declared previously
  //  atributos var = varInfoIt->second;
	//}
	//variaveisGlobais.push_back(" " + tipo + " " +label);
	string novoValor = valor.substr(0, valor.size()-1);
  	tempGlobal.push_back(novoValor);
  	//string inicializaGlobal  = "\t" + label +" = " +novoValor.substr(1, 5) + ";";
  	//tempGlobal.push_back(inicializaGlobal);
  	if(verificaVariavel(label,tipo) == 0){

		atributos v;
		v.label = label;
		v.valor = valor;
		//v.tipo = tipo;
		if(tipo == "string"){
			v.tamanho = 199;
		}else{
			v.tamanho = getTamanho(tipo);
		}
		varInfo[label] = v;
		if(tipo == "bool"){
			v.booleano = 1;
			v.tipo = "int";
		}else{
			v.booleano = 0;
			v.tipo = tipo;
		}
		varContext[0].varMap[label] = v;

	}

}


void addVar(string label, string valor, string tipo){
  varInfoIt = varInfo.find(label);
 	if(verificaVariavel(label, tipo) == 0){

		atributos v;
		v.label = label;
		v.valor = valor;
		//v.tipo = tipo;
		if(tipo == "string"){
			v.tamanho = 199;
		}else{
			v.tamanho = getTamanho(tipo);
		}
		varInfo[label] = v;
		if(tipo == "bool"){
			v.booleano = 1;
			v.tipo = "bool";
		}else{
			v.booleano = 0;
			v.tipo = tipo;
		}
		varContext[0].varMap[label] = v;

	}

}

int getTamanho(string tipo){

	if(tipo == "int"){
		return 4;
	}else if (tipo == "float"){
		return 4;
	}else if (tipo == "char"){
		return 1;
	}
	return 0;
}

atributos operacoes(struct atributos $$, struct atributos $1, string op, struct atributos $3){
	
	if($1.tipo == "string" || $3.tipo == "string"){
		mensagens.push_back("Operação inválida com STRING.");
	}
	
	$$.label = "TMP" + itos(i++);
	$$.tipo = typeCompare($1.tipo, $3.tipo); // int + float = float
	variaveis.push_back("\t" + $$.tipo + " " +$$.label);
	if($1.tipo == "int" && $$.tipo == "float"){
	   string aux = "TMP"+itos(i++); // aux = TMP30
	   //$$.traducao = $$.traducao + "\tfloat " + aux + " = " + $1.label+";\n"; // float TMP30 = TMP0
	   $$.traducao = $$.traducao + "\t" + aux + " = (float) " + $1.label+";\n"; // float TMP30 = TMP0
	   $1.label = aux; // TMP0 -> TMP30
	   $$.traducao = $$.traducao + $3.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		 variaveis.push_back("\t" + $$.tipo + " " +$1.label);

	}else if($3.tipo == "int" && $$.tipo == "float"){
	  string aux = "TMP"+itos(i++); // aux = TMP30
	  //$$.traducao = "\tfloat " + aux + " = " + $3.label+";\n" + $$.traducao; // float TMP30 = TMP0
	  $$.traducao = "\t" + aux + " = (float) " + $3.label+";\n" + $$.traducao;
	  $3.label = aux; // TMP0 -> TMP30
	  $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		 variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($$.tipo == "float" && $1.tipo == "char"){
		string aux = "TMP"+itos(i++); // aux = TMP30
        //$$.traducao = $$.traducao + "\tfloat " + aux + " = " + $1.label+";\n"; // float TMP30 = TMP0
        $$.traducao = $$.traducao + "\t " + aux + " = (float) " + $1.label+";\n";
	    $1.label = aux; // TMP0 -> TMP30
	    $$.traducao = $$.traducao + $3.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
			variaveis.push_back("\t" + $$.tipo + " " +$1.label);

	}else if($$.tipo == "float" && $3.tipo == "char"){
	  string aux = "TMP"+itos(i++); // aux = TMP30
	  //$$.traducao = "\tfloat " + aux + " = " + $3.label+";\n" + $$.traducao; // float TMP30 = TMP0
	  $$.traducao = "\t" + aux + " = (float) " + $3.label+";\n" + $$.traducao;
	  $3.label = aux; // TMP0 -> TMP30
	  $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($1.tipo == "char" && $3.tipo == "char"){
		string aux = "TMP"+itos(i++);
		$$.traducao = $1.traducao + $3.traducao;
	//	$$.traducao = $$.traducao + "\tint " + aux + " = " + $1.label + ";\n";
		$$.traducao = $$.traducao + "\t " + aux + " = (int) " + $1.label + ";\n";
		$1.label = aux;
		aux = "TMP"+itos(i++);
		$$.traducao = $$.traducao + "\tint " + aux + " = (int) " + $3.label + ";\n";
		$3.label = aux;
		$$.traducao = $$.traducao + "\tint " + $$.label + " = " + $1.label + op + $3.label + ";\n";
		variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($1.tipo == "char" && $3.tipo == "int"){
      string aux = "TMP"+itos(i++); // aux = TMP30
	  //$$.traducao = $$.traducao + "\tint " + aux + " = (int) " + $1.label+";\n"; // float TMP30 = TMP0
	  $$.traducao = $$.traducao + "\t" + aux + " = " + $1.label+";\n";
	  $1.label = aux; // TMP0 -> TMP30
	  $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($1.tipo == "int" && $3.tipo == "char"){
	  string aux = "TMP"+itos(i++); // aux = TMP30
	  $$.traducao = $$.traducao +"\tint " + aux + " = (int) " + $3.label+";\n"; // float TMP30 = TMP0
	  $3.label = aux; // TMP0 -> TMP30
	 // $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
     $$.traducao = $3.traducao + $$.traducao + "\t"+ $$.label + " = " + $1.label + op +$3.label + ";\n";
		 variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else{
	  //$$.traducao = $1.traducao + $3.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
  	  $$.traducao = $1.traducao + $3.traducao + "\t"+ $$.label + " = " + $1.label + op +$3.label + ";\n";

	}
	return $$;
}

atributos getVar(string label){
	for(int i = varContext.size() - 1; i>=0; i--){
		if(varContext[i].varMap.count(label)){
			return varContext[i].varMap[label];
		}
	}
}

//verifica se a variável ja foi criada antes
int checkVar(string label){
	for(int i = varContext.size() - 1; i>= 0; i--){
		if(varContext[i].varMap.count(label)){
			return 1;
		}
	}
	mensagens.push_back("XIIIIII! Dá uma olhada, porque acho que a variável '"+ label + "' não foi declarada! ");
	return 0;
	
}

void checkRelacionalType(string t1, string t2){
	if((t1 == "int" && t2 == "int") || (t1 == "float" && t2 == "float")){
		return;
	} else if ((t1 == "float" && t2 == "int") || (t1 == "int" && t2 == "float")){
		return;
	}else{
		//yyerror("Não dá pra comparar esses tipos que você colocou não. Troca lá");
		mensagens.push_back("Não dá pra comparar esses tipos que você colocou não. Troca lá");

	}
}

void checkBooleanType(string t1, string t2){
	if(t1 != "bool" || t2 != "bool"){
		//yyerror("Não dá para comparar, pois não é tipo booleano.");
		mensagens.push_back("Não dá para comparar, pois não é tipo booleano.");
	}else{
		return;
	}
}

void checkNegacaoBool(string t){
	if(t != "bool"){
		//yyerror("Não dá para fazer negação, pois a variável não é booleana");
		mensagens.push_back("Não dá para fazer negação, pois a variável não é booleana");
	}else{
		return;
	}
}

void declaraVariaveis(){
	for(std::vector<string>::iterator it = variaveis.begin(); it != variaveis.end(); ++it) {
    	cout<< *it << ";"<<endl;
	}
	cout << "" <<endl;

}

void declaraFunctions(){
	for(int i = stackFunction.size()-1; i>= 0; i--){
		cout << stackFunction[i].label  << ":"<< endl;
		cout << stackFunction[i].conteudo << endl;
	
	}
}

void declaraVariaveisGlobais(){
	for(std::vector<string>::iterator it = variaveisGlobais.begin(); it != variaveisGlobais.end(); ++it) {
    	cout<< *it << ";"<<endl;
	}
	cout << "" <<endl;

}

void atribuiTempsGlobais(){
	for(std::vector<string>::iterator it = tempGlobal.begin(); it != tempGlobal.end(); ++it) {
    	cout<< *it << ""<<endl;
	}
}

void pushContext(){


	contexto newContext;
	varContext.push_back(newContext);
	dim newc;
	matContext.push_back(newc);

}

void popContext(){
	varContext.pop_back();
}

int verificaVariavel(string label, string tipo){
	int i = varContext.size() - 1;
	
	if (varContext[i].varMap.count(label)) {
  		mensagens.push_back("Ih. Dá uma olhadinha lá, porque acho que a variável '"+label + "' já foi declarada antes.");
		return 1;
	}

	return 0;
}

contexto returnContexto(){
	cout<<"RETURN CONTEXTO" << endl;
	for(int i = varContext.size()-1; i>= 0; i--){
		//if(varContext[i].labelInicio != ""){
		//	return varContext[i];
		//}
	}
}

void defineLabel(string inicio, string fim){
	varContext[varContext.size()-1].labelInicio = inicio;
	varContext[varContext.size()-1].labelFim = fim;

}

string getLabel(){
	lbl++;	
	return "LBL" + itos(lbl);
} 

string getContinue(){
	return "LBL" + itos(lbl+1);
}

string getBreak(){
	int temp = lbl+2; 
	return "LBL" + itos(temp);
}

//empilha função
void pushFunction(string label, string content){
	funcao newfunction;
	newfunction.label = label;
	newfunction.conteudo = content;
	funcParam[label] = temparam;
	stackFunction.push_back(newfunction);
	temparam.clear();
}

//desempilha função
void popFunction(){
	stackFunction.pop_back();
}

//empilha parametros da função
void pushParameters(string label){
	if(!checkVar(label)){
		mensagens.push_back("Pelamor né. Essa variável aí da função veio de onde? Troca lá");
	}else{
		atributos var = getVar(label);	
		varStack.push_back(var);

	}
}

string popParameters(){
	string result = ""; 
	for(int i = varStack.size()-1; i>= 0; i--){
	//	if(checkVariableValue(varStack[i].label)){
			result += "\t " + varStack[i].label + " = " + varStack[i].valor + ";\n"; 
	//	}		
	}
	varStack.clear();
	return result;
}

int checkVariableValue(string label){
	atributos var = getVar(label);
	if(var.valor == ""){
		mensagens.push_back("EU VOU EXPOR ELA! Tu esqueceu de inicializar a variável '"+ label +"' ali ó. ");
		return 0;
	}
	return 1;
}

void freeAll(){
	int i;
	for(i=0; i<setMeFree.size(); i++){
		cout << "\tfree("+setMeFree[i]+");" << endl;
	}
}

