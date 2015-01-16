#ifndef _ABSTRACT_SYNTAX_TREE_H_
#define _ABSTRACT_SYNTAX_TREE_H_

#include "interpreter.h"

#define LVAL 1
#define RVAL 0

typedef enum abstract_syntax_tree_node_tag {
	SCRIPT, FUNCTION, BLOCK, VARIABLE, ARRAY, ARRAY2, CONSTANT, TYPE, DECLARATION, ASSIGNMENT, UNARY_MINUS, 
	UNARY_PLUS, ADDITION, SUBTRACTION, MULTIPLICATION, MODULO, DIVISION, BITWISE_AND, BITWISE_OR, BITWISE_XOR,
	BITWISE_NOT, LOGICAL_AND, LOGICAL_OR, LOGICAL_NOT, REL_LESS, REL_GREATER, REL_LESS_EQUAL, CALL, REL_EQUAL,
	REL_GREATER_EQUAL, REL_NOT_EQUAL, IF_STATEMENT, WHILE_STATEMENT, FOR_STATEMENT, POST_INCREMENT, TYPE_CAST,
	POST_DECREMENT, PRE_INCREMENT, PRE_DECREMENT, LEFT_SHIFT, RIGHT_SHIFT, CONDITIONAL, EXP_LIST, INIT_LIST,
	VAR_DECL_LIST, VAR_TYPE_DECL_LIST, RETURN_STATEMENT, TRANSLATION_UNIT_LIST, EXPRESSION_STATEMENT, PARAM_NUM,
	ARGUMENT_EXPRESSION_LIST, STATEMENT_LIST, REFERENCE, DEREFERENCE, BREAK_STATEMENT, CONTINUE_STATEMENT
} ast_node_tag;

typedef struct abstract_syntax_tree_node {
	ast_node_tag tag;
	char* ast_node_label;
	data_type return_type;
	struct abstract_syntax_tree_node* left_most_child;
	struct abstract_syntax_tree_node* left_most_sibling;
} ast_node;

typedef ast_node* ast;

extern ast asts[MAX_NO_OF_FUNCTIONS];

ast new_ast(ast_node_tag t, char* l, data_type rt);
ast copy_ast(ast node);
void set_left_most_child(ast node, ast lmc);
void set_left_most_sibling(ast node, ast lms);
ast get_left_most_sibling(ast node);
ast get_left_most_child(ast node);
void purge_ast(ast node);
int set_ast_root_reference(ast node);
ast lookup_ast(char* label);
char* toString(ast_node_tag tag);

#endif
