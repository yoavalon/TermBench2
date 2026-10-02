#include <stdio.h>

void main() {
    int x = 0;
    while (1) {
        x = (x + 1) % 1000;
        printf("%d\n", x);
    }
}