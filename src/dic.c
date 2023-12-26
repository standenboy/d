#include<stdio.h>
#include<string.h>
#include "parse.h"

#define MAXLINE 1024

void printElement(struct element el){
	printf("{ command: %s, argCount: %d, args: ", el.command, el.argCount); 
	for (int i = 0; i < strlen(el.args); i++){
		if (el.args[i] == '#'){
			printf(" ");
		} else{
			printf("%c", el.args[i]);
		}
	}	
	printf(" }\n");	
}

int main(int argc, char **argv){
	FILE *fptr;
	fptr = fopen(argv[1], "r");
	char buffer[MAXLINE];

	while (fgets(buffer, MAXLINE, fptr) != NULL){
		printf(buffer);
		struct element el = parser(buffer);
		printElement(el);
	}

	return 0;
}
