#include <stdio.h>	//�Լ���ũ�� ���� 
#define RANGE(x,y,z) !((x) < (y) || (x) >(z))
#define ODD_GT(x,y) ((x%2==1) && (x) > (y))
#define IS_UPPER(c) (((c) >= 'A') && ((c) <= 'Z'))

int main(void) { 
	int x, y, z;
	char c = 'a';
	x = 1, y = 2, z = 3;
	printf("x = %d, y = %d, z= %d, c = %c\n", x, y, z, c);
	printf("x�� y���� �۰ų� z���� ũ�� 0�� ��ȯ�ϴ� ��ũ�� RANGE : %d\n", RANGE(x, y, z));
	printf("x�� Ȧ���̰� y���� ũ�� 1�� ��ȯ�ϴ� ��ũ�� ODD_GT : %d\n", ODD_GT(x, y));
	printf("c�� �빮���̸� ���� ��ȯ�ϴ� ��ũ�� IS_UPPER : %d\n", IS_UPPER(c));
	return 0;
}