#include <stdio.h>//printf(), scanf()를 쓸 수 있게 해줌
#include <math.h>//sqrt()를 쓸 수 있게 해줌
#include <string.h>//문자열 길이를 알 수 는있는strlen(), 문자열 비교가 비교한 strcmp()쓰기 위해서 필요함

char data[8][10] = { "정육면체", "구", "원뿔", "원기둥", "정사면체", "직육면체","삼각뿔", "정사각뿔" };//8개의 문자열
char c[] = "";//도형의 값을 받는 문자
int check = 0;
int mm(char in); //부피를 측정하는 함수
void reset();//다시 시작할 지 물어보는 함수
char stringtochar(char string[]);//문자열을 a,b,c,d...로 바꾸는함수
void select_(char ch);//선택한 입체도형을 말해주는 함수

int main(void) {
	if (check == 0) {
		printf("\t\tVolume Program (부피 프로그램)\n\n");
		check = 1;
	}
	printf("부피를 구하고 싶은 입체도형을 입력하세요. [이름과 소문자 둘다 입력가능]\n(정육면체 : a | 구 : b | 원뿔 : c | 원기둥  : d | 정사면체 : e | 직육면체 : f | 삼각뿔 : g | 정사각뿔 : h) >> ");
	scanf("%s", &c);
	if (strlen(c) > 1) {
		mm(stringtochar(c));
	}
	else
	{
		mm(c[0]);
	}
	reset();
	return 0;
}
void reset() {
	while (1)
	{
		printf("\n\n\t다시 입력하시겠습니까?\n\n\t예 : Y\t아니오 : N\n>> ");
		scanf("%s", &c);
		if (c[0] == 'Y' || c[0] == 'y') {
			printf("\n===========================================================================\n\n");
			main();
			break;
		}
		else if (c[0] == 'N' || c[0] == 'n') {
			printf("\t종료합니다...\n\n");
			break;
		}
	}
}
int mm(char in) {
	double x, y, z, result = 0;//입력값 3개와 결과값
	switch (in)
	{
	case 'a'://정육면체
		select_('a');
		printf("한 변의 길이를 입력하세요 : ");
		scanf("%lf", &x);
		result = x * x * x;
		printf("정육면체");
		break;
	case 'b'://구
		select_('b');
		printf("반지름을 입력하세요 : ");
		scanf("%lf", &x);
		result = x * x * x * 3.14 * 4.0 / 3.0;
		printf("구");
		break;
	case 'c'://원뿔
		select_('c');
		printf("반지름 높이를 입력하세요 : ");
		scanf("%lf %lf", &x, &y);
		result = x * x  * 3.14 * y * 1.0 / 3.0;
		printf("원뿔");
		break;
	case 'd'://원기둥
		select_('d');
		printf("반지름 높이를 입력하세요 : ");
		scanf("%lf %lf", &x, &y);
		result = x * x  * 3.14 * y;
		printf("원기둥");
		break;
	case 'e'://정사면체
		select_('e');
		printf("한 변의 길이를 입력하세요 : ");
		scanf("%lf", &x);
		result = sqrt(2) / 12.0 * x *x * x;
		printf("정사면체");
		break;
	case 'f'://직육면체
		select_('f');
		printf("가로 세로 높이를 입력하세요 : ");
		scanf("%lf %lf %lf", &x, &y, &z);
		result = x * y * z;
		printf("직육면체");
		break;
	case 'g'://삼각뿔
		select_('g');
		printf("밑변의 넓이 높이를 입력하세요 : ");
		scanf("%lf %lf", &x, &y);
		result = x * y * 1.0 / 3.0;
		printf("삼각뿔");
		break;
	case 'h'://정사각뿔
		select_('h');
		printf("밑변의 길이 높이를 입력하세요 : ");
		scanf("%lf %lf", &x, &y);
		result = x * x  * y * 1.0 / 3.0;
		printf("정사각뿔");
		break;
	default :
		printf("다시 입력해주세요.\n");
		main();
		break;
	}
	printf("의 부피 : %lf\n", result);
	return 0;
}
void select_(char ch) {
	printf("%s(을)를 선택하셨습니다.\n", data[(int)(ch - 'a')]);
	printf("%s | ", data[(int)(ch - 'a')]);
}
char stringtochar(char string[]) {
	char rec;
	int i, count;
	count = 0;
	for (i = 0; i < 8; i++) {
		if (strcmp(data[i], string) == 0) {
			count++;
			rec = 97 + i;
			return rec;
		}
	}
	if (count == 0) {
		printf("다시 입력해주세요.\n");
		main();
	}
}