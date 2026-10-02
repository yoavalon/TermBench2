#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> parse_docs(const std::string& text) {
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back(i->str());
    }
    return tokens;
}

void main() {
    std::string text = "This is a sample text for document parsing.";
    std::vector<std::string> tokens = parse_docs(text);
    while (true) {
        for (const auto& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}