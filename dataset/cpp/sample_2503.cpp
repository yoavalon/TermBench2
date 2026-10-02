#include <iostream>
#include <vector>

std::vector<int> seq_gen(int n) {
    int a = 0, b = 1;
    std::vector<int> sequence;
    for (int _ = 0; _ < n; ++_) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

std::vector<int> consensus_mechanism(const std::vector<int>& seq) {
    std::vector<int> result;
    for (int i = 1; i < seq.size(); ++i) {
        int diff = seq[i] - seq[i - 1];
        result.push_back(diff);
    }
    return result;
}

int main() {
    int n = 10;
    std::vector<int> sequence = seq_gen(n);
    std::vector<int> consensus = consensus_mechanism(sequence);
    for (int diff : consensus) {
        std::cout << diff << " ";
    }
    return 0;
}