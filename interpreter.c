#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "symbol_table.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int _main_env_, _interact_env_, _block_stmt;
ar* activation_record_stack;

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
