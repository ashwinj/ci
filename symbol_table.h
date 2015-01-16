#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include "interpreter.h"

#define LOOP_ENV					   1
#define BREAK_ENV					   2
#define CONTINUE_ENV					   4

#define CONTEXT_SYMBOL_TABLE		((peek_ar())->table)
#define CONTEXT_ENV			((peek_ar())->env)
#define CONTEXT_RETURN_VALUE		((peek_ar())->return_value)

typedef enum symbol_table_entry_token_tag {
	_VARIABLE, _ARRAY, _2ARRAY, _FUNCTION
} symbol_token_tag;

typedef union {
	value var_val;
	int ast_ref_index;
} symbol_value_type;

typedef struct symbol_table_entry {
	symbol_token_tag symbol_entry_tag;
	char* symbol_entry_label;
	data_type symbol_entry_type;
	symbol_value_type symbol_entry_value;
	struct symbol_table_entry* next;
} st_entry;

typedef struct symbol_table {
	char* symbol_table_id;
	st_entry* entry[SYMBOL_TABLE_HASH_SIZE];
} st;

typedef struct activation_record {
	st* table;
	returnable* return_value;
	char env;
	struct activation_record* next;
} ar;

extern st* global_symbol_table;

extern st* context_symbol_table;

extern ar* activation_record_stack;

st_entry* new_st_entry(symbol_token_tag stt, char* l, data_type set, symbol_value_type sev);
void purge_st_entry(st_entry* te);
st* new_st(char* id);
void purge_st(st* t);
void purge_st_entries(st* t);
void insert_st_entry(st* table, st_entry* te);
st_entry* lookup_st_entry(st* table, char* id);
ar* new_ar(char* block_id);
void purge_ar(ar* a);
void push_ar(ar* a);
ar* pop_ar();
ar* peek_ar();

#endif
