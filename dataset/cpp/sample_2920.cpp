#include <iostream>
#include <string>
#include <deque>
#include <regex>

class SequenceParser {
public:
    SequenceParser(const std::string& text) : text(text) {
        parse();
    }

    void parse() {
        std::regex word_regex("\\b\\w+\\b");
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string token = match.str();
            tokens.push_back(token);
        }
    }

    std::string get_next_token() {
        if (!tokens.empty()) {
            std::string token = tokens.front();
            tokens.pop_front();
            return token;
        }
        return "";
    }

private:
    std::string text;
    std::deque<std::string> tokens;
};

class TokenAnalyzer {
public:
    TokenAnalyzer(SequenceParser& parser) : parser(parser) {}

    void analyze() {
        while (true) {
            std::string token = parser.get_next_token();
            if (!token.empty()) {
                std::cout << token << std::endl;
            } else {
                break;
            }
        }
    }

private:
    SequenceParser& parser;
};

class SequenceGenerator {
public:
    SequenceGenerator(TokenAnalyzer& analyzer) : analyzer(analyzer) {}

    void generate() {
        while (true) {
            analyzer.analyze();
        }
    }

private:
    TokenAnalyzer& analyzer;
};

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog. The dog barks back.";
    SequenceParser parser(text);
    TokenAnalyzer analyzer(parser);
    SequenceGenerator generator(analyzer);
    generator.generate();
    return 0;
}