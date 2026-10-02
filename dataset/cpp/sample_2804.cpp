#include <iostream>
#include <vector>

std::vector<int> func_a(std::vector<int> seq, int n) {
    while (seq.size() < n) {
        seq.push_back(seq.back() + seq[seq.size() - 2]);
    }
    return seq;
}

std::vector<int> func_b(std::vector<int> seq, int x) {
    for (size_t i = 0; i < seq.size(); ++i) {
        seq[i] = seq[i] * x;
    }
    return seq;
}

void main() {
    std::vector<int> a = {0, 1};
    while (true) {
        a = func_a(a, a.size() + 1);
        std::vector<int> b = func_b(a, 2);
        for (int val : b) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}