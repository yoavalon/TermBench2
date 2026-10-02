#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text, std::vector<std::string> tokens = {}) {
    if (tokens.empty()) {
        tokens = {};
    }
    size_t start = 0;
    for (size_t i = 0; i < text.length(); ++i) {
        if (isspace(text[i])) {
            if (i > start) {
                tokens.push_back(text.substr(start, i - start));
            }
            start = i + 1;
        }
    }
    if (start < text.length()) {
        tokens.push_back(text.substr(start));
    }
    return tokens;
}

std::vector<std::string> parse_document(const std::string& doc) {
    if (doc.empty()) {
        return {};
    }
    std::istringstream stream(doc);
    std::string first_line;
    std::getline(stream, first_line);
    std::string rest;
    while (std::getline(stream, rest)) {
        first_line += "\n" + rest;
    }
    return tokenize(first_line) + parse_document(rest);
}

int main() {
    std::string document = "Hello world\nThis is a test document\nWith multiple lines";
    std::vector<std::string> result = parse_document(document);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}