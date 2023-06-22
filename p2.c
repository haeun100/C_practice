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

int main() {
	int year;
	printf("연도를 입력하세요: ");
	scanf_s("%d", &year);

	printf("%d년에는 %d일이 있습니다.\n", year, GetNumDaysInYear(year));
	return 0;
}