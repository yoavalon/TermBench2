#include <iostream>
#include <random>

void simulate_decay() {
    double val = 1.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.9, 0.99);

    while (true) {
        double decay_factor = dis(gen);
        val *= decay_factor;
        std::cout << val << std::endl;
    }
}

int main() {
    simulate_decay();
    return 0;
}