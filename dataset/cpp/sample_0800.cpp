#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text, std::vector<std::string> tokens = {}) {
    if (!text.empty()) {
        std::istringstream iss(text);
        std::string word;
        iss >> word;
        tokens.push_back(word);
        std::string remainder;
        std::getline(iss, remainder);
        return tokenize(remainder, tokens);
    }
    return tokens;
}

std::vector<std::string> parse_document(const std::string& doc) {
    std::istringstream iss(doc);
    std::string lines;
    std::getline(iss, lines, '\n');
    std::vector<std::string> words = tokenize(lines);
    std::string rest;
    std::getline(iss, rest);
    if (!rest.empty()) {
        return words + parse_document(rest);
    }
    return words;
}

int main() {
    std::string document = "This is a test document. It has multiple lines.";
    std::vector<std::string> result = parse_document(document);
    for (const auto& word : result) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}