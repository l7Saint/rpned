/* TEMPLATE
int fn_(struct Stack_unit* top_stack, bool* running){
	return OK;
}
*/

int fn_quit(struct Stack_unit* top_stack, bool* running){
	*running = false;
	return OK;
}

int fn_stack(struct Stack_unit* top_stack, bool* running){
	print_stack(top_stack);
	return OK;
}

int fn_drop(struct Stack_unit* top_stack, bool* running){
	pop_stack(top_stack);
	return OK;
}

int fn_flush(struct Stack_unit* top_stack, bool* running){
	flush_stack(top_stack);
	return OK;
}

int fn_help(struct Stack_unit* top_stack, bool* running){
	#include"help_op.c"
	printf("%s\n", help_op_string);
	return OK;
}
