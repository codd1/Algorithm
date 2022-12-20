/*
	문제 3: 도치들의 갯수 구하기
	
	A[1..N]은 N(> 0)개의 서로 다른 정수들의 배열이다. i < j이고 A[i] > A[j]이면 한 쌍 (A[i], A[j])는 도치라고 부른다.

	배열 A 내에 있는 도치들의 수를 억지기법을 사용하여 구하는 알고리즘을 작성하라.
*/

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