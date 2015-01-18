#include<stdio.h>
#include<stdlib.h>
#include "vm.h"
#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "ast_evaluator.h"
#include "symbol_table.h"
#include"y.tab.h"

extern FILE *yyin, *yyout;
ast _main_ref_;

/**
 * one of these days I will
 * define this init boilerplate
 *
 * int __init__();
 */

void publish_masthead() {
	fprintf(stdout, "\nci interpreter "INTERPRETER_VERSION"\n\t"
			"@author  Ashwin Jha <ajha.dev@gmail.com>\n\t"
			"@author  Durgesh Singh <blah@blah.blah>\n\n");
}

void show_help() {
	fprintf(stdout, "\nci interpreter "INTERPRETER_VERSION"\n"
			"Usage:\n"
			"Virtual Machine:\tci <ci script file with \".ci\" extension>\n"
			"Interactive Session:\tci\n"
			"Help:\t\t\tci -h\n"
			"Version:\t\tci -v\n\n");
}

void set_main_ref(ast node) {
	if(_main_ref_ == NULL)
		_main_ref_ = node;
	else {
		err_msg = "No main declaration block.\n\n";
		err();
	}
}

void print_prompt() {
	fprintf(stdout, "ci>> ");
}

int _start_() {
	publish_masthead();
	print_prompt();
	yyin=stdin;
	while(1) {
		init(TRUE);
		yyparse();
		purge_vmds();
		_main_ref_ = NULL;
		fprintf(stdout, "\nBye bye!!\n\n");
		break;
	}
	return 0;
}

int _interpret_(FILE* in) {
	/* go on interpreting */
	int i = -1;
	init(FALSE);
	yyin=in;
	yyparse();
	i =  eval_func_call(_main_ref_)->eval._INT;
	purge_vmds();
	_main_ref_ = NULL;
	return i;
}
