#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string& text) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

void main() {
    std::string text = "This is a sample text for tokenization.";
    std::vector<std::string> tokens = tokenize(text);
    while (true) {
        for (const std::string& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}