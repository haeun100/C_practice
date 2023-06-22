#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int x1, y1, x2, y2;
	int area;

	printf("사각형의 좌표(x1 y1 x2 y2): ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	area = (x2 - x1) * (y2 - y1);
	printf("사각형의 면적 = %d\n", area);
	return 0;
}