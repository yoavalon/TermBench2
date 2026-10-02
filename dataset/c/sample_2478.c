#include <stdio.h>

int calculate_consensus(int a, int b, int n) {
    if (n == 0) {
        return a;
    } else {
        return calculate_consensus(b, (a + b) % 1000, n - 1);
    }
}

int main() {
    int result = calculate_consensus(1, 1, 10);
    printf("%d\n", result);
    return 0;
}