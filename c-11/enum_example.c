#include <stdio.h>
enum game{scissor, rock, paper};

int main(void) {
	enum game computer = scissor;
	enum game user = scissor;

	printf("���� (0), ���� (1), �� (2)�� �Է��Ͻÿ� : ");
	scanf("%d", &user);
	if (user == scissor) {
		printf("�����ϴ�.\n");
	}
	if (user == rock) {
		printf("�̰���ϴ�.\n");
	}
	if (user == paper) {
		printf("�����ϴ�.\n");
	}

	return 0;
}