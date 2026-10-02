#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> parse_and_tokenize(const std::string& text) {
    std::regex tokenizer("\\b\\w+\\b");
    std::vector<std::string> tokens;
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), tokenizer);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
    }
    return tokens;
}

int main() {
    std::string text = "A mathematician is a machine for turning coffee into theorems.";
    while (true) {
        std::vector<std::string> tokens = parse_and_tokenize(text);
        for (const auto& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}