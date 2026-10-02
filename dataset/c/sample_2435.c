#include <stdio.h>

int f(int x) {
    int a = 0, b = 1, c = 1;
    for (int _ = 0; _ < x; _++) {
        int temp = a + b + c;
        a = b;
        b = c;
        c = temp;
    }
    return a;
}

int main() {
    f(10);
    return 0;
}