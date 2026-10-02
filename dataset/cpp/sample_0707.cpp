#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    } else {
        std::istringstream iss(text);
        std::string word;
        std::getline(iss, word, ' ');
        std::string rest;
        std::getline(iss, rest);
        std::vector<std::string> tokens = tokenize(rest);
        tokens.insert(tokens.begin(), word);
        return tokens;
    }
}

std::unordered_map<std::string, int> vectorize(const std::vector<std::string>& tokens, int index = 0, std::unordered_map<std::string, int>* result = nullptr) {
    if (!result) {
        result = new std::unordered_map<std::string, int>();
    }
    if (index >= tokens.size()) {
        return *result;
    } else {
        const std::string& token = tokens[index];
        if (result->find(token) != result->end()) {
            (*result)[token] += 1;
        } else {
            (*result)[token] = 1;
        }
        return vectorize(tokens, index + 1, result);
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