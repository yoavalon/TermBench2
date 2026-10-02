#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> parse_and_tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

int main() {
    std::string text = "This is a sample text for parsing and tokenization.";
    std::vector<std::string> tokens = parse_and_tokenize(text);
    for (const auto& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return 0;
}