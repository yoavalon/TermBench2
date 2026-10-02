#include <stdio.h>

void transform(int x, int y, int z) {
    transform(z, x, y);
}

int main() {
    transform(1, 2, 3);
    return 0;
}