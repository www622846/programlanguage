#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i;
	double b;
	//문자열을 수치로
	i = atof("100");
	printf("%d\n", i);

	b = atof("36.5");
	printf("%lf\n", b);

	return 0;
}