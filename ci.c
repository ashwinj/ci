/*---------------------------------------------------------------------------------------------------------
Name: Ashwin Jha
Roll Number: CS1328
Program description: This piece of code will manage the call to ci virtual machine for running ci commands
		     or interpreting ci scripts.	     
Acknowledgements: 
-----------------------------------------------------------------------------------------------------------*/
#include "vm.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE* in;
	int a=0;
	if(argc == 1) {
		a = _start_();
	} else if (argc > 1) {
		if(argv[1][0]=='-') {
			/* handle options */
		} else if(!strcmp(argv[1]+strlen(argv[1])-3,".ci")) {
			in = fopen(argv[1], "r");
			a = _interpret_(in);
		} else {
			/* handle incorrect usage.*/
			/* print usage direction.*/
		}
	}
	return a;
}
