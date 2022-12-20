/*
	문제 3: 작업 순서 정하기
	
	m(> 1) 명의 작업자들이 수행할 n(> 1)개의 작업들이 있다.
	i, 1 ≤ i ≤ n, 번째 작업의 수행 시간은 t_i이다. 이 작업들은 어떤 순서로도 수행될 수 있다.
	그러나 각 작업자는 한번에 한 개의 작업만을 수행할 수 있다.
	모든작업들이 시스템에서 보내는 총 시간이 최소가 되는 순서를 찾아야 한다.
	한 작업이 시스템에서 보내는 시간은 시스템에서 기다리는시간과 수행 시간의 합이다.
	
	이 문제를 위한 탐욕적인 알고리즘을 작성하라.
*/

#include <stdio.h>

#define m 2		// m명의 작업자
#define n 3		// n개의 수행할 작업

void quickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

int main() {
	int work_time[n] = { 3,5,4 };		// n개의 작업 수행 시간 배열
	
	quickSort(work_time, 0, n - 1);		// work_time 배열을 오름차순으로 정렬한다.

	for(int i = 0; i < n;) {
		for (int j = 1; j <= m; j++) {
			if (i < n) {
				printf("m%d: %d시간 작업 선택\n", j, work_time[i]);
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