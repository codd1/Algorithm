/*
	���� 3: ��ġ���� ���� ���ϱ�

	A[1..N]�� N(> 0)���� ���� �ٸ� �������� �迭�̴�. i < j�̰� A[i] > A[j]�̸� �� �� (A[i], A[j])�� ��ġ��� �θ���.

	�迭 A ���� �ִ� ��ġ���� ���� ���ϴ� ���� ���� �˰����� �ۼ��϶�.
	�˰����� �־��� �ð����⵵�� O(N log N)�̾�� �Ѵ�.
	�迭 ���� �ִ� �������� ������ �ٲ� �� �ִ�. (��Ʈ: �պ� ������ �̿��϶�)
*/

#include <stdio.h>

#define N 8

int merge(int A[], int i, int mid, int j);
int findInversion(int A[], int i, int j) {
	int count = 0;
	if (i < j) {
		int mid = (i + j) / 2;
		count += findInversion(A, i, mid);		// ���� ���� ��ġ ���� ã��
		count += findInversion(A, mid + 1, j);	// ������ ���� ��ġ ���� ã��
		count += merge(A, i, mid, j);			// �պ� merge �޼ҵ� ȣ��
	}
	return count;
}

int main() {

	// ���� 2���� �迭 A ���ҵ��� �����߽��ϴ�.
	// N�� 8�� ���
	int A[N] = { 82,35,27,96,73,14,58,49 };

	printf("%d\n", findInversion(A, 0, N - 1));
	return 0;
}

int merge(int A[], int low, int mid, int high) {
	int B[N] = { 0, };	// �ӽ� �迭

	int Bindex = low;	// ���� ����� ������ ��ġ(�ε���)
	int i = low;
	int j = mid + 1;

	int count = 0;

	while (i <= mid && j <= high) {
		if (A[i] <= A[j]) {
			B[Bindex] = A[i];
			i++;
		}
		else {	// A[i] > A[j]�̸� count�� ����.
			count += mid -i + 1;
			B[Bindex] = A[j];
			j++;
		}
		Bindex++;
	}
	if (i > mid) {		// �� �迭�� ���� �迭�� ���� ����, �� �迭�� ���� �迭�� ���� ���� ���
		for (int k = j; k <= high; k++) {
			B[Bindex] = A[k];
			Bindex++;
		}
	}
	else {		// �� �迭�� ���� �迭�� ���� ����, �� �迭�� ���� �迭�� ���� ���� ���
		for (int k = i; k <= mid; k++) {
			B[Bindex] = A[k];
			Bindex++;
		}
	}

	for (int k = low; k <= high; k++) {		// �״�� A �迭�� ����
		A[k] = B[k];
	}
	return count;
}