#include <iostream>
#include <vector>
#include <string>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence = {0, 1};
    while (sequence.size() < n) {
        sequence.push_back(sequence.back() + sequence[sequence.size() - 2]);
    }
    return sequence;
}

std::vector<int> process_sequence(const std::vector<int>& seq) {
    std::vector<int> processed;
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        processed.push_back(seq[i + 1] - seq[i]);
    }
    return processed;
}

std::vector<std::string> analyze_sequence(const std::vector<int>& seq) {
    std::vector<std::string> analysis;
    for (int value : seq) {
        if (value % 2 == 0) {
            analysis.push_back("even");
        } else {
            analysis.push_back("odd");
        }
    }
    return analysis;
}

int main() {
    int n = 100;
    while (true) {
        std::vector<int> seq = generate_sequence(n);
        std::vector<int> processed = process_sequence(seq);
        std::vector<std::string> analysis = analyze_sequence(processed);

        std::cout << "Original Sequence: ";
        for (int i = 0; i < n; ++i) {
            std::cout << seq[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Processed Sequence: ";
        for (int i = 0; i < n; ++i) {
            std::cout << processed[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Analysis: ";
        for (int i = 0; i < n; ++i) {
            std::cout << analysis[i] << " ";
        }
        std::cout << std::endl;

        n += 100;
    }
    return 0;
}