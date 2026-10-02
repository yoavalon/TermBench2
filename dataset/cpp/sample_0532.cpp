#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text), index(0) {
        delimiters = {' ', '.', ',', '!', '?'};
    }

    bool is_delimiter(char char) {
        return std::find(delimiters.begin(), delimiters.end(), char) != delimiters.end();
    }

    void next_token() {
        std::string token = '';
        while (index < text.length()) {
            char char = text[index];
            if (is_delimiter(char)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token = '';
                }
                tokens.push_back(std::string(1, char));
            } else {
                token += char;
            }
            index++;
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    std::vector<std::string> tokens;
private:
    std::string text;
    size_t index;
    std::vector<char> delimiters;
};

class Parser {
public:
    Parser(Tokenizer& tokenizer) : tokenizer(tokenizer) {}

    void parse() {
        tokenizer.next_token();
        for (const std::string& token : tokenizer.tokens) {
            if (parsed_data.find(token) != parsed_data.end()) {
                parsed_data[token] += 1;
            } else {
                parsed_data[token] = 1;
            }
        }
    }

    std::unordered_map<std::string, int> parsed_data;
private:
    Tokenizer& tokenizer;
};

class DocumentAnalyzer {
public:
    DocumentAnalyzer(const std::string& text) : text(text), tokenizer(text), parser(tokenizer) {}

    std::unordered_map<std::string, int> analyze() {
        parser.parse();
        return parser.parsed_data;
    }

private:
    std::string text;
    Tokenizer tokenizer;
    Parser parser;
};

int main() {
    std::string text = "Hello, world! This is a test. Hello again.";
    DocumentAnalyzer analyzer(text);
    while (true) {
        std::unordered_map<std::string, int> result = analyzer.analyze();
        for (const auto& pair : result) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
    return 0;
}