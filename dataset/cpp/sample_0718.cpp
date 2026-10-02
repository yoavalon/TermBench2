#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text, int depth) {
    if (depth == 0) {
        return {};
    }
    std::istringstream stream(text);
    std::string word;
    std::vector<std::string> result;
    while (stream >> word) {
        result.push_back(word);
        std::vector<std::string> subTokens = tokenize(word, depth - 1);
        result.insert(result.end(), subTokens.begin(), subTokens.end());
    }
    return result;
}

std::vector<int> vectorize(const std::vector<std::string>& tokens, int depth) {
    if (depth == 0) {
        return {};
    }
    std::vector<int> vector = {static_cast<int>(tokens.size())};
    for (const auto& token : tokens) {
        std::vector<int> subVector = vectorize({token}, depth - 1);
        vector.insert(vector.end(), subVector.begin(), subVector.end());
    }
    return vector;
}

int main() {
    std::string text = "Recursive vectorization";
    int depth = 2;
    std::vector<std::string> tokens = tokenize(text, depth);
    std::vector<int> vector = vectorize(tokens, depth);
    for (int num : vector) {
        std::cout << num << " ";
    }
    return 0;
}