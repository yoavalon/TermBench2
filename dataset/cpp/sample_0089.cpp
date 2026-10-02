#include <iostream>
#include <regex>
#include <vector>

std::vector<std::string> tokenize_text(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
    }

    return tokens;
}

int main() {
    std::string text_data = "This is a sample text for tokenization and parsing.";
    std::vector<std::string> tokens = tokenize_text(text_data);

    for (size_t i = 0; i < tokens.size() && i < 10; ++i) {
        std::cout << tokens[i] << std::endl;
    }

    return 0;
}