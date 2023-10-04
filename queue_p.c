#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef int QueueObject;
QueueObject queue[MAX_QUEUE_SIZE];
int front, rear;

void initalize() {	//큐 초기화 함수
	front = rear = 0;
}

int isEmpty() {	//큐의 공백 상태 검사 함수
	return (front == rear);
}

int isFull() {	//큐의 포화 상태 검사 함수
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(QueueObject item) {	//큐에서 요소를 추가하는 함수
	if (isFull()) {	//큐가 포화 상태인 지를 검사
		printf("queue is full\n");
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

int deleteq() {	//큐에서 요소를 가져오는 함수
	if (isEmpty()) {	//큐가 비어 있는 지를 검사
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