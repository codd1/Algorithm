#include <stdio.h>

#define N 9

int findInversion(int A[]) {
	int count = 0;
	for (int i = 1; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i] > A[j]) {
				count++;
			}
		}
	}
	return count;
}

int main() {

	// 문제 2번의 배열 A 원소들을 저장했습니다.
	// N이 8인 경우
	int A[N] = { 0,82, 35,27,96,73,14,58,49};
	
	printf("%d\n", findInversion(A));

	return 0;
}