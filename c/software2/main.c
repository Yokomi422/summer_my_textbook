#include <stdio.h>
#include <unistd.h> // sleepのためにinclude 

int main (int argc, char **argv){
	printf("-: 左寄せ\n"); // デフォルトでは右寄せになっている
	printf("%-10d\n", 12441);
	printf("%10d\n", 12441);

	printf("-----+: 符号出力 -----\n");
	printf("%+d\n", 10);
	printf("%+d\n", -10);

	printf("----- : +は空白出力 -----\n");
	printf("% d\n", 10);
	printf("% d\n", -10);

	printf("----- #: 基数表示 -----\n");
	printf("%#x\n", 10); // 16進数表記
	printf("%#o\n", 10);  // 8進数表記
	printf("浮動小数点数: %#f\n", 10.0);  // 小数点を必ず表示
    printf("指数表記: %#e\n", 10.0);       // 小数点を必ず表示
    printf("一般形式: %#g\n", 10.0);       // 末尾のゼロを省略しない

	
}
