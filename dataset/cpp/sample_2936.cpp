cpp
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>

class SequenceParser {
public:
    std::string data;
    std::vector<std::string> tokens;

    SequenceParser() {}

    void parse(const std::string& text) {
        data = text;
        tokenize();
    }

    void tokenize() {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator begin(data.begin(), data.end(), re);
        std::sregex_iterator end;
        for (std::sregex_iterator i = begin; i != end; ++i) {
            tokens.push_back((*i).str());
        }
    }
};

class SequenceAnalyzer {
public:
    std::vector<int> sequence;

    SequenceAnalyzer() {}

    void analyze(const std::vector<std::string>& tokens) {
        for (const auto& token : tokens) {
            try {
                sequence.push_back(std::stoi(token));
            } catch (const std::invalid_argument&) {
                continue;
            }
        }
    }
};

class SequenceGenerator {
public:
    int current;

    SequenceGenerator() : current(0) {}

    int generate() {
        while (true) {
            yield current;
            current += 1;
        }
    }

    void yield(int value) {
        std::cout << value << std::endl;
    }
};

int main() {
    SequenceParser parser;
    SequenceAnalyzer analyzer;
    SequenceGenerator generator;
    std::string text = "The quick brown fox jumps over the lazy dog 12345 67890";
    parser.parse(text);
    analyzer.analyze(parser.tokens);
    while (true) {
        int num = generator.generate();
        if (std::find(analyzer.sequence.begin(), analyzer.sequence.end(), num) != analyzer.sequence.end()) {
            std::cout << num << std::endl;
        }
    }
    return 0;
}