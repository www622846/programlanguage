#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *pi;
	double *pd;
	int *ary;
	int i;

	printf("문장 : pi = (int * )malloc(sizeof(int))\n");
	pi = (int *)malloc(sizeof(int));
	*pi = 3;
	printf("*pi = %d\n\n", *pi);
	free(pi);

	printf("문장 : pd = (double * )malloc(sizeof(double))\n");
	pd = (double *)malloc(sizeof(double));
	*pd = 3.141592;
	printf("*pi = %ld\n\n", *pd);
	free(pd);

	printf("문장 : ary = (int * )malloc(sizeof(int) * 3)\n");
	ary = (int *)malloc(sizeof(int) * 3);
	ary[0] = 1; ary[1] = 2; ary[2] = 3;
	for (i = 0; i < 3; i++) {
		printf("%d\n", ary[i]);
	}
	free(ary);

	return 0;
}