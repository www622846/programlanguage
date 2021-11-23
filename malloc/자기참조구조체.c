#include <stdio.h>
#include <stdlib.h>

//자기참조 구조체
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
	
	printf("첫번째 구조체 : \n");
	printf("자료 값 (first->n) = %d\n", first->n);


	printf("두번째 구조체 : \n");
	printf("자료 값 (second->n) = %d\n", second->n);
	printf("자료 값 (first->next->n) = %d\n", first->next->n);
	free(first);
	free(second);
	return 0;
}
