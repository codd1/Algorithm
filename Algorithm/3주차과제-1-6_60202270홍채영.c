// ���� 1-6. ���̰� N(> 0)�� �ùٸ� ���ڿ����� ���� �ݺ��� �̿��Ͽ� ���ϴ� ��(N) �˰����� �ۼ��϶�.

#include <stdio.h>
#define N 5				// N�� ���� ���⼭ ����

int main() {

	int A[N+1];

	A[1] = 2;
	A[2] = 3;

	for (int i = 3; i <= N; i++) {
		A[i] = A[i - 1] + A[i - 2];
	}

	printf("���: %d\n", A[N]);

	return 0;
}