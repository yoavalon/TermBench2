#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> parse_text(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string token = match.str();
        tokens.push_back(token);
    }

    std::vector<std::string> float_tokens;
    std::regex float_regex("^\\d+\\.\\d+$");
    for (const auto& token : tokens) {
        if (std::regex_match(token, float_regex)) {
            float_tokens.push_back(token);
        }
    }
    return float_tokens;
}

int main() {
    std::string text = "The value of pi is approximately 3.14159. The number 2.71828 is also important.";
    std::vector<std::string> result = parse_text(text);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}