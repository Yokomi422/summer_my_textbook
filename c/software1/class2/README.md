## 学習したこと

### 1. 演算子

1. 算術演算子
   数学の基本要素の+などのことです. 特に割り算の/は切り捨てであることに注意する.

```c
printf("a / b = %d\n",  10 / 3); // 3
printf("%s\n", "%%"); // この挙動をするのはprintfだけらしい.
// 代入文をprintfに入れると中身が表示される. 代入式そのものも値を返す.
int a;
printf("%d\n", a = 1);
```

ちなみに、コード中に 1.0 などと書いたら double と解釈されるがこれをリテラルという. 明示的に float にするには 1.0f などとする.

2. 比較演算子
   <などが相当するが、整数型には使用してもいいが、float や double には原則として使用しない.

3. 代入演算子
   優先順位が同じ場合は右から実行される場合と左から実行される場合があるので注意する.

```c
int a = 3 + 2 - 1; // 左から実行： ((3 + 2) - 1)
printf("%d\n", a); // 4

int x, y, z;
x = y = z = 3;  // 右から実行：(x = (y = (z = 3)))
printf("%d %d %d\n", x, y, z);  // 3 3 3
```

優先順位や結合についてはhttps://ja.cppreference.com/w/c/language/operator_precedence
を参照する.左結合と右結合がある。

### 問題 1 BMI を計算するプログラム

体重 w kg で身長 h m の人の BMI は
\begin{equation}
BMI = \frac{w}{h^2}
\end{equation}

```c
double BMI(double weight, double height) {
	return weight / (height * height);
}

int main() {
	double weight = 50;
	double height = 1.5;

	double bmi =  BMI(weight, height);
	printf("my bmi is %f\n", bmi);
}
```

### 問題 2 閏年を判定するプログラム

This extra leap day occurs in each year that is a multiple of 4, except for years evenly divisible by 100 but not by 400.

```c
	int year = 1900;
	int is_leap = (year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0;

	printf("the year of %d is leqp year?: %d\n", year, is_leap);
```

## 2. 制御

### 2.1 式と文

式は値を返すが文は値を返さない. そのため、関数の返り値は式であるが、代入文は文である.
`;`が文の区切りである.

ブロックは複数の文のまとまりになっていてそれ自体が文である. そのため、ブロックの中にブロックを入れることができる.

### 2.2 if 文

```c
// c言語では0以外はtrueとして扱われる.
if (3) {
    printf("Here?\n");
} else {
    printf("or here?\n");
}
```

### 2.3 switch 文

```

```

### 2.4 while 文

```

```

### 2.5 for 文

```c
// Google c++ coding standardでは++iの方がいいとされている.
for (int i = 0; i < 10; ++i) {

}
```

### 2.6 goto

goto という label をつけて自由にジャンプできるが、goto はプログラムの可読性を下げるため、基本的には使わない方がいい.

```

```

### 問題

1 から 100 までの整数で 2 の冪乗になっているものをコンマ・スペースを挟み、最後に１回だけ改行するようにしましょう。

```c
int main() {
	int n = 1;

	while (n <= 100) {
		printf("%d, ", n);
		n *= 2;
	}

	printf("\n");
}

// 別解
#include <stdio.h>

int is_power_2(int x) {
	while (x % 2 == 0) {
		x /= 2;
	}

	return x == 1;
}

int main() {
	for (int i = 1; i <= 100; ++i) {
		if (is_power_2(i)) {
			printf("%d, ", i);
		}
	}
	printf("\n");
}


for (int n = 1; n < 100; n *= 2) {
    printf("%d, ", n);
}
printf("\n");
```

- for 文の更新条件は++i だけではなくて自由にできるのを忘れていた。

## 3. 配列

### 3.1 普通の配列

配列の宣言

```c
int nums[3];

nums[0] = 0;
nums[1] = 1;
nums[2] = 2;

for (int i = 0; i < 3; ++i) {
	printf("nums[%d] is %d\n", i, nums[i]);
}

// 配列の初期化はさまざまな方法がある.
int nums[3] = { 0, 1, 2};
int nums[] = { 0, 1, 2};
```

- 配列リテラルを利用すると、配列の要素数を省略できる.

配列の要素は連続してメモリ(主記憶)上に保存されている.

```c
int main() {
	int nums[] = { 0, 1, 2};

	for (int i = 0; i < 3; ++i) {
		printf("the address of nums[%d] is %p\n", i, &nums[i]);
	}
}
```

### 3.2 多次元配列

```c
int nums[][] = {
	{0, 1},
	{2, 3},
	{4, 5}
};

for (int i = 0; i < 3; ++i) {
	for (int j = 0; j < 2; ++j) {
		printf("the address of nums[%d][%d] is %p\t", i, j, &nums[i][j]);
	}
	printf("\n");
}

// 省略可能
int nums[][] = {
		{0, 1},
		{2, 3},
		{4, 5}
	};
```

- 多次元配列はメモリ上では同じ行のデータが連続されて保存される。
  配列は最初の方を初期化しておけば、後ろは 0 で埋められる。

```c
int nums[3][2] = {
	{0, 1},
};
```

配列外参照をすると、配列の最後の要素のアドレス以降のアドレスが無理やり読み込まれる

```c
float a[3] = {0.5, 0.3, 0.8};
printf("%f\n", a[3]);
```

## 4. 関数

いわゆるサブルーチン. コルーチンは非同期のことなので全く違うよ.

### 4.1 値渡し

関数の引数は値渡しといって、関数に渡された変数のコピーが関数内で使われる. そのため、関数内で変数の値を変えても、元の変数の値は変わらない.

### スコープ

ローカル変数とグローバル変数.
ローカル変数は関数などブロック内でのみ参照可能な変数. グローバル変数プログラム全体で参照できる変数.

ブロックを利用したスコープの制御

```c
{
	int a = 10;
	printf("a is %d", a);
}
{
	printf("a is %d", a); //  error: use of undeclared identifier 'a'
}
```

### 4.2 関数のプロトタイプ宣言

メイン関数でまだ宣言されていない関数を使うときは、シグネチャだけを宣言しておく必要がある.

```c
double BMI(double weight, double height);

int main() {
	double weight = 50;
	double height = 1.5;

	double bmi =  BMI(weight, height);
	printf("my bmi is %f\n", bmi);
}

double BMI(double weight, double height) {
	return weight / (height * height);
}
```

### 問題

C 言語で累乗を計算する関数を作成せよ.

```c
int power(int, int);

int main() {
	int powerd_num = power(3, 4);
	printf("m is %d\n", powerd_num);
}

int power(int x, int y) {
	int ans = 1;
	while (y > 0) {
		ans *= x;
		y--;
	}
	return ans;
}
```

# 課題 1.

## \b

バックスペースは前の文字を削除する.

```c
int main() {
	printf("hello\b a\n");
}
```

## 解答
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int sum = atoi(argv[1]);

	int coins[] = {100, 50, 10, 5, 1};
	int how_many_divide[sizeof(coins) / sizeof(int)] = {0};
	int max_divide = 0;

	for (int i = 0; i < 5; ++i) {
		int coin = coins[i];
		how_many_divide[i] = sum / coin;
		sum = sum % coin;

		if (how_many_divide[i] > max_divide) {
			max_divide = how_many_divide[i];
		}
	}

	for (int i = 0; i < 5; ++i) {
		int coin = coins[i];
		int divided_time = how_many_divide[i];
		for (int j = 0; j < max_divide - divided_time; ++j) {
			printf(" ");
		}
		for (int j = 0; j < divided_time; ++j) {
			printf("*");
		}
		printf(": ");
		if (coin == 50 || coin == 10) {
			printf(" ");
		} else if (coin == 5 || coin == 1) {
			printf("  ");
		}
		printf("%d yen\n", coin);
	}
}
```

### エラー処理

- https://jp-seemore.com/iot/10967/
	- 今回のsegmentation faultはargvでcommand line 引数を与えていなかったために発生した.
- デバックの基本
	- https://inno-tech-life.com/dev/cpp/cpp_debug_vscode/#index_id2
