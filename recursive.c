#include <stdio.h>
#include <math.h>

double recursive(int);

int main(void) {
	int n;
	printf("���� ���� �Է��ϼ��� >> ");
	scanf("%d", &n);
	printf("1���� %d���� sqrt�� �� : %f\n", n, recursive(n));
	return 0;
}
double recursive(int n) {
	if (n == 1) return 1;
	else return sqrt(n) + recursive(n-1); //������
	//else return n *n *n + recursive(n - 1); ������
}