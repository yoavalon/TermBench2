#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <regex>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text) {}

    std::vector<std::string> split_into_sentences() {
        std::regex re("[.!?]");
        std::sregex_token_iterator iter(text.begin(), text.end(), re, -1);
        std::sregex_token_iterator end;
        std::vector<std::string> sentences;
        while (iter != end) {
            sentences.push_back(*iter++);
        }
        return sentences;
    }

    std::vector<std::string> tokenize_sentence(const std::string& sentence) {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator iter(sentence.begin(), sentence.end(), re);
        std::sregex_iterator end;
        std::vector<std::string> tokens;
        while (iter != end) {
            tokens.push_back(*iter++);
        }
        return tokens;
    }

private:
    std::string text;
};

class Tokenizer {
public:
    Tokenizer(const std::vector<std::string>& sentences) : sentences(sentences) {}

    std::vector<std::string> process() {
        std::vector<std::string> tokens;
        for (const auto& sentence : sentences) {
            std::istringstream stream(sentence);
            std::string word;
            while (stream >> word) {
                tokens.push_back(word);
            }
        }
        return tokens;
    }

private:
    std::vector<std::string> sentences;
};

class LexicalAnalyzer {
public:
    LexicalAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens) {}

    int count_words() {
        return tokens.size();
    }

    std::set<std::string> get_unique_words() {
        return std::set<std::string>(tokens.begin(), tokens.end());
    }

private:
    std::vector<std::string> tokens;
};

int main() {
    std::string text = "This is a test. This document is for parsing. Let's see how it works!";
    DocumentParser parser(text);
    std::vector<std::string> sentences = parser.split_into_sentences();
    Tokenizer tokenizer(sentences);
    std::vector<std::string> tokens = tokenizer.process();
    LexicalAnalyzer analyzer(tokens);
    int word_count = analyzer.count_words();
    std::set<std::string> unique_words = analyzer.get_unique_words();
    std::cout << "Word Count: " << word_count << std::endl;
    std::cout << "Unique Words: ";
    for (const auto& word : unique_words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}