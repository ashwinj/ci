/****************************************************************************************************

	Copyright (C) 2015 Ashwin Jha

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


	This module handles the functions related to manipulation of symbol table and activation
	record data structure.


	@author		Ashwin Jha<ajha.dev@gmail.com>

*****************************************************************************************************/

#include "interpreter.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

st* global_symbol_table;
st* context_symbol_table;

st_entry* new_st_entry(symbol_token_tag stt, char* l, data_type set, symbol_value_type sev) {
	st_entry* entry = (st_entry*)safe_malloc(sizeof(st_entry));
	entry->symbol_entry_label = strdup(l);
	entry->symbol_entry_tag = stt;
	entry->symbol_entry_type = set;
	entry->symbol_entry_value = sev;
	entry->next = NULL;
	return entry;
}

void purge_st_entry(st_entry* te) {
	free(te->symbol_entry_label);
	if(te->symbol_entry_tag != _FUNCTION) purge_mem(te->symbol_entry_type, te->symbol_entry_value.var_val);
	free(te);
}

st* new_st(char* id) {
	int i;
	st* node = (st*)safe_malloc(sizeof(st));
	node->symbol_table_id = strdup(id);
	for(i = 0; i < SYMBOL_TABLE_HASH_SIZE; node->entry[i++] = NULL);
	return node;
}

void purge_st(st* t) {
	purge_st_entries(t);
	free(t->symbol_table_id);
	free(t);
}

void purge_st_entries(st* t) {
	int i;
	st_entry *temp, *cur;
	for(i = 0; i < SYMBOL_TABLE_HASH_SIZE; i++) {
		temp = t->entry[i];
		while(temp != NULL) {
			cur = temp;
			temp = temp->next;
			purge_st_entry(cur);
		}
		t->entry[i] = NULL;
	}
}

void insert_st_entry(st* table, st_entry* te) {
	int h = hash(te->symbol_entry_label, SYMBOL_TABLE_HASH_SIZE);
	st_entry* temp = table->entry[h];
	if(temp == NULL) {
		table->entry[h] = te;
	} else {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = te;
	}
}

st_entry* lookup_st_entry(st* table, char* id) {
	int h = hash(id, SYMBOL_TABLE_HASH_SIZE);
	st_entry* temp = table->entry[h];
	while(temp != NULL) {
		if(strcmp(temp->symbol_entry_label, id) == 0) return temp;
		temp = temp->next;
	}
	return NULL;
}		

ar* new_ar(char* block_id) {
	ar* a = (ar*)safe_malloc(sizeof(ar));
	a->table = new_st(block_id);
	a->env = 0;
	a->next = NULL;
	a->return_value = NULL;
	return a;
}

void purge_ar(ar* a) {
	purge_st(a->table);
	purge_returnable(a->return_value);
	free(a);
}

void push_ar(ar* a) {
	a->next = activation_record_stack;
	activation_record_stack = a;
}

void clear_ar_stack() {
	ar* a;
	while(activation_record_stack != NULL) {
		a = activation_record_stack;
		activation_record_stack = activation_record_stack->next;
		purge_ar(a);
	}
}

ar* pop_ar() {
	ar* temp = activation_record_stack;
	activation_record_stack = temp->next;
	return temp;
}

ar* peek_ar() {
	return activation_record_stack;
}
