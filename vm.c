#include<stdio.h>
#include<stdlib.h>
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
	fprintf(stdout, "ci_debug-0.0.1\nci stands for c interpreter."
			" Please excuse the authors for their lack of"
			" imagination in naming.\n\t"
			"@author  Ashwin Jha <ajha.dev@gmail.com>\n\t"
			"@author  Durgesh Singh <blah@blah.blah>\n");
}

void set_main_ref(ast node) {
	//if(_main_ref_ == NULL)
		_main_ref_ = node;
	//else
		//goto ERROR;
}

void print_prompt() {
	fprintf(stderr, "ci>> ");
}

int _start_() {
	/* print some shit and wait for user input */
	/* this one not working correctly right now */
	publish_masthead();
	init(TRUE);
	yyin=stdin;
	fprintf(stderr, "ci>> ");
	while(1) {
		yyparse();
		if(_main_ref_ != NULL) eval_func_call(_main_ref_);
		fprintf(stderr, "ci>> ");
	}
	return 0;
}

int _interpret_(FILE* in) {
	/* go on interpreting */
	init(FALSE);
	yyin=in;
	yyparse();
	return eval_func_call(_main_ref_)->eval._INT;
}
