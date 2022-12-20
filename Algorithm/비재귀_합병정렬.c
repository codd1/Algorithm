#include <stdio.h>

#define N 8

void merge(int A[], int low, int mid, int high);
void mergeSort2(int A[], int n);

int main() {
	int A[N] = { 91,82,13,85,68,70,98,24 };

	mergeSort2(A, N);

	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
}

// ���ĵ� �κ� �迭 A[low...mid]�� A[mid+1...high]�� �պ��Ѵ�.
void merge(int A[], int low, int mid, int high) {
	int B[N] = { 0, };	// ũ�Ⱑ high+1�� �迭 B�� �����. ������ �� �迭 B
	int B_index = low;
	int left_i = low, right_i = mid + 1;		// left_i: ���� ���� ���� ���� ��, right_i: ������ ���� ���� ���� ��

	while (left_i <= mid && right_i <= high) {		// ����, ������ �� �� �� ������ ��ҿ� �� ������ �ݺ�
		if (A[left_i] <= A[right_i]) {			// ������ ��Ұ� �� �۰ų� ���ٸ�
			B[B_index] = A[left_i];				// �迭 B�� ������ ��� �� ����
			left_i++;							// ������ ��Ҵ� ����Ǿ����Ƿ� ���� ��ҷ� �Ѿ��. i++
		}
		else {							// �������� ��Ұ� �� �۴ٸ�
			B[B_index] = A[right_i];	//�迭 B�� �������� ��� �� ����
			right_i++;					// �������� ��Ҵ� ����Ǿ����Ƿ� ���� ��ҷ� �Ѿ��. i++
		}
		B_index++;		// A[left_i] Ȥ�� A[right_i]�� B[B_index]�� �̹� ��������Ƿ� B�迭�� ���� ��ҷ� �Ѿ��. i++
	}

	// �̹� ����, �������� ������ �Ǿ��ִ� �����̹Ƿ� B�� �״�� �����Ѵ�.
	if (left_i > mid) {			// ���ʿ� ���� �迭�� ���� ����, �����ʿ��� ���� ���
		for (int k = right_i; k <= high; k++, B_index++) {		// right_i�� high���� �ݺ�
			B[B_index] = A[k];		// B[B_index]�� A[right_i] �� ����
		}
	}
	else {						// �����ʿ� ���� �迭�� ���� ����, ���ʿ��� ���� ���
		for (int k = left_i; k <= mid; k++, B_index++) {		// left_i�� mid���� �ݺ�
			B[B_index] = A[k];		// B[B_index]�� A[left_i] �� ����
		}
	}
	for (int k = low; k <= high; k++) {		// �迭 A�� ���ĵ� �迭 B ���� �״�� ����
		A[k] = B[k];
	}
}

void mergeSort2(int A[], int n) {		// n = 7
	int size = 1;

	while (size < n) {
		for (int i = 0; i < n; i = i + 2 * size) {
			merge(A, i, i + size - 1, i + 2 * size - 1);
		}
		size = size * 2;
	}
}