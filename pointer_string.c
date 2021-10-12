#include <stdio.h>


int main(void) {
	char s[] = "HelloWorld";
	char *p = "HelloWorld";

	s[0] = 'h';//변경 가능.
	// *p[0] = 'h'; 프로그램이 중지됨

	printf("포인터가 가리키는 문자열 %s\n", p);
	p = "GoodBye";	//이것은 바꿀 수 있음.
	printf("포인터가 가리키는 문자열 %s\n", p);


	return 0;
}