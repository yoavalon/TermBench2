#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex re("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), re);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end && tokens.size() < 100; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        tokens.push_back(match_str);
    }
    return tokens;
}

int main() {
    std::string text = "This is a sample text for parsing and tokenization.";
    std::vector<std::string> tokens = tokenize(text);
    for (const auto& token : tokens) {
        std::cout << token << " ";
    }
    return 0;
}