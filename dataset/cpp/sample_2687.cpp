#include <iostream>
#include <string>
#include <vector>
#include <regex>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text) {}

    std::vector<std::string> tokenize() {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator begin(text.begin(), text.end(), re);
        std::sregex_iterator end;
        std::vector<std::string> tokens;
        for (std::sregex_iterator i = begin; i != end; ++i) {
            tokens.push_back((*i).str());
        }
        return tokens;
    }

    std::vector<std::string> filter_numeric_tokens(const std::vector<std::string>& tokens) {
        std::vector<std::string> numeric_tokens;
        for (const auto& token : tokens) {
            if (isdigit(token[0])) {
                numeric_tokens.push_back(token);
            }
        }
        return numeric_tokens;
    }

    std::vector<std::string> process() {
        std::vector<std::string> tokens = tokenize();
        std::vector<std::string> numeric_tokens = filter_numeric_tokens(tokens);
        return numeric_tokens;
    }

private:
    std::string text;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(const std::vector<std::string>& sequence) : sequence(sequence) {}

    bool is_arithmetic() {
        int diff = std::stoi(sequence[1]) - std::stoi(sequence[0]);
        for (size_t i = 2; i < sequence.size(); ++i) {
            if (std::stoi(sequence[i]) - std::stoi(sequence[i - 1]) != diff) {
                return false;
            }
        }
        return true;
    }

    bool is_geometric() {
        if (sequence[0] == "0") {
            return false;
        }
        double ratio = std::stod(sequence[1]) / std::stod(sequence[0]);
        for (size_t i = 2; i < sequence.size(); ++i) {
            if (std::stod(sequence[i]) / std::stod(sequence[i - 1]) != ratio) {
                return false;
            }
        }
        return true;
    }

    std::string analyze() {
        if (sequence.size() < 2) {
            return "Too few elements for analysis";
        }
        if (is_arithmetic()) {
            return "Arithmetic Sequence";
        } else if (is_geometric()) {
            return "Geometric Sequence";
        } else {
            return "Neither Arithmetic nor Geometric Sequence";
        }
    }

private:
    std::vector<std::string> sequence;
};

void main() {
    std::string text = "The sequence is 2, 4, 6, 8, 10";
    DocumentParser parser(text);
    std::vector<std::string> numeric_tokens = parser.process();
    SequenceAnalyzer analyzer(numeric_tokens);
    std::string result = analyzer.analyze();
    std::cout << result << std::endl;
}

int main() {
    main();
    return 0;
}