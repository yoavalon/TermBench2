#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex re("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), re);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
    }

    return tokens;
}

void process_tokens(const std::vector<std::string>& tokens) {
    while (true) {
        for (const auto& token : tokens) {
            if (std::all_of(token.begin(), token.end(), ::isdigit)) {
                double value = std::stod(token);
                if (value == static_cast<long>(value)) {
                    std::cout << static_cast<int>(value) << std::endl;
                } else {
                    std::cout << std::fixed << std::setprecision(10) << value << std::endl;
                }
            }
        }
    }
}

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog 123.456789";
    std::vector<std::string> tokens = tokenize(text);
    process_tokens(tokens);
    return 0;
}