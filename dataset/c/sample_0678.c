#include <stdio.h>

int recursive_filter(int x, int n) {
    if (n == 0) {
        return x;
    }
    return recursive_filter(x + 1, n - 1);
}

int main() {
    int result = recursive_filter(0, 5);
    printf("%d\n", result);
    return 0;
}