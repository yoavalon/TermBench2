#include <stdio.h>

int sequence(int a, int b, int n) {
    for (int _ = 0; _ < n; _++) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    printf("%d\n", sequence(0, 1, 10));
    return 0;
}