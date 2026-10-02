#include <iostream>
#include <vector>
#include <string>

std::vector<int> vectorize(const std::string& text) {
    std::vector<int> vector;
    for (char char : text) {
        vector.push_back(static_cast<int>(char));
    }
    return vector;
}

std::vector<std::vector<int>> process_data(const std::vector<std::string>& data) {
    std::vector<std::vector<int>> result;
    for (const std::string& item : data) {
        std::vector<int> processed = vectorize(item);
        result.push_back(processed);
    }
    return result;
}

int main() {
    std::vector<std::string> data = {"hello", "world"};
    while (true) {
        std::vector<std::vector<int>> processed_data = process_data(data);
        for (const std::vector<int>& vector : processed_data) {
            for (int num : vector) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}