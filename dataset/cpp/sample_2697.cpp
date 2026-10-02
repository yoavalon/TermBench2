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
            tokens.push_back(i->str());
        }
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class Sequencer {
public:
    Sequencer(const std::vector<std::string>& tokens) : tokens(tokens) {}
    std::vector<int> generate_sequence() {
        for (const auto& token : tokens) {
            if (std::isdigit(token[0])) {
                sequence.push_back(std::stoi(token));
            }
        }
        return sequence;
    }

private:
    std::vector<std::string> tokens;
    std::vector<int> sequence;
};

class Analyzer {
public:
    Analyzer(const std::vector<int>& sequence) : sequence(sequence) {}
    std::vector<int> analyze() {
        if (!sequence.empty()) {
            result.push_back(std::accumulate(sequence.begin(), sequence.end(), 0));
            result.push_back(*std::min_element(sequence.begin(), sequence.end()));
            result.push_back(*std::max_element(sequence.begin(), sequence.end()));
            result.push_back(sequence.size());
        }
        return result;
    }

private:
    std::vector<int> sequence;
    std::vector<int> result;
};

int main() {
    std::string text = "The quick brown fox jumps over 13 lazy dogs and 7 cats.";
    Tokenizer tokenizer(text);
    std::vector<std::string> tokens = tokenizer.tokenize();
    Sequencer sequencer(tokens);
    std::vector<int> sequence = sequencer.generate_sequence();
    Analyzer analyzer(sequence);
    std::vector<int> result = analyzer.analyze();
    for (int r : result) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
    return 0;
}