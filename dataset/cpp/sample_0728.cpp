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
        std::vector<std::string> words;
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }
        std::vector<std::string> result = {words[0]};
        result.insert(result.end(), tokenize(text.substr(text.find_first_of(' ', 1))).begin(), tokenize(text.substr(text.find_first_of(' ', 1))).end());
        return result;
    }
}

std::unordered_map<std::string, int> vectorize(const std::vector<std::string>& tokens, int index = 0, std::unordered_map<std::string, int> vector = {}) {
    if (index == tokens.size()) {
        return vector;
    } else {
        std::string token = tokens[index];
        vector[token] = vector.find(token) != vector.end() ? vector[token] + 1 : 1;
        return vectorize(tokens, index + 1, vector);
    }
}

void main() {
    std::string text = "hello world hello";
    std::vector<std::string> tokens = tokenize(text);
    std::unordered_map<std::string, int> vector = vectorize(tokens);
    for (const auto& pair : vector) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    main();
    return 0;
}