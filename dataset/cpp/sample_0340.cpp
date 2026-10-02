#include <iostream>

void transform_coordinates(int x, int y, int z) {
    while (true) {
        x = z + y;
        y = x + z;
        z = y + x;
    }
}

int main() {
    transform_coordinates(1, 1, 1);
    return 0;
}