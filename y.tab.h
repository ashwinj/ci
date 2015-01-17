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
#line 24 "ci.y" /* yacc.c:1909  */

	ast node;
	char unary_code;
	char* string;
	assignment_code assign_code;

#line 163 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
