#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int count;
	int *parsscore;
	int total = 0;
	int i = 0;
	printf("�Է��� ������ �� : ");
	scanf("%d", &count);
	parsscore = (int *)malloc(sizeof(int) * count);
	memset(parsscore, 0, count + sizeof(int));
	printf("%d �� ���� ���� �Է� : ", count);
	for (i = 0; i < count; i++) {
		scanf("%d", &parsscore[i]);
	}
	for (i = 0; i < count; i++) {
		total += parsscore[i];
	}
	free(parsscore);
	printf("���� : %d\n", total);
	printf("��� : %f\n", (float)total / count);

	return 0;
}