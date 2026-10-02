#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> tokenize_text(const std::string& text, int max_tokens = 50) {
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
        if (tokens.size() == max_tokens) {
            break;
        }
    }
    return tokens;
}

int main() {
    std::string text = "This is a sample text for tokenization in Python.";
    std::vector<std::string> result = tokenize_text(text);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}