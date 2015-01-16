%{
#include <stdio.h>
#include "interpreter.h"
#include "abstract_syntax_tree.h"
#include "ast_builder.h"
#include "symbol_table.h"
#include "vm.h"

//#define YYDEBUG 1
%}

%union {
	ast node;
	char unary_code;
	char* string;
	assignment_code assign_code;
}

%token MAIN_DEFINITION LIB_PRINTF LIB_SCANF

%token <string> CHAR_CONSTANT HEX_INT_CONSTANT OCT_INT_CONSTANT DEC_INT_CONSTANT
%token <string> HEX_LONG_CONSTANT OCT_LONG_CONSTANT DEC_LONG_CONSTANT FLOAT_CONSTANT
%token <string> DOUBLE_CONSTANT IDENTIFIER STRING_LITERAL

%token INC_OP DEC_OP LEFT_SHIFT_OP RIGHT_SHIFT_OP
%token LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP

%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN 
%token LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN

%token CHAR_TYPE SHORT_TYPE INT_TYPE LONG_TYPE FLOAT_TYPE DOUBLE_TYPE VOID_TYPE

%token IF ELSE WHILE FOR CONTINUE BREAK RETURN

%type <node> constant type primary_expression postfix_expression unary_expression cast_expression multiplicative_expression
%type <node> additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression
%type <node> inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression
%type <node> expression constant_expression initializer declarator variable_declarator variable_declaration statement compound_statement
%type <node> expression_statement selection_statement iteration_statement jump_statement parameter function_definition function_call
%type <node> global_declaration main_prototype main_definition translation_unit script initializer_list variable_declarator_list 
%type <node> variable_declaration_list statement_list parameter_list argument_expression_list printf_call scanf_call

%type <unary_code> unary_operator

%type <assign_code> assignment_operator

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start script

%%

constant
	: CHAR_CONSTANT				{ $$ = new_constant_node($1, CHAR); }
	| HEX_INT_CONSTANT			{ $$ = new_constant_node($1, INT); }
	| OCT_INT_CONSTANT			{ $$ = new_constant_node($1, INT); }
	| DEC_INT_CONSTANT			{ $$ = new_constant_node($1, INT); }
	| FLOAT_CONSTANT			{ $$ = new_constant_node($1, FLOAT); }
	| DOUBLE_CONSTANT			{ $$ = new_constant_node($1, DOUBLE); }
	| HEX_LONG_CONSTANT			{ $$ = new_constant_node($1, LONG); }
	| OCT_LONG_CONSTANT			{ $$ = new_constant_node($1, LONG); }
	| DEC_LONG_CONSTANT			{ $$ = new_constant_node($1, LONG); }
	;

type
	: VOID_TYPE				{ $$ = new_type_node("void", VOID); }
	| CHAR_TYPE				{ $$ = new_type_node("char", CHAR); }
	| SHORT_TYPE				{ $$ = new_type_node("short", SHORT); }
	| INT_TYPE				{ $$ = new_type_node("int", INT); }
	| FLOAT_TYPE				{ $$ = new_type_node("float", FLOAT); }
	| DOUBLE_TYPE				{ $$ = new_type_node("double", DOUBLE); }
	| LONG_TYPE				{ $$ = new_type_node("long", LONG); }
	| VOID_TYPE '*'				{ $$ = new_type_node("void pointer", VOID_PTR); }
	| CHAR_TYPE '*'				{ $$ = new_type_node("char pointer", CHAR_PTR); }
	| SHORT_TYPE '*'			{ $$ = new_type_node("short pointer", SHORT_PTR); }
	| INT_TYPE '*'				{ $$ = new_type_node("int pointer", INT_PTR); }
	| FLOAT_TYPE '*'			{ $$ = new_type_node("float pointer", FLOAT_PTR); }
	| DOUBLE_TYPE '*'			{ $$ = new_type_node("double pointer", DOUBLE_PTR); }
	| LONG_TYPE '*'				{ $$ = new_type_node("long pointer", LONG_PTR); }
	;

primary_expression
	: IDENTIFIER				{ $$ = new_variable_node($1, UNDEFINED); }
	| constant				{ $$ = $1; }
	| STRING_LITERAL			{ $$ = new_constant_node($1, CHAR_PTR); }
	| '(' expression ')'			{ $$ = $2; }
	;

postfix_expression
	: primary_expression			{ $$ = $1; }
	| IDENTIFIER '[' expression ']'		{ $$ = new_array_variable_node($1, $3, UNDEFINED); }
	| function_call				{ $$ = $1; }
	| printf_call				{ $$ = $1; }	
	| scanf_call				{ $$ = $1; }
	| postfix_expression INC_OP		{ $$ = new_inc_exp_node(POST_INCREMENT, $1); }
	| postfix_expression DEC_OP		{ $$ = new_dec_exp_node(POST_DECREMENT, $1); }
	;

unary_expression
	: postfix_expression			{ $$ = $1; }
	| INC_OP unary_expression		{ $$ = new_inc_exp_node(PRE_INCREMENT, $2); }
	| DEC_OP unary_expression		{ $$ = new_dec_exp_node(PRE_DECREMENT, $2); }
	| unary_operator cast_expression	{ $$ = new_unary_exp_node($1, $2); }
	;

unary_operator
	: '&'					{ $$ = '&'; }
	| '*'					{ $$ = '*'; }
	| '-'					{ $$ = '-'; }
	| '~'					{ $$ = '~'; }
	| '!'					{ $$ = '!'; }
	;

cast_expression
	: unary_expression			{ $$ = $1; }
	| '(' type ')' cast_expression		{ $$ = new_cast_node($2, $4); }
	;

multiplicative_expression
	: cast_expression							{ $$ = $1; }
	| multiplicative_expression '*' cast_expression				{ $$ = new_mul_exp_node($1, MULTIPLICATION, $3); }
	| multiplicative_expression '/' cast_expression				{ $$ = new_mul_exp_node($1, DIVISION, $3); }
	| multiplicative_expression '%' cast_expression				{ $$ = new_mul_exp_node($1, MODULO, $3); }
	;

additive_expression
	: multiplicative_expression						{ $$ = $1; }
	| additive_expression '+' multiplicative_expression			{ $$ = new_add_exp_node($1, ADDITION, $3); }
	| additive_expression '-' multiplicative_expression			{ $$ = new_add_exp_node($1, SUBTRACTION, $3); } 	
	;

shift_expression
	: additive_expression							{ $$ = $1; }
	| shift_expression LEFT_SHIFT_OP additive_expression			{ $$ = new_shift_exp_node($1, LEFT_SHIFT, $3); }
	| shift_expression RIGHT_SHIFT_OP additive_expression			{ $$ = new_shift_exp_node($1, RIGHT_SHIFT, $3); }
	;

relational_expression
	: shift_expression							{$$ = $1; }
	| relational_expression '<' shift_expression				{ $$ = new_rel_exp_node($1, REL_LESS, $3); }
	| relational_expression '>' shift_expression				{ $$ = new_rel_exp_node($1, REL_GREATER, $3); }
	| relational_expression LE_OP shift_expression				{ $$ = new_rel_exp_node($1, REL_LESS_EQUAL, $3); }
	| relational_expression GE_OP shift_expression				{ $$ = new_rel_exp_node($1, REL_GREATER_EQUAL, $3); }
	;

equality_expression
	: relational_expression							{ $$ = $1; }
	| equality_expression EQ_OP relational_expression			{ $$ = new_rel_exp_node($1, REL_EQUAL, $3); }
	| equality_expression NE_OP relational_expression			{ $$ = new_rel_exp_node($1, REL_NOT_EQUAL, $3); }
	;

and_expression
	: equality_expression							{ $$ = $1; }
	| and_expression '&' equality_expression				{ $$ = new_bit_exp_node($1, BITWISE_AND, $3); }
	;

exclusive_or_expression
	: and_expression							{ $$ = $1; }
	| exclusive_or_expression '^' and_expression				{ $$ = new_bit_exp_node($1, BITWISE_XOR, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression						{ $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression			{ $$ = new_bit_exp_node($1, BITWISE_OR, $3); }
	;

logical_and_expression
	: inclusive_or_expression						{ $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression			{ $$ = new_logic_exp_node($1, LOGICAL_AND, $3); }
	;

logical_or_expression
	: logical_and_expression						{ $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression			{ $$ = new_logic_exp_node($1, LOGICAL_OR, $3); }
	;

conditional_expression
	: logical_or_expression							{ $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression	{ $$ = new_cond_exp_node($1, $3, $5); }
	;

assignment_expression
	: conditional_expression						{ $$ = $1; }
	| unary_expression assignment_operator assignment_expression		{ $$ = new_assign_exp_node($1, $2, $3); }
	;

assignment_operator
	: '='									{ $$ = EQ_ASSIGN_CODE; }
	| MUL_ASSIGN								{ $$ = MUL_ASSIGN_CODE; }
	| DIV_ASSIGN								{ $$ = DIV_ASSIGN_CODE; }
	| MOD_ASSIGN								{ $$ = MOD_ASSIGN_CODE; }
	| ADD_ASSIGN								{ $$ = ADD_ASSIGN_CODE; }
	| SUB_ASSIGN								{ $$ = SUB_ASSIGN_CODE; }
	| LEFT_ASSIGN								{ $$ = LEFT_ASSIGN_CODE; }
	| RIGHT_ASSIGN								{ $$ = RIGHT_ASSIGN_CODE; }
	| AND_ASSIGN								{ $$ = AND_ASSIGN_CODE; }
	| XOR_ASSIGN								{ $$ = XOR_ASSIGN_CODE; }
	| OR_ASSIGN								{ $$ = OR_ASSIGN_CODE; }
	;

expression
	: assignment_expression							{ $$ = new_exp_list_node($1); }
	| expression ',' assignment_expression					{ $$ = append_exp_list_node($1, $3); }
	;

constant_expression
	: conditional_expression						{ $$ = $1; }
	;

initializer
	: assignment_expression							{ $$ = $1; }
	| '{' initializer_list '}'						{ $$ = $2; }
	;

initializer_list
	: initializer								{ $$ = new_init_list_node($1); }
	| initializer_list ',' initializer					{ $$ = append_init_list_node($1, $3); }
	;

declarator
	: IDENTIFIER								{ $$ = new_variable_node($1, UNDEFINED); }
	| IDENTIFIER '[' constant_expression ']'				{ $$ = new_array_variable_node($1, $3, UNDEFINED); }  
	;

variable_declarator
	: declarator								{ $$ = $1; }
	| declarator '=' initializer						{ $$ = new_assign_exp_node($1, EQ_ASSIGN_CODE, $3); }
	;

variable_declarator_list
	: variable_declarator							{ $$ = new_var_decl_list_node($1); }
	| variable_declarator_list ',' variable_declarator			{ $$ = append_var_decl_list_node($1, $3); }
	;

variable_declaration
	: type variable_declarator_list ';'					{ $$ = new_decl_node($1, $2); }
	;

variable_declaration_list
	: variable_declaration							{ $$ = new_var_type_decl_list_node($1); }
	| variable_declaration_list variable_declaration			{ $$ = append_var_type_decl_list_node($1, $2); }
	;

statement
	: compound_statement							{ $$ = $1; }
	| expression_statement							{ $$ = $1; }
	| selection_statement							{ $$ = $1; }
	| iteration_statement							{ $$ = $1; }
	| jump_statement							{ $$ = $1; }
	;

statement_list
	: statement								{ $$ = new_stmt_list_node($1); }
	| statement_list statement						{ $$ = append_stmt_list_node($1, $2); }
	;

expression_statement
	: ';'									{ $$ = new_exp_stmt_node(NULL); }
	| expression ';'							{ $$ = new_exp_stmt_node($1); }
	;

selection_statement
	: IF '(' expression ')' statement %prec LOWER_THAN_ELSE 		{ $$ = new_if_stmt_node($3, $5, NULL); }
	| IF '(' expression ')' statement ELSE statement			{ $$ = new_if_stmt_node($3, $5, $7); }
	;

iteration_statement
	: WHILE '(' expression ')' statement						{ $$ = new_while_stmt_node($3, $5); }
	| FOR '(' expression_statement expression_statement ')' statement		{ $$ = new_for_stmt_node($3,$4,NULL,$6); }
	| FOR '(' expression_statement expression_statement expression ')' statement	{ $$ = new_for_stmt_node($3,$4,$5,$7); }
	;

jump_statement
	: RETURN ';'							{ $$ = new_return_stmt_node(NULL); }
	| RETURN expression ';'						{ $$ = new_return_stmt_node($2); }
	| BREAK ';'							{ $$ = new_break_stmt_node(); }
	| CONTINUE ';'							{ $$ = new_continue_stmt_node(); }
	;

compound_statement
	: '{' '}'							{ $$ = new_compound_stmt_node(NULL, NULL); }
	| '{' statement_list '}'					{ $$ = $2; }
	| '{' variable_declaration_list '}'				{ $$ = $2; }
	| '{' variable_declaration_list statement_list '}'		{ $$ = new_compound_stmt_node($2, $3); }
	;

parameter_list
	:								{ $$ = NULL; }
	| parameter							{ $$ = new_param_list_node($1); }
	| parameter_list ',' parameter					{ $$ = append_param_list_node($1, $3); }
	;

parameter
	: type IDENTIFIER						{ $$ = new_param_node($1, $2); }
	;

function_definition
	: type IDENTIFIER '(' parameter_list ')' compound_statement	{ $$ = new_func_def_node($1,$2,$4,$6); }
	;

function_call
	: IDENTIFIER '(' argument_expression_list ')'			{ $$ = new_func_call_node($1,$3); }
	;

printf_call
	: LIB_PRINTF '(' argument_expression_list ')'			{ $$ = new_printf_call_node($3); }
	;

scanf_call
	: LIB_SCANF '(' argument_expression_list ')'			{ $$ = new_scanf_call_node($3); }
	;

argument_expression_list
	:								{ $$ = NULL; }
	| assignment_expression						{ $$ = new_arg_exp_list_node($1); }
	| argument_expression_list ',' assignment_expression		{ $$ = append_arg_exp_list_node($1, $3); }
	;

global_declaration
	: function_definition						{ $$ = $1; eval_func_def($$); if(_interact) print_prompt(); }
	| variable_declaration						{ $$ = $1; eval_global_var_decl($$); if(_interact) print_prompt(); }
	;

main_prototype
	: MAIN_DEFINITION						{ $$ = NULL; /*set IN_MAIN flag here*/ }
	;

main_definition
	: main_prototype compound_statement				{ $$ = new_main_def_node($2); eval_main_def($$); }
	;

translation_unit
	: global_declaration 						{ $$ = NULL; /* are these nodes required? */ }
	| translation_unit global_declaration				{ $$ = NULL; /* are these nodes required? */ }
	;

script
	: main_definition 						{ $$ = new_func_call_node(MAIN_FUNCTION_LABEL, NULL); set_main_ref($$); /* are these nodes required? */ }
	| translation_unit main_definition				{ $$ = new_func_call_node(MAIN_FUNCTION_LABEL, NULL); set_main_ref($$); /* are these nodes required? */ }
	;

%%

extern char yytext[];
extern int column;
//int yydebug=1;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
