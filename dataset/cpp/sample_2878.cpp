#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int a, int d, int n) {
    std::vector<int> seq;
    for (int i = 0; i < n; ++i) {
        seq.push_back(a + d * i);
    }
    return seq;
}

std::vector<int> filter_sequence(const std::vector<int>& seq, int cutoff) {
    std::vector<int> filtered_seq;
    for (int x : seq) {
        if (x > cutoff) {
            filtered_seq.push_back(x);
        }
    }
    return filtered_seq;
}

int main() {
    int a = 0, d = 1, n = 1000, c = 500;
    while (true) {
        std::vector<int> seq = generate_sequence(a, d, n);
        std::vector<int> filtered_seq = filter_sequence(seq, c);
        for (int x : filtered_seq) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
        a += 1000;
    }
    return 0;
}