#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 0;
	int i;
	int * p;
	int sum = 0;
	printf("정수의 개수 : ");
	scanf("%d", &size);
	p = (int *)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) {
		printf("양의 정수를 입력하시오 : ");
		scanf("%d", &p[i]);
	}

	for (i = 0; i < size; i++) {
		sum += *(p + i);
	}
	free(p);
	printf("모두 더한 값 : %d\n", sum);

	return 0;
}