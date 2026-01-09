#ifndef COMMAND_PARSER_C

#include"stack.h"
#include<stdbool.h>
#include<string.h>

#ifndef DEBUG_MODE
#define DEBUG_MODE true
#endif

/*Error codes for commands*/
#define OK 0
#define COMMAND_NOT_FOUND -1

#define COMMANDLIST \
	X(q, quit) \
	X(s, stack) \
	X(d, drop) \
	X(f, flush)

void clean_input(char* input){
	int i = 0;

	while(input[i] != '\n')
		i++;
	input[i] = '\0';
}

bool is_number(char c){
	return c >= '0' && c <= '9';
}

struct Command {
	char* string;
	int (*fn)(struct Stack_unit*, bool*);
};

#include"command_fn.c"

const struct Command commandlist[] = {
	#define X(str, name) {#str, &fn_##name},
	COMMANDLIST
	{"", NULL}
	#undef X
};

char* strrev(char* str){
	if (str == NULL) 
		return NULL;
	char *start = str;
	char *end = str + strlen(str) - 1;

	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

	return str;
}

char* erase_colon(char* input){
	int i = 0;

	input = strrev(input);
	while(input[i] != ':')
		i++;
	input[i] = '\0';
	input = strrev(input);
	return input;
}

int get_times(char* input){
	if(!is_number(input[0]))
		return 1;
	char* end = NULL;
	int returnv = strtoul(input, &end, 10);
	int i = 0;
	input = strrev(input);
	while(!is_number(input[i]))
		i++;
	input[i] = '\0';
	input = strrev(input);
	return returnv;
}

int command_parser(char* command, struct Stack_unit* top_stack, bool* running) {
	int returnv = COMMAND_NOT_FOUND;
	int arrsize = sizeof(commandlist)/sizeof(struct Command);
	arrsize--;
	command = erase_colon(command);	
	unsigned int times = get_times(command);

	for(int i = 0; i < arrsize; i++){

		if(strcmp(command, commandlist[i].string) == 0){
			for(unsigned int j = 0; j < times; j++)
				returnv = commandlist[i].fn(top_stack, running);
			break;
		}
	}

	return returnv;
}

#endif
