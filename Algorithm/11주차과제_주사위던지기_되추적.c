/*
	���� 1: �ֻ��� ������
	
	n(> 1)���� �ֻ����� ������ �� ������ ���� k, 1 < k �� 6n�� ��츸 ����ؾ� �Ѵ�.
	���� ���, 3���� �ֻ����� ������ �� ������ ���� 5�� ��츸 ����ϸ� [1, 1, 3], [1, 2, 2], [1, 3, 1], [2, 1, 2], [2, 2, 1], [3, 1, 1]�̴�.

	�� ������ �ذ��ϴ� ������ �˰����� �ۼ��϶�.
*/

#include <stdio.h>

#define N 3		// ���� �ֻ����� ����
#define K 5		// �ֻ��� ������ ��

void diceRoll(int dice, int desiredSum, int currentSum, int A[], int k);

int main() {
	int A[N];
	diceRoll(N, K, 0, A, 0);

	return 0;
}

/* �Է�: dice - ���� �ֻ����� ����
		 desiredSum - ���� �ֻ��� ������ ��
		 currentSum - ������� ���� �ֻ��� ������ ��
		 A[] - A[0..N-1] ũ�Ⱑ N�� �迭 A
		 diceOrder - (diceOrder+1)��° �ֻ��� (���� ȣ��: diceOrder = 0)
*/
void diceRoll(int dice, int desiredSum, int currentSum, int A[], int diceOrder) {
	if (dice == 0) {
		if (currentSum == desiredSum) {
			for (int i = 0; i < N; i++) {
				printf("%d ", A[i]);	// �� ���
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
