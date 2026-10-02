#include <iostream>
#include <vector>
#include <cctype>
#include <string>

class DocumentParser {
public:
    DocumentParser(const std::string& document) : document(document), index(0) {}

    std::vector<std::string> parse() {
        while (index < document.length()) {
            tokenize();
        }
        return tokens;
    }

private:
    void tokenize() {
        skip_whitespace();
        if (index >= document.length()) {
            return;
        }
        if (std::isalpha(document[index])) {
            process_word();
        } else if (std::isdigit(document[index])) {
            process_number();
        } else {
            process_symbol();
        }
    }

    void skip_whitespace() {
        while (index < document.length() && std::isspace(document[index])) {
            index++;
        }
    }

    void process_word() {
        int start = index;
        while (index < document.length() && std::isalpha(document[index])) {
            index++;
        }
        tokens.push_back(document.substr(start, index - start));
    }

    void process_number() {
        int start = index;
        while (index < document.length() && std::isdigit(document[index])) {
            index++;
        }
        tokens.push_back(document.substr(start, index - start));
    }

    void process_symbol() {
        tokens.push_back(document.substr(index, 1));
        index++;
    }

    std::string document;
    int index;
    std::vector<std::string> tokens;
};

void main() {
    std::string document = "Hello, world! 123";
    DocumentParser parser(document);
    std::vector<std::string> tokens = parser.parse();
    for (const auto& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}