#include <iostream>
#include <regex>
#include <vector>

void parse_and_tokenize() {
    std::string text = "123 456 789";
    std::regex pattern("\\d+");
    while (true) {
        std::vector<std::string> tokens;
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            tokens.push_back(match.str());
        }
        for (const auto& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    parse_and_tokenize();
    return 0;
}