#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text), tokens() {}

    std::vector<std::string> tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        std::sregex_iterator words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();
            tokens.push_back(match_str);
        }
        return tokens;
    }

    std::vector<std::string> filter_tokens(int min_length) {
        std::vector<std::string> filtered_tokens;
        for (const auto& token : tokens) {
            if (token.length() >= min_length) {
                filtered_tokens.push_back(token);
            }
        }
        tokens = filtered_tokens;
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class TokenAnalyzer {
public:
    TokenAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens), analysis() {}

    std::unordered_map<std::string, int> count_tokens() {
        for (const auto& token : tokens) {
            analysis[token]++;
        }
        return analysis;
    }

    std::unordered_map<std::string, int> update_analysis(const std::vector<std::string>& new_tokens) {
        for (const auto& token : new_tokens) {
            analysis[token]++;
        }
        return analysis;
    }

private:
    std::vector<std::string> tokens;
    std::unordered_map<std::string, int> analysis;
};

class DataProcessor {
public:
    DataProcessor(DocumentParser& parser, TokenAnalyzer& analyzer) : parser(parser), analyzer(analyzer) {}

    std::unordered_map<std::string, int> process() {
        parser.tokenize();
        analyzer.count_tokens();
        return analyzer.analysis;
    }

private:
    DocumentParser& parser;
    TokenAnalyzer& analyzer;
};

int main() {
    std::string text = "In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.";
    DocumentParser parser(text);
    TokenAnalyzer analyzer({});
    DataProcessor processor(parser, analyzer);
    while (true) {
        auto analysis = processor.process();
        for (const auto& pair : analysis) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        analyzer.update_analysis({"precision", "Python", "interest", "galaxy"});
        for (const auto& pair : analyzer.analysis) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
    return 0;
}