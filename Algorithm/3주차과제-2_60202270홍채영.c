#include <stdio.h>

int countNumber(int num, int index, int count) {		// num: 입력한 숫자, index: 0~9의 숫자, count: 입력된 index(숫자)의 갯수(결과)
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
		printf("%d의 갯수: %d\n", i, countNumber(input, i,0));
	}

	return 0;
}