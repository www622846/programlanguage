#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef int QueueObject;
QueueObject queue[MAX_QUEUE_SIZE];
int front, rear;

void initalize() {	//ť �ʱ�ȭ �Լ�
	front = rear = 0;
}

int isEmpty() {	//ť�� ���� ���� �˻� �Լ�
	return (front == rear);
}

int isFull() {	//ť�� ��ȭ ���� �˻� �Լ�
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(QueueObject item) {	//ť���� ��Ҹ� �߰��ϴ� �Լ�
	if (isFull()) {	//ť�� ��ȭ ������ ���� �˻�
		printf("queue is full\n");
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

int deleteq() {	//ť���� ��Ҹ� �������� �Լ�
	if (isEmpty()) {	//ť�� ��� �ִ� ���� �˻�
		printf("queue is empty\n");
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

void main() {
	printf("front = %d rear = %d\n", front, rear);
	printf("addq(1)\n");
	addq(1);
	printf("addq(2)\n");
	addq(2); 
	printf("addq(3)\n");
	addq(3);
	printf("front = %d rear = %d\n", front, rear);
	printf("deleteq() = %d\n", deleteq());
	printf("deleteq() = %d\n", deleteq());
	printf("deleteq() = %d\n", deleteq());
	printf("front = %d, rear = %d\n", front, rear);
}