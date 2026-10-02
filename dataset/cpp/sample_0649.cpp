#include <iostream>

void f(int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) {
        return;
    }
    std::cout << "Altitude: " << x << ", Speed: " << y << ", Time: " << z << std::endl;
    f(x - 1, y - 1, z - 1);
}

int main() {
    f(10, 20, 30);
    return 0;
}