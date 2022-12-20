#include <stdio.h>
#define MAX_PROTO 1024

//char myarray[MAX_PROTO];

/*char func(int proto) {
	if (proto >= MAX_PROTO)
		//return "ERROR";
		return 2;
	return myarray[proto];
	//return "ERROR";
}*/
int main() {
	char myarray[MAX_PROTO];
	myarray[0] = "ERROR";
	printf("Ãâ·Â: %c", myarray[0]);
	//putchar("%s", func(1025));
}