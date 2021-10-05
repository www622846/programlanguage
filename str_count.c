#include <stdio.h>

void str_count(char *parray[], int n);

int main(void) {
	int i = 0;
	char *parray[] = { "data structure", "programming language", "operationg system" };
	str_count(parray, 3);
	return 0;
}

void str_count(char *parray[], int n) {
	int i, j;
	for (i = 0; i < 3; i++) {
		printf("%s 각 문자열의 크기는 >> ", parray[i]);
		j = 0;
		while (*(parray[i] + j) != NULL)//각 문자열의 크기를 계산
		{
			j++;
		}
		printf("%d\n", j);
	}
	return 0;
}