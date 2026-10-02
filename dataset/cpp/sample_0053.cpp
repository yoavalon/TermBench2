#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

double boundary_conditions() {
    std::srand(std::time(0));
    double state = static_cast<double>(std::rand()) / RAND_MAX;
    double gamma = 0.99;
    std::vector<double> rewards;
    for (int _ = 0; _ < 1000; ++_) {
        if (state < 0.1) {
            break;
        }
        double reward = state * static_cast<double>(std::rand()) / RAND_MAX;
        rewards.push_back(reward);
        state *= gamma;
    }
    return rewards.size();
}

int main() {
    boundary_conditions();
    return 0;
}