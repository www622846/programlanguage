#include <stdio.h>

int main(void) {
	int i;
	char menu[5][10] = {
		"init",
		"open",
		"close",
		"read",
		"write"
	};//포인터로 메모리 아낄 수 있음.

	for (i = 0; i < 5; i++) {
		printf("%d 번째 메뉴 : %s\n",i, menu[i]);
	}

	return 0;
}