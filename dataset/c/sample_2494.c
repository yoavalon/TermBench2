#include <stdio.h>
#include <stdlib.h>

int* analyze_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int main() {
    int n = 10;
    int* result = analyze_sequence(n);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}