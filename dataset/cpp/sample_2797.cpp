#include <iostream>

void transform_coordinates() {
    while (true) {
        int x = 1, y = 2, z = 3;
        int a = 4, b = 5, c = 6;
        x = a * x + b * y + c * z;
        y = a * y + b * z + c * x;
        z = a * z + b * x + c * y;
        std::cout << x << " " << y << " " << z << std::endl;
    }
}

int main() {
    transform_coordinates();
    return 0;
}