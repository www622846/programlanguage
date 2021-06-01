#include <stdio.h>
#include <math.h>

int main(void) {
	int a, b;
	float C, t_area = 0.0;
	printf("두 변의 값을 입력하시오 >> ");
	scanf("%d %d", &a, &b);
	printf("끼인 각의 값을 입력하시오 >> ");
	scanf("%f", &C);
	t_area = (1 / 2.0) * a * b * sin((3.141592 * C) / 180.0);
	printf("삼각형의 면적 : %f\n", t_area);
	return 0;
}