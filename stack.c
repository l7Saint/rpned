#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

#ifndef STACK_UNIT_STRUCT
#define STACK_UNIT_STRUCT
struct Stack_unit {
	double num;
	struct Stack_unit* next;
};
#endif

#ifndef DEBUG_MODE
#define DEBUG_MODE true
#endif

void free_unit(struct Stack_unit *unit){
	if(DEBUG_MODE)	
		printf("DEBUG: freed %f, addr: %#lx\n", unit->num,(uint64_t)unit);
	free(unit);
}

double pop_stack(struct Stack_unit *top){
	double num = 0;
	/*poppes the old_second and puts in its place the top with the old_second number*/
	if(top->next != NULL){
		num = top->num;

		struct Stack_unit* old_second = top->next;	
		top->num = old_second->num;
		top->next = old_second->next;

		free(old_second);
	}	
	return num;
}

void push_stack(struct Stack_unit *top, double num){
	struct Stack_unit* new_second = (struct Stack_unit*)malloc(sizeof(struct Stack_unit));	

	/*Swap numbers between top and new_second*/
	double old_num = top->num;
	top->num = num;
	new_second->num = old_num; 
	
	if(top->next != NULL){
		/*Put the new_second inbetween the old_second and top*/
		struct Stack_unit* old_second = top->next;
		top->next = new_second;
		new_second->next = old_second;
	} else {
		top->next = new_second;
		new_second->next = NULL;
	}
}

void print_unit(struct Stack_unit* unit){
	if(DEBUG_MODE){
		printf("%f DEBUG: addr: %#lx\n", unit->num,(uint64_t)unit);
	} else {
		printf("%f\n", unit->num);
	}
}

void print_stack(struct Stack_unit* top){
	const char* topbottomtext = "|-----------STACK-----------|";
	struct Stack_unit* index = top;

	printf("%s\n", topbottomtext);
	print_unit(index);
	while (index->next != NULL){	
		index = index->next;
		print_unit(index);
	} 	
	printf("%s\n", topbottomtext);
}

int check_size_stack(struct Stack_unit* top){
	int i = 1;
	struct Stack_unit* index = top;
	while(index->next != NULL){
		index = index->next;
		i++;
	}
	return i;
}

void free_stack(struct Stack_unit* top){
	struct Stack_unit* index1 = top;
	struct Stack_unit* index2 = top->next;

	while(index2 != NULL){	
		free_unit(index1);
		index1 = index2;
		if(index1 != NULL)
			index2 = index1->next;
	}
	free_unit(index1);
}

void flush_stack(struct Stack_unit* top){
	if(check_size_stack(top) == 1)
		return;
	else if (check_size_stack(top) == 2) {
		free_unit(top->next);
		top->next = NULL;
		return;
	}

	struct Stack_unit* index1 = top->next;
	struct Stack_unit* index2 = index1->next;

	while(index2 != NULL){	
		free_unit(index1);
		index1 = index2;
		if(index1 != NULL)
			index2 = index1->next;
	}
	free_unit(index1);
	top->next = NULL;
}


