#define PI 3.1415926
/* TEMPLATE
int fn_(struct Stack_unit* top){
	return OK;
}
*/

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
	/*tan = sin/cos -> if cos == 0 then !exist tan*/
	if(cos(top->num) == 0)
		return NOT_A_NUMBER;
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

int fn_sqrt(struct Stack_unit* top){
	if(top->num < 0)
		return NOT_A_NUMBER;
	top->num = sqrt(top->num);
	return OK;
}

int fn_nrt(struct Stack_unit* top){
	if(check_size_stack(top) < 2)
		return STACK_SIZE_INVALID;
	if(top->next->num < 0 && ((int)floor(top->num) % 2 == 0 || floor(top->num) != top->num))
		return NOT_A_NUMBER;
	if(top->next->num == 0)
		return DIVISION_BY_0;

	double num1 = pop_stack(top);
	top->num = pow(top->num, 1/num1);
	return OK;
}

int fn_power(struct Stack_unit* top){
	if(check_size_stack(top) < 2)
		return STACK_SIZE_INVALID;
	double result = pow(top->next->num, top->num);
	if(result == NAN)
		return NOT_A_NUMBER;

	pop_stack(top);
	top->num = result;
	return OK;
}

int fn_ceil(struct Stack_unit* top){
	top->num = ceil(top->num);
	return OK;
}

int fn_floor(struct Stack_unit* top){
	top->num = floor(top->num);
	return OK;
}

int fn_absv(struct Stack_unit* top){
	if(top->num < 0)
		top->num = top->num * -1;
	return OK;
}

int fn_ln(struct Stack_unit* top){
	top->num = log(top->num);
	return OK;
}

int fn_log(struct Stack_unit* top){
	top->num = log10(top->num);
	return OK;
}

/*logX(Y)*/
int fn_logn(struct Stack_unit* top){
	if(check_size_stack(top) < 2)
		return STACK_SIZE_INVALID;
	double num = pop_stack(top);
	top->num = log(top->num)/log(num);
	return OK;
}
