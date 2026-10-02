#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int current = 1;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(current);
        current *= 2;
    }
    return sequence;
}

double calculate_entropy(const std::vector<int>& sequence) {
    double entropy = 0;
    for (int value : sequence) {
        entropy += value * 0.5;
    }
    return entropy;
}

int main() {
    int n = 10;
    std::vector<int> seq = generate_sequence(n);
    double ent = calculate_entropy(seq);
    std::cout << "Sequence: ";
    for (int value : seq) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Entropy: " << ent << std::endl;
    return 0;
}