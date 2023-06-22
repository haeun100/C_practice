#include <stdio.h>
int IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}

int GetDayRankInsideYear(int year, int month, int day) {
	int i;
	int count = 0;
	for (i = 1; i <= month - 1; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			count += 31;
		else if (i == 2) {
			if (IsLeapYear(year))
				count += 29;
			else
				count += 28;
		}
		else
			count += 30;
	}
	count += day;
	return count;
}

int main() {
	int year, month, day;
	printf("날짜를 입력하세요 (년 월 일) : ");
	scanf_s("%d %d %d", &year, &month, &day);

	printf("%d년의 %d번째 날입니다.\n", year, GetDayRankInsideYear(year, month, day));
	return 0;
}