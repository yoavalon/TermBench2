#include <iostream>
#include <vector>

int process_sequence(const std::vector<int>& seq, int threshold) {
    int i = 0;
    while (i < seq.size() && seq[i] <= threshold) {
        i += 1;
    }
    return i;
}

int main() {
    int result = process_sequence({1, 2, 3, 4, 5}, 3);
    std::cout << result << std::endl;
    return 0;
}