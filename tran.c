#include <stdio.h>
#include <math.h>

int main(void) {
	int a, b;
	float C, t_area = 0.0;
	printf("�� ���� ���� �Է��Ͻÿ� >> ");
	scanf("%d %d", &a, &b);
	printf("���� ���� ���� �Է��Ͻÿ� >> ");
	scanf("%f", &C);
	t_area = (1 / 2.0) * a * b * sin((3.141592 * C) / 180.0);
	printf("�ﰢ���� ���� : %f\n", t_area);
	return 0;
}