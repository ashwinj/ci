/****************************************************************************************************

	Copyright (C) 2015 Ashwin Jha and Durgesh Singh

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.


	Declaration of interpreter scoper parameters and functions. For more information,
	check interpreter.c.


	@author		Ashwin Jha<ajha.dev@gmail.com>

*****************************************************************************************************/

#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#define MAX_NO_OF_FUNCTIONS				   19
#define SYMBOL_TABLE_HASH_SIZE				   31
#define CHAR_HASH_OFFSET_PRIME				   17
#define GLOBAL_SYMBOL_TABLE		"global_symbol_table"
#define _X_OPEN_SOURCE					  500
#define TRUE						    1
#define FALSE						    0

#define CHAR_SIZE 				 sizeof(char)
#define SHORT_SIZE 				sizeof(short)
#define INT_SIZE 				  sizeof(int)
#define LONG_SIZE 				 sizeof(long)
#define FLOAT_SIZE 				sizeof(float)
#define DOUBLE_SIZE 			       sizeof(double)
#define PTR_SIZE 				sizeof(char*)

#define MAIN_FUNCTION_LABEL 			       "main"
#define PRINTF_LABEL 				     "printf"
#define SCANF_LABEL 				      "scanf"					    

#include <stdlib.h>

extern int _main_env_;
extern int _interact_env_;
extern int _block_stmt;
extern char* err_msg;

typedef enum {
	UNDEFINED, VOID, CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, CHAR_ARR, SHORT_ARR, INT_ARR,
	LONG_ARR, FLOAT_ARR, DOUBLE_ARR, VOID_PTR, CHAR_PTR, SHORT_PTR, INT_PTR, LONG_PTR, 
	FLOAT_PTR, DOUBLE_PTR, AST_PTR, VOID_2PTR, CHAR_2PTR, SHORT_2PTR, INT_2PTR, LONG_2PTR, 
	FLOAT_2PTR, DOUBLE_2PTR, VOID_3PTR, CHAR_3PTR, SHORT_3PTR, INT_3PTR, LONG_3PTR, 
	FLOAT_3PTR, DOUBLE_3PTR
} data_type;

typedef enum {
	EQ_ASSIGN_CODE, MUL_ASSIGN_CODE, DIV_ASSIGN_CODE, MOD_ASSIGN_CODE, ADD_ASSIGN_CODE, SUB_ASSIGN_CODE, 
	LEFT_ASSIGN_CODE, RIGHT_ASSIGN_CODE, AND_ASSIGN_CODE, XOR_ASSIGN_CODE, OR_ASSIGN_CODE
} assignment_code;

typedef union {
	char _CHAR;
	short _SHORT;
	int _INT;
	long _LONG;
	float _FLOAT;
	double _DOUBLE;
	void* _VOID_PTR;
	char* _CHAR_PTR;
	short* _SHORT_PTR;
	int* _INT_PTR;
	long* _LONG_PTR;
	float* _FLOAT_PTR;
	double* _DOUBLE_PTR;
	void** _VOID_2PTR;
	char** _CHAR_2PTR;
	short** _SHORT_2PTR;
	int** _INT_2PTR;
	long** _LONG_2PTR;
	float** _FLOAT_2PTR;
	double** _DOUBLE_2PTR;
	void*** _VOID_3PTR;
	char*** _CHAR_3PTR;
	short*** _SHORT_3PTR;
	int*** _INT_3PTR;
	long*** _LONG_3PTR;
	float*** _FLOAT_3PTR;
	double*** _DOUBLE_3PTR;
} value;

typedef struct returnable {
	data_type type;
	value eval;
	struct returnable* next;
} returnable;

void init(int isInteractiveSession);
value alloc_mem(data_type type, int units);
value alloc_mem_for_2arr(data_type type, int rows, int cols);
void purge_mem(data_type type, value val);
returnable* new_returnable();
returnable* copy_returnable(returnable* orig);
void purge_returnable(returnable* ret);
int hash(char* message, int hash_size);
int ltoi(long val);
int get_int(long val);
char* concat_str(int num, ...);
void* safe_malloc(size_t size);
void purge_vmds();
void err();

#endif
