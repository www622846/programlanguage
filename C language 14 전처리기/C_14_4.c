#include <stdio.h>
#define LINUX

int main(void) {
#ifdef LINUX
	printf("������ �����Դϴ�.\n");
#else // LINUX
	printf("������ �����Դϴ�.\n");
#endif
	return 0;
}