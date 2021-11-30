#include <stdio.h>	//매크로 문제 
#define PI 3.1415
#define CIRCLE_CIRCUM(r) (2 * PI * (r))

int main(void) { 
	double radius, circum;

	printf("반지름을 입력하시오 : ");
	scanf("%lf", &radius);
	circum = CIRCLE_CIRCUM(radius);
	printf("원의 둘레 : %lf\n", circum);
	return 0;
}