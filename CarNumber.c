#include <stdio.h>
#include <string.h>

void CarNumber(char *s);

int main(void) {
	char *str[50];
	printf("자동차 번호 입력 : (XX가 XXXX형식):");
	scanf("%s", str);
	CarNumber(str);
	return 0;
}

void CarNumber(char *s) {
	int i, number = 0;
	char car[3];
	for (i = 0; i <= 1; i++) car[i] = s[i];//차 번호 두자리 car배열로 복사
	car[number] = '\0';
	number = atoi(car);
	if (number < 70) {
		printf("승용차\n");
	}
	else if (number < 80) {
		printf("승합차\n");
	}
	else if (number < 98) {
		printf("화물차\n");
	}
	else if(number < 100)
	{
		printf("특수차\n");
	}
	else
	{
		printf("차가 아닙니다.\n");
	}

}