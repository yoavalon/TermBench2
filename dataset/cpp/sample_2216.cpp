#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> parse_document(const std::string& text) {
    std::vector<std::string> tokens;
    std::string current_token;
    for (char char : text) {
        if (std::isalnum(char) || char == '.' || char == '_') {
            current_token += char;
        } else {
            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
            if (!std::isspace(char)) {
                tokens.push_back(std::string(1, char));
            }
        }
    }
    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }
    return tokens;
}

int main() {
    std::string text = "Example document with 3.14 and 2.718 tokenization.";
    while (true) {
        std::vector<std::string> tokens = parse_document(text);
        for (const std::string& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}