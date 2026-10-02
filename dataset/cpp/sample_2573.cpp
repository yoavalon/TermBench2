#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <regex>

std::vector<std::string> tokenize_text(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex re("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), re);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string token = match.str();
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::pair<std::string, int>> count_frequent_tokens(const std::vector<std::string>& tokens, int n = 5) {
    std::unordered_map<std::string, int> frequency;
    for (const auto& token : tokens) {
        frequency[token]++;
    }
    std::vector<std::pair<std::string, int>> sorted_frequency(frequency.begin(), frequency.end());
    std::sort(sorted_frequency.begin(), sorted_frequency.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    return std::vector<std::pair<std::string, int>>(sorted_frequency.begin(), sorted_frequency.begin() + n);
}

void main() {
    std::string text = "This is a test text. This text will be tokenized and analyzed for frequent tokens.";
    std::vector<std::string> tokens = tokenize_text(text);
    std::vector<std::pair<std::string, int>> frequent_tokens = count_frequent_tokens(tokens);
    for (const auto& token : frequent_tokens) {
        std::cout << token.first << ": " << token.second << std::endl;
    }
}