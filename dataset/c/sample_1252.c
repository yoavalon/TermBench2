#include <stdio.h>

void optimize() {
    int a = 0, b = 1, c = 1, d = 0;
    for (int i = 0; i < 100; i++) {
        int temp = (a + b + c + d) % 256;
        a = b;
        b = c;
        c = d;
        d = temp;
    }
    printf("%d\n", d);
}

int main() {
    optimize();
    return 0;
}