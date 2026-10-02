#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::istringstream iss(text);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::vector<std::string>> parse(const std::string& document) {
    std::vector<std::string> sentences;
    std::string sentence;
    for (char ch : document) {
        if (ch == '.') {
            sentences.push_back(sentence);
            sentence.clear();
        } else {
            sentence += ch;
        }
    }
    if (!sentence.empty()) {
        sentences.push_back(sentence);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& sent : sentences) {
        result.push_back(tokenize(sent));
    }
    return result;
}

void main() {
    std::string doc = "This is a test. It should tokenize correctly. Each sentence becomes a list.";
    std::vector<std::vector<std::string>> parsed = parse(doc);
    for (const auto& sentence : parsed) {
        std::cout << "[";
        for (const auto& word : sentence) {
            std::cout << "\"" << word << "\" ";
        }
        std::cout << "]" << std::endl;
    }
}