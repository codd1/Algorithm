#include <stdio.h>

int findMin(int A[], int i, int j) {

	int mid, min1, min2 = 1;

	if (i == j) return A[i];
	else if (i == (j - 1)) {
		if (A[i] < A[j]) return A[i];
		else {
			return A[j];
		}
	}
	else {
		mid = (i + j) / 2;
		min1 = findMin(A, i, mid);
		min2 = findMin(A, mid + 1, j);
		if (min1 < min2) return min1;
		else {
			return min2;
		}
	}
}

int main() {

	// N�� ���� �����̰� i�� j�� 1 ��  i �� j �� N�� ������Ű�� �������̴�. �迭 A[i . . j]���� ���� ������ �̿��Ͽ� �ּڰ��� ã�� ��� �˰����� �ۼ��϶�.

	// N�� 10�� ���
	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };

	printf("%d\n", findMin(A, 1, 10-1));

	return 0;
}