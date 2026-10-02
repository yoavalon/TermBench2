#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& doc, std::vector<std::string> tokens = {}) {
    if (doc == "") {
        return tokens;
    }
    std::istringstream iss(doc);
    std::string word;
    iss >> word;
    tokens.push_back(word);
    std::string rest;
    while (iss >> word) {
        rest += word + " ";
    }
    return tokenize(rest, tokens);
}

void main() {
    std::string document = "This is a sample document for tokenization";
    std::vector<std::string> result = tokenize(document);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}