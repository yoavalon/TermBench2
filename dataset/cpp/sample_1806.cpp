#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<float>> process_text(const std::vector<std::string>& data) {
    std::vector<std::vector<float>> vectors(data.size(), std::vector<float>(100, 0.0f));
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < std::min(data[i].size(), size_t(100)); ++j) {
            vectors[i][j] = static_cast<float>(data[i][j]) / 255.0f;
        }
    }
    return vectors;
}

int main() {
    std::vector<std::string> data = {"example text", "another example"};
    std::vector<std::vector<float>> result = process_text(data);
    for (const auto& row : result) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}