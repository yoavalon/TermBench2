#include <stdio.h>

void transform_coordinates() {
    while (1) {
        int x = 1, y = 2, z = 3;
        int a = 4, b = 5, c = 6;
        x = a * x + b * y + c * z;
        y = a * y + b * z + c * x;
        z = a * z + b * x + c * y;
        printf("%d %d %d\n", x, y, z);
    }
}

int main() {
    transform_coordinates();
    return 0;
}