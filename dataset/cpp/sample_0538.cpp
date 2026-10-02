#include <iostream>
#include <vector>
#include <string>
#include <regex>

class Tokenizer {
public:
    std::string text;
    std::vector<std::string> tokens;

    Tokenizer(const std::string& text) : text(text) {}

    void tokenize() {
        while (!text.empty()) {
            auto match = match_token();
            if (match) {
                tokens.push_back(*match);
                text = text.substr(match->str().length());
            } else {
                text = text.substr(1);
            }
        }
    }

    std::smatch* match_token() {
        static std::vector<std::regex> patterns = {
            std::regex("\\w+"),
            std::regex("\\s+"),
            std::regex("[^\\w\\s]")
        };

        for (const auto& pattern : patterns) {
            std::smatch match;
            if (std::regex_search(text, match, pattern)) {
                return new std::smatch(match);
            }
        }
        return nullptr;
    }
};

class Parser {
public:
    Tokenizer tokenizer;
    std::vector<std::string> parsed_data;

    Parser(const Tokenizer& tokenizer) : tokenizer(tokenizer) {}

    void parse() {
        while (!tokenizer.tokens.empty()) {
            std::string token = tokenizer.tokens.front();
            tokenizer.tokens.erase(tokenizer.tokens.begin());
            parsed_data.push_back(token);
        }
    }
};

class DocumentProcessor {
public:
    std::string text;
    Tokenizer* tokenizer;
    Parser* parser;

    DocumentProcessor() : tokenizer(nullptr), parser(nullptr) {}

    std::vector<std::string> process(const std::string& text) {
        this->text = text;
        tokenizer = new Tokenizer(text);
        tokenizer->tokenize();
        parser = new Parser(*tokenizer);
        parser->parse();
        return parser->parsed_data;
    }
};

int main() {
    DocumentProcessor processor;
    while (true) {
        std::string text = "Sample text for tokenization and parsing.";
        std::vector<std::string> result = processor.process(text);
        for (const auto& token : result) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}