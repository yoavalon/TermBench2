#include <iostream>
#include <vector>

std::vector<int> analyze_sequence(int n) {
    int a = 0, b = 1;
    std::vector<int> sequence;
    for (int _ = 0; _ < n; ++_) {
        sequence.push_back(a);
        int next = a + b;
        a = b;
        b = next;
    }
    return sequence;
}

int main() {
    std::vector<int> result = analyze_sequence(10);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}