#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string& text, int pos = 0, std::vector<std::string>& tokens = *new std::vector<std::string>()) {
    if (pos >= text.length()) {
        tokenize(text, pos, tokens);
    } else if (isalnum(text[pos])) {
        int start = pos;
        while (pos < text.length() && isalnum(text[pos])) {
            pos += 1;
        }
        tokens.push_back(text.substr(start, pos - start));
    } else {
        pos += 1;
    }
    return tokenize(text, pos, tokens);
}

int main() {
    std::string text = "This is a test document for tokenization.";
    std::vector<std::string> result = tokenize(text);
    for (const auto& token : result) {
        std::cout << token << std::endl;
    }
    return 0;
}