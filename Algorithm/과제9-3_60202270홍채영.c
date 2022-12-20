#include <stdio.h>

#define m 2		// m���� �۾���
#define n 3		// n���� ������ �۾�

void quickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

int main() {
	int work_time[n] = { 3,5,4 };		// n���� �۾� ���� �ð� �迭
	
	quickSort(work_time, 0, n - 1);		// work_time �迭�� ������������ �����Ѵ�.

	for(int i = 0; i < n;) {
		for (int j = 1; j <= m; j++) {
			if (i < n) {
				printf("m%d: %d�ð� �۾� ����\n", j, work_time[i]);
				i++;
			}
			else {
				break;
			}
		}
	}

	return 0;
}


void quickSort(int A[], int low, int high) {
	if (low < high) {		// ��Ұ� 1���� ��� ���� �� ��.
		int s = partition(A, low, high);	// s = ���ؿ���� ��ġ
		quickSort(A, low, s - 1);			// ���� �κ� ���� ����
		quickSort(A, s + 1, high);			// ������ �κ� ���� ����
	}
}

int partition(int A[], int low, int high) {		// ����: low = 0, high = 7
	int i = low + 1;		// ���ؿ�� �������� ����
	int j = high;
	int temp;				// �迭 �� ��Ҹ� �ٲٱ� ���� �ӽ� ����

	while (i <= j) {		// i > j�� �Ǹ� �ݺ��� ����
		if (A[i] <= A[low]) {		// �� ���� ��Ұ� ���ؿ��(A[low])���� ���ų� ������ �ڱ� �ڸ�.
			i++;			// ���� �ε����� �Ѿ��.
		}
		else if (A[j] > A[low]) {	// �� ���� ��Ұ� ���ؿ�Һ��� ũ�� �ڱ� �ڸ�.
			j--;			// �� �ε����� �Ѿ��.
		}
		else {
			// �ڱ� �ڸ��� �ƴϹǷ� �ڸ� �ٲٱ� A[i] <-> A[j]
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;

			i++;		// ���� �ε����� �Ѿ��.
			j--;		// �� �ε����� �Ѿ��.
		}
	}
	// A[low] <-> A[j]
	temp = A[low];
	A[low] = A[j];
	A[j] = temp;

	// ���� ��� A[low]�� A[j]�� �ٲ����Ƿ�, ���� ����� ���� ��ġ�� j�� �ȴ�. ���� j ����
	return j;
}