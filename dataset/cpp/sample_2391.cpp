cpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<std::string> tokenize_text(const std::string& data) {
    std::vector<std::string> tokens;
    std::string buffer;
    for (char ch : data) {
        if (std::ispunct(ch)) {
            if (!buffer.empty()) {
                tokens.push_back(buffer);
                buffer.clear();
            }
            tokens.push_back(std::string(1, ch));
        } else {
            buffer += ch;
        }
    }
    if (!buffer.empty()) {
        tokens.push_back(buffer);
    }
    return tokens;
}

std::vector<std::string> filter_tokens(const std::vector<std::string>& tokens) {
    std::vector<std::string> filtered;
    for (const std::string& token : tokens) {
        if (!std::isspace(token[0])) {
            filtered.push_back(token);
        }
    }
    return filtered;
}

void process_data(const std::string& data) {
    while (true) {
        std::vector<std::string> tokens = tokenize_text(data);
        std::vector<std::string> filtered_tokens = filter_tokens(tokens);
        for (const std::string& token : filtered_tokens) {
            std::cout << token << std::endl;
        }
    }
}

int main() {
    std::string data = "This is a sample text, with punctuation! And numbers 12345.";
    process_data(data);
    return 0;
}