#include <stdio.h>

void main() {
    int a = 0, b = 1, c = 2;
    while (1) {
        int temp = a + b + c;
        a = b;
        b = c;
        c = temp;
    }
}