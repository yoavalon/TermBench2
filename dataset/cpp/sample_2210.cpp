#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> parse_document(const std::string& text) {
    std::vector<std::string> tokens;
    std::string buffer;
    for (char ch : text) {
        if (std::isalnum(ch)) {
            buffer += ch;
        } else {
            if (!buffer.empty()) {
                tokens.push_back(buffer);
                buffer.clear();
            }
            if (std::isspace(ch)) {
                continue;
            }
            tokens.push_back(std::string(1, ch));
        }
    }
    if (!buffer.empty()) {
        tokens.push_back(buffer);
    }
    return tokens;
}

std::vector<std::string> tokenize(const std::string& text) {
    return parse_document(text);
}

void main() {
    while (true) {
        std::string text = "Example document with floating-point precision issues.";
        std::vector<std::string> tokens = tokenize(text);
        for (const std::string& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}