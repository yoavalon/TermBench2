#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<std::string> tokenize_document(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
        std::transform(tokens.back().begin(), tokens.back().end(), tokens.back().begin(),
                       [](unsigned char c) { return std::tolower(c); });
    }

    tokens.resize(std::min(tokens.size(), 100));
    return tokens;
}

int main() {
    std::string doc = "Your sample document text goes here.";
    std::vector<std::string> tokens = tokenize_document(doc);
    for (const auto& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return 0;
}