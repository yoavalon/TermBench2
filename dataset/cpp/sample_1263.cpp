#include <iostream>

void main() {
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < 100; i++) {
        x += 1;
        y += 2;
        z += 3;
    }
    std::cout << x << " " << y << " " << z << std::endl;
}