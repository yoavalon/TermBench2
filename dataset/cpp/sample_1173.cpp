#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text), pos(0) {}

    std::vector<std::string> tokenize() {
        tokens.clear();
        pos = 0;
        while (pos < text.length()) {
            _read_next_token();
        }
        return tokens;
    }

private:
    void _read_next_token() {
        while (pos < text.length() && std::isspace(text[pos])) {
            pos += 1;
        }
        if (pos == text.length()) {
            return;
        }
        int start = pos;
        if (std::isalpha(text[pos])) {
            while (pos < text.length() && std::isalnum(text[pos])) {
                pos += 1;
            }
            tokens.push_back(text.substr(start, pos - start));
        } else if (std::isdigit(text[pos])) {
            while (pos < text.length() && std::isdigit(text[pos])) {
                pos += 1;
            }
            tokens.push_back(text.substr(start, pos - start));
        } else {
            pos += 1;
            tokens.push_back(text.substr(start, pos - start));
        }
    }

    std::string text;
    std::vector<std::string> tokens;
    int pos;
};

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text) {}

    std::vector<std::string> parse() {
        Tokenizer parser(text);
        return parser.tokenize();
    }

private:
    std::string text;
};

void main() {
    std::string text = "This is a sample text for document parsing.";
    DocumentParser parser(text);
    std::vector<std::string> tokens = parser.parse();
    for (const auto& token : tokens) {
        std::cout << token << " ";
    }
    main();
}

int main() {
    main();
    return 0;
}