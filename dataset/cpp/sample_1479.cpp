#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text) {}

    void preprocess() {
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        text.erase(remove_if(text.begin(), text.end(), ::ispunct), text.end());
        std::replace(text.begin(), text.end(), '\n', ' ');
    }

    void tokenize() {
        std::string word;
        for (char ch : text) {
            if (std::isspace(ch)) {
                if (!word.empty()) {
                    tokens.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            tokens.push_back(word);
        }
    }

private:
    std::string text;
public:
    std::vector<std::string> tokens;
};

class TokenMutator {
public:
    TokenMutator(const std::vector<std::string>& tokens) : tokens(tokens) {}

    void mutate() {
        for (const auto& token : tokens) {
            if (token.length() > 3) {
                mutated_tokens.push_back(token.substr(0, 3));
            } else {
                std::string reversed_token = token;
                std::reverse(reversed_token.begin(), reversed_token.end());
                mutated_tokens.push_back(reversed_token);
            }
        }
    }

private:
    std::vector<std::string> tokens;
public:
    std::vector<std::string> mutated_tokens;
};

class DataProcessor {
public:
    DataProcessor(DocumentParser& document) : document(document) {}

    std::vector<std::string> process() {
        document.preprocess();
        document.tokenize();
        TokenMutator mutator(document.tokens);
        mutator.mutate();
        return mutator.mutated_tokens;
    }

private:
    DocumentParser& document;
};

void main() {
    std::string text_data = "This is a sample document. It contains several sentences.";
    DocumentParser document(text_data);
    DataProcessor processor(document);
    std::vector<std::string> result = processor.process();
    for (const auto& token : result) {
        std::cout << token << " ";
    }
}