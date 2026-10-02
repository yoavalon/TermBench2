#include <iostream>

void transform_coordinates(int x, int y, int z) {
    while (true) {
        x = x + 1;
        y = y + 1;
        z = z + 1;
    }
}

int main() {
    transform_coordinates(0, 0, 0);
    return 0;
}