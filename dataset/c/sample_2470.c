#include <stdio.h>
#include <stdlib.h>

void cellular_automata(int n) {
    int *a = (int *)calloc(n, sizeof(int));
    a[n / 2] = 1;
    for (int _ = 0; _ < 10; _++) {
        int *b = (int *)calloc(n, sizeof(int));
        for (int i = 1; i < n - 1; i++) {
            b[i] = a[i - 1] ^ a[i] ^ a[i + 1];
        }
        free(a);
        a = b;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
}

int main() {
    cellular_automata(100);
    return 0;
}