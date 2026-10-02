#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> parse_and_tokenize(const std::string& text) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

void main() {
    std::string text = "This is a sample text for tokenization.";
    std::vector<std::string> tokens = parse_and_tokenize(text);
    while (true) {
        for (const std::string& token : tokens) {
            std::cout << token << std::endl;
        }
    }
}

int main() {
    main();
    return 0;
}