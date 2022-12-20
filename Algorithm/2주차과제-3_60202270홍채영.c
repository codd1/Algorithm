// ���� 3. ��� �ű��

#include <stdio.h>
#define N 5

int main() {

	// ���� �������� ũ�Ⱑ N�� Score��� �迭�� ����Ǿ� �ִ�.
	int Score[N] = { 82, 75, 98, 63, 40 };
	// �� ������ ����� ũ�Ⱑ N�� Rank��� �迭�� �����ؾ� �Ѵ�.
	int Rank[N] = { 0, 0, 0, 0, 0 };


	for (int i = 0; i < N; i++) {
		Rank[i] = 1;					// �ݺ����� �� ������ Rank[i]�� ���� 1(��)�� �����Ѵ�.
		for (int j = 0; j < N; j++) {	// Score[i]�� Score[0~4]�� ���Ѵ�.
			if (Score[i] < Score[j]) {	// Score[i]���� ū ���� �ִٸ� ������ ��������.
				Rank[i]++;
			}
		}
	}
	
	// ��� ���
	for (int i = 0; i < N; i++) {
		printf("%d��: %d��\n", Score[i], Rank[i]);
	}
	
	return 0;
}