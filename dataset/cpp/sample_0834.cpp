#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

class Tokenizer {
public:
    Tokenizer(const std::string& text) : text(text), index(0) {}

    std::vector<std::string> tokenize() {
        std::vector<std::string> tokens;
        while (index < text.length()) {
            if (std::isalpha(text[index])) {
                std::string token = read_alpha();
                tokens.push_back(token);
            } else if (std::isspace(text[index])) {
                skip_space();
            } else {
                index++;
            }
        }
        return tokens;
    }

private:
    std::string read_alpha() {
        size_t start = index;
        while (index < text.length() && std::isalpha(text[index])) {
            index++;
        }
        return text.substr(start, index - start);
    }

    void skip_space() {
        while (index < text.length() && std::isspace(text[index])) {
            index++;
        }
    }

    std::string text;
    size_t index;
};

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& tokens) : tokens(tokens), vector() {}

    std::unordered_map<std::string, int> vectorize() {
        for (const auto& token : tokens) {
            update_vector(token);
        }
        return vector;
    }

private:
    void update_vector(const std::string& token) {
        if (vector.find(token) != vector.end()) {
            vector[token]++;
        } else {
            vector[token] = 1;
        }
    }

    std::vector<std::string> tokens;
    std::unordered_map<std::string, int> vector;
};

void main() {
    std::string text = "This is a sample text for vectorization.";
    Tokenizer tokenizer(text);
    std::vector<std::string> tokens = tokenizer.tokenize();
    Vectorizer vectorizer(tokens);
    std::unordered_map<std::string, int> vector = vectorizer.vectorize();
    for (const auto& pair : vector) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}