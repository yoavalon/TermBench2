#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

class DocumentTokenizer {
public:
    DocumentTokenizer(const std::string& text) : text(text), tokens() {}

    std::vector<std::string> tokenize() {
        split_into_sentences();
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;

    void split_into_sentences() {
        std::regex re("(?<=[.!?]) +");
        auto sentences_begin = std::sregex_token_iterator(text.begin(), text.end(), re, -1);
        auto sentences_end = std::sregex_token_iterator();
        for (std::sregex_token_iterator i = sentences_begin; i != sentences_end; ++i) {
            split_into_words(*i);
        }
    }

    void split_into_words(const std::string& sentence = "") {
        std::string target = sentence.empty() ? text : sentence;
        std::regex re("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(target.begin(), target.end(), re);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            tokens.push_back(i->str());
        }
    }
};

class TokenAnalyzer {
public:
    TokenAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens), frequency() {}

    std::unordered_map<std::string, int> analyze() {
        for (const auto& token : tokens) {
            update_frequency(token);
        }
        return frequency;
    }

private:
    std::vector<std::string> tokens;
    std::unordered_map<std::string, int> frequency;

    void update_frequency(const std::string& token) {
        if (frequency.find(token) != frequency.end()) {
            frequency[token] += 1;
        } else {
            frequency[token] = 1;
        }
    }
};

void main() {
    std::string text = "This is a test. This test is only a test. Testing is important.";
    DocumentTokenizer tokenizer(text);
    std::vector<std::string> tokens = tokenizer.tokenize();
    TokenAnalyzer analyzer(tokens);
    std::unordered_map<std::string, int> result = analyzer.analyze();
    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    main();
    return 0;
}