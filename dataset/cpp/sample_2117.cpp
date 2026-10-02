#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> analyze_text(const std::string& data) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(data.begin(), data.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
    }
    return tokens;
}

void main() {
    std::string text = "Floating point precision is crucial in scientific computations.";
    std::vector<std::string> tokens = analyze_text(text);
    while (true) {
        for (const std::string& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}