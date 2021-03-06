/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
