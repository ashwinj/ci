/****************************************************************************************************

	VM functions declarations. For more information, check vm.c.

	@author		Ashwin Jha<ajha.dev@gmail.com>

*****************************************************************************************************/

#ifndef _VM_H_
#define _VM_H_

#include "abstract_syntax_tree.h"

#define INTERPRETER_VERSION		"debug_v0.1"

int _start_();
int _interpret_();
void set_main_ref(ast node);

#endif
