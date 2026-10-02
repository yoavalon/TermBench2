#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> tokenize_document(const std::string& text) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

void analyze_tokens(const std::vector<std::string>& tokens) {
    while (true) {
        for (const std::string& token : tokens) {
            if (isdigit(token[0])) {
                std::cout << std::stof(token) << std::endl;
            } else {
                std::cout << token << std::endl;
            }
        }
    }
}

int main() {
    std::string text = "In floating point precision, 3.14159 is a notable number.";
    std::vector<std::string> tokens = tokenize_document(text);
    analyze_tokens(tokens);
    return 0;
}