#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

	printf("�簢��1�� ��ǥ �Է�: ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("�簢��2�� ��ǥ �Է�: ");
	scanf("%d%d%d%d", &x3, &y3, &x4, &y4);

	if (x3 < x2)
		printf("��ģ��.");
	else
		printf("��ġ�� �ʴ´�.");

	return 0;
}