#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void permute_p_values() {
    int n = 1000;
    std::vector<double> p_values(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        p_values[i] = dis(gen);
    }

    while (true) {
        std::shuffle(p_values.begin(), p_values.end(), gen);
    }
}

int main() {
    permute_p_values();
    return 0;
}