#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> vectorize_text(const std::vector<std::string>& text, int index = 0, std::vector<std::vector<std::string>> result = {}) {
    if (index == text.size()) {
        return result;
    }
    std::vector<std::string> word = {text[index]};
    result.push_back(word);
    return vectorize_text(text, index + 1, result);
}

int main() {
    std::vector<std::string> text_data = {"hello world", "data science", "python programming"};
    std::vector<std::vector<std::string>> vectorized_data = vectorize_text(text_data);
    for (const auto& vec : vectorized_data) {
        for (const auto& word : vec) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}