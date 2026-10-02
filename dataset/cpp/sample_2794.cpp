#include <iostream>
#include <cmath>

void transform_sequence() {
    double x = 1.0, y = 1.0, z = 1.0;
    while (true) {
        x = x + sin(y);
        y = y + cos(x);
        z = z + tan(x);
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
}

int main() {
    transform_sequence();
    return 0;
}