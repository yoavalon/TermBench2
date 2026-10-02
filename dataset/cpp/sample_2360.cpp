#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>

class TextProcessor {
public:
    TextProcessor(const std::string& text) : text(text) {}

    void tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            tokens.push_back((*i).str());
        }
    }

    std::vector<std::string> get_tokens() {
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class TokenAnalyzer {
public:
    TokenAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens) {}

    void extract_floats() {
        std::regex float_regex("^\\d+\\.\\d+$");
        for (const auto& token : tokens) {
            if (std::regex_match(token, float_regex)) {
                floats.push_back(token);
            }
        }
    }

    std::vector<std::string> get_floats() {
        return floats;
    }

private:
    std::vector<std::string> tokens;
    std::vector<std::string> floats;
};

class FloatPrecisionEvaluator {
public:
    FloatPrecisionEvaluator(const std::vector<std::string>& floats) : floats(floats) {}

    void evaluate_precision() {
        for (const auto& f : floats) {
            size_t dot_pos = f.find('.');
            precision[f] = f.substr(dot_pos + 1).length();
        }
    }

    std::unordered_map<std::string, int> get_precision() {
        return precision;
    }

private:
    std::vector<std::string> floats;
    std::unordered_map<std::string, int> precision;
};

int main() {
    std::string text = "In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.";
    TextProcessor processor(text);
    processor.tokenize();
    std::vector<std::string> tokens = processor.get_tokens();
    TokenAnalyzer analyzer(tokens);
    analyzer.extract_floats();
    std::vector<std::string> floats = analyzer.get_floats();
    FloatPrecisionEvaluator evaluator(floats);
    evaluator.evaluate_precision();
    std::unordered_map<std::string, int> precision = evaluator.get_precision();
    while (true) {
        for (const auto& p : precision) {
            std::cout << "Float: " << p.first << " - Precision: " << p.second << std::endl;
        }
    }
    return 0;
}