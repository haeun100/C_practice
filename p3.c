#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	int x5, y5, x6, y6;
	int area;

	printf("�簢��1�� ��ǥ �Է�: ");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	printf("�簢��2�� ��ǥ �Է�: ");
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
	printf("\n");

	if (x3 < x2) {
		if (x3 > x1 && y3 > y1) {
			x5 = x3;
			y5 = y3;
		}
		else if (x3 > x1 && y3 < y1) {
			x5 = x3;
			y5 = y1;
		}
		else if (x3 < x1 && y3 > y1) {
			x5 = x1;
			y5 = y3;
		}
		else {
			x5 = x1;
			y5 = y1;
		}

		if (x2 < x4 && y2 < y4) {
			x6 = x2;
			y6 = y2;
		}
		else if (x2<x4 && y2>y4) {
			x6 = x2;
			y6 = y4;
		}
		else if (x2 > x4 && y2 < y4) {
			x6 = x4;
			y6 = y2;
		}
		else {
			x6 = x4;
			y6 = y4;
		}
		area = (x6 - x5) * (y6 - y5);
		printf("��ġ�� �κ��� ��ǥ= (%d,%d),(%d,%d)\n", x5, y5, x6, y6);
		printf("��ġ�� �κ��� ����= %d", area);
	}
	else
		printf("��ġ�� �ʴ´�.");
	return 0;
}