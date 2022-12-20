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

	// N은 양의 정수이고 i와 j는 1 ≤  i ≤ j ≤ N를 만족시키는 정수들이다. 배열 A[i . . j]에서 분할 정복을 이용하여 최솟값을 찾는 재귀 알고리즘을 작성하라.

	// N이 10인 경우
	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };

	printf("%d\n", findMin(A, 1, 10-1));

	return 0;
}