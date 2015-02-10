/****************************************************************************************************

	Command line handler for ci. It uses vm.c as helper.

	@author		Ashwin Jha<ajha.dev@gmail.com>

*****************************************************************************************************/
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE* in;
	int a=0;
	if(argc == 1) {
		a = _start_();
	} else if (argc > 1) {
		if(argv[1][0]=='-') {
			switch(argv[1][1]) {
			case 'v':
				publish_masthead();
			case 'h':
			default:
				show_help();
			}
		} else if(!strcmp(argv[1]+strlen(argv[1])-3,".ci")) {
			in = fopen(argv[1], "r");
			if(in == NULL) {
				fprintf(stderr, "\nUnable to open script file.\n");
				exit(1);
			} else {
				a = _interpret_(in);
				fclose(in);
			}
		} else {
			show_help();
		}
	}
	return a;
}
