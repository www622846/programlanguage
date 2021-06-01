/*피보나츠 수*/

#include <stdio.h>

int fibo(int);

int main(void) {
	int count = 0;
	printf("피보나츠 수를  처음부터 6번째까지 출력합니다.\n\n");
	for (count = 0; count <= 6; count++) {
		printf("%2d번째 피보나츠 수 %6d\n", count, fibo(count));
	}
	return 0;
}

int fibo(int a) {
	int fn;
	if (a >= 2) {
		fn = fibo(a - 1) + fibo(a - 2);
	}
	else if (a == 1) {
		fn = 1;
	}
	else if(a == 0)
	{
		fn = 0;
	}
	return fn;
}