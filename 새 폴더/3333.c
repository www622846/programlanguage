#include <stdio.h>
#include <string.h>

struct tagBooks {
	char books[50];
	char press[50];
	int price;
};
int main(void) {
	struct tagBooks book;
	strcpy(book.books, "C언어");
	strcpy(book.press, "생능 출판사");
	book.price = 20000;

	printf("도서명 : %s\n", book.books);
	printf("출판사 : %s\n", book.press);
	printf("가  격 : %d\n", book.price);

}