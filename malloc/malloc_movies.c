#include <stdio.h>
#include <stdlib.h>
struct dvd {
	char  title[100];
	int rating;
};

int main(void) {
	struct dvd *ps;
	int i, n;

	printf("��ȭ�� ���� : ");
	scanf("%d", &n);
	ps = (struct dvd *)malloc(n * sizeof(struct dvd));	//���� �޸� �Ҵ�
	if (ps == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	for (i = 0; i < n; i++) {
		printf("��ȭ�� ���� :");
		scanf("%s", ps[i].title);
		printf("��ȭ�� ���� :");
		scanf("%s", ps[i].rating);
	}
	printf("==================================\n");
	for (i = 0; i < n; i++) {
		printf("��ȭ�� ���� : %s\n", ps[i].title);
		printf("��ȭ�� ���� : %s\n", ps[i].rating);
	}
	printf("==================================\n");
	free(ps);	//�����޸� �ݳ�
	return 0;
}