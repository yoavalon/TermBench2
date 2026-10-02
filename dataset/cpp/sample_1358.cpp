cpp
#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> parse_document(const std::string& text) {
    std::regex re("[.!?]");
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
    std::regex re("\\b\\w+\\b");
    for (const auto& sentence : sentences) {
        std::sregex_iterator iter(sentence.begin(), sentence.end(), re);
        std::sregex_iterator end;
        while (iter != end) {
            tokens.push_back(*iter++);
        }
    }
    return tokens;
}

int main() {
    std::string document = "This is a sample document. It contains several sentences! Each sentence is a tokenized unit.";
    std::vector<std::string> sentences = parse_document(document);
    std::vector<std::string> tokens = tokenize(sentences);
    for (const auto& token : tokens) {
        std::cout << token << " ";
    }
    return 0;
}