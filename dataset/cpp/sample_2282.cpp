#include <iostream>
#include <vector>
#include <cctype>

std::vector<std::string> parse_text(const std::string& data) {
    std::vector<std::string> tokens;
    std::string buffer;
    for (char ch : data) {
        if (std::isalnum(ch)) {
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
    std::string text = "Example text with numbers 123 and symbols! #456";
    std::vector<std::string> result = parse_text(text);
    while (true) {
        for (const std::string& token : result) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}