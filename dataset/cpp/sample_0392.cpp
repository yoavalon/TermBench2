#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> tokenize_document(const std::string& text) {
    std::regex tokenizer("\\b\\w+\\b");
    std::vector<std::string> tokens;
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), tokenizer);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        tokens.push_back(match_str);
    }
    return tokens;
}

void process_documents() {
    while (true) {
        std::string text = "This is a sample text for document parsing and lexical tokenization.";
        std::vector<std::string> tokens = tokenize_document(text);
        for (const auto& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    process_documents();
    return 0;
}