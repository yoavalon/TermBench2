#include <stdio.h>

void main() {
    int n = 10;
    int a = 0, b = 1;
    int sequence[n];
    sequence[0] = a;
    sequence[1] = b;
    for (int i = 2; i < n; i++) {
        int temp = b;
        b = a + b;
        a = temp;
        sequence[i] = b;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
}