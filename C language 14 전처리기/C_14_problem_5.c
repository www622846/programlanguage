#include <stdio.h>	//��ũ�� ���� 
#define PI 3.1415
#define CIRCLE_CIRCUM(r) (2 * PI * (r))

int main(void) { 
	double radius, circum;

	printf("�������� �Է��Ͻÿ� : ");
	scanf("%lf", &radius);
	circum = CIRCLE_CIRCUM(radius);
	printf("���� �ѷ� : %lf\n", circum);
	return 0;
}