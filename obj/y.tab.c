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
     ID = 258,
     INTCONST = 259,
     CHARCONST = 260,
     KWD_INT = 261,
     KWD_CHAR = 262,
     KWD_VOID = 263,
     KWD_WHILE = 264,
     KWD_RETURN = 265,
     KWD_IF = 266,
     KWD_ELSE = 267,
     LSQ_BRKT = 268,
     RSQ_BRKT = 269,
     LCRLY_BRKT = 270,
     RCRLY_BRKT = 271,
     LPAREN = 272,
     RPAREN = 273,
     COMMA = 274,
     SEMICLN = 275,
     OPER_LTE = 276,
     OPER_LT = 277,
     OPER_DIV = 278,
     OPER_GT = 279,
     OPER_GTE = 280,
     OPER_EQ = 281,
     OPER_ASGN = 282,
     OPER_NEQ = 283,
     OPER_ADD = 284,
     OPER_SUB = 285,
     OPER_MUL = 286,
     ERROR = 287,
     ILLEGAL_TOK = 288,
     LOWER_THAN_ELSE = 289
   };
#endif
/* Tokens.  */
#define ID 258
#define INTCONST 259
#define CHARCONST 260
#define KWD_INT 261
#define KWD_CHAR 262
#define KWD_VOID 263
#define KWD_WHILE 264
#define KWD_RETURN 265
#define KWD_IF 266
#define KWD_ELSE 267
#define LSQ_BRKT 268
#define RSQ_BRKT 269
#define LCRLY_BRKT 270
#define RCRLY_BRKT 271
#define LPAREN 272
#define RPAREN 273
#define COMMA 274
#define SEMICLN 275
#define OPER_LTE 276
#define OPER_LT 277
#define OPER_DIV 278
#define OPER_GT 279
#define OPER_GTE 280
#define OPER_EQ 281
#define OPER_ASGN 282
#define OPER_NEQ 283
#define OPER_ADD 284
#define OPER_SUB 285
#define OPER_MUL 286
#define ERROR 287
#define ILLEGAL_TOK 288
#define LOWER_THAN_ELSE 289




/* Copy the first part of user declarations.  */
#line 2 "src/parser.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>

extern char currFunction[256];

extern int yylineno;
extern int yylex(void);

int yywarning(char *msg);
int yyerror(char *msg);

int callArgDepth = 0;

typedef struct treenode tree;
extern tree *ast;

/* nodeTypes refer to different types of internal and external nodes
  that can be part of the abstract syntax tree.
  */
enum nodeTypes {PROGRAM, DECLLIST, DECL, VARDECL, TYPESPEC, FUNDECL,
                FORMALDECLLIST, FORMALDECL, FUNBODY, LOCALDECLLIST,
                STATEMENTLIST, STATEMENT, COMPOUNDSTMT, ASSIGNSTMT,
                CONDSTMT, LOOPSTMT, RETURNSTMT, EXPRESSION, RELOP,
                ADDEXPR, ADDOP, TERM, MULOP, FACTOR, FUNCCALLEXPR,
                ARGLIST, INTEGER, IDENTIFIER, VAR, ARRAYDECL, CHAR,
                FUNCTYPENAME};

enum opType {ADD, SUB, MUL, DIV, LT, LTE, EQ, GTE, GT, NEQ};

/* NOTE: mC has two kinds of scopes for variables : local and global.
  Variables declared outside any function are considered globals,
    whereas variables (and parameters) declared inside a function foo
    are local to foo.
  You should update the scope variable whenever you are inside a production
    that matches function definition (funDecl production).
  The rationale is that you are entering that function, so all variables,
    arrays, and other functions should be within this scope.
  You should pass this variable whenever you are
    calling the ST_insert or ST_lookup functions.
  This variable should be updated to scope = ""
    to indicate global scope whenever funDecl finishes.
  Treat these hints as helpful directions only.
  You may implement all of the functions as you like
    and not adhere to my instructions.
  As long as the directory structure is correct and the file names are correct,
    we are okay with it.
  */
char* scope = "";

#define TYPE_ERROR (-1)

static char current_function[256] = "";
static int pending_func_index = -1;
static int pending_param_count = 0;

static int in_local_scope(void){
    return current_function[0] != '\0';
}

static int is_same_scope_entry(symEntry *entry){
    if (!entry) { return 0; }
    if (!in_local_scope()) { return (entry->scope == NULL || entry->scope[0] == '\0'); }
    return (entry->scope != NULL && strcmp(entry->scope, current_function) == 0);
}

static int insert_decl(char *id, int data_type, int symbol_type){
  int scope_flag = in_local_scope() ? 1 : 0;
  symEntry *existing = ST_lookup(id);

  if(existing && strcmp(existing->id, id) == 0 && is_same_scope_entry(existing)){
    yyerror("Symbol declared multiple times.");
    return -1;
  }

  return ST_insert(id, data_type, symbol_type, &scope_flag);
}

static symEntry* lookup_var(char *id){
  symEntry *entry = ST_lookup(id);
  if (!entry){
    if(callArgDepth == 0){ yyerror("Undeclared variable."); } // editted from prev version due to extra undeclared variable calls when testing.
    return NULL;
  }
  return entry;
}

static symEntry* lookup_func(char *id){
  symEntry *entry = ST_lookup(id);
  if (!entry || entry->symbol_type != FUNCTION){
    yyerror("Undefined function.");
    return NULL;
  }
  return entry;
}

static int id_for_ast(symEntry *entry){ return entry ? 0 : -1; }

static int combine_arithmetic_type(int lhs, int rhs){
  if(lhs == TYPE_ERROR || rhs == TYPE_ERROR){ return TYPE_ERROR; }
  if(lhs == rhs && lhs != VOID_TYPE) { return lhs; }
  return TYPE_ERROR;
}
static void set_expr(tree *n, int type, int scope, int val){
  n->type = type;
  n->scope = scope;
  n->val = val;
}

static int validate_func_call(symEntry *fn, tree *args){
  if (!fn) { return TYPE_ERROR; }

  int numArgsGiven = (args == NULL) ? 0 : args->numChildren;
  
  if(numArgsGiven < fn->size){
    yyerror("Too few arguments provided in function call.");
    return fn->data_type;
  }
  if(numArgsGiven > fn->size){
    yyerror("Too many arguments provided in function call.");
    return fn->data_type;
  }

  param *parameters = fn->params;
  for(int i = 0; i < numArgsGiven && parameters != NULL; i++){
    tree *arg = getChild(args, i);
    if (arg->type == TYPE_ERROR || arg->type != parameters->data_type){
      yyerror("Argument type mismatch in function call.");
      break;
    }
    parameters = parameters->next;
  }
  return fn->data_type;
  
}



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
#line 146 "src/parser.y"
{
    int value;
    struct treenode *node;
    char *strval;
}
/* Line 193 of yacc.c.  */
#line 311 "obj/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 324 "obj/y.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  112

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    23,
      26,    28,    30,    32,    37,    43,    45,    49,    52,    57,
      61,    66,    67,    70,    71,    74,    76,    78,    80,    82,
      84,    87,    91,    96,   102,   110,   116,   119,   123,   125,
     130,   132,   136,   138,   140,   142,   144,   146,   148,   150,
     154,   156,   158,   160,   164,   166,   168,   172,   174,   176,
     178,   180,   181,   187,   188,   193,   195
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    38,    -1,    37,    38,    -1,
      39,    -1,    42,    -1,    41,     3,    20,    -1,    41,     3,
      45,    20,    -1,    41,     3,    -1,     6,    -1,     7,    -1,
       8,    -1,    40,    17,    18,    46,    -1,    40,    17,    43,
      18,    46,    -1,    44,    -1,    43,    19,    44,    -1,    41,
       3,    -1,    41,     3,    13,    14,    -1,    13,     4,    14,
      -1,    15,    47,    48,    16,    -1,    -1,    39,    47,    -1,
      -1,    49,    48,    -1,    50,    -1,    51,    -1,    52,    -1,
      53,    -1,    54,    -1,    56,    20,    -1,    15,    48,    16,
      -1,    55,    27,    56,    20,    -1,    11,    17,    56,    18,
      49,    -1,    11,    17,    56,    18,    49,    12,    49,    -1,
       9,    17,    56,    18,    49,    -1,    10,    20,    -1,    10,
      56,    20,    -1,     3,    -1,     3,    13,    58,    14,    -1,
      58,    -1,    56,    57,    58,    -1,    21,    -1,    22,    -1,
      24,    -1,    25,    -1,    26,    -1,    28,    -1,    60,    -1,
      58,    59,    60,    -1,    29,    -1,    30,    -1,    62,    -1,
      60,    61,    62,    -1,    31,    -1,    23,    -1,    17,    56,
      18,    -1,    55,    -1,    63,    -1,     4,    -1,     5,    -1,
      -1,     3,    17,    64,    66,    18,    -1,    -1,     3,    17,
      65,    18,    -1,    56,    -1,    66,    19,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   184,   184,   193,   199,   208,   213,   220,   228,   247,
     270,   274,   278,   284,   300,   318,   323,   331,   341,   353,
     361,   370,   373,   382,   385,   393,   398,   403,   408,   413,
     418,   425,   432,   442,   448,   457,   465,   469,   476,   492,
     513,   519,   535,   539,   543,   547,   551,   555,   561,   567,
     584,   588,   594,   600,   620,   624,   630,   636,   642,   648,
     654,   662,   662,   674,   674,   686,   691
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTCONST", "CHARCONST", "KWD_INT",
  "KWD_CHAR", "KWD_VOID", "KWD_WHILE", "KWD_RETURN", "KWD_IF", "KWD_ELSE",
  "LSQ_BRKT", "RSQ_BRKT", "LCRLY_BRKT", "RCRLY_BRKT", "LPAREN", "RPAREN",
  "COMMA", "SEMICLN", "OPER_LTE", "OPER_LT", "OPER_DIV", "OPER_GT",
  "OPER_GTE", "OPER_EQ", "OPER_ASGN", "OPER_NEQ", "OPER_ADD", "OPER_SUB",
  "OPER_MUL", "ERROR", "ILLEGAL_TOK", "LOWER_THAN_ELSE", "$accept",
  "program", "declList", "decl", "varDecl", "funcTypeName",
  "typeSpecifier", "funDecl", "formalDeclList", "formalDecl", "arrayDecl",
  "funBody", "localDeclList", "statementList", "statement", "compoundStmt",
  "assignStmt", "condStmt", "loopStmt", "returnStmt", "var", "expression",
  "relop", "addExpr", "addop", "term", "mulop", "factor", "funCallExpr",
  "@1", "@2", "argList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      41,    41,    41,    42,    42,    43,    43,    44,    44,    45,
      46,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    50,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    64,    63,    65,    63,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     4,     2,
       1,     1,     1,     4,     5,     1,     3,     2,     4,     3,
       4,     0,     2,     0,     2,     1,     1,     1,     1,     1,
       2,     3,     4,     5,     7,     5,     2,     3,     1,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     0,     5,     0,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,    12,     0,     2,     3,     5,     0,     0,
       6,     1,     4,     0,     9,     0,     0,     0,    15,     0,
       7,     0,    21,    13,    17,     0,     0,     0,     8,    21,
       0,    23,     0,    14,    16,    19,    22,     0,    38,    59,
      60,     0,     0,     0,    23,     0,     0,    23,    25,    26,
      27,    28,    29,    57,     0,    40,    48,    52,    58,    18,
       0,    61,     0,    36,    57,     0,     0,     0,     0,    20,
      24,     0,    30,    42,    43,    44,    45,    46,    47,     0,
      50,    51,     0,    55,    54,     0,     0,     0,     0,     0,
      37,     0,    31,    56,     0,    41,    49,    53,    39,    65,
       0,    64,     0,     0,    32,    62,     0,    35,    33,    66,
       0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    17,    18,
      21,    23,    31,    46,    47,    48,    49,    50,    51,    52,
      64,    54,    79,    55,    82,    56,    85,    57,    58,    87,
      88,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int8 yypact[] =
{
     114,   -94,   -94,   -94,     5,   114,   -94,   -94,    -3,    21,
     -94,   -94,   -94,    34,     6,    14,    41,    99,   -94,    45,
     -94,    49,   114,   -94,    80,    14,   114,    83,   -94,   114,
      55,    28,    88,   -94,   -94,   -94,   -94,     6,    71,   -94,
     -94,    89,     3,    93,    28,    31,    98,    28,   -94,   -94,
     -94,   -94,   -94,   100,    61,    94,    44,   -94,   -94,   -94,
      31,   110,    31,   -94,   -94,    70,    31,   113,    29,   -94,
     -94,    31,   -94,   -94,   -94,   -94,   -94,   -94,   -94,    31,
     -94,   -94,    31,   -94,   -94,    31,    -2,    31,   112,    38,
     -94,    52,   -94,   -94,    79,    94,    44,   -94,   -94,    87,
     107,   -94,    28,    28,   -94,   -94,    31,   -94,   119,    87,
      28,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   127,    39,   -94,   -11,   -94,   -94,   108,
     -94,   111,   104,    72,   -93,   -94,   -94,   -94,   -94,   -94,
     -31,   -41,   -94,   -57,   -94,    53,   -94,    54,   -94,   -94,
     -94,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -64
static const yytype_int8 yytable[] =
{
      53,    65,    16,    86,    68,    11,    38,    39,    40,   107,
     108,    30,    98,    53,    13,    16,    53,   111,    30,    19,
      45,    89,    95,    63,    14,    91,    20,    80,    81,    22,
      94,    38,    39,    40,    38,    39,    40,    41,    42,    43,
       1,     2,     3,    44,    24,    45,    99,    93,    45,    27,
      73,    74,    15,    75,    76,    77,   102,    78,    37,    73,
      74,    29,    75,    76,    77,   109,    78,    83,    29,    28,
     103,    53,    53,    73,    74,    84,    75,    76,    77,    53,
      78,    72,    73,    74,    60,    75,    76,    77,    61,    78,
      90,    73,    74,    32,    75,    76,    77,    35,    78,   104,
      73,    74,    59,    75,    76,    77,    62,    78,    73,    74,
      66,    75,    76,    77,    69,    78,    67,    25,    26,    70,
       1,     2,     3,    80,    81,   105,   106,    71,   -63,    92,
     101,   110,    12,    36,    34,    96,    33,     0,     0,    97
};

static const yytype_int8 yycheck[] =
{
      31,    42,    13,    60,    45,     0,     3,     4,     5,   102,
     103,    22,    14,    44,    17,    26,    47,   110,    29,    13,
      17,    62,    79,    20,     3,    66,    20,    29,    30,    15,
      71,     3,     4,     5,     3,     4,     5,     9,    10,    11,
       6,     7,     8,    15,     3,    17,    87,    18,    17,     4,
      21,    22,    18,    24,    25,    26,    18,    28,     3,    21,
      22,    22,    24,    25,    26,   106,    28,    23,    29,    20,
      18,   102,   103,    21,    22,    31,    24,    25,    26,   110,
      28,    20,    21,    22,    13,    24,    25,    26,    17,    28,
      20,    21,    22,    13,    24,    25,    26,    14,    28,    20,
      21,    22,    14,    24,    25,    26,    17,    28,    21,    22,
      17,    24,    25,    26,    16,    28,    44,    18,    19,    47,
       6,     7,     8,    29,    30,    18,    19,    27,    18,    16,
      18,    12,     5,    29,    26,    82,    25,    -1,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    36,    37,    38,    39,    40,    41,
      42,     0,    38,    17,     3,    18,    41,    43,    44,    13,
      20,    45,    15,    46,     3,    18,    19,     4,    20,    39,
      41,    47,    13,    46,    44,    14,    47,     3,     3,     4,
       5,     9,    10,    11,    15,    17,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    58,    60,    62,    63,    14,
      13,    17,    17,    20,    55,    56,    17,    48,    56,    16,
      48,    27,    20,    21,    22,    24,    25,    26,    28,    57,
      29,    30,    59,    23,    31,    61,    58,    64,    65,    56,
      20,    56,    16,    18,    56,    58,    60,    62,    14,    56,
      66,    18,    18,    18,    20,    18,    19,    49,    49,    56,
      12,    49
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
#line 185 "src/parser.y"
    {
                    tree *progNode = maketree(PROGRAM);
                    addChild(progNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = progNode;
                    ast = progNode;
                 }
    break;

  case 3:
#line 194 "src/parser.y"
    {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declListNode;
                 }
    break;

  case 4:
#line 200 "src/parser.y"
    {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[(1) - (2)].node));
                    addChild(declListNode, (yyvsp[(2) - (2)].node));
                    (yyval.node) = declListNode;
                 }
    break;

  case 5:
#line 209 "src/parser.y"
    {
                    (yyval.node) = maketree(DECL);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 6:
#line 214 "src/parser.y"
    {
                    (yyval.node) = maketree(DECL);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 7:
#line 221 "src/parser.y"
    {
                    tree *varDeclNode = maketree(VARDECL);
                    int idx = insert_decl((yyvsp[(2) - (3)].strval), (yyvsp[(1) - (3)].node)->val, SCALAR);
                    addChild(varDeclNode, (yyvsp[(1) - (3)].node));
                    addChild(varDeclNode, maketreeWithVal(IDENTIFIER, idx));
                    (yyval.node) = varDeclNode;
                 }
    break;

  case 8:
#line 229 "src/parser.y"
    {
                    tree *varDeclNode = maketree(VARDECL);
                    int idx = insert_decl((yyvsp[(2) - (4)].strval), (yyvsp[(1) - (4)].node)->val, ARRAY);

                    if((yyvsp[(3) - (4)].node)->val == 0){ yyerror("Array variable declared with size of zero."); }

                    addChild(varDeclNode, (yyvsp[(1) - (4)].node));
                    addChild(varDeclNode, maketreeWithVal(IDENTIFIER, idx));
                    addChild(varDeclNode, (yyvsp[(3) - (4)].node));
                    (yyval.node) = varDeclNode;

                    symEntry *arr = ST_lookup((yyvsp[(2) - (4)].strval));
                    if (arr && arr->symbol_type == ARRAY && is_same_scope_entry(arr)){
                      arr->size = (yyvsp[(3) - (4)].node)->val;
                    }
                 }
    break;

  case 9:
#line 248 "src/parser.y"
    {
                    int idx = insert_decl((yyvsp[(2) - (2)].strval), (yyvsp[(1) - (2)].node)->val, FUNCTION);

                    strncpy(current_function, (yyvsp[(2) - (2)].strval), sizeof(current_function)-1);
                    current_function[sizeof(current_function)-1] = '\0';
                    strncpy(currFunction, current_function, sizeof(currFunction)-1);
                    currFunction[sizeof(currFunction)-1] = '\0';
                    scope = current_function;

                    pending_func_index = idx;
                    pending_param_count = 0;
                    working_list_head = NULL;
                    working_list_end = NULL;

                    new_scope();

                    (yyval.node) = maketree(FUNCTYPENAME);
                    addChild((yyval.node), (yyvsp[(1) - (2)].node));
                    addChild((yyval.node), maketreeWithVal(IDENTIFIER, idx));
                 }
    break;

  case 10:
#line 271 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(TYPESPEC, INT_TYPE);
                 }
    break;

  case 11:
#line 275 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(TYPESPEC, CHAR_TYPE);
                 }
    break;

  case 12:
#line 279 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(TYPESPEC, VOID_TYPE);
                 }
    break;

  case 13:
#line 285 "src/parser.y"
    {
                    tree *funDeclNode = maketree(FUNDECL);
                    
                    addChild(funDeclNode, (yyvsp[(1) - (4)].node));
                    addChild(funDeclNode, (yyvsp[(4) - (4)].node));

                    connect_params(pending_func_index, 0);
                    up_scope();

                    current_function[0] = '\0';
                    currFunction[0] = '\0';
                    scope = "";

                    (yyval.node) = funDeclNode;
                 }
    break;

  case 14:
#line 301 "src/parser.y"
    {
                    tree *funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, (yyvsp[(1) - (5)].node));
                    addChild(funDeclNode, (yyvsp[(3) - (5)].node));
                    addChild(funDeclNode, (yyvsp[(5) - (5)].node));

                    connect_params(pending_func_index, pending_param_count);
                    up_scope();

                    current_function[0] = '\0';
                    currFunction[0] = '\0';
                    scope = "";

                    (yyval.node) = funDeclNode;
                 }
    break;

  case 15:
#line 319 "src/parser.y"
    {
                    (yyval.node) = maketree(FORMALDECLLIST);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                 }
    break;

  case 16:
#line 324 "src/parser.y"
    {
                    (yyval.node) = maketree(FORMALDECLLIST);
                    addChild((yyval.node), (yyvsp[(1) - (3)].node));
                    addChild((yyval.node), (yyvsp[(3) - (3)].node));
                 }
    break;

  case 17:
#line 332 "src/parser.y"
    {
                    int idx = insert_decl((yyvsp[(2) - (2)].strval), (yyvsp[(1) - (2)].node)->val, SCALAR);
                    pending_param_count++;
                    add_param((yyvsp[(1) - (2)].node)->val, SCALAR);

                    (yyval.node) = maketree(FORMALDECL);
                    addChild((yyval.node), (yyvsp[(1) - (2)].node));
                    addChild((yyval.node), maketreeWithVal(IDENTIFIER, idx));
                 }
    break;

  case 18:
#line 342 "src/parser.y"
    {
                    int idx = insert_decl((yyvsp[(2) - (4)].strval), (yyvsp[(1) - (4)].node)->val, ARRAY);
                    pending_param_count++;
                    add_param((yyvsp[(1) - (4)].node)->val, ARRAY);

                    (yyval.node) = maketree(FORMALDECL);
                    addChild((yyval.node), (yyvsp[(1) - (4)].node));
                    addChild((yyval.node), maketreeWithVal(IDENTIFIER, idx));
                 }
    break;

  case 19:
#line 354 "src/parser.y"
    {
                    (yyval.node) = maketree(ARRAYDECL);
                    (yyval.node)->val = (yyvsp[(2) - (3)].value);
                    addChild((yyval.node), maketreeWithVal(INTEGER, (yyvsp[(2) - (3)].value)));
                 }
    break;

  case 20:
#line 362 "src/parser.y"
    {
                    (yyval.node) = maketree(FUNBODY);
                    addChild((yyval.node), (yyvsp[(2) - (4)].node));
                    addChild((yyval.node), (yyvsp[(3) - (4)].node));
                 }
    break;

  case 21:
#line 370 "src/parser.y"
    {
                    (yyval.node) = maketree(LOCALDECLLIST);
                  }
    break;

  case 22:
#line 374 "src/parser.y"
    {
                    (yyval.node) = maketree(LOCALDECLLIST);
                    addChild((yyval.node), (yyvsp[(1) - (2)].node));
                    addChild((yyval.node), (yyvsp[(2) - (2)].node));
                  }
    break;

  case 23:
#line 382 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENTLIST);
                  }
    break;

  case 24:
#line 386 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENTLIST);
                    addChild((yyval.node), (yyvsp[(1) - (2)].node));
                    addChild((yyval.node), (yyvsp[(2) - (2)].node));
                  }
    break;

  case 25:
#line 394 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENT);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 26:
#line 399 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENT);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 27:
#line 404 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENT);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 28:
#line 409 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENT);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 29:
#line 414 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENT);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 30:
#line 419 "src/parser.y"
    {
                    (yyval.node) = maketree(STATEMENT);
                    addChild((yyval.node), (yyvsp[(1) - (2)].node));
                  }
    break;

  case 31:
#line 426 "src/parser.y"
    {
                    (yyval.node) = maketree(COMPOUNDSTMT);
                    addChild((yyval.node), (yyvsp[(2) - (3)].node));
                  }
    break;

  case 32:
#line 433 "src/parser.y"
    {
                    (yyval.node) = maketree(ASSIGNSTMT);
                    addChild((yyval.node), (yyvsp[(1) - (4)].node));
                    addChild((yyval.node), (yyvsp[(3) - (4)].node));

                    if((yyvsp[(1) - (4)].node)->type == TYPE_ERROR || (yyvsp[(3) - (4)].node)->type == TYPE_ERROR || (yyvsp[(1) - (4)].node)->type != (yyvsp[(3) - (4)].node)->type){ yyerror("Type mismatch in assignment."); }
                  }
    break;

  case 33:
#line 443 "src/parser.y"
    {
                    (yyval.node) = maketree(CONDSTMT);
                    addChild((yyval.node), (yyvsp[(3) - (5)].node));
                    addChild((yyval.node), (yyvsp[(5) - (5)].node));
                  }
    break;

  case 34:
#line 449 "src/parser.y"
    {
                    (yyval.node) = maketree(CONDSTMT);
                    addChild((yyval.node), (yyvsp[(3) - (7)].node));
                    addChild((yyval.node), (yyvsp[(5) - (7)].node));
                    addChild((yyval.node), (yyvsp[(7) - (7)].node));
                  }
    break;

  case 35:
#line 458 "src/parser.y"
    {
                    (yyval.node) = maketree(LOOPSTMT);
                    addChild((yyval.node), (yyvsp[(3) - (5)].node));
                    addChild((yyval.node), (yyvsp[(5) - (5)].node));
                  }
    break;

  case 36:
#line 466 "src/parser.y"
    {
                    (yyval.node) = maketree(RETURNSTMT);
                  }
    break;

  case 37:
#line 470 "src/parser.y"
    {
                    (yyval.node) = maketree(RETURNSTMT);
                    addChild((yyval.node), (yyvsp[(2) - (3)].node));
                  }
    break;

  case 38:
#line 477 "src/parser.y"
    {
                    symEntry *entry = lookup_var((yyvsp[(1) - (1)].strval));

                    (yyval.node) = maketree(VAR);
                    addChild((yyval.node), maketreeWithVal(IDENTIFIER, id_for_ast(entry)));

                    if(entry){
                      (yyval.node)->type = entry->data_type;
                      (yyval.node)->sym_type = entry->symbol_type;
                    }
                    else{
                      (yyval.node)->type = TYPE_ERROR;
                      (yyval.node)->sym_type = SCALAR;
                    }
                  }
    break;

  case 39:
#line 493 "src/parser.y"
    {
                    symEntry *entry = lookup_var((yyvsp[(1) - (4)].strval));

                    (yyval.node) = maketree(VAR);
                    addChild((yyval.node), maketreeWithVal(IDENTIFIER, id_for_ast(entry)));
                    addChild((yyval.node), (yyvsp[(3) - (4)].node));

                    if(!entry){ (yyval.node)->type = TYPE_ERROR; (yyval.node)->sym_type = SCALAR; }
                    else{
                      if(entry->symbol_type != ARRAY){ yyerror("Non-array identifier used as an array."); }
                      if((yyvsp[(3) - (4)].node)->type != INT_TYPE){ yyerror("Array indexed using non-integer expression."); }
                      if(entry->symbol_type == ARRAY && entry->size > 0 && (yyvsp[(3) - (4)].node)->scope == 1){
                        if((yyvsp[(3) - (4)].node)->val < 0 || (yyvsp[(3) - (4)].node)->val >= entry->size){ yyerror("Statically sized array indexed with constant, out-of-bounds expression."); }
                      }
                      (yyval.node)->type = entry->data_type;
                      (yyval.node)->sym_type = SCALAR;
                    }
                  }
    break;

  case 40:
#line 514 "src/parser.y"
    {
                    (yyval.node) = maketree(EXPRESSION);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                    set_expr((yyval.node), (yyvsp[(1) - (1)].node)->type, (yyvsp[(1) - (1)].node)->scope, (yyvsp[(1) - (1)].node)->val);
                  }
    break;

  case 41:
#line 520 "src/parser.y"
    {
                    (yyval.node) = maketree(EXPRESSION);
                    addChild((yyval.node), (yyvsp[(1) - (3)].node));
                    addChild((yyval.node), (yyvsp[(2) - (3)].node));
                    addChild((yyval.node), (yyvsp[(3) - (3)].node));

                    if((yyvsp[(1) - (3)].node)->type == TYPE_ERROR || (yyvsp[(3) - (3)].node)->type == TYPE_ERROR || (yyvsp[(1) - (3)].node)->type == VOID_TYPE || (yyvsp[(3) - (3)].node)->type == VOID_TYPE || (yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
                      set_expr((yyval.node), TYPE_ERROR, 0, 0);
                    }
                    else{
                      set_expr((yyval.node), INT_TYPE, 0 ,0);
                    }
                  }
    break;

  case 42:
#line 536 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(RELOP, LTE);
                  }
    break;

  case 43:
#line 540 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(RELOP, LT);
                  }
    break;

  case 44:
#line 544 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(RELOP, GT);
                  }
    break;

  case 45:
#line 548 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(RELOP, GTE);
                  }
    break;

  case 46:
#line 552 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(RELOP, EQ);
                  }
    break;

  case 47:
#line 556 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(RELOP, NEQ);
                  }
    break;

  case 48:
#line 562 "src/parser.y"
    {
                    (yyval.node) = maketree(ADDEXPR);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                    set_expr((yyval.node), (yyvsp[(1) - (1)].node)->type, (yyvsp[(1) - (1)].node)->scope, (yyvsp[(1) - (1)].node)->val);
                  }
    break;

  case 49:
#line 568 "src/parser.y"
    { 
                    (yyval.node) = maketree(ADDEXPR);
                    addChild((yyval.node), (yyvsp[(1) - (3)].node));
                    addChild((yyval.node), (yyvsp[(2) - (3)].node));
                    addChild((yyval.node), (yyvsp[(3) - (3)].node));

                    int typ = combine_arithmetic_type((yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type);
                    if(typ == TYPE_ERROR){ set_expr((yyval.node), TYPE_ERROR, 0, 0); }
                    else if((yyvsp[(1) - (3)].node)->scope == 1 && (yyvsp[(3) - (3)].node)->scope == 1){ 
                      int vl = ((yyvsp[(2) - (3)].node)->val == ADD) ? ((yyvsp[(1) - (3)].node)->val + (yyvsp[(3) - (3)].node)->val) : ((yyvsp[(1) - (3)].node)->val - (yyvsp[(3) - (3)].node)->val); 
                      set_expr((yyval.node), typ, 1, vl);
                    }
                    else{ set_expr((yyval.node), typ, 0, 0); }
                  }
    break;

  case 50:
#line 585 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(ADDOP, ADD);
                  }
    break;

  case 51:
#line 589 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(ADDOP, SUB);
                  }
    break;

  case 52:
#line 595 "src/parser.y"
    {
                    (yyval.node) = maketree(TERM);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                    set_expr((yyval.node), (yyvsp[(1) - (1)].node)->type, (yyvsp[(1) - (1)].node)->scope, (yyvsp[(1) - (1)].node)->val);
                  }
    break;

  case 53:
#line 601 "src/parser.y"
    {
                    (yyval.node) = maketree(TERM);
                    addChild((yyval.node), (yyvsp[(1) - (3)].node));
                    addChild((yyval.node), (yyvsp[(2) - (3)].node));
                    addChild((yyval.node), (yyvsp[(3) - (3)].node));

                    int typ = combine_arithmetic_type((yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type);
                    if(typ == TYPE_ERROR){ set_expr((yyval.node), TYPE_ERROR, 0, 0); }
                    else if((yyvsp[(1) - (3)].node)->scope == 1 && (yyvsp[(3) - (3)].node)->scope == 1){
                      if((yyvsp[(2) - (3)].node)->val == MUL){ set_expr((yyval.node), typ, 1, (yyvsp[(1) - (3)].node)->val * (yyvsp[(3) - (3)].node)->val); }
                      else{
                        if((yyvsp[(3) - (3)].node)->val == 0){ set_expr((yyval.node), typ, 0, 0); }
                        else { set_expr((yyval.node), typ, 1, (yyvsp[(1) - (3)].node)->val / (yyvsp[(3) - (3)].node)->val); }
                      }
                    }
                    else{ set_expr((yyval.node), typ, 0, 0);}
                  }
    break;

  case 54:
#line 621 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(MULOP, MUL);
                  }
    break;

  case 55:
#line 625 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(MULOP, DIV);
                  }
    break;

  case 56:
#line 631 "src/parser.y"
    {
                    (yyval.node) = maketree(FACTOR);
                    addChild((yyval.node), (yyvsp[(2) - (3)].node));
                    set_expr((yyval.node), (yyvsp[(2) - (3)].node)->type, (yyvsp[(2) - (3)].node)->scope, (yyvsp[(2) - (3)].node)->val);
                  }
    break;

  case 57:
#line 637 "src/parser.y"
    {
                    (yyval.node) = maketree(FACTOR);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                    set_expr((yyval.node), (yyvsp[(1) - (1)].node)->type, 0, 0);
                  }
    break;

  case 58:
#line 643 "src/parser.y"
    {
                    (yyval.node) = maketree(FACTOR);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                    set_expr((yyval.node), (yyvsp[(1) - (1)].node)->type, 0, 0);
                  }
    break;

  case 59:
#line 649 "src/parser.y"
    {
                    (yyval.node) = maketree(FACTOR);
                    addChild((yyval.node), maketreeWithVal(INTEGER, (yyvsp[(1) - (1)].value)));
                    set_expr((yyval.node), INT_TYPE, 1, (yyvsp[(1) - (1)].value));
                  }
    break;

  case 60:
#line 655 "src/parser.y"
    {
                    (yyval.node) = maketree(FACTOR);
                    addChild((yyval.node), maketreeWithVal(CHAR, (yyvsp[(1) - (1)].value)));
                    set_expr((yyval.node), CHAR_TYPE, 1, (yyvsp[(1) - (1)].value));
                  }
    break;

  case 61:
#line 662 "src/parser.y"
    { callArgDepth++; }
    break;

  case 62:
#line 663 "src/parser.y"
    {
                    callArgDepth--;

                    symEntry *fn = lookup_func((yyvsp[(1) - (5)].strval));

                    (yyval.node) = maketree(FUNCCALLEXPR);
                    addChild((yyval.node), maketreeWithVal(IDENTIFIER, id_for_ast(fn)));
                    addChild((yyval.node), (yyvsp[(4) - (5)].node));

                    (yyval.node)->type = validate_func_call(fn, (yyvsp[(4) - (5)].node));
                  }
    break;

  case 63:
#line 674 "src/parser.y"
    { callArgDepth++; }
    break;

  case 64:
#line 675 "src/parser.y"
    {
                    callArgDepth--;
                    symEntry *fn = lookup_func((yyvsp[(1) - (4)].strval));

                    (yyval.node) = maketree(FUNCCALLEXPR);
                    addChild((yyval.node), maketreeWithVal(IDENTIFIER, id_for_ast(fn)));

                    (yyval.node)->type = validate_func_call(fn, NULL);
                  }
    break;

  case 65:
#line 687 "src/parser.y"
    {
                    (yyval.node) = maketree(ARGLIST);
                    addChild((yyval.node), (yyvsp[(1) - (1)].node));
                  }
    break;

  case 66:
#line 692 "src/parser.y"
    {
                    (yyval.node) = (yyvsp[(1) - (3)].node);
                    addChild((yyval.node), (yyvsp[(3) - (3)].node));
                  }
    break;


/* Line 1267 of yacc.c.  */
#line 2282 "obj/y.tab.c"
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


#line 698 "src/parser.y"
 
int yywarning(char *msg){
  printf("warning: line %d: %s\n", yylineno, msg);
  return 0;
}

int yyerror(char * msg){
  printf("error: line %d: %s\n", yylineno, msg);
  return 0;
}

