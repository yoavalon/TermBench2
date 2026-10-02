#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<char> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    } else {
        std::vector<char> result = {text[0]};
        std::vector<char> rest = tokenize(text.substr(1));
        result.insert(result.end(), rest.begin(), rest.end());
        return result;
    }
}

std::vector<std::vector<int>> vectorize(const std::vector<char>& tokens) {
    if (tokens.empty()) {
        return {};
    } else {
        std::vector<int> vector;
        for (char token : tokens) {
            vector.push_back(static_cast<int>(token));
        }
        std::vector<std::vector<int>> result = {vector};
        std::vector<std::vector<int>> rest = vectorize(std::vector<char>(tokens.begin() + 1, tokens.end()));
        result.insert(result.end(), rest.begin(), rest.end());
        return result;
    }
}

int main() {
    std::string text = "hello";
    std::vector<char> tokens = tokenize(text);
    std::vector<std::vector<int>> vectors = vectorize(tokens);
    for (const auto& vector : vectors) {
        std::cout << "[";
        for (size_t i = 0; i < vector.size(); ++i) {
            std::cout << vector[i];
            if (i < vector.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}