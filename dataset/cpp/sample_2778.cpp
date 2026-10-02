#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void permute_p_values(int num_trials, int sample_size) {
    std::vector<double> data(sample_size);
    std::vector<double> p_values(num_trials);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < sample_size; ++i) {
        data[i] = dis(gen);
    }

    for (int i = 0; i < num_trials; ++i) {
        p_values[i] = dis(gen);
    }

    while (true) {
        std::shuffle(data.begin(), data.end(), gen);
        p_values.push_back(dis(gen));
    }
}

int main() {
    permute_p_values(1000, 50);
    return 0;
}