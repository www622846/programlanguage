/*�Ǻ����� ��*/

#include <stdio.h>

int fibo(int);

int main(void) {
	int count = 0;
	printf("�Ǻ����� ����  ó������ 6��°���� ����մϴ�.\n\n");
	for (count = 0; count <= 6; count++) {
		printf("%2d��° �Ǻ����� �� %6d\n", count, fibo(count));
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