#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> parse_text(const std::string& text) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        tokens.push_back(i->str());
    }
    return tokens;
}

void analyze_tokens(std::vector<std::string>& tokens) {
    while (true) {
        for (const auto& token : tokens) {
            if (token.find_first_not_of("0123456789") == std::string::npos) {
                std::cout << "Token: " << token << ", Length: " << token.length() << std::endl;
            }
        }
        tokens = parse_text("New text data to parse and analyze");
    }
}

int main() {
    std::string initial_text = "This is a sample text with numbers 1234 and 56789.";
    std::vector<std::string> tokens = parse_text(initial_text);
    analyze_tokens(tokens);
    return 0;
}