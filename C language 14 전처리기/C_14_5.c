#include <stdio.h>
#define DEBUG
#define PI 3,14
#define CURCLE_AREA(r) (PI * r *r)

int main(void) {
	double radius, area;
#ifdef DEBUG
	printf("����� ����Դϴ�,\n");
#endif

	printf("���� ������ : ");
	scanf("%lf", &radius);
	area = CURCLE_AREA(radius);
	printf("���� ���� : %lf\n", area);
	return 0;
}