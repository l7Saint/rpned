#ifndef OP_PARSER_C

#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"stack.h"

#ifndef DEBUG_MODE
#define DEBUG_MODE true
#endif

/*Exit codes for the operation functions*/
#define OK 0
#define OP_NOT_FOUND -1
#define STACK_SIZE_INVALID 1
#define DIVISION_BY_0 -2
#define NOT_A_NUMBER -3

#define OPLIST \
	X(+, add) \
	X(-, sub) \
	X(*, mult) \
	X(/, div) \
	X(sin, sin) \
	X(cos, cos) \
	X(tan, tan) \
	X(asin, asin) \
	X(acos, acos) \
	X(atan, atan) \
	X(dtr, degtorad) \
	X(rtd, radtodeg) \
	X(sqrt, sqrt) \
	X(nrt, nrt) \
	X(^, power) \
	X(ceil, ceil) \
	X(floor, floor) \
	X(absv, absv) \
	X(ln, ln) \
	X(log, log) \
	X(logn, logn)

struct Op {
	char* string;
	int (*fn)(struct Stack_unit*);
};

#include"op_fn.c"

const struct Op oplist[] = {
	#define X(str, name) {#str, &fn_##name},
	OPLIST
	{"", NULL}
	#undef X
};

int op_parser(char* input_buffer, struct Stack_unit* top){
	int returnv = OP_NOT_FOUND;
	int arrsize = sizeof(oplist)/sizeof(struct Op);
	arrsize--;
	
	for(int i = 0; i < arrsize; i++){
		if(strcmp(input_buffer, oplist[i].string) == 0){
			returnv = oplist[i].fn(top);
			break;
		}
	}	

	return returnv;
}

#endif
