#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1024

int main(int argc, char **argv){
	FILE *fptr;
	fptr = fopen(argv[1], "r");
	char buffer[MAXLINE];
	while (fgets(buffer, MAXLINE, fptr) != NULL){
		printf(buffer);
	}
	return 0;
}
