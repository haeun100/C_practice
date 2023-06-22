#include <stdio.h>
int IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int main() {
	int year;
	printf("연도를 입력하세요: ");
	scanf_s("%d", &year);

	if (IsLeapYear(year))
		printf("%d년은 윤년입니다.\n", year);
	else
		printf("%d년은 윤년이 아닙니다.\n", year);
	return 0;
}