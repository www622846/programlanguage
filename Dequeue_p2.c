//Deque

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5


typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeObject;

void initalize(DequeObject *q) {	//큐 초기화 함수
	q->front = q->rear = 0;
}

int isEmpty(DequeObject *q) {	//큐의 공백 상태 검사 함수
	return (q->front == q->rear);
}

int isFull(DequeObject *q) {	//큐의 포화 상태 검사 함수
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//원형 큐 출력 함수

void deque_print(DequeObject *q) {
	printf("DEQUE(front = %d rear = %d) =", q->front, q->rear);
	if (!isEmpty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | " q->data[i]);
			if (i == q->rear) {
				break;
			}while (i != q->front);
		}
		printf("\n");
	}
}

void addq_rear(DequeObject *q, element item) {	//큐에서 요소를 추가하는 함수
	if (isFull(q)) {	//큐가 포화 상태인 지를 검사
		printf("queue is full\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int delete_rear(DequeObject *q) {	//큐에서 요소를 가져오는 함수
	int prev = q - rear;
	if (isEmpty(q)) {
		printf("큐가 공백 상태입니다");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	//뒤로 가는 경우
	return q->data[prev];
}
int deleteq(DequeObject *q) {	//큐에서 요소를 가져오는 함수
	if (isEmpty(q)) {	//큐가 비어 있는 지를 검사
		printf("queue is empty\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void main() {
	DequeObject queue;

	initalize(&queue);
	for (int i = 0; i < 3; i++) {
		addq_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
}