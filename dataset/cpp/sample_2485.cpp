#include <iostream>

void sequence(int x, int y) {
    if (x > y) {
        return;
    }
    std::cout << x << std::endl;
    sequence(x + 1, y);
}

int main() {
    sequence(1, 10);
    return 0;
}