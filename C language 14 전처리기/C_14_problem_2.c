#include <stdio.h>	//함수메크로 문제 
#define MULT(x,y,z) ((x) * (y) * (z))
#define Add(x, y, z) ((x) + (y) + (z))

int main(void) { 
	int result_m, result_a;
	result_m = MULT(10, 20, 30);
	result_a = Add(10, 20, 30);
	printf("%d와 %d와 %d의  곱은 %d입니다\n", 10, 20,30, result_m);
	printf("%d와 %d와 %d의  합은 %d입니다\n", 10, 20, 30, result_a);
	return 0;
}