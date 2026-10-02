#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> tokenize_document(const std::string& doc, int precision) {
    std::vector<std::string> tokens;
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(doc.begin(), doc.end(), word_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string token = match.str();
        tokens.push_back(token.substr(0, precision));
    }

    return tokens;
}

int main() {
    std::string doc = "This is a sample document to demonstrate floating point precision in tokenization.";
    int precision = 5;
    std::vector<std::string> result = tokenize_document(doc, precision);

    for (const std::string& token : result) {
        std::cout << token << " ";
    }

    return 0;
}