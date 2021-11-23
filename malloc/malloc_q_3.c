#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int count;
	int *parsscore;
	int total = 0;
	int i = 0;
	printf("입력할 과목의 수 : ");
	scanf("%d", &count);
	parsscore = (int *)malloc(sizeof(int) * count);
	memset(parsscore, 0, count + sizeof(int));
	printf("%d 개 과목 점수 입력 : ", count);
	for (i = 0; i < count; i++) {
		scanf("%d", &parsscore[i]);
	}
	for (i = 0; i < count; i++) {
		total += parsscore[i];
	}
	free(parsscore);
	printf("총점 : %d\n", total);
	printf("평균 : %f\n", (float)total / count);

	return 0;
}