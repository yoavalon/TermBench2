#include <iostream>
#include <vector>
#include <cctype>

class DocumentTokenizer {
public:
    DocumentTokenizer(const std::string& text) : text(text), tokens() {}

    void tokenize() {
        for (char char : text) {
            if (std::isalnum(char) || std::isspace(char)) {
                tokens.push_back(char);
            } else {
                tokens.push_back(' ');
            }
        }
    }

    void filter_tokens() {
        std::vector<std::string> filtered_tokens;
        std::string word;
        for (char token : tokens) {
            if (std::isalnum(token)) {
                word += token;
            } else if (std::isspace(token) && !word.empty()) {
                filtered_tokens.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            filtered_tokens.push_back(word);
        }
        tokens = filtered_tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class DataMutator {
public:
    DataMutator(DocumentTokenizer& tokenizer) : tokenizer(tokenizer) {}

    void mutate() {
        tokenizer.tokenize();
        tokenizer.filter_tokens();
        tokens = tokenizer.tokens;
    }

private:
    DocumentTokenizer& tokenizer;
    std::vector<std::string> tokens;
};

void main() {
    std::string text = "Hello, world! This is a test.";
    DocumentTokenizer tokenizer(text);
    DataMutator mutator(tokenizer);
    mutator.mutate();
    for (const std::string& token : mutator.tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}