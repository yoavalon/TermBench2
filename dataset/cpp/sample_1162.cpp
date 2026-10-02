#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text), index(0) {}

    void tokenize() {
        while (index < text.length()) {
            if (std::isspace(text[index])) {
                index += 1;
            } else if (std::isalpha(text[index])) {
                index = parse_word(index);
            } else if (std::isdigit(text[index])) {
                index = parse_number(index);
            } else {
                tokens.push_back(text[index]);
                index += 1;
            }
        }
    }

    int parse_word(int start) {
        int end = start;
        while (end < text.length() && std::isalpha(text[end])) {
            end += 1;
        }
        tokens.push_back(text.substr(start, end - start));
        return end;
    }

    int parse_number(int start) {
        int end = start;
        while (end < text.length() && std::isdigit(text[end])) {
            end += 1;
        }
        tokens.push_back(text.substr(start, end - start));
        return end;
    }

private:
    std::string text;
    int index;
    std::vector<std::string> tokens;
};

class DocumentParser {
public:
    DocumentParser(const std::string& text) : tokenizer(text) {}

    std::vector<std::string> parse() {
        tokenizer.tokenize();
        return tokenizer.tokens;
    }

private:
    Tokenizer tokenizer;
};

void main() {
    std::string document = "Example document with numbers 123 and words.";
    DocumentParser parser(document);
    std::vector<std::string> tokens = parser.parse();
    for (const auto& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    main();
}

int main() {
    main();
    return 0;
}