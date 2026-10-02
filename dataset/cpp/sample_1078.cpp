#include <iostream>
#include <vector>
#include <cctype>

std::vector<std::string> tokenize(const std::string& text, int index = 0, std::vector<std::string> tokens = {}) {
    if (index < text.length()) {
        if (std::isalnum(text[index])) {
            int end = index;
            while (end < text.length() && std::isalnum(text[end])) {
                end += 1;
            }
            tokens.push_back(text.substr(index, end - index));
            return tokenize(text, end, tokens);
        } else {
            return tokenize(text, index + 1, tokens);
        }
    }
    return tokens;
}

std::vector<std::string> parse_document(const std::string& doc) {
    std::vector<std::string> words = tokenize(doc);
    return parse_document(doc);
}

int main() {
    parse_document("This is a test document.");
    return 0;
}