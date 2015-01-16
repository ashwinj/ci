#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include <stdlib.h>
#include <string.h>

ast asts[MAX_NO_OF_FUNCTIONS];

ast new_ast(ast_node_tag t, char* l, data_type rt) {
	ast node = (ast)safe_malloc(sizeof(ast_node));
	node->tag = t;
	node->ast_node_label = strdup(l);
	node->return_type = rt;
	node->left_most_child = NULL;
	node->left_most_sibling = NULL;
	return node;
}

ast copy_ast(ast node) {
	ast dup;
	ast left_dup;
	ast sibling;
	if(node == NULL) return NULL;
	dup = new_ast(node->tag, node->ast_node_label, node->return_type);
	left_dup = copy_ast(get_left_most_child(node));
	set_left_most_child(dup, left_dup);
	sibling = copy_ast(get_left_most_sibling(node));
	set_left_most_sibling(dup, sibling);
	return dup;
}

void set_left_most_child(ast node, ast lmc) {
	node->left_most_child = lmc;
}

void set_left_most_sibling(ast node, ast lms) {
	node->left_most_sibling = lms;
}

ast get_left_most_sibling(ast node) {
	return node->left_most_sibling;
}

ast get_left_most_child(ast node) {
	return node->left_most_child;
}

void purge_ast(ast node) {
	ast temp;
	while(node->left_most_child != NULL) {
		temp = get_left_most_sibling(node->left_most_child);
		purge_ast(node->left_most_child);
		node->left_most_child = temp;
	}
	free(node->ast_node_label);
	free(node);
}

int set_ast_root_reference(ast node) {
	int i, j;
	int h = hash(node->ast_node_label, MAX_NO_OF_FUNCTIONS);
	for(i = 0; i < MAX_NO_OF_FUNCTIONS; i++) {
	        j = (h+i)%MAX_NO_OF_FUNCTIONS; 	
		if(asts[j] == NULL) {
			asts[j] = node;
			return j;
		}
	}
	return -1;
	// handle stack overflow case
}

ast lookup_ast(char* label) {
	int i, j;
	int h = hash(label, MAX_NO_OF_FUNCTIONS);
	for(i = 0; i < MAX_NO_OF_FUNCTIONS; i++) {
		j = (h+i)%MAX_NO_OF_FUNCTIONS;
		if(asts[j] != NULL && strcmp(asts[j]->ast_node_label, label) == 0) {
			return asts[j];
		}
	}
}

char* toString(ast_node_tag tag) {
	switch(tag) {
	case MULTIPLICATION:
		return "*";
	case DIVISION:
		return "/";
	case MODULO:
		return "%";
	case ADDITION:
		return "+";
	case SUBTRACTION:
		return "-";
	case BITWISE_AND:
		return "&";
	case BITWISE_OR:
		return "|";
	case BITWISE_XOR:
		return "^";
	case LOGICAL_AND:
		return "&&";
	case LOGICAL_OR:
		return "||";
	case LEFT_SHIFT:
		return "<<";
	case RIGHT_SHIFT:
		return ">>";
	case REL_LESS:
		return "<";
	case REL_GREATER:
		return ">";
	case REL_LESS_EQUAL:
		return "<=";
	case REL_GREATER_EQUAL:
		return ">=";
	case REL_EQUAL:
		return "==";
	case REL_NOT_EQUAL:
		return "!=";	
/*	case PROGRAM, FUNCTION, BLOCK, VARIABLE, ARRAY, ARRAY_ID, ARRAY_OFFSET, CONSTANT, TYPE, DECLARATION,
	ASSIGNMENT, UNARY_SUBTRACTION,BITWISE_NOT, RELATIONAL_NOT, IF_STATEMENT, 
	WHILE_STATEMENT, FOR_STATEMENT, POST_INCREMENT, POST_DECREMENT, TYPE_CAST */
	default:
		return "";
	}
}
