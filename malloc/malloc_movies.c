#include <stdio.h>
#include <stdlib.h>
struct dvd {
	char  title[100];
	int rating;
};

int main(void) {
	struct dvd *ps;
	int i, n;

	printf("영화의 개수 : ");
	scanf("%d", &n);
	ps = (struct dvd *)malloc(n * sizeof(struct dvd));	//동적 메모리 할당
	if (ps == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	for (i = 0; i < n; i++) {
		printf("영화의 제목 :");
		scanf("%s", ps[i].title);
		printf("영화의 평점 :");
		scanf("%s", ps[i].rating);
	}
	printf("==================================\n");
	for (i = 0; i < n; i++) {
		printf("영화의 제목 : %s\n", ps[i].title);
		printf("영화의 평점 : %s\n", ps[i].rating);
	}
	printf("==================================\n");
	free(ps);	//동적메모리 반납
	return 0;
}