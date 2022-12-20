/*
	���� 3: ��ġ���� ���� ���ϱ�
	
	A[1..N]�� N(> 0)���� ���� �ٸ� �������� �迭�̴�. i < j�̰� A[i] > A[j]�̸� �� �� (A[i], A[j])�� ��ġ��� �θ���.

	�迭 A ���� �ִ� ��ġ���� ���� ��������� ����Ͽ� ���ϴ� �˰����� �ۼ��϶�.
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

	// ���� 2���� �迭 A ���ҵ��� �����߽��ϴ�.
	// N�� 8�� ���
	int A[N] = { 0,82, 35,27,96,73,14,58,49};
	
	printf("%d\n", findInversion(A));

	return 0;
}