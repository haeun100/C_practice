#include <stdio.h>
int IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int main() {
	int year;
	printf("������ �Է��ϼ���: ");
	scanf_s("%d", &year);

	if (IsLeapYear(year))
		printf("%d���� �����Դϴ�.\n", year);
	else
		printf("%d���� ������ �ƴմϴ�.\n", year);
	return 0;
}