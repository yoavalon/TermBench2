#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    for (int _ = 0; _ < n; ++_) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

std::vector<int> process_sequence(const std::vector<int>& seq) {
    std::vector<int> processed;
    for (int num : seq) {
        if (num % 2 == 0) {
            processed.push_back(num * 2);
        } else {
            processed.push_back(num + 1);
        }
    }
    return processed;
}

void main() {
    while (true) {
        std::vector<int> seq = generate_sequence(10);
        std::vector<int> proc_seq = process_sequence(seq);
        for (int num : proc_seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}