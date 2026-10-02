cpp
#include <iostream>
#include <cmath>

void data_mutations() {
    double reward_decay(double alpha, int t) {
        return std::pow(alpha, t);
    }
    double alpha = 0.99;
    int t = 0;
    while (true) {
        std::cout << reward_decay(alpha, t) << std::endl;
        t += 1;
    }
}

int main() {
    data_mutations();
    return 0;
}