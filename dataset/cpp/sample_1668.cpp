#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::string preprocess_text(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    result.erase(std::remove_if(result.begin(), result.end(), ::ispunct), result.end());
    return result;
}

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::string token;
    for (char ch : text) {
        if (std::isspace(ch)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    while (true) {
        std::string data = "Sample document for parsing and tokenization.";
        std::string processed_text = preprocess_text(data);
        std::vector<std::string> tokens = tokenize(processed_text);
        for (const std::string& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}