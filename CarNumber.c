#include <stdio.h>
#include <string.h>

void CarNumber(char *s);

int main(void) {
	char *str[50];
	printf("�ڵ��� ��ȣ �Է� : (XX�� XXXX����):");
	scanf("%s", str);
	CarNumber(str);
	return 0;
}

void CarNumber(char *s) {
	int i, number = 0;
	char car[3];
	for (i = 0; i <= 1; i++) car[i] = s[i];//�� ��ȣ ���ڸ� car�迭�� ����
	car[number] = '\0';
	number = atoi(car);
	if (number < 70) {
		printf("�¿���\n");
	}
	else if (number < 80) {
		printf("������\n");
	}
	else if (number < 98) {
		printf("ȭ����\n");
	}
	else if(number < 100)
	{
		printf("Ư����\n");
	}
	else
	{
		printf("���� �ƴմϴ�.\n");
	}

}