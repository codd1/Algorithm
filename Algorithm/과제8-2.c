#include <stdio.h>
#define N 3

void quickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

int main() {
	int t[N] = { 2,4,3 };
	
	// 정렬 t를 오름차순으로 정렬한다.
	quickSort(t, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d ", t[i]);
	}
	

}

void quickSort(int A[], int low, int high) {
	if (low < high) {		// 요소가 1개일 경우 정렬 안 함.
		int s = partition(A, low, high);	// s = 기준요소의 위치
		quickSort(A, low, s - 1);			// 왼쪽 부분 빠른 정렬
		quickSort(A, s + 1, high);			// 오른쪽 부분 빠른 정렬
	}
}

int partition(int A[], int low, int high) {		// 최초: low = 0, high = 7
	int i = low + 1;		// 기준요소 다음부터 시작
	int j = high;
	int temp;				// 배열 내 요소를 바꾸기 위한 임시 변수

	while (i <= j) {		// i > j가 되면 반복문 종료
		if (A[i] <= A[low]) {		// 맨 앞의 요소가 기준요소(A[low])보다 같거나 작으면 자기 자리.
			i++;			// 다음 인덱스로 넘어간다.
		}
		else if (A[j] > A[low]) {	// 맨 뒤의 요소가 기준요소보다 크면 자기 자리.
			j--;			// 앞 인덱스로 넘어간다.
		}
		else {
			// 자기 자리가 아니므로 자리 바꾸기 A[i] <-> A[j]
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;

			i++;		// 다음 인덱스로 넘어간다.
			j--;		// 앞 인덱스로 넘어간다.
		}
	}
	// A[low] <-> A[j]
	temp = A[low];
	A[low] = A[j];
	A[j] = temp;

	// 기준 요소 A[low]와 A[j]를 바꿨으므로, 기준 요소의 최종 위치는 j가 된다. 따라서 j 리턴
	return j;
}