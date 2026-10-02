#include <iostream>
#include <vector>
#include <regex>

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

int main() {
    std::string text = "This is a sample text for document parsing and lexical tokenization.";
    std::vector<std::string> tokens = tokenize(text);
    for (int i = 0; i < 5; ++i) {
        std::cout << tokens[i] << std::endl;
    }
    return 0;
}