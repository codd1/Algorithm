#include <stdio.h>

#define W 4

int MAX(int num1, int num2);

int cutDiaSell(int p[], int c[], int w) {
	//배열 maxSell[0...W]을 선언한다.
	int maxSell[W+1];
	int maxVal;

	maxSell[0] = 0;
	for (int j = 1; j <= w; j++) {
		maxVal = 0;
		for (int k = 1; k <= j; k++) {
			maxVal = MAX(maxVal, p[k] + maxSell[j - k] - c[j - k]);
		}
		maxSell[j] = maxVal;
	}
	return maxSell[w];
}

int main() {
	int p[] = { 0,3,4,8,9 };
	int c[] = { 0,1,2,1 };

	printf("다이아몬드 판매 최대 금액: %d\n", cutDiaSell(p, c, W));

	return 0;
}

int MAX(int num1, int num2) {
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}