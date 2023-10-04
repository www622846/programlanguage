#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

//괄호 검사

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;
int stack[MAX_STACK_SIZE];
int top = -1;

//스택 초기화 함수
void init_stack(StackType *s) {
	s->top = -1;
}

//스택 공백 검출 함수
int isEmpty(StackType *s) {
	return (s->top == -1);
}

//스택 포화 검출 함수
int isFull(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(StackType *s, element item) {
	if (isFull(s)) {
		printf("stack is full\n");
	}
	else {
		s->stack[++(s->top)] = item;
	}
}

//삭제 함수
element pop(StackType *s) {
	if (isEmpty(s)) {
		printf("stack is empty\n");
	}
	else {
		return s->stack[(s->top)--];
	}
}

//괄호 검사 함수
int check_matching(char *in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);	//n = 문자열의 길이
	init_stack(&s);	//스택 초기화

	for (i = 0; i < n; i++) {
		ch = in[i];	//ch = 다음 문자
		switch (ch) {
		case '(':case'[':case'{':
			push(&s, ch);	//(나 [나 {이면 삽입
			break;
		case')':case']':case'}':
			if (isEmpty(&s)) {
				return 0;	//스택이 비어있으면 0
			}
			else {
				open_ch = pop(&s);	//팝
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {	//(일 때 )가 아니거나 [일 때 ]가 아니거나 {일 때 }가 아니면
					return 0;	//0을 내보냄
				}
				break;	
			}
		}
	}
	if (!isEmpty(&s)) return 0;	//아직도 남아있다면 0을 내보냄 
	return 1;	//이상 없을 경우 1을 내보냄
}

void main() {
	char *p = "{ A[(i+1)]=0; }";
	if (check_matching(p) == 1) {	//괄호 검사 호출 함수
		printf("%s 괄호 검사 성공\n", p);
	}
	else
	{
		printf("%s 괄호 검사 실패\n", p);
	}
}