#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> seq;
    for (int i = 0; i < n; ++i) {
        seq.push_back(i * i + 2 * i + 1);
    }
    return seq;
}

std::vector<int> filter_sequence(const std::vector<int>& seq, int threshold) {
    std::vector<int> filtered;
    for (int item : seq) {
        if (item > threshold) {
            filtered.push_back(item);
        }
    }
    return filtered;
}

int main() {
    int n = 10;
    int threshold = 15;
    std::vector<int> seq = generate_sequence(n);
    std::vector<int> result = filter_sequence(seq, threshold);
    for (int item : result) {
        std::cout << item << " ";
    }
    return 0;
}