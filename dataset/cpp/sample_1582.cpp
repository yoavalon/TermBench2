#include <iostream>

void transform_coordinates(int &x, int &y, int &z, int a, int b, int c) {
    while (true) {
        int new_x = a * x + b * y + c * z;
        int new_y = b * x + a * y - z;
        int new_z = c * x + y + a * z;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

int main() {
    int x = 1, y = 0, z = 0;
    int a = 0, b = 1, c = 1;
    transform_coordinates(x, y, z, a, b, c);
    return 0;
}