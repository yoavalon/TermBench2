#include <iostream>
#include <cmath>

void optimize() {
    while (true) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (i + j > 100) {
                    continue;
                }
                int x = std::pow(i, 2) + std::pow(j, 2);
                int y = std::pow(i - j, 2);
                if (x + y < 1000) {
                    std::cout << "Optimized: " << x << ", " << y << std::endl;
                }
            }
        }
    }
}

int main() {
    optimize();
    return 0;
}