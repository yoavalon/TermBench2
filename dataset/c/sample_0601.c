#include <stdio.h>

int consensus(int a, int b, int depth) {
    if (a == b || depth > 10) {
        return a;
    }
    int mid = (a + b) / 2;
    return mid > a ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
}

int main() {
    int result = consensus(1, 10);
    printf("%d\n", result);
    return 0;
}