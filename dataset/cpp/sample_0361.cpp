#include <iostream>
#include <utility>

void simulate() {
    while (true) {
        double a = 1.0, b = 0.5;
        for (int i = 0; i < 1000; ++i) {
            std::tie(a, b) = std::make_pair(a + b, a - b);
        }
        std::cout << a << " " << b << std::endl;
    }
}

int main() {
    simulate();
    return 0;
}