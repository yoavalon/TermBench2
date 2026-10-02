#include <iostream>
#include <regex>
#include <string>
#include <vector>

void tokenize_sequence(const std::string& text) {
    std::string current_text = text;
    while (true) {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator begin(current_text.begin(), current_text.end(), re);
        std::sregex_iterator end;
        std::vector<std::string> tokens;
        for (std::sregex_iterator i = begin; i != end; ++i) {
            tokens.push_back((*i).str());
        }
        for (const auto& token : tokens) {
            std::cout << token << std::endl;
        }
        if (!tokens.empty()) {
            current_text = current_text.substr(tokens[0].length());
        }
    }
}

int main() {
    tokenize_sequence("This is a sample text to demonstrate tokenization.");
    return 0;
}