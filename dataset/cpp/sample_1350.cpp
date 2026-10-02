#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> parse_document(const std::string& text) {
    std::regex re("(?<=[.!?]) +");
    std::sregex_token_iterator iter(text.begin(), text.end(), re, -1);
    std::sregex_token_iterator end;
    std::vector<std::string> sentences;
    while (iter != end) {
        sentences.push_back(*iter++);
    }
    return sentences;
}

std::vector<std::string> tokenize(const std::vector<std::string>& sentences) {
    std::vector<std::string> tokens;
    for (const auto& sentence : sentences) {
        std::istringstream stream(sentence);
        std::string word;
        while (stream >> word) {
            tokens.push_back(word);
        }
    }
    return tokens;
}

int main() {
    std::string text = "Hello world! This is a test document.";
    std::vector<std::string> sentences = parse_document(text);
    std::vector<std::string> tokens = tokenize(sentences);
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }
    return 0;
}