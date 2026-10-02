#include <iostream>
#include <vector>

std::vector<int> process_sequence(const std::vector<int>& seq) {
    std::vector<int> states = {0, 1};
    std::vector<std::vector<int>> transitions = {{0, 1}, {1, 0}};
    int current = states[0];
    std::vector<int> result;
    for (size_t _ = 0; _ < seq.size(); ++_) {
        current = transitions[current][seq[_] % 2 == 0 ? 0 : 1];
        result.push_back(current);
    }
    return result;
}

int main() {
    std::vector<int> seq = {0, 1, 2, 3, 4, 5};
    std::vector<int> result = process_sequence(seq);
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}