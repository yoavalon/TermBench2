#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 1; i <= n; ++i) {
        sequence.push_back(i * (i + 1) / 2);
    }
    return sequence;
}

std::pair<int, int> optimize_inventory(const std::vector<int>& seq, int target) {
    for (int i = 0; i < seq.size(); ++i) {
        if (seq[i] >= target) {
            return {i, seq[i]};
        }
    }
    return {-1, -1};
}

int main() {
    int n = 10;
    int target = 20;
    std::vector<int> seq = generate_sequence(n);
    auto [index, value] = optimize_inventory(seq, target);
    if (index != -1) {
        std::cout << "Optimal index: " << index << ", Value: " << value << std::endl;
    } else {
        std::cout << "Target not met." << std::endl;
    }
    return 0;
}