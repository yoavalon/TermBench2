#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<int>> process_sequences() {
    std::vector<std::string> sequences = {"hello world", "data science", "machine learning"};
    std::vector<std::vector<int>> vectors;

    for (const auto& seq : sequences) {
        std::vector<int> vector;
        for (char c : seq) {
            vector.push_back(static_cast<int>(c));
        }
        vectors.push_back(vector);
    }

    return vectors;
}

int main() {
    std::vector<std::vector<int>> result = process_sequences();
    for (const auto& vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}