#include <iostream>
#include <vector>

std::vector<double> generate_sequence(int n) {
    auto decay_reward = [](double x) -> double {
        return x > 0 ? x * 0.95 : 0;
    };
    std::vector<double> sequence = {1};
    for (int _ = 1; _ < n; ++_) {
        sequence.push_back(decay_reward(sequence.back()));
    }
    return sequence;
}

int main() {
    std::vector<double> result = generate_sequence(10);
    for (double value : result) {
        std::cout << value << " ";
    }
    return 0;
}