#include <stdio.h>	//�Լ���ũ�� ���� 
#define MULT(x,y,z) ((x) * (y) * (z))
#define Add(x, y, z) ((x) + (y) + (z))

int main(void) { 
	int result_m, result_a;
	result_m = MULT(10, 20, 30);
	result_a = Add(10, 20, 30);
	printf("%d�� %d�� %d��  ���� %d�Դϴ�\n", 10, 20,30, result_m);
	printf("%d�� %d�� %d��  ���� %d�Դϴ�\n", 10, 20, 30, result_a);
	return 0;
}