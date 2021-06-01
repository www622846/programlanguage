#include <stdio.h>
#include <math.h>

double dist_2d(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(void) {
	double x1, x2, y1, y2;
	printf("ù��° ���� ��ǥ�� �Է��ϼ��� >> ");
	scanf("%lf %lf", &x1, &y1);
	printf("�ι�° ���� ��ǥ�� �Է��ϼ��� >> ");
	scanf("%lf %lf", &x2, &y2);
	printf("���� ������ �Ÿ��� %f�Դϴ�.\n", dist_2d(x1, y1, x2, y2));
	return 0;
}