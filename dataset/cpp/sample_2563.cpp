#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

std::vector<std::string> tokenize_text(const std::string& text) {
    std::vector<std::string> words;
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        words.push_back(word);
    }
    std::vector<std::string> tokens;
    for (const auto& word : words) {
        std::string token;
        for (char c : word) {
            token += std::tolower(c);
        }
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<int> process_tokens(const std::vector<std::string>& tokens) {
    std::vector<int> numeric_tokens;
    for (const auto& token : tokens) {
        if (std::isdigit(token[0])) {
            numeric_tokens.push_back(std::stoi(token));
        }
    }
    return numeric_tokens;
}

int main() {
    std::string text = "The sequence starts with 1, 2, 3 and continues with 4, 5, 6.";
    std::vector<std::string> tokens = tokenize_text(text);
    std::vector<int> numbers = process_tokens(tokens);
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    return 0;
}