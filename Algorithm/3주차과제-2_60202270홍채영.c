#include <stdio.h>

int countNumber(int num, int index, int count) {		// num: �Է��� ����, index: 0~9�� ����, count: �Էµ� index(����)�� ����(���)
	if (num == 0) {
		return count;
	}
	else{
		if (num % 10 == index){
			count++;
		}
		return countNumber(num / 10, index, count);
	}
}

int main() {
	int count[10] = { 0, };

	int input;
	scanf_s("%d", &input);
	
	for (int i = 0; i < 10; i++) {
		printf("%d�� ����: %d\n", i, countNumber(input, i,0));
	}

	return 0;
}