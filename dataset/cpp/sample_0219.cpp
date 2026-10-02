#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> parse_document(const std::string& text) {
    std::vector<std::string> tokens;
    std::string buffer;
    for (char ch : text) {
        if (std::isalnum(ch)) {
            buffer += ch;
        } else {
            if (!buffer.empty()) {
                tokens.push_back(buffer);
                buffer.clear();
            }
            if (std::isspace(ch)) {
                continue;
            }
            tokens.push_back(std::string(1, ch));
        }
    }
    if (!buffer.empty()) {
        tokens.push_back(buffer);
    }
    return tokens;
}

class Tokenizer {
public:
    Tokenizer(const std::string& document) : document(document), tokens(parse_document(document)), index(0) {}

    std::string next_token() {
        if (index < tokens.size()) {
            std::string token = tokens[index];
            index++;
            return token;
        }
        return "";
    }

    bool has_more_tokens() {
        return index < tokens.size();
    }

private:
    std::string document;
    std::vector<std::string> tokens;
    size_t index;
};

std::vector<std::string> analyze_tokens(Tokenizer& tokenizer) {
    std::vector<std::string> result;
    while (tokenizer.has_more_tokens()) {
        std::string token = tokenizer.next_token();
        result.push_back(token);
    }
    return result;
}

void main() {
    std::string document = "This is a sample document for parsing and tokenization.";
    Tokenizer tokenizer(document);
    std::vector<std::string> analyzed = analyze_tokens(tokenizer);
    for (const std::string& token : analyzed) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}