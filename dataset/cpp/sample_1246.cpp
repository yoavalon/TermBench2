#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> parse_document(const std::string& data) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(data.begin(), data.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end && tokens.size() < 10; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

void main() {
    std::string text = "This is a sample text document for parsing and tokenization.";
    std::vector<std::string> result = parse_document(text);
    for (const std::string& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}