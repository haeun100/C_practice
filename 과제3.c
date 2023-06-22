#define _CRT_SECURE_NO_WARNINGS
#define N 30  // 학급 최대 크기
#include <stdio.h>
#include <string.h>

// 학급 학생 정보
char s[N][10];   // 학생 이름
int midterm[N], final[N]; // 중간시험, 기말시험 점수
int n; // 파일에 저장되어 있는 학생 수

// 함수 프로토타입
void readClassInfo();
void printClass();
void sortClass();
void computeClassAvg();
void searchStudent();

// 학생 정보 읽어 저장하고 출력
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

	printf("*** 학급 점수 (입력순) ***\n");
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
	printf("\n*** 학급 점수 (가나다순) ***\n");
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

	printf("\n*** 학급 성적 평균 ***\n");
	printf("학급 중간시험 평균 = %.2f\n", midtermAvg);
	printf("학급 기말시험 평균 = %.2f\n", finalAvg);
}

void searchStudent() {
	char name[10];
	char finish[10] = { "끝" };
	double avg, add;
	printf("\n*** 학생 정보 검색 ***\n");
	while (1) {
		int count = 0;
		printf("학생 이름을 입력하시오: ");
		scanf("%s", name);
		if (strcmp(name, finish) == 0) {
			printf("다음에 만나요!\n");
			break;
		}
		for (int i = 0; i < n; i++)
			if (strcmp(name, s[i]) == 0) {
				count = 1;
				add = midterm[i] + final[i];
				avg = add / 2;
				printf("중간 = %d, 기말 = %d, 평균 = %.2f\n\n", midterm[i], final[i], avg);
			}
		if (count == 0)
			printf("%s 학생은 학급에 없습니다.\n\n", name);
	}
}

void main() {
	readClassInfo();
	sortClass();
	computeClassAvg();
	searchStudent();
}