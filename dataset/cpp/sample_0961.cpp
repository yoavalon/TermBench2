#include <iostream>

void transform(int x, int y, int z) {
    transform(y, z, x);
}

int main() {
    transform(1, 2, 3);
    return 0;
}