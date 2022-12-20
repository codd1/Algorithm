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

// 정렬된 부분 배열 A[low...mid]와 A[mid+1...high]를 합병한다.
void merge(int A[], int low, int mid, int high) {
	int B[N] = { 0, };	// 크기가 high+1인 배열 B를 만든다. 정렬을 할 배열 B
	int B_index = low;
	int left_i = low, right_i = mid + 1;		// left_i: 왼쪽 반의 가장 왼쪽 값, right_i: 오른쪽 반의 가장 왼쪽 값

	while (left_i <= mid && right_i <= high) {		// 왼쪽, 오른쪽 반 둘 다 마지막 요소에 갈 때까지 반복
		if (A[left_i] <= A[right_i]) {			// 왼쪽의 요소가 더 작거나 같다면
			B[B_index] = A[left_i];				// 배열 B에 왼쪽의 요소 값 저장
			left_i++;							// 왼쪽의 요소는 저장되었으므로 다음 요소로 넘어간다. i++
		}
		else {							// 오른쪽의 요소가 더 작다면
			B[B_index] = A[right_i];	//배열 B에 오른쪽의 요소 값 저장
			right_i++;					// 오른쪽의 요소는 저장되었으므로 다음 요소로 넘어간다. i++
		}
		B_index++;		// A[left_i] 혹은 A[right_i]가 B[B_index]에 이미 저장됐으므로 B배열도 다음 요소로 넘어간다. i++
	}

	// 이미 왼쪽, 오른쪽은 정렬이 되어있는 상태이므로 B에 그대로 저장한다.
	if (left_i > mid) {			// 왼쪽에 비교할 배열의 값이 없고, 오른쪽에만 남은 경우
		for (int k = right_i; k <= high; k++, B_index++) {		// right_i를 high까지 반복
			B[B_index] = A[k];		// B[B_index]에 A[right_i] 값 저장
		}
	}
	else {						// 오른쪽에 비교할 배열의 값이 없고, 왼쪽에만 남은 경우
		for (int k = left_i; k <= mid; k++, B_index++) {		// left_i를 mid까지 반복
			B[B_index] = A[k];		// B[B_index]에 A[left_i] 값 저장
		}
	}
	for (int k = low; k <= high; k++) {		// 배열 A에 정렬된 배열 B 값을 그대로 복사
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