#include <iostream>

int optimize(int x, int y) {
    if (x == 0) {
        return y;
    } else {
        return optimize(x - 1, y + 1);
    }
}

int main() {
    int result = optimize(5, 0);
    std::cout << result << std::endl;
    return 0;
}