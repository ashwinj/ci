#ifndef _AST_UTIL_H_
#define _AST_UTIL_H_

#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "ast_builder.h"
#include "symbol_table.h"
#include <string.h>

#define CHAR_VALUE(x) (x->eval._CHAR)
#define SHORT_VALUE(x) (x->type == SHORT ? x->eval._SHORT : CHAR_VALUE(x))
#define INT_VALUE(x) (x->type == INT ? x->eval._INT : SHORT_VALUE(x))
#define LONG_VALUE(x) (x->type == LONG ? x->eval._LONG : INT_VALUE(x))
#define FLOAT_VALUE(x) (x->type == FLOAT ? x->eval._FLOAT : LONG_VALUE(x))
#define DOUBLE_VALUE(x) (x->type == DOUBLE ? x->eval._DOUBLE : FLOAT_VALUE(x))

#define VOID_PTR_VALUE(x) (x->eval._VOID_PTR)
#define CHAR_PTR_VALUE(x) (x->type == CHAR_PTR ? x->eval._CHAR_PTR : VOID_PTR_VALUE(x))
#define SHORT_PTR_VALUE(x) (x->type == SHORT_PTR ? x->eval._SHORT_PTR : CHAR_PTR_VALUE(x))
#define INT_PTR_VALUE(x) (x->type == INT_PTR ? x->eval._INT_PTR : SHORT_PTR_VALUE(x))
#define LONG_PTR_VALUE(x) (x->type == LONG_PTR ? x->eval._LONG_PTR : INT_PTR_VALUE(x))
#define FLOAT_PTR_VALUE(x) (x->type == FLOAT_PTR ? x->eval._FLOAT_PTR : LONG_PTR_VALUE(x))
#define DOUBLE_PTR_VALUE(x) (x->type == DOUBLE_PTR ? x->eval._DOUBLE_PTR : FLOAT_PTR_VALUE(x))

#define VOID_2PTR_VALUE(x) (x->eval._VOID_2PTR)
#define CHAR_2PTR_VALUE(x) (x->type == CHAR_2PTR ? x->eval._CHAR_2PTR : VOID_2PTR_VALUE(x))
#define SHORT_2PTR_VALUE(x) (x->type == SHORT_2PTR ? x->eval._SHORT_2PTR : CHAR_2PTR_VALUE(x))
#define INT_2PTR_VALUE(x) (x->type == INT_2PTR ? x->eval._INT_2PTR : SHORT_2PTR_VALUE(x))
#define LONG_2PTR_VALUE(x) (x->type == LONG_2PTR ? x->eval._LONG_2PTR : INT_2PTR_VALUE(x))
#define FLOAT_2PTR_VALUE(x) (x->type == FLOAT_2PTR ? x->eval._FLOAT_2PTR : LONG_2PTR_VALUE(x))
#define DOUBLE_2PTR_VALUE(x) (x->type == DOUBLE_2PTR ? x->eval._DOUBLE_2PTR : FLOAT_2PTR_VALUE(x))

#define is_int_type(type) ((type >= CHAR) && (type <= LONG))

#define is_basic_type ((type >= CHAR) && (type <= DOUBLE))

#define is_1pointer_type(type) ((type >= VOID_PTR) && (type <= DOUBLE_PTR))
#define is_2pointer_type(type) ((type >= VOID_2PTR) && (type <= DOUBLE_2PTR))
#define is_pointer_type(type) (is_1pointer_type(type) || is_2pointer_type(type))

#define is_compatible(lval, rval) ((lval >= rval) || (is_int_type(lval) && is_int_type(rval)))
#define is_lval_type(node) ((node->tag == VARIABLE) || ((node->tag == FUNCTION) && is_pointer_type(node->return_type) || \
				(node->tag == ARRAY) || (node->tag == DEREFERENCE))

#define is_additive_types(ltype, rtype) ((is_pointer_type(ltype) && is_int_type(rtype)) || \
					 (is_pointer_type(rtype) && is_int_type(ltype)))
#define is_multiplicative_types(ltype, rtype) (is_basic_type(ltype) && is_basic_type(rtype))
#define is_arithmetic_types(ltype, rtype) (is_additive_type(ltype, rtype) || is_multiplicative_type(ltype, rtype))

#define is_loop_env (CONTEXT_ENV == LOOP_ENV)
#define is_break_condition (CONTEXT_ENV == (LOOP_ENV | BREAK_ENV))
#define is_continue_condition (CONTEXT_ENV == (LOOP_ENV | CONTINUE_ENV))
#define is_return_condition (CONTEXT_RETURN_VALUE != NULL)
#define is_jmp_condition (is_return_condition || is_break_condition | is_continue_condition)

#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "ast_util.h"
#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>

value alloc_mem(data_type type, int units);
data_type ptob(data_type type);
data_type btop(data_type type);
data_type get_effective_type(data_type left_type, data_type right_type);
value get_const(data_type type, char * str);
returnable* get_lval_from_entry(st_entry* e, int offset, int is_arr);
returnable* get_rval_from_entry(st_entry* e, int offset, int is_arr);
returnable* get_lval_from_returnable(returnable* r, int offset);
returnable* get_rval_from_returnable(returnable* e, int offset);
value get_val_from_entry(st_entry* entry, int mode, int offset, int is_arr);
value get_val_from_returnable(returnable* ret, int mode, int offset);
returnable* get_assign_value(returnable* left, returnable* right);
void set_init_value(st_entry* entry, int offset, returnable* _init_);
returnable* get_arithmetic_value(returnable* left, returnable* right, ast_node_tag op);
char char_arithmetic_value(char left, char right, ast_node_tag op);
char short_arithmetic_value(short left, short right, ast_node_tag op);
int int_arithmetic_value(int left, int right, ast_node_tag op);
long long_arithmetic_value(long left, long right, ast_node_tag op);
float float_arithmetic_value(float left, float right, ast_node_tag op);
double double_arithmetic_value(double left, double right, ast_node_tag op);
void* ptr_arithmetic_value(void* left, int right, ast_node_tag op);
returnable* get_relational_value(returnable* left, returnable* right, ast_node_tag op);
returnable* get_logical_value(returnable* left, returnable* right, ast_node_tag op);
returnable* get_bitwise_value(returnable* left, returnable* right, ast_node_tag op);
returnable* lib_printf(returnable* param_list);
returnable* lib_scanf(returnable* param_list);
char* get_param_num(ast node);
char* itostr(int i);
char* get_unquoted_string(char* s);
int is_lib_func(char* str);
returnable* new_returnable();
returnable* copy_returnable(returnable* orig);
void purge_returnable(returnable* ret);
int is_lib_func(char* str);
char get_char(char* str);

#endif
