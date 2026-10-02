#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <map>

class TextProcessor {
public:
    std::string text;
    std::vector<std::string> tokens;

    TextProcessor(std::string text) : text(text) {}

    std::vector<std::string> tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            tokens.push_back(match.str());
        }
        return tokens;
    }

    std::vector<std::string> filter_tokens() {
        std::vector<std::string> filtered;
        for (const auto& token : tokens) {
            if (token.length() > 3) {
                filtered.push_back(token);
            }
        }
        return filtered;
    }
};

class NumericParser {
public:
    std::vector<std::string> tokens;
    std::vector<std::string> numeric_tokens;

    NumericParser(std::vector<std::string> tokens) : tokens(tokens) {}

    std::vector<std::string> extract_numeric() {
        std::regex numeric_regex("^\\d+(\\.\\d+)?$");
        for (const auto& token : tokens) {
            if (std::regex_match(token, numeric_regex)) {
                numeric_tokens.push_back(token);
            }
        }
        return numeric_tokens;
    }
};

class PrecisionAnalyzer {
public:
    std::vector<std::string> numeric_tokens;
    std::map<std::string, int> precision;

    PrecisionAnalyzer(std::vector<std::string> numeric_tokens) : numeric_tokens(numeric_tokens) {}

    std::map<std::string, int> analyze_precision() {
        for (const auto& token : numeric_tokens) {
            if (token.find('.') != std::string::npos) {
                precision[token] = token.substr(token.find('.') + 1).length();
            }
        }
        return precision;
    }
};

void main() {
    std::string text = "The quick brown fox jumps over the lazy dog 123.456 789.10 100.001";
    TextProcessor processor(text);
    std::vector<std::string> tokens = processor.tokenize();
    std::vector<std::string> filtered_tokens = processor.filter_tokens();
    NumericParser parser(filtered_tokens);
    std::vector<std::string> numeric_tokens = parser.extract_numeric();
    PrecisionAnalyzer analyzer(numeric_tokens);
    std::map<std::string, int> precision_results = analyzer.analyze_precision();
    for (const auto& pair : precision_results) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    main();
    return 0;
}