#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <regex>
#include <algorithm>
#include <random>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text) {}

    void tokenize() {
        std::regex re("\\b\\w+\\b");
        std::smatch matches;
        std::string lower_text = text;
        std::transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);

        while (std::regex_search(lower_text, matches, re)) {
            tokens.push_back(matches[0].str());
            lower_text = matches.suffix().str();
        }
    }

    void filter_tokens() {
        std::set<std::string> stop_words = {"the", "and", "is", "in", "to", "a", "of", "it", "that", "for", "on", "with", "as", "by", "at", "from", "this", "an", "or", "but", "not", "are", "be", "was", "were", "has", "have", "had", "do", "does", "did", "will", "would", "can", "could", "should", "if", "then", "else", "while", "when", "where", "who", "what", "why", "how", "all", "any", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};
        tokens.erase(std::remove_if(tokens.begin(), tokens.end(), [&stop_words](const std::string& token) {
            return stop_words.find(token) != stop_words.end();
        }), tokens.end());
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class DataMutator {
public:
    DataMutator(const std::vector<std::string>& tokens) : tokens(tokens) {}

    void mutate() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        for (const auto& token : tokens) {
            if (dis(gen)) {
                std::string reversed_token = token;
                std::reverse(reversed_token.begin(), reversed_token.end());
                mutated_tokens.push_back(reversed_token);
            } else {
                mutated_tokens.push_back(token);
            }
        }
    }

private:
    std::vector<std::string> tokens;
    std::vector<std::string> mutated_tokens;
};

int main() {
    std::string text = "Document parsing and lexical tokenization are important for natural language processing tasks.";
    DocumentParser parser(text);
    parser.tokenize();
    parser.filter_tokens();
    DataMutator mutator(parser.tokens);
    mutator.mutate();

    for (const auto& token : mutator.mutated_tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;

    return 0;
}