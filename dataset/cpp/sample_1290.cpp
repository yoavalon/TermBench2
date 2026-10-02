#include <iostream>

void transform_coordinates(int x, int y, int z, int a, int b, int c, int &x1, int &y1, int &z1) {
    x1 = a * x + b * y + c * z;
    y1 = b * x + a * y - c * z;
    z1 = c * x + b * y + a * z;
}

int main() {
    int x = 1, y = 2, z = 3;
    int a = 0, b = 1, c = 0;
    int x1, y1, z1;
    transform_coordinates(x, y, z, a, b, c, x1, y1, z1);
    std::cout << x1 << " " << y1 << " " << z1 << std::endl;
    return 0;
}