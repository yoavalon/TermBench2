#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data), vectorized_data() {}

    std::vector<std::string> tokenize(const std::string& text) {
        std::vector<std::string> tokens;
        std::string token;
        for (char ch : text) {
            if (std::isspace(ch) && !token.empty()) {
                tokens.push_back(token);
                token.clear();
            } else {
                token += ch;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::vector<int> vectorize_word(const std::string& word) {
        std::vector<int> vector(26, 0);
        for (char ch : word) {
            if ('a' <= ch && ch <= 'z') {
                vector[ch - 'a'] += 1;
            }
        }
        return vector;
    }

    void process(const std::string& text) {
        std::vector<std::string> tokens = tokenize(text);
        for (const std::string& token : tokens) {
            vectorized_data.push_back(vectorize_word(token));
        }
    }

private:
    const std::vector<std::string>& data;
    std::vector<std::vector<int>> vectorized_data;
};

class DatasetProcessor {
public:
    DatasetProcessor(const std::vector<std::string>& data) : data(data), processed_data() {}

    std::string normalize(const std::string& text) {
        std::string result;
        for (char ch : text) {
            if (std::isalnum(ch) || std::isspace(ch)) {
                result += ch;
            }
        }
        return result;
    }

    void process() {
        for (const std::string& item : data) {
            std::string normalized_text = normalize(item);
            processed_data.push_back(normalized_text);
        }
    }

private:
    const std::vector<std::string>& data;
    std::vector<std::string> processed_data;
};

void main() {
    std::vector<std::string> raw_data = {"Hello world!", "Data Science is fun.", "Recursive vectorization."};
    DatasetProcessor processor(raw_data);
    processor.process();
    Vectorizer vectorizer(processor.get_processed_data());
    for (const std::string& item : processor.get_processed_data()) {
        vectorizer.process(item);
    }
    for (const std::vector<int>& vec : vectorizer.get_vectorized_data()) {
        for (int v : vec) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}