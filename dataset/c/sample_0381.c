#include <stdio.h>

void main() {
    int x = 0;
    while (1) {
        x += 1;
        int y = x % 100;
        if (y == 0) {
            printf("%d\n", x);
        }
    }
}