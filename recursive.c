#include <stdio.h>
#include <math.h>

double recursive(int);

int main(void) {
	int n;
	printf("정수 값을 입력하세요 >> ");
	scanf("%d", &n);
	printf("1부터 %d까지 sqrt의 합 : %f\n", n, recursive(n));
	return 0;
}
double recursive(int n) {
	if (n == 1) return 1;
	else return sqrt(n) + recursive(n-1); //제곱근
	//else return n *n *n + recursive(n - 1); 세제곱
}