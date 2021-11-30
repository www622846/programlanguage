#include <stdio.h>	//함수매크로 문제 
#define RANGE(x,y,z) !((x) < (y) || (x) >(z))
#define ODD_GT(x,y) ((x%2==1) && (x) > (y))
#define IS_UPPER(c) (((c) >= 'A') && ((c) <= 'Z'))

int main(void) { 
	int x, y, z;
	char c = 'a';
	x = 1, y = 2, z = 3;
	printf("x = %d, y = %d, z= %d, c = %c\n", x, y, z, c);
	printf("x가 y보다 작거나 z보다 크면 0을 반환하는 매크로 RANGE : %d\n", RANGE(x, y, z));
	printf("x가 홀수이고 y보다 크면 1을 반환하는 매크로 ODD_GT : %d\n", ODD_GT(x, y));
	printf("c가 대문자이면 참을 반환하는 매크로 IS_UPPER : %d\n", IS_UPPER(c));
	return 0;
}