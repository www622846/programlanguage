#include <stdio.h>
#include <stdlib.h>

//�ڱ����� ����ü
struct pselfer {
	int n;
	struct pselfer *next;
};
typedef struct pselfer list;

int main(void) {
	list *first = NULL, *second = NULL;

	first = (list *)malloc(sizeof(list));
	first->n = 100;
	first->next = NULL;
	second = (list *)malloc(sizeof(list));
	second->n = 200;
	second->next = NULL;
	first->next = second;
	
	printf("ù��° ����ü : \n");
	printf("�ڷ� �� (first->n) = %d\n", first->n);


	printf("�ι�° ����ü : \n");
	printf("�ڷ� �� (second->n) = %d\n", second->n);
	printf("�ڷ� �� (first->next->n) = %d\n", first->next->n);
	free(first);
	free(second);
	return 0;
}
