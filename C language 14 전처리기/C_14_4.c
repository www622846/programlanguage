#include <stdio.h>
#define LINUX

int main(void) {
#ifdef LINUX
	printf("리눅스 버전입니다.\n");
#else // LINUX
	printf("원도우 버전입니다.\n");
#endif
	return 0;
}