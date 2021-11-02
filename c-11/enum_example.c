#include <stdio.h>
enum game{scissor, rock, paper};

int main(void) {
	enum game computer = scissor;
	enum game user = scissor;

	printf("가위 (0), 바위 (1), 보 (2)를 입력하시오 : ");
	scanf("%d", &user);
	if (user == scissor) {
		printf("비겼습니다.\n");
	}
	if (user == rock) {
		printf("이겼습니다.\n");
	}
	if (user == paper) {
		printf("졌습니다.\n");
	}

	return 0;
}