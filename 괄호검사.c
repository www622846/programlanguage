#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

//��ȣ �˻�

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;
int stack[MAX_STACK_SIZE];
int top = -1;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int isEmpty(StackType *s) {
	return (s->top == -1);
}

//���� ��ȭ ���� �Լ�
int isFull(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(StackType *s, element item) {
	if (isFull(s)) {
		printf("stack is full\n");
	}
	else {
		s->stack[++(s->top)] = item;
	}
}

//���� �Լ�
element pop(StackType *s) {
	if (isEmpty(s)) {
		printf("stack is empty\n");
	}
	else {
		return s->stack[(s->top)--];
	}
}

//��ȣ �˻� �Լ�
int check_matching(char *in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);	//n = ���ڿ��� ����
	init_stack(&s);	//���� �ʱ�ȭ

	for (i = 0; i < n; i++) {
		ch = in[i];	//ch = ���� ����
		switch (ch) {
		case '(':case'[':case'{':
			push(&s, ch);	//(�� [�� {�̸� ����
			break;
		case')':case']':case'}':
			if (isEmpty(&s)) {
				return 0;	//������ ��������� 0
			}
			else {
				open_ch = pop(&s);	//��
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {	//(�� �� )�� �ƴϰų� [�� �� ]�� �ƴϰų� {�� �� }�� �ƴϸ�
					return 0;	//0�� ������
				}
				break;	
			}
		}
	}
	if (!isEmpty(&s)) return 0;	//������ �����ִٸ� 0�� ������ 
	return 1;	//�̻� ���� ��� 1�� ������
}

void main() {
	char *p = "{ A[(i+1)]=0; }";
	if (check_matching(p) == 1) {	//��ȣ �˻� ȣ�� �Լ�
		printf("%s ��ȣ �˻� ����\n", p);
	}
	else
	{
		printf("%s ��ȣ �˻� ����\n", p);
	}
}