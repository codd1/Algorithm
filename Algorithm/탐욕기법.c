#include <stdio.h>
#define N 6

void work(int s[], int f[]) {
	int m[N] = {0,0,0,0,0,0};
	int worker = 1;
	m[worker] = f[worker];		// m[1] = f[1]

	for (int i = 2; i <= N; i++) {
		if (s[i] == s[i - 1]) {
			worker++;
			m[worker] = f[worker];
		}
		else {
			for (int j = 1; j < i; j++) {
				if (f[j] > s[i]) {
					worker++;
					m[worker] = f[i];
					break;
				}
				else {
					m[j] = f[i];
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", m[i]);
	}
}

int main() {
	int s[N] = { 0,1,1,2,3,4 };
	int f[N] = { 0,2,4,6,4,5 };

	work(s, f);
}