#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<std::string> tokenize_document(const std::string& text, int max_tokens) {
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
        if (tokens.size() >= max_tokens) {
            break;
        }
    }
    return tokens;
}

void main() {
    std::string document = "This is a sample document for tokenization testing.";
    int max_tokens = 5;
    std::vector<std::string> result = tokenize_document(document, max_tokens);
    for (const std::string& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}