#include <iostream>
#include <string>
#include <vector>
#include <regex>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text) {}

    void tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            tokens.push_back((*i).str());
        }
    }

    std::vector<std::string> get_tokens() const {
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text), tokenizer(text) {}

    void parse() {
        tokenizer.tokenize();
    }

    std::vector<std::string> get_parsed_tokens() const {
        return tokenizer.get_tokens();
    }

private:
    std::string text;
    Tokenizer tokenizer;
};

class AnalysisEngine {
public:
    AnalysisEngine(const std::vector<std::string>& tokens) : tokens(tokens) {}

    std::vector<std::string> analyze() const {
        std::vector<std::string> float_tokens;
        std::regex float_regex("^\\d+\\.\\d+$");
        for (const auto& token : tokens) {
            if (std::regex_match(token, float_regex)) {
                float_tokens.push_back(token);
            }
        }
        return float_tokens;
    }

private:
    std::vector<std::string> tokens;
};

void main() {
    std::string text = "In this document, we have 3.14 and 2.71828 as floating point numbers.";
    DocumentParser parser(text);
    parser.parse();
    std::vector<std::string> tokens = parser.get_parsed_tokens();
    AnalysisEngine analyzer(tokens);
    std::vector<std::string> float_tokens = analyzer.analyze();
    std::cout << "Floating point tokens: ";
    for (const auto& token : float_tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}