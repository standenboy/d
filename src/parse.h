#include<string.h>
#include<stdlib.h>

typedef struct element {
	char *command;
	int argCount;
	char *args; // sep by #
};

int countElements(char line[]){
	int counter = 1;
	for (int i = 0; i < strlen(line); i++){
		if (line[i] == ' ') {
			counter++;
		} 
	}
	return counter;
}

char *getElement(char line[], int elNum){
	if (elNum > countElements(line)){
		return "(null)";
	}
	int elementCounter = 0;
	char *output = malloc(32);
	for (int i = 0; i < strlen(line); i++){
		if (line[i] != ' '){       	
			output[i] = line[i];
		}else{
			elementCounter++;
			if (elementCounter == elNum){
				break;
			}
		}
	}
	strcat(output,"\0");
	return output;
}


struct element parser(char line[]){
	struct element *output = malloc(1024); 	
	output -> command = getElement(line, 1);
	char args[512];  
	int counter = 2;
	while (strcmp(getElement(line, counter), "(null)") != 0){ 
		strcat(args, "#");
		strcat(args, getElement(line, counter));
		counter++;
	}
	output -> args = args; // currently broken
	output -> argCount = countElements(line);

	return *output;
}
