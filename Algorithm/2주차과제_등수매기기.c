/*
	문제 3: 등수 매기기
	
	시험 점수들을 값이 큰 순서대로 등수를 매기려고 한다.
	예를 들면, 5명의 시험 점수가 82, 75, 98, 63, 40이라면 각 점수의 등수는 2,3,1,4,5등이 된다.
	시험 점수들의 갯수는 N(>0)이다. 시험 점수들은 크기가 N인 Score라는 배열에 저장되어 있다.
	각 점수의 등수는 크기가 N인 Rank라는 배열에 저장해야 한다.
	등수를 매기는 알고리즘을 작성하라.
	정렬을 사용하지 말아라.
	작성한 알고리즘의 시간복잡도를 세타(Theta)-표기로 나타내라.
*/

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