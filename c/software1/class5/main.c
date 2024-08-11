#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

int is_alphabet(char);
char shift_char(char, int);
char reverse_char(char, int);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string> <number>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int n = atoi(argv[2]);

    char reversed_text[strlen(text) + 1];

    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (is_alphabet(c)) {
            reversed_text[i] = shift_char(c, n);
        } else {
            reversed_text[i] = c;
        }
    }

    printf("the text is %s\n", reversed_text);
}

int is_alphabet(char c) {
    if ((97 <= c && c <= 122) || (65 <= c && c <= 90)) {
        return 1;
    } else {
        return 0;
    }
}

char shift_char(char c, int n) {
    // 0基準にする
    if (c <= 90) {
        c -= 65;
        return (c + n) % 26 + 65;
    } else {
        c -= 97;
        return (c + n) % 26 + 97;
    }
}