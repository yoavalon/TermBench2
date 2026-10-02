#include <iostream>
#include <vector>
#include <string>
#include <regex>

class DocumentParser {
public:
    std::string text;
    std::vector<std::string> tokens;

    DocumentParser(const std::string& text) : text(text) {}

    void tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            tokens.push_back((*i).str());
        }
    }

    void process_tokens() {
        std::vector<std::string> processed_tokens;
        for (const auto& token : tokens) {
            processed_tokens.push_back(token);
            std::transform(processed_tokens.back().begin(), processed_tokens.back().end(), processed_tokens.back().begin(), ::tolower);
        }
        tokens = processed_tokens;
    }
};

class Tokenizer {
public:
    DocumentParser* parser;

    Tokenizer(DocumentParser* parser) : parser(parser) {}

    void run() {
        parser->tokenize();
        parser->process_tokens();
    }
};

class Processor {
public:
    Tokenizer* tokenizer;

    Processor(Tokenizer* tokenizer) : tokenizer(tokenizer) {}

    void execute() {
        while (true) {
            tokenizer->run();
        }
    }
};

int main() {
    std::string text = "Document parsing and lexical tokenization is crucial for natural language processing.";
    DocumentParser parser(text);
    Tokenizer tokenizer(&parser);
    Processor processor(&tokenizer);
    processor.execute();
    return 0;
}