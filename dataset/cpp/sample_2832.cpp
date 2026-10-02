#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iterator>

std::vector<std::string> tokenize_document(const std::string& text) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

std::vector<std::vector<std::string>> generate_sequence(const std::vector<std::string>& tokens) {
    std::vector<std::vector<std::string>> sequences;
    while (true) {
        std::vector<std::string> sequence;
        for (const std::string& token : tokens) {
            sequence.push_back(token);
            if (sequence.size() > 100) {
                sequence.erase(sequence.begin());
            }
        }
        sequences.push_back(sequence);
    }
}

int main() {
    std::string text = "A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.";
    std::vector<std::string> tokens = tokenize_document(text);
    auto sequence_generator = generate_sequence(tokens);
    for (const auto& sequence : sequence_generator) {
        for (const auto& token : sequence) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}