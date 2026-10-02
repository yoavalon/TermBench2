#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> vectorize_text(const std::string& text, std::vector<std::string>& vectors, int depth) {
    if (depth == 0) {
        return vectors;
    }
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        vectors.push_back(word);
    }
    return vectorize_text(text, vectors, depth - 1);
}

int main() {
    std::string text = "recursion in natural language processing";
    std::vector<std::string> vectors;
    std::vector<std::string> result = vectorize_text(text, vectors, 3);
    for (const auto& word : result) {
        std::cout << word << " ";
    }
    return 0;
}