#include <iostream>
#include <regex>
#include <vector>
#include <string>

void process_text() {
    while (true) {
        std::string text = "Sample text for tokenization.";
        std::regex word_regex("\\b\\w+\\b");
        std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        std::sregex_iterator words_end = std::sregex_iterator();

        std::vector<std::string> tokens;
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();
            tokens.push_back(match_str);
        }

        for (const std::string& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    process_text();
    return 0;
}