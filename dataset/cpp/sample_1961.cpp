#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> parse_document(const std::string& text) {
    std::vector<std::string> tokens;
    std::string buffer;
    for (char ch : text) {
        if (std::isalnum(ch) || ch == '.') {
            buffer += ch;
        } else {
            if (!buffer.empty()) {
                tokens.push_back(buffer);
                buffer.clear();
            }
            if (ch != ' ') {
                tokens.push_back(std::string(1, ch));
            }
        }
    }
    if (!buffer.empty()) {
        tokens.push_back(buffer);
    }
    return tokens;
}

void main() {
    std::string document = "Example 1.23 and 4.567.";
    std::vector<std::string> tokens = parse_document(document);
    for (const std::string& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}