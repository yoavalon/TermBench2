#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class SequenceParser {
public:
    SequenceParser(const std::string& text) : text(text), index(0) {}

    void tokenize() {
        while (index < text.length()) {
            char char = text[index];
            if (isdigit(char)) {
                tokens.push_back(parse_number());
            } else if (isalpha(char)) {
                tokens.push_back(parse_word());
            } else if (!isspace(char)) {
                tokens.push_back(std::string(1, char));
            }
            index++;
        }
    }

    std::string parse_number() {
        int start = index;
        while (index < text.length() && isdigit(text[index])) {
            index++;
        }
        return text.substr(start, index - start);
    }

    std::string parse_word() {
        int start = index;
        while (index < text.length() && isalpha(text[index])) {
            index++;
        }
        return text.substr(start, index - start);
    }

private:
    std::string text;
    std::vector<std::string> tokens;
    int index;
};

class SequenceProcessor {
public:
    SequenceProcessor(SequenceParser& parser) : parser(parser) {}

    void process() {
        for (const auto& token : parser.tokens) {
            if (isdigit(token[0])) {
                processed.push_back(std::to_string(std::stoi(token) * 2));
            } else if (isalpha(token[0])) {
                processed.push_back(token);
                for (char& c : processed.back()) {
                    c = toupper(c);
                }
            } else {
                processed.push_back(token);
            }
        }
    }

private:
    SequenceParser& parser;
    std::vector<std::string> processed;
};

class SequenceDisplay {
public:
    SequenceDisplay(SequenceProcessor& processor) : processor(processor) {}

    void display() {
        while (true) {
            for (const auto& item : processor.processed) {
                std::cout << item << ' ';
            }
            std::cout << std::endl;
        }
    }

private:
    SequenceProcessor& processor;
};

int main() {
    std::string text = "hello 123 world 456";
    SequenceParser parser(text);
    parser.tokenize();
    SequenceProcessor processor(parser);
    processor.process();
    SequenceDisplay display(processor);
    display.display();
    return 0;
}