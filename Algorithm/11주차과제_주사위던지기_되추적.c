/*
	문제 1: 주사위 던지기
	
	n(> 1)개의 주사위를 던졌을 때 눈들의 합이 k, 1 < k ≤ 6n인 경우만 출력해야 한다.
	예를 들면, 3개의 주사위를 던졌을 때 눈들의 합이 5인 경우만 출력하면 [1, 1, 3], [1, 2, 2], [1, 3, 1], [2, 1, 2], [2, 2, 1], [3, 1, 1]이다.

	이 문제를 해결하는 되추적 알고리즘을 작성하라.
*/

#include <stdio.h>

#define N 3		// 굴릴 주사위의 갯수
#define K 5		// 주사위 눈들의 합

void diceRoll(int dice, int desiredSum, int currentSum, int A[], int k);

int main() {
	int A[N];
	diceRoll(N, K, 0, A, 0);

	return 0;
}

/* 입력: dice - 굴릴 주사위의 갯수
		 desiredSum - 구할 주사위 눈들의 합
		 currentSum - 현재까지 더한 주사위 눈들의 합
		 A[] - A[0..N-1] 크기가 N인 배열 A
		 diceOrder - (diceOrder+1)번째 주사위 (최초 호출: diceOrder = 0)
*/
void diceRoll(int dice, int desiredSum, int currentSum, int A[], int diceOrder) {
	if (dice == 0) {
		if (currentSum == desiredSum) {
			for (int i = 0; i < N; i++) {
				printf("%d ", A[i]);	// 해 출력
			}
			printf("\n");
		}
	}
	else if (currentSum + dice <= desiredSum && currentSum + 6 * dice >= desiredSum) {
		for (int i = 1; i <= 6; i++) {
			A[diceOrder] = i;
			diceRoll(dice - 1, desiredSum, currentSum + i, A, diceOrder + 1);
		}
	}
}
