// 문제 3. 등수 매기기

#include <stdio.h>
#define N 5

int main() {

	// 시험 점수들은 크기가 N인 Score라는 배열에 저장되어 있다.
	int Score[N] = { 82, 75, 98, 63, 40 };
	// 각 점수의 등수는 크기가 N인 Rank라는 배열에 저장해야 한다.
	int Rank[N] = { 0, 0, 0, 0, 0 };


	for (int i = 0; i < N; i++) {
		Rank[i] = 1;					// 반복문을 돌 때마다 Rank[i]의 값을 1(위)로 저장한다.
		for (int j = 0; j < N; j++) {	// Score[i]와 Score[0~4]를 비교한다.
			if (Score[i] < Score[j]) {	// Score[i]보다 큰 값이 있다면 순위가 낮아진다.
				Rank[i]++;
			}
		}
	}
	
	// 결과 출력
	for (int i = 0; i < N; i++) {
		printf("%d점: %d등\n", Score[i], Rank[i]);
	}
	
	return 0;
}