#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s) {
	int count = 0;
	while (s[count] != '\0') {
		++count;
	}
	return count;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("the input is ./main <row size> <column size> and both size is 1 - 9");
		return 1;
	}

	int row_size = atoi(argv[1]);
	int column_size = atoi(argv[2]);

	
}
