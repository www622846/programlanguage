#include <stdio.h>	//�ܼ���ũ��
#define PI 3.1415

int main(void) {
	double radius, area, circum;
	printf("���� �������� �Է��Ͻÿ� : ");
	scanf("%lf", &radius);

	area = radius * PI * radius;
	circum = 2 * radius * PI;
	printf("���� ���̴� %lf�Դϴ�.\n", area);
	printf("���� �ѷ��� %lf�Դϴ�.\n", circum);
	return 0;
}