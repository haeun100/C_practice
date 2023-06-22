#include <stdio.h>
int IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int GetNumDaysInYear(int year) {
	if (IsLeapYear(year))
		return 366;
	else
		return 365;
}
int GetTotalNumDays(int year) {
	int i;
	int count = 0;
	for (i = 1; i <= year; i++)
		count += GetNumDaysInYear(i);
	return count;
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
void PrintDayofTheWeek(int days) {
	switch (days % 7) {
	case 0:
		printf("일요일입니다.\n");
		break;
	case 1:
		printf("월요일입니다.\n");
		break;
	case 2:
		printf("화요일입니다.\n");
		break;
	case 3:
		printf("수요일입니다.\n");
		break;
	case 4:
		printf("목요일입니다.\n");
		break;
	case 5:
		printf("금요일입니다.\n");
		break;
	case 6:
		printf("토요일입니다.\n");
		break;
	}
}

int main() {
	int year, month, day;
	int days;
	while (1) {
		printf("날짜를 입력하세요 (년 월 일): ");
		scanf_s("%d %d %d", &year, &month, &day);

		if (year == 0) {
			printf("안녕!\n");
			break;
		}
		else {
			days = GetTotalNumDays(year - 1) + GetDayRankInsideYear(year, month, day);
			PrintDayofTheWeek(days);
		}
	}
	return 0;
}