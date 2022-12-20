/*
	문제 2: 중복 숫자 제거

	N 개의 숫자들의 배열이 있다. 이 배열 안에 있는 숫자들 중 일부는 값들이 서로 같다.
	다시 말해, 어떤 숫자는 배열 안에 두 번 이상 저장되어 있다.
	배열 안에 있는 중복된 숫자들을 모두 제거하는 알고리즘을 작성하라.
	그 알고리즘의 시간복잡도는 O(n log n)이어야 한다(힌트: 분할 정복을 사용하는 시간복잡도가 O(n log n)인 정렬 알고리즘을 이용하라.)
*/

#include <stdio.h>
#define n 8

void mergeSort(int A[], int low, int high);
void merge(int A[], int low, int mid, int high);

int main() {
	int A[n] = { 1,2,2,3,3,4,5,7 };	// -> 1 2 3 4 5 7
	int B[n] = { 0,0,0,0,0,0,0,0 };
	B[0] = A[0];
	for (int i = 1, j=1; i < n; i++) {
		if (A[i] != B[j - 1]) {
			B[j] = A[i];
			j++;
		}
	}

	for (int i = 0; i < n; i++) {
		A[i] = B[i];
		printf("%d ", A[i]);
	}
	//mergeSort(A, 0, n - 1);

	return 0;
}

void mergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(A, low, mid);
		mergeSort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}

void merge(int A[], int low, int mid, int high) {
	int B[] = {0,};
	int h = low;
	int i = low;
	int j = mid + 1;

	while (i <= mid && j <= high) {
		if (A[i] <= A[j]) {
			B[h] = A[i];
			i++;
		}
		else {
			B[h] = A[j];
			j++;
		}
		h++;
	}
	if (i > mid) {
		for (int k = j; k <= high; k++) {
			B[h] = A[k];
			h++;
		}
	}
	else {
		for (int k = i; k <= mid; k++) {
			B[h] = A[k];
			h++;
		}
	}
	for (int k = low; k <= high; k++) {
		A[k] = B[k];
	}
}