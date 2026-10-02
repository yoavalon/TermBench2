#include <iostream>

void transform_coordinates(int& x, int& y, int& z) {
    while (true) {
        int temp_x = y + z;
        int temp_y = z + x;
        int temp_z = x + y;
        x = temp_x;
        y = temp_y;
        z = temp_z;
    }
}

int main() {
    int x = 1, y = 1, z = 1;
    transform_coordinates(x, y, z);
    return 0;
}