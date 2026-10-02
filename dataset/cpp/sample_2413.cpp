#include <iostream>
#include <vector>

int process_sequence(const std::vector<int>& seq, int max_iter) {
    int a = 0, b = 1;
    for (int _ = 0; _ < max_iter; ++_) {
        if (std::find(seq.begin(), seq.end(), a) != seq.end()) {
            return a;
        }
        int temp = b;
        b = a + b;
        a = temp;
    }
    return -1;
}

int main() {
    std::vector<int> sequence = {5, 8, 13, 21, 34};
    int iterations = 10;
    int result = process_sequence(sequence, iterations);
    std::cout << result << std::endl;
    return 0;
}