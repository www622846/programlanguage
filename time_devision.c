#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void time_devision(char *s);

int main(void) {
	char str[50];
	printf("시간을 입력 ");	//시, 분, 초, 다 두 자리 수로 입력 ->130725
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
		printf("문자열을 잘못 입력하였습니다.\n");
		return -1;
	}

	if (hour > 12) {
		hour -= 12;
		printf("오후 %d시 %d분 %d초\n", hour, min, sec);
	}
	else
	{
		printf("오전 %d시 %d분 %d초\n", hour, min, sec);
	}
}