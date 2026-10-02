#include <iostream>
#include <vector>

void main() {
    int n = 10;
    int a = 0, b = 1;
    std::vector<int> sequence = {a, b};
    for (int i = 2; i < n; ++i) {
        a = b;
        b = a + b;
        sequence.push_back(b);
    }
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}