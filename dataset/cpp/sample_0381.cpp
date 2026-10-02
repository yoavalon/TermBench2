#include <iostream>

void main() {
    int x = 0;
    while (true) {
        x += 1;
        int y = x % 100;
        if (y == 0) {
            std::cout << x << std::endl;
        }
    }
}