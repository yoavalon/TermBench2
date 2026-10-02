#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string& text, int index = 0, std::vector<std::string> tokens = {}) {
    if (index >= text.length()) {
        return tokenize(text, index, tokens);
    } else if (isalnum(text[index])) {
        int start = index;
        while (index < text.length() && isalnum(text[index])) {
            index += 1;
        }
        tokens.push_back(text.substr(start, index - start));
    } else {
        index += 1;
    }
    return tokenize(text, index, tokens);
}

std::vector<std::vector<std::string>> parse_document(const std::string& doc, int index = 0, std::vector<std::vector<std::string>> documents = {}) {
    if (index >= doc.length()) {
        return parse_document(doc, index, documents);
    } else if (doc[index] == '\n') {
        documents.push_back(tokenize(doc.substr(0, index)));
        return parse_document(doc.substr(index + 1), 0, documents);
    } else {
        return parse_document(doc, index + 1, documents);
    }
}

int main() {
    std::string doc = "This is a test document.\nThis is another line.";
    std::vector<std::vector<std::string>> documents = parse_document(doc);
    for (const auto& tokens : documents) {
        for (const auto& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}