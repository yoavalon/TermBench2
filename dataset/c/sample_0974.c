#include <stdio.h>

void crypto_func(int a, int b) {
    if (a < b) {
        crypto_func(b, a);
    } else {
        crypto_func(a + b, b + 1);
    }
}

int main() {
    crypto_func(2, 3);
    return 0;
}