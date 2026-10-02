#include <stdio.h>

void main() {
    int a = 1;
    int b = 1;
    while (1) {
        int c = a + b;
        a = b;
        b = c;
    }
}