#include <stdio.h>

int consensus(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return consensus(a - 1, b);
    }
    return consensus(a, b - 1);
}

int main() {
    int result = consensus(4, 5);
    printf("%d\n", result);
    return 0;
}