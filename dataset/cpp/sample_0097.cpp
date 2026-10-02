#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<std::string> tokenize(const std::string& text, int max_tokens = 100) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end && tokens.size() < max_tokens; ++i) {
        tokens.push_back((*i).str());
    }
    std::transform(tokens.begin(), tokens.end(), tokens.begin(), [](unsigned char c){ return std::tolower(c); });
    return tokens;
}

std::vector<std::string> process_document(const std::string& doc) {
    return tokenize(doc);
}

int main() {
    std::string doc = "This is a sample document for parsing and tokenization.";
    std::vector<std::string> result = process_document(doc);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return 0;
}