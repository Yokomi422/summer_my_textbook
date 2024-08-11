## 1. 文字と文字列

C 言語において char 型の文字といわゆる string は別物で char は１文字だけを表す. 'a'は文字で、"a"は文字列になる. char は実際には 1byte の int 型であるが、0 ~ 127 で表現される文字のことを ASCII という.

文字列は char 型の配列になっていて、その配列の最後の要素は'\0'という NULL 文字で終わる。char 型で NULL 文字は 0 で表現される. 配列の要素数を明示的に指定するとバグの温床になるので、コンパイラに任せるのが無難である.

```c
char s[] = "hello"; // "hello\0"と同じ
char s[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; // "hello\0"と同じ

char s[8] = { 'h', 'e', 'l', 'l', 'o' }; // "hello"と同じで残りはすべてNULL文字で埋められる. これは配列の初期化されていない要素がNULL文字で埋められるためである. intの配列なら0で埋められる.
```

## 2. 配列と文字列

配列と文字列は基本的には同じような考え方で理解することができる. 配列変数は配列の先頭アドレスを返すので、以下にリテラルによる代入は初期化時しかできない.

```c
char s[] = "hello"; // OK
s = "world"; // NG

char s[] = "hello";
char t[] = "hello";

if (s == t) // これは常にfalse
```

これは、配列変数がポインタである一方で、"hello"というリテラルはメモリ上のどこかに存在するデータそのものであるからである。
また、配列の要素数を数えるときは sizeof を使うが最後に NULL 文字があるので、文字列の長さは strlen 関数を使う.

````c
char s[] = "hello";
printf("%d\n", sizeof(s)); // 6
printf("%d\n", strlen(s)); // 5

printf("%lu\n", sizeof(test)); // intの配列は最後のNULL文字とかないね.

### 2.1 配列と引数
文字列以外の配列を関数の引数雨として渡すときは、配列の要素数も引数として渡す必要がある. これは配列変数がポインタであるためである.

### 2.2 文字列に関する関数

1. 文字列の長さ
```c
char s[] = "hello world!";
printf("the length of s is %lu or %lu?\n", sizeof(s) / sizeof(char), strlen(s));
````

2. 文字列のコピー

```c
	char s[10];
	strcpy(s, "hello");

	printf("s is %s\n", s);
```

3. 文字列の結合

```c
	char s[10] = "matsui";
	char s1[10] = "matsui";
	char t[10] = "528";

	char *name = strcat(s, t);
	strcat(s1, t);

	printf("the name is %s\n", name);
	printf("the name is %s\n", s1);
```

4. 文字列の比較

```c
	char s[] = "matsui";
	char t[] = "matsui";

	if (strcmp(s, t) == 0) {
		printf("%s == %s\n", s, t);
	}
```

5. ascii と文字列

```c
int ascii_bit = 7;
for (int i = 0; i < (1 << ascii_bit); ++i) {
	printf("the ascii char is %c of %d\n", i, i);
}
```

### 問題 1. ascii の文字で表させる数字をその文字の int を出力するプログラムを作成せよ.

```c
int main() {
	int ascii_bit = 7;
	for (int i = 0; i < (1 << ascii_bit); ++i) {
		printf("the ascii char is %c of %d\n", i, i);
	}
}
```

### 問題 2. 大文字が与えられたときに小文字に変換するプログラムを作成せよ.

```c
char lower(char c) {
	if ('A' <= c && c <= 'Z') {
		int gap = 'A' - 'a';
		return c - gap;
	}
	return c;
}
```

### 問題 3. 文字列が与えられた時に、その文字列の長さを出力する mystrlen 関数を作成せよ.

```c
int my_strlen(char *s) {
	int number = 0;

	while (s[number] != '\0') {
		++number;
	}

	return number;
}
```

## 3. 型変換

C 言語では異なる型同士の演算では暗黙的な型変換が行われる. 原則は、「意味を変えないように注意してより大きい範囲に合わせる」

```c
float v = 3.223;   // この場合はOKだが、doubleからfloatに変換されている3.223f
float v2 = 3.223f; // 明示的にfloatのリテラルだと示すときはこちらのほうがいい
```

1. 明示的な型変換 cast

詳しい説明

- https://arc.net/l/quote/wnzvfdwb

## 4. 入出力

C 言語での入出力はストリームという概念を使って行われる. これは文字列 + \n が 1 単位とした集まりのことである.

### 4.1 getchar と putchar

```c
int main() {
	char c;
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
```

- EOF は End Of File の略で、ファイルの終わりを示す.
- control + D で EOF を入力できる. control + C は強制終了
- getchar では enter を押すまでは buffer に貯められて enter が押されると一気に getchar に流れ込む.

### 4.2 printf 詳細

```
printf("%5.2f\n", 3.14159); //  3.14 と表示される. 5は全体の幅、2は小数点以下の幅
```

10進数から2, 8, 16進数に変換する場合は以下のようにする.

```
printf("%d %o %x\n", 10, 10, 10); // 10 12 a と表示される
```

## 5. 課題
文字と数字を与えると、それを数直線上に表示するプログラムを書きましょう。main.cにはほとんど何も書いてありません。それを編集して以下を実現してください。

知識
- `echo "" -nは改行なしでEOFを出力する

タスクEまでの実装
```c
#include <stdio.h>

int atoi(char c) {
	int gap = 1 - '1';
	return c + gap;	
}

int my_strlen(char *s) {
	int count = 0;
	while (s[count] != '\0') {
		++count;
	}
	return count;
}

int main() {
	char number_area[] = "  0    5   10   15  ";
	char mark_area[] = "--+----+----+----+-->";

	// 0よりも前に謎に2byte分あるため. 
	int buffer_size = 2;
	// 記号を格納
	char sign;
	// 場所のindexを格納
	int place = 0;

	char c;
	// この実装では2桁以上の数字に対応できない
	while ((c = getchar()) != EOF) {
		if ('a' <= c && c <= 'z') {
			sign = c;
		} else if('0' <= c && c <= '9') {
			int number = atoi(c);
			if (place != 0) {
				place = 10 * place + number;
			} else {
				place = number;
			}
		} else if (c == '\n') {
			mark_area[place + buffer_size] = sign;
			place = 0;
			printf("%s\n", number_area);
			printf("%s\n", mark_area); 
		}
	}
}
```

発展課題
二次元配列に対応する. 