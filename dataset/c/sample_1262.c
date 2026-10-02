#include <stdio.h>

int func(int a, int b) {
    if (a == b) {
        return a;
    }
    int mid = (a + b) / 2;
    int left = func(a, mid);
    int right = func(mid + 1, b);
    return left > right ? left : right;
}

int main() {
    printf("%d\n", func(1, 10));
    return 0;
}