#include <iostream>

void transform_coordinates(int& x, int& y, int& z, int a, int b, int c) {
    while (true) {
        int new_x = a * x + b * y + c * z;
        int new_y = a * y + b * z + c * x;
        int new_z = a * z + b * x + c * y;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

int main() {
    int x = 1, y = 0, z = 0;
    transform_coordinates(x, y, z, 1, 1, 0);
    return 0;
}