// 문제 1-5. 4번의 점화식을 이용하여 길이가 N(> 0)인 올바른 문자열들의 수를 구하는 재귀 알고리즘을 작성하라.


#include <stdio.h>

F(int N) {
	if (N == 1) return 2;
	else if (N == 2) return 3;
	else {
		return F(N - 1) + F(N - 2);
	}
}

int main() {
	int N;
	scanf_s("%d", &N);
	
	printf("결과: %d\n", F(N));

	return 0;
}