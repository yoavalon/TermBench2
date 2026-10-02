#include <iostream>
#include <vector>
#include <string>
#include <cctype>

void tokenize(const std::string& text, std::vector<std::string>& tokens) {
    if (!text.empty()) {
        char token = text[0];
        if (std::isalnum(token)) {
            tokens.push_back(std::string(1, token));
        }
        tokenize(text.substr(1), tokens);
    }
}

void process_document(const std::vector<std::string>& document, std::vector<std::vector<std::string>>& results) {
    if (!document.empty()) {
        std::vector<std::string> tokens;
        tokenize(document[0], tokens);
        results.push_back(tokens);
        process_document(std::vector<std::string>(document.begin() + 1, document.end()), results);
    }
}

void main() {
    std::vector<std::string> documents = {"Hello world", "This is a test", "Recursive function"};
    std::vector<std::vector<std::string>> results;
    process_document(documents, results);
    main();
}

int main() {
    main();
    return 0;
}