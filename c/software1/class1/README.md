## 学習したこと

1. print 関数の違い

2. printf の詳細
   実はストリームバッファに出力をしている.
   stream buffer の大きさは`printf("%d\n", BUFSIZ);`で確認可能. 私のマシンでは 1024byte でした。一般にheap size
   という. 

参考

- https://hikotech.net/post-331/
- https://software-dl.ti.com/ccs/esd/documents/sdto_cgt_tips_for_using_printf.html

3. include
`#include`は指定したファイルを展開するという意味. headerは`/usr/include`にある

4. 特殊文字
"や\を文字列として出力するためには、特殊文字として\"や\\を使う必要がある. 

5. データ型
```c
// 宣言と代入
int a = 1;
// 複数制限
int a, b;
```

整数の型としては以下のようのものがある. 
| 型名            | サイズ (bit) | 値の範囲                                   |
|-----------------|--------------|--------------------------------------------|
| char (よく使う) | 8            | (-128 から 127)                             |
| short           | 普通は16     | (-32,768 から 32,767)                       |
| int (よく使う)  | 普通は32     | (-2,147,483,648 から 2,147,483,647)         |
| long            | 32か64       | (-2,147,483,648 から 2,147,483,647) あるいは, (-9,223,372,036,854,775,808 から 9,223,372,036,854,775,807) |
| unsigned char   | 8            | (0 から 255)                               |
| unsigned short  | 普通は16     | (0 から 65,535)                            |
| unsigned int    | 普通は32     | (0 から 4,294,967,295)                     |
| unsigned long   | 32か64       | (0 から 4,294,967,295) あるいは, (0 から 18,446,744,073,709,551,615) |

実数型

| 型名                       | サイズ (bit) | 値の範囲                         |
|----------------------------|--------------|----------------------------------|
| float (よく使う)：単精度浮動小数点数 | 普通は32     | 約 \(1.2 \times 10^{-38}\) から 約 \(3.4 \times 10^{38}\) |
| double (よく使う)：倍精度浮動小数点数 | 普通は64     | 約 \(2.3 \times 10^{-308}\) から 約 \(1.7 \times 10^{308}\) |

`%f`や`%lf`でエスケープされる.

`printf("%d\n", sizeof(float) * 8);`などでbit数を確認してみよう. 

### 問題1
以下がどうして0になるかを考えてみよう
int main() {
	float v = 123 / 3;
	printf("%d\n", v);
}


```
char c1, c2, c3;
c1 = 12;
c2 = 24;
c3 = 140;
printf("c1: %d, c2: %d, c3: %d, c1+c2: %d\n", c1, c2, c3, c1 + c2);
```

c3が-116になる理由は、charは-128 ~ 127の範囲の整数を表現するが、140をbit列で表現をすると'0b10001100'になりこれを符号付きの整数と考えると確かに-116になる.

