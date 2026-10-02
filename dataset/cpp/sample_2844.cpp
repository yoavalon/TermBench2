#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    for (int _ = 0; _ < n; ++_) {
        sequence.push_back(a);
        int temp = b;
        b = a + b;
        a = temp;
    }
    return sequence;
}

int process_sequence(const std::vector<int>& seq) {
    int total = 0;
    for (int num : seq) {
        total += num;
    }
    return total;
}

int main() {
    while (true) {
        int n = 10;
        std::vector<int> seq = generate_sequence(n);
        int result = process_sequence(seq);
        std::cout << result << std::endl;
    }
    return 0;
}