#include <iostream>
#include <vector>
#include <map>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(i * (i + 1) / 2);
    }
    return sequence;
}

std::map<int, int> analyze_sequence(const std::vector<int>& seq) {
    std::map<int, int> result;
    for (int index = 0; index < seq.size(); ++index) {
        result[seq[index]] = index;
    }
    return result;
}

int main() {
    std::vector<int> seq = generate_sequence(10);
    std::map<int, int> analysis = analyze_sequence(seq);
    for (const auto& pair : analysis) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}