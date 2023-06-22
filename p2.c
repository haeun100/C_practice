#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

	printf("사각형1의 좌표 입력: ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("사각형2의 좌표 입력: ");
	scanf("%d%d%d%d", &x3, &y3, &x4, &y4);

	if (x3 < x2)
		printf("겹친다.");
	else
		printf("겹치지 않는다.");

	return 0;
}