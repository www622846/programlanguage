#include <stdio.h>


int main(void) {
	char s[] = "HelloWorld";
	char *p = "HelloWorld";

	s[0] = 'h';//���� ����.
	// *p[0] = 'h'; ���α׷��� ������

	printf("�����Ͱ� ����Ű�� ���ڿ� %s\n", p);
	p = "GoodBye";	//�̰��� �ٲ� �� ����.
	printf("�����Ͱ� ����Ű�� ���ڿ� %s\n", p);


	return 0;
}