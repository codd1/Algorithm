// 문제 1-6. 길이가 N(> 0)인 올바른 문자열들의 수를 반복을 이용하여 구하는 θ(N) 알고리즘을 작성하라.

#include <stdio.h>
#define N 5				// N의 값은 여기서 수정

int main() {

	int A[N+1];

	A[1] = 2;
	A[2] = 3;

	for (int i = 3; i <= N; i++) {
		A[i] = A[i - 1] + A[i - 2];
	}

	printf("결과: %d\n", A[N]);

	return 0;
}