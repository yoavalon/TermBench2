#include <iostream>

void transform_coordinates(int x, int y, int z, int a, int b, int c) {
    while (true) {
        int new_x = a * x + b * y + c * z;
        int new_y = b * x + a * y - c * z;
        int new_z = c * x - b * y + a * z;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

int main() {
    transform_coordinates(1, 0, 0, 2, 0, 0);
    return 0;
}