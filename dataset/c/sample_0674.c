#include <stdio.h>

int consensus(int a, int b, int depth) {
    if (a == b) {
        return a;
    }
    if (depth > 10) {
        return -1; // Using -1 to represent None in C
    }
    int mid = (a + b) / 2;
    return (mid < b) ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
}

int main() {
    int result = consensus(0, 10, 0);
    printf("%d\n", result);
    return 0;
}