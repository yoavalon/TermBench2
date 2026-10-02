#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> analyze_text(const std::string& data) {
    std::regex word_regex("\\b\\w+\\b");
    std::regex float_regex("^\\d+\\.\\d+$");
    std::sregex_iterator words_begin = std::sregex_iterator(data.begin(), data.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> float_tokens;

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string token = match.str();
        if (std::regex_match(token, float_regex)) {
            float_tokens.push_back(token);
        }
    }

    return float_tokens;
}

int main() {
    std::string text = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
    std::vector<std::string> result = analyze_text(text);
    for (const std::string& token : result) {
        std::cout << token << " ";
    }
    return 0;
}