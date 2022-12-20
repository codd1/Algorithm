#include <stdio.h>

#define N 8

int merge(int A[], int i, int mid, int j);
int findInversion(int A[], int i, int j) {
	int count = 0;
	if (i < j) {
		int mid = (i + j) / 2;
		count += findInversion(A, i, mid);		// 왼쪽 반의 도치 개수 찾기
		count += findInversion(A, mid + 1, j);	// 오른쪽 반의 도치 개수 찾기
		count += merge(A, i, mid, j);			// 합병 merge 메소드 호출
	}
	return count;
}

int main() {

	// 문제 2번의 배열 A 원소들을 저장했습니다.
	// N이 8인 경우
	int A[N] = { 82,35,27,96,73,14,58,49 };

	printf("%d\n", findInversion(A, 0, N - 1));
	return 0;
}

int merge(int A[], int low, int mid, int high) {
	int B[N] = { 0, };	// 임시 배열

	int Bindex = low;	// 비교한 결과를 저장할 위치(인덱스)
	int i = low;
	int j = mid + 1;

	int count = 0;

	while (i <= mid && j <= high) {
		if (A[i] <= A[j]) {
			B[Bindex] = A[i];
			i++;
		}
		else {	// A[i] > A[j]이면 count를 센다.
			count += mid -i + 1;
			B[Bindex] = A[j];
			j++;
		}
		Bindex++;
	}
	if (i > mid) {		// 앞 배열에 비교할 배열의 값이 없고, 뒷 배열에 비교할 배열의 값이 남은 경우
		for (int k = j; k <= high; k++) {
			B[Bindex] = A[k];
			Bindex++;
		}
	}
	else {		// 뒷 배열에 비교할 배열의 값이 없고, 앞 배열에 비교할 배열의 값이 남은 경우
		for (int k = i; k <= mid; k++) {
			B[Bindex] = A[k];
			Bindex++;
		}
	}

	for (int k = low; k <= high; k++) {		// 그대로 A 배열에 복사
		A[k] = B[k];
	}
	return count;
}