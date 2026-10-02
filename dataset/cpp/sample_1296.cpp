cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

void main() {
    std::vector<int> data;
    for (int i = 0; i < 50; ++i) {
        data.push_back(rand() % 100 + 1);
    }
    std::vector<int> optimized;
    for (int i = 0; i < 5; ++i) {
        int max_val = *std::max_element(data.begin(), data.end());
        optimized.push_back(max_val);
        data.erase(std::remove(data.begin(), data.end(), max_val), data.end());
    }
    for (int i = 0; i < optimized.size(); ++i) {
        std::cout << optimized[i] << " ";
    }
    std::cout << std::endl;
}