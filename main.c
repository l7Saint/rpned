#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<unistd.h>

#ifndef STACK_H
#define STACK_H
#include"stack.h"
#endif

#ifndef OP_PARSER_C
#define OP_PARSER_C
#include"op_parser.c"
#endif

#ifndef DEBUG_MODE
#define DEBUG_MODE true
#endif

void clean_input(char* input){
	int i = 0;

	while(input[i] != '\n')
		i++;
	input[i] = '\0';
}

bool is_number(char c){
	return c >= '0' && c <= '9';
}

int main(int argc, char** argv){
	bool running = true;
	struct Stack_unit* top_stack = (struct Stack_unit*)malloc(sizeof(struct Stack_unit));
	char input_buffer[256];

	top_stack->next = NULL;
	top_stack->num = 0;
	
	while(running) {
		printf(">> ");	
		fgets(input_buffer, sizeof(input_buffer), stdin);	
		clean_input(input_buffer);
		
		/*TODO: make ts more efficient plz */
		if(is_number(input_buffer[0]) || (input_buffer[0] == '-' && (unsigned)strlen(input_buffer) >= 2 && is_number(input_buffer[1]))) {
			double input_number = strtod(input_buffer, NULL);
			push_stack(top_stack, input_number);	
		} else if (input_buffer[0] == ':') {
			/* command section */
			switch(input_buffer[1]){
				case 'q':
					running = false;
					break;
				case 's':
					print_stack(top_stack);
					break;	
				case 'p':
					pop_stack(top_stack);
					break;
				case 'f':
					flush_stack(top_stack);
					break;
			}
		} else {
			int errcode = op_parser(input_buffer, top_stack);
			switch(errcode){
				case OK:
					break;
				case OP_NOT_FOUND:
					printf("Invalid operation.\n");
					break;
				case DIVISION_BY_0:
					printf("Invalid division by 0.\n");
					break;
				case STACK_SIZE_INVALID:
					printf("Not enough stack size for desired operation.\n");
					break;
				case NOT_A_NUMBER:
					printf("Result is not a number.\n");
					break;
				default:
					printf("Error code not recognized, Error Code: %i\n", errcode);		
			}
		}
	}

	free_stack(top_stack);
	return 0;
}
