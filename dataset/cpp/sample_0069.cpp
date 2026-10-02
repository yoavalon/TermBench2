#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::vector<int>> vectorize_text(const std::vector<std::string>& data) {
    std::vector<std::vector<int>> vec(data.size(), std::vector<int>(100, 0));
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size() && j < 100; ++j) {
            vec[i][j] = static_cast<int>(data[i][j]) % 256;
        }
    }
    return vec;
}

int main() {
    std::vector<std::string> sample_data = {"hello", "world", "example"};
    std::vector<std::vector<int>> result = vectorize_text(sample_data);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}