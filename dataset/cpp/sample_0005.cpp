#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> process_document(const std::string& text, int max_tokens = 100) {
    std::regex word_regex("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
        if (tokens.size() >= max_tokens) {
            break;
        }
    }
    return tokens;
}

int main() {
    std::string doc = "This is a sample document for parsing and tokenization.";
    std::vector<std::string> result = process_document(doc);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}