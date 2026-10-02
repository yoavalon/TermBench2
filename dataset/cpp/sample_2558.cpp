#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> seq;
    for (int i = 0; i < n; ++i) {
        seq.push_back(i * (i + 1));
    }
    return seq;
}

int process_sequence(const std::vector<int>& seq) {
    int total = 0;
    for (int num : seq) {
        total += num;
    }
    return total;
}

int main() {
    int n = 10;
    std::vector<int> seq = generate_sequence(n);
    int result = process_sequence(seq);
    std::cout << result << std::endl;
    return 0;
}