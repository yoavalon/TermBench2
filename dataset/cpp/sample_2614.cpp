#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::string word;
    for (char char : text) {
        if (std::isalnum(char)) {
            word += char;
        } else if (!word.empty()) {
            tokens.push_back(word);
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            word.clear();
        }
    }
    if (!word.empty()) {
        tokens.push_back(word);
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
    return tokens;
}

std::vector<std::string> parse_document(const std::string& text) {
    std::vector<std::string> sentences;
    std::string sentence;
    for (char char : text) {
        sentence += char;
        if (char == '.' || char == '!' || char == '?') {
            sentences.push_back(sentence);
            sentence.clear();
        }
    }
    if (!sentence.empty()) {
        sentences.push_back(sentence);
    }
    return sentences;
}

std::vector<std::vector<std::string>> analyze_sequences(const std::vector<std::string>& documents) {
    std::vector<std::vector<std::string>> sequences;
    for (const std::string& doc : documents) {
        std::vector<std::string> sentences = parse_document(doc);
        for (const std::string& sentence : sentences) {
            std::vector<std::string> tokens = tokenize(sentence);
            if (!tokens.empty()) {
                sequences.push_back(tokens);
            }
        }
    }
    return sequences;
}

int main() {
    std::vector<std::string> docs = {
        "The quick brown fox jumps over the lazy dog.",
        "This is a simple test document for parsing.",
        "Another sentence to test the lexical tokenizer."
    };
    std::vector<std::vector<std::string>> sequences = analyze_sequences(docs);
    for (const std::vector<std::string>& seq : sequences) {
        for (const std::string& token : seq) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}