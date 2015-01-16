/****************************************************************************************************

	TODO: implement pre/post increment/decrement operations.
	TODO: handle pointer variables. only uncommenting and book keeping required.
	TODO: check double pointer support and resolve any undefined behaviour.
	      REMEMBER:	double_pointers are not allowed in the language. they are for
			VM's internal use.

*****************************************************************************************************/

#include "interpreter.h"
#include "symbol_table.h"
#include "abstract_syntax_tree.h"
#include "ast_evaluator.h"
#include "ast_util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

returnable* eval_constant(ast const_node) {
	value val;
	returnable* ret;
	//if(const_node->tag != CONSTANT) goto ERROR;
	//else {
		val = get_const(const_node->return_type, const_node->ast_node_label);
		ret = new_returnable();
		ret->type = const_node->return_type;
		ret->eval = val;
		return ret;
	//}
}

data_type eval_type(ast type_node) {
	//if(type_node->tag != TYPE) goto ERROR;
	/*else */return type_node->return_type;
}

returnable* eval_var_rval(ast var_node) {
	st_entry* entry = lookup_st_entry(CONTEXT_SYMBOL_TABLE, var_node->ast_node_label);
	if(entry == NULL) {
		entry = lookup_st_entry(global_symbol_table, var_node->ast_node_label);
		//if(entry == NULL) goto ERROR;
	}
	if(entry->symbol_entry_tag == _ARRAY) return get_lval_from_entry(entry, 0, 0);
	else return get_rval_from_entry(entry, 0, 0);
}

returnable* eval_var_lval(ast var_node) {
	st_entry* entry = lookup_st_entry(CONTEXT_SYMBOL_TABLE, var_node->ast_node_label);
	if(entry == NULL) {
		entry = lookup_st_entry(global_symbol_table, var_node->ast_node_label);
		//if(entry == NULL) goto ERROR;
	}
	return get_lval_from_entry(entry, 0, 0);
}

returnable* eval_arr_rval(ast arr_node) {
	ast left_;
	returnable* left;
	st_entry* entry;
	//if(arr_node->tag != ARRAY) goto ERROR;
	left_ = get_left_most_child(arr_node);
	entry = lookup_st_entry(CONTEXT_SYMBOL_TABLE, arr_node->ast_node_label);
	if(entry == NULL) {
		entry = lookup_st_entry(global_symbol_table, arr_node->ast_node_label);
		//if(entry == NULL) goto ERROR;
	}
	//if(left_ == NULL) goto ERROR;
	left = eval_exp(left_, RVAL);
	if(entry->symbol_entry_tag == _VARIABLE) {
		if(is_pointer_type(entry->symbol_entry_type)) 
			return get_rval_from_entry(entry, left->eval._INT, 1);
		//else goto ERROR;
	}
	//if(!is_int_type(left->type)) goto ERROR;
	return get_rval_from_entry(entry, left->eval._INT, 0);
}

returnable* eval_arr_lval(ast arr_node) {
	ast left_;
	returnable* left;
	st_entry* entry;
	//if(arr_node->tag != ARRAY) goto ERROR;
	left_ = get_left_most_child(arr_node);
	entry = lookup_st_entry(CONTEXT_SYMBOL_TABLE, arr_node->ast_node_label);
	if(entry == NULL) {
		entry = lookup_st_entry(global_symbol_table, arr_node->ast_node_label);
		//if(entry == NULL) goto ERROR;
	}
	//if(left_ == NULL) goto ERROR;
	left = eval_exp(left_, RVAL);
	if(entry->symbol_entry_tag == _VARIABLE) {
		if(is_pointer_type(entry->symbol_entry_type)) 
			return get_rval_from_entry(entry, left->eval._INT, 0);
		//else goto ERROR;
	}
	//if(!is_int_type(left->type)) goto ERROR;
	return get_lval_from_entry(entry, left->eval._INT, 0);
}

returnable* eval_func_call(ast node) {
	st_entry* entry;
	ast left;
	ast func_def;
	returnable* ret;
	returnable* param_list;
	ar* record;
	left = get_left_most_child(node);
	if(left != NULL) param_list = eval_param_list(left);
	else param_list = NULL;
	if(is_lib_func(node->ast_node_label)) return exec_lib_func(node->ast_node_label, param_list);
	entry = lookup_st_entry(global_symbol_table, node->ast_node_label);				
	//if(entry == NULL || entry->symbol_entry_tag != _FUNCTION) goto ERROR;			
	func_def = asts[entry->symbol_entry_value.ast_ref_index];
	record = new_ar(strdup(entry->symbol_entry_label));
	push_ar(record);
	exec_func(func_def, param_list);
	if(param_list != NULL) purge_returnable(param_list);
	if(CONTEXT_RETURN_VALUE == NULL) {
		CONTEXT_RETURN_VALUE = new_returnable();
		CONTEXT_RETURN_VALUE->type = VOID;
		CONTEXT_RETURN_VALUE->eval._INT = 0;
	}
	ret = copy_returnable(CONTEXT_RETURN_VALUE);
	purge_ar(pop_ar());
	return ret;
}

int exec_func(ast func_def, returnable* param_list) {
	ast temp;
	ast var;
	ast param;
	st_entry* entry;
	returnable* p = param_list;
	int x = (eval_constant(get_left_most_child(func_def)))->eval._INT;
	//if((!x && p != NULL) || (x && p == NULL) || (x && p != NULL && x != get_list_size(p))) goto ERROR;
	temp = get_left_most_sibling(get_left_most_child(func_def));
	param = get_left_most_child(temp);
	while(x && p != NULL) {
		eval_var_decl(CONTEXT_SYMBOL_TABLE, param);
		var = get_left_most_child(get_left_most_sibling(get_left_most_child(param)));
		entry = lookup_st_entry(CONTEXT_SYMBOL_TABLE, var->ast_node_label);
		//if(!is_compatible(entry->symbol_entry_type,p->type)) goto ERROR;
		//else {
			set_init_value(entry, 0, p);
		//}
		p = p->next;
		param = get_left_most_sibling(param);
		x--;
	}
	if(param_list != NULL) {
		temp = get_left_most_sibling(temp);
	}
	if(temp->tag == VAR_TYPE_DECL_LIST) return eval_context_var_decl_list(temp);
	else if(temp->tag == STATEMENT_LIST) return eval_stmt_list(temp);
	else return eval_block_stmt(temp);
}

returnable* exec_lib_func(char* func, returnable* param_list) {
	if(!strcmp(func, PRINTF_LABEL)) return lib_printf(param_list);
	else if(!strcmp(func, SCANF_LABEL)) return lib_scanf(param_list);
	//else goto ERROR;
}

returnable* eval_param_list(ast param_list) {
	ast temp = get_left_most_child(param_list);
	returnable* ret = NULL;
	returnable* count = NULL;
	while(temp != NULL) {
		if(ret == NULL) {
			ret = eval_exp(temp, RVAL);
			count = ret;
		} else {
			count->next = eval_exp(temp, RVAL);
			count = count->next;
		}
		temp = get_left_most_sibling(temp);
	}
	return ret;
}

returnable* eval_exp(ast exp_node, int mode) {
	switch(exp_node->tag) {
	case VARIABLE:
		if(mode) return eval_var_lval(exp_node);
		else return eval_var_rval(exp_node);
	case ARRAY:
		if(mode) return eval_arr_lval(exp_node);
		else return eval_arr_rval(exp_node);
	case CONSTANT:
		return eval_constant(exp_node);
	case EXP_LIST:
		return eval_exp_list(exp_node);
	case ASSIGNMENT:
		return eval_assign_exp(exp_node);
	case MULTIPLICATION:
		return eval_arithmetic_exp(exp_node);
	case DIVISION:
		return eval_arithmetic_exp(exp_node);
	case MODULO:
		return eval_arithmetic_exp(exp_node);
	case ADDITION:
		return eval_arithmetic_exp(exp_node);
	case SUBTRACTION:
		return eval_arithmetic_exp(exp_node);
	case LEFT_SHIFT:
		return eval_shift_exp(exp_node);
	case RIGHT_SHIFT:
		return eval_shift_exp(exp_node);
	case REL_LESS:
		return eval_rel_exp(exp_node);
	case REL_GREATER:
		return eval_rel_exp(exp_node);
	case REL_LESS_EQUAL:
		return eval_rel_exp(exp_node);
	case REL_GREATER_EQUAL:
		return eval_rel_exp(exp_node);
	case REL_EQUAL:
		return eval_rel_exp(exp_node);
	case REL_NOT_EQUAL:
		return eval_rel_exp(exp_node);
	case BITWISE_AND:
		return eval_bitwise_exp(exp_node);
	case BITWISE_OR:
		return eval_bitwise_exp(exp_node);
	case BITWISE_XOR:
		return eval_bitwise_exp(exp_node);
	case BITWISE_NOT:
		return eval_bitwise_exp(exp_node);
	case LOGICAL_AND:
		return eval_logical_exp(exp_node);
	case LOGICAL_OR:
		return eval_logical_exp(exp_node);
	case LOGICAL_NOT:
		return eval_logical_exp(exp_node);
	case CONDITIONAL:
		return eval_conditional_exp(exp_node);
	case REFERENCE:
		return eval_ref_exp(exp_node);
	case DEREFERENCE:
		return eval_deref_exp(exp_node, mode);
	case UNARY_MINUS:
		return eval_unary_minus_exp(exp_node);
	case PRE_INCREMENT:
	case POST_INCREMENT:
	case PRE_DECREMENT:
	case POST_DECREMENT:
	case CALL:
		return eval_func_call(exp_node);
	}
}

returnable* eval_exp_list(ast node) {
	ast left_;
	returnable* ret;
	left_ = get_left_most_child(node);
	if(left_ == NULL) {
		ret = new_returnable();
		ret->type = INT;
		ret->eval._INT = 1;
		return ret;
	} else if(get_left_most_sibling(left_) == NULL) {
		return eval_exp(left_, RVAL);
	} else {
		do {
			eval_exp(left_, RVAL);
			left_ = get_left_most_sibling(left_);
		} while(left_ != NULL);
		ret = new_returnable();
		ret->type = INT;
		ret->eval._INT = 1;
		return ret;
	}
}

returnable* eval_assign_exp(ast node) {
	ast left_;
	ast right_;
	returnable* left;
	returnable* right;
	returnable* ret;
	left_ = get_left_most_child(node);
	//if(!is_lval_type(left_)) goto ERROR;
	right_ = get_left_most_sibling(left_);
	left = eval_exp(left_, LVAL);
	right = eval_exp(right_, RVAL);
	//if(!is_compatible(ptob(left->type),right->type)) goto ERROR;
	ret = get_assign_value(left, right);
	return ret;
}	

returnable* eval_arithmetic_exp(ast node) {
	ast left_;
	ast right_;
	returnable* left;
	returnable* right;
	returnable* ret;
	left_ = get_left_most_child(node);
	right_ = get_left_most_sibling(left_);
	left = eval_exp(left_, RVAL);
	right = eval_exp(right_, RVAL);
	//if(is_arithmetic_type(ret->type)) {
		ret = get_arithmetic_value(left, right, node->tag);
		return ret;
	/*} else {
		goto ERROR;
	}*/
}

returnable* eval_shift_exp(ast node) {
	ast left_;
	ast right_;
	returnable* left;
	returnable* right;
	returnable* ret;
	left_ = get_left_most_child(node);
	right_ = get_left_most_sibling(left_);
	left = eval_exp(left_, RVAL);
	right = eval_exp(right_, RVAL);
	//if(is_int_type(left->type) && is_int_type(right->type)) {
		ret = get_arithmetic_value(left, right, node->tag);
		return ret;
	/*} else {
		goto ERROR;
	}*/
}	

returnable* eval_rel_exp(ast node) {
	ast left_;
	ast right_;
	returnable* left;
	returnable* right;
	returnable* ret;
	left_ = get_left_most_child(node);
	right_ = get_left_most_sibling(left_);
	left = eval_exp(left_, RVAL);
	right = eval_exp(right_, RVAL);
	//if(is_compatible(left->type,right->type)) {
		ret = get_relational_value(left, right, node->tag);
		return ret;
	/*} else {
		goto ERROR;
	}*/
}

returnable* eval_bitwise_exp(ast node) {
	ast left_;
	ast right_;
	returnable* left;
	returnable* right = NULL;
	returnable* ret;
	left_ = get_left_most_child(node);
	right_ = get_left_most_sibling(left_);
	left = eval_exp(left_, RVAL);
	if(right_ != NULL) right = eval_exp(right_, RVAL);
	//if(is_int_type(left->type) && is_int_type(right->type)) {
		ret = get_bitwise_value(left, right, node->tag);
		return ret;
	/*} else {
		goto ERROR;
	}*/
}

returnable* eval_logical_exp(ast node) {
	ast left_;
	ast right_;
	returnable* left;
	returnable* right=NULL;
	returnable* ret;
	left_ = get_left_most_child(node);
	right_ = get_left_most_sibling(left_);
	left = eval_exp(left_, RVAL);
	if(right_ != NULL) right = eval_exp(right_, RVAL);
	ret = get_logical_value(left, right, node->tag);
	return ret;
}

returnable* eval_conditional_exp(ast node) {
	ast condition_;
	ast true_case_;
	ast false_case_;
	returnable* condition;
	condition_ = get_left_most_child(node);
	true_case_ = get_left_most_sibling(condition_);
	false_case_= get_left_most_sibling(true_case_);
	condition = eval_exp(condition_, RVAL);
	//if(condition->type != INT) goto ERROR; 
	if(condition->eval._INT)
		return (eval_exp(true_case_, RVAL));
	else
		return (eval_exp(false_case_, RVAL));
}

returnable* eval_unary_minus_exp(ast node) {
	returnable* exp;
	returnable* ret;
	exp=eval_exp(get_left_most_child(node), RVAL);
	//if(!is_arithmetic_type(exp)) goto ERROR;
 	ret = get_arithmetic_value(exp,NULL,node->tag);
	return ret;
}

returnable* eval_deref_exp(ast node, int mode) {
	ast left_;
	returnable* left;
	left_ = get_left_most_child(node);
	left = eval_exp(left_, RVAL);
	//if(!is_pointer_type(left->type)) goto ERROR;
	if(mode == RVAL) {
		return get_rval_from_returnable(left, 0);
	} else {
		return get_lval_from_returnable(left, 0);
	}
}

returnable* eval_ref_exp(ast node) {
	ast left_;
	returnable* left;
	left_ = get_left_most_child(node);
	left = eval_exp(left_, LVAL);
	//if(!is_pointer_type(left->type)) goto ERROR;
	return left;
}

int eval_stmt(ast stmt_node) {
	if(stmt_node == NULL) return 1;
	switch(stmt_node->tag) {
	case FOR_STATEMENT:
		return eval_for_stmt(stmt_node);
	case WHILE_STATEMENT:
		return eval_while_stmt(stmt_node);
	case IF_STATEMENT:
		return eval_if_stmt(stmt_node);
	case BLOCK:
		return eval_block_stmt(stmt_node);
	case RETURN_STATEMENT:
		return eval_return_stmt(stmt_node);
	case BREAK_STATEMENT:
		return eval_break_stmt(stmt_node);
	case CONTINUE_STATEMENT:
		return eval_continue_stmt(stmt_node);
	case STATEMENT_LIST:
		return eval_stmt_list(stmt_node);
	case EXPRESSION_STATEMENT:
		return eval_exp_stmt(stmt_node);
	//default:
		//goto ERROR;
	}
}

int eval_for_stmt(ast node) {
	int loop_flag = 0;
	int condition;
	ast init_node_ = get_left_most_child(node);
	ast condition_ = get_left_most_sibling(init_node_);
	ast stmt_ = get_left_most_sibling(condition_);
        ast inc_exp_node_ = get_left_most_sibling(stmt_);
	eval_stmt(init_node_);
	condition = eval_stmt(condition_);
	if(!is_loop_env) {
		CONTEXT_ENV |= LOOP_ENV;
		loop_flag = 1;
	}	
	while(condition) {
		eval_stmt(stmt_);
		if(CONTEXT_RETURN_VALUE != NULL) return 1;
		else if(is_break_condition) {
			CONTEXT_ENV ^= BREAK_ENV;
			break;
		} else if(is_continue_condition) {
			CONTEXT_ENV ^= CONTINUE_ENV;
		}
		eval_exp(inc_exp_node_, RVAL);
		condition=eval_stmt(condition_);
	}
	if(loop_flag) CONTEXT_ENV ^= LOOP_ENV;
	return 1;
}

int eval_while_stmt(ast node) {
	int loop_flag = 0;
	ast condition_ = get_left_most_child(node);
	ast stmt_ = get_left_most_sibling(condition_);
	returnable* condition = eval_exp(condition_, RVAL);
	if(!is_loop_env) {
		CONTEXT_ENV |= LOOP_ENV;
		loop_flag = 1;
	}
	while(condition->eval._INT) {
		eval_stmt(stmt_);
		if(CONTEXT_RETURN_VALUE != NULL) return 1;
		else if(is_break_condition) {
			CONTEXT_ENV ^= BREAK_ENV;
			break;
		} else if(is_continue_condition) {
			CONTEXT_ENV ^= CONTINUE_ENV;
		}
		condition = eval_exp(condition_, RVAL);
	}
	if(loop_flag) CONTEXT_ENV ^= LOOP_ENV;
	return 1;
}

int eval_if_stmt(ast node) {
	ast condition_;
	ast true_case_;
	ast false_case_;
	returnable* condition;
	condition_= get_left_most_child(node);
	true_case_= get_left_most_sibling(condition_);
	false_case_= get_left_most_sibling(true_case_);
	condition = eval_exp(condition_, RVAL);
	//if(condition->type != INT) goto ERROR; 
	if(condition->eval._INT)
		eval_stmt(true_case_);
	else
		eval_stmt(false_case_);
	return 1;
}

int eval_exp_stmt(ast node) {
	ast exp_;
	returnable* exp;
	exp_= get_left_most_child(node);
	if(exp_ == NULL) return 1;
	else return eval_exp(exp_, RVAL)->eval._INT;
}

int eval_block_stmt(ast node) {
	ast left_;
	ast right_;
	left_ = get_left_most_child(node);
	right_ = get_left_most_sibling(left_);
	if(left_ != NULL) {
		eval_context_var_decl_list(left_);
	}
	if(right_ != NULL) {
		eval_stmt_list(right_);
	}
	return 1;
}

void eval_func_def(ast function) {
	int x = set_ast_root_reference(function);
	symbol_value_type val;
	st_entry* entry;
	val.ast_ref_index = x;
	entry = new_st_entry(_FUNCTION, strdup(function->ast_node_label), function->return_type, val);
	insert_st_entry(global_symbol_table, entry);
}

void eval_main_def(ast _main_) {
	int x = set_ast_root_reference(_main_);
	symbol_value_type val;
	st_entry* entry;
	val.ast_ref_index = x;
	entry = new_st_entry(_FUNCTION, strdup(_main_->ast_node_label), _main_->return_type, val);
	insert_st_entry(global_symbol_table, entry);
}

int eval_return_stmt(ast stmt) {
	ast left_;
	returnable* ret;
	ar* cur_rec;
	left_ = get_left_most_child(stmt);
	if(left_ != NULL)
		ret = eval_exp(left_, RVAL);
	else {
		ret->type = VOID;
		ret->eval._INT = 0;
	}
	CONTEXT_RETURN_VALUE = copy_returnable(ret);
	return 1;
}

int eval_break_stmt(ast stmt) {
	if(CONTEXT_ENV & LOOP_ENV) CONTEXT_ENV |= BREAK_ENV;
	return 1;
}

int eval_continue_stmt(ast stmt) {
	if(CONTEXT_ENV & LOOP_ENV) CONTEXT_ENV |= CONTINUE_ENV;
	return 1;
}

int eval_stmt_list(ast node) {
	ast left_;
	left_ = get_left_most_child(node);
	if(left_ == NULL) return 1;
	else {
		do {
			eval_stmt(left_);
			if(is_jmp_condition) return 1;
			left_ = get_left_most_sibling(left_);
		} while(left_ != NULL);
		return 1;
	}
}

int eval_global_var_decl(ast global_decl) {
	eval_var_decl(global_symbol_table, global_decl);
	purge_ast(global_decl);
	return 1;
}

int eval_context_var_decl_list(ast context_decl) {
	eval_var_decl_list(CONTEXT_SYMBOL_TABLE, context_decl);
	return 1;
}

int eval_var_decl_list(st* table, ast vtdl) {
	ast temp;
	//if(!vdl->tag == VAR_TYPE_DECL_LIST) goto ERROR;
	//else {
		temp = get_left_most_child(vtdl);
		while(temp != NULL) {
			eval_var_decl(table, temp);
			temp = get_left_most_sibling(temp);
		}
	//}
	return 1;
}

int eval_var_decl(st* table, ast variable) {
	ast var;
	ast init;
	ast type = get_left_most_child(variable);
	data_type t = eval_type(type);
	ast decl_list = get_left_most_sibling(type);
	ast temp = get_left_most_child(decl_list);
	while(temp != NULL) {
		if(temp->tag == ASSIGNMENT) {
			var = get_left_most_child(temp);
			init = get_left_most_sibling(var);
		} else {
			var = temp;
			init = NULL;
		}
		decl_var(table, t, var);
		if(init != NULL) init_var(table, var->ast_node_label, init);
		temp = get_left_most_sibling(temp);
	}
	return 1;
}

int decl_var(st* table, data_type type, ast var) {
	st_entry* entry;
	symbol_value_type sev;
	//if(lookup_st_entry(table, var->ast_node_label) != NULL) goto ERROR;
	if(var->tag == ARRAY) {
		decl_arr(table, type, var);
	} else {
		sev.var_val = alloc_mem(type, 1);
		entry = new_st_entry(_VARIABLE, strdup(var->ast_node_label), type, sev);
		insert_st_entry(table, entry);
	}
	return 1;
}

int decl_arr(st* table, data_type type, ast var) {
	ast offset;
	returnable* ret;
	st_entry* entry;
	symbol_value_type sev;
	//if(!is_basic_type(type)) goto ERROR;
	offset = get_left_most_child(var);
	//if(offset == NULL) goto ERROR;
	ret = eval_exp(offset, RVAL);
	//if(!is_int_type(ret->type)) goto ERROR;
	sev.var_val = alloc_mem(type, ret->eval._INT);
	entry = new_st_entry(_ARRAY, strdup(var->ast_node_label), type, sev);
	insert_st_entry(table, entry);
	return 1;
}

int init_var(st* table, char* var, ast init_exp) {
	st_entry* entry;
	returnable* ret;
	entry = lookup_st_entry(table, var);
	//if(entry == NULL) goto ERROR;
	if(entry->symbol_entry_tag == _ARRAY) init_arr(entry, init_exp);
	else {
		//if(init_exp->tag == INIT_LIST) goto ERROR;
		ret = eval_exp(init_exp, RVAL);
		//if(!is_compatible(entry->symbol_entry_type, ret->type)) goto ERROR;
		set_init_value(entry, 0, ret);
	}
	return 1;
}

int init_arr(st_entry* entry, ast init_list) {
	int i;
	ast temp;
	returnable* ret;
	temp = get_left_most_child(init_list);
	//if(init_list->tag != INIT_LIST) goto ERROR;
	for(i = 0; temp != NULL; i++) {
		ret = eval_exp(temp, RVAL);
		//if(!is_compatible(entry->symbol_entry_type, ret->type)) goto ERROR;
		set_init_value(entry, i, ret);
		temp = get_left_most_sibling(temp);
	}
	return 1;
}

