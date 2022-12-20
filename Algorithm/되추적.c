#include <stdio.h>
#define N 4

void coin(int m, int n, int d[], int c) {
	if (n == 0) {
		printf("%d\n", c);
	}
	else {
		for (int i = 1; i <= m; i++) {
			if (n >= d[i]) {
				printf("coin(%d, %d, d, %d)\n", m, n-d[i], c+1);
				coin(m, n - d[i], d, c + 1);
			}
		}
	}
}
int main() {
	int d[N + 1] = { 0,50,10,5,1 };
	coin(N, 16, d, 0);
}