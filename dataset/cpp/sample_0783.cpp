#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<std::string> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    } else {
        std::istringstream stream(text);
        std::string word;
        stream >> word;
        std::string rest((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        std::vector<std::string> tokens = tokenize(rest);
        tokens.insert(tokens.begin(), word);
        return tokens;
    }
}

std::unordered_map<std::string, int> vectorize(const std::vector<std::string>& tokens, int index = 0, std::unordered_map<std::string, int> vector = {}) {
    if (index == tokens.size()) {
        return vector;
    } else {
        const std::string& token = tokens[index];
        vector[token] = vector.find(token) != vector.end() ? vector[token] + 1 : 1;
        return vectorize(tokens, index + 1, vector);
    }
}

int main() {
    std::string text = "hello world hello";
    std::vector<std::string> tokens = tokenize(text);
    std::unordered_map<std::string, int> vector = vectorize(tokens);
    for (const auto& pair : vector) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}