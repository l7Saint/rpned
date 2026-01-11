#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<unistd.h>
#include"stack.h"

#ifndef OP_PARSER_C
#include"op_parser.c"
#define OP_PARSER_C
#endif

#ifndef COMMAND_PARSER_C
#include"command_parser.c"
#define COMMAND_PARSER_C
#endif

#ifndef DEBUG_MODE
#define DEBUG_MODE true
#endif

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
			int errcode = command_parser(input_buffer, top_stack, &running);	
			switch(errcode){
				case OK:
					break;
				case COMMAND_NOT_FOUND:
					printf("Invalid command \n");
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
