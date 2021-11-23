#include <stdio.h>
#include <stdlib.h>

struct pscore {
	int num;
	char nme[10];
	float sc1;
	float sc2;
};
typedef struct pscore pscr;
int main(void) {
	pscr psc;
	pscr *pss;
	int i;
	pss = (pscr *)malloc(sizeof(psc) * 3);
	if (pss == NULL) {
		printf("can't allocate memory\n");
		exit(1);
	}
	for (i = 0; i < 3; i++) {
		printf("학번, 이름, 중간, 기말을 입력하시오 ");
		scanf("%d %s %f %f\n ", &pss[i].num, pss[i].nme, &pss[i].sc1, &pss[i].sc2);
		printf("학번 = %d, 이름 = %s, 중간 = %f, 기말 = %f, 합계 = %f\n", pss[i].num,pss[i].nme, pss[i].sc1, pss[i].sc2, pss[i].sc1 + pss[i].sc2);
	}
	free(pss);
	return 0;
}