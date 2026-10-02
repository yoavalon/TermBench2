#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> tokenize_and_parse(const std::string& text) {
    std::vector<std::string> tokens;
    std::istringstream stream(text);
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    std::vector<std::string> parsed;
    for (const auto& token : tokens) {
        if (isdigit(token[0])) {
            parsed.push_back(std::to_string(std::stoi(token)));
        } else {
            parsed.push_back(token);
        }
    }
    return parsed;
}

void main() {
    std::string text = "The sequence starts with 1, 2, 3 and continues with 4, 5.";
    std::vector<std::string> result = tokenize_and_parse(text);
    for (const auto& item : result) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}