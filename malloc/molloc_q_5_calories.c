#include <stdio.h>
#include <stdlib.h>
typedef struct food {
	char name[50];
	int calories;
} pfood;
int cal_total(struct food array[], int size);


int main(void) {
	int i, total, count = 0;
	pfood *pf;
	printf("�Ļ��ϴ� ������ �� : ");
	scanf("%d", &count);
	pf = (pfood *)malloc(sizeof(pfood) * count);
	if (pf == NULL) {
		printf("can't aollocate memory\n");
		exit(1);
	}

	printf("�̸� Į�θ�:\n");
	for (i = 0; i < count; i++) {
		scanf("%s%d", pf[i].name, &pf[i].calories);
	}

	total = cal_total(pf, count);
	printf("��� ������ Į�θ� : %d\n", total);
	free(pf);
	return 0;
}

int cal_total(struct food array[], int size) {
	int result = 0;

	for (int i= 0; i < size; i++) {
		result += array[i].calories;
	}
	return result;
}