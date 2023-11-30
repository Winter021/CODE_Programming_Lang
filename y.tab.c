
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "yacc.y"
 
   /*INCLUDE STATEMENTS*/
   #include <stdio.h> 
   #include <stdlib.h> 
   #include <string.h> 
   #include <stdarg.h> 
   #include "header.h" 

   /*FUNCTION DECLARATIONS*/
   parseNode *createOpNode(int optr, int nops, ...); 
   parseNode *createOpNode2(int optr, int typ1, int nops, ...);
   parseNode *createVarNode(int i); 
   parseNode  createVarNode2(int i, int typ); 
   parseNode *createConNode(double i);
   parseNode *createConStrNode(char* i);

   void putFunc(int index, parseNode *start);
   void getArguments(parseNode *p);
   void addClsData(int index, parseNode *ptr);
   void addClsMethod(int index, parseNode *ptr);
   void addMethPara(int index, int methodindex, parseNode *ptr);
   void copyObj(int objindex, int clsindex);
   void clsDataInitialize(int objindex, int clsindex, parseNode *ptr);

   void printTheList(parseNode *ptr);

   void cleanSpace(parseNode *ptr);

   double executeTheNode(parseNode *ptr);

   int yylex(void); 
   void yyerror(char *s); 


   /*TABLES & CNT, INDEX VARIABLES*/
   int symTabList_index = 0;                 //INDEX IN LIST OF SYMBOLTABLES(FUNCTION LEVEL SYMBOL TABLE). 
   tabNode sym_Tab[100][1000];               //LIST OF SYMBOL TABLES.

   classNode class_Tab[100];                 //LIST OF CLASSES, EACH HAVING THEIR OWN OBJECTS STORED.
   objNode tempClsStruct[100];               //TEMP STORAGE OF CLASS STRUCTURES.

   int tpl_index = 0;                        //INDEX IN TEMP FUNCTION'S PARAMETER STORAGE..
   parseNode tempParaList[20];               //TEMPORARY FUNCTION'S PARAMETER STORAGE.
   funcNode func_Table[1000];                //FUNCTION TABLE TO STORE FUNCTIONS.

   int arg_cnt = 0;                          //MAINTAINING ARGUMENT CNT OF FUNCTION CALL.
   int tal_index;	                           //INDEX IN FUNCTION'S ARGUMENT LIST IN 'tempArgList'.
   double tempArgList[10];                   //STORING FUNCTION ARGUMENTS TEMPORARITLY.
   
   int itr = 0;                              //


/* Line 189 of yacc.c  */
#line 126 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     DOUBLE = 259,
     STRING = 260,
     INT = 261,
     FLOAT = 262,
     ID = 263,
     UNTIL = 264,
     LOOP = 265,
     CHECK = 266,
     PRINT = 267,
     PRINTF = 268,
     WRITE = 269,
     CLSEND = 270,
     FUNEND = 271,
     MAIN = 272,
     RETURN = 273,
     FUNCALL = 274,
     CLSCONSTR = 275,
     CLSDATA = 276,
     CLSDATAINI = 277,
     OBJFUNCALL = 278,
     INPUT = 279,
     CHECKX = 280,
     OTHERWISE = 281,
     OR = 282,
     AND = 283,
     NE = 284,
     EQ = 285,
     LE = 286,
     GE = 287,
     EP = 288,
     EM = 289,
     EMUL = 290,
     EDIV = 291,
     UP = 292,
     UM = 293,
     UMINUS = 294
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define DOUBLE 259
#define STRING 260
#define INT 261
#define FLOAT 262
#define ID 263
#define UNTIL 264
#define LOOP 265
#define CHECK 266
#define PRINT 267
#define PRINTF 268
#define WRITE 269
#define CLSEND 270
#define FUNEND 271
#define MAIN 272
#define RETURN 273
#define FUNCALL 274
#define CLSCONSTR 275
#define CLSDATA 276
#define CLSDATAINI 277
#define OBJFUNCALL 278
#define INPUT 279
#define CHECKX 280
#define OTHERWISE 281
#define OR 282
#define AND 283
#define NE 284
#define EQ 285
#define LE 286
#define GE 287
#define EP 288
#define EM 289
#define EMUL 290
#define EDIV 291
#define UP 292
#define UM 293
#define UMINUS 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 57 "yacc.y"
                                     //"YYLVAL" CAN BE ONE OF THESE.
   int iVal; 
   char* strVal;
   double dVal;
   
   int symInd;
   parseNode *nPtr; 



/* Line 214 of yacc.c  */
#line 251 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 263 "y.tab.c"

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
# if YYENABLE_NLS
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   582

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  246

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    51,     2,     2,     2,
      46,    47,    41,    39,    50,    40,    54,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      28,    53,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      25,    26,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    43,    44,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    11,    19,    22,    24,    32,    33,
      38,    43,    46,    49,    50,    53,    55,    62,    63,    68,
      73,    77,    81,    82,    85,    87,    96,    97,   102,   107,
     110,   113,   114,   117,   118,   120,   123,   129,   135,   139,
     143,   148,   153,   158,   163,   168,   174,   182,   188,   196,
     202,   206,   210,   218,   227,   236,   240,   244,   246,   249,
     251,   253,   259,   262,   266,   270,   274,   278,   282,   286,
     290,   294,   298,   302,   306,   310,   314,   317,   320,   323,
     326,   328,   329,   339,   341,   343,   344,   350,   354,   356,
     357,   359,   363,   367,   369,   373,   375,   377,   378,   384,
     390,   394,   398,   402,   406,   408
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    -1,    62,    15,    59,    16,    57,    58,
      -1,    17,    46,    47,    48,    68,    82,    49,    -1,    60,
      59,    -1,    60,    -1,     8,    19,    61,    48,    68,    82,
      49,    -1,    -1,    61,    50,     6,     8,    -1,    61,    50,
       7,     8,    -1,     6,     8,    -1,     7,     8,    -1,    -1,
      63,    62,    -1,    63,    -1,     8,    48,    64,    65,    49,
      51,    -1,    -1,    64,     6,     8,    52,    -1,    64,     7,
       8,    52,    -1,     6,     8,    52,    -1,     7,     8,    52,
      -1,    -1,    65,    66,    -1,    66,    -1,     8,    19,    67,
      48,    68,    82,    49,    52,    -1,    -1,    67,    50,     6,
       8,    -1,    67,    50,     7,     8,    -1,     6,     8,    -1,
       7,     8,    -1,    -1,    68,    69,    -1,    -1,    52,    -1,
      71,    52,    -1,     6,     8,    53,    71,    52,    -1,     7,
       8,    53,    71,    52,    -1,     6,     8,    52,    -1,     7,
       8,    52,    -1,     8,    53,    71,    52,    -1,     8,    35,
      71,    52,    -1,     8,    36,    71,    52,    -1,     8,    37,
      71,    52,    -1,     8,    38,    71,    52,    -1,     9,    46,
      71,    47,    69,    -1,    10,    46,    69,    69,    71,    47,
      69,    -1,    11,    46,    71,    47,    69,    -1,    11,    46,
      71,    47,    69,    26,    69,    -1,    14,    46,     8,    47,
      52,    -1,    14,     8,    52,    -1,    12,    77,    52,    -1,
      13,    46,     5,    50,    71,    47,    52,    -1,     8,    53,
      20,     8,    46,    79,    47,    52,    -1,     8,    54,     8,
      54,     8,    53,    71,    52,    -1,    24,    81,    52,    -1,
      48,    70,    49,    -1,    69,    -1,    70,    69,    -1,    73,
      -1,     8,    -1,     8,    54,     8,    54,     8,    -1,    40,
      71,    -1,    71,    39,    71,    -1,    71,    40,    71,    -1,
      71,    41,    71,    -1,    71,    42,    71,    -1,    71,    28,
      71,    -1,    71,    27,    71,    -1,    71,    34,    71,    -1,
      71,    33,    71,    -1,    71,    31,    71,    -1,    71,    32,
      71,    -1,    71,    30,    71,    -1,    71,    29,    71,    -1,
      46,    71,    47,    -1,     8,    43,    -1,     8,    44,    -1,
      43,     8,    -1,    44,     8,    -1,    74,    -1,    -1,     8,
      54,     8,    54,     8,    46,    72,    76,    47,    -1,     3,
      -1,     4,    -1,    -1,     8,    46,    75,    76,    47,    -1,
      71,    50,    76,    -1,    71,    -1,    -1,    78,    -1,    46,
      78,    47,    -1,    78,    50,    71,    -1,    71,    -1,    78,
      50,     5,    -1,     5,    -1,    80,    -1,    -1,    80,    50,
       8,    53,    73,    -1,    80,    50,     8,    53,     8,    -1,
       8,    53,    73,    -1,     8,    53,     8,    -1,    46,    81,
      47,    -1,    81,    50,     8,    -1,     8,    -1,    18,    71,
      52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    94,    98,   102,   103,   107,   108,   112,
     113,   114,   115,   116,   120,   121,   125,   126,   130,   131,
     132,   133,   134,   138,   139,   143,   144,   148,   149,   150,
     151,   152,   156,   157,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   188,   189,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   215,   219,   220,   224,   224,   228,   229,   230,
     234,   235,   239,   240,   241,   242,   245,   246,   250,   251,
     252,   253,   257,   258,   259,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DOUBLE", "STRING", "INT",
  "FLOAT", "ID", "UNTIL", "LOOP", "CHECK", "PRINT", "PRINTF", "WRITE",
  "CLSEND", "FUNEND", "MAIN", "RETURN", "FUNCALL", "CLSCONSTR", "CLSDATA",
  "CLSDATAINI", "OBJFUNCALL", "INPUT", "CHECKX", "OTHERWISE", "'>'", "'<'",
  "OR", "AND", "NE", "EQ", "LE", "GE", "EP", "EM", "EMUL", "EDIV", "'+'",
  "'-'", "'*'", "'/'", "UP", "UM", "UMINUS", "'('", "')'", "'{'", "'}'",
  "','", "'$'", "';'", "'='", "'.'", "$accept", "program", "$@1", "main",
  "funclist", "func", "paralist", "classlist", "class", "datalist",
  "methodlist", "method", "methparalist", "body", "stmt", "stmts", "expr",
  "$@2", "num", "funccall", "$@3", "arglist", "printlist1", "printlist",
  "inilist1", "inilist", "inputlist", "return", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    62,    60,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,    43,
      45,    42,    47,   292,   293,   294,    40,    41,   123,   125,
      44,    36,    59,    61,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    57,    56,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    71,    73,    73,    75,    74,    76,    76,    76,
      77,    77,    78,    78,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     7,     2,     1,     7,     0,     4,
       4,     2,     2,     0,     2,     1,     6,     0,     4,     4,
       3,     3,     0,     2,     1,     8,     0,     4,     4,     2,
       2,     0,     2,     0,     1,     2,     5,     5,     3,     3,
       4,     4,     4,     4,     4,     5,     7,     5,     7,     5,
       3,     3,     7,     8,     8,     3,     3,     1,     2,     1,
       1,     5,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       1,     0,     9,     1,     1,     0,     5,     3,     1,     0,
       1,     3,     3,     1,     3,     1,     1,     0,     5,     5,
       3,     3,     3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,     0,     0,     0,    15,    22,     1,     8,    14,     0,
       0,    26,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    24,    13,     2,     5,    20,    21,     0,     0,    31,
       0,    23,     0,     0,     0,     0,    18,    19,     0,     0,
       0,    16,    11,    12,    33,     0,     0,     3,    29,    30,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    32,     0,
      59,    80,     0,     9,    10,     0,     0,    27,    28,     0,
       0,     0,     0,     0,     0,    76,    77,    85,     0,     0,
       0,     0,     0,    95,    60,     0,    93,     0,    90,     0,
       0,     0,     0,   104,     0,     0,    62,    78,    79,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     7,    33,     0,    38,     0,
      39,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,    93,     0,    51,     0,     0,    50,
       0,   105,     0,     0,    55,    75,    56,    58,    68,    67,
      74,    73,    71,    72,    70,    69,    63,    64,    65,    66,
       0,    25,     0,     0,    41,    42,    43,    44,    88,     0,
       0,    40,     0,     0,     0,     0,     0,    91,    94,    92,
       0,     0,   102,   103,     0,    36,    37,    89,    86,    97,
      61,    45,     0,    47,     0,     0,    49,     4,    87,     0,
       0,    96,    81,     0,     0,     0,    61,     0,     0,     0,
       0,    89,     0,    46,    48,    52,   101,   100,    53,     0,
       0,    54,     0,    82,    99,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    35,    47,    13,    14,    34,     3,     4,    11,
      20,    21,    40,    52,    78,   121,    79,   231,    80,    81,
     146,   189,   107,   108,   220,   221,   115,    82
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -222
static const yytype_int16 yypact[] =
{
       7,   -29,    32,    22,     7,    47,  -222,    35,  -222,    40,
      68,    77,    98,    91,    35,    67,    71,   135,   136,   128,
      -4,  -222,    64,  -222,  -222,  -222,  -222,   101,   103,    97,
     106,  -222,   141,   150,    39,   142,  -222,  -222,   152,   153,
      51,  -222,  -222,  -222,  -222,   123,   116,  -222,  -222,  -222,
    -222,   129,   102,   155,   157,   119,   102,   159,   160,  -222,
    -222,   161,   166,   512,   138,   143,   145,     6,   146,    -2,
     216,     5,   216,   180,   186,   216,   192,  -222,  -222,   236,
    -222,  -222,   148,  -222,  -222,   162,   158,  -222,  -222,    42,
      85,   216,   216,   216,   216,  -222,  -222,  -222,    78,   200,
     216,   192,   216,  -222,   -26,    88,   540,   171,   164,   206,
     175,   221,   252,  -222,     5,    50,  -222,  -222,  -222,   420,
    -222,   169,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,  -222,  -222,  -222,   178,  -222,   216,
    -222,   216,   268,   284,   300,   316,   216,   223,   332,   179,
     441,   192,   462,   226,   420,    28,  -222,   182,   187,  -222,
     194,  -222,    30,   231,  -222,  -222,  -222,  -222,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   110,  -222,  -222,
     102,  -222,   348,   364,  -222,  -222,  -222,  -222,   396,   195,
     197,  -222,   237,   192,   216,   192,   193,  -222,  -222,   540,
     216,   196,  -222,  -222,   201,  -222,  -222,   216,  -222,   238,
     -30,  -222,   483,   225,   241,   504,  -222,  -222,  -222,   199,
     207,   203,  -222,   216,   192,   192,   209,   205,    26,   219,
     250,   216,   380,  -222,  -222,  -222,  -222,  -222,  -222,   208,
     227,  -222,    65,  -222,  -222,  -222
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,  -222,   258,  -222,  -222,   269,  -222,  -222,
    -222,   267,  -222,   -48,   -54,  -222,   -67,  -222,  -221,  -222,
    -222,  -195,  -222,   184,  -222,  -222,   176,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     106,    86,    56,   112,    19,   116,   110,   237,   119,    59,
      60,   103,   218,   113,   104,     1,   222,    95,    96,     5,
      97,   245,   120,   223,   142,   143,   144,   145,   153,    59,
      60,   148,     6,   150,   236,   152,   240,     7,   154,   130,
     131,   132,   133,    12,   111,    30,    72,   151,    15,    73,
      74,   114,   105,     9,    10,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   167,    59,    60,
      32,    33,   182,   244,   183,   197,    16,   202,   157,   188,
     163,    59,    60,    17,    18,    19,   104,    44,   180,    45,
     199,    59,    60,   103,   138,   139,   104,   194,   147,    50,
     163,    51,   164,    38,    39,    59,    60,    23,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    22,    72,    25,
      70,    73,    74,    26,    75,   204,    71,   212,    72,    53,
      54,    73,    74,   215,    75,    57,    58,   140,   141,   211,
     188,   213,    72,    27,    28,    73,    74,    29,    75,    42,
      76,   132,   133,    36,    77,    37,   232,    41,    43,    46,
      48,    49,    55,    83,   188,    84,    85,    87,    88,    89,
     233,   234,    59,    60,    90,    61,    62,    63,    64,    65,
      66,    67,    68,    69,   100,    59,    60,   198,   117,   101,
     104,   102,   109,    71,   118,    59,    60,   135,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   137,   149,    72,
     136,   158,    73,    74,   157,    75,    71,    76,   166,    59,
      60,    77,    72,   156,   104,    73,    74,   159,    75,   160,
     181,   190,    72,   192,   196,    73,    74,   200,    75,   203,
      76,   201,   208,   209,    77,   210,   219,   214,   216,   226,
     217,   225,   228,   230,   229,   222,    72,   235,   239,    73,
      74,   242,    75,   122,   123,   124,   125,   126,   127,   128,
     129,   238,    24,     8,   243,   130,   131,   132,   133,   122,
     123,   124,   125,   126,   127,   128,   129,    31,   134,   155,
     162,   130,   131,   132,   133,   122,   123,   124,   125,   126,
     127,   128,   129,     0,   161,     0,     0,   130,   131,   132,
     133,   122,   123,   124,   125,   126,   127,   128,   129,     0,
     184,     0,     0,   130,   131,   132,   133,   122,   123,   124,
     125,   126,   127,   128,   129,     0,   185,     0,     0,   130,
     131,   132,   133,   122,   123,   124,   125,   126,   127,   128,
     129,     0,   186,     0,     0,   130,   131,   132,   133,   122,
     123,   124,   125,   126,   127,   128,   129,     0,   187,     0,
       0,   130,   131,   132,   133,   122,   123,   124,   125,   126,
     127,   128,   129,     0,   191,     0,     0,   130,   131,   132,
     133,   122,   123,   124,   125,   126,   127,   128,   129,     0,
     205,     0,     0,   130,   131,   132,   133,   122,   123,   124,
     125,   126,   127,   128,   129,     0,   206,     0,     0,   130,
     131,   132,   133,   122,   123,   124,   125,   126,   127,   128,
     129,     0,   241,     0,     0,   130,   131,   132,   133,     0,
       0,     0,     0,     0,     0,     0,   207,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,   130,
     131,   132,   133,     0,     0,     0,     0,   165,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
     130,   131,   132,   133,     0,     0,     0,     0,   193,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,   130,   131,   132,   133,     0,     0,     0,     0,   195,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,   130,   131,   132,   133,     0,     0,     0,     0,
     224,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,   130,   131,   132,   133,    91,    92,    93,
      94,   227,     0,     0,     0,    95,    96,     0,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,   130,
     131,   132,   133
};

static const yytype_int16 yycheck[] =
{
      67,    56,    50,    70,     8,    72,     8,   228,    75,     3,
       4,     5,   207,     8,     8,     8,    46,    43,    44,    48,
      46,   242,    76,    53,    91,    92,    93,    94,    54,     3,
       4,    98,     0,   100,     8,   102,   231,    15,   105,    39,
      40,    41,    42,     8,    46,    49,    40,   101,     8,    43,
      44,    46,    46,     6,     7,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   121,     3,     4,
       6,     7,   139,     8,   141,    47,     8,    47,    50,   146,
      50,     3,     4,     6,     7,     8,     8,    48,   136,    50,
     157,     3,     4,     5,    52,    53,     8,   151,    20,    48,
      50,    50,    52,     6,     7,     3,     4,    16,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    19,    40,    52,
      18,    43,    44,    52,    46,   180,    24,   194,    40,     6,
       7,    43,    44,   200,    46,     6,     7,    52,    53,   193,
     207,   195,    40,     8,     8,    43,    44,    19,    46,     8,
      48,    41,    42,    52,    52,    52,   223,    51,     8,    17,
       8,     8,    46,     8,   231,     8,    47,     8,     8,     8,
     224,   225,     3,     4,     8,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    46,     3,     4,     5,     8,    46,
       8,    46,    46,    24,     8,     3,     4,    49,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    49,     8,    40,
      48,     5,    43,    44,    50,    46,    24,    48,    49,     3,
       4,    52,    40,    52,     8,    43,    44,    52,    46,     8,
      52,     8,    40,    54,     8,    43,    44,    50,    46,     8,
      48,    47,    47,    46,    52,     8,     8,    54,    52,     8,
      49,    26,    53,    50,    47,    46,    40,    52,     8,    43,
      44,    53,    46,    27,    28,    29,    30,    31,    32,    33,
      34,    52,    14,     4,    47,    39,    40,    41,    42,    27,
      28,    29,    30,    31,    32,    33,    34,    20,    52,   105,
     114,    39,    40,    41,    42,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    52,    -1,    -1,    39,    40,    41,
      42,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      52,    -1,    -1,    39,    40,    41,    42,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    52,    -1,    -1,    39,
      40,    41,    42,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    52,    -1,    -1,    39,    40,    41,    42,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    52,    -1,
      -1,    39,    40,    41,    42,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    52,    -1,    -1,    39,    40,    41,
      42,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      52,    -1,    -1,    39,    40,    41,    42,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    52,    -1,    -1,    39,
      40,    41,    42,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    52,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    47,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    47,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    47,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    35,    36,    37,
      38,    47,    -1,    -1,    -1,    43,    44,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,
      40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    56,    62,    63,    48,     0,    15,    62,     6,
       7,    64,     8,    59,    60,     8,     8,     6,     7,     8,
      65,    66,    19,    16,    59,    52,    52,     8,     8,    19,
      49,    66,     6,     7,    61,    57,    52,    52,     6,     7,
      67,    51,     8,     8,    48,    50,    17,    58,     8,     8,
      48,    50,    68,     6,     7,    46,    68,     6,     7,     3,
       4,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      18,    24,    40,    43,    44,    46,    48,    52,    69,    71,
      73,    74,    82,     8,     8,    47,    82,     8,     8,     8,
       8,    35,    36,    37,    38,    43,    44,    46,    53,    54,
      46,    46,    46,     5,     8,    46,    71,    77,    78,    46,
       8,    46,    71,     8,    46,    81,    71,     8,     8,    71,
      69,    70,    27,    28,    29,    30,    31,    32,    33,    34,
      39,    40,    41,    42,    52,    49,    48,    49,    52,    53,
      52,    53,    71,    71,    71,    71,    75,    20,    71,     8,
      71,    69,    71,    54,    71,    78,    52,    50,     5,    52,
       8,    52,    81,    50,    52,    47,    49,    69,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      68,    52,    71,    71,    52,    52,    52,    52,    71,    76,
       8,    52,    54,    47,    69,    47,     8,    47,     5,    71,
      50,    47,    47,     8,    82,    52,    52,    50,    47,    46,
       8,    69,    71,    69,    54,    71,    52,    49,    76,     8,
      79,    80,    46,    53,    47,    26,     8,    47,    53,    47,
      50,    72,    71,    69,    69,    52,     8,    73,    52,     8,
      76,    52,    53,    47,     8,    73
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
# if YYLTYPE_IS_TRIVIAL
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 94 "yacc.y"
    {symTabList_index = 0;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 94 "yacc.y"
    { ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 98 "yacc.y"
    { executeTheNode((yyvsp[(5) - (7)].nPtr)); cleanSpace((yyvsp[(5) - (7)].nPtr)); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 102 "yacc.y"
    { ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 103 "yacc.y"
    { ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 107 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, (yyvsp[(5) - (7)].nPtr), (yyvsp[(6) - (7)].nPtr)); putFunc((yyvsp[(1) - (7)].symInd), (yyval.nPtr)); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 108 "yacc.y"
    { ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 112 "yacc.y"
    { tempParaList[tpl_index] = createVarNode2((yyvsp[(4) - (4)].symInd), 0); tpl_index++; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 113 "yacc.y"
    { tempParaList[tpl_index] = createVarNode2((yyvsp[(4) - (4)].symInd), 1); tpl_index++; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 114 "yacc.y"
    { tempParaList[tpl_index] = createVarNode2((yyvsp[(2) - (2)].symInd), 0); tpl_index++; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 115 "yacc.y"
    { tempParaList[tpl_index] = createVarNode2((yyvsp[(2) - (2)].symInd), 1); tpl_index++; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 116 "yacc.y"
    { ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 120 "yacc.y"
    { ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 121 "yacc.y"
    { ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 125 "yacc.y"
    { itr = 0; addClsData((yyvsp[(1) - (6)].symInd), (yyvsp[(3) - (6)].nPtr)); addClsMethod((yyvsp[(1) - (6)].symInd), (yyvsp[(4) - (6)].nPtr)); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 126 "yacc.y"
    { (yyval.nPtr)= NULL;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 130 "yacc.y"
    { (yyval.nPtr) = createOpNode2('^', 0, 2, (yyvsp[(1) - (4)].nPtr), createVarNode((yyvsp[(3) - (4)].symInd))); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 131 "yacc.y"
    { (yyval.nPtr) = createOpNode2('^', 1, 2, (yyvsp[(1) - (4)].nPtr), createVarNode((yyvsp[(3) - (4)].symInd))); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 132 "yacc.y"
    { (yyval.nPtr) = createOpNode2('^', 0, 2, NULL, createVarNode((yyvsp[(2) - (3)].symInd))); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 133 "yacc.y"
    { (yyval.nPtr) = createOpNode2('^', 1, 2, NULL, createVarNode((yyvsp[(2) - (3)].symInd))); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 134 "yacc.y"
    { ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 138 "yacc.y"
    { (yyval.nPtr) = createOpNode('^', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 139 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 143 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 4, createVarNode((yyvsp[(1) - (8)].symInd)), (yyvsp[(3) - (8)].nPtr), (yyvsp[(5) - (8)].nPtr), (yyvsp[(6) - (8)].nPtr)); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 144 "yacc.y"
    { (yyval.nPtr) =  NULL; }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 148 "yacc.y"
    { (yyval.nPtr) = createOpNode2('!', 0, 2, (yyvsp[(1) - (4)].nPtr), createVarNode((yyvsp[(4) - (4)].symInd))); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 149 "yacc.y"
    { (yyval.nPtr) = createOpNode2('!', 1, 2, (yyvsp[(1) - (4)].nPtr), createVarNode((yyvsp[(4) - (4)].symInd))); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 150 "yacc.y"
    { (yyval.nPtr) = createOpNode2('!', 0, 2, NULL, createVarNode((yyvsp[(2) - (2)].symInd))); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 151 "yacc.y"
    { (yyval.nPtr) = createOpNode2('!', 1, 2, NULL, createVarNode((yyvsp[(2) - (2)].symInd))); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 152 "yacc.y"
    { (yyval.nPtr) = NULL; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 156 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 157 "yacc.y"
    { (yyval.nPtr) = NULL; }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 162 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, NULL, NULL); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 163 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 164 "yacc.y"
    { (yyval.nPtr) = createOpNode2('=', 0, 2, createVarNode((yyvsp[(2) - (5)].symInd)), (yyvsp[(4) - (5)].nPtr)); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 165 "yacc.y"
    { (yyval.nPtr) = createOpNode2('=', 1, 2, createVarNode((yyvsp[(2) - (5)].symInd)), (yyvsp[(4) - (5)].nPtr)); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 166 "yacc.y"
    { (yyval.nPtr) = createOpNode2('=', 0, 1, createVarNode((yyvsp[(2) - (3)].symInd))); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 167 "yacc.y"
    { (yyval.nPtr) = createOpNode2('=', 1, 1, createVarNode((yyvsp[(2) - (3)].symInd))); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 168 "yacc.y"
    { (yyval.nPtr) = createOpNode('=', 3, createVarNode((yyvsp[(1) - (4)].symInd)), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 169 "yacc.y"
    { (yyval.nPtr) = createOpNode(EP, 2, createVarNode((yyvsp[(1) - (4)].symInd)), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 170 "yacc.y"
    { (yyval.nPtr) = createOpNode(EM, 2, createVarNode((yyvsp[(1) - (4)].symInd)), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 171 "yacc.y"
    { (yyval.nPtr) = createOpNode(EMUL, 2, createVarNode((yyvsp[(1) - (4)].symInd)), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 172 "yacc.y"
    { (yyval.nPtr) = createOpNode(EDIV, 2, createVarNode((yyvsp[(1) - (4)].symInd)), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 173 "yacc.y"
    { (yyval.nPtr) = createOpNode(UNTIL, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 174 "yacc.y"
    { (yyval.nPtr) = createOpNode(LOOP, 4, (yyvsp[(3) - (7)].nPtr), (yyvsp[(4) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 175 "yacc.y"
    { (yyval.nPtr) = createOpNode(CHECK, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 176 "yacc.y"
    { (yyval.nPtr) = createOpNode(CHECK, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 177 "yacc.y"
    { (yyval.nPtr) = createOpNode(WRITE, 1, createVarNode((yyvsp[(3) - (5)].symInd))); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 178 "yacc.y"
    { (yyval.nPtr) = createOpNode(WRITE, 1, createVarNode((yyvsp[(2) - (3)].symInd))); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 179 "yacc.y"
    { (yyval.nPtr) = createOpNode(PRINT, 1, (yyvsp[(2) - (3)].nPtr)); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 180 "yacc.y"
    { (yyval.nPtr) = createOpNode(PRINTF, 2, createConStrNode((yyvsp[(3) - (7)].strVal)), (yyvsp[(5) - (7)].nPtr));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 181 "yacc.y"
    { (yyval.nPtr) = createOpNode(CLSCONSTR, 3, createVarNode((yyvsp[(1) - (8)].symInd)), createVarNode((yyvsp[(4) - (8)].symInd)), (yyvsp[(6) - (8)].nPtr)); copyObj((yyvsp[(1) - (8)].symInd), (yyvsp[(4) - (8)].symInd)); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 182 "yacc.y"
    { (yyval.nPtr) = createOpNode(CLSDATAINI, 4, createVarNode((yyvsp[(1) - (8)].symInd)),createVarNode((yyvsp[(3) - (8)].symInd)),createVarNode((yyvsp[(5) - (8)].symInd)),(yyvsp[(7) - (8)].nPtr)); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 183 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 184 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 188 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 189 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 193 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 194 "yacc.y"
    { (yyval.nPtr) = createVarNode((yyvsp[(1) - (1)].symInd)); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 195 "yacc.y"
    { (yyval.nPtr) = createOpNode(CLSDATA, 3, createVarNode((yyvsp[(1) - (5)].symInd)), createVarNode((yyvsp[(3) - (5)].symInd)), createVarNode((yyvsp[(5) - (5)].symInd))); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 196 "yacc.y"
    { (yyval.nPtr) = createOpNode(UMINUS, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 197 "yacc.y"
    { (yyval.nPtr) = createOpNode('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 198 "yacc.y"
    { (yyval.nPtr) = createOpNode('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 199 "yacc.y"
    { (yyval.nPtr) = createOpNode('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 200 "yacc.y"
    { (yyval.nPtr) = createOpNode('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 201 "yacc.y"
    { (yyval.nPtr) = createOpNode('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 202 "yacc.y"
    { (yyval.nPtr) = createOpNode('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 203 "yacc.y"
    { (yyval.nPtr) = createOpNode(GE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 204 "yacc.y"
    { (yyval.nPtr) = createOpNode(LE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 205 "yacc.y"
    { (yyval.nPtr) = createOpNode(NE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 206 "yacc.y"
    { (yyval.nPtr) = createOpNode(EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 207 "yacc.y"
    { (yyval.nPtr) = createOpNode(AND, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 208 "yacc.y"
    { (yyval.nPtr) = createOpNode(OR, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 209 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 210 "yacc.y"
    { (yyval.nPtr) = createOpNode(UP,1, createVarNode((yyvsp[(1) - (2)].symInd))); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 211 "yacc.y"
    { (yyval.nPtr) = createOpNode(UM,1, createVarNode((yyvsp[(1) - (2)].symInd))); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 212 "yacc.y"
    { (yyval.nPtr) = createOpNode(UP,1, createVarNode((yyvsp[(2) - (2)].symInd))); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 213 "yacc.y"
    { (yyval.nPtr) = createOpNode(UM,1, createVarNode((yyvsp[(2) - (2)].symInd))); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 214 "yacc.y"
    { ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 215 "yacc.y"
    {arg_cnt=0;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 215 "yacc.y"
    { (yyval.nPtr) = createOpNode(OBJFUNCALL, 4, createVarNode((yyvsp[(1) - (9)].symInd)), createVarNode((yyvsp[(3) - (9)].symInd)), createVarNode((yyvsp[(5) - (9)].symInd)), (yyvsp[(8) - (9)].nPtr)); }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 219 "yacc.y"
    { (yyval.nPtr) = createConNode((yyvsp[(1) - (1)].iVal)); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 220 "yacc.y"
    { (yyval.nPtr) = createConNode((yyvsp[(1) - (1)].dVal)); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 224 "yacc.y"
    { arg_cnt=0;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 224 "yacc.y"
    { (yyval.nPtr) = createOpNode(FUNCALL, 2, createVarNode((yyvsp[(1) - (5)].symInd)), (yyvsp[(4) - (5)].nPtr)); }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 228 "yacc.y"
    { arg_cnt++; (yyval.nPtr) = createOpNode(';', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 229 "yacc.y"
    { arg_cnt++; (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 230 "yacc.y"
    { ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 234 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 235 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 239 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 240 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, NULL, (yyvsp[(1) - (1)].nPtr)); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 241 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, (yyvsp[(1) - (3)].nPtr), createConStrNode((yyvsp[(3) - (3)].strVal))); }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 242 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 2, NULL,createConStrNode((yyvsp[(1) - (1)].strVal))); }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 245 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 246 "yacc.y"
    { (yyval.nPtr) = NULL; }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 250 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 3, (yyvsp[(1) - (5)].nPtr), createVarNode((yyvsp[(3) - (5)].symInd)), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 251 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 3, (yyvsp[(1) - (5)].nPtr), createVarNode((yyvsp[(3) - (5)].symInd)), createVarNode((yyvsp[(5) - (5)].symInd))); }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 252 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 3, NULL, createVarNode((yyvsp[(1) - (3)].symInd)), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 253 "yacc.y"
    { (yyval.nPtr) = createOpNode(';', 3, NULL, createVarNode((yyvsp[(1) - (3)].symInd)), createVarNode((yyvsp[(3) - (3)].symInd))); }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 257 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 258 "yacc.y"
    { (yyval.nPtr) = createOpNode(INPUT, 2, (yyvsp[(1) - (3)].nPtr), createVarNode((yyvsp[(3) - (3)].symInd))); }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 259 "yacc.y"
    { (yyval.nPtr) = createOpNode(INPUT, 2, NULL, createVarNode((yyvsp[(1) - (1)].symInd))); }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 263 "yacc.y"
    { (yyval.nPtr) = createOpNode(RETURN, 1, (yyvsp[(2) - (3)].nPtr)); }
    break;



/* Line 1455 of yacc.c  */
#line 2459 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 266 "yacc.y"


/*SUBROUTINES FOR YACC FILE*/

/*CREATE A PARSE NODE OF TYPE 'OPERATION', SAVE THE OPERATOR & OPERANDS AND RETURN THE POINTER*/
parseNode *createOpNode(int oper, int nops, ...) { 
   va_list ap; 
   parseNode *ptr; 

   ptr = malloc(sizeof(parseNode)); ptr->opr.operands = malloc(nops * sizeof(parseNode)); 

   ptr->type = oprType;          //NODE TYPE: OPERATION.
   ptr->opr.optr = oper;         //OPERATOR TYPE.
   ptr->opr.nops = nops;         //# OF OPERANDS.

   //STORE THE OPERANDS.
   va_start(ap, nops); 
   for (int i = 0; i < nops; i++) {
      ptr->opr.operands[i] = va_arg(ap, parseNode*); 
   }
   va_end(ap);

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'OPERATION', SAVE THE OPERATOR & OPERANDS AND RETURN THE POINTER*/
parseNode *createOpNode2(int oper,int typ1, int nops, ...) { 
   va_list ap; 
   parseNode *ptr; 

   ptr = malloc(sizeof(parseNode)); ptr->opr.operands = malloc(nops * sizeof(parseNode)); 

   ptr->type = oprType;          //NODE TYPE IS OPERATION.
   ptr->opr.optr = oper;         //OPERATOR TYPE.
   ptr->opr.nops = nops;         //# OF OPERANDS.
   ptr->opr.type = typ1; 

   //STORE THE OPERANDS.
   va_start(ap, nops); 
   for (int i = 0; i < nops; i++) {
      ptr->opr.operands[i] = va_arg(ap, parseNode*); 
   }
   va_end(ap);

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'VARIABLE', SAVE THE INDEX OF THE VARIABLE AND RETURN THE POINTER*/
parseNode *createVarNode(int i) { 
   parseNode *ptr; 

   ptr = malloc(sizeof(parseNode)); 

   ptr->type = varType;          //NODE TYPE: VARIABLE.
   ptr->var.index = i;           //INDEX OF THE VARIABLE IN SYMBOL TABLE.

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'VARIABLE' AND SAVE THE CONTENT*/
parseNode createVarNode2(int i, int typ) { 
   parseNode ptr; 
   ptr.type = (typ==0)?conintTyp: condoubleTyp; 
   ptr.var.index = i; 

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'CONSTANT NUMBER', SAVE THE NUMBER AND RETURN THE POINTER*/
parseNode *createConNode(double i) { 
   parseNode *ptr; 
   ptr = malloc(sizeof(parseNode)); 
   ptr->type = connumType;       //NODE TYPE: CONSTANT.
   ptr->constNum.value = i;      //CONSTANT VALUE.
   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'STRING', SAVE THE STRING AND RETURN THE POINTER*/
parseNode *createConStrNode(char* i) { 
   parseNode *ptr; 
   ptr = malloc(sizeof(parseNode)); 
   ptr->type = constringType;    //NODE TYPE: STRING.
   ptr->constString.svalue = i;  //STRING.
   return ptr; 
}

/*PUT THE # OF PARAMETERS, PARAMETERS, ROOT NODE OF THE FUNCTION INTO FUNCTION TABLE*/
void putFunc(int index, parseNode *start){
         
			func_Table[index].numPara = tpl_index;
			for(int i=0; i<tpl_index; i++){
				func_Table[index].para[i] = tempParaList[i];
			}
			tpl_index=0;

			func_Table[index].start = start;
}

/*GET THE ARGUMENTS INTO TEMPORARY LIST OF ARGUMENTS FOR FUNCTIONS AND CLASS MEMBER METHODS*/
void getArguments(parseNode *p){
    if (!p) return ;
    switch(p->type) {
        case connumType: 
            tempArgList[tal_index] = p->constNum.value; tal_index++; return;    
        case varType:
            tempArgList[tal_index] = sym_Tab[symTabList_index][p->var.index].value; tal_index++; return;
        case oprType:
            switch(p->opr.optr){
               case ';': 
                  {
                     getArguments(p->opr.operands[0]); getArguments(p->opr.operands[1]); return;
                  }
               case UMINUS: 
                  tempArgList[tal_index] = -executeTheNode(p->opr.operands[0]); tal_index++;return;

               case '+': 
                  tempArgList[tal_index] =  executeTheNode(p->opr.operands[0]) + executeTheNode(p->opr.operands[1]); tal_index++;return;

               case '-': 
                  tempArgList[tal_index] =  executeTheNode(p->opr.operands[0]) - executeTheNode(p->opr.operands[1]);tal_index++;return;

               case '*': 
                  tempArgList[tal_index] = executeTheNode(p->opr.operands[0]) * executeTheNode(p->opr.operands[1]); tal_index++;return;
               
               case '/': 
                  if(executeTheNode(p->opr.operands[1]) == 0){
                     yyerror("Divide by zero error."); 
                     tempArgList[tal_index] = 0;tal_index++;return;
                  }else{
                     tempArgList[tal_index] = executeTheNode(p->opr.operands[0]) / executeTheNode(p->opr.operands[1]);tal_index++;return; 
                  }
            }
    }
}

/*ADD THE MEMBER VARIABLES OF THE CLASS INTO THE TEMPORARY CLASS STRUCTURE - 'tempClsStruct'*/
void addClsData(int index, parseNode *ptr){
   if(!ptr){
      tempClsStruct[index].nodp = itr;
      return;
   } 
   switch(ptr->opr.optr){
      case '^':
         {  
            itr++;
            addClsData(index, ptr->opr.operands[0]);
            itr--;
            tempClsStruct[index].data[ptr->opr.operands[1]->var.index].type = (ptr->opr.type == 1)?doubleType:intType; 
            tempClsStruct[index].inUse[itr] = ptr->opr.operands[1]->var.index;
         }
   }
}

/*ADD THE CLASS METHODS INTO THE TEMPORARY CLASS STRUCTURE - 'tempClsStruct'*/
void addClsMethod(int index, parseNode *ptr){
   if(!ptr) return;

   switch(ptr->type){
      case oprType:
         {
            switch(ptr->opr.optr){
               case '^':
                  {
                     addClsMethod(index,ptr->opr.operands[0]);
                     addClsMethod(index,ptr->opr.operands[1]);
                  }

               case ';':
                  {
                     int methodindex =  ptr->opr.operands[0]->var.index;
                     tempClsStruct[index].methTable[methodindex].numPara = 0;
                     addMethPara(index, methodindex, ptr->opr.operands[1]);

                     parseNode *p = createOpNode(';', 2, ptr->opr.operands[2], ptr->opr.operands[3]);
                     tempClsStruct[index].methTable[methodindex].start = p;
                  }
            }
         }
   }
}

/*ADD THE PARAMETERS OF THE CLASS'S METHOD INTO THE TEMPORARY CLASS STRUCTURE - 'tempClsStruct'*/
void addMethPara(int index, int methodindex, parseNode *ptr){
if(!ptr) return;

   switch(ptr->type){
      case oprType:
         {
            switch(ptr->opr.optr){
               case '!':
                  {
                     addMethPara(index, methodindex, ptr->opr.operands[0]);
                     tempClsStruct[index].methTable[methodindex].para[tempClsStruct[index].methTable[methodindex].numPara] = createVarNode2(ptr->opr.operands[1]->var.index,ptr->opr.type);
                     tempClsStruct[index].methTable[methodindex].numPara = tempClsStruct[index].methTable[methodindex].numPara +1;
                     
                  }
            }
         }
   }
}

/*COPY THE STRUCTURE OF THE CLASS WHICH IS TEMPORARILY STORED IN 'tempClsStruct' 
  INTO THE OBJECT CREATED OF THAT CLASS*/
void copyObj(int objindex, int clsindex){
   class_Tab[clsindex].obj[objindex] = tempClsStruct[clsindex];
}

/*INITIALIZE THE CLASS MEMBER VARIABLES WHILE CREATING OBJECTS = CONSTRUCTOR IMPLEMENTATION.*/
void clsDataInitialize(int objindex, int clsindex, parseNode *ptr){
   if(!ptr)return;

   switch(ptr->type){
         case oprType:
            {
               switch(ptr->opr.optr){
                  case ';':
                     {  
                        clsDataInitialize(objindex, clsindex, ptr->opr.operands[0]);
                        class_Tab[clsindex].obj[objindex].data[ptr->opr.operands[1]->var.index].value = executeTheNode(ptr->opr.operands[2]); 
                        return;
                     }
               }
            }

   }
}

/*OUTPUT THE LIST OF EXPRESSIONS RECURSIVELY BY EVALUATING THE NODES*/
void printTheList(parseNode *ptr){
   if(!ptr)return;
   switch(ptr->type){
      case oprType:
         switch(ptr->opr.optr){
            case ';':
               {  
                  printTheList(ptr->opr.operands[0]);
                  if((ptr->opr.operands[1])->type == constringType){
                     printf("%s ",(ptr->opr.operands[1])->constString.svalue);
                  }else{
                     double num = executeTheNode(ptr->opr.operands[1]);
                     int num1 = (int)num;
                     double num2 = num1;
                     double zer = 0;
                     if(num2-num == zer){
                        printf("%d ", num1); 
                     }else{
                        printf("%lf ", num); 
                     }
                  }

               }
         }
   }
   
}

/*CLEAR THE SPACE OF THE NODE AFTER IT'S EXECUTION IS DONE*/
void cleanSpace(parseNode *ptr) { 
   if (!ptr) return;

   if (ptr->type == oprType) { 
      for (int i = 0; i < ptr->opr.nops; i++) 
         cleanSpace(ptr->opr.operands[i]); 
      free(ptr->opr.operands); 
   }

   free(ptr); 
}

/*EXECUTE THE NODES STARTING FROM ROOT OF THE INPUT MAIN FUNCTION CODE RECURSIVELY*/
double executeTheNode(parseNode *ptr) { 
   if (!ptr) return 0;

   switch(ptr->type) { 

      //IF IT IS A 'CONSTANT NODE' THEN RETURN IT'S VALUE.
      case connumType:  return ptr->constNum.value;

      //IF IT IS A 'VARIABLE NODE' THEN RETURN THE VALUE OF IT STORED IN SYMBOL TABLE.
      case varType:     return sym_Tab[symTabList_index][ptr->var.index].value; 

      //IF IT IS A 'OPERATOR NODE' THEN CHECK THE OPERATOR TYPE.
      case oprType: 
      
         switch(ptr->opr.optr) { 

            //WHILE LOOP IMPLEMENTATION.
            case UNTIL: 
               {
                  //EXECUTE OPERAND-2 UNTIL OPERAND-1 IS EVALUATED TO TRUE.
                  while(executeTheNode(ptr->opr.operands[0])) executeTheNode(ptr->opr.operands[1]);
                  return 0;
               }
               
            //FOR LOOP IMPLEMENTATION.
            case LOOP:
               {
                  executeTheNode(ptr->opr.operands[0]);           //DECLARATION OF LOOP VARIABLE. 
                  while(executeTheNode(ptr->opr.operands[2])){    //USING WHILE LOOP TO EXECUTE FOR LOOP.
                     executeTheNode(ptr->opr.operands[3]);        //FOR LOOP'S BODY.
                     executeTheNode(ptr->opr.operands[1]);        //UPDATION OF LOOP VARIABLE.
                  };
                  return 0;
               }

            //IF AND IF-ELSE IMPLEMENTATION.
            case CHECK: 
               {
                  if (executeTheNode(ptr->opr.operands[0])) 
                     executeTheNode(ptr->opr.operands[1]); 
                  else if (ptr->opr.nops > 2) 
                     executeTheNode(ptr->opr.operands[2]);
                  return 0;  
               }
               
            //WRITE FUNCTION: TO PRINT ANY INDIVIDUAL VARIABLES.
            case WRITE:
               {
                  switch(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type){
                     case intType:
                        {
                           int num = (int)sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value;
                           printf("%d\n",num);
                           break;
                        }
                     case doubleType:
                        {
                           printf("%f\n",sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
                           break;
                        }
                  }
                  return 0;
               }

            //OUTPUT FUNCTION: TO PRINT LIST OF EXPRESSIONS.
            case PRINT: 

               {
                  printTheList(ptr->opr.operands[0]);
                  printf("\n");
                  return 0;
               }
            
            //OUTPUT FUNCTION TO PRINT A STRING AND AN EXPRESSION.
            case PRINTF: 
               {
                  double num = executeTheNode(ptr->opr.operands[1]);
                  int num1 = (int)num;
                  double num2 = num1;
                  double zer = 0;
                  if(num2-num == zer){
                     printf("%s %d\n", ptr->opr.operands[0]->constString.svalue, num1);
                  }else{
                     printf("%s %lf\n", ptr->opr.operands[0]->constString.svalue, num);
                  }
                  return 0;
               }
               
            //SEGREGATE THE STATEMENTS IN THE STATEMENT LIST.
            case ';': 
               executeTheNode(ptr->opr.operands[0]); return executeTheNode(ptr->opr.operands[1]); 

            //ASSIGNMENT OPERATION.
            case '=': 
               {  
                  if(ptr->opr.nops == 1){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type = (ptr->opr.type == 0)?intType:doubleType;
                  }else if(ptr->opr.nops == 2){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type = (ptr->opr.type == 0)?intType:doubleType;
                     if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[1]);
                     }else{
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)executeTheNode(ptr->opr.operands[1]);
                     }
                     return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value); 
                  }else{
                     if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[1]);
                     }else{
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)executeTheNode(ptr->opr.operands[1]);
                     }
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                     return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value); 
                  }
               }

            //ADD AND ASSIGN '+=' OPERATION.
            case EP:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value + executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value + executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }

            //SUBTRACT AND ASSIGN '-=' OPERATION.
            case EM:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value - executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value - executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }

            //MULTIPLY AND ASSIGN '*=' OPERATION.
            case EMUL:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value * executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value * executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }
            
            //DIVIDE AND ASSIGN '/=' OPERATION.
            case EDIV:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value / executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value / executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }

            //RECOGNIZE (NEGATIVE NUMBERS WITHOUT ANY LEFT OPERAND) AND RETURN IT.
            case UMINUS: 
               return -executeTheNode(ptr->opr.operands[0]); 

            //ADDITION OPERATION.
            case '+': 
               return executeTheNode(ptr->opr.operands[0]) + executeTheNode(ptr->opr.operands[1]); 

            //SUBTRACTION OPERATION.
            case '-': 
               return executeTheNode(ptr->opr.operands[0]) - executeTheNode(ptr->opr.operands[1]);

            //MULTIPLICATION OPERATION.
            case '*': 
               return executeTheNode(ptr->opr.operands[0]) * executeTheNode(ptr->opr.operands[1]); 
            
            //DIVISION OPERATION.
            //IF OPERAND-2 IS EVALUATED TO 0, PRINT ERROR.
            case '/': 
               {
                  double op2 = executeTheNode(ptr->opr.operands[1]);
                  if( op2 == 0){
                     yyerror("Divide by zero error."); 
                     return 0;
                  }else{
                     return executeTheNode(ptr->opr.operands[0]) / op2; 
                  }
               }
            
            //BOOLEAN OPERATION = '<'.
            case '<': 
               return executeTheNode(ptr->opr.operands[0]) < executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '>'.
            case '>': 
               return executeTheNode(ptr->opr.operands[0]) > executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '>='.
            case GE: 
               return executeTheNode(ptr->opr.operands[0]) >= executeTheNode(ptr->opr.operands[1]);
               
            //BOOLEAN OPERATION = '<='.
            case LE: 
               return executeTheNode(ptr->opr.operands[0]) <= executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '!='.
            case NE: 
               return executeTheNode(ptr->opr.operands[0]) != executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '=='.
            case EQ: 
               return executeTheNode(ptr->opr.operands[0]) == executeTheNode(ptr->opr.operands[1]); 
            
            //AND OPEERATION.
            case AND: 
               return (int)executeTheNode(ptr->opr.operands[0]) & (int)executeTheNode(ptr->opr.operands[1]); 
            
            //OR OPERATION.
            case OR: 
               return (int)executeTheNode(ptr->opr.operands[0]) | (int)executeTheNode(ptr->opr.operands[1]);
             
            //UNARY INCREMENT OPERATION.
            case UP : 
               {
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[0])+1); 
               }

            //UNARY DECREMENT OPERATION.
            case UM : 
               {
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[0])-1);
               }
            
            //EXECUTE THE EXPRESSION AND RETURN IT.
            case RETURN: 
               return executeTheNode(ptr->opr.operands[0]); 
            
            //FUNCTION IS CALLED, EXECUTE THE PARSE TREE OF THE FUCNTION(EXECUTE THE FUNCTION).
            case FUNCALL:
               {
                  int funcindex = ptr->opr.operands[0]->var.index;

                  //TAKE THE FUNCTION CALL ARGUMENTS AND STORE IN TEMPORARY ARGUMENT LIST.
                  tal_index=0;
                  getArguments(ptr->opr.operands[1]);

                  //NEXT LEVEL SYMBOL TABLE == THIS FUNCTION LEVEL SYMBOL TABLE. 
                  symTabList_index++;

                  //ADDING ARGUMENTS OF THE FUNCTION CALL INTO THE SYMBOL TABLE.
                  for(int i =0; i <func_Table[funcindex].numPara ; i++){
                     sym_Tab[symTabList_index][func_Table[funcindex].para[i].var.index].type = (func_Table[funcindex].para[i].type == conintTyp)?intType:doubleType;
                     sym_Tab[symTabList_index][func_Table[funcindex].para[i].var.index].value = tempArgList[i];
                  }
                  tal_index=0;

                  //EXECUTE THE FUNCTION USING IT'S ROOT WHICH WAS STORED IN FUNCTION TABLE.
                  double res= executeTheNode(func_Table[funcindex].start);

                  //BACK TO PREVIOUS LEVEL SYMBOL TABLE.
                  if(symTabList_index >= 1) symTabList_index--;

                  // RETURN THE RETURN VALUE OF THE FUNCTION'S RETURN EXPRESSION.
                  return res;
               }
            
            //ACCESS CLASS MEMBER VARIABLES.
            case CLSDATA:
               {
                  return class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value;
               }

            //ASSIGN CLASS MEMBER VARIABLES THE EVALUATED EXPRESSION.
            case CLSDATAINI:
               {
                  
                  if(class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].type == intType){
                     class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value = (int)executeTheNode(ptr->opr.operands[3]);
                  }else{
                     class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value = executeTheNode(ptr->opr.operands[3]);
                  }
                  return class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value;
               }

            //MEMBER METHOD OF OBJECT IS CALLED, EXECUTE THE PARSE TREE OF THAT METHOD(EXECUTE THE FUNCTION).
            case OBJFUNCALL:
               {
                  int clsindex = ptr->opr.operands[0]->var.index;
                  int objindex = ptr->opr.operands[1]->var.index;
                  int methindex = ptr->opr.operands[2]->var.index;

                  //TAKE THE FUNCTION CALL ARGUMENTS AND STORE IN TEMPORARY ARGUMENT LIST.
                  getArguments(ptr->opr.operands[3]);

                  //NEXT LEVEL SYMBOL TABLE == THIS FUNCTION LEVEL SYMBOL TABLE. 
                  symTabList_index++;

                  //TAKE THE MEMBER VARIABLES OF THE CLASS INTO CURRENT LEVEL SYMBOL TABLE.
                  for(int i =0; i< 1000; i++){
                     sym_Tab[symTabList_index][i] = class_Tab[clsindex].obj[objindex].data[i];
                  }
                  
                  //ADDING ARGUMENTS OF THE FUNCTION CALL INTO THE SYMBOL TABLE.
                  for(int i =0; i <class_Tab[clsindex].obj[objindex].methTable[methindex].numPara ; i++){
                     sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].methTable[methindex].para[i].var.index].type = (class_Tab[clsindex].obj[objindex].methTable[methindex].para[i].type == conintTyp)?intType:doubleType;
                     sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].methTable[methindex].para[i].var.index].value = tempArgList[i];
                  }
                  tal_index=0;

                  //EXECUTE THE FUNCTION USING IT'S ROOT WHICH WAS STORED IN FUNCTION TABLE.
                  double res= executeTheNode(class_Tab[clsindex].obj[objindex].methTable[methindex].start);

                  //UPDATE THE MEMBER VARIABLES OF THE CLASS.
                  for(int i =0; i < class_Tab[clsindex].obj[objindex].nodp ; i++){
                     if(sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].inUse[i]].used == 1){
                           for(int j = 0; j<100; j++){
                              class_Tab[clsindex].obj[j].data[class_Tab[clsindex].obj[objindex].inUse[i]].value = sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].inUse[i]].value;
                           }
                     }
                  }

                  //BACK TO PREVIOUS LEVEL SYMBOL TABLE.
                  if(symTabList_index >= 1) symTabList_index--;

                  // RETURN THE RETURN VALUE OF THE FUNCTION'S RETURN EXPRESSION.
                  return res;

               }

            //INITIALIZE THE CLASS MEMBER VARIABLES WHILE CREATING OBJECTS = CONSTRUCTOR IMPLEMENTATION.
            case CLSCONSTR:
               {
                  int i = ptr->opr.operands[0]->var.index;
                  int j = ptr->opr.operands[1]->var.index;
                  clsDataInitialize(i, j, ptr->opr.operands[2]);
                  return 0;
               }
            
            //TAKE INPUT: ANY # OF INPUTS IN ONE LINE.
            case INPUT:
               {  
                  executeTheNode(ptr->opr.operands[0]);
                  double inp;
                  scanf("%lf", &inp);
                  if(sym_Tab[symTabList_index][ptr->opr.operands[1]->var.index].type == intType){
                     sym_Tab[symTabList_index][ptr->opr.operands[1]->var.index].value = (int)inp;
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[1]->var.index].value = inp;
                  }
               }
         } 
   } 
   return 0; 
} 


/*PRINTING ERROR MESSAGE*/
void yyerror(char *s) { 
   fprintf(stdout, "%s\n", s); 
}

/*MAIN FUNCTION : TAKES INPUT OF INPUTFILE & CALLS THE PARSER USING 'YYPARSE()'*/
int main(void) {
   char* s;
   scanf("%s", s);
   extern FILE* yyin;
   FILE* f = fopen(s,"r"); 
   yyin = f;
   yyparse(); 
   return 0; 
}
