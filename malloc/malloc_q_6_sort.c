#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print(int *a);
void sort(int *x);
void swap(int *x, int *y) {
	int z;
	z = *x;
	*x = *y;
	*y = z;
}
int main(void) {
	int i;
	long seed = time(NULL);
	int *a = (int *)malloc(sizeof(int) * 10);
	srand(seed);
	for (i = 0; i <= 9; i++) {
		a[i] = rand() %100;
	}
	printf("정렬 전 배열의 값 : \n");
	print(a);
	printf("정렬 후 배열의 값 : \n");
	sort(a);
	print(a);
	free(a);
	return 0;
}
void print(int *a) {
	int i;
	for (i = 0; i <= 9; i++) {
		printf("%d%c", a[i], i == 9 ? ' ' : ',');
	}
	printf("\n");
}
void sort(int *x) {
	int i,j;
	for (i = 0; i <= 9; i++)
		for (j = 0; j < 9; j++)
			if (*(x + j)>*(x + j + 1))
				swap((x + j), (x + j + 1));
}
