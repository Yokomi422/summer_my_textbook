#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_array(int height, int width, char array[][width]);
int count_options(int);

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Usage: ./a.out [string] int");
		return 1;
	}

	char *str = argv[1];
	int n = atoi(argv[2]);

	// 与えられたnと文字列から最初のwidthとheightを決める
	int width = n;
	int height = strlen(str) / width;

	// widthとheightから二次元配列を作成
	char string_array[height][width];
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			string_array[i][j] = str[i * width + j];
		}
	}

	int option_count = count_options(argc);



	print_array(height, width, string_array);
}

void print_array(int height, int width, char array[][width]) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			printf("%c", array[i][j]);
		}
		printf("\n");
	}
}

int count_options(int argc) {
	return argc - 2;
}
