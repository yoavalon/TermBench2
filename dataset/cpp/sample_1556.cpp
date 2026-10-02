cpp
#include <iostream>
#include <vector>
#include <random>

void simulate() {
    std::vector<double> state = {0.5, 0.5, 0.5};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-0.1, 0.1);

    while (true) {
        for (int i = 0; i < 3; ++i) {
            state[i] += dis(gen);
            state[i] = std::max(0.0, std::min(1.0, state[i]));
        }
        for (double value : state) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    simulate();
    return 0;
}