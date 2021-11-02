#include <stdio.h>
struct sample_student {
	char name[50];
	int age;
	long number;
	int score;
};
void print_student_info(struct sample_student* s);
struct sample_student get_max_score(struct sample_student *ps, int student_count);


int main(void) {
	struct sample_student s[]= { {"홍길동", 20, 1001, 90}, {"이영희", 19, 1002, 50}, {"김길동", 21,1003,100} };

	struct sample_student student = { 0 };
	int count = 0;
	count = sizeof(s) / sizeof(struct sample_student);
	student = get_max_score(s, count );
	printf("최고 성적을 얻은 학생 정보\n");
	print_student_info(&student);

	return 0;
}
struct sample_student get_max_score(struct sample_student *ps, int student_count) {
	struct sample_student result = { 0 };
	int max_score = 0, max_index = 0, i = 0;
	if (NULL != ps && student_count > 0) {
		max_score = ps[0].score;
		max_index = 0;
		for (i = 1; i < student_count; i++) {
			if (ps[i].score >= max_score) {
				max_index = i;
				max_score = ps[i].score;
			}
		}
		result = ps[max_index];
	}
	else
	{
		printf("오류 NULL\n");
	}
	return result;
}

void print_student_info(struct sample_student* s) {
	if (NULL != s) {
		printf("이름 : %s\n나이 : %d\n학번 : %d\n점수 : %d\n", s->name, s->age, s->number, s->score);
	}
	else
	{
		printf("NULL오류");
	}
}