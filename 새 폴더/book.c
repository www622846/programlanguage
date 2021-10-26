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
	char title[SIZE][50] = { "C언어", "", "윈도우 프로그래밍" };
	char press[SIZE][50] = { "생능출판사", "", "정보문학사" };
	int price[SIZE] = { 20000, 25000, 30000 };

	for (i = 0; i < SIZE; i++) {
		strcpy(book[i].books, title[i]);
		strcpy(book[i].press, press[i]);
		book[i].price = price[i];
	}
	book[1] = book[0];

	for (i = 0; i < SIZE; i++) {
		printf("도서명 : %s\n", book[i].books);
		printf("출판사 : %s\n", book[i].press);
		printf("가  격 : %d\n", book[i].price);
		printf("\n");
	}
	
	return 0;
}