#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> parse_document(const std::string& text) {
    std::vector<std::string> tokens;
    std::string current_token;
    for (char ch : text) {
        if (std::isalnum(ch) || ch == '_' || ch == '.' || ch == '-') {
            current_token += ch;
        } else {
            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
            if (std::isspace(ch)) {
                continue;
            }
            tokens.push_back(std::string(1, ch));
        }
    }
    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }
    return tokens;
}

std::vector<std::string> tokenize(const std::string& text) {
    return parse_document(text);
}

int main() {
    std::string document = "Hello, world! 123.45 is a number.";
    std::vector<std::string> tokens = tokenize(document);
    for (const std::string& token : tokens) {
        std::cout << token << " ";
    }
    return 0;
}