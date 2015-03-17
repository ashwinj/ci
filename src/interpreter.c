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


	This module handles the functions common throughout the interpreter scope.


	@author		Ashwin Jha<ajha.dev@gmail.com>

*****************************************************************************************************/

#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "symbol_table.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int _main_env_, _interact_env_, _block_stmt;
ar* activation_record_stack;

value alloc_mem(data_type type, int units) {
	value val;
	switch(type) {
	case CHAR:
		val._CHAR_PTR = (char*)safe_malloc(sizeof(char)*units);
		return val;
	case SHORT:
		val._SHORT_PTR = (short*)safe_malloc(sizeof(short)*units);
		return val;
	case INT:
		val._INT_PTR = (int*)safe_malloc(sizeof(int)*units);
		return val;
	case LONG:
		val._LONG_PTR = (long*)safe_malloc(sizeof(long)*units);
		return val;
	case FLOAT:
		val._FLOAT_PTR = (float*)safe_malloc(sizeof(float)*units);
		return val;
	case DOUBLE:
		val._DOUBLE_PTR = (double*)safe_malloc(sizeof(double)*units);
		return val;
	case CHAR_PTR:
		val._CHAR_2PTR = (char**)safe_malloc(sizeof(char*)*units);
		return val;
	case SHORT_PTR:
		val._SHORT_2PTR = (short**)safe_malloc(sizeof(short*)*units);
		return val;
	case INT_PTR:
		val._INT_2PTR = (int**)safe_malloc(sizeof(int*)*units);
		return val;
	case LONG_PTR:
		val._LONG_2PTR = (long**)safe_malloc(sizeof(long*)*units);
		return val;
	case FLOAT_PTR:
		val._FLOAT_2PTR = (float**)safe_malloc(sizeof(float*)*units);
		return val;
	case DOUBLE_PTR:
		val._DOUBLE_2PTR = (double**)safe_malloc(sizeof(double*)*units);
		return val;
	case CHAR_2PTR:
		val._CHAR_3PTR = (char***)safe_malloc(sizeof(char**)*units);
		return val;
	case SHORT_2PTR:
		val._SHORT_3PTR = (short***)safe_malloc(sizeof(short**)*units);
		return val;
	case INT_2PTR:
		val._INT_3PTR = (int***)safe_malloc(sizeof(int**)*units);
		return val;
	case LONG_2PTR:
		val._LONG_3PTR = (long***)safe_malloc(sizeof(long**)*units);
		return val;
	case FLOAT_2PTR:
		val._FLOAT_3PTR = (float***)safe_malloc(sizeof(float**)*units);
		return val;
	case DOUBLE_2PTR:
		val._DOUBLE_3PTR = (double***)safe_malloc(sizeof(double**)*units);
		return val;
	default:
		err_msg = "RUNTIME EXCEPTION: Something wierd happening.\n\n";
		err();
	}
}

value alloc_mem_for_2arr(data_type type, int rows, int cols) {
	int i;
	value val;
	switch(type) {
	case CHAR:
		val._CHAR_2PTR = (char**)safe_malloc(sizeof(char*)*rows);
		for(i = 0; i < rows; i++) 
			*(val._CHAR_2PTR + i) = (char*)safe_malloc(sizeof(char)*cols);
		return val;
	case SHORT:
		val._SHORT_2PTR = (short**)safe_malloc(sizeof(short*)*rows);
		for(i = 0; i < rows; i++) 
			*(val._SHORT_2PTR + i) = (short*)safe_malloc(sizeof(short)*cols);
		return val;
	case INT:
		val._INT_2PTR = (int**)safe_malloc(sizeof(int*)*rows);
		for(i = 0; i < rows; i++) 
			*(val._INT_2PTR + i) = (int*)safe_malloc(sizeof(int)*cols);
		return val;
	case LONG:
		val._LONG_2PTR = (long**)safe_malloc(sizeof(long*)*rows);
		for(i = 0; i < rows; i++) 
			*(val._LONG_2PTR + i) = (long*)safe_malloc(sizeof(long)*cols);
		return val;
	case FLOAT:
		val._FLOAT_2PTR = (float**)safe_malloc(sizeof(float*)*rows);
		for(i = 0; i < rows; i++) 
			*(val._FLOAT_2PTR + i) = (float*)safe_malloc(sizeof(float)*cols);
		return val;
	case DOUBLE:
		val._DOUBLE_2PTR = (double**)safe_malloc(sizeof(double*)*rows);
		for(i = 0; i < rows; i++) 
			*(val._DOUBLE_2PTR + i) = (double*)safe_malloc(sizeof(double)*cols);
		return val;
	default:
		err_msg = "RUNTIME EXCEPTION: Something wierd happening.\n\n";
		err();
	}
}

void purge_mem(data_type type, value val) {
	switch(type) {
	case CHAR:
		free(val._CHAR_PTR);
		return;
	case SHORT:
		free(val._SHORT_PTR);
		return;
	case INT:
		free(val._INT_PTR);
		return;
	case LONG:
		free(val._LONG_PTR);
		return;
	case FLOAT:
		free(val._FLOAT_PTR);
		return;
	case DOUBLE:
		free(val._DOUBLE_PTR);
		return;
	case CHAR_PTR:
		free(val._CHAR_2PTR);
		return;
	case SHORT_PTR:
		free(val._SHORT_2PTR);
		return;
	case INT_PTR:
		free(val._INT_2PTR);
		return;
	case LONG_PTR:
		free(val._LONG_2PTR);
		return;
	case FLOAT_PTR:
		free(val._FLOAT_2PTR);
		return;
	case DOUBLE_PTR:
		free(val._DOUBLE_2PTR);
		return;
	case CHAR_2PTR:
		free(val._CHAR_3PTR);
		return;
	case SHORT_2PTR:
		free(val._SHORT_3PTR);
		return;
	case INT_2PTR:
		free(val._INT_3PTR);
		return;
	case LONG_2PTR:
		free(val._LONG_3PTR);
		return;
	case FLOAT_2PTR:
		free(val._FLOAT_3PTR);
		return;
	case DOUBLE_2PTR:
		free(val._DOUBLE_3PTR);
		return;
	default:
		err_msg = "RUNTIME EXCEPTION: Something wierd happening.\n\n";
		err();
	}
}

returnable* new_returnable() {
	returnable* ret = (returnable*)safe_malloc(sizeof(returnable));
	ret->next = NULL;
	return ret;
}

returnable* copy_returnable(returnable* orig) {
	returnable* dup = new_returnable();
	dup->eval = orig->eval;
	dup->type = orig->type;
	dup->next = orig->next;
	return dup;
}

void purge_returnable(returnable* ret) {
	returnable* next;
	returnable* temp = ret;
	if(temp == NULL) return;
	while(temp != NULL) {
		next = temp->next;
		free(temp);
		temp = next;
	}
	ret = NULL;
}

void init(int isInteractiveSession) {
	int i;
	global_symbol_table = new_st(GLOBAL_SYMBOL_TABLE);
	for(i = 0; i < MAX_NO_OF_FUNCTIONS; asts[i++] = NULL);
	context_symbol_table = global_symbol_table;
	activation_record_stack = NULL;
	_main_env_ = FALSE;
	_interact_env_ = isInteractiveSession;
	_block_stmt = 0;
}

int hash(char* message, int hash_size) {
	long digest = 0l;
	char* msg = message;
	while(*msg != '\0') {
		digest += *msg;
		digest *= CHAR_HASH_OFFSET_PRIME;
		msg++;
	}
	digest %= hash_size;
	return ltoi(digest);
}

int ltoi(long val) {
	union {
		int i;
		long l;
	} x;
	x.l = val;
	return x.i;
}

char* concat_str(int num, ...) {
	va_list str_list;
	char* str = (char*)safe_malloc(sizeof(char));
	*str = '\0';
	char* temp = NULL;
	va_start(str_list, num);
	while(num--)
	{
		temp = va_arg(str_list, char*);
		str = (char*)realloc(str, str != NULL?strlen(temp)+strlen(str)+1:strlen(temp)+1);
		strcat(str, temp);
	}
	va_end(str_list);
	return str;
}

void* safe_malloc(size_t size) {
	void* mem = malloc(size);
	if(mem != NULL) {
		return mem;
	} else {
		err_msg = "INTERNAL EXCEPTION: Memory allocation error. Maybe running low on memeory.\n\n";
		err();
	}
}

void purge_vmds() {
	clear_ar_stack();
	purge_st(global_symbol_table);
	purge_asts();
}
