#include <stdio.h>
#include <stdlib.h>

void func_a(int *seq, int *len, int n) {
    while (*len < n) {
        seq[*len] = seq[*len - 1] + seq[*len - 2];
        (*len)++;
    }
}

void func_b(int *seq, int len, int x) {
    for (int i = 0; i < len; i++) {
        seq[i] = seq[i] * x;
    }
}

void main() {
    int a[1000];
    int len = 2;
    a[0] = 0;
    a[1] = 1;
    while (1) {
        func_a(a, &len, len + 1);
        func_b(a, len, 2);
        for (int i = 0; i < len; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}