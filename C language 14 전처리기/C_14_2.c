#include <stdio.h>
#define SQUARE(x) ((x) * (x))


int main(void) {
	int x = 2;

	printf("SQUARE = %d\n", SQUARE(3));	//상수 가능
	printf("SQUARE = %lf\n", SQUARE(1.2));	//실수 가능
	printf("SQUARE = %d\n", SQUARE(2+3));	//수식 가능
	printf("x = %d\n", x);
	printf("SQUARE = %d\n", SQUARE(x));	//변수 가능
	printf("SQUARE = %d\n", SQUARE(++x));	//논리오류
	return 0;
}