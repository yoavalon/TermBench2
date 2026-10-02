#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

std::vector<int> optimize_logistics(const std::vector<int>& sequence) {
    std::vector<int> costs;
    for (int value : sequence) {
        int cost = value * value + 3 * value + 2;
        costs.push_back(cost);
    }
    return costs;
}

int main() {
    while (true) {
        std::vector<int> seq = generate_sequence(10);
        std::vector<int> costs = optimize_logistics(seq);
        for (int cost : costs) {
            std::cout << cost << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}