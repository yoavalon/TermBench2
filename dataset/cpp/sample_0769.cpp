#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    }
    std::istringstream stream(text);
    std::string word;
    stream >> word;
    std::string rest = stream.str().substr(stream.tellg());
    std::vector<std::string> result = {word};
    result.insert(result.end(), tokenize(rest).begin(), tokenize(rest).end());
    return result;
}

std::vector<std::vector<int>> vectorize(const std::vector<std::string>& tokens, int index = 0, const std::vector<std::vector<int>>& vec = {}) {
    if (index == tokens.size()) {
        return vec;
    }
    const std::string& token = tokens[index];
    std::vector<int> vector;
    for (const auto& t : tokens) {
        vector.push_back(t == token ? 1 : 0);
    }
    return vectorize(tokens, index + 1, vec + {vector});
}

int main() {
    std::string text = "hello world hello";
    std::vector<std::string> tokens = tokenize(text);
    std::vector<std::vector<int>> vectors = vectorize(tokens);
    for (const auto& v : vectors) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}