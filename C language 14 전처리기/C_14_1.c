#include <stdio.h>
#define and &&


int main(void) {
	int credits;
	double gpa;
	printf("���ݱ��� ȹ���� �������� �Է��Ͻÿ� : ");
	scanf("%d", &credits);
	printf("���ݱ��� ȹ���� ��������� �Է��Ͻÿ� : ");
	scanf("%lf", &gpa);

	if (credits >= 120 and gpa >= 2.0)
		printf("���� �����մϴ�.\n");
	else
		printf("�� �� �ٳ���մϴ�.\n");

	return 0;
}