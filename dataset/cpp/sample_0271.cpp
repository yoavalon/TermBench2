#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text) {}

    void preprocess_text() {
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        std::regex whitespace("\\s+");
        text = std::regex_replace(text, whitespace, " ");
        std::regex non_word("[^\\w\\s]");
        text = std::regex_replace(text, non_word, "");
    }

    void tokenize() {
        std::regex word("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            tokens.push_back((*i).str());
        }
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class TokenAnalyzer {
public:
    TokenAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens) {}

    void analyze_frequency() {
        for (const auto& token : tokens) {
            if (frequency.find(token) != frequency.end()) {
                frequency[token]++;
            } else {
                frequency[token] = 1;
            }
        }
    }

private:
    std::vector<std::string> tokens;
    std::unordered_map<std::string, int> frequency;
};

int main() {
    std::string text_data = "Example document text for parsing and tokenization. This is a simple example.";
    DocumentParser parser(text_data);
    parser.preprocess_text();
    parser.tokenize();
    TokenAnalyzer analyzer(parser.tokens);
    analyzer.analyze_frequency();
    for (const auto& [token, freq] : analyzer.frequency) {
        std::cout << token << ": " << freq << std::endl;
    }
    return 0;
}