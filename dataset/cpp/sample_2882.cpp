#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int a, int b, int n) {
    std::vector<int> sequence = {a, b};
    for (int i = 2; i < n; ++i) {
        int next_value = sequence[i - 1] + sequence[i - 2];
        sequence.push_back(next_value);
    }
    return sequence;
}

std::vector<int> optimize_route(const std::vector<int>& route, const std::vector<int>& sequence) {
    std::vector<int> optimized_route;
    for (size_t i = 0; i < route.size(); ++i) {
        optimized_route.push_back(route[i] + sequence[i % sequence.size()]);
    }
    return optimized_route;
}

int main() {
    int a = 0, b = 1, n = 100;
    std::vector<int> sequence = generate_sequence(a, b, n);
    std::vector<int> route = {1, 2, 3, 4, 5};
    std::vector<int> optimized_route = optimize_route(route, sequence);
    while (true) {
        for (int value : optimized_route) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}