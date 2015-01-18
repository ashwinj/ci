#include <stdio.h>
#include <stdlib.h>
#include "abstract_syntax_tree.h"
#include "symbol_table.h"

//err_t err_type;
char* err_msg;

void purge_vmds() {
	clear_ar_stack();
	purge_st(global_symbol_table);
	purge_asts();
}

void err() {
	fprintf(stderr, "\n%sBye bye!!\n\n", err_msg);
	exit(1);
}
