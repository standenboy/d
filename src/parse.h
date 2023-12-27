#include<string.h>
#include<stdlib.h>

typedef struct element {
	char *command;
	int argCount;
	char *args; // sep by #
} element;

int toggle(int b){
	if (b == 1){
		return 0;
	}
	return 1;
}

char *strip(char c, char buffer[]){
	char *output = malloc(strlen(buffer));
	int currentChar = 0;
	for (int i = 0; i < strlen(buffer); i++){
		if (buffer[i] != c){
			output[currentChar] = buffer[i];
			currentChar++;
		}
	}
	return output;
}

int countElements(char line[]){
	int counter = 1;
	int inquotes = 0;
	for (int i = 0; i < strlen(line); i++){
		if (line[i] == '"'){
			inquotes = toggle(inquotes);
		}
	
		if (inquotes != 1){
			if (line[i] == ' ') {
				counter++;
			}
		}	
	}
	return counter;
}

char *getElement(char line[], int elNum){
	char *output = malloc(32);
	int elementCount = 0;
	int charCount = 0;
	int inquotes = 0;
	for (int i = 0; i < strlen(line); i++){
		if (line[i] == '"'){
			inquotes = toggle(inquotes);
		}

		if (line[i] == ' ' || line[i] == '\n'){
			if (inquotes != 1){
				elementCount++;
				if (elementCount == elNum){
					output[charCount+1] = '\0';
					return output;
				}
				output = malloc(32);
			}else {
				if (elementCount == elNum - 1){
					output[charCount] = line[i];
		       			charCount++;	
				}
			}	
		}else{
			if (elementCount == elNum - 1){
				output[charCount] = line[i];
		       		charCount++;	
			}
		}
	}
	return "(null)";
}


struct element parser(char line[]){
	line = strip('	', line);

	struct element *output = malloc(1024); 	
	output -> command = getElement(line, 1);
	output -> argCount = countElements(line) - 1;
	char *args = malloc(32);
	for (int i = 0; i < output -> argCount; i++){
		strcat(args, getElement(line, i + 2));
		strcat(args, "#");
	}
	output -> args = args;	
	return *output;
}

// for if statments make { act as an end if command
