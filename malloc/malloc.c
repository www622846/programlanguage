#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main(void) {
	int *p;
	int i, max;


	p = (int *)malloc(SIZE * sizeof(int));	//���� �޸� �Ҵ�
	if (p == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
	}
	for (i = 0; i < SIZE; i++) {
		p[i] = rand();
	}
	max = p[0];
	for (i = 0; i < SIZE; i++) {
		if (max < p[i])
			max = p[i];
	}

	printf("�ִ� : %d\n", max);
	free(p);	//�����޸� �ݳ�
	return 0;
}