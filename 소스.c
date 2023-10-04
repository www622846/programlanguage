#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
int stack[MAX_STACK_SIZE];
int top = -1;

void init_stack() {
	top = -1;
}

int isEmpty() {
	return (top == -1);
}

int isFull() {
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) {
	if (isFull()) {
		printf("stack is full\n");
	}
	else {
		stack[++top] = item;
	}
}

element pop() {
	if (isEmpty()) {
		printf("stack is empty\n");
	}
	else {
		return stack[top--];
	}
}

void main() {
	push(1);	//1�� ���ÿ� ���� ����
	push(2);	//2�� ���ÿ� ���� ����
	push(3);	//3�� ���ÿ� ���� ����
	printf("%d\n",pop());	//3�� ���ÿ��� ������
	printf("%d\n", pop());	//2�� ���ÿ��� ������
	printf("%d\n", pop());	//1�� ���ÿ��� ������
}