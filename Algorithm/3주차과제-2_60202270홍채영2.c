#include <stdio.h>

int main() {
	int count[10] = {0,};
	
	int input;
	scanf_s("%d", &input);

	while (input != 0) {
		count[input % 10]++;
		input = input / 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%dÀÇ °¹¼ö: %d\n", i, count[i]);
	}

	return 0;
}