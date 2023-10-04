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
	push(1);	//1를 스택에 집어 넣음
	push(2);	//2를 스택에 집어 넣음
	push(3);	//3를 스택에 집어 넣음
	printf("%d\n",pop());	//3을 스택에서 가져옴
	printf("%d\n", pop());	//2을 스택에서 가져옴
	printf("%d\n", pop());	//1을 스택에서 가져옴
}