#include <stdio.h>
#define SIZE 3

struct student {
	int number;
	char name[10];
	double grade;
};
int main(void) {
	struct student list[SIZE];
	int i;

	for (i = 0; i < SIZE; i++) {
		printf("�й��� �Է��Ͻÿ�.");
		scanf("%d", &list[i].number);
		printf("�̸��� �Է��Ͻÿ�.");
		scanf("%s", &list[i].name);
		printf("������ �Է��Ͻÿ�.");
		scanf("%lf", &list[i].grade);
		printf("\n");
	}

	printf("\n============================================================\n");
	for (i = 0; i < SIZE; i++) {
		printf("�й� : %d \n�̸� : %s \n���� : %lf\n", list[i].number, list[i].name, list[i].grade);
	}
	printf("============================================================\n");

	return 0;
}