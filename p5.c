#include <stdio.h>
void PrintDayofTheWeek(int days) {
	switch (days % 7) {
	case 0:
		printf("�Ͽ����Դϴ�.\n");
		break;
	case 1:
		printf("�������Դϴ�.\n");
		break;
	case 2:
		printf("ȭ�����Դϴ�.\n");
		break;
	case 3:
		printf("�������Դϴ�.\n");
		break;
	case 4:
		printf("������Դϴ�.\n");
		break;
	case 5:
		printf("�ݿ����Դϴ�.\n");
		break;
	case 6:
		printf("������Դϴ�.\n");
		break;
	}
}
int main() {
	int day;
	printf("��� �� ���° ���Դϱ�? ");
	scanf_s("%d", &day);
	PrintDayofTheWeek(day);
	return 0;
}