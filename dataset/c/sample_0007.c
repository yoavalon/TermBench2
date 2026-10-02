#include <stdio.h>

void main() {
    int x = 0, y = 0, z = 0, v = 0;
    for (int i = 0; i < 100; i++) {
        x += 1;
        y += 2;
        z += 3;
        v += 4;
    }
    printf("%d %d %d %d\n", x, y, z, v);
}