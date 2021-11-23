#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main(void) {
	int *p;
	int i, max;


	p = (int *)malloc(SIZE * sizeof(int));	//동적 메모리 할당
	if (p == NULL) {
		printf("동적 메모리 할당 오류\n");
	}
	for (i = 0; i < SIZE; i++) {
		p[i] = rand();
	}
	max = p[0];
	for (i = 0; i < SIZE; i++) {
		if (max < p[i])
			max = p[i];
	}

	printf("최댓값 : %d\n", max);
	free(p);	//동적메모리 반납
	return 0;
}