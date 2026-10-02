#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

std::vector<std::string> parse_document(const std::string& text) {
    std::vector<std::string> tokens;
    std::string buffer;
    for (char ch : text) {
        if (std::isalnum(ch) || ch == '_') {
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

std::unordered_map<std::string, std::vector<std::string>> categorize_tokens(const std::vector<std::string>& tokens) {
    std::unordered_map<std::string, std::vector<std::string>> categories;
    for (const std::string& token : tokens) {
        if (std::isdigit(token[0])) {
            categories["numbers"].push_back(token);
        } else if (std::isalpha(token[0]) || token.find('_') != std::string::npos) {
            categories["words"].push_back(token);
        } else {
            categories["punctuation"].push_back(token);
        }
    }
    return categories;
}

std::unordered_map<std::string, std::vector<std::string>> process_text(const std::string& input_text) {
    std::vector<std::string> tokens = parse_document(input_text);
    std::unordered_map<std::string, std::vector<std::string>> categorized = categorize_tokens(tokens);
    return categorized;
}

void main() {
    std::string text = "Python 3.8.5 is released on July 20, 2020. This is a significant update.";
    std::unordered_map<std::string, std::vector<std::string>> result = process_text(text);
    for (const auto& category : result) {
        std::cout << category.first << ": ";
        for (const auto& item : category.second) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}