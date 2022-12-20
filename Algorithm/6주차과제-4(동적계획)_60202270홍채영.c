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
