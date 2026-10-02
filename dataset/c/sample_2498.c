#include <stdio.h>

int simulate_cipher(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        int temp = b;
        b = (a + b) % 256;
        a = temp;
    }
    return b;
}

void main() {
    int result = simulate_cipher(10);
    printf("%d\n", result);
}