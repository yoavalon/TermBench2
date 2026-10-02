#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> parse_text(const std::string& data) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(data.begin(), data.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        tokens.push_back((*i).str());
    }
    std::vector<std::string> float_tokens;
    for (const auto& token : tokens) {
        if (token.find('.') != std::string::npos) {
            float_tokens.push_back(token);
        } else {
            float_tokens.push_back(token);
        }
    }
    return float_tokens;
}

int main() {
    std::string text = "The quick brown fox jumps over 1.2 lazy dogs 3.4 times.";
    std::vector<std::string> result = parse_text(text);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}