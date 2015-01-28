/****************************************************************************************************

	Virtual machine for ci. It manages all the modules of the interpreter to
	parse-->build ast-->evaluate ast.
	For more information on specific modules, check following:
		1. Lexer + Parser	ci.l, ci.y
		2. AST builder		ast_builder.h
		3. AST evaluation	ast_evaluator.h
	For data structures:
		1. Abstract syntax tree		abstract_syntax_tree.h	
		1. Symbol table			symbol_table.h
		2. Activation record		symbol_table.h


	@author		Ashwin Jha<ajha.dev@gmail.com>

*****************************************************************************************************/

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
			"@author  	Ashwin Jha<ajha.dev@gmail.com>\n\t"
			"@contributor  	Durgesh Singh<durgesh.ccet@gmail.com>\n\n");
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
	returnable* ret;
	init(FALSE);
	yyin=in;
	yyparse();
	ret = eval_func_call(_main_ref_);
	i =  ret->eval._INT;
	purge_returnable(ret);
	purge_vmds();
	purge_ast(_main_ref_);
	_main_ref_ = NULL;
	return i;
}
