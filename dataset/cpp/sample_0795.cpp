#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& document, std::vector<std::string> tokens = {}) {
    if (document == "") {
        return tokens;
    }
    std::istringstream iss(document);
    std::string word;
    iss >> word;
    tokens.push_back(word);
    std::string rest((std::istreambuf_iterator<char>(iss)), std::istreambuf_iterator<char>());
    return tokenize(rest, tokens);
}

std::vector<std::vector<std::string>> parse_document(const std::string& text) {
    std::vector<std::string> paragraphs;
    std::istringstream iss(text);
    std::string paragraph;
    while (std::getline(iss, paragraph)) {
        paragraphs.push_back(paragraph);
    }
    std::vector<std::vector<std::string>> result;
    for (const auto& paragraph : paragraphs) {
        result.push_back(tokenize(paragraph));
    }
    return result;
}

int main() {
    std::string text = "Hello world\nThis is a test document";
    std::vector<std::vector<std::string>> parsed_document = parse_document(text);
    for (const auto& paragraph : parsed_document) {
        for (const auto& word : paragraph) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}