#include<string.h>

typedef struct element {
	char *command;
	int argCount;
	char *args; // sep by #
};

struct element parser(char line[]){
	// attempt to convert the code in example into these elements
	// an if statment should be treated the same as any other 
	// the closing } should become an endif 
	// for loops should use this too
	struct element output = {"import", 1, "io#math"};
	return output;
}
