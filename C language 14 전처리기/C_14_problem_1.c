#include <stdio.h>	//단순메크로
#define PI 3.1415

int main(void) {
	double radius, area, circum;
	printf("원의 반지름을 입력하시오 : ");
	scanf("%lf", &radius);

	area = radius * PI * radius;
	circum = 2 * radius * PI;
	printf("원의 넓이는 %lf입니다.\n", area);
	printf("원의 둘레는 %lf입니다.\n", circum);
	return 0;
}