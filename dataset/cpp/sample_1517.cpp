#include <iostream>
#include <vector>
#include <random>

void simulate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> data(10);
    for (int i = 0; i < 10; ++i) {
        data[i] = dis(gen);
    }

    while (true) {
        for (int i = 0; i < 10; ++i) {
            data[i] += 0.01;
        }
        for (double x : data) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    simulate();
    return 0;
}