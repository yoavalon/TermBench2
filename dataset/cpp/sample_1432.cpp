#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text) {}

    std::vector<std::string> tokenize() {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator begin(text.begin(), text.end(), re);
        std::sregex_iterator end;
        for (std::sregex_iterator i = begin; i != end; ++i) {
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
    DocumentParser(const std::string& text) : text(text) {}

    void preprocess() {
        text = std::regex_replace(text, std::regex("[^\\w\\s]"), "");
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    }

    std::vector<std::string> parse() {
        Tokenizer tokenizer(text);
        return tokenizer.tokenize();
    }

private:
    std::string text;
};

class DataMutator {
public:
    DataMutator(const std::vector<std::string>& data) : data(data) {}

    std::vector<std::string> mutate() {
        std::vector<std::string> mutated;
        for (const auto& item : data) {
            mutated.push_back(std::string(item).upper());
        }
        return mutated;
    }

private:
    std::vector<std::string> data;
};

void main() {
    std::string document = "This is a sample document for testing. It includes various words!";
    DocumentParser parser(document);
    parser.preprocess();
    std::vector<std::string> tokens = parser.parse();
    DataMutator mutator(tokens);
    std::vector<std::string> mutated_data = mutator.mutate();
    for (const auto& item : mutated_data) {
        std::cout << item << " ";
    }
}