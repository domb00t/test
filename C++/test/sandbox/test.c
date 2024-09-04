#include <stdio.h>

void print(int value) {
	printf("%d",value);
}

typedef void (*f_p)(int);

typedef struct S {
	
	int re;
	int img;

} complex_t;

int mian() {
	f_p p_print = print;
	p_print(3);

	return 0;
}