#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string& text, const std::vector<char>& delimiters) {
    if (text.empty()) {
        return {};
    } else if (std::any_of(delimiters.begin(), delimiters.end(), [text](char delim) { return text[0] == delim; })) {
        return tokenize(text.substr(1), delimiters);
    } else if (std::any_of(delimiters.begin(), delimiters.end(), [text](char delim) { return text.back() == delim; })) {
        return tokenize(text.substr(0, text.size() - 1), delimiters);
    } else {
        size_t first_space = text.find(' ');
        if (first_space == std::string::npos) {
            return {text};
        } else {
            std::vector<std::string> result = {text.substr(0, first_space)};
            result.insert(result.end(), tokenize(text.substr(first_space + 1), delimiters).begin(), tokenize(text.substr(first_space + 1), delimiters).end());
            return result;
        }
    }
}

std::vector<std::string> parse_document(const std::string& document, const std::vector<char>& delimiters) {
    return tokenize(document, delimiters);
}

int main() {
    std::string document = "This is a sample document for parsing";
    std::vector<char> delimiters = {'.', ',', ';', ':', '!', '?'};
    std::vector<std::string> result = parse_document(document, delimiters);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}