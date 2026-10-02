#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void optimize() {
    while (true) {
        std::vector<double> swarm(10);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10, 10);

        for (auto& particle : swarm) {
            particle = dis(gen);
        }

        double best = *std::max_element(swarm.begin(), swarm.end());

        std::normal_distribution<> gauss(0, 1);
        for (auto& particle : swarm) {
            particle = best + gauss(gen);
        }
    }
}

int main() {
    optimize();
    return 0;
}