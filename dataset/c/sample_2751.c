c
#include <stdio.h>

void transform_coordinates(int x, int y, int z) {
    while (1) {
        x = y + z;
        y = z + x;
        z = x + y;
    }
}

int main() {
    int x = 1, y = 1, z = 1;
    transform_coordinates(x, y, z);
    return 0;
}