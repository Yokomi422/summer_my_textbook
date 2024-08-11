## 1. ポインタとは
ポインタとは変数のメモリでの住所(アドレス)を格納する変数のこと. 

注意
```c
int *p, q, r;
```
- この場合, pはポインタ変数であり, q, rはint型の変数である.

## 2. ポインタと関数
ポインタの使用例のひとつは、関数複数の値を返したい時である. 複数の値を返すといってもreturnのオペラントが複数になるわけではなく、ポインタ引数取ってそのまま値を直接書き換えるという方法である. 

また、関数に配列を渡すことはポインタを渡すことと同じなので、`int a[]`は`int *a`と同じである.

とは言っても、関数引数以外で配列をポインタとして扱うときは、`int *a`と`int a[]`は異なる.これは`sizeof`演算子を使用するとわかる. 

```c
int a[] = {1, 2, 3, 4, 5}, *p;
p = a;
printf("sizeof(p): %lu\n", sizeof(p)); // sizeof(p): 8
printf("sizeof(a): %lu\n", sizeof(a)); // sizeof(a): 20
```

### 問題1
与えられた配列の中から最大値と最小値を返す関数を作成せよ. 

```c
void max_min(int a[], int n,int *max, int *min) {
	for (int i = 0; i < n; ++i) {
		if (*max < a[i]) {
			*max = a[i];
		}

		if (*min > a[i]) {
			*min = a[i];
		}
	}
}

int main() {
	int a[] = { 1, 3, 1, 4, 10, 591, -10};
	int max = - (1 << 10);
	int min = 1 << 10;

	max_min(a, sizeof(a) / sizeof(int), &max, &min);

	printf("max: %d min: %d\n", max, min);
}
```

知識
```c
void max_min(int a[], int *max, int *min) {
	int size = (int)sizeof(a) / sizeof(int);

}
```
- 関数の引数に配列を渡しても配列の長さはわからない. 


## 3. ポインタと配列

- C言語のNULLという概念
- `define N 5`はマクロで、コンパイルする段階でNを5に置き換える.

### 問題2
与えられた配列を並び替えるアルゴリズム(挿入ソート)を実装せよ.

```c
#include <stdio.h>

void insertion_sort(int nums[], int size) {
	int index = 1;

	while (index < size) {
		int tmp_index = index - 1;
		int tmp = nums[index];
		while (tmp_index >= 0) {
			if (tmp < nums[tmp_index]) {
				nums[tmp_index + 1] = nums[tmp_index];
				--tmp_index;
			} else if (tmp >= nums[tmp_index]) {
				break;
			}
		}
		nums[tmp_index + 1] = tmp;
		++index;
	}
}

int main() {
	int nums[] = {41,1, 10, 1241, 1513,541,5,14,13,41,425,25};
	int size = sizeof(nums) / sizeof(int);

	insertion_sort(nums, size);
	for (int i = 0; i < size; ++i) {
		printf("%d\n", nums[i]);
	}
}


```