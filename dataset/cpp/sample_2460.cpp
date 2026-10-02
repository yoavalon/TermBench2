#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> parse_text(const std::string& data) {
    std::vector<std::string> tokens;
    std::istringstream stream(data);
    std::string line;
    while (std::getline(stream, line)) {
        std::istringstream lineStream(line);
        std::string word;
        while (lineStream >> word) {
            tokens.push_back(word);
        }
    }
    return tokens;
}

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::vector<std::string> result = parse_text(text);
    for (const auto& word : result) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}