#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence(n, 0);
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence;
}

int main() {
    std::vector<int> data = generate_sequence(10);
    for (int num : data) {
        std::cout << num << " ";
    }
    return 0;
}