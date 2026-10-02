#include <stdio.h>

int* f() {
    static int a = 0, b = 1;
    static int* result = &a;
    b = a + b;
    a = *result;
    *result = b;
    return result;
}

int* g() {
    static int* x = f();
    static int* result = &(*x % 2);
    return result;
}

int main() {
    int* h = g();
    while (1) {
        printf("%d\n", *h);
        h = g();
    }
    return 0;
}