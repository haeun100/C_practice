#include <stdio.h>
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
	int day;
	printf("기원 후 몇번째 날입니까? ");
	scanf_s("%d", &day);
	PrintDayofTheWeek(day);
	return 0;
}