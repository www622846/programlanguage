#include <stdio.h>
#include <stdlib.h>


struct student {
	int id;
	char name[20];
	short score;
};

int main(void) {
	struct student rec;
	FILE *fp = fopen("example.bin", "wb");
	printf("%-9s %-7s %-4s\n", "�й�", "�̸�", "����");
	for (int i = 0; i < 3; i++) {
		scanf("%d %s %s", &rec.id, rec.name, &rec.score);
		fwrite(&rec, sizeof(rec), 1, fp);
	}
	fclose(fp);
	printf("--------------------------------\n");
	printf("%10s %6s %6s\n", "�й�", "�̸�", "����");
	printf("--------------------------------\n");

	if (fp = fopen("example.bin", "rb") == NULL) printf("�Է� ����"); exit(1);
	for (int i = 0; i < 3; i++) {
		fread(&rec, sizeof(rec), 1, fp);
		printf("%10d %6s %6s\n", rec.id, rec.name, rec.score);
	}
	printf("--------------------------------\n");
	fclose(fp);
	return 0;
}