#include <iostream>
#include <string>
#include <vector>
#include <regex>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text) {}

    std::vector<std::string> tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            tokens.push_back((*i).str());
        }
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text), tokenizer(text) {}

    std::vector<std::string> parse() {
        return tokenizer.tokenize();
    }

private:
    std::string text;
    Tokenizer tokenizer;
};

class PrecisionAnalyzer {
public:
    PrecisionAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens) {}

    int analyze() {
        int float_count = 0;
        for (const auto& token : tokens) {
            if (is_float(token)) {
                ++float_count;
            }
        }
        return float_count;
    }

private:
    std::vector<std::string> tokens;

    bool is_float(const std::string& token) {
        try {
            std::stof(token);
            return true;
        } catch (const std::invalid_argument& e) {
            return false;
        }
    }
};

void main() {
    std::string text = "The price of the item is 19.99 and the discount is 0.25.";
    DocumentParser parser(text);
    std::vector<std::string> tokens = parser.parse();
    PrecisionAnalyzer analyzer(tokens);
    int result = analyzer.analyze();
    std::cout << "Number of floating-point numbers: " << result << std::endl;
}

int main() {
    main();
    return 0;
}