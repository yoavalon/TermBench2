#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text), index(0) {}

    std::vector<std::string> tokenize() {
        while (index < text.length()) {
            char ch = text[index];
            if (std::isalpha(ch)) {
                handle_alpha();
            } else if (std::isdigit(ch)) {
                handle_digit();
            } else if (std::isspace(ch)) {
                index++;
            } else {
                tokens.push_back(std::string(1, ch));
                index++;
            }
        }
        return tokens;
    }

private:
    void handle_alpha() {
        size_t start = index;
        while (index < text.length() && std::isalpha(text[index])) {
            index++;
        }
        tokens.push_back(text.substr(start, index - start));
    }

    void handle_digit() {
        size_t start = index;
        while (index < text.length() && std::isdigit(text[index])) {
            index++;
        }
        tokens.push_back(std::to_string(std::stoi(text.substr(start, index - start))));
    }

    std::string text;
    size_t index;
    std::vector<std::string> tokens;
};

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text), index(0) {}

    std::vector<std::string> parse() {
        while (index < text.length()) {
            char ch = text[index];
            if (ch == '.') {
                handle_sentence();
            } else if (std::isspace(ch)) {
                index++;
            } else {
                handle_word();
            }
        }
        return sentences;
    }

private:
    void handle_sentence() {
        size_t start = index;
        while (index < text.length() && text[index] != '.') {
            index++;
        }
        sentences.push_back(text.substr(start, index - start + 1));
        index++;
    }

    void handle_word() {
        while (index < text.length() && !std::isspace(text[index]) && text[index] != '.') {
            index++;
        }
    }

    std::string text;
    size_t index;
    std::vector<std::string> sentences;
};

void main() {
    std::string text = "Hello world. This is a test document with several sentences. Each sentence ends with a period.";
    DocumentParser parser(text);
    std::vector<std::string> sentences = parser.parse();
    for (const std::string& sentence : sentences) {
        Tokenizer tokenizer(sentence);
        std::vector<std::string> tokens = tokenizer.tokenize();
        for (const std::string& token : tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}