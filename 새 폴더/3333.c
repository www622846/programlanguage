#include <stdio.h>
#include <string.h>

struct tagBooks {
	char books[50];
	char press[50];
	int price;
};
int main(void) {
	struct tagBooks book;
	strcpy(book.books, "C���");
	strcpy(book.press, "���� ���ǻ�");
	book.price = 20000;

	printf("������ : %s\n", book.books);
	printf("���ǻ� : %s\n", book.press);
	printf("��  �� : %d\n", book.price);

}