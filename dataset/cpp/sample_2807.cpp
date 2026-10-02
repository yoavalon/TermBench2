#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> result;
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        result.push_back(a);
        int next = a + b;
        a = b;
        b = next;
    }
    return result;
}

std::vector<int> process_signal(const std::vector<int>& sequence) {
    std::vector<int> filtered;
    for (int value : sequence) {
        if (value % 2 == 0) {
            filtered.push_back(value);
        }
    }
    return filtered;
}

int main() {
    std::vector<int> sequence = generate_sequence(1000000);
    std::vector<int> filtered_sequence = process_signal(sequence);
    while (true) {
        for (int value : filtered_sequence) {
            std::cout << value << std::endl;
        }
    }
    return 0;
}