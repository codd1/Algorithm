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