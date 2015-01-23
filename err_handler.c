/****************************************************************************************************

	This module handles error handling. Currently, this module is in its very basic
	structure. This will be improved subsequently.


	@author		Ashwin Jha<ajha.dev@gmail.com>

*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "abstract_syntax_tree.h"
#include "symbol_table.h"

//err_t err_type;
char* err_msg;

void err() {
	purge_vmds();
	fprintf(stderr, "\n%sBye bye!!\n\n", err_msg);
	exit(1);
}
