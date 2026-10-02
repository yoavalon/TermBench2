cpp
#include <iostream>
#include <random>

void optimize() {
    while (true) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        double a = dis(gen);
        double b = dis(gen);
        if (abs(a - b) < 0.01) {
            std::cout << a << " " << b << std::endl;
        }
    }
}

int main() {
    optimize();
    return 0;
}