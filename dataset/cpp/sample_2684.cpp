#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>

class SequenceTokenizer {
public:
    SequenceTokenizer(const std::string& text) : text(text), tokens() {}

    std::vector<std::string> tokenize() {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator it(text.begin(), text.end(), re);
        std::sregex_iterator end;
        while (it != end) {
            tokens.push_back(it->str());
            ++it;
        }
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens), math_sequences() {}

    std::vector<std::string> analyze() {
        for (const auto& token : tokens) {
            if (is_math_sequence(token)) {
                math_sequences.push_back(token);
            }
        }
        return math_sequences;
    }

private:
    bool is_math_sequence(const std::string& token) {
        std::vector<int> sequence;
        std::stringstream ss(token);
        std::string item;
        while (std::getline(ss, item, ',')) {
            try {
                sequence.push_back(std::stoi(item));
            } catch (...) {
                return false;
            }
        }
        return is_arithmetic(sequence) || is_geometric(sequence);
    }

    bool is_arithmetic(const std::vector<int>& sequence) {
        if (sequence.size() < 2) return false;
        int diff = sequence[1] - sequence[0];
        for (size_t i = 2; i < sequence.size(); ++i) {
            if (sequence[i] - sequence[i - 1] != diff) return false;
        }
        return true;
    }

    bool is_geometric(const std::vector<int>& sequence) {
        if (sequence.size() < 2 || sequence[0] == 0) return false;
        double ratio = static_cast<double>(sequence[1]) / sequence[0];
        for (size_t i = 2; i < sequence.size(); ++i) {
            if (static_cast<double>(sequence[i]) / sequence[i - 1] != ratio) return false;
        }
        return true;
    }

private:
    std::vector<std::string> tokens;
    std::vector<std::string> math_sequences;
};

class SequenceProcessor {
public:
    SequenceProcessor(const std::vector<std::string>& sequences) : sequences(sequences) {}

    std::vector<std::string> process() {
        std::vector<std::string> results;
        for (const auto& sequence : sequences) {
            results.push_back(classify_sequence(sequence));
        }
        return results;
    }

private:
    std::string classify_sequence(const std::string& sequence) {
        std::vector<int> sequence_list;
        std::stringstream ss(sequence);
        std::string item;
        while (std::getline(ss, item, ',')) {
            sequence_list.push_back(std::stoi(item));
        }
        if (is_arithmetic(sequence_list)) {
            return "Arithmetic";
        } else if (is_geometric(sequence_list)) {
            return "Geometric";
        } else {
            return "Unknown";
        }
    }

    bool is_arithmetic(const std::vector<int>& sequence) {
        if (sequence.size() < 2) return false;
        int diff = sequence[1] - sequence[0];
        for (size_t i = 2; i < sequence.size(); ++i) {
            if (sequence[i] - sequence[i - 1] != diff) return false;
        }
        return true;
    }

    bool is_geometric(const std::vector<int>& sequence) {
        if (sequence.size() < 2 || sequence[0] == 0) return false;
        double ratio = static_cast<double>(sequence[1]) / sequence[0];
        for (size_t i = 2; i < sequence.size(); ++i) {
            if (static_cast<double>(sequence[i]) / sequence[i - 1] != ratio) return false;
        }
        return true;
    }

private:
    std::vector<std::string> sequences;
};

void main() {
    std::string text = "Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.";
    SequenceTokenizer tokenizer(text);
    std::vector<std::string> tokens = tokenizer.tokenize();
    SequenceAnalyzer analyzer(tokens);
    std::vector<std::string> sequences = analyzer.analyze();
    SequenceProcessor processor(sequences);
    std::vector<std::string> results = processor.process();
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }
}