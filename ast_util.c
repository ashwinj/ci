#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "ast_util.h"
#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

value alloc_mem(data_type type, int units) {
	value val;
	switch(type) {
	case CHAR:
		val._CHAR_PTR = (char*)safe_malloc(sizeof(char)*units);
		return val;
	case SHORT:
		val._SHORT_PTR = (short*)safe_malloc(sizeof(short)*units);
		return val;
	case INT:
		val._INT_PTR = (int*)safe_malloc(sizeof(int)*units);
		return val;
	case LONG:
		val._LONG_PTR = (long*)safe_malloc(sizeof(long)*units);
		return val;
	case FLOAT:
		val._FLOAT_PTR = (float*)safe_malloc(sizeof(float)*units);
		return val;
	case DOUBLE:
		val._DOUBLE_PTR = (double*)safe_malloc(sizeof(double)*units);
		return val;
	case CHAR_PTR:
		val._CHAR_2PTR = (char**)safe_malloc(sizeof(char*)*units);
		return val;
	case SHORT_PTR:
		val._SHORT_2PTR = (short**)safe_malloc(sizeof(short*)*units);
		return val;
	case INT_PTR:
		val._INT_2PTR = (int**)safe_malloc(sizeof(int*)*units);
		return val;
	case LONG_PTR:
		val._LONG_2PTR = (long**)safe_malloc(sizeof(long*)*units);
		return val;
	case FLOAT_PTR:
		val._FLOAT_2PTR = (float**)safe_malloc(sizeof(float*)*units);
		return val;
	case DOUBLE_PTR:
		val._DOUBLE_2PTR = (double**)safe_malloc(sizeof(double*)*units);
		return val;
	}
}

data_type ptob(data_type type) {
	switch(type) {
	case VOID_PTR:
		return VOID;
	case CHAR_PTR:
		return CHAR;
	case SHORT_PTR:
		return SHORT;
	case INT_PTR:
		return INT;
	case LONG_PTR:
		return LONG;
	case FLOAT_PTR:
		return FLOAT;
	case DOUBLE_PTR:
		return DOUBLE;
	case VOID_2PTR:
		return VOID_PTR;
	case CHAR_2PTR:
		return CHAR_PTR;
	case SHORT_2PTR:
		return SHORT_PTR;
	case INT_2PTR:
		return INT_PTR;
	case LONG_2PTR:
		return LONG_PTR;
	case FLOAT_2PTR:
		return FLOAT_PTR;
	case DOUBLE_2PTR:
		return DOUBLE_PTR;
	}
}

data_type btop(data_type type) {
	switch(type) {
	case VOID:
		return VOID_PTR;
	case CHAR:
		return CHAR_PTR;
	case SHORT:
		return SHORT_PTR;
	case INT:
		return INT_PTR;
	case LONG:
		return LONG_PTR;
	case FLOAT:
		return FLOAT_PTR;
	case DOUBLE:
		return DOUBLE_PTR;
	case VOID_PTR:
		return VOID_2PTR;
	case CHAR_PTR:
		return CHAR_2PTR;
	case SHORT_PTR:
		return SHORT_2PTR;
	case INT_PTR:
		return INT_2PTR;
	case LONG_PTR:
		return LONG_2PTR;
	case FLOAT_PTR:
		return FLOAT_2PTR;
	case DOUBLE_PTR:
		return DOUBLE_2PTR;
	}
}

data_type get_effective_type(data_type left_type, data_type right_type) {
	if(left_type >= right_type) 
		return left_type;
	else
		return right_type;
} 
 
value get_const(data_type type, char * str) {
	char* dup;
	value val;
	switch(type) {
		case CHAR:
			val._CHAR = get_char(str);
			return val;
		case SHORT:
			val._SHORT = atoi(str);
			return val;
		case INT:
			val._INT = atoi(str);
			return val;
		case LONG:
			val._LONG = atol(str);
			return val;
		case FLOAT:
			val._FLOAT = atof(str);
			return val;
		case DOUBLE:
			val._DOUBLE = atof(str);
			return val;
		case CHAR_PTR:
			dup = get_unquoted_string(str);
			val._CHAR_PTR = dup;
			return val;
	}
}

returnable* get_lval_from_entry(st_entry* e, int offset, int is_arr) {
	returnable* ret = new_returnable();
	ret->eval = get_val_from_entry(e, LVAL, offset, is_arr);
	if(is_arr) ret->type = e->symbol_entry_type;
	else ret->type = btop(e->symbol_entry_type);
	return ret;
}

returnable* get_rval_from_entry(st_entry* e, int offset, int is_arr) {
	returnable* ret = new_returnable();
	ret->eval = get_val_from_entry(e, RVAL, offset, is_arr);
	if(is_arr) ret->type = ptob(e->symbol_entry_type);
	else ret->type = e->symbol_entry_type;
	return ret;
}

returnable* get_lval_from_returnable(returnable* r, int offset) {
	returnable* ret = new_returnable();
	ret->eval = get_val_from_returnable(r, LVAL, offset);
	ret->type = r->type;
	return ret;
}

returnable* get_rval_from_returnable(returnable* r, int offset) {
	returnable* ret = new_returnable();
	ret->eval = get_val_from_returnable(r, RVAL, offset);
	ret->type = ptob(r->type);
	return ret;
}

value get_val_from_entry(st_entry* entry, int mode, int offset, int is_arr) {
	value val;
	switch(entry->symbol_entry_type) {
	case VOID:
		if(mode) val._VOID_PTR = NULL;
		else val._INT = 0;
		return val;
	case CHAR:
		if(mode) val._CHAR_PTR = entry->symbol_entry_value.var_val._CHAR_PTR + offset;
		else val._CHAR = *(entry->symbol_entry_value.var_val._CHAR_PTR + offset);
		return val;
	case SHORT:
		if(mode) val._SHORT_PTR = entry->symbol_entry_value.var_val._SHORT_PTR + offset;
		else val._SHORT = *(entry->symbol_entry_value.var_val._SHORT_PTR + offset);
		return val;		
	case INT:
		if(mode) val._INT_PTR = entry->symbol_entry_value.var_val._INT_PTR + offset;
		else val._INT = *(entry->symbol_entry_value.var_val._INT_PTR + offset);
		return val;
	case LONG:
		if(mode) val._LONG_PTR = entry->symbol_entry_value.var_val._LONG_PTR + offset;
		else val._LONG = *(entry->symbol_entry_value.var_val._LONG_PTR + offset);
		return val;
	case FLOAT:
		if(mode) val._FLOAT_PTR = entry->symbol_entry_value.var_val._FLOAT_PTR + offset;
		else val._FLOAT = *(entry->symbol_entry_value.var_val._FLOAT_PTR + offset);
		return val;
	case DOUBLE:
		if(mode) val._DOUBLE_PTR = entry->symbol_entry_value.var_val._DOUBLE_PTR + offset;
		else val._DOUBLE = *(entry->symbol_entry_value.var_val._DOUBLE_PTR + offset);
		return val;
	case VOID_PTR:
		if(mode) val._VOID_2PTR = entry->symbol_entry_value.var_val._VOID_2PTR + offset;
		else val._VOID_PTR = *entry->symbol_entry_value.var_val._VOID_2PTR + offset;
		return val;
	case CHAR_PTR:
		if(is_arr) val._CHAR = *(*entry->symbol_entry_value.var_val._CHAR_2PTR + offset);
		else if(mode) val._CHAR_2PTR = entry->symbol_entry_value.var_val._CHAR_2PTR + offset;
		else val._CHAR_PTR = *entry->symbol_entry_value.var_val._CHAR_2PTR + offset;
		return val;
	case SHORT_PTR:
		if(is_arr) val._SHORT = *(*entry->symbol_entry_value.var_val._SHORT_2PTR + offset);
		else if(mode) val._SHORT_2PTR = entry->symbol_entry_value.var_val._SHORT_2PTR + offset;
		else val._SHORT_PTR = *entry->symbol_entry_value.var_val._SHORT_2PTR + offset;
		return val;
	case INT_PTR:
		if(is_arr) val._INT = *(*entry->symbol_entry_value.var_val._INT_2PTR + offset);
		else if(mode) val._INT_2PTR = entry->symbol_entry_value.var_val._INT_2PTR + offset;
		else val._INT_PTR = *entry->symbol_entry_value.var_val._INT_2PTR + offset;
		return val;
	case LONG_PTR:
		if(is_arr) val._LONG = *(*entry->symbol_entry_value.var_val._LONG_2PTR + offset);
		else if(mode) val._LONG_2PTR = entry->symbol_entry_value.var_val._LONG_2PTR + offset;
		else val._LONG_PTR = *entry->symbol_entry_value.var_val._LONG_2PTR + offset;
		return val;
	case FLOAT_PTR:
		if(is_arr) val._FLOAT = *(*entry->symbol_entry_value.var_val._FLOAT_2PTR + offset);
		else if(mode) val._FLOAT_2PTR = entry->symbol_entry_value.var_val._FLOAT_2PTR + offset;
		else val._FLOAT_PTR = *entry->symbol_entry_value.var_val._FLOAT_2PTR + offset;
		return val;
	case DOUBLE_PTR:
		if(is_arr) val._DOUBLE = *(*entry->symbol_entry_value.var_val._DOUBLE_2PTR + offset);
		else if(mode) val._DOUBLE_2PTR = entry->symbol_entry_value.var_val._DOUBLE_2PTR + offset;
		else val._DOUBLE_PTR = *entry->symbol_entry_value.var_val._DOUBLE_2PTR + offset;
		return val;
	//default:
		//goto ERROR;
	}
}

value get_val_from_returnable(returnable* ret, int mode, int offset) {
	value val;
	switch(ret->type) {
	case VOID_PTR:
		if(mode) val._VOID_PTR = NULL;
		else val._INT = 0;
		return val;
	case CHAR_PTR:
		if(mode) val._CHAR_PTR = ret->eval._CHAR_PTR + offset;
		else val._CHAR = *(ret->eval._CHAR_PTR + offset);
		return val;
	case SHORT_PTR:
		if(mode) val._SHORT_PTR = ret->eval._SHORT_PTR + offset;
		else val._SHORT = *(ret->eval._SHORT_PTR + offset);
		return val;		
	case INT_PTR:
		if(mode) val._INT_PTR = ret->eval._INT_PTR + offset;
		else val._INT = *(ret->eval._INT_PTR + offset);
		return val;
	case LONG_PTR:
		if(mode) val._LONG_PTR = ret->eval._LONG_PTR + offset;
		else val._LONG = *(ret->eval._LONG_PTR + offset);
		return val;
	case FLOAT_PTR:
		if(mode) val._FLOAT_PTR = ret->eval._FLOAT_PTR + offset;
		else val._FLOAT = *(ret->eval._FLOAT_PTR + offset);
		return val;
	case DOUBLE_PTR:
		if(mode) val._DOUBLE_PTR = ret->eval._DOUBLE_PTR + offset;
		else val._DOUBLE = *(ret->eval._DOUBLE_PTR + offset);
		return val;
	case VOID_2PTR:
		if(mode) val._VOID_2PTR = ret->eval._VOID_2PTR + offset;
		else val._VOID_PTR = *ret->eval._VOID_2PTR + offset;
		return val;
	case CHAR_2PTR:
		if(mode) val._CHAR_2PTR = ret->eval._CHAR_2PTR + offset;
		else val._CHAR_PTR = *ret->eval._CHAR_2PTR + offset;
		return val;
	case SHORT_2PTR:
		if(mode) val._SHORT_2PTR = ret->eval._SHORT_2PTR + offset;
		else val._SHORT_PTR = *ret->eval._SHORT_2PTR + offset;
		return val;
	case INT_2PTR:
		if(mode) val._INT_2PTR = ret->eval._INT_2PTR + offset;
		else val._INT_PTR = *ret->eval._INT_2PTR + offset;
		return val;
	case LONG_2PTR:
		if(mode) val._LONG_2PTR = ret->eval._LONG_2PTR + offset;
		else val._LONG_PTR = *ret->eval._LONG_2PTR + offset;
		return val;
	case FLOAT_2PTR:
		if(mode) val._FLOAT_2PTR = ret->eval._FLOAT_2PTR + offset;
		else val._FLOAT_PTR = *ret->eval._FLOAT_2PTR + offset;
		return val;
	case DOUBLE_2PTR:
		if(mode) val._DOUBLE_2PTR = ret->eval._DOUBLE_2PTR + offset;
		else val._DOUBLE_PTR = *ret->eval._DOUBLE_2PTR + offset;
		return val;
	//default:
		//goto ERROR;
	}
}

returnable* get_assign_value(returnable* left, returnable* right) {
	returnable* ret = new_returnable();
	ret->type = ptob(left->type);
	switch(left->type) {	
	case CHAR_PTR:
		*(left->eval._CHAR_PTR) = CHAR_VALUE(right);
		ret->eval._SHORT = *(left->eval._SHORT_PTR);
		return ret;		
	case SHORT_PTR:
		*(left->eval._SHORT_PTR) = SHORT_VALUE(right);
		ret->eval._SHORT = *(left->eval._SHORT_PTR);
		return ret;		
	case INT_PTR:
		*(left->eval._INT_PTR) = INT_VALUE(right);
		ret->eval._INT = *(left->eval._INT_PTR);
		return ret;		
	case LONG_PTR:
		*(left->eval._LONG_PTR) = LONG_VALUE(right);
		ret->eval._LONG = *(left->eval._LONG_PTR);
		return ret;		
	case FLOAT_PTR:
		*(left->eval._FLOAT_PTR) = FLOAT_VALUE(right);
		ret->eval._FLOAT = *(left->eval._FLOAT_PTR);
		return ret;		
	case DOUBLE_PTR:
		*(left->eval._DOUBLE_PTR) = DOUBLE_VALUE(right);
		ret->eval._DOUBLE = *(left->eval._DOUBLE_PTR);
		return ret;	
	case VOID_2PTR:
		*(left->eval._VOID_2PTR) = VOID_PTR_VALUE(right);
		ret->eval._VOID_PTR = *(left->eval._VOID_2PTR);
		return ret;
	case CHAR_2PTR:
		*(left->eval._CHAR_2PTR) = CHAR_PTR_VALUE(right);
		ret->eval._CHAR_PTR = *(left->eval._CHAR_2PTR);
		return ret;		
	case SHORT_2PTR:
		*(left->eval._SHORT_2PTR) = SHORT_PTR_VALUE(right);
		ret->eval._SHORT_PTR = *(left->eval._SHORT_2PTR);
		return ret;		
	case INT_2PTR:
		*(left->eval._INT_2PTR) = INT_PTR_VALUE(right);
		ret->eval._INT_PTR = *(left->eval._INT_2PTR);
		return ret;		
	case LONG_2PTR:
		*(left->eval._LONG_2PTR) = LONG_PTR_VALUE(right);
		ret->eval._LONG_PTR = *(left->eval._LONG_2PTR);
		return ret;		
	case FLOAT_2PTR:
		*(left->eval._FLOAT_2PTR) = FLOAT_PTR_VALUE(right);
		ret->eval._FLOAT_PTR = *(left->eval._FLOAT_2PTR);
		return ret;		
	case DOUBLE_2PTR:
		*(left->eval._DOUBLE_2PTR) = DOUBLE_PTR_VALUE(right);
		ret->eval._DOUBLE_PTR = *(left->eval._DOUBLE_2PTR);
		return ret;
	}
}

void set_init_value(st_entry* entry, int offset, returnable* _init_) {
	switch(entry->symbol_entry_type) {	
	case CHAR:
		*(entry->symbol_entry_value.var_val._CHAR_PTR + offset) = CHAR_VALUE(_init_);
		return;		
	case SHORT:
		*(entry->symbol_entry_value.var_val._SHORT_PTR + offset) = SHORT_VALUE(_init_);
		return;		
	case INT:
		*(entry->symbol_entry_value.var_val._INT_PTR + offset) = INT_VALUE(_init_);
		return;		
	case LONG:
		*(entry->symbol_entry_value.var_val._LONG_PTR + offset) = LONG_VALUE(_init_);
		return;		
	case FLOAT:
		*(entry->symbol_entry_value.var_val._FLOAT_PTR + offset) = FLOAT_VALUE(_init_);
		return;		
	case DOUBLE:
		*(entry->symbol_entry_value.var_val._DOUBLE_PTR + offset) = DOUBLE_VALUE(_init_);
		return;		
	case VOID_PTR:
		*(entry->symbol_entry_value.var_val._VOID_2PTR + offset) = VOID_PTR_VALUE(_init_);
		return;		
	case CHAR_PTR:
		*(entry->symbol_entry_value.var_val._CHAR_2PTR + offset) = CHAR_PTR_VALUE(_init_);
		return;		
	case SHORT_PTR:
		*(entry->symbol_entry_value.var_val._SHORT_2PTR + offset) = SHORT_PTR_VALUE(_init_);
		return;		
	case INT_PTR:
		*(entry->symbol_entry_value.var_val._INT_2PTR + offset) = INT_PTR_VALUE(_init_);
		return;		
	case LONG_PTR:
		*(entry->symbol_entry_value.var_val._LONG_2PTR + offset) = LONG_PTR_VALUE(_init_);
		return;		
	case FLOAT_PTR:
		*(entry->symbol_entry_value.var_val._FLOAT_2PTR + offset) = FLOAT_PTR_VALUE(_init_);
		return;		
	case DOUBLE_PTR:
		*(entry->symbol_entry_value.var_val._DOUBLE_2PTR + offset) = DOUBLE_PTR_VALUE(_init_);
		return;
	}
}

returnable* get_arithmetic_value(returnable* left, returnable* right, ast_node_tag op) {
	returnable* ret = new_returnable();
	ret->type = get_effective_type(left->type, right->type);
	void* l;
	int i;
	//if(op == SUBTRACTION && is_pointer_type(ret->type) && ret->type == right->type) goto ERROR;
	switch(ret->type) {
	case CHAR:
		ret->eval._CHAR = char_arithmetic_value(CHAR_VALUE(left), CHAR_VALUE(right), op);
		return ret;
	case SHORT:
		ret->eval._SHORT = short_arithmetic_value(SHORT_VALUE(left), SHORT_VALUE(right), op);
		return ret;
	case INT:
		ret->eval._INT = int_arithmetic_value(INT_VALUE(left), INT_VALUE(right), op);
		return ret;
	case LONG:
		ret->eval._LONG = long_arithmetic_value(LONG_VALUE(left), LONG_VALUE(right), op);
		return ret;
	case FLOAT:
		ret->eval._FLOAT = float_arithmetic_value(FLOAT_VALUE(left), FLOAT_VALUE(right), op);
		return ret;
	case DOUBLE:
		ret->eval._DOUBLE = double_arithmetic_value(DOUBLE_VALUE(left), DOUBLE_VALUE(right), op);
		return ret;
	case CHAR_PTR:
		ret->eval._CHAR_PTR = (char*)ptr_arithmetic_value((is_pointer_type(left->type) ? VOID_PTR_VALUE(left) : VOID_PTR_VALUE(right)),
									(is_int_type(left->type) ? INT_VALUE(left) : INT_VALUE(right)), op);
		return ret;
	case SHORT_PTR:
		ret->eval._SHORT_PTR = (short*)ptr_arithmetic_value((is_pointer_type(left->type) ? VOID_PTR_VALUE(left) : VOID_PTR_VALUE(right)),
									(is_int_type(left->type) ? INT_VALUE(left) : INT_VALUE(right)), op);
		return ret;
	case INT_PTR:
		ret->eval._INT_PTR = (int*)ptr_arithmetic_value((is_pointer_type(left->type) ? VOID_PTR_VALUE(left) : VOID_PTR_VALUE(right)),
									(is_int_type(left->type) ? INT_VALUE(left) : INT_VALUE(right)), op);
		return ret;
	case LONG_PTR:
		ret->eval._LONG_PTR = (long*)ptr_arithmetic_value((is_pointer_type(left->type) ? VOID_PTR_VALUE(left) : VOID_PTR_VALUE(right)),
									(is_int_type(left->type) ? INT_VALUE(left) : INT_VALUE(right)), op);
		return ret;
	case FLOAT_PTR:
		ret->eval._FLOAT_PTR = (float*)ptr_arithmetic_value((is_pointer_type(left->type) ? VOID_PTR_VALUE(left) : VOID_PTR_VALUE(right)),
									(is_int_type(left->type) ? INT_VALUE(left) : INT_VALUE(right)), op);
		return ret;
	case DOUBLE_PTR:
		ret->eval._DOUBLE_PTR = (double*)ptr_arithmetic_value((is_pointer_type(left->type) ? VOID_PTR_VALUE(left) : VOID_PTR_VALUE(right)),
									(is_int_type(left->type) ? INT_VALUE(left) : INT_VALUE(right)), op);
		return ret;
	//default:
		//goto ERROR;
	}
}

char char_arithmetic_value(char left, char right, ast_node_tag op) {
	switch(op) {
	case MULTIPLICATION:
		return (left * right);
	case DIVISION:
		//if(right == 0) goto ERROR;
		return left/right;
	case MODULO:
		//if(right == 0) goto ERROR;
		return (left % right);
	case ADDITION:
		return (left + right);
	case SUBTRACTION:
		return (left - right);
	case LEFT_SHIFT:
		return (left << right);
	case RIGHT_SHIFT:
		return (left >> right);
	case UNARY_MINUS:
		return (-left);
	}
}

char short_arithmetic_value(short left, short right, ast_node_tag op) {
	switch(op) {
	case MULTIPLICATION:
		return (left * right);
	case DIVISION:
		//if(right == 0) goto ERROR;
		return left/right;
	case MODULO:
		//if(right == 0) goto ERROR;
		return (left % right);
	case ADDITION:
		return (left + right);
	case SUBTRACTION:
		return (left - right);
	case LEFT_SHIFT:
		return (left << right);
	case RIGHT_SHIFT:
		return (left >> right);
	case UNARY_MINUS:
		return (-left);
	}
}

int int_arithmetic_value(int left, int right, ast_node_tag op) {
	switch(op) {
	case MULTIPLICATION:
		return (left * right);
	case DIVISION:
		//if(right == 0) goto ERROR;
		return left/right;
	case MODULO:
		//if(right == 0) goto ERROR;
		return (left % right);
	case ADDITION:
		return (left + right);
	case SUBTRACTION:
		return (left - right);
	case LEFT_SHIFT:
		return (left << right);
	case RIGHT_SHIFT:
		return (left >> right);
	case UNARY_MINUS:
		return (-left);
	}
}

long long_arithmetic_value(long left, long right, ast_node_tag op) {
	switch(op) {
	case MULTIPLICATION:
		return (left * right);
	case DIVISION:
		//if(right == 0) goto ERROR;
		return left/right;
	case MODULO:
		//if(right == 0) goto ERROR;
		return (left % right);
	case ADDITION:
		return (left + right);
	case SUBTRACTION:
		return (left - right);
	case LEFT_SHIFT:
		return (left << right);
	case RIGHT_SHIFT:
		return (left >> right);
	case UNARY_MINUS:
		return (-left);
	}
}

float float_arithmetic_value(float left, float right, ast_node_tag op) {
	switch(op) {
	case MULTIPLICATION:
		return (left * right);
	case DIVISION:
		//if(right == 0) goto ERROR;
		return left/right;
	case ADDITION:
		return (left + right);
	case SUBTRACTION:
		return (left - right);
	case UNARY_MINUS:
		return (-left);
	}
}

double double_arithmetic_value(double left, double right, ast_node_tag op) {
	switch(op) {
	case MULTIPLICATION:
		return (left * right);
	case DIVISION:
		//if(right == 0) goto ERROR;
		return left/right;
	case ADDITION:
		return (left + right);
	case SUBTRACTION:
		return (left - right);
	case UNARY_MINUS:
		return (-left);
	}
}

void* ptr_arithmetic_value(void* left, int right, ast_node_tag op) {
	switch(op) {
	case ADDITION:
		return (left + right);
	case SUBTRACTION:
		return (left - right);
	//default:
		//goto ERROR;
	}
}

returnable* get_relational_value(returnable* left, returnable* right, ast_node_tag op) {
	returnable* ret = new_returnable();
	ret->type = INT;
	switch(op) {
	case REL_LESS:
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) < DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) < DOUBLE_VALUE(right));
		return ret;
	case REL_GREATER:
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) > DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) > DOUBLE_VALUE(right));
		return ret;
	case REL_LESS_EQUAL:
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) <= DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) <= DOUBLE_VALUE(right));
		return ret;
	case REL_GREATER_EQUAL:
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) >= DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) >= DOUBLE_VALUE(right));
		return ret;
	case REL_EQUAL:
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) == DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) == DOUBLE_VALUE(right));
		return ret;
	case REL_NOT_EQUAL:
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) != DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) != DOUBLE_VALUE(right));
		return ret;
	}
}

returnable* get_logical_value(returnable* left, returnable* right, ast_node_tag op) {
	returnable* ret = new_returnable();
	ret->type = INT;
	if(op == LOGICAL_AND) {
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) && DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) && DOUBLE_VALUE(right));
	} else if(op == LOGICAL_OR) {
		ret->eval._INT = is_pointer_type(left->type)?(DOUBLE_PTR_VALUE(left) || DOUBLE_PTR_VALUE(right)):(DOUBLE_VALUE(left) || DOUBLE_VALUE(right));
	} else {
		ret->eval._INT = is_pointer_type(left->type)?(!DOUBLE_PTR_VALUE(left)):(!DOUBLE_VALUE(left));
	}
	return ret;
}

returnable* get_bitwise_value(returnable* left, returnable* right, ast_node_tag op) {
	returnable* ret = new_returnable();
	ret->type = INT;
	switch(op) {
	case BITWISE_AND:
		ret->eval._INT = (INT_VALUE(left) & INT_VALUE(right));
		return ret;
	case BITWISE_OR:
		ret->eval._INT = (INT_VALUE(left) | INT_VALUE(right));
		return ret;
	case BITWISE_XOR:
		ret->eval._INT = (INT_VALUE(left) | INT_VALUE(right));
		return ret;
	case BITWISE_NOT:
		ret->eval._INT = (~INT_VALUE(left));
		return ret;
	}
}

returnable* lib_printf(returnable* param_list) {
	int len, i = 0, count = 0; 
	char* str;
	char flag = 1;
	returnable* ret;
	returnable* param = param_list;
	//if(param == NULL || param->type != CHAR_PTR) goto ERROR;
	str = param->eval._CHAR_PTR;
	param = param->next;
	len = strlen(str);
	while(len >= i) {
		if(str[i] == '%') {
			switch(str[i+1]) {
			case 'c':
				//if(param == NULL) goto ERROR;
				//if(!is_compatible(param->type, CHAR)) goto ERROR; 
				//else {
					count += printf("%c", param->eval._CHAR);
					i += 2;
					break;
				//}
			case 'd':
				//if(param == NULL) goto ERROR;
				//if(!is_compatible(param->type, INT)) goto ERROR;
				//else {
					count += printf("%d", param->eval._INT);
					i += 2;
					break;
				//}
			case 'f':
				//if(param == NULL) goto ERROR;
				//if(!is_compatible(param->type, FLOAT)) goto ERROR;
				//else {
					count += printf("%f", param->eval._FLOAT);
					i += 2;
					break;
				//}
			case 'l':
				if(str[i+2] == 'd') {
					//if(param == NULL) goto ERROR;
					//if(!is_compatible(param->type, LONG)) goto ERROR;
					//else {
						count += printf("%ld", param->eval._LONG);
						i += 3;
						break;
					//}
				} else if(str[i+2] == 'f') {				
					//if(param == NULL) goto ERROR;
					//if(!is_compatible(param->type, DOUBLE)) goto ERROR;
					//else {
						count += printf("%lf", param->eval._DOUBLE);						
						i += 3;
						break;
					//}
				} //else goto ERROR;
			case 's':
				//if(param == NULL) goto ERROR;
				//if(param->type != CHAR_PTR) goto ERROR;
				//else {
					count += printf("%s", param->eval._CHAR_PTR);
					i += 2;
					break;
				//}
			case '%':
				count += printf("%%");
				flag = 0;
				i += 2;
				break;
			//default:
				//goto ERROR;				
			}
			if(flag && param != NULL) param = param->next;
			else flag = 1;
		} else if(str[i] == '\\') {
			switch(str[i+1]) {
			case 't':
				count += printf("\t");
				break;
			case 'n':
				count += printf("\n");
				break;
			case '\\':
				count += printf("\\");
				break;
			case '\'':
				count += printf("\'");
				break;
			case '\"':
				count += printf("\"");
				break;
			case 'v':
				count += printf("\v");
				break;
			case 'b':
				count += printf("\b");
				break;
			case 'a':
				count += printf("\a");
				break;
			case 'f':
				count += printf("\f");
				break;
			case 'r':
				count += printf("\r");
				break;
			case '?':
				count += printf("\?");
				break;
			//default:
				//goto ERROR;				
			}
			i += 2;
		} else {
			count += printf("%c", str[i]);
			i += 1;
		}
	}
	ret = new_returnable();
	ret->type = INT;
	ret->eval._INT = count;
	return ret;
}

returnable* lib_scanf(returnable* param_list) {
	int len, i = 0, count = 0;
	char* str;	
	returnable* ret;
	returnable* param = param_list;
	//if(param == NULL || param->type != CHAR_PTR) goto ERROR;
	str = param->eval._CHAR_PTR;
	param = param->next;
	len = strlen(str);
	while (len > i) {
		//if(str[i] != '%') goto ERROR;
		//else {
			switch(str[i+1]) {
			case 'c':
				//if(param == NULL) goto ERROR;
				//if(!is_compatible(param->type, CHAR_PTR)) goto ERROR; 
				//else {
					count += scanf("%c", param->eval._CHAR_PTR);
					i += 2;
					break;
				//}
			case 'd':
				//if(param == NULL) goto ERROR;
				//if(!is_compatible(param->type, INT_PTR)) goto ERROR;
				//else {
					count += scanf("%d", param->eval._INT_PTR);
					i += 2;
					break;
				//}
			case 'f':
				//if(param == NULL) goto ERROR;
				//if(!is_compatible(param->type, FLOAT_PTR)) goto ERROR;
				//else {
					count += scanf("%f", param->eval._FLOAT_PTR);
					i += 2;
					break;
				//}
			case 'l':
				if(str[i+2]=='d') {
					//if(param == NULL) goto ERROR;
					//if(!is_compatible(param->type, LONG_PTR)) goto ERROR;
					//else {
						count += scanf("%ld", param->eval._LONG_PTR);
						i += 3;
						break;
					//}
				} else if(str[i+2]=='f') {				
					//if(param == NULL) goto ERROR;
					//if(!is_compatible(param->type, DOUBLE_PTR)) goto ERROR;
					//else {
						count += scanf("%lf", param->eval._DOUBLE_PTR);						
						i += 3;
						break;
					//}
				} //else goto ERROR;
			case 's':
				//if(param == NULL) goto ERROR;
				//if(param->type != CHAR_PTR) goto ERROR;
				//else {
					count += scanf("%s", param->eval._CHAR_PTR);
					i += 2;
					break;
				//}
			//default:
				//goto ERROR;				
			}
			if(param != NULL) param = param->next;
		//}
	}
	ret = new_returnable();
	ret->type = INT;
	ret->eval._INT = count;
	return ret;
}

char* get_param_num(ast node) {
	int i = 0;
	ast temp;
	if(node == NULL) return strdup("0");
	else {
		temp = get_left_most_child(node);
		while(temp != NULL) {
			i++;
			temp = get_left_most_sibling(temp);
		}
		return itostr(i);
	}			
}

char* itostr(int i) {
	char* str = (char*)safe_malloc(2*sizeof(int));
	sprintf(str, "%d", i);
	return str;
}

returnable* new_returnable() {
	returnable* ret = (returnable*)safe_malloc(sizeof(returnable));
}

returnable* copy_returnable(returnable* orig) {
	returnable* dup = new_returnable();
	dup->eval = orig->eval;
	dup->type = orig->type;
	return dup;
}

void purge_returnable(returnable* ret) {
	returnable* next;
	if(ret == NULL) return;
	while(ret != NULL) {
		next = ret->next;
		free(ret);
		ret = next;
	}
}

int is_lib_func(char* str) {
	if(!strcmp(str, PRINTF_LABEL)) return 1;
	else if(!strcmp(str, SCANF_LABEL)) return 1;
	else return 0;
}

char* get_unquoted_string(char* s) {
	int i = 0, j = strlen(s)-1;
	char* str = (char*)safe_malloc(sizeof(char)*j);
	for(i =0; i < j-1; i++) str[i] = s[i+1];
	str[j-1] = '\0';
	return str;
}

char get_char(char* s) {
	int x = strlen(s);
	//if(x <= 2) goto ERROR;
	if(s[1] == '\\' && x >= 3) {
		switch(s[2]) {
		case '0':
			return '\0';
		case '\\':
			if(x>= 4 && s[3] == '\'') return s[3];
			else if(x>= 4 && s[3] == '\"') return s[3];
			else return s[2];
		//default:
			//goto ERROR;
		}
	} else return s[1];
}

