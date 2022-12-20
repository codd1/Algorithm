/*
	문제 2: 다이아몬드 판매
	
	무게가 W(양의 정수)인 다이아몬드가 있다. 다이아몬드는 무게가 i(양의 정수), 1≤i≤W-1, 인 조각 다이아몬드로 자를 수 있다.
	무게가 i, 1≤i≤W, 인 다이아몬드의 판매 가격은 p_i 이다.
	무게가 W인 다이아몬드에서 무게가 i, 1≤i≤w, 인 조각 다이아몬드로 자르는 비용은 c_i 이다.
	무게가 W 인 다이아몬드를 자르지 않고 통째로 판매하거나 여러 개의 정수 무게의 조각 다이아몬드들로 잘라서 판매할 때 얻을 수 있는 최대 금액을 구하려고 한다.
	최대 금액은 다이아몬드(들)을 판매해서 얻을 수 있는 금액에서 다이아몬드를 자르는 비용을 제외해야 한다.

	기초하여 무게가 W인 다이아몬드를 자르지 않고 통째로 판매하거나 여러 개의 정수 무게의 조각 다이아몬드들로 잘라서 판매할 때 얻을 수 있는 최대 금액을 구하는 동적 계획 알고리즘을 작성하라.
	작성한 알고리즘의 시간복잡도를 차수(세타) 표기법으로 표시하라.
*/

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