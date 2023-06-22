#define _CRT_SECURE_NO_WARNINGS
#define N 30  // �б� �ִ� ũ��
#include <stdio.h>
#include <string.h>

// �б� �л� ����
char s[N][10];   // �л� �̸�
int midterm[N], final[N]; // �߰�����, �⸻���� ����
int n; // ���Ͽ� ����Ǿ� �ִ� �л� ��

// �Լ� ������Ÿ��
void readClassInfo();
void printClass();
void sortClass();
void computeClassAvg();
void searchStudent();

// �л� ���� �о� �����ϰ� ���
void readClassInfo() {
	FILE* fp = NULL;
	fp = fopen("student-info.txt", "r");
	int i = 0;
	while (i < N) {
		if (fscanf(fp, "%s%d%d", s[i], &midterm[i], &final[i]) == 3) {
			i++;
			n = i;
		}
		else
			break;
	}
	fclose(fp);

	printf("*** �б� ���� (�Է¼�) ***\n");
	printClass();
}

void sortClass() {
	char temp[10];
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < (n - 1) - i; j++)
			if (strcmp(s[j], s[j + 1]) == 1) {
				strcpy(temp, s[j]);
				strcpy(s[j], s[j + 1]);
				strcpy(s[j + 1], temp);
				a = midterm[j];
				midterm[j] = midterm[j + 1];
				midterm[j + 1] = a;
				b = final[j];
				final[j] = final[j + 1];
				final[j + 1] = b;
			}
	}
	printf("\n*** �б� ���� (�����ټ�) ***\n");
	printClass();
}

void printClass() {
	for (int i = 0; i < n; i++) {
		printf("[%d] %s %d %d\n", i, s[i], midterm[i], final[i]);
	}
}

void computeClassAvg() {
	double midtermAvg, finalAvg;
	double count1 = 0;
	double count2 = 0;
	for (int i = 0; i < n; i++)
		count1 += midterm[i];
	midtermAvg = count1 / n;
	for (int i = 0; i < n; i++)
		count2 += final[i];
	finalAvg = count2 / n;

	printf("\n*** �б� ���� ��� ***\n");
	printf("�б� �߰����� ��� = %.2f\n", midtermAvg);
	printf("�б� �⸻���� ��� = %.2f\n", finalAvg);
}

void searchStudent() {
	char name[10];
	char finish[10] = { "��" };
	double avg, add;
	printf("\n*** �л� ���� �˻� ***\n");
	while (1) {
		int count = 0;
		printf("�л� �̸��� �Է��Ͻÿ�: ");
		scanf("%s", name);
		if (strcmp(name, finish) == 0) {
			printf("������ ������!\n");
			break;
		}
		for (int i = 0; i < n; i++)
			if (strcmp(name, s[i]) == 0) {
				count = 1;
				add = midterm[i] + final[i];
				avg = add / 2;
				printf("�߰� = %d, �⸻ = %d, ��� = %.2f\n\n", midterm[i], final[i], avg);
			}
		if (count == 0)
			printf("%s �л��� �б޿� �����ϴ�.\n\n", name);
	}
}

void main() {
	readClassInfo();
	sortClass();
	computeClassAvg();
	searchStudent();
}