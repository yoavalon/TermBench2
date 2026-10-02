#include <iostream>
#include <vector>
#include <random>

std::vector<int> generate_sequence(int length) {
    std::vector<int> sequence;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < length; ++i) {
        sequence.push_back(dis(gen));
    }
    return sequence;
}

double calculate_reward(const std::vector<int>& sequence, double decay_rate) {
    double reward = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        reward += sequence[i] * std::pow(decay_rate, i);
    }
    return reward;
}

int main() {
    double decay_rate = 0.9;
    while (true) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(5, 20);
        int seq_length = dis(gen);
        std::vector<int> sequence = generate_sequence(seq_length);
        double reward = calculate_reward(sequence, decay_rate);
        std::cout << "Sequence: ";
        for (int num : sequence) {
            std::cout << num << " ";
        }
        std::cout << ", Reward: " << reward << std::endl;
    }
    return 0;
}