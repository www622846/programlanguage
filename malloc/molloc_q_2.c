#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 0;
	int i;
	int * p;
	int sum = 0;
	printf("������ ���� : ");
	scanf("%d", &size);
	p = (int *)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) {
		printf("���� ������ �Է��Ͻÿ� : ");
		scanf("%d", &p[i]);
	}

	for (i = 0; i < size; i++) {
		sum += *(p + i);
	}
	free(p);
	printf("��� ���� �� : %d\n", sum);

	return 0;
}