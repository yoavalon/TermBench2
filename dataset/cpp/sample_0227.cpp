#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text), tokens() {
        process_text();
    }

    void process_text() {
        tokenize();
    }

    void tokenize() {
        std::string lower_text = text;
        std::transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
        std::string word;
        for (char c : lower_text) {
            if (isalnum(c)) {
                word += c;
            } else if (!word.empty()) {
                tokens.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            tokens.push_back(word);
        }
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class TokenAnalyzer {
public:
    TokenAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens), token_count() {
        analyze_tokens();
    }

    void analyze_tokens() {
        for (const std::string& token : tokens) {
            if (token_count.find(token) != token_count.end()) {
                token_count[token]++;
            } else {
                token_count[token] = 1;
            }
        }
    }

private:
    std::vector<std::string> tokens;
    std::unordered_map<std::string, int> token_count;
};

class ReportGenerator {
public:
    ReportGenerator(const std::unordered_map<std::string, int>& token_count) : token_count(token_count), report() {
        generate_report();
    }

    void generate_report() {
        std::vector<std::pair<std::string, int>> sorted_token_count(token_count.begin(), token_count.end());
        std::sort(sorted_token_count.begin(), sorted_token_count.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });
        report = sorted_token_count;
    }

private:
    std::unordered_map<std::string, int> token_count;
    std::vector<std::pair<std::string, int>> report;
};

void main() {
    std::string text = "This is a test document. This document is used for testing tokenization and analysis.";
    DocumentParser parser(text);
    TokenAnalyzer analyzer(parser.tokens);
    ReportGenerator report_generator(analyzer.token_count);
    for (const auto& pair : report_generator.report) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}