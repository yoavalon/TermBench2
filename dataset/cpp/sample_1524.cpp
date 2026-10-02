cpp
#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> parse_and_tokenize(const std::string& text) {
    std::regex tokenizer(R"(\\b\\w+\\b)");
    std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), tokenizer);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
    }
    return tokens;
}

void main() {
    std::string sample_text = "This is a sample text for parsing and tokenization.";
    while (true) {
        std::vector<std::string> tokens = parse_and_tokenize(sample_text);
        for (const auto& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}