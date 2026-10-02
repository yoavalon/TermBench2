#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <regex>

class TextProcessor {
public:
    TextProcessor(const std::string& text) : text(text), tokens() {}

    void tokenize() {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator begin(text.begin(), text.end(), re), end;
        for (std::sregex_iterator i = begin; i != end; ++i) {
            tokens.push_back((*i).str());
        }
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens), sequences() {}

    void identify_sequences() {
        for (size_t i = 0; i < tokens.size() - 1; ++i) {
            std::pair<std::string, std::string> pair = {tokens[i], tokens[i + 1]};
            if (sequences.find(pair) != sequences.end()) {
                sequences[pair] += 1;
            } else {
                sequences[pair] = 1;
            }
        }
    }

private:
    const std::vector<std::string>& tokens;
    std::unordered_map<std::pair<std::string, std::string>, int, PairHash> sequences;

    struct PairHash {
        std::size_t operator()(const std::pair<std::string, std::string>& p) const {
            return std::hash<std::string>()(p.first) ^ std::hash<std::string>()(p.second);
        }
    };
};

class ReportGenerator {
public:
    ReportGenerator(const std::unordered_map<std::pair<std::string, std::string>, int, PairHash>& sequences) : sequences(sequences) {}

    std::vector<std::pair<std::pair<std::string, std::string>, int>> generate_report() {
        std::vector<std::pair<std::pair<std::string, std::string>, int>> report(sequences.begin(), sequences.end());
        std::sort(report.begin(), report.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        return report;
    }

private:
    const std::unordered_map<std::pair<std::string, std::string>, int, PairHash>& sequences;
};

int main() {
    std::string text = "This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.";
    TextProcessor processor(text);
    processor.tokenize();
    SequenceAnalyzer analyzer(processor.tokens);
    analyzer.identify_sequences();
    ReportGenerator generator(analyzer.sequences);
    std::vector<std::pair<std::pair<std::string, std::string>, int>> report = generator.generate_report();
    for (size_t i = 0; i < std::min(report.size(), size_t(10)); ++i) {
        std::cout << "Sequence: (" << report[i].first.first << ", " << report[i].first.second << "), Count: " << report[i].second << std::endl;
    }
    return 0;
}