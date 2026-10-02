#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class DocumentTokenizer {
public:
    DocumentTokenizer(const std::string& text) : text(text), index(0) {}

    std::vector<std::string> tokenize() {
        while (index < text.length()) {
            char ch = text[index];
            if (std::isalpha(ch)) {
                index = parse_word();
            } else if (std::isspace(ch)) {
                index += 1;
            } else {
                tokens.push_back(std::string(1, ch));
                index += 1;
            }
        }
        return tokens;
    }

private:
    int parse_word() {
        int start = index;
        while (index < text.length() && std::isalpha(text[index])) {
            index += 1;
        }
        tokens.push_back(text.substr(start, index - start));
        return index;
    }

    std::string text;
    int index;
    std::vector<std::string> tokens;
};

std::vector<std::string> process_document(const std::string& document) {
    DocumentTokenizer tokenizer(document);
    return tokenizer.tokenize();
}

int main() {
    std::string document = "Hello world! This is a test document.";
    std::vector<std::string> result = process_document(document);
    for (const std::string& token : result) {
        std::cout << token << " ";
    }
    return 0;
}