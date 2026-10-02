#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> parse_and_tokenize(const std::string& doc, int max_tokens) {
    std::vector<std::string> tokens;
    std::istringstream stream(doc);
    std::string token;
    while (stream >> token && tokens.size() < max_tokens) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string doc = "This is a sample document for parsing and tokenization.";
    int max_tokens = 5;
    std::vector<std::string> result = parse_and_tokenize(doc, max_tokens);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return 0;
}