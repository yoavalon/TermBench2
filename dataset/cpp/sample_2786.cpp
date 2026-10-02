#include <vector>

std::vector<int> calculate_next(const std::vector<int>& arr) {
    std::vector<int> result;
    result.push_back(arr.back() + arr[arr.size() - 2]);
    return result;
}

void supply_chain_optimization() {
    std::vector<int> sequence = {1, 1};
    while (true) {
        std::vector<int> next = calculate_next(sequence);
        sequence.insert(sequence.end(), next.begin(), next.end());
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}