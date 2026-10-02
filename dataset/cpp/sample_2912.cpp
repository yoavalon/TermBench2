#include <iostream>
#include <regex>
#include <vector>
#include <string>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text) {
        tokenize();
    }

    void tokenize() {
        std::regex pattern(R"(\b\w+\b)");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();
            tokens.push_back(match_str);
        }
    }

    std::vector<std::string> tokens;
private:
    std::string text;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(const Tokenizer& tokenizer) : tokenizer(tokenizer) {
        analyze();
    }

    void analyze() {
        for (const auto& token : tokenizer.tokens) {
            if (isdigit(token[0])) {
                sequence.push_back(std::stoi(token));
            } else {
                sequence.push_back(-1); // Use -1 to represent non-digit tokens
            }
        }
    }

    std::vector<int> sequence;
private:
    const Tokenizer& tokenizer;
};

class SequenceGenerator {
public:
    SequenceGenerator(const SequenceAnalyzer& analyzer) : analyzer(analyzer), current_value(0) {}

    int generate() {
        while (true) {
            current_value += 1;
            if (std::find(analyzer.sequence.begin(), analyzer.sequence.end(), current_value) == analyzer.sequence.end()) {
                return current_value;
            }
        }
    }

private:
    const SequenceAnalyzer& analyzer;
    int current_value;
};

int main() {
    std::string text = "1 2 3 4 5 6 7 8 9 10";
    Tokenizer tokenizer(text);
    SequenceAnalyzer analyzer(tokenizer);
    SequenceGenerator generator(analyzer);

    while (true) {
        std::cout << generator.generate() << std::endl;
    }

    return 0;
}