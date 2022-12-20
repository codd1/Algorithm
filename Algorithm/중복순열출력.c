#include <stdio.h>
#define N 4
#define K 2

void func(int n, int k, int first) {
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			printf("<%d,%d>", first, i);
		}
		printf("\n");
	}
	else {
		for (int i = 1; i <= n; i++) {
			func(n, k - 1, i);
		}
	}
}
int main() {
	func(N, K, N);
}