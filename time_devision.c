#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void time_devision(char *s);

int main(void) {
	char str[50];
	printf("�ð��� �Է� ");	//��, ��, ��, �� �� �ڸ� ���� �Է� ->130725
	scanf("%s", str);
	time_devision(str);
	return 0;
}

void time_devision(char *s) {
	int i, hour, min, sec;
	char temp[3];

	for (i = 0; i <= 1; i++) {
		temp[i] = s[i];
	}
	temp[2] = '\0';
	hour = atoi(temp);

	for (i = 0; i <= 1; i++) {
		temp[i] = s[2 + i];
	}
	min = atoi(temp);

	for (i = 0; i <= 1; i++) {
		temp[i] = s[4 + i];
	}
	sec = atoi(temp);

	if (hour > 23 || min > 59 || sec > 59) {
		printf("���ڿ��� �߸� �Է��Ͽ����ϴ�.\n");
		return -1;
	}

	if (hour > 12) {
		hour -= 12;
		printf("���� %d�� %d�� %d��\n", hour, min, sec);
	}
	else
	{
		printf("���� %d�� %d�� %d��\n", hour, min, sec);
	}
}