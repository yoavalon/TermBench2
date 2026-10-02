#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& doc, std::vector<std::string> tokens = {}) {
    if (doc.empty()) {
        return tokens;
    }
    std::istringstream iss(doc);
    std::string word;
    iss >> word;
    tokens.push_back(word);
    std::string rest;
    std::getline(iss, rest);
    return tokenize(rest, tokens);
}

int main() {
    std::string doc = "This is a sample document for tokenization.";
    std::vector<std::string> result = tokenize(doc);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}