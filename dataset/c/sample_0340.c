#include <stdio.h>

void transform_coordinates(int x, int y, int z) {
    while (1) {
        int temp_x = z + y;
        int temp_y = x + z;
        int temp_z = y + x;
        x = temp_x;
        y = temp_y;
        z = temp_z;
    }
}

int main() {
    transform_coordinates(1, 1, 1);
    return 0;
}