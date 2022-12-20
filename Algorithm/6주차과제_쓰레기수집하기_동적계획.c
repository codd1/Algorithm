/*
	문제 1: 쓰레기 수집하기

	쓰레기들이 m행과 n열을 가진 보드(board)의 칸들(cells)에 있다.
	칸들에 있는 쓰레기들의 무게는 배열 W에 저장된다.
	즉, i, 1≤i≤m, 번째 행의 j, 1≤j≤n, 번째 열에 있는 쓰레기의 무게는 W[i, j]이다.
	로봇은 처음에 보드의 왼쪽 상단 칸(1행 1열)에 있다. 
	로봇은 보드의 칸들에 있는 쓰레기들을 가능한 많이 모아서 보드의 오른쪽 하단 칸(m행 n열)으로 가지고 가야 한다.
	로봇은 한 번에 현재 위치에서 오른쪽으로 한 칸 혹은 아래 쪽으로 한 칸 이동할 수 있다.
	로봇이 쓰레기가 있는 칸을 방문할 때는 항상 그 칸에 있는 쓰레기를 수집해야 한다.
	로봇이 수집할 수 있는 최대 쓰레기의 무게를 구하려고 한다.

	로봇이 수집할 수 있는 최대 쓰레기의 무게 F(i, j), 0 ≤ i ≤m, 0 ≤ j ≤n, 를 구하는 동적 계획 알고리즘을 작성하라.
*/

#include <stdio.h>

#define m 3
#define n 4

int MAX(int num1, int num2);

int calc(int p[][n], int i, int j) {
	int maxWeight[m+1][n+1];
	int maxVal = 0;
	int k, l;
	
	for (k = 0; k <= m; k++) {
		maxWeight[k][0] = 0;
		//printf("%d. maxSell[%d][0]=%d\n", i, i, maxSell[i][0]);
	}
	for (l = 1; l <= n; l++) {
		maxWeight[0][l] = 0;
		//printf("%d. maxSell[0][%d]=%d\n", j, j, maxSell[0][j]);
	}

	for (k = 1; k <= m; k++) {
		for (l = 1; l <= n; l++) {
			maxWeight[k][l] = MAX(maxWeight[k - 1][l], maxWeight[k][l - 1]) + p[k-1][l-1];
		}
	}
	return maxWeight[i][j];
}

int MAX(int num1, int num2) {
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}

int main() {
	
	int p[m][n] = { {6,0,2,4},{5,3,0,5},{4,0,3,2} };

	printf("%d\n", calc(p, m, n));
}
