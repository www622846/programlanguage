#include <stdio.h>
#include <string.h>
#define SIZE 3

struct tagBooks {
	char books[50];
	char press[50];
	int price;
};
int main(void) {

	struct tagBooks book[SIZE];
	int i;
	char title[SIZE][50] = { "C���", "", "������ ���α׷���" };
	char press[SIZE][50] = { "�������ǻ�", "", "�������л�" };
	int price[SIZE] = { 20000, 25000, 30000 };

	for (i = 0; i < SIZE; i++) {
		strcpy(book[i].books, title[i]);
		strcpy(book[i].press, press[i]);
		book[i].price = price[i];
	}
	book[1] = book[0];

	for (i = 0; i < SIZE; i++) {
		printf("������ : %s\n", book[i].books);
		printf("���ǻ� : %s\n", book[i].press);
		printf("��  �� : %d\n", book[i].price);
		printf("\n");
	}
	
	return 0;
}