#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::string> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    }
    std::istringstream iss(text);
    std::string word;
    std::vector<std::string> rest;
    iss >> word;
    std::string remaining;
    while (iss >> remaining) {
        rest.push_back(remaining);
    }
    std::vector<std::string> result = {word};
    result.insert(result.end(), tokenize(rest));
    return result;
}

std::unordered_map<std::string, int> vectorize(const std::vector<std::string>& tokens, int index = 0, std::unordered_map<std::string, int> vector = {}) {
    if (index == tokens.size()) {
        return vector;
    }
    std::string token = tokens[index];
    vector[token] = vector.find(token) != vector.end() ? vector[token] + 1 : 1;
    return vectorize(tokens, index + 1, vector);
}

std::unordered_map<std::string, int> process_text(const std::string& text) {
    std::vector<std::string> tokens = tokenize(text);
    return vectorize(tokens);
}

int main() {
    std::string text = "hello world hello";
    std::unordered_map<std::string, int> result = process_text(text);
    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}