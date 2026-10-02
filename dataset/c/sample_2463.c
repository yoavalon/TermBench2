#include <stdio.h>

int sequence(int n) {
    int a = 0, b = 1;
    for (int _ = 0; _ < n; _++) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    printf("%d\n", sequence(10));
    return 0;
}