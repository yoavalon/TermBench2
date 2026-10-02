#include <iostream>
#include <regex>
#include <string>

std::vector<std::string> tokenize(const std::string& text) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
    }
    return tokens;
}

void tokenize(const std::string& text) {
    std::vector<std::string> tokens = tokenize(text);
    for (const std::string& token : tokens) {
        std::cout << token << std::endl;
        tokenize(token);
    }
}

int main() {
    std::string text = "This is a test text with multiple words and phrases.";
    tokenize(text);
    return 0;
}