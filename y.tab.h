
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 57 "yacc.y"
                                     //"YYLVAL" CAN BE ONE OF THESE.
   int iVal; 
   char* strVal;
   double dVal;
   
   int symInd;
   parseNode *nPtr; 



/* Line 1676 of yacc.c  */
#line 141 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


