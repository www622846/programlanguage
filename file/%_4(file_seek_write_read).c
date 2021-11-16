#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct day_record {
	int date;
	int income;
	int expense;
}day_record;

int main(void) {
	FILE *fp1, *fp2, *fp3;
	day_record buffer[SIZE] = { {201004, 100, 800}, {201005, 900, 100}, {201006, 1100, 800} };
	day_record today_record = { 201007, 1300, 1000 };
	if ((fp1 = fopen("month.dat", "wb")) == NULL) {
		printf("�������� ������.");
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		fwrite(&buffer[i], sizeof(day_record), 1, fp1);
	}
	fclose(fp1);
	if ((fp2 = fopen("month.dat", "ab")) == NULL){
	fprintf(stderr, "���� ���� �� �����ϴ�.\n");
	exit(1);
	}
	fseek(fp2, 0, SEEK_END);
	fwrite(&today_record, sizeof(day_record), 1, fp2);
	fclose(fp2);
	if ((fp3 = fopen("month.dat", "rb")) == NULL) {
		fprintf(stderr, "���� month.dat�� �� �� �����ϴ�\n");
		exit(1);
	}
	for (int i = 0; i < 4; i++) {
		fread(&buffer[i], sizeof(day_record), 1, fp3);
		printf("��¥ : %d, ���� : %d, ���� : %d\n", buffer[i].date, buffer[i].income, buffer[i].expense);
	}
	fclose(fp3);
	return 0;
}