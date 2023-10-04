//Deque

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5


typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeObject;

void initalize(DequeObject *q) {	//ť �ʱ�ȭ �Լ�
	q->front = q->rear = 0;
}

int isEmpty(DequeObject *q) {	//ť�� ���� ���� �˻� �Լ�
	return (q->front == q->rear);
}

int isFull(DequeObject *q) {	//ť�� ��ȭ ���� �˻� �Լ�
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//���� ť ��� �Լ�

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

void addq_rear(DequeObject *q, element item) {	//ť���� ��Ҹ� �߰��ϴ� �Լ�
	if (isFull(q)) {	//ť�� ��ȭ ������ ���� �˻�
		printf("queue is full\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int delete_rear(DequeObject *q) {	//ť���� ��Ҹ� �������� �Լ�
	int prev = q - rear;
	if (isEmpty(q)) {
		printf("ť�� ���� �����Դϴ�");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	//�ڷ� ���� ���
	return q->data[prev];
}
int deleteq(DequeObject *q) {	//ť���� ��Ҹ� �������� �Լ�
	if (isEmpty(q)) {	//ť�� ��� �ִ� ���� �˻�
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