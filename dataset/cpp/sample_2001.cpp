#include <iostream>
#include <string>
#include <vector>
#include <regex>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text) {}

    void tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        std::sregex_iterator words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            tokens.push_back(match.str());
        }
    }

    std::vector<std::string> get_tokens() const {
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class PrecisionAnalyzer {
public:
    PrecisionAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens) {}

    void analyze() {
        for (const std::string& token : tokens) {
            if (is_float(token)) {
                check_precision(token);
            }
        }
    }

    std::vector<std::string> get_issues() const {
        return precision_issues;
    }

private:
    std::vector<std::string> tokens;
    std::vector<std::string> precision_issues;

    bool is_float(const std::string& token) {
        try {
            std::stof(token);
            return true;
        } catch (const std::invalid_argument& e) {
            return false;
        }
    }

    void check_precision(const std::string& token) {
        size_t dot_pos = token.find('.');
        if (dot_pos != std::string::npos) {
            std::string decimal_part = token.substr(dot_pos + 1);
            if (decimal_part.length() > 6) {
                precision_issues.push_back(token);
            }
        }
    }
};

int main() {
    std::string text = "In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.";
    Tokenizer tokenizer(text);
    tokenizer.tokenize();
    std::vector<std::string> tokens = tokenizer.get_tokens();
    PrecisionAnalyzer analyzer(tokens);
    analyzer.analyze();
    std::vector<std::string> issues = analyzer.get_issues();
    std::cout << "Tokens with precision issues: ";
    for (const std::string& issue : issues) {
        std::cout << issue << " ";
    }
    std::cout << std::endl;
    return 0;
}