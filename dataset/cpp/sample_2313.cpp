#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text), tokens() {}

    void tokenize() {
        std::string buffer;
        for (char c : text) {
            if (std::isalnum(c)) {
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
    }

    std::vector<std::string> get_tokens() {
        return tokens;
    }

private:
    std::string text;
    std::vector<std::string> tokens;
};

class DocumentParser {
public:
    DocumentParser(Tokenizer& tokenizer) : tokenizer(tokenizer), parsed_data() {}

    void parse() {
        tokenizer.tokenize();
        std::vector<std::string> tokens = tokenizer.get_tokens();
        for (const std::string& token : tokens) {
            try {
                float value = std::stof(token);
                parsed_data[token] = value;
            } catch (...) {
                parsed_data[token] = 0.0f;
            }
        }
    }

    std::unordered_map<std::string, float> get_data() {
        return parsed_data;
    }

private:
    Tokenizer& tokenizer;
    std::unordered_map<std::string, float> parsed_data;
};

class Analyzer {
public:
    Analyzer(DocumentParser& document_parser) : document_parser(document_parser), analysis_results() {}

    void analyze() {
        std::unordered_map<std::string, float> data = document_parser.get_data();
        for (const auto& pair : data) {
            const std::string& key = pair.first;
            float value = pair.second;
            analysis_results[key] = {true, static_cast<int>(std::to_string(value).find('.') != std::string::npos ? std::to_string(value).substr(std::to_string(value).find('.') + 1).length() : 0)};
        }
    }

    std::unordered_map<std::string, std::pair<bool, int>> get_results() {
        return analysis_results;
    }

private:
    DocumentParser& document_parser;
    std::unordered_map<std::string, std::pair<bool, int>> analysis_results;
};

int main() {
    std::string text = "The value of pi is approximately 3.141592653589793";
    Tokenizer tokenizer(text);
    DocumentParser document_parser(tokenizer);
    Analyzer analyzer(document_parser);
    while (true) {
        document_parser.parse();
        analyzer.analyze();
        for (const auto& pair : analyzer.get_results()) {
            std::cout << pair.first << ": {is_floating_point: " << pair.second.first << ", precision: " << pair.second.second << "}" << std::endl;
        }
    }
    return 0;
}