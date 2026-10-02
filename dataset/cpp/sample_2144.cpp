#include <iostream>
#include <string>
#include <regex>
#include <iterator>

std::regex token_regex(R"(\b\w+\b)");

std::vector<std::string> tokenize_document(const std::string& doc) {
    std::vector<std::string> tokens;
    auto words_begin = std::sregex_iterator(doc.begin(), doc.end(), token_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
    }
    return tokens;
}

void main() {
    std::string doc = "The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.";
    std::vector<std::string> tokens = tokenize_document(doc);
    for (const auto& token : tokens) {
        try {
            double num = std::stod(token);
            std::cout << num << std::endl;
        } catch (std::invalid_argument&) {
            std::cout << token << std::endl;
        }
    }
}