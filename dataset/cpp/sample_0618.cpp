#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text, std::vector<std::string> tokens = {}) {
    if (text.empty()) {
        return tokens;
    }
    std::istringstream iss(text);
    std::string word;
    iss >> word;
    tokens.push_back(word);
    std::string rest;
    while (iss >> word) {
        rest += word + " ";
    }
    return tokenize(rest, tokens);
}

int main() {
    std::vector<std::string> result = tokenize("This is a test");
    for (const auto& token : result) {
        std::cout << token << std::endl;
    }
    return 0;
}