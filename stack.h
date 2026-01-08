#ifndef STACK_UNIT_STRUCT
#define STACK_UNIT_STRUCT
struct Stack_unit {
	double num;
	struct Stack_unit* next;
};
#endif

double pop_stack(struct Stack_unit *top);
void push_stack(struct Stack_unit *top, double num);
void print_stack(struct Stack_unit* top);
int check_size_stack(struct Stack_unit* top);
void free_stack (struct Stack_unit* top);
void flush_stack (struct Stack_unit* top);

