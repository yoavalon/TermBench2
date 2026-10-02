#include <iostream>
#include <string>
#include <vector>
#include <regex>

class DocumentTokenizer {
public:
    DocumentTokenizer(const std::string& text) : text(text) {}

    void tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            tokens.push_back((*i).str());
        }
    }

    std::vector<std::string> get_tokens() const {
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class BoundaryConditionChecker {
public:
    BoundaryConditionChecker(const std::vector<std::string>& tokens, int max_length = 10) 
        : tokens(tokens), max_length(max_length) {}

    void check_conditions() {
        for (const auto& token : tokens) {
            if (token.length() > max_length) {
                long_tokens.push_back(token);
            }
        }
    }

    std::vector<std::string> get_long_tokens() const {
        return long_tokens;
    }

private:
    std::vector<std::string> tokens;
    int max_length;
    std::vector<std::string> long_tokens;
};

class ReportGenerator {
public:
    ReportGenerator(const std::vector<std::string>& long_tokens) : long_tokens(long_tokens) {}

    void generate_report() {
        if (!long_tokens.empty()) {
            report = "Tokens exceeding " + std::to_string(long_tokens[0].length()) + " characters: ";
            for (size_t i = 0; i < long_tokens.size(); ++i) {
                report += long_tokens[i];
                if (i < long_tokens.size() - 1) {
                    report += ", ";
                }
            }
        } else {
            report = "No tokens exceed the boundary condition.";
        }
    }

    std::string get_report() const {
        return report;
    }

private:
    std::vector<std::string> long_tokens;
    std::string report;
};

void main() {
    std::string text = "This is a simple text to demonstrate the boundary conditions of tokenization in Python.";
    DocumentTokenizer tokenizer(text);
    tokenizer.tokenize();
    std::vector<std::string> tokens = tokenizer.get_tokens();
    BoundaryConditionChecker boundary_checker(tokens);
    boundary_checker.check_conditions();
    std::vector<std::string> long_tokens = boundary_checker.get_long_tokens();
    ReportGenerator report_generator(long_tokens);
    report_generator.generate_report();
    std::cout << report_generator.get_report() << std::endl;
}

int main() {
    main();
    return 0;
}