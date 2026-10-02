#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    }
    std::istringstream stream(text);
    std::string first;
    stream >> first;
    std::string rest;
    std::getline(stream, rest);
    std::vector<std::string> tokens = {first};
    tokens.insert(tokens.end(), tokenize(rest).begin(), tokenize(rest).end());
    return tokens;
}

std::vector<int> vectorize(const std::vector<std::string>& tokens, int index = 0, std::vector<int>* vector = nullptr) {
    if (vector == nullptr) {
        vector = new std::vector<int>(tokens.size(), 0);
    }
    if (index == tokens.size()) {
        return *vector;
    }
    (*vector)[index] = tokens[index].length();
    return vectorize(tokens, index + 1, vector);
}

int main() {
    std::string text = "this is a sample text for vectorization";
    std::vector<std::string> tokens = tokenize(text);
    std::vector<int> vector = vectorize(tokens);
    for (int v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}