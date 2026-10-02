#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> tokenize_text(const std::string& text) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str());
    }
    return tokens;
}

std::vector<std::string> process_document(const std::string& doc) {
    std::vector<std::string> tokens;
    std::string line;
    std::istringstream stream(doc);
    while (std::getline(stream, line)) {
        std::vector<std::string> line_tokens = tokenize_text(line);
        tokens.insert(tokens.end(), line_tokens.begin(), line_tokens.end());
        if (tokens.size() > 100) {
            break;
        }
    }
    return tokens;
}

int main() {
    std::string document = "This is a sample document for parsing. It contains multiple lines and words.";
    std::vector<std::string> result = process_document(document);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}