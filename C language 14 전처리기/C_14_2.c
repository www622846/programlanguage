#include <stdio.h>
#define SQUARE(x) ((x) * (x))


int main(void) {
	int x = 2;

	printf("SQUARE = %d\n", SQUARE(3));	//��� ����
	printf("SQUARE = %lf\n", SQUARE(1.2));	//�Ǽ� ����
	printf("SQUARE = %d\n", SQUARE(2+3));	//���� ����
	printf("x = %d\n", x);
	printf("SQUARE = %d\n", SQUARE(x));	//���� ����
	printf("SQUARE = %d\n", SQUARE(++x));	//������
	return 0;
}