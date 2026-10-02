#include <iostream>
#include <vector>

std::vector<int> optimize_logistics(const std::vector<int>& seq) {
    std::vector<int> result;
    for (size_t i = 0; i < seq.size(); ++i) {
        if (seq[i] > 0) {
            result.push_back(seq[i] * 2);
        } else {
            result.push_back(seq[i] + 5);
        }
    }
    return result;
}

int main() {
    std::vector<int> sequence = {1, -2, 3, -4, 5};
    std::vector<int> optimized_sequence = optimize_logistics(sequence);
    
    for (int num : optimized_sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}