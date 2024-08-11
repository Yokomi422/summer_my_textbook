#include <stdio.h>

int atoi(char c) {
	int gap = 1 - '1';
	return c + gap;	
}

int main(int argc, char **argv) {
	printf("%d\n", atoi('1'));
	printf("%d\n", atoi('1')  + atoi('1'));
}
