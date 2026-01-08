#define PI 3.1415926

int fn_add(struct Stack_unit* top){
	if(check_size_stack(top) < 2)
		return STACK_SIZE_INVALID;
	
	double num = pop_stack(top);
	top->num += num;
	return OK;
}

int fn_sub(struct Stack_unit* top){
	if(check_size_stack(top) < 2)
		return STACK_SIZE_INVALID;
	
	double num = pop_stack(top);
	top->num -= num;
	return OK;
}

int fn_mult(struct Stack_unit* top){
	if(check_size_stack(top) < 2)
		return STACK_SIZE_INVALID;
	
	double num = pop_stack(top);
	top->num *= num;
	return OK;
}

int fn_div(struct Stack_unit* top){
	if(check_size_stack(top) < 2)
		return STACK_SIZE_INVALID;
	if(top->num == 0)
		return DIVISION_BY_0;

	double num = pop_stack(top);
	top->num /= num;
	return OK;
}

int fn_sin(struct Stack_unit* top){
	top->num = sin(top->num);
	return OK;
}

int fn_cos(struct Stack_unit* top){
	top->num = cos(top->num);
	return OK;
}

int fn_tan(struct Stack_unit* top){
	/*TODO: proper checking if tan(top->num) == NAN*/
	top->num = tan(top->num);
	return OK;
}

int fn_asin(struct Stack_unit* top){
	if(top->num > 1 || top->num < -1)
		return NOT_A_NUMBER; 
	top->num = asin(top->num);
	return OK;
}

int fn_acos(struct Stack_unit* top){
	if(top->num > 1 || top->num < -1)
		return NOT_A_NUMBER;
	top->num = acos(top->num);
	return OK;
}

int fn_atan(struct Stack_unit* top){
	top->num = atan(top->num);
	return OK;
}

int fn_degtorad(struct Stack_unit* top){
	top->num *= (PI/180);
	return OK;
}

int fn_radtodeg(struct Stack_unit* top){
	top->num /= (PI/180);
	return OK;
}

