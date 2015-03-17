#***********************************************************************************
#
#	Copyright (C) 2015 Ashwin Jha and Durgesh Singh
#
#	This program is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#	
#	Manages all the compilation and linking related jobs.
#
#	@author Ashwin Jha<ajha.dev@gmail.com>
#
#***********************************************************************************

CC=gcc

LD=ld

LEX=lex

YACC=yacc

CFLAGS=-g -c -I'$(INCLUDE_DIR)' -o

LDFLAGS=-r -o

YFLAGS=-d

SRC_DIR=./src/

PARSER_DIR=./src/lex-yacc/

INCLUDE_DIR=./include/

OBJ_DIR=./obj/

BIN_DIR=./bin/

OBJ:=$(OBJ_DIR)interpreter.o $(OBJ_DIR)abstract_syntax_tree.o $(OBJ_DIR)symbol_table.o $(OBJ_DIR)parser.o $(OBJ_DIR)vm.o $(OBJ_DIR)ci.o

BIN=$(BIN_DIR)ci

.PHONY: all clean directories lex-yacc-gen

all: directories $(BIN)

directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

$(OBJ_DIR)interpreter.o: $(INCLUDE_DIR)interpreter.h $(INCLUDE_DIR)abstract_syntax_tree.h \
			 $(INCLUDE_DIR)symbol_table.h $(SRC_DIR)interpreter.c $(SRC_DIR)err_handler.c
	$(CC) $(CFLAGS) $(OBJ_DIR)i.o $(SRC_DIR)interpreter.c
	$(CC) $(CFLAGS) $(OBJ_DIR)e.o $(SRC_DIR)err_handler.c
	$(LD) $(LDFLAGS) $(OBJ_DIR)interpreter.o $(OBJ_DIR)i.o $(OBJ_DIR)e.o

$(OBJ_DIR)abstract_syntax_tree.o: $(INCLUDE_DIR)interpreter.h $(INCLUDE_DIR)abstract_syntax_tree.h \
				  $(INCLUDE_DIR)symbol_table.h $(INCLUDE_DIR)ast_builder.h $(INCLUDE_DIR)ast_util.h \
				  $(INCLUDE_DIR)ast_evaluator.h $(SRC_DIR)abstract_syntax_tree.c \
				  $(SRC_DIR)ast_builder.c $(SRC_DIR)ast_evaluator.c $(SRC_DIR)ast_util.c
	$(CC) $(CFLAGS) $(OBJ_DIR)a.o $(SRC_DIR)abstract_syntax_tree.c 
	$(CC) $(CFLAGS) $(OBJ_DIR)b.o $(SRC_DIR)ast_builder.c 
	$(CC) $(CFLAGS) $(OBJ_DIR)c.o $(SRC_DIR)ast_evaluator.c 
	$(CC) $(CFLAGS) $(OBJ_DIR)d.o $(SRC_DIR)ast_util.c
	$(LD) $(LDFLAGS) $(OBJ_DIR)abstract_syntax_tree.o $(OBJ_DIR)a.o $(OBJ_DIR)b.o $(OBJ_DIR)c.o $(OBJ_DIR)d.o

$(OBJ_DIR)symbol_table.o: $(INCLUDE_DIR)interpreter.h $(INCLUDE_DIR)abstract_syntax_tree.h \
			  $(INCLUDE_DIR)symbol_table.h $(SRC_DIR)symbol_table.c
	$(CC) $(CFLAGS) $(OBJ_DIR)symbol_table.o $(SRC_DIR)symbol_table.c

lex-yacc-gen: $(PARSER_DIR)ci.y $(PARSER_DIR)ci.l
	cd $(PARSER_DIR); $(YACC) $(YFLAGS) ci.y; \
	$(LEX) ci.l; cd -;
	mv $(PARSER_DIR)y.tab.c $(SRC_DIR)
	mv $(PARSER_DIR)y.tab.h $(INCLUDE_DIR)
	mv $(PARSER_DIR)lex.yy.c $(SRC_DIR)
	
$(OBJ_DIR)parser.o: lex-yacc-gen $(INCLUDE_DIR)interpreter.h $(INCLUDE_DIR)abstract_syntax_tree.h \
		    $(INCLUDE_DIR)symbol_table.h $(INCLUDE_DIR)ast_builder.h $(INCLUDE_DIR)ast_evaluator.h
	$(CC) $(CFLAGS) $(OBJ_DIR)y.tab.o $(SRC_DIR)y.tab.c
	$(CC) $(CFLAGS) $(OBJ_DIR)lex.yy.o $(SRC_DIR)lex.yy.c
	$(LD) $(LDFLAGS) $(OBJ_DIR)parser.o $(OBJ_DIR)y.tab.o $(OBJ_DIR)lex.yy.o

$(OBJ_DIR)vm.o: $(INCLUDE_DIR)vm.h $(INCLUDE_DIR)interpreter.h $(INCLUDE_DIR)abstract_syntax_tree.h \
		$(INCLUDE_DIR)ast_evaluator.h $(INCLUDE_DIR)symbol_table.h $(INCLUDE_DIR)y.tab.h $(SRC_DIR)vm.c
	$(CC) $(CFLAGS) $(OBJ_DIR)vm.o $(SRC_DIR)vm.c

$(OBJ_DIR)ci.o: $(INCLUDE_DIR)vm.h $(SRC_DIR)ci.c
	$(CC) $(CFLAGS) $(OBJ_DIR)ci.o $(SRC_DIR)ci.c

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
