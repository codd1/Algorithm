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
