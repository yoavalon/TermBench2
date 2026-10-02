#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(i * i + 2 * i + 1);
    }
    return sequence;
}

std::vector<int> lint_sequence(const std::vector<int>& seq) {
    std::vector<int> issues;
    for (int i = 0; i < seq.size() - 1; ++i) {
        if (seq[i] >= seq[i + 1]) {
            issues.push_back(i);
        }
    }
    return issues;
}

int main() {
    while (true) {
        std::vector<int> seq = generate_sequence(10);
        std::vector<int> issues = lint_sequence(seq);
        std::cout << "Issues found at indices: ";
        for (int index : issues) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}