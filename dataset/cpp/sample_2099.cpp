#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class DocumentParser {
public:
    DocumentParser(const std::string& text) : text(text) {}

    std::vector<std::string> tokenize() {
        std::vector<std::string> tokens;
        std::string buffer;
        for (char c : text) {
            if (std::isalnum(c) || c == '_') {
                buffer += c;
            } else {
                if (!buffer.empty()) {
                    tokens.push_back(buffer);
                    buffer.clear();
                }
                if (!std::isspace(c)) {
                    tokens.push_back(std::string(1, c));
                }
            }
        }
        if (!buffer.empty()) {
            tokens.push_back(buffer);
        }
        return tokens;
    }

private:
    std::string text;
};

class Tokenizer {
public:
    Tokenizer(const std::vector<std::string>& tokens) : tokens(tokens) {}

    std::vector<std::string> categorize() {
        std::vector<std::string> categorized;
        for (const std::string& token : tokens) {
            if (isNumeric(token)) {
                categorized.push_back("Number");
            } else if (isFloat(token)) {
                categorized.push_back("Float");
            } else if (isIdentifier(token)) {
                categorized.push_back("Identifier");
            } else {
                categorized.push_back("Operator");
            }
        }
        return categorized;
    }

private:
    std::vector<std::string> tokens;

    bool isNumeric(const std::string& token) {
        for (char c : token) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    bool isFloat(const std::string& token) {
        bool hasDecimal = false;
        for (char c : token) {
            if (c == '.') {
                if (hasDecimal) {
                    return false;
                }
                hasDecimal = true;
            } else if (!std::isdigit(c)) {
                return false;
            }
        }
        return hasDecimal;
    }

    bool isIdentifier(const std::string& token) {
        if (token.empty() || !std::isalnum(token[0]) && token[0] != '_') {
            return false;
        }
        for (char c : token) {
            if (!std::isalnum(c) && c != '_') {
                return false;
            }
        }
        return true;
    }
};

void main() {
    std::string text = "x = 3.14 * 2 + 5.0";
    DocumentParser parser(text);
    std::vector<std::string> tokens = parser.tokenize();
    Tokenizer tokenizer(tokens);
    std::vector<std::string> categorized = tokenizer.categorize();
    for (const std::string& category : categorized) {
        std::cout << category << " ";
    }
}