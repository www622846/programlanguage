#include <string.h>
#include <stdio.h>

int main(void) {
	char str_source[] = "ABCabc012ABC";
	char *pFind = NULL;
	int position = 0;
	puts(str_source);
	pFind = (strchr(str_source, 'c'));
	if (NULL != pFind) {
		position = pFind - str_source;
		printf("문자 %c의 위치 : %d\n", 'c', position);
	}

	return 0;
}